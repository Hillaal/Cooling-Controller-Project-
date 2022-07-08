/*
 ============================================================================
 Name        : rcc.h
 Author      : Ahmed Khaled Hilal
 Description : enable/disable clk of rcc
 ============================================================================
*/


#ifndef INC_RCC_H_
#define INC_RCC_H_


/*RCC buses registers */
#define RCC_AHB1ENR		*((volatile unsigned int*)(0x40023800 + 0x30))
#define RCC_AHB2ENR		*((volatile unsigned int*)(0x40023800 + 0x34))
#define RCC_AHB3ENR		*((volatile unsigned int*)(0x40023800 + 0x38))
#define RCC_APB1ENR		*((volatile unsigned int*)(0x40023800 + 0x40))
#define RCC_APB2ENR		*((volatile unsigned int*)(0x40023800 + 0x44))


/*functions declaration*/

#define RCC_ENABLE_CLOCK(BUS,PIN)	((BUS) |= (1<<PIN))
#define RCC_DISABLE_CLOCK(BUS,PIN)	((BUS) &= ~(1<<PIN))



#endif /* INC_RCC_H_ */
