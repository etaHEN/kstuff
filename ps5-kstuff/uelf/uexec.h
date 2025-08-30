#pragma once
#include <stdint.h>

int handle_uexec(uint64_t* regs, uint64_t* args);
void handle_uexec_trap(uint64_t* regs, uint32_t trap);
int try_handle_uexec_trap(uint64_t* regs);
void uexec_ipi(uint64_t* regs);
