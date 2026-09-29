#include "SysTick.h"
#include "stm32f767xx.h"

volatile uint32_t ms_ticks = 0;

void sysTick_init()
{
	SysTick->CTRL |= SysTick_CTRL_TICKINT_Msk;
	SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;

	SysTick->LOAD = ((SystemCoreClock / 1000)-1);
	SysTick->VAL = 0;
	SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;

}

void SysTick_Handler()
{
	ms_ticks++;
}

void delay_ms(uint32_t ms)
{
	uint32_t start = ms_ticks;
	while(ms_ticks - start < ms);
}
