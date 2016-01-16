################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include Robotics_2.0/subdir.mk
-include Robotics_2.0/WayPoint/subdir.mk
-include Robotics_2.0/STC/subdir.mk
-include Robotics_2.0/Robot/subdir.mk
-include Robotics_2.0/Plans/subdir.mk
-include Robotics_2.0/Particle/subdir.mk
-include Robotics_2.0/Map/subdir.mk
-include Robotics_2.0/Managers/subdir.mk
-include Robotics_2.0/Debug/subdir.mk
-include Robotics_2.0/Debug/WayPoint/subdir.mk
-include Robotics_2.0/Debug/STC/subdir.mk
-include Robotics_2.0/Debug/Robot/subdir.mk
-include Robotics_2.0/Debug/Plans/subdir.mk
-include Robotics_2.0/Debug/Particle/subdir.mk
-include Robotics_2.0/Debug/Map/subdir.mk
-include Robotics_2.0/Debug/Managers/subdir.mk
-include Robotics_2.0/Debug/Behaviors/subdir.mk
-include Robotics_2.0/Behaviors/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: roboticP

# Tool invocations
roboticP: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++  -o"roboticP" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(C++_DEPS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) roboticP
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
