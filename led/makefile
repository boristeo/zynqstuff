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
  -I../../zybo_example_vitis_ws/zybo_example/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/include \
  -o "xgpio_low_level_example_1.elf"  \
  -Wl,--start-group,-lxil,-lgcc,-lc,--end-group \
  xgpio_low_level_example.c

