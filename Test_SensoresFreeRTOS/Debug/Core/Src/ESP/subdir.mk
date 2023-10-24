################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/ESP/ESPDataLogger.c \
../Core/Src/ESP/UartRingbuffer.c 

OBJS += \
./Core/Src/ESP/ESPDataLogger.o \
./Core/Src/ESP/UartRingbuffer.o 

C_DEPS += \
./Core/Src/ESP/ESPDataLogger.d \
./Core/Src/ESP/UartRingbuffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/ESP/%.o Core/Src/ESP/%.su Core/Src/ESP/%.cyclo: ../Core/Src/ESP/%.c Core/Src/ESP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"C:/Users/santi/STM32CubeIDE/workspace_1.12.0/Test_SensoresFreeRTOS/Core/Inc/ESP" -I"C:/Users/santi/STM32CubeIDE/workspace_1.12.0/Test_SensoresFreeRTOS/Core/Inc/Sensores" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-ESP

clean-Core-2f-Src-2f-ESP:
	-$(RM) ./Core/Src/ESP/ESPDataLogger.cyclo ./Core/Src/ESP/ESPDataLogger.d ./Core/Src/ESP/ESPDataLogger.o ./Core/Src/ESP/ESPDataLogger.su ./Core/Src/ESP/UartRingbuffer.cyclo ./Core/Src/ESP/UartRingbuffer.d ./Core/Src/ESP/UartRingbuffer.o ./Core/Src/ESP/UartRingbuffer.su

.PHONY: clean-Core-2f-Src-2f-ESP

