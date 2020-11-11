################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../Collection.o \
../TAjuster.o \
../TRetirer.o 

CPP_SRCS += \
../Collection.cpp \
../TAjuster.cpp \
../TRetirer.cpp \
../TReunirEtSecondConstruteur.cpp 

OBJS += \
./Collection.o \
./TAjuster.o \
./TRetirer.o \
./TReunirEtSecondConstruteur.o 

CPP_DEPS += \
./Collection.d \
./TAjuster.d \
./TRetirer.d \
./TReunirEtSecondConstruteur.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


