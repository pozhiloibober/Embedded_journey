#include "bitops.h"
#include "gpio.h"
#include <stdio.h>

int main()
{

    uint32_t a =31;
    bit_toggle(&a, 1);
    print_bits(a);

    printf("%d\n", bit_is_set(a, 31));

    uint32_t moder = 0;
    gpio_set_mode(&moder, 5, Output_Mode);   // пин 5 → биты 10-11 = 01
    print_bits(moder);                        // ждём ...00 0100 0000 0000

    gpio_set_mode(&moder, 15, AlternativeFun_Mode); // пин 15 → биты 30-31 = 10
    print_bits(moder);

    return 0;
}


