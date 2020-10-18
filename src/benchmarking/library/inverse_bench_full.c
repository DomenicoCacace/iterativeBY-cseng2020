/**
 * Software Artifact of the paper A Comprehensive Analysis of Constant-time
 * Polynomial Inversion for Post-quantum Cryptosystems
 *
 * @author Alessandro Barenghi <alessandro.barenghi@polimi.it>
 * @author Gerardo Pelosi <gerardo.pelosi@polimi.it>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 **/

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

#define NUM_TESTS 1000

#include "../../inverse/include/inverse_Bru.h"
#include "../../inverse/include/inverse_exp.h"
#include "../../inverse/include/inverse_KTT.h"
#include "../../inverse/include/inverse_DJB.h"


welford_t benchmark_Bru(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */
    gf2x_mod_inverse_Brunner(outcheck,input);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        gf2x_mod_inverse_Brunner(outcheck,input);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

welford_t benchmark_KTT(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */
    gf2x_mod_inverse_KTT(outcheck,input);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        gf2x_mod_inverse_KTT(outcheck,input);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

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

welford_t benchmark_exp(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */

    gf2x_mod_inverse_exp(outcheck,input);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        gf2x_mod_inverse_exp(outcheck,input);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

welford_t benchmark_exp_compact(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */

    gf2x_mod_inverse_exp_compactmem(outcheck,input);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        gf2x_mod_inverse_exp_compactmem(outcheck,input);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

welford_t benchmark_exp_onlysquares(DIGIT *outcheck, DIGIT *input) {
    uint64_t start, end;
    welford_t timer;
    welford_init(&timer);
    /* heat caches to minimize variance */

    gf2x_mod_inverse_exp_onlysquares(outcheck,input);
    for(int i = 0; i < NUM_TESTS; i++) {
        start = x86_64_rtdsc();
        gf2x_mod_inverse_exp_onlysquares(outcheck,input);
        end = x86_64_rtdsc();
        welford_update(&timer, ((long double) (end-start)));
    }
    welford_print(timer);
    return timer;
}

void inverse_functional_test(void) {
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
    } else {
        fprintf(stderr,"Inverse OK\n");
    }

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

    
    rnd = benchmark_Bru(out,input);
    printf(",");
    trinomial = benchmark_Bru(out,input_trinomial);
    printf(",%lf,",welch_t_statistic(rnd,trinomial));

    rnd = benchmark_KTT(out,input);
    printf(",");
    trinomial = benchmark_KTT(out,input_trinomial);
    printf(",%lf,",welch_t_statistic(rnd,trinomial));

    rnd = benchmark_DJB(out,input);
    printf(",");
    trinomial = benchmark_DJB(out,input_trinomial);
    printf(",%lf,",welch_t_statistic(rnd,trinomial));

    rnd = benchmark_exp_compact(out, input);
    printf(",");
    trinomial = benchmark_exp_compact(out, input_trinomial);
    printf(",%lf,",welch_t_statistic(rnd,trinomial));

    rnd = benchmark_exp_onlysquares(out, input);
    printf(",");
    trinomial = benchmark_exp_onlysquares(out, input_trinomial);
    printf(",%lf,",welch_t_statistic(rnd,trinomial));

    init_inverse_index_permutation_table();
    rnd = benchmark_exp(out, input);
    printf(",");
    trinomial = benchmark_exp(out, input_trinomial);
    printf(",%lf\n",welch_t_statistic(rnd,trinomial));
    
    return 0;
}
