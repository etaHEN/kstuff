#include "r0gdb.h"
#include "offsets.h"

struct offset_table offsets;
extern uint64_t kdata_base;

#define OFFSET(x) offsets.x = kdata_base + x;
#define DEF(x, y) enum { x = (y) + 0 * sizeof(offsets.x) };

#define START_FW(fw) void set_offsets_ ## fw(void) {
#define END_FW() }

START_FW(300)
DEF(allproc, 0x276dc58)
DEF(idt, 0x642dc80)
DEF(gdt_array, 0x642ee20)
DEF(tss_array, 0x6430820)
DEF(pcpu_array, 0x6432280)
DEF(doreti_iret, -0x9aefbc)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x96f79a)
DEF(rdmsr_start, -0x9b046a)
DEF(wrmsr_ret, -0x9b183c)
DEF(dr2gpr_start, -0x9b6513)
DEF(gpr2dr_1_start, -0x9b63fa)
DEF(gpr2dr_2_start, -0x9b6307)
DEF(mov_cr3_rax, -0x39099e)
DEF(mov_rdi_cr3, -0x390a0e)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9b6700)
DEF(mprotect_fix_start, -0x8ee651)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2c92bd)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1dd21e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6b549f)
DEF(sigaction_fix_end, -0x6b5449)
DEF(sysents, 0x16f720)
DEF(sysents_ps4, 0x167170)
DEF(sysentvec, 0xca0cd8)
DEF(sysentvec_ps4, 0xca0e50)
DEF(sceSblServiceMailbox, -0x675df0)
DEF(sceSblAuthMgrSmIsLoadable2, -0x88a540)
DEF(mdbg_call_fix, -0x626d49)
DEF(syscall_before, -0x7e91bf)
DEF(syscall_after, -0x7e919c)
DEF(malloc, -0xaa2a0)
DEF(M_something, 0x12d3d70)
DEF(loadSelfSegment_epilogue, -0x889e0d)
DEF(loadSelfSegment_watchpoint, -0x2c88a8)
DEF(loadSelfSegment_watchpoint_lr, -0x88a067)
DEF(decryptSelfBlock_watchpoint_lr, -0x889cca)
DEF(decryptSelfBlock_epilogue, -0x889c03)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x889595)
DEF(decryptMultipleSelfBlocks_epilogue, -0x889112)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x88a1bc)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x889e81)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x889954)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8891cc)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x88a5be)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x92d9b0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x92df7b)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x92df05)
DEF(sceSblPfsSetKeys, -0x92dc60)
DEF(sceSblServiceCryptAsync, -0x8d1e30)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8d1df2)
DEF(copyin, -0x970050)
DEF(copyout, -0x970100)
DEF(crypt_message_resolve, -0x475790)
DEF(justreturn, -0x9af100)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xd4fe88)
DEF(pop_all_iret, -0x9af01b)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x94f570)
DEF(kernel_pmap_store, 0x31be218)
DEF(crypt_singleton_array, 0x2d99830)
DEF(security_flags, 0x6466474)
DEF(targetid, 0x646647d)
DEF(qa_flags, 0x6466498)
DEF(utoken, 0x6466500)
#include "offset_list.txt"
END_FW()

START_FW(310)
DEF(allproc, 0x276dc58)
DEF(idt, 0x642dc80)
DEF(gdt_array, 0x642ee20)
DEF(tss_array, 0x6430820)
DEF(pcpu_array, 0x6432280)
DEF(doreti_iret, -0x9aefbc)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x96f79a)
DEF(rdmsr_start, -0x9b046a)
DEF(wrmsr_ret, -0x9b183c)
DEF(dr2gpr_start, -0x9b6513)
DEF(gpr2dr_1_start, -0x9b63fa)
DEF(gpr2dr_2_start, -0x9b6307)
DEF(mov_cr3_rax, -0x39095e)
DEF(mov_rdi_cr3, -0x3909ce)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9b6700)
DEF(mprotect_fix_start, -0x8ee651)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2c927d)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1dd1de)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6b545f)
DEF(sigaction_fix_end, -0x6b5409)
DEF(sysents, 0x16f720)
DEF(sysents_ps4, 0x167170)
DEF(sysentvec, 0xca0cd8)
DEF(sysentvec_ps4, 0xca0e50)
DEF(sceSblServiceMailbox, -0x675db0)
DEF(sceSblAuthMgrSmIsLoadable2, -0x88a540)
DEF(mdbg_call_fix, -0x626d09)
DEF(syscall_before, -0x7e917f)
DEF(syscall_after, -0x7e915c)
DEF(malloc, -0xaa260)
DEF(M_something, 0x12d3d70)
DEF(loadSelfSegment_epilogue, -0x889dcd)
DEF(loadSelfSegment_watchpoint, -0x2c8868)
DEF(loadSelfSegment_watchpoint_lr, -0x88a027)
DEF(decryptSelfBlock_watchpoint_lr, -0x889c8a)
DEF(decryptSelfBlock_epilogue, -0x889bc3)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x889555)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8890d2)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x88a1bc)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x889e41)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x889914)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x88918c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x88a5be)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x92d9b0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x92df7b)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x92df05)
DEF(sceSblPfsSetKeys, -0x92dc60)
DEF(sceSblServiceCryptAsync, -0x8d1e30)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8d1df2)
DEF(copyin, -0x970050)
DEF(copyout, -0x970100)
DEF(crypt_message_resolve, -0x475750)
DEF(justreturn, -0x9af100)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xd4fe88)
DEF(pop_all_iret, -0x9af01b)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x94f6b8)
DEF(kernel_pmap_store, 0x31be218)
DEF(crypt_singleton_array, 0x2d99830)
DEF(security_flags, 0x6466474)
DEF(targetid, 0x646647d)
DEF(qa_flags, 0x6466490)
DEF(utoken, 0x6466500)
#include "offset_list.txt"
END_FW()

START_FW(320)
DEF(allproc, 0x276dc58)
DEF(idt, 0x642dc80)
DEF(gdt_array, 0x642ee20)
DEF(tss_array, 0x6430820)
DEF(pcpu_array, 0x6432280)
DEF(doreti_iret, -0x9aec7c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x96f45a)
DEF(rdmsr_start, -0x9b012a)
DEF(wrmsr_ret, -0x9b14fc)
DEF(dr2gpr_start, -0x9b61d3)
DEF(gpr2dr_1_start, -0x9b60ba)
DEF(gpr2dr_2_start, -0x9b5fc7)
DEF(mov_cr3_rax, -0x39060e)
DEF(mov_rdi_cr3, -0x39067e)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9b63c0)
DEF(mprotect_fix_start, -0x8ee311)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2c8f2d)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1dcd1e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6b510f)
DEF(sigaction_fix_end, -0x6b50b9)
DEF(sysents, 0x16f720)
DEF(sysents_ps4, 0x167170)
DEF(sysentvec, 0xca0cd8)
DEF(sysentvec_ps4, 0xca0e50)
DEF(sceSblServiceMailbox, -0x675a60)
DEF(sceSblAuthMgrSmIsLoadable2, -0x88a200)
DEF(mdbg_call_fix, -0x6269b9)
DEF(syscall_before, -0x7e8e2f)
DEF(syscall_after, -0x7e8e0c)
DEF(malloc, -0xa9da0)
DEF(M_something, 0x12d3d70)
DEF(loadSelfSegment_epilogue, -0x889a7d)
DEF(loadSelfSegment_watchpoint, -0x2c8518)
DEF(loadSelfSegment_watchpoint_lr, -0x889cd7)
DEF(decryptSelfBlock_watchpoint_lr, -0x88993a)
DEF(decryptSelfBlock_epilogue, -0x889873)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x889205)
DEF(decryptMultipleSelfBlocks_epilogue, -0x888d82)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x889e7c)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x889af1)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8895c4)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x888e3c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x88a27e)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x92d670)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x92dc3b)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x92dbc5)
DEF(sceSblPfsSetKeys, -0x92d920)
DEF(sceSblServiceCryptAsync, -0x8d1af0)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8d1ab2)
DEF(copyin, -0x96fd10)
DEF(copyout, -0x96fdc0)
DEF(crypt_message_resolve, -0x475400)
DEF(justreturn, -0x9aedc0)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xd4fe88)
DEF(pop_all_iret, -0x9aecdb)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x94e7d0)
DEF(kernel_pmap_store, 0x31be218)
DEF(crypt_singleton_array, 0x2d99830)
DEF(security_flags, 0x6466474)
DEF(targetid, 0x646647d)
DEF(qa_flags, 0x6466498)
DEF(utoken, 0x6466500)
#include "offset_list.txt"
END_FW()

START_FW(321)
DEF(allproc, 0x276dc58)
DEF(idt, 0x642dc80)
DEF(gdt_array, 0x642ee20)
DEF(tss_array, 0x6430820)
DEF(pcpu_array, 0x6432280)
DEF(doreti_iret, -0x9aec7c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x96f45a)
DEF(rdmsr_start, -0x9b012a)
DEF(wrmsr_ret, -0x9b14fc)
DEF(dr2gpr_start, -0x9b61d3)
DEF(gpr2dr_1_start, -0x9b60ba)
DEF(gpr2dr_2_start, -0x9b5fc7)
DEF(mov_cr3_rax, -0x39060e)
DEF(mov_rdi_cr3, -0x39067e)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9b63c0)
DEF(mprotect_fix_start, -0x8ee311)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2c8f2d)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1dcd1e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6b510f)
DEF(sigaction_fix_end, -0x6b50b9)
DEF(sysents, 0x16f720)
DEF(sysents_ps4, 0x167170)
DEF(sysentvec, 0xca0cd8)
DEF(sysentvec_ps4, 0xca0e50)
DEF(sceSblServiceMailbox, -0x675a60)
DEF(sceSblAuthMgrSmIsLoadable2, -0x88a200)
DEF(mdbg_call_fix, -0x6269b9)
DEF(syscall_before, -0x7e8e2f)
DEF(syscall_after, -0x7e8e0c)
DEF(malloc, -0xa9da0)
DEF(M_something, 0x12d3d70)
DEF(loadSelfSegment_epilogue, -0x889a7d)
DEF(loadSelfSegment_watchpoint, -0x2c8518)
DEF(loadSelfSegment_watchpoint_lr, -0x889cd7)
DEF(decryptSelfBlock_watchpoint_lr, -0x88993a)
DEF(decryptSelfBlock_epilogue, -0x889873)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x889205)
DEF(decryptMultipleSelfBlocks_epilogue, -0x888d82)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x889e7c)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x889af1)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8895c4)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x888e3c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x88a27e)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x92d670)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x92dc3b)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x92dbc5)
DEF(sceSblPfsSetKeys, -0x92d920)
DEF(sceSblServiceCryptAsync, -0x8d1af0)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8d1ab2)
DEF(copyin, -0x96fd10)
DEF(copyout, -0x96fdc0)
DEF(crypt_message_resolve, -0x475400)
DEF(justreturn, -0x9aedc0)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xd4fe88)
DEF(pop_all_iret, -0x9aecdb)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x94e4d0)
DEF(kernel_pmap_store, 0x31be218)
DEF(crypt_singleton_array, 0x2d99830)
DEF(security_flags, 0x6466474)
DEF(targetid, 0x646647d)
DEF(qa_flags, 0x6466498)
DEF(utoken, 0x6466500)
#include "offset_list.txt"
END_FW()

START_FW(400)
DEF(allproc, 0x27edcb8)
DEF(idt, 0x64cdc80)
DEF(gdt_array, 0x64cee30)
DEF(tss_array, 0x64d0830)
DEF(pcpu_array, 0x64d2280)
DEF(doreti_iret, -0x9cf84c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x99002a)
DEF(rdmsr_start, -0x9d0cfa)
DEF(wrmsr_ret, -0x9d20cc)
DEF(dr2gpr_start, -0x9d6d93)
DEF(gpr2dr_1_start, -0x9d6c7a)
DEF(gpr2dr_2_start, -0x9d6b87)
DEF(mov_cr3_rax, -0x39707e)
DEF(mov_rdi_cr3, -0x3970ee)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9d6f80)
DEF(mprotect_fix_start, -0x90ac61)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2cd3fd)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1df3ae)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6c2989)
DEF(sigaction_fix_end, -0x6c2933)
DEF(sysents, 0x1709c0)
DEF(sysents_ps4, 0x168410)
DEF(sysentvec, 0xd11bb8)
DEF(sysentvec_ps4, 0xd11d30)
DEF(sceSblServiceMailbox, -0x6824c0)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8a5c40)
DEF(mdbg_call_fix, -0x631eb9)
DEF(syscall_before, -0x802311)
DEF(syscall_after, -0x8022ee)
DEF(malloc, -0xa9be0)
DEF(M_something, 0x1346080)
DEF(loadSelfSegment_epilogue, -0x8a54cd)
DEF(loadSelfSegment_watchpoint, -0x2cc9f8)
DEF(loadSelfSegment_watchpoint_lr, -0x8a5727)
DEF(decryptSelfBlock_watchpoint_lr, -0x8a538a)
DEF(decryptSelfBlock_epilogue, -0x8a52c3)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8a4c55)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8a47d2)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8a58bc)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8a5541)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8a5014)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8a488c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8a5cbe)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x94a7f0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x94ada4)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x94ad2e)
DEF(sceSblPfsSetKeys, -0x94aaa0)
DEF(sceSblServiceCryptAsync, -0x8ed940)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8ed902)
DEF(copyin, -0x9908e0)
DEF(copyout, -0x990990)
DEF(crypt_message_resolve, -0x479e40)
DEF(justreturn, -0x9cf990)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xdc16e8)
DEF(pop_all_iret, -0x9cf8ab)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x96bc30)
DEF(kernel_pmap_store, 0x3257a78)
DEF(crypt_singleton_array, 0x2e31830)
DEF(security_flags, 0x6506474)
DEF(targetid, 0x650647d)
DEF(qa_flags, 0x6506498)
DEF(utoken, 0x6506500)
#include "offset_list.txt"
END_FW()

START_FW(402)
DEF(allproc, 0x27edcb8)
DEF(idt, 0x64cdc80)
DEF(gdt_array, 0x64cee30)
DEF(tss_array, 0x64d0830)
DEF(pcpu_array, 0x64d2280)
DEF(doreti_iret, -0x9cf84c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x99002a)
DEF(rdmsr_start, -0x9d0cfa)
DEF(wrmsr_ret, -0x9d20cc)
DEF(dr2gpr_start, -0x9d6d93)
DEF(gpr2dr_1_start, -0x9d6c7a)
DEF(gpr2dr_2_start, -0x9d6b87)
DEF(mov_cr3_rax, -0x39702e)
DEF(mov_rdi_cr3, -0x39709e)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9d6f80)
DEF(mprotect_fix_start, -0x90ac61)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2cd3ad)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1df35e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6c2989)
DEF(sigaction_fix_end, -0x6c2933)
DEF(sysents, 0x1709c0)
DEF(sysents_ps4, 0x168410)
DEF(sysentvec, 0xd11bb8)
DEF(sysentvec_ps4, 0xd11d30)
DEF(sceSblServiceMailbox, -0x6824c0)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8a5c40)
DEF(mdbg_call_fix, -0x631e99)
DEF(syscall_before, -0x802311)
DEF(syscall_after, -0x8022ee)
DEF(malloc, -0xa9b90)
DEF(M_something, 0x1346080)
DEF(loadSelfSegment_epilogue, -0x8a54cd)
DEF(loadSelfSegment_watchpoint, -0x2cc9a8)
DEF(loadSelfSegment_watchpoint_lr, -0x8a5727)
DEF(decryptSelfBlock_watchpoint_lr, -0x8a538a)
DEF(decryptSelfBlock_epilogue, -0x8a52c3)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8a4c55)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8a47d2)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8a58bc)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8a5541)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8a5014)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8a488c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8a5cbe)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x94a7f0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x94ada4)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x94ad2e)
DEF(sceSblPfsSetKeys, -0x94aaa0)
DEF(sceSblServiceCryptAsync, -0x8ed940)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8ed902)
DEF(copyin, -0x9908e0)
DEF(copyout, -0x990990)
DEF(crypt_message_resolve, -0x479df0)
DEF(justreturn, -0x9cf990)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xdc16e8)
DEF(pop_all_iret, -0x9cf8ab)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x96d208)
DEF(kernel_pmap_store, 0x3257a78)
DEF(crypt_singleton_array, 0x2e31830)
DEF(security_flags, 0x6505474)
DEF(targetid, 0x650547d)
DEF(qa_flags, 0x6505498)
DEF(utoken, 0x6505500)
#include "offset_list.txt"
END_FW()

START_FW(403)
DEF(allproc, 0x27edcb8) //data 0x33EDCB8
DEF(idt, 0x64cdc80) //data 0x70CDC80
DEF(gdt_array, 0x64cee30) //data 0x70CEE30
DEF(tss_array, 0x64d0830) //data 0x70D0830
DEF(pcpu_array, 0x64d2280) //data 0x70D2280
DEF(doreti_iret, -0x9cf84c) //data 0x2307B4
DEF(add_rsp_iret, doreti_iret - 7) //data 0x2307AD
DEF(swapgs_add_rsp_iret, doreti_iret - 10) //data 0x2307B4
DEF(rep_movsb_pop_rbp_ret, -0x99002a) //data 0x26FFD6
DEF(rdmsr_start, -0x9d0cfa) //data 0x22F306
DEF(wrmsr_ret, -0x9d20cc) //data 0x22DF34
DEF(dr2gpr_start, -0x9d6d93) //data 0x22926D
DEF(gpr2dr_1_start, -0x9d6c7a) //data 0x229386
DEF(gpr2dr_2_start, -0x9d6b87) //data 0x229479
DEF(mov_cr3_rax, -0x396f9e) //data 0x869062
DEF(mov_rdi_cr3, -0x39700e) //data 0x868FF2
DEF(nop_ret, wrmsr_ret + 2) //data 0x22DF36
DEF(cpu_switch, -0x9d6f80) //data 0x229080
DEF(mprotect_fix_start, -0x90ac61) //data 0x2F539F
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2cd31d)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1df2ce)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6c2989) //data 0x53D677
DEF(sigaction_fix_end, -0x6c2933) //data 0x53D6CD
DEF(sysents, 0x1709c0) //data 0xD709C0
DEF(sysents_ps4, 0x168410) //data 0xD68410
DEF(sysentvec, 0xd11bb8) //data 0x1911BB8
DEF(sysentvec_ps4, 0xd11d30) //data 0x1911D30
DEF(sceSblServiceMailbox, -0x6824c0) //data 0x57DB40
DEF(sceSblAuthMgrSmIsLoadable2, -0x8a5c40) //data 0x35A3C0
DEF(mdbg_call_fix, -0x631ea9) //data 0x5CE157
DEF(syscall_before, -0x802311) //data 0x3FDCEF
DEF(syscall_after, -0x8022ee) //data 0x3FDD12
DEF(malloc, -0xa9b00) //data 0xB56500
DEF(M_something, 0x1346080) //data 0x1F46080
DEF(loadSelfSegment_epilogue, -0x8a54cd) //data 0x35AB33
DEF(loadSelfSegment_watchpoint, -0x2cc918) //data 0x9336E8
DEF(loadSelfSegment_watchpoint_lr, -0x8a5727) //data 0x35A8D9
DEF(decryptSelfBlock_watchpoint_lr, -0x8a538a) //data 0x35AC76
DEF(decryptSelfBlock_epilogue, -0x8a52c3) //data 0x35AD3D
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8a4c55) //data 0x35B3AB
DEF(decryptMultipleSelfBlocks_epilogue, -0x8a47d2) //data 0x35B82E
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8a58bc) //data 0x35A744
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8a5541) //data 0x35AABF
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8a5014) //data 0x35AFEC
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8a488c) //data 0x35B774
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8a5cbe) //data 0x35A342
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x94a7f0) //data 0x2B5810
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x94ada4) //data 0x2B525C
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x94ad2e) //data 0x2B52D2
DEF(sceSblPfsSetKeys, -0x94aaa0) //data 0x2B5560
DEF(sceSblServiceCryptAsync, -0x8ed940) //data 0x3126C0
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8ed902) //data 0x3126FE
DEF(copyin, -0x9908e0) //data 0x26F720
DEF(copyout, -0x990990) //data 0x26F670
DEF(crypt_message_resolve, -0x479d60) //data 0x7862A0
DEF(justreturn, -0x9cf990) //data 0x230670
DEF(justreturn_pop, justreturn+8) //data 0x230678
DEF(mini_syscore_header, 0xdc16e8) //data 0x19C16E8
DEF(pop_all_iret, -0x9cf8ab) //data 0x230755
DEF(pop_all_except_rdi_iret, pop_all_iret+4) //data 0x230759
DEF(push_pop_all_iret, -0x96be70) //data 0x294190
DEF(kernel_pmap_store, 0x3257a78) //data 0x3E57A78
DEF(crypt_singleton_array, 0x2e31830) //data 0x3A31830
DEF(security_flags, 0x6506474) //data 0x7106474
DEF(targetid, 0x650647d) //data 0x710647D
DEF(qa_flags, 0x6506498) //data 0x7106498
DEF(utoken, 0x6506500) //data 0x7106500
#include "offset_list.txt"
END_FW()

START_FW(450)
DEF(allproc, 0x27edcb8)
DEF(idt, 0x64cdc80)
DEF(gdt_array, 0x64cee30)
DEF(tss_array, 0x64d0830)
DEF(pcpu_array, 0x64d2280)
DEF(doreti_iret, -0x9cf84c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x99002a /*-0x990a55*/)
DEF(rdmsr_start, -0x9d0cfa /*-0x9d6d02*/)
//DEF(rdmsr_end, -0x9d6cf9)
DEF(wrmsr_ret, -0x9d20cc)
DEF(dr2gpr_start, -0x9d6d93)
//DEF(dr2gpr_end, -0x9d6d7c)
DEF(gpr2dr_1_start, -0x9d6c7a)
//DEF(gpr2dr_1_end, -0x9d6c55)
DEF(gpr2dr_2_start, -0x9d6b87)
//DEF(gpr2dr_2_end, -0x9d6de9)
DEF(mov_cr3_rax, -0x396e4e)
DEF(mov_rdi_cr3, -0x396ebe)
DEF(nop_ret, -0x396de1)
DEF(cpu_switch, -0x9d6f80)
DEF(mprotect_fix_start, -0x90ac61)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2cd16d)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1df11e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6c2959)
DEF(sigaction_fix_end, -0x6c2903)
DEF(sysents, 0x1709c0)
DEF(sysents_ps4, 0x168410)
DEF(sysentvec, 0xd11bb8)
DEF(sysentvec_ps4, 0xd11d30)
DEF(sceSblServiceMailbox, -0x682490)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8a5be0)
DEF(mdbg_call_fix, -0x631e79)
DEF(syscall_before, -0x8022e1)
DEF(syscall_after, -0x8022be)
DEF(malloc, -0xa9940)
DEF(M_something, 0x1346080)
DEF(loadSelfSegment_epilogue, -0x8a546d)
DEF(loadSelfSegment_watchpoint, -0x2cc768)
DEF(loadSelfSegment_watchpoint_lr, -0x8a56c7)
//DEF(decryptSelfBlock_watchpoint, -0x2cc6de)
DEF(decryptSelfBlock_watchpoint_lr, -0x8a532a)
DEF(decryptSelfBlock_epilogue, -0x8a5263)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8a4bf5)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8a4772)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8a585c)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8a54e1)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8a4fb4)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8a482c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8a5c5e)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x94a7f0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x94ada4)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x94ad2e)
DEF(sceSblPfsSetKeys, -0x94aaa0)
//DEF(panic, -0x20e40)
DEF(sceSblServiceCryptAsync, -0x8ed930)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8ed8f2)
DEF(copyin, -0x9908e0)
DEF(copyout, -0x990990)
DEF(crypt_message_resolve, -0x479c30)
DEF(justreturn, -0x9cf990)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xdc16e8)
DEF(pop_all_iret, -0x9cf8ab)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x96db88)
DEF(kernel_pmap_store, 0x3257a78)
DEF(crypt_singleton_array, 0x2e31830)
DEF(security_flags, 0x6506474)
DEF(targetid, 0x650647d)
DEF(qa_flags, 0x6506498)
DEF(utoken, 0x6506500)
#include "offset_list.txt"
END_FW()

START_FW(451)
DEF(allproc, 0x27edcb8)
DEF(idt, 0x64cdc80)
DEF(gdt_array, 0x64cee30)
DEF(tss_array, 0x64d0830)
DEF(pcpu_array, 0x64d2280)
DEF(doreti_iret, -0x9cf84c)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x99002a)
DEF(rdmsr_start, -0x9d0cfa)
//DEF(rdmsr_end, -0x9d6cf9)
DEF(wrmsr_ret, -0x9d20cc)
DEF(dr2gpr_start, -0x9d6d93)
//DEF(dr2gpr_end, -0x9d6d7c)
DEF(gpr2dr_1_start, -0x9d6c7a)
//DEF(gpr2dr_1_end, -0x9d6c55)
DEF(gpr2dr_2_start, -0x9d6b87)
//DEF(gpr2dr_2_end, -0x9d6de9)
DEF(mov_cr3_rax, -0x396aae)
DEF(mov_rdi_cr3, -0x396b1e)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0x9d6f80)
DEF(mprotect_fix_start, -0x90ac61)
DEF(mprotect_fix_end, mprotect_fix_start+6)
DEF(mmap_self_fix_1_start, -0x2ccdcd)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, -0x1ded7e)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)
DEF(sigaction_fix_start, -0x6c2959)
DEF(sigaction_fix_end, -0x6c2903)
DEF(sysents, 0x1709c0)
DEF(sysents_ps4, 0x168410)
DEF(sysentvec, 0xd11bb8)
DEF(sysentvec_ps4, 0xd11d30)
DEF(sceSblServiceMailbox, -0x682490)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8a5be0)
DEF(mdbg_call_fix, -0x631e79)
DEF(syscall_before, -0x8022e1)
DEF(syscall_after, -0x8022be)
DEF(malloc, -0xa9510)
DEF(M_something, 0x1346080)
DEF(loadSelfSegment_epilogue, -0x8a546d)
DEF(loadSelfSegment_watchpoint, -0x2cc3c8)
DEF(loadSelfSegment_watchpoint_lr, -0x8a56c7)
//DEF(decryptSelfBlock_watchpoint, -0x2cc33e)
DEF(decryptSelfBlock_watchpoint_lr, -0x8a532a)
DEF(decryptSelfBlock_epilogue, -0x8a5263)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8a4bf5)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8a4772)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8a585c)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8a54e1)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8a4fb4)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8a482c)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8a5c5e)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x94a7f0)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x94ada4)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x94ad2e)
DEF(sceSblPfsSetKeys, -0x94aaa0)
//DEF(panic, -0x20a10)
DEF(sceSblServiceCryptAsync, -0x8ed930)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x8ed8f2)
DEF(copyin, -0x9908e0)
DEF(copyout, -0x990990)
DEF(crypt_message_resolve, -0x479890)
DEF(justreturn, -0x9cf990)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xdc16e8)
DEF(pop_all_iret, -0x9cf8ab)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x96d488)
DEF(kernel_pmap_store, 0x3257a78)
DEF(crypt_singleton_array, 0x2e31830)
DEF(security_flags, 0x6506474)
DEF(targetid, 0x650647d)
DEF(qa_flags, 0x6506498)
DEF(utoken, 0x6506500)
#include "offset_list.txt"
END_FW()

START_FW(500)
DEF(allproc, 0x291dd00) //data 0x355DD00
DEF(idt, 0x660dca0) //data 0x724DCA0
DEF(gdt_array, 0x660ee50) //data 0x724EE50
DEF(tss_array, 0x6610850) //data 0x7250850
DEF(pcpu_array, 0x6622680) //data 0x7262680
DEF(doreti_iret, -0xa04f93) //data 0x23B06D
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x9c576a) //data 0x27A896
DEF(rdmsr_start, -0xa0652a) //data 0x239AD6
DEF(wrmsr_ret, -0xa078fc) //data 0x238704
DEF(dr2gpr_start, -0xa0bf13) //data 0x2340ED
DEF(gpr2dr_1_start, -0xa0bdfa) //data 0x234206
DEF(gpr2dr_2_start, -0xa0bd07) //data 0x2342F9
DEF(mov_cr3_rax, -0x3a982e) //data 0x8967D2
DEF(mov_rdi_cr3, -0x3a989e) //data 0x896762
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0xa0c100) //data 0x233F00
DEF(mprotect_fix_start, -0x93efa2) //data 0x30105E
DEF(mprotect_fix_end, mprotect_fix_start+6)

DEF(mmap_self_fix_1_start, 0x0)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, 0x0)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)

DEF(sigaction_fix_start, -0x6e7db0) //data 0x558250
DEF(sigaction_fix_end, -0x6e7d6e) //data 0x558292
DEF(sysents, 0x1b1ef0) //data 0xDF1EF0
DEF(sysents_ps4, 0x1a9940) //data 0xDE9940
DEF(sysentvec, 0xe00be8) //data 0x1A40BE8
DEF(sysentvec_ps4, 0xe00d60) //data 0x1A40D60
DEF(sceSblServiceMailbox, -0x6a5de0) //data 0x59A220
DEF(sceSblAuthMgrSmIsLoadable2, -0x8d90d0) //data 0x366F30
DEF(mdbg_call_fix, -0x650049) //data 0x5EFFB7
DEF(syscall_before, -0x8357e1) //data 0x40A81F
DEF(syscall_after, -0x8357be) //data 0x40A842
DEF(malloc, -0xb4df0) //data 0xB8B210
DEF(M_something, 0x14355a0) //data 0x20755A0
DEF(loadSelfSegment_epilogue, -0x8d898d) //data 0x367673
DEF(loadSelfSegment_watchpoint, -0x2dd358) //data 0x962CA8
DEF(loadSelfSegment_watchpoint_lr, -0x8d8be7) //data 0x367419
DEF(decryptSelfBlock_watchpoint_lr, -0x8d885f) //data 0x3677A1
DEF(decryptSelfBlock_epilogue, -0x8d87a2) //data 0x36785E
//DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8112) //data 0x367EEE //403
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8119) //data 0x367EE7 //550
DEF(decryptMultipleSelfBlocks_epilogue, -0x8d7ee4) //data 0x36811C
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8d8d76) //data 0x36728A
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8d8a01) //data 0x3675FF
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8d8439) //data 0x367BC7
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8d7c58) //data 0x3683A8
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8d914e) //data 0x366EB2
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x97f430) //data 0x2C0BD0
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x97f9df) //data 0x2C0621
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x97f969) //data 0x2C0697
//DEF(sceSblPfsSetKeys, -0x97f6e0) //data 0x2C0920 // 403
DEF(sceSblPfsSetKeys, -0x9805e0) //data 0x2BFA20 // 550
DEF(sceSblServiceCryptAsync, -0x921ac0) //data 0x31E540
DEF(sceSblServiceCryptAsync_deref_singleton, -0x921a82) //data 0x31E57E
DEF(copyin, -0x9c6020) //data 0x279FE0
DEF(copyout, -0x9c60d0) //data 0x279F30
DEF(crypt_message_resolve, -0x48c080) //data 0x7B3F80
DEF(justreturn, -0xa051c0) //data 0x23AE40
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xeaf938) //data 0x1AEF938
DEF(pop_all_iret, -0xa04ff2) //data 0x23B00E
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x9a2d78) //data 0x29D288
DEF(kernel_pmap_store, 0x3398a88) //data 0x3FD8A88
DEF(crypt_singleton_array, 0x2f51830) //data 0x3B91830
DEF(security_flags, 0x66466ec) //data 0x72866EC
DEF(targetid, 0x66466f5) //data 0x72866F5
DEF(qa_flags, 0x6646710) //data 0x7286710
DEF(utoken, 0x6646778) //data 0x7286778
#include "offset_list.txt"
END_FW()

START_FW(502)
DEF(allproc, 0x291dd00) //data 0x355DD00
DEF(idt, 0x660dca0) //data 0x724DCA0
DEF(gdt_array, 0x660ee50) //data 0x724EE50
DEF(tss_array, 0x6610850) //data 0x7250850
DEF(pcpu_array, 0x6622680) //data 0x7262680
DEF(doreti_iret, -0xa04f93) //data 0x23B06D
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x9c576a) //data 0x27A896
DEF(rdmsr_start, -0xa0652a) //data 0x239AD6
DEF(wrmsr_ret, -0xa078fc) //data 0x238704
DEF(dr2gpr_start, -0xa0bf13) //data 0x2340ED
DEF(gpr2dr_1_start, -0xa0bdfa) //data 0x234206
DEF(gpr2dr_2_start, -0xa0bd07) //data 0x2342F9
DEF(mov_cr3_rax, -0x3a982e) //data 0x8967D2
DEF(mov_rdi_cr3, -0x3a989e) //data 0x896762
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0xa0c100) //data 0x233F00
DEF(mprotect_fix_start, -0x93efa2) //data 0x30105E
DEF(mprotect_fix_end, mprotect_fix_start+6)

DEF(mmap_self_fix_1_start, 0x0)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, 0x0)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)

DEF(sigaction_fix_start, -0x6e7db0) //data 0x558250
DEF(sigaction_fix_end, -0x6e7d6e) //data 0x558292
DEF(sysents, 0x1b1ef0) //data 0xDF1EF0
DEF(sysents_ps4, 0x1a9940) //data 0xDE9940
DEF(sysentvec, 0xe00be8) //data 0x1A40BE8
DEF(sysentvec_ps4, 0xe00d60) //data 0x1A40D60
DEF(sceSblServiceMailbox, -0x6a5de0) //data 0x59A220
DEF(sceSblAuthMgrSmIsLoadable2, -0x8d90d0) //data 0x366F30
DEF(mdbg_call_fix, -0x650049) //data 0x5EFFB7
DEF(syscall_before, -0x8357e1) //data 0x40A81F
DEF(syscall_after, -0x8357be) //data 0x40A842
DEF(malloc, -0xb4df0) //data 0xB8B210
DEF(M_something, 0x14355a0) //data 0x20755A0
DEF(loadSelfSegment_epilogue, -0x8d898d) //data 0x367673
DEF(loadSelfSegment_watchpoint, -0x2dd358) //data 0x962CA8
DEF(loadSelfSegment_watchpoint_lr, -0x8d8be7) //data 0x367419
DEF(decryptSelfBlock_watchpoint_lr, -0x8d885f) //data 0x3677A1
DEF(decryptSelfBlock_epilogue, -0x8d87a2) //data 0x36785E
//DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8112) //data 0x367EEE //403
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8119) //data 0x367EE7 //550
DEF(decryptMultipleSelfBlocks_epilogue, -0x8d7ee4) //data 0x36811C
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8d8d76) //data 0x36728A
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8d8a01) //data 0x3675FF
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8d8439) //data 0x367BC7
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8d7c58) //data 0x3683A8
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8d914e) //data 0x366EB2
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x97f430) //data 0x2C0BD0
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x97f9df) //data 0x2C0621
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x97f969) //data 0x2C0697
//DEF(sceSblPfsSetKeys, -0x97f6e0) //data 0x2C0920 // 403
DEF(sceSblPfsSetKeys, -0x9805e0) //data 0x2BFA20 // 550
DEF(sceSblServiceCryptAsync, -0x921ac0) //data 0x31E540
DEF(sceSblServiceCryptAsync_deref_singleton, -0x921a82) //data 0x31E57E
DEF(copyin, -0x9c6020) //data 0x279FE0
DEF(copyout, -0x9c60d0) //data 0x279F30
DEF(crypt_message_resolve, -0x48c080) //data 0x7B3F80
DEF(justreturn, -0xa051c0) //data 0x23AE40
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xeaf938) //data 0x1AEF938
DEF(pop_all_iret, -0xa04ff2) //data 0x23B00E
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x9a33c8) //data 0x29CC38
DEF(kernel_pmap_store, 0x3398a88) //data 0x3FD8A88
DEF(crypt_singleton_array, 0x2f51830) //data 0x3B91830
DEF(security_flags, 0x66466ec) //data 0x72866EC
DEF(targetid, 0x66466f5) //data 0x72866F5
DEF(qa_flags, 0x6646710) //data 0x7286710
DEF(utoken, 0x6646778) //data 0x7286778
#include "offset_list.txt"
END_FW()

START_FW(510)
DEF(allproc, 0x291dd00)
DEF(idt, 0x660dca0)
DEF(gdt_array, 0x660ee50)
DEF(tss_array, 0x6610850)
DEF(pcpu_array, 0x6622680)
DEF(doreti_iret, -0xa04f93)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x9c576a)
DEF(rdmsr_start, -0xa0652a)
DEF(wrmsr_ret, -0xa078fc)
DEF(dr2gpr_start, -0xa0bf13)
DEF(gpr2dr_1_start, -0xa0bdfa)
DEF(gpr2dr_2_start, -0xa0bd07)
DEF(mov_cr3_rax, -0x3a965e)
DEF(mov_rdi_cr3, -0x3a96ce)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0xa0c100)
DEF(mprotect_fix_start, -0x93efa2)
DEF(mprotect_fix_end, mprotect_fix_start+6)

DEF(mmap_self_fix_1_start, 0x0)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, 0x0)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)

DEF(sigaction_fix_start, -0x6e7be0)
DEF(sigaction_fix_end, -0x6e7b9e)
DEF(sysents, 0x1b2040)
DEF(sysents_ps4, 0x1a9a90)
DEF(sysentvec, 0xe00be8)
DEF(sysentvec_ps4, 0xe00d60)
DEF(sceSblServiceMailbox, -0x6a5c10)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8d90d0)
DEF(mdbg_call_fix, -0x64fe79)
DEF(syscall_before, -0x8357e1)
DEF(syscall_after, -0x8357be)
DEF(malloc, -0xb4ac0)
DEF(M_something, 0x14355a0)
DEF(loadSelfSegment_epilogue, -0x8d898d)
DEF(loadSelfSegment_watchpoint, -0x2dd108)
DEF(loadSelfSegment_watchpoint_lr, -0x8d8be7)
DEF(decryptSelfBlock_watchpoint_lr, -0x8d885f)
DEF(decryptSelfBlock_epilogue, -0x8d87a2)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8119)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8d7ee4)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8d8d76)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8d8A01)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8d8439)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8d7C58)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8d914E)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x97F430)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x97F9DF)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x97F969)
DEF(sceSblPfsSetKeys, -0x9805E0)
DEF(sceSblServiceCryptAsync, -0x921AC0)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x921A82)
DEF(copyin, -0x9c6020)
DEF(copyout, -0x9c60D0)
DEF(crypt_message_resolve, -0x48BEB0)
DEF(justreturn, -0xa051c0)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xeb0938)
DEF(pop_all_iret, -0xa04ff2)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x9a3e70)
DEF(kernel_pmap_store, 0x3398a88)
DEF(crypt_singleton_array, 0x2f51830)
DEF(security_flags, 0x66466EC)
DEF(targetid, 0x66466F5)
DEF(qa_flags, 0x6646710)
DEF(utoken, 0x6646778)
#include "offset_list.txt"
END_FW()

START_FW(550)
DEF(allproc, 0x291dd00)
DEF(idt, 0x660dca0)
DEF(gdt_array, 0x660ee50)
DEF(tss_array, 0x6610850)
DEF(pcpu_array, 0x6622680)
DEF(doreti_iret, -0xa04fd3)
DEF(add_rsp_iret, doreti_iret - 7)
DEF(swapgs_add_rsp_iret, doreti_iret - 10)
DEF(rep_movsb_pop_rbp_ret, -0x9c57aa)
DEF(rdmsr_start, -0xa0656a)
DEF(wrmsr_ret, -0xa0793c)
DEF(dr2gpr_start, -0xa0bf53)
DEF(gpr2dr_1_start, -0xa0be3a)
DEF(gpr2dr_2_start, -0xa0bd47)
DEF(mov_cr3_rax, -0x3a886e)
DEF(mov_rdi_cr3, -0x3a88de)
DEF(nop_ret, wrmsr_ret + 2)
DEF(cpu_switch, -0xa0c140)
DEF(mprotect_fix_start, -0x93EFE2)
DEF(mprotect_fix_end, mprotect_fix_start+6)

DEF(mmap_self_fix_1_start, 0x0)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, 0x0)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)

DEF(sigaction_fix_start, -0x6e7b30)
DEF(sigaction_fix_end, -0x6e7aee)
DEF(sysents, 0x1b2210)
DEF(sysents_ps4, 0x1a9c60)
DEF(sysentvec, 0xe00be8)
DEF(sysentvec_ps4, 0xe00d60)
DEF(sceSblServiceMailbox, -0x6a5b60)
DEF(sceSblAuthMgrSmIsLoadable2, -0x8d9110)
DEF(mdbg_call_fix, -0x64fb79)
DEF(syscall_before, -0x835731)
DEF(syscall_after, -0x83570e)
DEF(malloc, -0xb3cd0)
DEF(M_something, 0x14355a0)
DEF(loadSelfSegment_epilogue, -0x8d89CD)
DEF(loadSelfSegment_watchpoint, -0x2dC318)
DEF(loadSelfSegment_watchpoint_lr, -0x8d8C27)
DEF(decryptSelfBlock_watchpoint_lr, -0x8d889F)
DEF(decryptSelfBlock_epilogue, -0x8d87E2)
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8d8159)
DEF(decryptMultipleSelfBlocks_epilogue, -0x8d7F24)
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8d8DB6)
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8d8A41)
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8d8479)
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8d7C98)
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8d918E)
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x97F470)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x97FA1F)
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x97F9A9)
DEF(sceSblPfsSetKeys, -0x980620)
DEF(sceSblServiceCryptAsync, -0x921B00)
DEF(sceSblServiceCryptAsync_deref_singleton, -0x921AC2)
DEF(copyin, -0x9c6060)
DEF(copyout, -0x9c6110)
DEF(crypt_message_resolve, -0x48B0C0)
DEF(justreturn, -0xa05200)
DEF(justreturn_pop, justreturn+8)
DEF(mini_syscore_header, 0xeaf938)
DEF(pop_all_iret, -0xa05032)
DEF(pop_all_except_rdi_iret, pop_all_iret+4)
DEF(push_pop_all_iret, -0x99fc70)
DEF(kernel_pmap_store, 0x3394a88)
DEF(crypt_singleton_array, 0x2f4d830)
DEF(security_flags, 0x66466EC)
DEF(targetid, 0x66466F5)
DEF(qa_flags, 0x6646710)
DEF(utoken, 0x6646778)
#include "offset_list.txt"
END_FW()

START_FW(650)
DEF(allproc, 0x2869d20) //data 0x34C9D20
DEF(idt, 0x655dde0) //data 0x71BDDE0
DEF(gdt_array, 0x655f000) //data 0x71BF000
DEF(tss_array, 0x6560a00) //data 0x71C0A00
DEF(pcpu_array, 0x6572880) //data 0x71D2880
DEF(doreti_iret, -0xa1b813) //data 0x2447ED
DEF(add_rsp_iret, doreti_iret - 7) //data 0x2247E6
DEF(swapgs_add_rsp_iret, doreti_iret - 10) //data 0x2247E3
DEF(rep_movsb_pop_rbp_ret, -0x9dbfea) //data 0x284016
DEF(rdmsr_start, -0xa1cdaa) //data 0x243256
DEF(wrmsr_ret, -0xa1e17c) //data 0x241E84
DEF(dr2gpr_start, -0xa22793) //data 0x23D86D
DEF(gpr2dr_1_start, -0xa2267a) //data 0x23D986
DEF(gpr2dr_2_start, -0xa22587) //data 0x23DA79
DEF(mov_cr3_rax, -0x3aa0de) //data 0x8B5F22
DEF(mov_rdi_cr3, -0x3aa14e) //data 0x8B5EB2
DEF(nop_ret, wrmsr_ret + 2) //data 0x241E86
DEF(cpu_switch, -0xa22980) //data 0x23D680
DEF(mprotect_fix_start, -0x9546e2) //data 0x30B91E
DEF(mprotect_fix_end, mprotect_fix_start+6) //data 0x30B924

DEF(mmap_self_fix_1_start, 0x0)
DEF(mmap_self_fix_1_end, mmap_self_fix_1_start+2)
DEF(mmap_self_fix_2_start, 0x0)
DEF(mmap_self_fix_2_end, mmap_self_fix_2_start+2)

DEF(sigaction_fix_start, -0x6f6b12) //data 0x5694EE
DEF(sigaction_fix_end, -0x6f6ae8) //data 0x569518
DEF(sysents, 0x1b49f0) //data 0xE149F0
DEF(sysents_ps4, 0x1ac440) //data 0xE0C440
DEF(sysentvec, 0xe210a8) //data 0x1A810A8
DEF(sysentvec_ps4, 0xe21220) //data 0x1A81220
DEF(sceSblServiceMailbox, -0x6b2790) //data 0x5AD870
DEF(sceSblAuthMgrSmIsLoadable2, -0x8ed100) //data 0x372F00
DEF(mdbg_call_fix, -0x65c199) //data 0x603E67
DEF(syscall_before, -0x844a51) //data 0x41B5AF
DEF(syscall_after, -0x844a2e) //data 0x41B5D2
DEF(malloc, -0xa9d40) //data 0xBB62C0
DEF(M_something, 0x1456690) //data 0x20B6690
DEF(loadSelfSegment_epilogue, -0x8ec9cd) //data 0x373633
DEF(loadSelfSegment_watchpoint, -0x2da218) //data 0x985DE8
DEF(loadSelfSegment_watchpoint_lr, -0x8ecc27) //data 0x3733D9
DEF(decryptSelfBlock_watchpoint_lr, -0x8ec89f) //data 0x373761
DEF(decryptSelfBlock_epilogue, -0x8ec7e2) //data 0x37381E
//DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8ec152) //data 0x373EAE //403
DEF(decryptMultipleSelfBlocks_watchpoint_lr, -0x8ec159) //data 0x373EA7 //550
DEF(decryptMultipleSelfBlocks_epilogue, -0x8ebf24) //data 0x3740DC
DEF(sceSblServiceMailbox_lr_verifyHeader, -0x8ecdb9) //data 0x373247
DEF(sceSblServiceMailbox_lr_loadSelfSegment, -0x8eca41) //data 0x3735BF
DEF(sceSblServiceMailbox_lr_decryptSelfBlock, -0x8ec479) //data 0x373B87
DEF(sceSblServiceMailbox_lr_decryptMultipleSelfBlocks, -0x8ebc88) //data 0x374378
DEF(sceSblServiceMailbox_lr_sceSblAuthMgrSmFinalize, -0x8ed17e) //data 0x372E82
DEF(sceSblServiceMailbox_lr_verifySuperBlock, -0x995381) //data 0x2CAC7F
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_1, -0x995931) //data 0x2CA6CF
DEF(sceSblServiceMailbox_lr_sceSblPfsClearKey_2, -0x9958bb) //data 0x2CA745
//DEF(sceSblPfsSetKeys, -0x995630) //data 0x2CA9D0 //403
DEF(sceSblPfsSetKeys, -0x996400) //data 0x2C9C00 //550
DEF(sceSblServiceCryptAsync, -0x936090) //data 0x329F70
DEF(sceSblServiceCryptAsync_deref_singleton, -0x936052) //data 0x329FAE
DEF(copyin, -0x9dc8a0) //data 0x283760
DEF(copyout, -0x9dc950) //data 0x2836B0
DEF(crypt_message_resolve, -0x490060) //data 0x7CFFA0
DEF(justreturn, -0xa1ba40) //data 0x2445C0
DEF(justreturn_pop, justreturn+8) //data 0x2445C8
DEF(mini_syscore_header, 0xed2048) //data 0x1B32048
DEF(pop_all_iret, -0xa1b872) //data 0x24478E
DEF(pop_all_except_rdi_iret, pop_all_iret+4) //data 0x244792
DEF(push_pop_all_iret, -0x9ba368) //data 0x2A5C98
DEF(kernel_pmap_store, 0x32e4358) //data 0x3F44358
DEF(crypt_singleton_array, 0x2e9d830) //data 0x3AFD830
DEF(security_flags, 0x65968ec) //data 0x71F68EC
DEF(targetid, 0x65968f5) //data 0x71F68F5
DEF(qa_flags, 0x6596910) //data 0x71F6910
DEF(utoken, 0x6596978) //data 0x71F6978
#include "offset_list.txt"
END_FW()

void* dlsym(void*, const char*);

int set_offsets(void)
{
    uint32_t ver = r0gdb_get_fw_version() >> 16;
    switch(ver)
    {
#ifndef NO_BUILTIN_OFFSETS
    case 0x300: set_offsets_300(); break;
    case 0x310: set_offsets_310(); break;
    case 0x320: set_offsets_320(); break;
    case 0x321: set_offsets_321(); break;
    case 0x400: set_offsets_400(); break;
    case 0x402: set_offsets_402(); break;
    case 0x403: set_offsets_403(); break;
    case 0x450: set_offsets_450(); break;
    case 0x451: set_offsets_451(); break;
    case 0x500: set_offsets_500(); break;
    case 0x502: set_offsets_502(); break;
    case 0x510: set_offsets_510(); break;
    case 0x550: set_offsets_550(); break;
    case 0x650: set_offsets_650(); break;
#endif
    default: return -1;
    }
    return 0;
}
