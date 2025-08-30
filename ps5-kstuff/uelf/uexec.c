#include <errno.h>
#include "uexec.h"
#include "utils.h"
#include "traps.h"
#include "shared_area.h"

extern char doreti_iret[];
extern char malloc[];
extern char M_something[];
extern char copyin[];
extern char eventhandler_register[];
extern char s_shutdown_final[];
extern char kproc_shutdown[];
extern char strlen_trap[];
extern char idt[];

static size_t get_page_counts(size_t size, size_t sizes[5])
{
    sizes[0] = (size + 4095) >> 12;
    for(size_t i = 1; i < 5; i++)
        sizes[i] = (sizes[i-1] + 511) >> 9;
    sizes[3] += 2;
    size_t ans = 0;
    for(size_t i = 0; i < 5; i++)
        ans += i;
    return ans << 12;
}

static void start_call3(uint64_t* regs, uint64_t trap, uint64_t fn, uint64_t arg1, uint64_t arg2, uint64_t arg3)
{
    uint64_t stack_frame[12] = {(uint64_t)doreti_iret, trap, 0, 0, 0, 0, 0, regs[RDI], regs[RSI], regs[RDX], regs[RCX], regs[R8]};
    push_stack(regs, stack_frame, sizeof(stack_frame));
    regs[RIP] = fn;
    regs[RDI] = arg1;
    regs[RSI] = arg2;
    regs[RDX] = arg3;
}

static void start_call6(uint64_t* regs, uint64_t trap, uint64_t fn, uint64_t arg1, uint64_t arg2, uint64_t arg3, uint64_t arg4, uint64_t arg5, uint64_t arg6)
{
    start_call3(regs, trap, fn, arg1, arg2, arg3);
    regs[RCX] = arg4;
    regs[R8] = arg5;
    regs[R9] = arg6;
}

static uint64_t stop_call(uint64_t* regs)
{
    uint64_t stack_frame[11];
    pop_stack(regs, stack_frame, sizeof(stack_frame));
    regs[RDI] = stack_frame[6];
    regs[RSI] = stack_frame[7];
    regs[RDX] = stack_frame[8];
    regs[RCX] = stack_frame[9];
    regs[R8] = stack_frame[10];
    return regs[RAX];
}

static void return_error(uint64_t* regs, int error)
{
    pop_stack(regs, &regs[RIP], sizeof(regs[RIP]));
    regs[RAX] = error;
}

//int uexec(void* blob, size_t size, size_t entry);
int handle_uexec(uint64_t* regs, uint64_t* args)
{
    uintptr_t blob = args[RDI];
    size_t size = args[RSI];
    size_t entry = args[RDX];
    if(entry >= size)
        return EINVAL;
    regs[RSI] = blob;
    regs[RDX] = size;
    regs[RCX] = entry;
    size_t sizes[5];
    start_call3(regs, MKTRAP(TRAP_UEXEC, 1), (uint64_t)malloc, get_page_counts(size, sizes), (uint64_t)M_something, 0x102);
    return ENOSYS;
}

void handle_uexec_trap(uint64_t* regs, uint32_t trap)
{
    switch(trap)
    {
    case 1:
        uint64_t addr = stop_call(regs);
        if(addr == 0)
            return_error(regs, ENOMEM);
        else
        {
            regs[R8] = addr;
            start_call3(regs, MKTRAP(TRAP_UEXEC, 2), (uint64_t)copyin, regs[RSI], addr, regs[RDX]);
        }
        return;
    case 2:
        int status = stop_call(regs);
        if(status != 0)
            return_error(regs, status);
        else
        {
            size_t sizes[5];
            get_page_counts(regs[RDX], sizes);
            uint64_t page = regs[R8];
            uint64_t phys1 = 0, phys2 = 0;
            uint64_t pagetable = regs[R8] + (sizes[0] << 12);
            uint64_t phys3 = 0, phys4 = 0;
            uint64_t cr3;
            for(size_t i = 0; i < 4; i++)
            {
                for(size_t j = 0; j < sizes[i]; j++)
                {
                    if(phys1 == phys2)
                        virt2phys(page, &phys1, &phys2);
                    if(phys3 == phys4)
                        virt2phys(pagetable, &phys3, &phys4);
                    *(uint64_t*)(DMEM + phys3) = phys1 | 7;
                    page += 4096;
                    phys1 += 4096;
                    pagetable += 8;
                    phys3 += 8;
                }
                if(i == 3)
                    break;
                while(phys3 % 4096)
                {
                    *(uint64_t*)(DMEM + phys3) = 0;
                    pagetable += 8;
                    phys3 += 8;
                }
                if(i == 2)
                {
                    if(phys3 == phys4)
                        virt2phys(pagetable, &phys3, &phys4);
                    uint64_t dmap_cached = phys3;
                    uint64_t* p = (uint64_t*)(DMEM + dmap_cached);
                    for(size_t i = 0; i < 512; i++)
                        p[i] = (i << 30) | 135;
                    pagetable += 4096;
                    phys3 += 4096;
                    if(phys3 == phys4)
                        virt2phys(pagetable, &phys3, &phys4);
                    uint64_t dmap_uncached = phys3;
                    p = (uint64_t*)(DMEM + dmap_uncached);
                    for(size_t i = 0; i < 512; i++)
                        p[i] = (i << 30) | 159;
                    pagetable += 4096;
                    phys3 += 4096;
                    if(phys3 == phys4)
                        virt2phys(pagetable, &phys3, &phys4);
                    cr3 = phys3;
                    p = (uint64_t*)(DMEM + cr3);
                    uint64_t* p2 = (uint64_t*)(DMEM + cr3_phys);
                    p[0] = dmap_cached | 7;
                    p[1] = dmap_uncached | 31;
                    for(size_t i = 256; i < 512; i++)
                        p[i] = p2[i];
                    pagetable += 16;
                    phys3 += 16;
                }
            }
            //TODO: proper locking
            shared_area.uexec_cr3 = cr3;
            shared_area.uexec_entry = (2ull << 39) + regs[RCX];
            start_call6(regs, MKTRAP(TRAP_UEXEC, 3), (uint64_t)eventhandler_register, 0, (uint64_t)s_shutdown_final, (uint64_t)kproc_shutdown, (uint64_t)s_shutdown_final, 0xdeadfb5d00000001, 19999);
        }
        return;
    case 3:
        uint64_t token = stop_call(regs);
        if(token == 0)
            return_error(regs, token);
        else
        {
            kpoke64(regs[RDI]+td_retval, 0);
            return_error(regs, 0);
        }
        return;
    }
}

/*static void uart_putchar(uint8_t c)
{
    while((*(volatile uint32_t*)(DMEM+0xc101010c) & 0x800));
    *(volatile uint32_t*)(DMEM+0xc1010104) = c;
}

static void uart_putstr(const char* s)
{
    for(char c; c = *s++;)
        uart_putchar(c);
}

static void uart_putn(uint64_t n)
{
    if(n < 10)
        uart_putchar(n + '0');
    else
    {
        uart_putn(n / 10);
        uart_putchar(n % 10 + '0');
    }
}*/

void uexec_jump(uint64_t* regs)
{
    while(__atomic_load_n(&shared_area.uexec_counter, __ATOMIC_SEQ_CST) != 0xffff);
    kpoke64(cr3_phys_addr, shared_area.uexec_cr3);
    for(size_t i = 0; i < RIP; i++)
        regs[i] = 0;
    regs[RIP] = shared_area.uexec_entry;
    regs[CS] = 0x43;
    regs[EFLAGS] = 2;
    regs[RSP] = 0;
    regs[SS] = 0x3b;
    regs[RDI] = shared_area.uexec_cr3;
}

void uexec_ipi(uint64_t* regs)
{
    uint32_t eax = 11, ecx, edx, ebx;
    asm volatile("cpuid":"=a"(eax),"=c"(ecx),"=d"(edx),"=b"(ebx):"a"(eax));
    int current_core = edx;
    __atomic_fetch_or(&shared_area.uexec_counter, 1 << current_core, __ATOMIC_SEQ_CST);
    uexec_jump(regs);
}

int try_handle_uexec_trap(uint64_t* regs)
{
    if(regs[RIP] == (uint64_t)strlen_trap && (regs[RDI] >> 32) == 0xdeadfb5d)
    {
        uint64_t idt_vector[2];
        copy_from_kernel(idt_vector, (uint64_t)idt + 16, sizeof(idt_vector));
        copy_to_kernel((uint64_t)idt + 16 * 240, idt_vector, sizeof(idt_vector));
        uint32_t eax = 11, ecx, edx, ebx;
        asm volatile("cpuid":"=a"(eax),"=c"(ecx),"=d"(edx),"=b"(ebx):"a"(eax));
        int current_core = edx;
        __atomic_fetch_or(&shared_area.uexec_counter, 1 << current_core, __ATOMIC_SEQ_CST);
        uint64_t apic_base = 0;
        rdmsr(0x1b, &apic_base);
        apic_base &= -4096;
        volatile uint32_t* apic = (volatile uint32_t*)(DMEM + apic_base);
        for(int i = 0; i < 16; i++)
            if(i != current_core)
            {
                while((apic[192] & 4096));
                apic[196] = i << 24;
                apic[192] = 0x4001;
                while(!(__atomic_load_n(&shared_area.uexec_counter, __ATOMIC_SEQ_CST) & (1 << i)));
            }
        uexec_jump(regs);
        return 1;
    }
    return 0;
}
