################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CC_SRCS += \
../src/sys/BaseThread.cc 

CPP_SRCS += \
../src/sys/FdTimer.cpp \
../src/sys/Logger.cpp \
../src/sys/SocketClient.cpp \
../src/sys/Timer.cpp 

CC_DEPS += \
./src/sys/BaseThread.d 

OBJS += \
./src/sys/BaseThread.o \
./src/sys/FdTimer.o \
./src/sys/Logger.o \
./src/sys/SocketClient.o \
./src/sys/Timer.o 

CPP_DEPS += \
./src/sys/FdTimer.d \
./src/sys/Logger.d \
./src/sys/SocketClient.d \
./src/sys/Timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/sys/%.o: ../src/sys/%.cc
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/sys/%.o: ../src/sys/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


