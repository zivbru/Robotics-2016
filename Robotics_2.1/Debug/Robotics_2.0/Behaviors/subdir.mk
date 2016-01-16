################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robotics_2.0/Behaviors/Behavior.cpp \
../Robotics_2.0/Behaviors/GoForward.cpp \
../Robotics_2.0/Behaviors/GoToWayPoint.cpp 

OBJS += \
./Robotics_2.0/Behaviors/Behavior.o \
./Robotics_2.0/Behaviors/GoForward.o \
./Robotics_2.0/Behaviors/GoToWayPoint.o 

CPP_DEPS += \
./Robotics_2.0/Behaviors/Behavior.d \
./Robotics_2.0/Behaviors/GoForward.d \
./Robotics_2.0/Behaviors/GoToWayPoint.d 


# Each subdirectory must supply rules for building sources it contributes
Robotics_2.0/Behaviors/%.o: ../Robotics_2.0/Behaviors/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


