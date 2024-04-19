################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/HAL/Comms/Communication.c 

OBJS += \
./Core/Src/HAL/Comms/Communication.o 

C_DEPS += \
./Core/Src/HAL/Comms/Communication.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/HAL/Comms/%.o Core/Src/HAL/Comms/%.su Core/Src/HAL/Comms/%.cyclo: ../Core/Src/HAL/Comms/%.c Core/Src/HAL/Comms/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-HAL-2f-Comms

clean-Core-2f-Src-2f-HAL-2f-Comms:
	-$(RM) ./Core/Src/HAL/Comms/Communication.cyclo ./Core/Src/HAL/Comms/Communication.d ./Core/Src/HAL/Comms/Communication.o ./Core/Src/HAL/Comms/Communication.su

.PHONY: clean-Core-2f-Src-2f-HAL-2f-Comms

