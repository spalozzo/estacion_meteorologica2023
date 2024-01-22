################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Display/Datos_Display.c \
../Core/Src/Display/ssd1306.c \
../Core/Src/Display/ssd1306_fonts.c \
../Core/Src/Display/ssd1306_tests.c 

OBJS += \
./Core/Src/Display/Datos_Display.o \
./Core/Src/Display/ssd1306.o \
./Core/Src/Display/ssd1306_fonts.o \
./Core/Src/Display/ssd1306_tests.o 

C_DEPS += \
./Core/Src/Display/Datos_Display.d \
./Core/Src/Display/ssd1306.d \
./Core/Src/Display/ssd1306_fonts.d \
./Core/Src/Display/ssd1306_tests.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Display/%.o Core/Src/Display/%.su Core/Src/Display/%.cyclo: ../Core/Src/Display/%.c Core/Src/Display/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xE -c -I../Core/Inc -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/Display" -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/ESP" -I"C:/Users/Santi/Documents/ProyectoTD2/estacion_meteorologica2023/Display_Sensores_RTOS/Core/Inc/Sensores" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -O0 -ffunction-sections -fdata-sections -Wall -u _printf_float -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Display

clean-Core-2f-Src-2f-Display:
	-$(RM) ./Core/Src/Display/Datos_Display.cyclo ./Core/Src/Display/Datos_Display.d ./Core/Src/Display/Datos_Display.o ./Core/Src/Display/Datos_Display.su ./Core/Src/Display/ssd1306.cyclo ./Core/Src/Display/ssd1306.d ./Core/Src/Display/ssd1306.o ./Core/Src/Display/ssd1306.su ./Core/Src/Display/ssd1306_fonts.cyclo ./Core/Src/Display/ssd1306_fonts.d ./Core/Src/Display/ssd1306_fonts.o ./Core/Src/Display/ssd1306_fonts.su ./Core/Src/Display/ssd1306_tests.cyclo ./Core/Src/Display/ssd1306_tests.d ./Core/Src/Display/ssd1306_tests.o ./Core/Src/Display/ssd1306_tests.su

.PHONY: clean-Core-2f-Src-2f-Display

