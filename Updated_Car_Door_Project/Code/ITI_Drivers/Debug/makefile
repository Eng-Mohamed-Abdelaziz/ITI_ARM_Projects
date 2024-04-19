################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/MCAL/MUSART/subdir.mk
-include Core/Src/MCAL/MSTK/subdir.mk
-include Core/Src/MCAL/MSPI/subdir.mk
-include Core/Src/MCAL/MRCC/subdir.mk
-include Core/Src/MCAL/MNVIC/subdir.mk
-include Core/Src/MCAL/MGPIO/subdir.mk
-include Core/Src/MCAL/MEXTI/subdir.mk
-include Core/Src/MCAL/MDMA/subdir.mk
-include Core/Src/MCAL/FLASH/subdir.mk
-include Core/Src/HAL/PB_Control/subdir.mk
-include Core/Src/HAL/LED_Control/subdir.mk
-include Core/Src/HAL/DC_Motor/subdir.mk
-include Core/Src/HAL/Comms/subdir.mk
-include Core/Src/HAL/Buzzer_Control/subdir.mk
-include Core/Src/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ITI_Drivers
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
ITI_Drivers.elf \

MAP_FILES += \
ITI_Drivers.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
ITI_Drivers.list \

OBJCOPY_HEX += \
ITI_Drivers.hex \


# All Target
all: main-build

# Main-build Target
main-build: ITI_Drivers.elf secondary-outputs

# Tool invocations
ITI_Drivers.elf ITI_Drivers.map: $(OBJS) $(USER_OBJS) D:\ARM_WS\ITI_Drivers\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "ITI_Drivers.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\ARM_WS\ITI_Drivers\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="ITI_Drivers.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

ITI_Drivers.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "ITI_Drivers.list"
	@echo 'Finished building: $@'
	@echo ' '

ITI_Drivers.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "ITI_Drivers.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ITI_Drivers.elf ITI_Drivers.hex ITI_Drivers.list ITI_Drivers.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
