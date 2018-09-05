################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/MessageDispatch-InputMsgHandler.o \
../src/MessageDispatch-MessageDispatch.o \
../src/MessageDispatch-OutputMsgHandler.o \
../src/MessageDispatch-PrintTask.o \
../src/MessageDispatch-StringBeads.o \
../src/MessageDispatch-ThreadPool.o \
../src/MessageDispatch-main.o 

CPP_SRCS += \
../src/IP.cpp \
../src/InputMsgHandler.cpp \
../src/MessageDispatch.cpp \
../src/OutputMsgHandler.cpp \
../src/PrintTask.cpp \
../src/StringBeads.cpp \
../src/ThreadPool.cpp \
../src/main.cpp 

OBJS += \
./src/IP.o \
./src/InputMsgHandler.o \
./src/MessageDispatch.o \
./src/OutputMsgHandler.o \
./src/PrintTask.o \
./src/StringBeads.o \
./src/ThreadPool.o \
./src/main.o 

CPP_DEPS += \
./src/IP.d \
./src/InputMsgHandler.d \
./src/MessageDispatch.d \
./src/OutputMsgHandler.d \
./src/PrintTask.d \
./src/StringBeads.d \
./src/ThreadPool.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


