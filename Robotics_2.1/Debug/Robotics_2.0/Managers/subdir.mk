################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robotics_2.0/Managers/ConfigurationManager.cpp \
../Robotics_2.0/Managers/LocalizationManager.cpp \
../Robotics_2.0/Managers/Manager.cpp \
../Robotics_2.0/Managers/WaypointsManager.cpp 

OBJS += \
./Robotics_2.0/Managers/ConfigurationManager.o \
./Robotics_2.0/Managers/LocalizationManager.o \
./Robotics_2.0/Managers/Manager.o \
./Robotics_2.0/Managers/WaypointsManager.o 

CPP_DEPS += \
./Robotics_2.0/Managers/ConfigurationManager.d \
./Robotics_2.0/Managers/LocalizationManager.d \
./Robotics_2.0/Managers/Manager.d \
./Robotics_2.0/Managers/WaypointsManager.d 


# Each subdirectory must supply rules for building sources it contributes
Robotics_2.0/Managers/%.o: ../Robotics_2.0/Managers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


