#include "bitops.h"

#define PAGE_SIZE_BITS PAGE_SIZE * 8 - 1

bool getbit(byte data, u8 bit_number) {
    return data >> bit_number & 0b1;
}

bool getbit_s(byte data, u8 bit_number) {
    return data >> ((bit_number > 7) ? 0 : bit_number) & 0b1;
}

bool qgetbit(qword data, u8 bit_number) {
    return data >> bit_number & 0b1;
}

bool getbit_block(block data, u32 block_size, u64 bit_number) {
    u64 block_size_bits = block_size * 8 - 1, bit_number_copy = bit_number;
    while ((block_size_bits - bit_number_copy) / 8 % 1 != 0)
        --bit_number_copy;
    bit_number_copy /= 8;
    while (bit_number > 7)
        bit_number -= 8;
    return getbit(data[bit_number_copy], bit_number);
}

bool getbit_page(page data, u64 bit_number) {
    u64 block_size_bits = PAGE_SIZE_BITS, bit_number_copy = bit_number;
    while ((block_size_bits - bit_number_copy) / 8 % 1 != 0)
        --bit_number_copy;
    bit_number_copy /= 8;
    while (bit_number > 7)
        bit_number -= 8;
    return getbit(data[bit_number_copy], bit_number);
}

bitgroup get_bitgroup_byte(byte data, u8 offset, u8 group_size) {
    return data << (8 - group_size - offset) >> (8 - group_size);
}

bitgroup get_bitgroup_word(word data, u8 offset, u8 group_size) {
    return data << (16 - group_size - offset) >> (16 - group_size);
}

bitgroup get_bitgroup_dword(dword data, u8 offset, u8 group_size) {
    return data << (32 - group_size - offset) >> (32 - group_size);
}

bitgroup get_bitgroup_qword(qword data, u8 offset, u8 group_size) {
    return data << (64 - group_size - offset) >> (64 - group_size);
}