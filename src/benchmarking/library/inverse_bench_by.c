#include <inttypes.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>
#include <alloca.h>

#include "../../gf2x/include/gf2x_limbs.h"
#include "../../gf2x/include/gf2x_arith_mod_xPplusOne.h"
#include "../../common/include/architecture_detect.h"
#include "../../common/include/timing_and_stats.h"
#include "../include/testing_facilities.h"

#include <string.h>

/*************************************************************************/

#define NUM_TESTS 500

#include "../../inverse/include/inverse_DJB.h"
#include "../../inverse/include/inverse_exp.h"


welford_t benchmark_DJB(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */
    inverse_DJB(outcheck,input, 0.5);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        inverse_DJB(outcheck,input, 0.5);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

/******************************************************************************/

int main(int argc, char const *argv[])
{
    srand(42);
    srand48(42);

    printf("%d,%d,",P,NUM_DIGITS_GF2X_ELEMENT);

    DIGIT input[NUM_DIGITS_GF2X_ELEMENT] = { 0 };
    DIGIT input_trinomial[NUM_DIGITS_GF2X_ELEMENT] = { 0 };
    DIGIT out[NUM_DIGITS_GF2X_ELEMENT] = { 0 };

    welford_t rnd, trinomial;

    generate_random_invertible_element(input);
    input_trinomial[NUM_DIGITS_GF2X_ELEMENT-1] = (DIGIT)7;

    rnd = benchmark_DJB(out,input);
    printf(",");
    trinomial = benchmark_DJB(out,input_trinomial);
    printf(",%lf\n",welch_t_statistic(rnd,trinomial));
    
    return 0;
}
