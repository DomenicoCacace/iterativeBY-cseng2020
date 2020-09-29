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

#include "gf2x_limbs.h"
#include "gf2x_arith.h"

/*----------------------------------------------------------------------------*/

#define                NUM_BITS_GF2X_ELEMENT (P)
#define              NUM_DIGITS_GF2X_ELEMENT ((P+DIGIT_SIZE_b-1)/DIGIT_SIZE_b)
#define MSb_POSITION_IN_MSB_DIGIT_OF_ELEMENT ( (P % DIGIT_SIZE_b) ? (P % DIGIT_SIZE_b)-1 : DIGIT_SIZE_b-1 )

#define                NUM_BITS_GF2X_MODULUS (P+1)
#define              NUM_DIGITS_GF2X_MODULUS ((P+1+DIGIT_SIZE_b-1)/DIGIT_SIZE_b)
#define MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS (P-DIGIT_SIZE_b*(NUM_DIGITS_GF2X_MODULUS-1))

#define                    INVALID_POS_VALUE (P)

#define IS_REPRESENTABLE_IN_D_BITS(D, N)                \
  (((unsigned long) N >= (1UL << (D - 1)) && (unsigned long) N < (1UL << D)) ? D : -1)

#define BITS_TO_REPRESENT(N)                            \
  (N == 0 ? 1 : (31                                     \
                 + IS_REPRESENTABLE_IN_D_BITS( 1, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 2, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 3, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 4, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 5, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 6, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 7, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 8, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS( 9, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(10, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(11, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(12, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(13, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(14, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(15, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(16, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(17, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(18, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(19, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(20, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(21, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(22, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(23, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(24, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(25, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(26, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(27, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(28, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(29, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(30, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(31, N)    \
                 + IS_REPRESENTABLE_IN_D_BITS(32, N)    \
                 )                                      \
   )

/*----------------------------------------------------------------------------*/

static inline void gf2x_copy(DIGIT dest[], const DIGIT in[])
{
    for (int i = NUM_DIGITS_GF2X_ELEMENT-1; i >= 0; i--)
        dest[i] = in[i];
} // end gf2x_copy

/*---------------------------------------------------------------------------*/

void gf2x_mod_mul(DIGIT Res[], const DIGIT A[], const DIGIT B[]);

/*---------------------------------------------------------------------------*/

static inline void gf2x_mod_add(DIGIT Res[], const DIGIT A[], const DIGIT B[])
{
    gf2x_add(NUM_DIGITS_GF2X_ELEMENT, Res,
             NUM_DIGITS_GF2X_ELEMENT, A,
             NUM_DIGITS_GF2X_ELEMENT, B);
} // end gf2x_mod_add

/*----------------------------------------------------------------------------*/

void gf2x_transpose_in_place(DIGIT
                             A[]); /* in place bit-transp. of a(x) % x^P+1  *
                                      * e.g.: a3 a2 a1 a0 --> a1 a2 a3 a0     */

/*---------------------------------------------------------------------------*/

/* population count for a single polynomial */
static inline int population_count(DIGIT upc[])
{
    int ret = 0;
    for(int i = NUM_DIGITS_GF2X_ELEMENT - 1; i >= 0; i--) {
#if defined(DIGIT_IS_ULLONG)
        ret += __builtin_popcountll((unsigned long long int) (upc[i]));
#elif defined(DIGIT_IS_ULONG)
        ret += __builtin_popcountl((unsigned long int) (upc[i]));
#elif defined(DIGIT_IS_UINT)
        ret += __builtin_popcount((unsigned int) (upc[i]));
#elif defined(DIGIT_IS_UCHAR)
        const unsigned char split_lookup[] = {
            0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4
        };
        ret += split_lookup[upc[i]&0xF] + split_lookup[upc[i]>>4];
#else
#error "Missing implementation for population_count(...) \
with this CPU word bitsize !!! "
#endif
    }
    return ret;
} // end population_count

/*--------------------------------------------------------------------------*/

/* returns a packed representation of the bits corresponding to the coefficients
 * of the range first_exponent to first_exponent+DIGIT_SIZE_b mod P. Does load
 * cyclically when the coefficients exceed P. Assumes cyclic padding with enough
 * bit material after P in the MSW of the poly. poly is NUM_DIGITS_GF2X_ELEMENT+1 DIGITS
 * long */
#ifdef HIGH_PERFORMANCE_X86_64
static inline
__m256i gf2x_get_DIGIT_SIZE_coeff_vector_boundless(const DIGIT poly[],
        const unsigned int first_exponent)
{

    unsigned int straightIdx = ((NUM_DIGITS_GF2X_ELEMENT+4)*DIGIT_SIZE_b-1) - first_exponent;
    unsigned int digitIdx = straightIdx / DIGIT_SIZE_b;
    __m256i lsw = _mm256_set_epi64x (poly[digitIdx-3],
                                     poly[digitIdx-2],
                                     poly[digitIdx-1],
                                     poly[digitIdx]);
    __m256i msw = _mm256_set_epi64x (poly[digitIdx-4],
                                     poly[digitIdx-3],
                                     poly[digitIdx-2],
                                     poly[digitIdx-1]);

    unsigned int inDigitIdx = first_exponent % DIGIT_SIZE_b;

    __m256i result = _mm256_or_si256 (
                         _mm256_slli_epi64(msw, (DIGIT_SIZE_b-inDigitIdx)), _mm256_srli_epi64(lsw, inDigitIdx ) );

    return result;
}
#else
static inline
DIGIT gf2x_get_DIGIT_SIZE_coeff_vector_boundless(const DIGIT poly[], const unsigned int first_exponent)
{

    unsigned int straightIdx = ((NUM_DIGITS_GF2X_ELEMENT+1)*DIGIT_SIZE_b-1) - first_exponent;
    unsigned int digitIdx = straightIdx / DIGIT_SIZE_b;
    DIGIT lsw = poly[digitIdx];
    DIGIT msw = poly[digitIdx-1];
    unsigned int inDigitIdx = first_exponent % DIGIT_SIZE_b;

    DIGIT result = (msw  << (DIGIT_SIZE_b-inDigitIdx) ) | (lsw >> (inDigitIdx));

    return result;
}
#endif
/*--------------------------------------------------------------------------*/

/* returns the coefficient of the x^exponent term as the LSB of a digit */
static inline
DIGIT gf2x_get_coeff(const DIGIT poly[], const unsigned int exponent)
{
    unsigned int straightIdx = (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - exponent;
    unsigned int digitIdx = straightIdx / DIGIT_SIZE_b;
    unsigned int inDigitIdx = straightIdx % DIGIT_SIZE_b;
    return (poly[digitIdx] >> (DIGIT_SIZE_b-1-inDigitIdx)) & ((DIGIT) 1) ;
}

/*--------------------------------------------------------------------------*/

/* sets the coefficient of the x^exponent term as the LSB of a digit */
static inline
void gf2x_set_coeff(DIGIT poly[], const unsigned int exponent, DIGIT value)
{
    int straightIdx = (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - exponent;
    int digitIdx = straightIdx / DIGIT_SIZE_b;

    unsigned int inDigitIdx = straightIdx % DIGIT_SIZE_b;

    /* clear given coefficient */
    DIGIT mask = ~( ((DIGIT) 1) << (DIGIT_SIZE_b-1-inDigitIdx));
    poly[digitIdx] = poly[digitIdx] & mask;
    poly[digitIdx] = poly[digitIdx] | (( value & ((DIGIT) 1)) <<
                                       (DIGIT_SIZE_b-1-inDigitIdx));
}

/*--------------------------------------------------------------------------*/

/* toggles (flips) the coefficient of the x^exponent term as the LSB of a digit */
static inline
void gf2x_toggle_coeff(DIGIT poly[], const unsigned int exponent)
{

    int straightIdx = (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - exponent;
    int digitIdx = straightIdx / DIGIT_SIZE_b;
    unsigned int inDigitIdx = straightIdx % DIGIT_SIZE_b;

    /* clear given coefficient */
    DIGIT mask = ( ((DIGIT) 1) << (DIGIT_SIZE_b-1-inDigitIdx));
    poly[digitIdx] = poly[digitIdx] ^ mask;
}

/*----------------------------------------------------------------------------*/

void gf2x_transpose_in_place_sparse(int sizeA, POSITION_T A[]);

/*----------------------------------------------------------------------------*/
void gf2x_mod_mul_dense_to_sparse(DIGIT Res[],
                                  const DIGIT dense[],
                                  const POSITION_T sparse[],
                                  unsigned int nPos);

#define MSB_SET_DIGIT ((DIGIT)1 << (DIGIT_SIZE_b-1))
static
void gf2x_mod_densify_CT(DIGIT dense[NUM_DIGITS_GF2X_ELEMENT],
                         const POSITION_T exponent[],
                         int num_exponents) {
    POSITION_T digit_pos[num_exponents];
    DIGIT indigit_bitmask[num_exponents];
    for(int i = 0; i < num_exponents; i++) {
        int straightIdx = (NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1) - exponent[i];
        digit_pos[i] = straightIdx / DIGIT_SIZE_b;
        indigit_bitmask[i] = MSB_SET_DIGIT >>  (straightIdx % DIGIT_SIZE_b);
    }

    for(int digit_to_set_idx=0; digit_to_set_idx < NUM_DIGITS_GF2X_ELEMENT; digit_to_set_idx++) {
        for(int i = 0; i < num_exponents; i++) {
            DIGIT mask = (DIGIT) 0 - (DIGIT)(digit_to_set_idx == digit_pos[i]);
            dense[digit_to_set_idx] |= ((mask&(indigit_bitmask[i])) | (~mask&((DIGIT)0) ));
        }
    }
}

static
void gf2x_mod_densify_VT(DIGIT dense[NUM_DIGITS_GF2X_ELEMENT],
                         const POSITION_T exponent[],
                         int num_exponents) {
    for(int j=0; j<num_exponents; j++) {
        gf2x_set_coeff(dense, exponent[j], (DIGIT) 1);
    }
}


/*----------------------------------------------------------------------------*/

void gf2x_reflect_in_place(DIGIT A[]);

#ifdef HIGH_PERFORMANCE_X86_64
#define GF2X_DIGIT_TIMES_POLY_MUL gf2x_digit_times_poly_mul_avx
void gf2x_digit_times_poly_mul_avx(const int nr,
                                   DIGIT Res[NUM_DIGITS_GF2X_ELEMENT+1],
                                   const int na, const DIGIT A[],
                                   const DIGIT B);
#else
#define GF2X_DIGIT_TIMES_POLY_MUL gf2x_digit_times_poly_mul
void gf2x_digit_times_poly_mul(const int nr, DIGIT Res[NUM_DIGITS_GF2X_ELEMENT+1],
                               const int na, const DIGIT A[],
                               const DIGIT B);
#endif

#include <string.h>  // memcpy(...), memset(...)
/*----------------------------------------------------------------------------*/

/* specialized for nin == 2 * NUM_DIGITS_GF2X_ELEMENT, as it is only used
 * by gf2x_mul */
static
void gf2x_mod(DIGIT out[],
              const int nin, const DIGIT in[])
{
    DIGIT aux[NUM_DIGITS_GF2X_ELEMENT+1];
    memcpy(aux, in, (NUM_DIGITS_GF2X_ELEMENT+1)*DIGIT_SIZE_B);
#if MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS != 0
    right_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT+1, aux,
                      MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS);
#endif
    gf2x_add(NUM_DIGITS_GF2X_ELEMENT,out,
             NUM_DIGITS_GF2X_ELEMENT,aux+1,
             NUM_DIGITS_GF2X_ELEMENT,in+NUM_DIGITS_GF2X_ELEMENT);
#if MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS != 0
    out[0] &=  ((DIGIT)1 << MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS) - 1 ;
#endif

} // end gf2x_mod

