################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/IP.cpp \
../src/InputMsgHandler.cpp \
../src/KafkaClientConfig.cpp \
../src/KafkaConsumerClient.cpp \
../src/KafkaProducerClient.cpp \
../src/MemoryBlock.cpp \
../src/MessageDispatch.cpp \
../src/OutputMsgHandler.cpp \
../src/Pointer.cpp \
../src/PrintTask.cpp \
../src/RedisClient.cpp \
../src/RedisClientPool.cpp \
../src/StringBeads.cpp \
../src/ThreadPool.cpp \
../src/main.cpp 

O_SRCS += \
../src/MessageDispatch-IP.o \
../src/MessageDispatch-InputMsgHandler.o \
../src/MessageDispatch-KafkaClientConfig.o \
../src/MessageDispatch-KafkaProducerClient.o \
../src/MessageDispatch-MessageDispatch.o \
../src/MessageDispatch-OutputMsgHandler.o \
../src/MessageDispatch-PrintTask.o \
../src/MessageDispatch-StringBeads.o \
../src/MessageDispatch-ThreadPool.o \
../src/MessageDispatch-main.o 

OBJS += \
./src/IP.o \
./src/InputMsgHandler.o \
./src/KafkaClientConfig.o \
./src/KafkaConsumerClient.o \
./src/KafkaProducerClient.o \
./src/MemoryBlock.o \
./src/MessageDispatch.o \
./src/OutputMsgHandler.o \
./src/Pointer.o \
./src/PrintTask.o \
./src/RedisClient.o \
./src/RedisClientPool.o \
./src/StringBeads.o \
./src/ThreadPool.o \
./src/main.o 

CPP_DEPS += \
./src/IP.d \
./src/InputMsgHandler.d \
./src/KafkaClientConfig.d \
./src/KafkaConsumerClient.d \
./src/KafkaProducerClient.d \
./src/MemoryBlock.d \
./src/MessageDispatch.d \
./src/OutputMsgHandler.d \
./src/Pointer.d \
./src/PrintTask.d \
./src/RedisClient.d \
./src/RedisClientPool.d \
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


