#include "stm32f4xx_hal.h"
#include "Board_LED.h"

int main()
{
	HAL_Init();
	
	LED_Initialize();
	while(1)
	{
		LED_On(0);
		LED_On(1);
		LED_On(2);
		LED_On(3);
		HAL_Delay(100);
		
		LED_Off(0);
		LED_Off(1);
		LED_Off(2);
		LED_Off(3);
		HAL_Delay(100);
				
		
	}
	
}
/*
SysTick timer generates interrupts after periodic intervals. 
Whenever this interrupt occurs, HAL_IncTick() gets called, which increases uwTick by 1.

This allows HAL libraries to accurately generate a delay, without keeping the processor busy.
*/

void SysTick_Handler(void)
{
 HAL_IncTick();
 HAL_SYSTICK_IRQHandler();
#ifdef USE_RTOS_SYSTICK
 osSystickHandler();
#endif
}