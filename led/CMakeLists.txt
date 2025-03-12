cmake_minimum_required(VERSION 3.15)

add_executable(led.elf led_main.c)
target_link_libraries(led.elf PUBLIC xil)
target_compile_options(led.elf PUBLIC -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostdlib)
target_link_options(led.elf PUBLIC -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -T${CMAKE_CURRENT_SOURCE_DIR}/lscript.ld -L,-build-id=none -nostdlib)

