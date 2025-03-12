connect -url TCP:localhost:3121

targets -set -nocase -filter {name =~ "arm*#0"}
stop

# select xc7z010, load bitfile
targets 4

#rst -srst
#after 10000

fpga zybo_example.bit

targets -set -nocase -filter {name =~ "arm*#0"}
dow ../zynq_fsbl/fsbl.elf

con; after 3000; stop

#targets 1
source ps7_init.tcl
ps7_init

#set deviceTreeOffset 0x100000
#dow -data  "system.dtb" ${deviceTreeOffset}

dow ../build/led/led.elf
con;



