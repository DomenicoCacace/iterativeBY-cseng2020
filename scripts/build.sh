#!/bin/bash

if [ $1 = "functional" ];
then
    mkdir -p ../src/benchmarking/build/functional
    cd ../src/benchmarking/build/functional
    cmake ../../ -DMODE=FUNCTIONAL
elif [ $1 = "by_timing" ];
then    
    mkdir -p ../src/benchmarking/build/by_timing
    cd ../src/benchmarking/build/by_timing
    cmake ../../ -DMODE=BY_TIMING
elif [ $1 = "full_timing" ];
then
    mkdir -p ../src/benchmarking/build/full_timing
    cd ../src/benchmarking/build/full_timing
    cmake ../../ -DMODE=FULL_TIMING
fi

make -j 20