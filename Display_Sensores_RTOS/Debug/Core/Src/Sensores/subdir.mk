################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Sensores/BH1750.c \
../Core/Src/Sensores/BMP280.c \
../Core/Src/Sensores/CNY70.c \
../Core/Src/Sensores/DHT22.c \
../Core/Src/Sensores/LM35.c \
../Core/Src/Sensores/MQ135.c 

OBJS += \
./Core/Src/Sensores/BH1750.o \
./Core/Src/Sensores/BMP280.o \
./Core/Src/Sensores/CNY70.o \
./Core/Src/Sensores/DHT22.o \
./Core/Src/Sensores/LM35.o \
./Core/Src/Sensores/MQ135.o 

C_DEPS += \
./Core/Src/Sensores/BH1750.d \
./Core/Src/Sensores/BMP280.d \
./Core/Src/Sensores/CNY70.d \
./Core/Src/Sensores/DHT22.d \
./Core/Src/Sensores/LM35.d \
./Core/Src/Sensores/MQ135.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Sensores/%.o Core/Src/Sensores/%.su Core/Src/Sensores/%.cyclo: ../Core/Src/Sensores/%.c Core/Src/Sensores/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/Display" -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/ESP" -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/Sensores" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -u _printf_float -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Sensores

clean-Core-2f-Src-2f-Sensores:
	-$(RM) ./Core/Src/Sensores/BH1750.cyclo ./Core/Src/Sensores/BH1750.d ./Core/Src/Sensores/BH1750.o ./Core/Src/Sensores/BH1750.su ./Core/Src/Sensores/BMP280.cyclo ./Core/Src/Sensores/BMP280.d ./Core/Src/Sensores/BMP280.o ./Core/Src/Sensores/BMP280.su ./Core/Src/Sensores/CNY70.cyclo ./Core/Src/Sensores/CNY70.d ./Core/Src/Sensores/CNY70.o ./Core/Src/Sensores/CNY70.su ./Core/Src/Sensores/DHT22.cyclo ./Core/Src/Sensores/DHT22.d ./Core/Src/Sensores/DHT22.o ./Core/Src/Sensores/DHT22.su ./Core/Src/Sensores/LM35.cyclo ./Core/Src/Sensores/LM35.d ./Core/Src/Sensores/LM35.o ./Core/Src/Sensores/LM35.su ./Core/Src/Sensores/MQ135.cyclo ./Core/Src/Sensores/MQ135.d ./Core/Src/Sensores/MQ135.o ./Core/Src/Sensores/MQ135.su

.PHONY: clean-Core-2f-Src-2f-Sensores

