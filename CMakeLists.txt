cmake_minimum_required(VERSION 3.15)

project(zynqstuff C ASM)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_C_COMPILER /usr/bin/arm-none-eabi-gcc)
set(CMAKE_ASM_COMPILER /usr/bin/arm-none-eabi-gcc)

# Their CMakes don't create nice targets for everything and use functions from somewhere else
#add_subdirectory(zynq_fsbl)

# Also don't need this. I stole the necessary stuff
#add_library(xil STATIC IMPORTED)
#target_include_directories(xil INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/include)
#set_target_properties(xil PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/zynq_fsbl/zynq_fsbl_bsp/ps7_cortexa9_0/lib/libxil.a)

#target_compile_options(xil INTERFACE -mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostdlib)
#target_link_options(xil PRIVATE -L,-Tlscript.ld -L,-build-id=none)

add_subdirectory(led)

