################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-1151743023: ../car.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"C:/ti/sysconfig_1.20.0/sysconfig_cli.bat" --script "C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8/car.syscfg" -o "." -s "C:/ti/mspm0_sdk_2_00_01_00/.metadata/product.json" -d "MSPM0G350X" -p "LQFP-64(PM)" -r "Default" --context "system" --compiler ticlang
	@echo 'Finished building: "$<"'
	@echo ' '

device_linker.cmd: build-1151743023 ../car.syscfg
device.opt: build-1151743023
device.cmd.genlibs: build-1151743023
ti_msp_dl_config.c: build-1151743023
ti_msp_dl_config.h: build-1151743023
Event.dot: build-1151743023

%.o: ./%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8" -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8/Debug" -I"C:/ti/mspm0_sdk_2_00_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_00_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

startup_mspm0g350x_ticlang.o: C:/ti/mspm0_sdk_2_00_01_00/source/ti/devices/msp/m0p/startup_system_files/ticlang/startup_mspm0g350x_ticlang.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8" -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8/Debug" -I"C:/ti/mspm0_sdk_2_00_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_00_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/ccs2020/ccs/tools/compiler/ti-cgt-armllvm_4.0.3.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8" -I"C:/Users/yv236/Desktop/ccsproject/car_3507_utf-8/Debug" -I"C:/ti/mspm0_sdk_2_00_01_00/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_00_01_00/source" -gdwarf-3 -MMD -MP -MF"$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


