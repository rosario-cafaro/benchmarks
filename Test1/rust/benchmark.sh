#!/bin/bash
clear
printf "\n##############\nBenchmark Rust\n##############\n"
printf "\n- Compiling\n"
time ./compile.sh
printf "\n- Running\n"
time ./run.sh
./cleaning.sh