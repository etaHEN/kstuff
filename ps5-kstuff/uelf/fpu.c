#include "utils.h"

__attribute__((aligned(64))) static char xsave_area[4096]; //is this enough?
static uint32_t xsave_eax, xsave_edx;
static uint64_t saved_cr0;

void uelf_fpu_enter(void)
{
    saved_cr0 = read_cr0();
    write_cr0(saved_cr0 & -9); //clear CR0.TS
    asm volatile("xgetbv":"=d"(xsave_edx),"=a"(xsave_eax):"c"(0));
    asm volatile("xsave %0":"=m"(xsave_area):"a"(xsave_eax),"d"(xsave_edx));
    asm volatile("finit");
    uint32_t mxcsr = 0x1f80;
    asm volatile("ldmxcsr %0"::"m"(mxcsr));
}

void uelf_fpu_exit(void)
{
    asm volatile("xrstor %0"::"m"(xsave_area),"a"(xsave_eax),"d"(xsave_edx));
    write_cr0(saved_cr0);
}
