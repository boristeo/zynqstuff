all:
	arm-none-eabi-gcc \
  -mcpu=cortex-a9 \
  -mfpu=vfpv3 \
  -nostdlib \
  -mfloat-abi=hard \
  -specs=Xilinx.spec \
  -Wl,-build-id=none \
  -Wl,-T \
  -Wl,lscript.ld \
  -L../../zybo_example_vitis_ws/zybo_example/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/lib \
  -lxil\
  -o "xgpio_low_level_example_1.elf"  \
  -I../../zybo_example_vitis_ws/zybo_example/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/include \
  xgpio_low_level_example.c

  #-Wl,--start-group,-lxil,-lgcc,-lc,--end-group \
