################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robotics_2.0/Plans/ObstacleAvoidPlan.cpp \
../Robotics_2.0/Plans/Plan.cpp 

OBJS += \
./Robotics_2.0/Plans/ObstacleAvoidPlan.o \
./Robotics_2.0/Plans/Plan.o 

CPP_DEPS += \
./Robotics_2.0/Plans/ObstacleAvoidPlan.d \
./Robotics_2.0/Plans/Plan.d 


# Each subdirectory must supply rules for building sources it contributes
Robotics_2.0/Plans/%.o: ../Robotics_2.0/Plans/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


