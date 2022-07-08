/*
 ============================================================================
 Name        : main.c
 Author      : Ahmed Khaled Hilal
 Description : Cooling controller using PID controller
 ============================================================================
*/


#include "PWM.h"
#include "RCC.h"
#include "PollerTimer.h"
#include "poller.h"
#include "device.h"


#define PWM_PRESCALER	(8000)	 /*with arr=0 gives us 0.5 sec periodic time*/

int main(void) {

	/*PWM configuration for Timer 5 channel 1 duty cycle is 0*/
	/*so we are selecting port A pin 0*/
	RCC_ENABLE_CLOCK(RCC_APB1ENR,_TIM5_RCC_ID);	/*enable clock for timer 5 for pwm*/
	GPIO_EnableClock(0); /*port A clock enabled*/
	GPIO_Init(0,0,ALTERNATE_FUN,PUSH_PULL);	/*setting PA0 as AF for the pwm output*/
	GPIO_REG(GPIOA,GPIO_AFRL) |= (0x02 << 0);	/*setting TIM5_CH1 as AF for PA0 */

	PWM_INIT(TIM5,1,PWM_PRESCALER,0);	/*Initialize pwm to 0% duty cycle*/
	PWM_START_TIMER(TIM5);

	Init_Device();	/*initialize TC72*/

	StartTimer();
	EnableInterrupt();
	SetPollingTime(500);	/*temperature sampling period 500 mSec*/
	StartPolling();


	while(1){

	}


	return 0;
}


void TIM2_IRQHandler(void)
{
	TIM2->SR &=~(1<<0);
	CallPollingFunction();
}

