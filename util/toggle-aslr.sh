#!/bin/bash

value=$((2 - $(cat /proc/sys/kernel/randomize_va_space)))

echo $value | sudo tee /proc/sys/kernel/randomize_va_space
