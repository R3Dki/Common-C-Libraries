#pragma once

#include <stdio.h>
#include "types.h"

#define BITOPS_LIB_VER_MAJOR 1
#define BITOPS_LIB_VER_MINOR 0
#define BITOPS_LIB_VER_PATCH 1

#ifndef BITOPS_LIB
#define BITOPS_LIB

// Gets specified bit from byte
// This is unsafe as it accepts bit_number values greater than 7 which results in undefined behaviour.
bool getbit(byte data, u8 bit_number);

// Checks if bit_number is in bounds and gets the specified bit from the byte.
// This alternative is better for security reasons, although it's slightly slower.
bool getbit_s(byte data, u8 bit_number);

// Gets specified bit from qword.
// This is unsafe as it accepts bit_number values greater than 7 which results in undefined behaviour.
bool qgetbit(qword data, u8 bit_number);

// Gets specified bit from a block.
bool getbit_block(block data, u32 block_size, u64 bit_number); // WORKING (MIGHT NEED UPDATING)

// Gets specified bit from a page.
bool getbit_page(page data, u64 bit_number); // WORKING (MIGHT NEED UPDATING)

// Gets a group of bits from a byte.
// UNSAFE
bitgroup get_bitgroup_byte(byte data, u8 offset, u8 group_size);

// Gets a group of bits from a word.
// UNSAFE
bitgroup get_bitgroup_word(word data, u8 offset, u8 group_size);

// Gets a group of bits from a dword.
// UNSAFE
bitgroup get_bitgroup_dword(dword data, u8 offset, u8 group_size);

// Gets a group of bits from a qword.
// UNSAFE
bitgroup get_bitgroup_qword(qword data, u8 offset, u8 group_size);

#endif // BITOPS_LIB