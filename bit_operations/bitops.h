#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>
#include <stdio.h>
#include <assert.h>

void print_bits(uint32_t n);
void bit_set(uint32_t* reg, uint8_t n);
void bit_clear(uint32_t* reg, uint8_t n);
void bit_toggle(uint32_t* reg, uint8_t n);
int bit_is_set(const uint32_t reg, uint8_t n);
void set_field(uint32_t* reg, uint8_t poz, uint8_t width, uint32_t value);


#endif // BITOPS_H
