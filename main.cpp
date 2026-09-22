#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void print_bits(uint32_t n);
void bit_set(uint32_t* reg, uint8_t n);
void bit_clear(uint32_t* reg, uint8_t n);
void bit_toggle(uint32_t* reg, uint8_t n);
int bit_is_set(const uint32_t reg, uint8_t n);

int main()
{

    uint32_t a =31;
    bit_toggle(&a, 1);
    print_bits(a);

    printf("%d\n", bit_is_set(a, 31));

    return 0;
}

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
