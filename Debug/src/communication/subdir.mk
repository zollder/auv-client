################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/communication/ClientThread.cpp \
../src/communication/ServerThread.cpp 

OBJS += \
./src/communication/ClientThread.o \
./src/communication/ServerThread.o 

CPP_DEPS += \
./src/communication/ClientThread.d \
./src/communication/ServerThread.d 


# Each subdirectory must supply rules for building sources it contributes
src/communication/%.o: ../src/communication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -c -fmessage-length=0 -w -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


