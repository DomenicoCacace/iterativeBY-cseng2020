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

#pragma once
#include <stdlib.h>
#include <stdio.h>
static
void generate_random_invertible_element(DIGIT input[NUM_DIGITS_GF2X_ELEMENT]) {

    for (unsigned i = 0 ; i < 8*NUM_DIGITS_GF2X_ELEMENT ; i++) {
        ((char*) input)[i] = rand();
    }

    int straightIdx = (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - P;
    unsigned int inDigitIdx = straightIdx % DIGIT_SIZE_b;
    /*poly does not fill the MS digit, clear slack*/
    if(inDigitIdx != 0) {
        DIGIT mask = (( (DIGIT) 1) << (DIGIT_SIZE_b-1-inDigitIdx))- ((DIGIT)1);
        input[0] &= mask;
    }

    while( population_count(input) %2 != 1 ) {
        for (unsigned i = 8*(NUM_DIGITS_GF2X_ELEMENT-1);
                i < 8*NUM_DIGITS_GF2X_ELEMENT;
                i++) {
            ((char*) input)[i] = rand();
        }
    }
}

static
void generate_invertible_trinomial(DIGIT input[NUM_DIGITS_GF2X_ELEMENT]) {
    input[NUM_DIGITS_GF2X_ELEMENT-1] = (DIGIT) 0x7;
}

static
void generate_invertible_dense_polynomial(DIGIT input[NUM_DIGITS_GF2X_ELEMENT]) {
    for(int i = 0; i < NUM_DIGITS_GF2X_ELEMENT; i++) {
        input[i] = (DIGIT) 0 - (DIGIT)1;
    }
    input[NUM_DIGITS_GF2X_ELEMENT-1] &=  ~ ((DIGIT) 0x3);
    input[0] &= SLACK_CLEAR_MASK;
}

/* generates a random sparse polynomial mod x^p+1*/
static
void generate_random_sparse_element(POSITION_T pos_ones[],
                                    const int countOnes ) {
    int duplicated, placedOnes = 0;

    while (placedOnes < countOnes) {
        int p = lrand48() %P;
        duplicated = 0;
        for (int j = 0; j < placedOnes; j++) if (pos_ones[j] == p) duplicated = 1;
        if (duplicated == 0) {
            pos_ones[placedOnes] = p;
            placedOnes++;
        }
    }
    return;
}

static
void print_pol(DIGIT pol[], char polin[], int len)
{
    int i;
    fprintf(stdout,"%s", polin);
    for (i = 0; i < len; i++) {
        fprintf(stdout," %016lX ", pol[i]);
    }
    fprintf(stdout,"\n");


}
#if (defined HIGH_PERFORMANCE_X86_64)
static
void print_pol128(__m128i pol, char polin[])
{

    printf("%s: ", polin);
    printf("hi: %llx || ", _mm_extract_epi64(pol, 1));
    printf("lo: %llx ", _mm_extract_epi64(pol, 0));

    printf("\n");
}

static
void print_pol256(__m256i pol, char polin[])
{

    printf("%s: ", polin);
    printf("hh: %016lX || ", (uint64_t)_mm256_extract_epi64(pol, 3));
    printf("hl: %016lX || ", (uint64_t)_mm256_extract_epi64(pol, 2));
    printf("lh: %016lX || ", (uint64_t)_mm256_extract_epi64(pol, 1));
    printf("ll: %016lX ",    (uint64_t)_mm256_extract_epi64(pol, 0));

    printf("\n");
}
#endif