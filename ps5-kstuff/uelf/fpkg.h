#pragma once
#include <sys/types.h>
#include <sys/syscall.h>

extern char sceSblServiceMailbox[];
extern char sceSblServiceMailbox_lr_verifySuperBlock[];
extern char sceSblServiceMailbox_lr_sceSblPfsClearKey_1[];
extern char sceSblServiceMailbox_lr_sceSblPfsClearKey_2[];
extern char sceSblServiceCryptAsync_deref_singleton[];
extern char crypt_message_resolve[];
extern char doreti_iret[];


void handle_fpkg_numount_syscall(uint64_t* regs);
void handle_fpkg_trap(uint64_t* regs, uint32_t trapno);
void handle_fpkg_mount_syscall(uint64_t* regs);
int try_handle_fpkg_trap(uint64_t* regs);
int try_handle_fpkg_mailbox(uint64_t* regs, uint64_t lr);
