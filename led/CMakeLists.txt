cmake_minimum_required(VERSION 3.15)

add_executable(led.elf led_main.c ps7_init.c)
target_sources(led.elf PUBLIC xil-crt0.S cpu_init.S asm_vectors.S vectors.c boot.S translation_table.S)
#target_link_libraries(led.elf PUBLIC xil)
target_compile_options(led.elf PUBLIC -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostdlib -ffreestanding)
target_link_options(led.elf PUBLIC -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -T${CMAKE_CURRENT_SOURCE_DIR}/../zynq_fsbl/lscript.ld -L,-build-id=none -nostdlib)

