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
-include Core/Src/MCAL/MTIM/subdir.mk
-include Core/Src/MCAL/MSTK/subdir.mk
-include Core/Src/MCAL/MSPI/subdir.mk
-include Core/Src/MCAL/MRCC/subdir.mk
-include Core/Src/MCAL/MNVIC/subdir.mk
-include Core/Src/MCAL/MGPIO/subdir.mk
-include Core/Src/MCAL/MEXTI/subdir.mk
-include Core/Src/LIB/subdir.mk
-include Core/Src/HAL/Push_Button/subdir.mk
-include Core/Src/HAL/LED/subdir.mk
-include Core/Src/HAL/LCD/subdir.mk
-include Core/Src/HAL/KEYPAD/subdir.mk
-include Core/Src/HAL/IR/subdir.mk
-include Core/Src/HAL/DC_Motor/subdir.mk
-include Core/Src/HAL/Comms/subdir.mk
-include Core/Src/HAL/Buzzer/subdir.mk
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


BUILD_ARTIFACT_NAME := MCU_2
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
MCU_2.elf \

MAP_FILES += \
MCU_2.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
MCU_2.list \

OBJCOPY_HEX += \
MCU_2.hex \


# All Target
all: main-build

# Main-build Target
main-build: MCU_2.elf secondary-outputs

# Tool invocations
MCU_2.elf MCU_2.map: $(OBJS) $(USER_OBJS) D:\ARM_WS\MCU_2\STM32F401CCUX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "MCU_2.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"D:\ARM_WS\MCU_2\STM32F401CCUX_FLASH.ld" --specs=nosys.specs -Wl,-Map="MCU_2.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

MCU_2.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "MCU_2.list"
	@echo 'Finished building: $@'
	@echo ' '

MCU_2.hex: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objcopy  -O ihex $(EXECUTABLES) "MCU_2.hex"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) MCU_2.elf MCU_2.hex MCU_2.list MCU_2.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_HEX)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
