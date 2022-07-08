#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

#include "GPIO.h"
#include "SPI.h"
#include "TC72.h"

#define TC72_SELECT()   (GPIO_WritePin(1, 0, 1))
#define TC72_UNSELECT() (GPIO_WritePin(1, 0, 0))

void Init_Device(void);
float Get_Data(void);

#endif /* INC_DEVICE_H_ */
