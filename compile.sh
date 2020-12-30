#!/bin/bash
filename="$1"
clang-8 -S -target arm-none-eabi -nostdlib -mcpu=cortex-m0 -mthumb -O0 -mfloat-abi=soft ${filename} && ./assembleur_tom.py ${filename%.*}.s
