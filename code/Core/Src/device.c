#include "device.h"
#include "USART.h"



void Init_Device(void){

	  USART2_Init();
	  USART2_Transmit("Hello SPI\r\n");

	/*SPI configuration on port B pin 0 */
	/* Slave Select */
	GPIO_EnableClock(1);
	GPIO_Init(1, 0, OUTPUT, PUSH_PULL);
	GPIO_WritePin(1, 0, 0);

	SPI1_Init(MASTER, IDLE_LOW, SAMPLE_SOCAND_TRANSITION);

	TC72_SELECT();
	TC72_Init(0);
	TC72_UNSELECT();

}


float Get_Data(void)
{
	unsigned char spiData = 0;
	float temperature = 0;

	TC72_SELECT();
	TC72_RegisterRead(0x01, &spiData);
	TC72_UNSELECT();

	if (spiData & (1 << 7)) {
		temperature += 0.5f;
	}
	if (spiData & (1 << 6)) {
		  temperature += 0.25f;
	}

	TC72_SELECT();
	TC72_RegisterRead(0x02, &spiData);
	TC72_UNSELECT();

	temperature += (signed char)spiData;



	return temperature;
}
