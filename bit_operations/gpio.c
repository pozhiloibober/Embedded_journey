#include "gpio.h"
#include "bitops.h"
#include <assert.h>
#include <stdio.h>
void gpio_set_mode(uint32_t* moder_reg, uint8_t pin, enum GPIO_MODER_T mode)
{
    assert(moder_reg!=NULL);
    assert(pin<16);
    assert(mode <= Analog_Mode);
    set_field(moder_reg, pin*2, 2, (uint8_t)mode);
}
