################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../GPIO_Exercise/GPIO_Exercise.c \
../GPIO_Exercise/gpio.c 

OBJS += \
./GPIO_Exercise/GPIO_Exercise.o \
./GPIO_Exercise/gpio.o 

C_DEPS += \
./GPIO_Exercise/GPIO_Exercise.d \
./GPIO_Exercise/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
GPIO_Exercise/%.o: ../GPIO_Exercise/%.c GPIO_Exercise/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


