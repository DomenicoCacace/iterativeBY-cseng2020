#!/bin/bash

./build.sh functional
exeFolder="../src/benchmarking/build/functional"

failedTests=0

cd ${exeFolder}
for i in  7187 8237 10853 13109 13397 15331 16067 16229 19709 20981 21611 22901 23371 25579 28277 28411 30803 35117 35507 36629 40787 42677 48371 52667 58171 61717 83579
do
    echo -n "Running with ${i}..."
    ./functional_test_${i}
    if [ $? != 0 ]
    then
        ((failedTests++)) 
    fi
done

echo "Completed"

exit $failedTests


