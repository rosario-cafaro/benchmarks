#!/bin/bash

printf "\n##############\nBenchmark C\n##############\n"
printf "\n- Compiling\n"
time ./compile.sh
printf "\n- Running\n"
time ./run.sh