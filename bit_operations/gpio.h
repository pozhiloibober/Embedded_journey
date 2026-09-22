#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

enum GPIO_MODER_T
{
    Input_Mode = 0,
    Output_Mode = 1,
    AlternativeFun_Mode = 2,
    Analog_Mode = 3
};

void gpio_set_mode(uint32_t* moder_reg, uint8_t pin, enum GPIO_MODER_T mode);


#endif // GPIO_H
