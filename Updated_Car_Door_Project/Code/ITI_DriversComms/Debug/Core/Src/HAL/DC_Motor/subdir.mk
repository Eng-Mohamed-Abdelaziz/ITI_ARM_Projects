################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/DC_Motor/DC_Motor.c 

OBJS += \
./Core/Src/HAL/DC_Motor/DC_Motor.o 

C_DEPS += \
./Core/Src/HAL/DC_Motor/DC_Motor.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/DC_Motor/%.o Core/Src/HAL/DC_Motor/%.su Core/Src/HAL/DC_Motor/%.cyclo: ../Core/Src/HAL/DC_Motor/%.c Core/Src/HAL/DC_Motor/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL-2f-DC_Motor

clean-Core-2f-Src-2f-HAL-2f-DC_Motor:
	-$(RM) ./Core/Src/HAL/DC_Motor/DC_Motor.cyclo ./Core/Src/HAL/DC_Motor/DC_Motor.d ./Core/Src/HAL/DC_Motor/DC_Motor.o ./Core/Src/HAL/DC_Motor/DC_Motor.su

.PHONY: clean-Core-2f-Src-2f-HAL-2f-DC_Motor

