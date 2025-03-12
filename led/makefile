all:
	arm-none-eabi-gcc \
  -mcpu=cortex-a9 \
  -mfpu=vfpv3 \
  -mfloat-abi=hard \
  -Wl,-build-id=none \
  -specs=Xilinx.spec \
  -Wl,-T \
  -Wl,lscript.ld \
  -L../../zybo_example_vitis_ws/zybo_example/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/lib \
  -o "xgpio_low_level_example_1.elf" 

