#!/bin/bash

./build.sh full_timing

cd ..
BASE_DIR=$(pwd)

exeFolder="${BASE_DIR}/src/benchmarking/build/full_timing"
numOfFiles=$(ls "${BASE_DIR}/logs/full_timing" | grep performanceLog_full | wc -l)
index=$(printf "%02d" $numOfFiles)

COMMIT=$(git rev-parse --short HEAD)


mkdir -p "${BASE_DIR}/logs/full_timing"

logPath="${BASE_DIR}/logs/full_timing/${index}_performanceLog_full_${COMMIT}.csv"

sudo cpupower frequency-set -f 1900M


echo -n "p,digits,bru_mean,bru_stddev,bru_mean_tri,bru_stddev_tri,bru_tstat," >> ${logPath}
echo -n "ktt_mean,ktt_stddev,ktt_mean_tri,ktt_stddev_tri,ktt_tstat," >> ${logPath}
echo -n "by_mean,by_stddev,by_mean_tri,by_stddev_tri,by_tstat," >> ${logPath}
echo -n "expcomp_mean,expcomp_stddev,expcomp_mean_tri,expcomp_stddev_tri,expcomp_tstat," >> ${logPath}
echo -n "expsquares_mean,expsquares_stddev,expsquares_mean_tri,expsquares_stddev_tri,expsquares_tstat," >> ${logPath}
echo     "exp_mean,exp_stddev,exp_mean_tri,exp_stddev_tri,exp_tstat" >> ${logPath}

cd ${exeFolder}
for i in  7187 8237 10853 13109 13397 15331 16067 16229 19709 20981 21611 22901 23371 25579 28277 28411 30803 35117 35507 36629 40787 42677 48371 52667 58171 61717 83579
do
    echo -n "Running with $i... "
    ./inverse_bench_full_${i} >> ${logPath}
    echo "Done"

done

echo "Benchmarking completed"
