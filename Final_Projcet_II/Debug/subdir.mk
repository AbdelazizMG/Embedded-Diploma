################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Buzzer.c \
../DC_Motor.c \
../Operations_II.c \
../PWM.c \
../Timers.c \
../UART.c \
../gpio.c \
../main.c 

OBJS += \
./Buzzer.o \
./DC_Motor.o \
./Operations_II.o \
./PWM.o \
./Timers.o \
./UART.o \
./gpio.o \
./main.o 

C_DEPS += \
./Buzzer.d \
./DC_Motor.d \
./Operations_II.d \
./PWM.d \
./Timers.d \
./UART.d \
./gpio.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


