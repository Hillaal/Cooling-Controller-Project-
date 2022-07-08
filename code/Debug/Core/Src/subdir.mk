################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/GPIO.c \
../Core/Src/PWM.c \
../Core/Src/PollDataClient.c \
../Core/Src/PollerTimer.c \
../Core/Src/SPI.c \
../Core/Src/TC72.c \
../Core/Src/USART.c \
../Core/Src/device.c \
../Core/Src/main.c \
../Core/Src/poller.c \
../Core/Src/system_stm32f4xx.c 

OBJS += \
./Core/Src/GPIO.o \
./Core/Src/PWM.o \
./Core/Src/PollDataClient.o \
./Core/Src/PollerTimer.o \
./Core/Src/SPI.o \
./Core/Src/TC72.o \
./Core/Src/USART.o \
./Core/Src/device.o \
./Core/Src/main.o \
./Core/Src/poller.o \
./Core/Src/system_stm32f4xx.o 

C_DEPS += \
./Core/Src/GPIO.d \
./Core/Src/PWM.d \
./Core/Src/PollDataClient.d \
./Core/Src/PollerTimer.d \
./Core/Src/SPI.d \
./Core/Src/TC72.d \
./Core/Src/USART.d \
./Core/Src/device.d \
./Core/Src/main.d \
./Core/Src/poller.d \
./Core/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

