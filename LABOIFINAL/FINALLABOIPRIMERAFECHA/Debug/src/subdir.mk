################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Controller.c \
../src/FINALLABOIPRIMERAFECHA.c \
../src/Funciones.c \
../src/SECABA.c \
../src/parser.c 

OBJS += \
./src/Controller.o \
./src/FINALLABOIPRIMERAFECHA.o \
./src/Funciones.o \
./src/SECABA.o \
./src/parser.o 

C_DEPS += \
./src/Controller.d \
./src/FINALLABOIPRIMERAFECHA.d \
./src/Funciones.d \
./src/SECABA.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


