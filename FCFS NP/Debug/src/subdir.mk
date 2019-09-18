################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/FCFS\ NP.c 

OBJS += \
./src/FCFS\ NP.o 

C_DEPS += \
./src/FCFS\ NP.d 


# Each subdirectory must supply rules for building sources it contributes
src/FCFS\ NP.o: ../src/FCFS\ NP.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/FCFS NP.d" -MT"src/FCFS\ NP.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


