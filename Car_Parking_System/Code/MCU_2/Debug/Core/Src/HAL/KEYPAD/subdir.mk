################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/KEYPAD/Keypad.c 

OBJS += \
./Core/Src/HAL/KEYPAD/Keypad.o 

C_DEPS += \
./Core/Src/HAL/KEYPAD/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/KEYPAD/%.o Core/Src/HAL/KEYPAD/%.su Core/Src/HAL/KEYPAD/%.cyclo: ../Core/Src/HAL/KEYPAD/%.c Core/Src/HAL/KEYPAD/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL-2f-KEYPAD

clean-Core-2f-Src-2f-HAL-2f-KEYPAD:
	-$(RM) ./Core/Src/HAL/KEYPAD/Keypad.cyclo ./Core/Src/HAL/KEYPAD/Keypad.d ./Core/Src/HAL/KEYPAD/Keypad.o ./Core/Src/HAL/KEYPAD/Keypad.su

.PHONY: clean-Core-2f-Src-2f-HAL-2f-KEYPAD

