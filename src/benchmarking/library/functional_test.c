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

#include "../../inverse/include/inverse_DJB.h"
#include "../../inverse/include/inverse_exp.h"


int main(int argc, char const *argv[])
{
    DIGIT input[NUM_DIGITS_GF2X_ELEMENT] = { 0 };
    DIGIT out[NUM_DIGITS_GF2X_ELEMENT] = { 0 };
    DIGIT outcheck[NUM_DIGITS_GF2X_ELEMENT] = { 0 };

    init_direct_factors_table();
    init_permutation_table();
    init_inverse_permutation_table();
    init_inverse_index_permutation_table();
    generate_random_invertible_element(input);
    inverse_DJB(out,input, 0.5);
    gf2x_mod_inverse_exp_onlysquares(outcheck,input);
    if (memcmp(out, outcheck, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B)!=0) {
        fprintf(stderr,"MISMATCH\n");
        return -1;
    } else {
        fprintf(stderr,"Inverse OK\n");
        return 0;
    }
}