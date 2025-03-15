connect -url TCP:localhost:3121
targets -set -nocase -filter {name =~ "arm*#0"}
rst -system
after 1000
# select xc7z010, load bitfile
targets 4
fpga zybo_example.bit
configparams force-mem-access 1
targets -set -nocase -filter {name =~ "arm*#0"}
dow ../build/led/led.elf
configparams force-mem-access 0
con;
