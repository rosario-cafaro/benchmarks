#!/bin/bash
clear
printf "\n##############\nBenchmark Go\n##############\n"
printf "\n- Compiling\n"
time ./compile.sh
printf "\n- Running\n"
time ./run.sh
./cleaning.sh