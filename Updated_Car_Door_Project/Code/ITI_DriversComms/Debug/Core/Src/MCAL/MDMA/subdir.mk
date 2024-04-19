################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/MCAL/MDMA/MDMA_Prog.c 

OBJS += \
./Core/Src/MCAL/MDMA/MDMA_Prog.o 

C_DEPS += \
./Core/Src/MCAL/MDMA/MDMA_Prog.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/MCAL/MDMA/%.o Core/Src/MCAL/MDMA/%.su Core/Src/MCAL/MDMA/%.cyclo: ../Core/Src/MCAL/MDMA/%.c Core/Src/MCAL/MDMA/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-MCAL-2f-MDMA

clean-Core-2f-Src-2f-MCAL-2f-MDMA:
	-$(RM) ./Core/Src/MCAL/MDMA/MDMA_Prog.cyclo ./Core/Src/MCAL/MDMA/MDMA_Prog.d ./Core/Src/MCAL/MDMA/MDMA_Prog.o ./Core/Src/MCAL/MDMA/MDMA_Prog.su

.PHONY: clean-Core-2f-Src-2f-MCAL-2f-MDMA

