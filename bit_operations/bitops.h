#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>


void print_bits(uint32_t n);
void bit_set(volatile uint32_t* reg, uint8_t n);
void bit_clear(volatile uint32_t* reg, uint8_t n);
void bit_toggle(volatileuint32_t* reg, uint8_t n);
int bit_is_set(const volatile uint32_t reg, uint8_t n);
void set_field(volatile uint32_t* reg, uint8_t poz, uint8_t width, uint32_t value);


#endif // BITOPS_H
