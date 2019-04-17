#!/bin/bash

arm-linux-gnueabihf-as exploit.asm -o exploit.o
arm-linux-gnueabihf-ld exploit.o -o exploit
arm-linux-gnueabihf-objcopy -O binary exploit exploit.bin
hexdump -v -e '"\\""x" 1/1 "%02x" ""' exploit.bin
rm -f exploit.o exploit.bin exploit
echo

