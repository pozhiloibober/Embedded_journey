#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>

void sysTick_init();
void delay_ms(uint32_t ms);
void SysTick_Handler();

extern volatile uint32_t ms_ticks;



#endif

