#pragma once
#include <sys/types.h>

extern struct
{
    uint64_t bitmask;
    char pad[24];
    char key_data[63][32];
    uint64_t uexec_cr3;
    uint64_t uexec_entry;
    uint64_t uexec_counter;
} shared_area;
