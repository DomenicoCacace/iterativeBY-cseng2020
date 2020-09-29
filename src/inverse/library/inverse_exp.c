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

#include <string.h>
#include "../../gf2x/include/gf2x_limbs.h"
#include "../../gf2x/include/gf2x_arith.h"
#include "../../gf2x/include/gf2x_arith_mod_xPplusOne.h"
#include <alloca.h>
#include "../../benchmarking/include/testing_facilities.h"
#include "../../common/include/architecture_detect.h"

#if (defined HIGH_PERFORMANCE_X86_64)
#include <immintrin.h>
static inline
void expand_clmul(uint64_t* input, uint64_t* destination ) {
    /* note, this load swaps lo and hi words */
    __m128i b = _mm_load_si128((__m128i*)input);
    __m128i expandedhi = _mm_clmulepi64_si128(b,b,0);
    __m128i expandedlo = _mm_clmulepi64_si128(b,b,0xFF);

    /*slightly faster, despite using a shufpd under the hood*/
    _mm_storer_pd ((double*) destination, (__m128d)expandedhi);
    _mm_storer_pd ((double*) (destination+2), (__m128d)expandedlo);
}

void expand_AVX2(__m256i* output, __m256i* input) {
    const __m256i low_nibbles_placer_permutation =
        /*low nibble of epi8 is source index, if MSB of epi8 is set, write 0 */
        _mm256_set_epi8((uint8_t)0x80,0x07, (uint8_t)0x80,0x06, (uint8_t)0x80,0x05, (uint8_t)0x80,0x04,
                        (uint8_t)0x80,0x03, (uint8_t)0x80,0x02, (uint8_t)0x80,0x01, (uint8_t)0x80,0x00,
                        (uint8_t)0x80,0x07, (uint8_t)0x80,0x06, (uint8_t)0x80,0x05, (uint8_t)0x80,0x04,
                        (uint8_t)0x80,0x03, (uint8_t)0x80,0x02, (uint8_t)0x80,0x01, (uint8_t)0x80,0x00);
    const __m256i high_nibbles_placer_permutation =
        /*low nibble of epi8 is source index, if MSB of epi8 is set, write 0 */
        _mm256_set_epi8(0x07,(uint8_t)0x80, 0x06,(uint8_t)0x80, 0x05,(uint8_t)0x80, 0x04,(uint8_t)0x80,
                        0x03,(uint8_t)0x80, 0x02,(uint8_t)0x80, 0x01,(uint8_t)0x80, 0x00,(uint8_t)0x80,
                        0x07,(uint8_t)0x80, 0x06,(uint8_t)0x80, 0x05,(uint8_t)0x80, 0x04,(uint8_t)0x80,
                        0x03,(uint8_t)0x80, 0x02,(uint8_t)0x80, 0x01,(uint8_t)0x80, 0x00,(uint8_t)0x80);
    __m256i inreg = _mm256_lddqu_si256 (input);
    __m256i outreg_lo, outreg_hi,
            hi_nib_lo, lo_nib_lo,
            hi_nib_hi, lo_nib_hi;

    outreg_lo =_mm256_permute4x64_epi64 (inreg, 0x50);
    outreg_hi =_mm256_permute4x64_epi64 (inreg, 0xFA);

    hi_nib_lo = _mm256_and_si256(
                    _mm256_shuffle_epi8(outreg_lo,
                                        high_nibbles_placer_permutation),
                    _mm256_set1_epi8( (uint8_t)0xf0));
    hi_nib_lo = _mm256_srli_epi16(hi_nib_lo,4);
    lo_nib_lo = _mm256_and_si256(
                    _mm256_shuffle_epi8(outreg_lo,
                                        low_nibbles_placer_permutation),
                    _mm256_set1_epi8(0x0f));
    outreg_lo = _mm256_or_si256(hi_nib_lo,lo_nib_lo);

    hi_nib_hi = _mm256_and_si256(
                    _mm256_shuffle_epi8(outreg_hi,
                                        high_nibbles_placer_permutation),
                    _mm256_set1_epi8((uint8_t)0xf0));
    hi_nib_hi = _mm256_srli_epi16(hi_nib_hi,4);
    lo_nib_hi = _mm256_and_si256(
                    _mm256_shuffle_epi8(outreg_hi,
                                        low_nibbles_placer_permutation),
                    _mm256_set1_epi8(0x0f));
    outreg_hi = _mm256_or_si256(hi_nib_hi,lo_nib_hi);

    /* finalize last two morton numbers, the usual way */
    const __m256i m4 = _mm256_set1_epi64x(0x3333333333333333);
    const __m256i m5 = _mm256_set1_epi64x(0x5555555555555555);
    outreg_hi = _mm256_xor_si256(outreg_hi, _mm256_slli_epi16(outreg_hi, 2));
    outreg_hi = _mm256_and_si256(outreg_hi, m4);
    outreg_hi = _mm256_xor_si256(outreg_hi, _mm256_slli_epi16(outreg_hi, 1));
    outreg_hi = _mm256_and_si256(outreg_hi, m5);

    outreg_lo = _mm256_xor_si256(outreg_lo, _mm256_slli_epi16(outreg_lo, 2));
    outreg_lo = _mm256_and_si256(outreg_lo, m4);
    outreg_lo = _mm256_xor_si256(outreg_lo, _mm256_slli_epi16(outreg_lo, 1));
    outreg_lo = _mm256_and_si256(outreg_lo, m5);

    _mm256_storeu_si256 (output, outreg_lo);
    _mm256_storeu_si256 (output+1, outreg_hi);
}

#endif

DIGIT interleave(DIGIT x, DIGIT y) {

    x = (x | (x << 16)) & 0x0000FFFF0000FFFF;
    x = (x | (x << 8)) & 0x00FF00FF00FF00FF;
    x = (x | (x << 4)) & 0x0F0F0F0F0F0F0F0F;
    x = (x | (x << 2)) & 0x3333333333333333;
    x = (x | (x << 1)) & 0x5555555555555555;

    y = (y | (y << 16)) & 0x0000FFFF0000FFFF;
    y = (y | (y << 8)) & 0x00FF00FF00FF00FF;
    y = (y | (y << 4)) & 0x0F0F0F0F0F0F0F0F;
    y = (y | (y << 2)) & 0x3333333333333333;
    y = (y | (y << 1)) & 0x5555555555555555;

    return x | (y << 1);
}
static inline
uint64_t expand(uint32_t x)  {
    return interleave(x,0);
}



/*
compute poly^2 in F2[X]/(x^P -1)
poly,poly_sq --> dense definition.
save the resalt in poly_sq.
*/
#if (DIGIT_MAX == UINT64_MAX)
#define DIGIT_SIZE_b_BITS 6
#define HALF_DIGIT uint32_t
#elif (DIGIT_MAX == UINT32_MAX)
#define DIGIT_SIZE_b_BITS 5
#define HALF_DIGIT uint16_t
#endif


/* splitting point of the operand, dividing bits to be expanded from bits
to be expanded and folded back. The value is to be subtracted from  */
#define LOW_HALFWORD_MASK ( ((DIGIT)1 << (DIGIT_SIZE_b/2))-1)

#include <stdalign.h>

/* AVX2 based bit interleaving CLMUL */
void pow_2_A(DIGIT * poly_sq, DIGIT * poly) {

    alignas(32) DIGIT tmp[2*NUM_DIGITS_GF2X_ELEMENT] = {0};

    int outidx = 2*NUM_DIGITS_GF2X_ELEMENT-4;
    int i = NUM_DIGITS_GF2X_ELEMENT-2;
#if (NUM_DIGITS_GF2X_ELEMENT%2==1) /* there may be an extra word to expand*/
    DIGIT word;
    HALF_DIGIT lohalf,hihalf;
    word = poly[NUM_DIGITS_GF2X_ELEMENT-1];
    hihalf = (word >> DIGIT_SIZE_b/2) & LOW_HALFWORD_MASK;
    lohalf = word & LOW_HALFWORD_MASK;
    tmp[2*NUM_DIGITS_GF2X_ELEMENT-1]  = expand(lohalf);
    tmp[2*NUM_DIGITS_GF2X_ELEMENT-2] = expand(hihalf);
    i--;
    outidx -=2;
#endif
    for(; i >= 0; i = i-2) {
#if defined(HIGH_PERFORMANCE_X86_64)
        expand_clmul(poly+i,tmp+outidx);
#else
        /* TODO: throughly test compatible square*/
        DIGIT word;
        HALF_DIGIT lohalf,hihalf;
        word = poly[i+1];
        hihalf = (word >> DIGIT_SIZE_b/2) & LOW_HALFWORD_MASK;
        lohalf = word & LOW_HALFWORD_MASK;
        tmp[outidx+3]  = expand(lohalf);
        tmp[outidx+2] = expand(hihalf);

        word = poly[i];
        hihalf = (word >> DIGIT_SIZE_b/2) & LOW_HALFWORD_MASK;
        lohalf = word & LOW_HALFWORD_MASK;
        tmp[outidx+1]  = expand(lohalf);
        tmp[outidx] = expand(hihalf);
#endif
        outidx=outidx-4;
    }
    gf2x_mod(poly_sq,2*NUM_DIGITS_GF2X_ELEMENT, tmp);
    return;
}

/* AVX2 based bit interleaving Morton numbers */
/* Useless. Slower than pow_2_A */
// void pow_2_B(DIGIT * poly_sq, DIGIT * poly) {
//
//   alignas(32) DIGIT tmp[2*NUM_DIGITS_GF2X_ELEMENT] = {0};
//
//   int outidx = 2*NUM_DIGITS_GF2X_ELEMENT-4;
//   int i = NUM_DIGITS_GF2X_ELEMENT-2;
// #if (NUM_DIGITS_GF2X_ELEMENT%2==1) /* there may be an extra word to expand*/
//   DIGIT word;
//   HALF_DIGIT lohalf,hihalf;
//   word = poly[NUM_DIGITS_GF2X_ELEMENT-1];
//   hihalf = (word >> DIGIT_SIZE_b/2) & LOW_HALFWORD_MASK;
//   lohalf = word & LOW_HALFWORD_MASK;
//   tmp[2*NUM_DIGITS_GF2X_ELEMENT-1]  = expand(lohalf);
//   tmp[2*NUM_DIGITS_GF2X_ELEMENT-2] = expand(hihalf);
//   i--;
//   outidx -=2;
// #endif
//
// #if (NUM_DIGITS_GF2X_ELEMENT%4==2) || (NUM_DIGITS_GF2X_ELEMENT%4==3)
//   /* there may be an extra word to expand*/
//   expand_clmul(poly+i,tmp+outidx);
//   i = i-2;
//   outidx = outidx-4;
// #endif
//   for(; i >= 0; i = i-4){
//       expand_AVX2((__m256i*)(tmp+outidx),(__m256i*)(poly+i));
//       outidx=outidx-8;
//   }
//   gf2x_mod(poly_sq,2*NUM_DIGITS_GF2X_ELEMENT, tmp);
//   return;
// }


#define SQUARE_IMPLEMENTATION pow_2_A
void raise_2_i_clmul(DIGIT* a, int i) {
    for (int j = 0; j < i; j++) {
        SQUARE_IMPLEMENTATION(a, a);
    }
}


/*****************************PERMUTATION BASED SQ*****************************/

#define NUM_SLACK_BITS (DIGIT_SIZE_b-(P%DIGIT_SIZE_b))
void raise_2_i_direct_permute_wfunctions(DIGIT* a, int i) {
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    unsigned int factor = 1;
    for(int x = 0; x < i ; x++) {
        factor = (factor*2)%P;
    }
    for(int exp = 0; exp < P; exp++) {
        unsigned int dst_exp = (exp*factor)%P;
        DIGIT to_move = gf2x_get_coeff(tmp, exp);
        gf2x_set_coeff(a, dst_exp, to_move);
    }
}

/******************************************************************************/

unsigned int direct_factors_table[BITS_TO_REPRESENT(P)];
void init_direct_factors_table(void) {
    for(int eexp = 0; eexp < BITS_TO_REPRESENT(P); eexp++) {
        int i = 1 << eexp;
        int dst_exp = 1;
        for(int x = 0; x < i; x++) {
            dst_exp = (dst_exp*2)%P;
        }
        direct_factors_table[eexp]=dst_exp;
    }
}

void raise_2_i_factor_permute(DIGIT* a, int i) {
    int tableindex = 0;
    /* count trailing zeroes */
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    memset(a,0,NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    for(int exp = 0; exp < P; exp++) {
        int dst_exp = (exp*direct_factors_table[tableindex])%P;
        DIGIT to_move = gf2x_get_coeff(tmp, exp);
        gf2x_set_coeff(a, dst_exp, to_move);
    }
}

/******************************************************************************/

int permutation_table[BITS_TO_REPRESENT(P)][P];
void init_permutation_table(void) {
    for(int eexp = 0; eexp < BITS_TO_REPRESENT(P); eexp++) {
        int twoexp = 1 << eexp;
        uint64_t factor = 1;
        for(int x = 0; x < twoexp; x++) {
            factor = (factor*2)%P;
        }
        for(int src_exp=0; src_exp < P; src_exp++) {
            permutation_table[eexp][src_exp] = (src_exp*factor)%P;
        }
    }
}

void raise_2_i_perm_table(DIGIT* a, int i) {
    int tableindex = 0;
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    for(int exp = 0; exp < P; exp++) {
        int dst_exp = permutation_table[tableindex][exp];
        DIGIT to_move = gf2x_get_coeff(tmp, exp);
        gf2x_set_coeff(a, dst_exp, to_move);
    }
}


/************************** INVERSE PERM BASED SQUARE *************************/
#include "../include/inverse_powers_mod_p.h"

void raise_2_i_factor_inverse_permute(DIGIT* a, int i) {
    int tableindex = 0;
    /* count trailing zeroes */
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    for(int dst_exp = 0; dst_exp < P; dst_exp++) {
        int exp = (dst_exp*inverse_factors_table[tableindex])%P;
        DIGIT to_move = gf2x_get_coeff(tmp, exp);
        gf2x_set_coeff(a, dst_exp, to_move);
    }
}

/*******************************************************************************/

int inverse_permutation_table[BITS_TO_REPRESENT(P)][P];

void init_inverse_permutation_table(void) {

    for(int tableindex = 0; tableindex < BITS_TO_REPRESENT(P); tableindex++) {
        for(int dst_exp=0; dst_exp < P; dst_exp++) {
            inverse_permutation_table[tableindex][dst_exp] = (dst_exp*inverse_factors_table[tableindex])%P;
        }
    }
}

void raise_2_i_inverse_perm_table(DIGIT* a, int i) {
    int tableindex = 0;
    /* count trailing zeroes */
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    for(int dst_exp = 0; dst_exp < P; dst_exp++) {

        int exp = inverse_permutation_table[tableindex][dst_exp];
        DIGIT to_move = gf2x_get_coeff(tmp, exp);
        gf2x_set_coeff(a, dst_exp, to_move);
    }
}

/*******************************************************************************/
int inverse_index_permutation_table[BITS_TO_REPRESENT(P)][NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b];
void init_inverse_index_permutation_table(void) {
    for(int eexp = 0; eexp < BITS_TO_REPRESENT(P); eexp++) {
        int64_t factor = inverse_factors_table[eexp];

        for(int dst_exp=0; dst_exp < P; dst_exp++) {
            int64_t src_exp = (dst_exp*factor)%P;
            int64_t src_pos =  (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - src_exp;
            int64_t dst_pos =  (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - dst_exp;
            inverse_index_permutation_table[eexp][dst_pos] = src_pos;
        }

    }
}

#if defined(HIGH_PERFORMANCE_X86_64)
void raise_2_i_inverse_perm_table_linsweep(DIGIT* a, int i) {
    /* just for interface compliance, remove in final version */
    int tableindex = 0;
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    int d_inDigitIdx;
    /* leading digit has slack bits */
    DIGIT d_digit = 0;
    for( d_inDigitIdx = (DIGIT_SIZE_b-(P%DIGIT_SIZE_b));
            d_inDigitIdx < DIGIT_SIZE_b;
            d_inDigitIdx++) {
        unsigned int s_straightIdx = inverse_index_permutation_table[tableindex][d_inDigitIdx];
        unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
        unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
        DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
        d_digit = (d_digit <<1) | to_move;
    }
    a[0] = d_digit;

    /* deal with spare digits which cannot be vectorized */
    int d_digit_idx;
    for(d_digit_idx = 1; d_digit_idx < 1+(NUM_DIGITS_GF2X_ELEMENT%4 + 4-1)%4 ; d_digit_idx++ ) {
        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int s_straightIdx = inverse_index_permutation_table[tableindex][d_digit_idx*DIGIT_SIZE_b + d_inDigitIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        a[d_digit_idx] = d_digit;
    }
    /* vectorize the remaining ones */
    __m256i vec_d_digit =_mm256_set_epi64x(0,0,0,0);
    for (; d_digit_idx <= NUM_DIGITS_GF2X_ELEMENT-4; d_digit_idx = d_digit_idx+4 ) {


        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int tableElemIdx = d_digit_idx *DIGIT_SIZE_b +
                                        0 *DIGIT_SIZE_b +
                                        d_inDigitIdx;
            unsigned int s_straightIdx =
                inverse_index_permutation_table[tableindex][tableElemIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        vec_d_digit = _mm256_insert_epi64(vec_d_digit, d_digit, 0);

        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int tableElemIdx = d_digit_idx *DIGIT_SIZE_b +
                                        1 *DIGIT_SIZE_b +
                                        d_inDigitIdx;
            unsigned int s_straightIdx =
                inverse_index_permutation_table[tableindex][tableElemIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        vec_d_digit = _mm256_insert_epi64(vec_d_digit, d_digit, 1);

        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int tableElemIdx = d_digit_idx *DIGIT_SIZE_b +
                                        2 *DIGIT_SIZE_b +
                                        d_inDigitIdx;
            unsigned int s_straightIdx =
                inverse_index_permutation_table[tableindex][tableElemIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        vec_d_digit = _mm256_insert_epi64(vec_d_digit, d_digit, 2);

        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int tableElemIdx = d_digit_idx *DIGIT_SIZE_b +
                                        3 *DIGIT_SIZE_b +
                                        d_inDigitIdx;
            unsigned int s_straightIdx =
                inverse_index_permutation_table[tableindex][tableElemIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        vec_d_digit = _mm256_insert_epi64(vec_d_digit, d_digit,3);
        _mm256_storeu_si256((__m256i*) (a+d_digit_idx), vec_d_digit);
    }
}

#else
void raise_2_i_inverse_perm_table_linsweep(DIGIT* a, int i) {
    /* just for interface compliance, remove in final version */
    int tableindex = 0;
    while(i>1) {
        tableindex++;
        i = i >> 1;
    }
    DIGIT tmp[NUM_DIGITS_GF2X_ELEMENT];
    memcpy(tmp, a, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    int d_inDigitIdx;
    /* leading digit has slack bits */
    DIGIT d_digit = 0;
    for( d_inDigitIdx = (DIGIT_SIZE_b-(P%DIGIT_SIZE_b));
            d_inDigitIdx < DIGIT_SIZE_b;
            d_inDigitIdx++) {
        unsigned int s_straightIdx = inverse_index_permutation_table[tableindex][d_inDigitIdx];
        unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
        unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
        DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
        d_digit = (d_digit <<1) | to_move;
    }
    a[0] = d_digit;
    /* all others are full */

    for(int d_digit_idx = 1; d_digit_idx < NUM_DIGITS_GF2X_ELEMENT; d_digit_idx++ ) {
        d_digit=0;
        for( d_inDigitIdx = 0; d_inDigitIdx < DIGIT_SIZE_b; d_inDigitIdx++) {
            unsigned int s_straightIdx = inverse_index_permutation_table[tableindex][d_digit_idx*DIGIT_SIZE_b + d_inDigitIdx];
            unsigned int s_digitIdx = s_straightIdx / DIGIT_SIZE_b;
            unsigned int s_inDigitIdx = s_straightIdx % DIGIT_SIZE_b;
            DIGIT to_move = (tmp[s_digitIdx] >> (DIGIT_SIZE_b-1-s_inDigitIdx)) & ((DIGIT) 1) ;
            d_digit = (d_digit << 1) | to_move;
        }
        a[d_digit_idx] = d_digit;
    }
}
#endif

#define RAISE_2_I_TRADEOFF_TH (1<<5)
void raise_2_i_hybrid(DIGIT* a, int i) {
    if (i <= RAISE_2_I_TRADEOFF_TH) {
        raise_2_i_clmul(a,i);
    }
    else {
        raise_2_i_inverse_perm_table_linsweep(a,i);
    }
}

// #define ITERATED_SQUARE_IMPLEMENTATION raise_2_i_clmul // OK
// #define ITERATED_SQUARE_IMPLEMENTATION raise_2_i_direct_permute_wfunctions  // OK
// #define ITERATED_SQUARE_IMPLEMENTATION raise_2_i_factor_permute // OK
// #define ITERATED_SQUARE_IMPLEMENTATION raise_2_i_perm_table     // OK
// #define ITERATED_SQUARE_IMPLEMENTATION  raise_2_i_factor_inverse_permute // OK

#define ITERATED_SQUARE_IMPLEMENTATION  raise_2_i_hybrid

void gf2x_mod_inverse_exp(DIGIT * polyInv, DIGIT * poly) {
    uint64_t p = P - 2;
    uint64_t exp;
    int i = 1;
    alignas(32) DIGIT b[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT a[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT temp[NUM_DIGITS_GF2X_ELEMENT];

    if ((p & 1) == 0) {
        b[NUM_DIGITS_GF2X_ELEMENT - 1] = 0x1;
    }
    else {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            b[j] = poly[j];
        }
    }
    for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
        a[j] = poly[j];
    }
    p >>= 1;
    while (p > 0) {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            temp[j] = a[j];
        }
        //a^2^2^(i-1)
        exp = 1 << (i - 1);
        ITERATED_SQUARE_IMPLEMENTATION(a,exp);
        gf2x_mod_mul(a, a, temp);

        if (p & 1) {
            //b^2^2^i
            exp = 1 << i;
            ITERATED_SQUARE_IMPLEMENTATION(b,exp);
            gf2x_mod_mul(b, b, a);
        }
        p >>= 1;
        i++;
    }
    SQUARE_IMPLEMENTATION(b, b);

    for (i = 0; i < NUM_DIGITS_GF2X_ELEMENT; i++) {
        polyInv[i] = b[i];
    }
    return;
}

void gf2x_mod_inverse_exp_compactmem(DIGIT * polyInv, DIGIT * poly) {
    uint64_t p = P - 2;
    uint64_t exp;
    int i = 1;
    alignas(32) DIGIT b[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT a[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT temp[NUM_DIGITS_GF2X_ELEMENT];

    if ((p & 1) == 0) {
        b[NUM_DIGITS_GF2X_ELEMENT - 1] = 0x1;
    }
    else {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            b[j] = poly[j];
        }
    }
    for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
        a[j] = poly[j];
    }
    p >>= 1;
    while (p > 0) {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            temp[j] = a[j];
        }
        //a^2^2^(i-1)
        exp = 1 << (i - 1);
        raise_2_i_factor_inverse_permute(a,exp);
        gf2x_mod_mul(a, a, temp);

        if (p & 1) {
            //b^2^2^i
            exp = 1 << i;
            raise_2_i_factor_inverse_permute(b,exp);
            gf2x_mod_mul(b, b, a);
        }
        p >>= 1;
        i++;
    }
    SQUARE_IMPLEMENTATION(b, b);

    for (i = 0; i < NUM_DIGITS_GF2X_ELEMENT; i++) {
        polyInv[i] = b[i];
    }
    return;
}


void gf2x_mod_inverse_exp_onlysquares(DIGIT * polyInv, DIGIT * poly) {
    uint64_t p = P - 2;
    uint64_t exp;
    int i = 1;
    alignas(32) DIGIT b[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT a[NUM_DIGITS_GF2X_ELEMENT];
    alignas(32) DIGIT temp[NUM_DIGITS_GF2X_ELEMENT];

    if ((p & 1) == 0) {
        b[NUM_DIGITS_GF2X_ELEMENT - 1] = 0x1;
    }
    else {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            b[j] = poly[j];
        }
    }
    for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
        a[j] = poly[j];
    }
    p >>= 1;
    while (p > 0) {
        for (int j = 0; j < NUM_DIGITS_GF2X_ELEMENT; j++) {
            temp[j] = a[j];
        }
        //a^2^2^(i-1)
        exp = 1 << (i - 1);
        raise_2_i_clmul(a,exp);
        gf2x_mod_mul(a, a, temp);

        if (p & 1) {
            //b^2^2^i
            exp = 1 << i;
            raise_2_i_clmul(b,exp);
            gf2x_mod_mul(b, b, a);
        }
        p >>= 1;
        i++;
    }
    SQUARE_IMPLEMENTATION(b, b);

    for (i = 0; i < NUM_DIGITS_GF2X_ELEMENT; i++) {
        polyInv[i] = b[i];
    }
    return;
}
