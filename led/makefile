all:
	arm-none-eabi-gcc \
  -mcpu=cortex-a9 \
  -mfpu=vfpv3 \
  -mfloat-abi=hard \
  -nostdlib \
  -Wl,-build-id=none \
  -Wl,-Tlscript.ld \
  -I../zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/include \
  -L../zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/lib \
  -lxil\
  -o "led.elf"  \
  led_main.c

