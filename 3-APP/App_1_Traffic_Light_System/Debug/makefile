################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
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

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
App_1_Traffic_Light_System.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: App_1_Traffic_Light_System.elf secondary-outputs

# Tool invocations
App_1_Traffic_Light_System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,App_1_Traffic_Light_System.map -mmcu=atmega32 -o "App_1_Traffic_Light_System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

App_1_Traffic_Light_System.lss: App_1_Traffic_Light_System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S App_1_Traffic_Light_System.elf  >"App_1_Traffic_Light_System.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: App_1_Traffic_Light_System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 App_1_Traffic_Light_System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) App_1_Traffic_Light_System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
