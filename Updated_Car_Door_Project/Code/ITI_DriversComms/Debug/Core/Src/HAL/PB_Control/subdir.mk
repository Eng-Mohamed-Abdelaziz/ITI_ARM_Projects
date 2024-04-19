################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/PB_Control/PB_Control.c 

OBJS += \
./Core/Src/HAL/PB_Control/PB_Control.o 

C_DEPS += \
./Core/Src/HAL/PB_Control/PB_Control.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/PB_Control/%.o Core/Src/HAL/PB_Control/%.su Core/Src/HAL/PB_Control/%.cyclo: ../Core/Src/HAL/PB_Control/%.c Core/Src/HAL/PB_Control/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL-2f-PB_Control

clean-Core-2f-Src-2f-HAL-2f-PB_Control:
	-$(RM) ./Core/Src/HAL/PB_Control/PB_Control.cyclo ./Core/Src/HAL/PB_Control/PB_Control.d ./Core/Src/HAL/PB_Control/PB_Control.o ./Core/Src/HAL/PB_Control/PB_Control.su

.PHONY: clean-Core-2f-Src-2f-HAL-2f-PB_Control

