################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Robotics_2.0/main.cpp 

OBJS += \
./Robotics_2.0/main.o 

CPP_DEPS += \
./Robotics_2.0/main.d 


# Each subdirectory must supply rules for building sources it contributes
Robotics_2.0/%.o: ../Robotics_2.0/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/local/include/player-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


