
#include "stm32f767xx.h"
#include "bitops.h"
#include <stdint.h>
#include <stdbool.h>



void led_init();
void button_init();
void button_front_toggle();





int main(void)
{
	led_init();
	button_init();




	while(1)
	{


	}

	return 0;
}



void led_init()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;  				//led
	GPIOB->MODER &= ~(GPIO_MODER_MODER0_Msk);
	GPIOB->MODER |= GPIO_MODER_MODER0_0; 				// output

	GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_0);				// push pull
	GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0_Msk);
	GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0_Msk; 		// very high spped
	GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR0_Msk); 			// no pull up/down

}

void button_init()
{
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;  				// button
	GPIOC->MODER &= ~(GPIO_MODER_MODER13_Msk);  		// input mode

	GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13_Msk);
}

void button_front_toggle()
{
	static bool pressed = false;
	if(!(GPIOC->IDR & GPIO_IDR_IDR_13))
		{
			if(!pressed)
			{
				bit_toggle(&GPIOB->ODR, 0);
				pressed = true;
			}
		}
		else
		{
			if(pressed)
			{
				pressed = false;

			}
		}
}

