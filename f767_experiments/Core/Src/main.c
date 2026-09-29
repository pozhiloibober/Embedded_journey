#include "stm32f767xx.h"
#include "bitops.h"
#include "SysTick.h"
#include <stdint.h>
#include <stdbool.h>

void led_init();
void button_init();
void button_front_toggle();


void EXTI15_10_IRQHandler();


volatile bool button_event = false;



int main(void)
{
    led_init();
    button_init();
    sysTick_init();
    uint32_t last_toggle = 0;


    while(1)
    {
    	uint32_t now  = ms_ticks;
    	if(now - last_toggle >=1000)
    	{
    		last_toggle = now;
    		bit_toggle(&GPIOB->ODR, 0);
    	}
        if(button_event)
        {
            button_event = false;
            bit_toggle(&GPIOB->ODR, 7);
        }

        //delay_ms(1000);

    }

    return 0;
}

void led_init()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;                  //led
    GPIOB->MODER &= ~(GPIO_MODER_MODER0_Msk);
    GPIOB->MODER |= GPIO_MODER_MODER0_0;                 // output

    GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_0);                // push pull
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR0_Msk);
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR0_Msk;         // very high spped
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR0_Msk);             // no pull up/down

    GPIOB->MODER &= ~(GPIO_MODER_MODER7_Msk);
    GPIOB->MODER |= GPIO_MODER_MODER7_0;                 // output

    GPIOB->OTYPER &= ~(GPIO_OTYPER_OT_7);                // push pull
    GPIOB->OSPEEDR &= ~(GPIO_OSPEEDER_OSPEEDR7_Msk);
    GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR7_Msk;         // very high spped
    GPIOB->PUPDR &= ~(GPIO_PUPDR_PUPDR7_Msk);             // no pull up/down




}

void button_init()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;                  // button
    GPIOC->MODER &= ~(GPIO_MODER_MODER13_Msk);          // input mode
    GPIOC->PUPDR &= ~(GPIO_PUPDR_PUPDR13_Msk);

    RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;                  // SYSFG enable(Multiplexor for exti port)
    SYSCFG->EXTICR[3] &= ~(SYSCFG_EXTICR4_EXTI13_Msk);
    SYSCFG->EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC;

    EXTI->FTSR |= EXTI_FTSR_TR13;
    EXTI->IMR |= EXTI_IMR_IM13;
    EXTI->PR = EXTI_PR_PR13;
    NVIC_EnableIRQ(EXTI15_10_IRQn);

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

void EXTI15_10_IRQHandler(void)
{
    EXTI->PR = EXTI_PR_PR13;

    static uint32_t last_press = 0;
    uint32_t now = ms_ticks;

    if (now - last_press >= 20)
    {
        last_press = now;
        button_event = true;
    }
}




