#include "bitops.h"



int main()
{

    uint32_t a =31;
    bit_toggle(&a, 1);
    print_bits(a);

    printf("%d\n", bit_is_set(a, 31));

    return 0;
}


