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

#include "../include/gf2x_arith_mod_xPplusOne.h"
#include "../../common/include/rng.h"
#include <string.h>  // memcpy(...), memset(...)
#include "../../common/include/architecture_detect.h"
#include <stdalign.h>


/*----------------------------------------------------------------------------*/

#if (defined(DIGIT_IS_UINT8) || defined(DIGIT_IS_UINT16))
static
uint8_t byte_reverse_with_less32bitDIGIT(uint8_t b)
{
    uint8_t r = b;
    int s = (sizeof(b) << 3) - 1;
    for (b >>= 1; b; b >>= 1) {
        r <<= 1;
        r |= b & 1;
        s--;
    }
    r <<= s;
    return r;
} // end byte_reverse_less32bitDIGIT
#endif

#if defined(DIGIT_IS_UINT32)
static
uint8_t byte_reverse_with_32bitDIGIT(uint8_t b)
{
    b = ( (b * 0x0802LU & 0x22110LU) | (b * 0x8020LU & 0x88440LU)
        ) * 0x10101LU >> 16;
    return b;
} // end byte_reverse_32bitDIGIT
#endif

#if defined(DIGIT_IS_UINT64)
static
uint8_t byte_reverse_with_64bitDIGIT(uint8_t b)
{
    b = (b * 0x0202020202ULL & 0x010884422010ULL) % 1023;
    return b;
} // end byte_reverse_64bitDIGIT
#endif

/*----------------------------------------------------------------------------*/

static
DIGIT reverse_digit(const DIGIT b)
{
    int i;
    union toReverse_t {
        uint8_t inByte[DIGIT_SIZE_B];
        DIGIT digitValue;
    } toReverse;

    toReverse.digitValue = b;
#if defined(DIGIT_IS_UINT64)
    for (i = 0; i < DIGIT_SIZE_B; i++)
        toReverse.inByte[i] = byte_reverse_with_64bitDIGIT(toReverse.inByte[i]);
    return __builtin_bswap64(toReverse.digitValue);
#elif defined(DIGIT_IS_UINT32)
    for (i = 0; i < DIGIT_SIZE_B; i++)
        toReverse.inByte[i] = byte_reverse_with_32bitDIGIT(toReverse.inByte[i]);
    return __builtin_bswap32(toReverse.digitValue);
#elif defined(DIGIT_IS_UINT16)
    for (i = 0; i < DIGIT_SIZE_B; i++)
        toReverse.inByte[i] = byte_reverse_with_less32bitDIGIT(toReverse.inByte[i]);
    reversed = __builtin_bswap16(toReverse.digitValue);
#elif defined(DIGIT_IS_UINT8)
    return byte_reverse_with_less32bitDIGIT(toReverse.inByte[0]);
#else
#error "Missing implementation for reverse_digit(...) \
with this CPU word bitsize !!! "
#endif
    return toReverse.digitValue;
} // end reverse_digit


/*----------------------------------------------------------------------------*/

void gf2x_transpose_in_place(DIGIT A[])
{
    /* it keeps the lsb in the same position and
     * inverts the sequence of the remaining bits
     */

    DIGIT mask = (DIGIT)0x1;
    DIGIT rev1, rev2, a00;
    int i, slack_bits_amount = NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b - P;

    if (NUM_DIGITS_GF2X_ELEMENT == 1) {
        a00 = A[0] & mask;
        right_bit_shift(1, A);
        rev1 = reverse_digit(A[0]);
#if (NUM_DIGITS_GF2X_MOD_P_ELEMENT*DIGIT_SIZE_b - P)
        rev1 >>= (DIGIT_SIZE_b-(P%DIGIT_SIZE_b));
#endif
        A[0] = (rev1 & (~mask)) | a00;
        return;
    }

    a00 = A[NUM_DIGITS_GF2X_ELEMENT-1] & mask;
    right_bit_shift(NUM_DIGITS_GF2X_ELEMENT, A);

    for (i = NUM_DIGITS_GF2X_ELEMENT-1; i >= (NUM_DIGITS_GF2X_ELEMENT+1)/2; i--) {
        rev1 = reverse_digit(A[i]);
        rev2 = reverse_digit(A[NUM_DIGITS_GF2X_ELEMENT-1-i]);
        A[i] = rev2;
        A[NUM_DIGITS_GF2X_ELEMENT-1-i] = rev1;
    }
    if (NUM_DIGITS_GF2X_ELEMENT % 2 == 1)
        A[NUM_DIGITS_GF2X_ELEMENT/2] = reverse_digit(A[NUM_DIGITS_GF2X_ELEMENT/2]);

    if (slack_bits_amount)
        right_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, A,slack_bits_amount);
    A[NUM_DIGITS_GF2X_ELEMENT-1] = (A[NUM_DIGITS_GF2X_ELEMENT-1] & (~mask)) | a00;
} // end transpose_in_place

/*----------------------------------------------------------------------------*/
/* computes poly times digit multiplication as a support for KTT inverse */
/* PRE : nr = na + 1 */

#ifdef HIGH_PERFORMANCE_X86_64

void gf2x_digit_times_poly_mul_avx(const int nr,
                                   DIGIT Res[NUM_DIGITS_GF2X_ELEMENT+1],
                                   const int na, const DIGIT A[],
                                   const DIGIT B) {

    __m128i prodRes0,prodRes1,
            accumRes,loopCarriedWord,lowToHighWord,
            wideB,wideA;

    int i;
    wideB=_mm_set_epi64x(0, B);
    loopCarriedWord = _mm_set_epi64x(0,0);

    for (i = na-1; i >= 1 ; i=i-2) {
        /*wideA contains [ A[i] A[i-1] ] */
        wideA = _mm_lddqu_si128((__m128i *)&A[i-1]);

        prodRes0 = _mm_clmulepi64_si128(wideA, wideB, 1);
        prodRes1 = _mm_clmulepi64_si128(wideA, wideB, 0);

        accumRes = _mm_xor_si128(loopCarriedWord,prodRes0);
        lowToHighWord = _mm_slli_si128(prodRes1,8);
        accumRes = _mm_xor_si128(accumRes,lowToHighWord);

        accumRes = (__m128i) _mm_shuffle_pd( (__m128d) accumRes,
                                             (__m128d) accumRes, 1);
        _mm_storeu_si128((__m128i *)(&Res[i]), accumRes);

        loopCarriedWord = _mm_srli_si128(prodRes1,8);
    }
    if (i == 0) { /*skipped last iteration i=0, compensate*/
        prodRes0 = _mm_clmulepi64_si128(_mm_set_epi64x(0, A[0]), wideB, 0);

        accumRes = loopCarriedWord;
        accumRes = _mm_xor_si128(accumRes,prodRes0);
        accumRes = (__m128i) _mm_shuffle_pd( (__m128d) accumRes,
                                             (__m128d) accumRes, 1);
        _mm_storeu_si128((__m128i *)(&Res[0]), accumRes);
    } else { /*i == 1*/
        /*regular exit condition, do nothing*/
    }

}

#else
void gf2x_digit_times_poly_mul(const int nr, DIGIT Res[NUM_DIGITS_GF2X_ELEMENT+1],
                               const int na, const DIGIT A[],
                               const DIGIT B) {

    DIGIT pres[2];
    Res[nr-1]=0;
    for (int i = (nr-1)-1; i >= 0 ; i--) {
        GF2X_MUL(2, pres, 1, &A[i], 1, &B);
        Res[i+1] = Res[i+1] ^ pres[1];
        Res[i] =  pres[0];
    }
}
#endif

/*----------------------------------------------------------------------------*/


#define CTIME_IF(mask,then,else)  ((mask&(then)) | (~mask&(else) ))

#define SIGNED_DIGIT int64_t

void gf2x_reflect_in_place(DIGIT A[])
{
    DIGIT rev1,rev2;
    for (int i = NUM_DIGITS_GF2X_ELEMENT-1; i >= (NUM_DIGITS_GF2X_ELEMENT+1)/2; i--) {
        rev1 = reverse_digit(A[i]);
        rev2 = reverse_digit(A[NUM_DIGITS_GF2X_ELEMENT-1-i]);
        A[i] = rev2;
        A[NUM_DIGITS_GF2X_ELEMENT-1-i] = rev1;
    }
    if (NUM_DIGITS_GF2X_ELEMENT % 2 == 1)
        A[NUM_DIGITS_GF2X_ELEMENT/2] = reverse_digit(A[NUM_DIGITS_GF2X_ELEMENT/2]);
} // end transpose_in_place

void gf2x_mod_mul(DIGIT Res[], const DIGIT A[], const DIGIT B[])
{

    DIGIT aux[2*NUM_DIGITS_GF2X_ELEMENT];
    GF2X_MUL(2*NUM_DIGITS_GF2X_ELEMENT, aux,
             NUM_DIGITS_GF2X_ELEMENT, A,
             NUM_DIGITS_GF2X_ELEMENT, B);
    gf2x_mod(Res, 2*NUM_DIGITS_GF2X_ELEMENT, aux);

} // end gf2x_mod_mul

/*----------------------------------------------------------------------------*/
/* computes operand*x^shiftAmt + Res. assumes res is
 * wide and operand is NUM_DIGITS_GF2X_ELEMENT with blank slack bits */
static inline
void gf2x_fmac(DIGIT Res[],
               const DIGIT operand[],
               const unsigned int shiftAmt) {

#if defined(HIGH_PERFORMANCE_X86_64)
    DIGIT shiftedOp[NUM_DIGITS_GF2X_ELEMENT*2] = {0};
    memcpy(shiftedOp+NUM_DIGITS_GF2X_ELEMENT,
           operand,
           NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    left_bit_shift_wide_n(NUM_DIGITS_GF2X_ELEMENT*2,
                          shiftedOp, shiftAmt);
    gf2x_add(NUM_DIGITS_GF2X_ELEMENT*2, Res,
             NUM_DIGITS_GF2X_ELEMENT*2, Res,
             NUM_DIGITS_GF2X_ELEMENT*2, shiftedOp);
#else
    unsigned int digitShift = shiftAmt / DIGIT_SIZE_b;
    unsigned int inDigitShift= shiftAmt % DIGIT_SIZE_b;
    DIGIT tmp,prevLo=0;
    int i;
    SIGNED_DIGIT inDigitShiftMask = ((SIGNED_DIGIT) (inDigitShift>0)  << (DIGIT_SIZE_b-1)) >> (DIGIT_SIZE_b-1);
    for(i = NUM_DIGITS_GF2X_ELEMENT-1; i>=0 ; i--) {
        tmp = operand[i];
        Res[NUM_DIGITS_GF2X_ELEMENT+i-digitShift] ^= prevLo | (tmp << inDigitShift);
        prevLo = (tmp >> (DIGIT_SIZE_b - inDigitShift)) & inDigitShiftMask;
    }
    Res[NUM_DIGITS_GF2X_ELEMENT+i-digitShift] ^= prevLo;
#endif
}

/*----------------------------------------------------------------------------*/

/*PRE: the representation of the sparse coefficients is sorted in increasing
 order of the coefficients themselves */
void gf2x_mod_mul_dense_to_sparse(DIGIT Res[],
                                  const DIGIT dense[],
                                  const POSITION_T sparse[],
                                  unsigned int nPos)
{
    DIGIT resDouble[2*NUM_DIGITS_GF2X_ELEMENT] = {0};

    for (unsigned int i = 0; i < nPos; i++) {
        if (sparse[i] != INVALID_POS_VALUE) {
            gf2x_fmac(resDouble, dense,sparse[i]);
        }
    }

    gf2x_mod(Res, 2*NUM_DIGITS_GF2X_ELEMENT, resDouble);

} // end gf2x_mod_mul

/*----------------------------------------------------------------------------*/


void gf2x_transpose_in_place_sparse(int sizeA, POSITION_T A[])
{

    POSITION_T t;
    int i = 0, j;

    if (A[i] == 0) {
        i = 1;
    }
    j = i;

    for (; i < sizeA && A[i] != INVALID_POS_VALUE; i++) {
        A[i] = P-A[i];
    }

    for (i -= 1; j < i; j++, i--) {
        t = A[j];
        A[j] = A[i];
        A[i] = t;
    }

} // end gf2x_transpose_in_place_sparse
