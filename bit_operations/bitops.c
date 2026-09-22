#include "bitops.h"
#include <stdio.h>
#include <assert.h>

void print_bits(uint32_t n)
{
    for(int size = sizeof(n)*8-1; size>=0; size--)
        printf("%d", (n>>size)&1U);

    printf("\n");
}

void bit_set(uint32_t* reg, uint8_t n)
{
    assert(reg != NULL);
    assert(n<32);
    *reg|= (1U << n);
}

void bit_clear(uint32_t* reg, uint8_t n)
{

    assert(reg != NULL);
    assert(n<32);
    *reg &= ~(1U << n);
}

void bit_toggle(uint32_t* reg, uint8_t n)
{
    assert(reg != NULL);
    assert(n<32);
    *reg ^= (1U << n);
}

int bit_is_set(const uint32_t reg, uint8_t n)
{
    assert(n<32);
    return (reg >> n) & 1U;
}

void set_field(uint32_t* reg, uint8_t poz, uint8_t width, uint32_t value)
{
    assert(reg!=NULL);
    assert(poz<32);
    assert((poz+width)<=32);
    value = value & ((1U << width)-1);

    *reg &= ~(((1U<<width)-1) << poz);
    *reg |= (value<<poz);
}


