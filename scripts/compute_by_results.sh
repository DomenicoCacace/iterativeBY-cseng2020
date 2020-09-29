#!/bin/bash

./build.sh by_timing

cd ..
BASE_DIR=$(pwd)

exeFolder="${BASE_DIR}/src/benchmarking/build/by_timing"

numOfFiles=$(ls "${BASE_DIR}/logs/by_timing" | grep performanceLog_by | wc -l)
index=$(printf "%02d" $numOfFiles)
COMMIT=$(git rev-parse --short HEAD)


mkdir -p "${BASE_DIR}/logs/by_timing"

logPath="${BASE_DIR}/logs/by_timing/${index}_performanceLog_by_${COMMIT}.csv"

sudo cpupower frequency-set -f 1900M

echo "p,digits,by_mean,by_stddev,by_mean_tri,by_stddev_tri,by_tstat" >> "${logPath}"

cd "${exeFolder}"
for i in  7187 8237 10853 13109 13397 15331 16067 16229 19709 20981 21611 22901 23371 25579 28277 28411 30803 35117 35507 36629 40787 42677 48371 52667 58171 61717 83579
do
    echo -n "Running with $i... "
    ./inverse_bench_by_${i} >> "${logPath}"
    echo "Done"

done
echo "Benchmarking completed"
