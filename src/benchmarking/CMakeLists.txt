cmake_minimum_required(VERSION 3.10)
project(inverse_bench C)

set(CC gcc)
set(OPTIMIZATION_FLAGS "-O2 -fipa-cp-clone -floop-interchange -fgcse-after-reload \
                        -floop-unroll-and-jam -fpeel-loops -fpredictive-commoning \
                        -fsplit-loops -fsplit-paths -ftree-loop-distribution -ftree-loop-vectorize \
                        -ftree-partial-pre -funswitch-loops -fvect-cost-model -fvect-cost-model=dynamic -fversion-loops-for-strides")

set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -pedantic -Wuninitialized -march=native -O3 -g3 -Wno-unused-function")

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -Wall -pedantic -Wuninitialized -march=native -g3")
message("FLAGS" ${CMAKE_C_FLAGS})

set (BASE_DIR ../../src)

set(HEADERS ${BASE_DIR}/gf2x/include/gf2x_limbs.h
            ${BASE_DIR}/gf2x/include/gf2x_arith_mod_xPplusOne.h
            ${BASE_DIR}/gf2x/include/gf2x_arith.h
            ${BASE_DIR}/common/include/architecture_detect.h
            ${BASE_DIR}/common/include/timing_and_stats.h
            ${BASE_DIR}/inverse/include/inverse_exp.h
            ${BASE_DIR}/inverse/include/inverse_DJB.h
            ${BASE_DIR}/inverse/include/inverse_DJB_specific.h
            ${BASE_DIR}/inverse/include/inverse_DJB_facilities.h)

set(SOURCES ${BASE_DIR}/gf2x/library/gf2x_arith.c
            ${BASE_DIR}/gf2x/library/gf2x_arith_mod_xPplusOne.c
            ${BASE_DIR}/inverse/library/inverse_exp.c
            ${BASE_DIR}/inverse/library/inverse_DJB.c
            ${BASE_DIR}/inverse/library/djb_support/inverse_DJB_facilities.c)

# Current primes in the specification
list(APPEND PRIME_LIST
 7187
8237
10853
13109
13397
15331
16067
16229
19709
20981
21611
22901
23371
25579
28277
28411
30803
35117
35507
36629
40787
42677
48371
52667
58171
61717
83579)

list(APPEND PRIMIT_LIST KEM-CPA
KEM-CPA
KEM-CPA
KEM-CPA
KEM-64
KEM-CPA
KEM-64
KEM-SL
KEM-SL
KEM-CPA
KEM-CPA
KEM-64
KEM-64
KEM-CPA
KEM-SL
KEM-64
KEM-SL
KEM-CPA
KEM-64
KEM-SL
KEM-64
KEM-64
KEM-SL
KEM-SL
KEM-SL
KEM-64
KEM-SL)

list(LENGTH PRIME_LIST count_primes)
math(EXPR count_primes "${count_primes}-1")

foreach(i RANGE ${count_primes})
    list(GET PRIME_LIST ${i} prime)

    set(JDS_SOURCE ${BASE_DIR}/inverse/library/djb_support/jumpdivstep_${prime}.c)
    list(APPEND SOURCES ${JDS_SOURCE})
    
    if ("${MODE}" STREQUAL "FULL_TIMING")
        add_executable(inverse_bench_full_${prime} ${HEADERS} ${SOURCES} ${BASE_DIR}/benchmarking/library/inverse_bench_full.c)
        target_link_libraries(inverse_bench_full_${prime} m)
        set_property(TARGET inverse_bench_full_${prime} APPEND PROPERTY COMPILE_FLAGS "-DCPU_WORD_BITS=64 -DP=${prime} -D")
    elseif("${MODE}" STREQUAL "BY_TIMING")
        add_executable(inverse_bench_by_${prime} ${HEADERS} ${SOURCES} ${BASE_DIR}/benchmarking/library/inverse_bench_by.c)
        target_link_libraries(inverse_bench_by_${prime} m)
        set_property(TARGET inverse_bench_by_${prime} APPEND PROPERTY COMPILE_FLAGS "-DCPU_WORD_BITS=64 -DP=${prime}")
    elseif("${MODE}" STREQUAL "FUNCTIONAL")
        add_executable(functional_test_${prime} ${HEADERS} ${SOURCES} ${BASE_DIR}/benchmarking/library/functional_test.c)
        target_link_libraries(functional_test_${prime} m)
        set_property(TARGET functional_test_${prime} APPEND PROPERTY COMPILE_FLAGS "-DCPU_WORD_BITS=64 -DP=${prime}")
    endif()

    list(REMOVE_ITEM SOURCES ${JDS_SOURCE})

endforeach(i RANGE ${count_primes})
    
