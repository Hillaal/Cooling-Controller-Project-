/*
 ============================================================================
 Name        :PollDataClient.c
 Author      : Ahmed Khaled Hilal
 Description : PID controller to generate a PWM signal based on the
			deviation between the read temperature from the sensor and the set temperature point.
 ============================================================================
*/



#include "PollingDataClient.h"
#include "PWM.h"
#include "USART.h"

#define setTemperature 	(30)

#define Kp 	(0.1f)
#define Ki 	(0.01f)
#define Kd 	(0.0f)

#define dutyCycleMax	(0.73f)
#define dutyCycleMin	(0.0f)

char usart2Data[] = {'-', ' ', ' ', '.', ' ', ' ', '\r', '\n', '\0'};

int measured;
int error;
int integral;
float pwm_signal;


void floatToStr(float val, char data[]) {
  if (val < 0) {
    *data = '-';
    data++;
    val *= -1;
  }
  int intVal = val * 100;
  data[4] = (intVal % 10) + '0';
  intVal /= 10;
  data[3] = (intVal % 10) + '0';
  data[2] = '.';
  intVal /= 10;
  data[1] = (intVal % 10) + '0';
  intVal /= 10;
  data[0] = (intVal % 10) + '0';

  data[5] = '\r';
  data[6] = '\n';
  data[7] = '\0';
}






void Handle_data(float data)
{
	measured = data;
	error = measured - 30;
	integral = integral + error;

	pwm_signal = (error*Kp) + (integral*Ki);


	if(pwm_signal >= dutyCycleMax){
		pwm_signal = dutyCycleMax;
	}

	else if (pwm_signal <= dutyCycleMin){
		pwm_signal = dutyCycleMin;
	}

	else{
		/*do nothing*/
	}

	PWM_ChangeDutycycle(TIM5, 1, (int)((pwm_signal*100)));

	 floatToStr(pwm_signal, usart2Data);
	 USART2_Transmit(usart2Data);			/*for watching the PMW duty cycle change on terminal*/
}
