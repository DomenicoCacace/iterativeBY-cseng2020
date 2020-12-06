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
#include "../../common/include/architecture_detect.h"

/*----------------------------------------------------------------------------*/
/*
 * Elements of GF(2)[x] are stored in compact dense binary form.
 *
 * Each bit in a byte is assumed to be the coefficient of a binary
 * polynomial f(x), in Big-Endian format (i.e., reading everything from
 * left to right, the most significant element is met first):
 *
 * byte:(0000 0000) == 0x00 ... f(x) == 0
 * byte:(0000 0001) == 0x01 ... f(x) == 1
 * byte:(0000 0010) == 0x02 ... f(x) == x
 * byte:(0000 0011) == 0x03 ... f(x) == x+1
 * ...                      ... ...
 * byte:(0000 1111) == 0x0F ... f(x) == x^{3}+x^{2}+x+1
 * ...                      ... ...
 * byte:(1111 1111) == 0xFF ... f(x) == x^{7}+x^{6}+x^{5}+x^{4}+x^{3}+x^{2}+x+1
 *
 *
 * A "machine word" (A_i) is considered as a DIGIT.
 * Bytes in a DIGIT are assumed in Big-Endian format:
 * E.g., if sizeof(DIGIT) == 4:
 * A_i: A_{i,3} A_{i,2} A_{i,1} A_{i,0}.
 * A_{i,3} denotes the most significant byte, A_{i,0} the least significant one.
 * f(x) ==   x^{31} + ... + x^{24} +
 *         + x^{23} + ... + x^{16} +
 *         + x^{15} + ... + x^{8}  +
 *         + x^{7}  + ... + x^{0}
 *
 *
 * Multi-precision elements (i.e., with multiple DIGITs) are stored in
 * Big-endian format:
 *           A = A_{n-1} A_{n-2} ... A_1 A_0
 *
 *           position[A_{n-1}] == 0
 *           position[A_{n-2}] == 1
 *           ...
 *           position[A_{1}]  ==  n-2
 *           position[A_{0}]  ==  n-1
 */
/*----------------------------------------------------------------------------*/

#define MIN_KAR_DIGITS 9
#define MIN_TOOM_DIGITS 50
#define GF2X_MUL gf2x_mul_TC3

/*----------------------------------------------------------------------------*/

#if (defined HIGH_PERFORMANCE_X86_64) || (defined HIGH_COMPATIBILITY_X86_64)

#define LOAD_m128_FROM_u64(a,b) ((a) = _mm_loadu_si128((__m128i *)(b)))
#define STORE_m128_INTO_u64(a,b) _mm_storeu_si128((__m128i *)(a), (b))

static inline void xor_128_v_with_r(uint64_t* i,__m128i v) {
    __m128i v1 = _mm_loadu_si128((__m128i *)i);
    v1 = (__m128i) _mm_shuffle_pd( (__m128d) v1, (__m128d) v1, 1);
    v1 = _mm_xor_si128(v1, _mm_loadu_si128(&v));
    v1 = (__m128i) _mm_shuffle_pd( (__m128d) v1, (__m128d) v1, 1);
    _mm_storeu_si128((__m128i *)i, v1);
}

// 1-word multiplication
static inline void gf2x_mul_1_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    __m128i res;
    res = _mm_clmulepi64_si128(_mm_set_epi64x(0, b[0]),_mm_set_epi64x(0, c[0]), 0);
    res = (__m128i) _mm_shuffle_pd( (__m128d) res, (__m128d) res, 1);
    STORE_m128_INTO_u64(a, res);
}

//2-word multiplication
static inline void gf2x_mul_2_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    register __m128i v1, v2;
    __m128i t1, t2, t3, t4;
    LOAD_m128_FROM_u64(v1, b);
    LOAD_m128_FROM_u64(v2, c);
    t1 = _mm_clmulepi64_si128(v1, v2, 0x11);
    t2 = _mm_clmulepi64_si128(v1, v2, 0x0);
    t3 = _mm_xor_si128(v1, _mm_srli_si128(v1, 8));
    t4 = _mm_xor_si128(v2, _mm_srli_si128(v2, 8));
    v1 = _mm_clmulepi64_si128(t3, t4, 0);
    v2 = _mm_xor_si128(_mm_xor_si128(v1, t2), t1);
    t1 = _mm_xor_si128(t1, _mm_slli_si128(v2, 8));
    t2 = _mm_xor_si128(t2, _mm_srli_si128(v2, 8));
    v1 = (__m128i) _mm_shuffle_pd( (__m128d) t1, (__m128d) t1,1);
    v2 = (__m128i) _mm_shuffle_pd( (__m128d) t2, (__m128d) t2,1);
    STORE_m128_INTO_u64(a, v2);
    STORE_m128_INTO_u64(a + 2, v1);
}

// 3-word multiplication
static inline void gf2x_mul_3_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    __m128i v1, v2;
    __m128i t1, t2, t3;
    __m128i t4, t5, t6, t7, t8;
    t3 = _mm_set_epi64x(c[0], b[0]);
    t7 = _mm_clmulepi64_si128(t3, t3, 1);

    t4 = _mm_loadu_si128((__m128i *)(b+1));
    t5 = _mm_loadu_si128((__m128i *)(c+1));
    t8 = _mm_clmulepi64_si128(t4, t5, 0x11);

    t6 = _mm_clmulepi64_si128(t4, t5, 0);
    v1 = _mm_unpackhi_epi64(t4, t5);
    v2 = _mm_unpacklo_epi64(t4, t5);
    t4 = _mm_xor_si128(v1, v2);
    t1 = _mm_clmulepi64_si128(t4, t4, 1);
    t5 = _mm_xor_si128(t3, v2);
    t2 = _mm_clmulepi64_si128(t5, t5, 1);
    v1 = _mm_xor_si128(v1, t3);
    t3 = _mm_clmulepi64_si128(v1, v1, 1);
    v1 = _mm_xor_si128(t6, t8);
    t1 = _mm_xor_si128(t1, v1);
    t2 = _mm_xor_si128(t2, _mm_xor_si128(t6, t7));
    t3 = _mm_xor_si128(t3, _mm_xor_si128(v1, t7));
    t8 = _mm_xor_si128(t8, _mm_slli_si128(t1, 8));
    t7 = _mm_xor_si128(t7, _mm_srli_si128(t2, 8));
    t3 = _mm_xor_si128(t3, _mm_alignr_epi8(t2, t1, 8));

    v1 = (__m128i) _mm_shuffle_pd( (__m128d) t7, (__m128d) t7,1);
    v2 = (__m128i) _mm_shuffle_pd( (__m128d) t3, (__m128d) t3,1);
    t1 = (__m128i) _mm_shuffle_pd( (__m128d) t8, (__m128d) t8,1);
    STORE_m128_INTO_u64(a, v1);
    STORE_m128_INTO_u64(a+2, v2);
    STORE_m128_INTO_u64(a+4, t1);
}

// 4-word multiplication (non-recursive)
static inline void gf2x_mul_4_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    register __m128i v1, v2, t1, t2;
    __m128i m[9], bc0, bc1, bc2, bc3;
    v1 = _mm_set_epi64x(b[2], b[3]);
    v2 = _mm_set_epi64x(c[2], c[3]);
    t1 = _mm_set_epi64x(b[0], b[1]);
    t2 = _mm_set_epi64x(c[0], c[1]);

    bc0 = _mm_unpacklo_epi64(v1, v2);
    bc1 = _mm_unpackhi_epi64(v1, v2);
    bc2 = _mm_unpacklo_epi64(t1, t2);
    bc3 = _mm_unpackhi_epi64(t1, t2);

    m[0] = _mm_clmulepi64_si128(bc0, bc0, 1);
    m[1] = _mm_clmulepi64_si128(bc1, bc1, 1);
    m[2] = _mm_clmulepi64_si128(bc2, bc2, 1);
    m[3] = _mm_clmulepi64_si128(bc3, bc3, 1);
    t1   = _mm_xor_si128(bc0, bc1);
    t2   = _mm_xor_si128(bc2, bc3);
    m[4] = _mm_clmulepi64_si128(t1, t1, 1);
    m[5] = _mm_clmulepi64_si128(t2, t2, 1);
    t1   = _mm_xor_si128(bc0, bc2);
    t2   = _mm_xor_si128(bc1, bc3);
    m[6] = _mm_clmulepi64_si128(t1, t1, 1);
    m[7] = _mm_clmulepi64_si128(t2, t2, 1);
    v1   = _mm_xor_si128(t1, t2);
    m[8] = _mm_clmulepi64_si128(v1, v1, 1);
    t1   = _mm_xor_si128(m[0], m[1]);
    t2   = _mm_xor_si128(m[2], m[6]);
    v1   = _mm_xor_si128(t1, m[4]);
    bc0  = _mm_xor_si128(m[0], _mm_slli_si128(v1, 8));
    bc1  = _mm_xor_si128(t1, t2);
    t1   = _mm_xor_si128(m[2], m[3]);
    t2   = _mm_xor_si128(m[1], m[7]);
    v2   = _mm_xor_si128(t1, m[5]);
    bc2  = _mm_xor_si128(t1, t2);
    bc3  = _mm_xor_si128(m[3], _mm_srli_si128(v2, 8));
    t1   = _mm_xor_si128(m[6], m[7]);
    t2   = _mm_xor_si128(_mm_xor_si128(v1, v2), _mm_xor_si128(t1, m[8]));
    bc1  = _mm_xor_si128(bc1, _mm_alignr_epi8(t2, v1, 8));
    bc2  = _mm_xor_si128(bc2, _mm_alignr_epi8(v2, t2, 8));

    bc0 = (__m128i) _mm_shuffle_pd( (__m128d) bc0, (__m128d) bc0, 1);
    bc1 = (__m128i) _mm_shuffle_pd( (__m128d) bc1, (__m128d) bc1, 1);
    bc2 = (__m128i) _mm_shuffle_pd( (__m128d) bc2, (__m128d) bc2, 1);
    bc3 = (__m128i) _mm_shuffle_pd( (__m128d) bc3, (__m128d) bc3, 1);

    STORE_m128_INTO_u64(a+6, bc0);
    STORE_m128_INTO_u64(a+4, bc1);
    STORE_m128_INTO_u64(a+2, bc2);
    STORE_m128_INTO_u64(a+0, bc3);
}

// 5-word multiplication (strategy 5-1)
static
inline
void gf2x_mul_5_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    register __m128i v1, v2, t1, t2,tmp;
    __m128i m[14], bc[5];
    bc[0] = _mm_set_epi64x(c[4], b[4]);
    bc[1] = _mm_set_epi64x(c[3], b[3]);
    bc[2] = _mm_set_epi64x(c[2], b[2]);
    bc[3] = _mm_set_epi64x(c[1], b[1]);
    bc[4] = _mm_set_epi64x(c[0], b[0]);

    LOAD_m128_FROM_u64(v1, b+3);
    LOAD_m128_FROM_u64(v2, c+3);
    m[1] = _mm_clmulepi64_si128(v1, v2, 0x11);
    m[2] = _mm_clmulepi64_si128(v1, v2, 0);
    v1 = _mm_set_epi64x(b[1], b[2]);
    v2 = _mm_set_epi64x(c[1], c[2]);
    m[3] = _mm_clmulepi64_si128(v1, v2, 0);
    m[4] = _mm_clmulepi64_si128(v1, v2, 0x11);
    m[5] = _mm_clmulepi64_si128(bc[4], bc[4], 1);
    v1 = _mm_xor_si128(bc[0], bc[1]);
    m[6] = _mm_clmulepi64_si128(v1, v1, 1);
    v2 = _mm_xor_si128(bc[0], bc[2]);
    m[7]= _mm_clmulepi64_si128(v2, v2, 1);
    t1 = _mm_xor_si128(bc[4], bc[2]);
    m[8] = _mm_clmulepi64_si128(t1, t1, 1);
    t2 = _mm_xor_si128(bc[3], bc[4]);
    m[9] = _mm_clmulepi64_si128(t2, t2, 1);
    v2 = _mm_xor_si128(v2, bc[3]);
    m[10]= _mm_clmulepi64_si128(v2, v2, 1);
    t1 = _mm_xor_si128(t1, bc[1]);
    m[11] = _mm_clmulepi64_si128(t1, t1, 1);
    v1 = _mm_xor_si128(v1, t2);
    m[12] = _mm_clmulepi64_si128(v1, v1, 1);
    v1 = _mm_xor_si128(v1, bc[2]);
    m[13] = _mm_clmulepi64_si128(v1, v1, 1);

    tmp = m[1];
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+8), tmp);

    tmp = m[5];
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+0), tmp);

    m[0] = _mm_xor_si128(m[1], m[2]);

    tmp = _mm_xor_si128(m[0], _mm_xor_si128(m[7], m[3]));
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    STORE_m128_INTO_u64(a+6,tmp);

    v1 = _mm_xor_si128(m[0], m[6]);
    m[0] = _mm_xor_si128(m[4], m[5]);

    tmp = _mm_xor_si128(m[0], _mm_xor_si128(m[8], m[3]));
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    STORE_m128_INTO_u64(a+2, tmp);

    v2 = _mm_xor_si128(m[0], m[9]);

    register __m128i t;
    t = _mm_xor_si128(m[13], v1);
    t = _mm_xor_si128(t, v2);
    t = _mm_xor_si128(t, m[10]);
    t = _mm_xor_si128(t, m[11]);

    tmp = t;
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+4), tmp);

    t = _mm_xor_si128(m[13], m[12]);

    tmp = _mm_load_si128((__m128i *)(a+6));
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    m[0] = _mm_xor_si128(tmp, t);

    tmp = _mm_load_si128((__m128i *)(a+2));
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    t = _mm_xor_si128(tmp, t);
    m[0] = _mm_xor_si128(m[0], m[5]);
    m[0] = _mm_xor_si128(m[0], m[11]);
    t = _mm_xor_si128(t, m[1]);
    t = _mm_xor_si128(t, m[10]);

    xor_128_v_with_r(a+7, v1);
    xor_128_v_with_r(a+5, t);
    xor_128_v_with_r(a+3, m[0]);
    xor_128_v_with_r(a+1, v2);
}

// 6-word multiplication (1 round Karatsuba w/ gf2x_mul_3_avx)
static inline void gf2x_mul_6_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    /* compute onto destination b0c0 */
    gf2x_mul_3_avx(a,b,c);
    /* compute onto destination b0c0 */
    gf2x_mul_3_avx(a+6,b+3,c+3);

    alignas(32) uint64_t sum1[3], sum2[3], prodsum[6];
    __m128i tmp1,tmp2;
    LOAD_m128_FROM_u64(tmp1, c);
    LOAD_m128_FROM_u64(tmp2, c+3);
    tmp1 = _mm_xor_si128(tmp1, tmp2);
    STORE_m128_INTO_u64(sum1, tmp1);
    sum1[2] = c[2]^c[5];

    LOAD_m128_FROM_u64(tmp1, b);
    LOAD_m128_FROM_u64(tmp2, b+3);
    tmp1 = _mm_xor_si128(tmp1,tmp2);
    STORE_m128_INTO_u64(sum2, tmp1);
    sum2[2] = b[2]^b[5];

    /* (a1+a0)*(b1+b0) +  */
    gf2x_mul_3_avx(prodsum,sum1,sum2);

    LOAD_m128_FROM_u64(tmp1, prodsum);
    LOAD_m128_FROM_u64(tmp2, a);
    tmp1 = _mm_xor_si128(tmp1,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+6);
    tmp1 = _mm_xor_si128(tmp1,tmp2);

    __m128i tmp3;
    LOAD_m128_FROM_u64(tmp3, prodsum+2);
    LOAD_m128_FROM_u64(tmp2, a+2);
    tmp3 = _mm_xor_si128(tmp3,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+8);
    tmp3 = _mm_xor_si128(tmp3,tmp2);

    __m128i tmp4;
    LOAD_m128_FROM_u64(tmp4, prodsum+4);
    LOAD_m128_FROM_u64(tmp2, a+4);
    tmp4 = _mm_xor_si128(tmp4,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+10);
    tmp4 = _mm_xor_si128(tmp4,tmp2);


    LOAD_m128_FROM_u64(tmp2, a+3);
    tmp1 = _mm_xor_si128(tmp1,tmp2);
    STORE_m128_INTO_u64(a + 3, tmp1);

    LOAD_m128_FROM_u64(tmp2, a+5);
    tmp3 = _mm_xor_si128(tmp3,tmp2);
    STORE_m128_INTO_u64(a + 5, tmp3);

    LOAD_m128_FROM_u64(tmp2, a+7);
    tmp4 = _mm_xor_si128(tmp4,tmp2);
    STORE_m128_INTO_u64(a + 7, tmp4);
}

// 7-word multiplication (strategy 7-1)
static inline void gf2x_mul_7_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    __m128i m[22], bc[7];
    __m128i v1, v2;
    __m128i t1, t2, t3, t4, t5, t6, t7, t8,tmp;
    bc[0] = _mm_set_epi64x(c[6], b[6]);
    bc[1] = _mm_set_epi64x(c[5], b[5]);
    bc[2] = _mm_set_epi64x(c[4], b[4]);
    bc[3] = _mm_set_epi64x(c[3], b[3]);
    bc[4] = _mm_set_epi64x(c[2], b[2]);
    bc[5] = _mm_set_epi64x(c[1], b[1]);
    bc[6] = _mm_set_epi64x(c[0], b[0]);

    v1 = _mm_set_epi64x(b[5],b[6]);
    v2 = _mm_set_epi64x(c[5],c[6]);
    m[1] = _mm_clmulepi64_si128(v1, v2, 0); //p0
    m[2] = _mm_clmulepi64_si128(v1, v2, 0x11); //p1
    t1 = _mm_xor_si128(v1, _mm_xor_si128(_mm_slli_si128(v1, 8), _mm_cvtsi64_si128(b[4])));
    t2 = _mm_xor_si128(v2, _mm_xor_si128(_mm_slli_si128(v2, 8), _mm_cvtsi64_si128(c[4])));
    m[4] = _mm_clmulepi64_si128(t1, t2, 0); //p02
    m[3] = _mm_clmulepi64_si128(t1, t2, 0x11); //p01
    v1 = _mm_set_epi64x(b[1],b[2]);
    v2 = _mm_set_epi64x(c[1],c[2]);

    m[5] = _mm_clmulepi64_si128(v1, v2, 0);    //p4
    m[6] = _mm_clmulepi64_si128(v1, v2, 0x11); //p5
    t3 = _mm_xor_si128(v1, _mm_set1_epi64x(b[0]));
    t4 = _mm_xor_si128(v2, _mm_set1_epi64x(c[0]));
    m[7] = _mm_clmulepi64_si128(t3, t4, 0);    //p46
    m[8] = _mm_clmulepi64_si128(t3, t4, 0x11); //p56
    v1 = _mm_xor_si128(t1, t3);
    v2 = _mm_xor_si128(t2, t4);
    m[9] = _mm_clmulepi64_si128(v1, v2, 0);  //p0246
    t5 = _mm_xor_si128(_mm_xor_si128(bc[1], bc[3]), bc[5]);
    m[16] = _mm_clmulepi64_si128(t5, t5, 1); //p135
    t6 = _mm_xor_si128(t5, bc[4]);
    m[17] = _mm_clmulepi64_si128(t6, t6, 1);  //p1345
    m[18] = _mm_clmulepi64_si128(_mm_xor_si128(v1, t5), _mm_xor_si128(v2, _mm_srli_si128(t5, 8)), 0); //p0123456
    v1 = _mm_xor_si128(_mm_srli_si128(t1, 8), t3);
    v2 = _mm_xor_si128(_mm_srli_si128(t2, 8), t4);
    t7 = _mm_xor_si128(_mm_insert_epi64(v1, 0, 1), _mm_slli_si128(v2, 8));
    m[15] = _mm_clmulepi64_si128(t7, t7, 1);  //p0146
    t8 = _mm_xor_si128(t7, bc[3]);
    m[10] = _mm_clmulepi64_si128(t8, t8, 1); //p01346
    t7 = _mm_xor_si128(bc[3], bc[0]);
    t7 = _mm_xor_si128(t7, _mm_srli_si128(t3, 8));
    t7 = _mm_xor_si128(t7, _mm_insert_epi64(t4, 0, 0));
    m[11] = _mm_clmulepi64_si128(t7, t7, 1);  //p0356
    t7 = _mm_xor_si128(t7, bc[2]);
    m[12] = _mm_clmulepi64_si128(t7, t7, 1);  //p02356
    m[13] = _mm_clmulepi64_si128(bc[2], bc[2], 1); //p2

    m[14] = _mm_clmulepi64_si128(bc[6], bc[6], 1); //p6
    t5 = _mm_xor_si128(_mm_xor_si128(bc[2], bc[4]), bc[5]);
    t6 = _mm_xor_si128(t5, bc[1]);
    m[19] = _mm_clmulepi64_si128(t6, t6, 1); //p1245
    t7 = _mm_xor_si128(t5, bc[6]);
    m[20] = _mm_clmulepi64_si128(t7, t7, 1); //p2456
    t5 = _mm_xor_si128(bc[2], bc[3]);
    t6 = _mm_xor_si128(t5, _mm_xor_si128(bc[0], bc[4]));
    m[21] = _mm_clmulepi64_si128(t6, t6, 1); //p0234
    t7 = _mm_xor_si128(t5, _mm_xor_si128(bc[1], bc[6]));
    m[0] = _mm_clmulepi64_si128(t7, t7, 1); //p1236

    tmp = m[1];
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+12), tmp);

    tmp = m[14];
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+0), tmp);

    t1 = _mm_xor_si128(m[1], m[2]);
    t2 = _mm_xor_si128(m[4], m[13]);
    t8 = _mm_xor_si128(t1, t2);

    tmp = t8;
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+10), tmp);
    _mm_store_si128((__m128i *)(a+8), tmp);
    t8 = _mm_xor_si128(t1, m[3]);

    xor_128_v_with_r(a+11, t8);
    t7 = _mm_xor_si128(t2, m[3]);

    tmp = t7;
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+6), tmp);
    _mm_store_si128((__m128i *)(a+4), tmp);

    t5 = _mm_xor_si128(m[6], m[14]);
    t6 = _mm_xor_si128(m[5], m[7]);
    t4 = _mm_xor_si128(t5, t6);

    tmp = t4;
    tmp = (__m128i) _mm_shuffle_pd( (__m128d) tmp, (__m128d) tmp, 1);
    _mm_store_si128((__m128i *)(a+2), tmp);

    xor_128_v_with_r(a+1, _mm_xor_si128(t5, m[8]));
    t3 = _mm_xor_si128(m[8], m[14]);
    t1 = _mm_xor_si128(m[15], m[17]);
    t5 = _mm_xor_si128(m[16], m[9]);
    v1 = _mm_xor_si128(m[8], m[6]);

    xor_128_v_with_r(a+5, _mm_xor_si128(_mm_xor_si128(t7, t5), _mm_xor_si128(_mm_xor_si128(t6, t3),
                                        _mm_xor_si128(m[20], t1))));
    t1 = _mm_xor_si128(m[12], t1);
    v2 = _mm_xor_si128(m[0], _mm_xor_si128(m[19], m[21]));
    xor_128_v_with_r(a+7, _mm_xor_si128(_mm_xor_si128(t1, v2), _mm_xor_si128(_mm_xor_si128(t6, t3),
                                        _mm_xor_si128(m[2], m[3]))));
    xor_128_v_with_r(a+6, _mm_xor_si128(_mm_xor_si128(v1, v2), _mm_xor_si128(m[10], m[20])));
    t3 = _mm_xor_si128(m[10], _mm_xor_si128(m[18], m[21]));
    xor_128_v_with_r(a+4, _mm_xor_si128(_mm_xor_si128(_mm_xor_si128(m[1], m[6]), t6),
                                        _mm_xor_si128(m[0], _mm_xor_si128(t1, t3))));
    xor_128_v_with_r(a+8, _mm_xor_si128(_mm_xor_si128(t1, t5), _mm_xor_si128(_mm_xor_si128(m[18], m[20]),
                                        _mm_xor_si128(v1, m[19]))));

    xor_128_v_with_r(a+3, _mm_xor_si128(_mm_xor_si128(_mm_xor_si128(m[11], m[17]), _mm_xor_si128(m[2], m[19])),
                                        _mm_xor_si128(_mm_xor_si128(t4, t2), _mm_xor_si128(t3, t5))));
    v1 = _mm_xor_si128(_mm_xor_si128(m[11], m[17]), m[20]);
    v2 = _mm_xor_si128(_mm_xor_si128(m[0], m[10]), m[12]);
    xor_128_v_with_r(a+9, _mm_xor_si128(_mm_xor_si128(t6, m[8]), _mm_xor_si128(_mm_xor_si128(t5, t8),
                                        _mm_xor_si128(v1, v2))));
}

// 8-word multiplication (1 round Karatsuba w/ gf2x_mul_4_avx)
static inline void gf2x_mul_8_avx(uint64_t *a, const uint64_t *b, const uint64_t *c) {
    /* compute onto destination b0c0 */
    gf2x_mul_4_avx(a,b,c);
    /* compute onto destination b0c0 */
    gf2x_mul_4_avx(a+8,b+4,c+4);

    alignas(32) uint64_t sum1[4], sum2[4], prodsum[8];
    __m128i tmp1,tmp2;

    LOAD_m128_FROM_u64(tmp1, c);
    LOAD_m128_FROM_u64(tmp2, c+4);
    tmp1 = _mm_xor_si128(tmp1, tmp2);
    STORE_m128_INTO_u64(sum1, tmp1);
    LOAD_m128_FROM_u64(tmp1, c+2);
    LOAD_m128_FROM_u64(tmp2, c+6);
    tmp1 = _mm_xor_si128(tmp1, tmp2);
    STORE_m128_INTO_u64(sum1+2, tmp1);

    LOAD_m128_FROM_u64(tmp1, b);
    LOAD_m128_FROM_u64(tmp2, b+4);
    tmp1 = _mm_xor_si128(tmp1, tmp2);
    STORE_m128_INTO_u64(sum2, tmp1);
    LOAD_m128_FROM_u64(tmp1, b+2);
    LOAD_m128_FROM_u64(tmp2, b+6);
    tmp1 = _mm_xor_si128(tmp1, tmp2);
    STORE_m128_INTO_u64(sum2+2, tmp1);

    /* (a1+a0)*(b1+b0) +  */
    gf2x_mul_4_avx(prodsum,sum1,sum2);

    LOAD_m128_FROM_u64(tmp1, prodsum);
    LOAD_m128_FROM_u64(tmp2, a);
    tmp1 = _mm_xor_si128(tmp1,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+8);
    tmp1 = _mm_xor_si128(tmp1,tmp2);

    __m128i tmp3;
    LOAD_m128_FROM_u64(tmp3, prodsum+2);
    LOAD_m128_FROM_u64(tmp2, a+2);
    tmp3 = _mm_xor_si128(tmp3,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+10);
    tmp3 = _mm_xor_si128(tmp3,tmp2);

    __m128i tmp4;
    LOAD_m128_FROM_u64(tmp4, prodsum+4);
    LOAD_m128_FROM_u64(tmp2, a+4);
    tmp4 = _mm_xor_si128(tmp4,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+12);
    tmp4 = _mm_xor_si128(tmp4,tmp2);

    __m128i tmp5;
    LOAD_m128_FROM_u64(tmp5, prodsum+6);
    LOAD_m128_FROM_u64(tmp2, a+6);
    tmp5 = _mm_xor_si128(tmp5,tmp2);
    LOAD_m128_FROM_u64(tmp2, a+14);
    tmp5 = _mm_xor_si128(tmp5,tmp2);

    LOAD_m128_FROM_u64(tmp2, a+4);
    tmp1 = _mm_xor_si128(tmp1,tmp2);
    STORE_m128_INTO_u64(a + 4, tmp1);

    LOAD_m128_FROM_u64(tmp2, a+6);
    tmp3 = _mm_xor_si128(tmp3,tmp2);
    STORE_m128_INTO_u64(a + 6, tmp3);

    LOAD_m128_FROM_u64(tmp2, a+8);
    tmp4 = _mm_xor_si128(tmp4,tmp2);
    STORE_m128_INTO_u64(a + 8, tmp4);

    LOAD_m128_FROM_u64(tmp2, a+10);
    tmp5 = _mm_xor_si128(tmp5,tmp2);
    STORE_m128_INTO_u64(a + 10, tmp5);
}

// 9-word multiplication (strategy 9-1)
static inline void gf2x_mul_9_avx(uint64_t *c, const uint64_t *a, const uint64_t *b) {
    alignas(32) uint64_t t1[5], t2[5], t3[10];

    gf2x_mul_5_avx(c+8, a+4, b+4);
    gf2x_mul_4_avx(c, a, b);

    _mm256_store_pd((double *)(t1+1),
                    _mm256_xor_pd(_mm256_loadu_pd((double *)a),
                                  _mm256_loadu_pd((double *)(a+5)))
                   );
    _mm256_storeu_pd((double *)(t2+1),
                     _mm256_xor_pd(_mm256_loadu_pd((double *)b),
                                   _mm256_loadu_pd((double *)(b+5)))
                    );
    t1[0] = a[4];
    t2[0] = b[4];

    gf2x_mul_5_avx(t3, t1, t2);

    __m256d d1 = _mm256_loadu_pd((double *)(t3+6));
    d1 = _mm256_xor_pd(d1, _mm256_loadu_pd((double *)(c+14)));
    d1 = _mm256_xor_pd(d1, _mm256_loadu_pd((double *)(c+4)));

    __m256d d2 = _mm256_loadu_pd((double *)(t3+2));
    d2 = _mm256_xor_pd(d2, _mm256_loadu_pd((double *)(c+10)));
    d2 = _mm256_xor_pd(d2, _mm256_loadu_pd((double *)(c   )));

    _mm_storeu_si128((__m128i *)(c+3),
                     _mm_xor_si128(_mm_loadu_si128((__m128i *)(c+3)),
                                   _mm_xor_si128(_mm_loadu_si128((__m128i *)(t3)),
                                           _mm_loadu_si128((__m128i *)(c+8)))
                                  )
                    );
    _mm256_storeu_pd((double *)(c+9),
                     _mm256_xor_pd(_mm256_loadu_pd((double *)(c+9)), d1));
    _mm256_storeu_pd((double *)(c+5),
                     _mm256_xor_pd(_mm256_loadu_pd((double *)(c+5)), d2));
}

#endif

static inline void gf2x_add(const int nr, DIGIT Res[],
                            const int na, const DIGIT A[],
                            const int nb, const DIGIT B[]) {
#if (defined HIGH_PERFORMANCE_X86_64)
    __m256i a, b;
    unsigned i;
    for(i = 0; i < nr/4; i++) {
        a = _mm256_lddqu_si256( (__m256i *)A + i );
        b = _mm256_lddqu_si256( (__m256i *)B + i );
        _mm256_storeu_si256(((__m256i *)Res + i), _mm256_xor_si256(a, b));
    }
    i = i*2;
    if(nr %4 >= 2) {
        __m128i c, d;
        c = _mm_lddqu_si128( (__m128i *)A + i );
        d = _mm_lddqu_si128( (__m128i *)B + i );
        _mm_storeu_si128(((__m128i *)Res + i), _mm_xor_si128(c, d));
        i++;
    }

    if( (nr & 1) == 1) {
        Res[nr-1] = A[nr-1] ^ B[nr-1];
    }

#elif (defined HIGH_COMPATIBILITY_X86_64)
    __m128i a, b;
    for (unsigned i = 0; i < nr/2; i++) {
        a = _mm_lddqu_si128( (__m128i *)A + i );
        b = _mm_lddqu_si128( (__m128i *)B + i );
        _mm_storeu_si128(((__m128i *)Res + i), _mm_xor_si128(a, b));
    }
    if( (nr & 1) != 0) {
        Res[nr-1] = A[nr-1] ^ B[nr-1];
    }
#else
    for (unsigned i = 0; i < nr; i++)
        Res[i] = A[i] ^ B[i];
#endif
} // end gf2x_add

/*----------------------------------------------------------------------------*/

void GF2X_MUL(const int nr, DIGIT Res[],
              const int na, const DIGIT A[],
              const int nb, const DIGIT B[]
             );

/*----------------------------------------------------------------------------*/

/* Shifts by a single bit  - currently unused used by reflection in DJB inverse, gf2x_mod, TC3 mul*/
static
inline
void right_bit_shift(const int length, DIGIT in[])
{
#if (defined HIGH_PERFORMANCE_X86_64)
    int j;
    if(length>=5) {
        __m256i v,u,x,v_tmp;
        __m128i one;
        one = _mm_setzero_si128();
        one = _mm_insert_epi64(one, 1,0);

        v = _mm256_lddqu_si256( (__m256i *)&in[(length-1)-3]);
        u = _mm256_setzero_si256();
        u = _mm256_insert_epi64(u, in[(length-1)-4], 0);
        x = v;
        x = _mm256_permute4x64_epi64(x,0x93);
        x = _mm256_blend_epi32 (x,u, 0x03);

        _mm256_storeu_si256( ((__m256i *)&in[(length-1)-3]),
                             _mm256_or_si256( _mm256_srl_epi64(v, one),
                                              _mm256_slli_epi64(x,DIGIT_SIZE_b-1)
                                            )
                           );
        u=_mm256_permute4x64_epi64(u,0x39);
        j=(length-1)-8;
        for(; j >= 0; j = j-4) {
            v = _mm256_lddqu_si256( (__m256i *)&in[j]);
            /* shuffle V so that V = [8 7 6 5] -> V = [7 6 5 8] to be blended with
               u[X X X 0]*/
            v_tmp = _mm256_permute4x64_epi64(v,0x39);
            x = _mm256_blend_epi32 (v_tmp,u, 0xC0);
            _mm256_storeu_si256( ((__m256i *)&in[j+1]),
                                 _mm256_or_si256( _mm256_srl_epi64(x, one),
                                                  _mm256_slli_epi64(v,DIGIT_SIZE_b-1)
                                                )
                               );
            u=v_tmp;
            /* useless, I'll just not blend the non-relevant part
            u= _mm256_and_si256(u,u_hi_mask); */
        }
        j+=4;
        /*here the highest word of u contains the unshifted MSW before head*/
        if(j == 0) {
            u=_mm256_srli_epi64(u, 1);
            in[j] = _mm256_extract_epi64 (u, 3);
        }
        if (j > 0) {
            /* stops GCC loop optimizer from complaining from an UB due to signed
             * integer underflow */
            unsigned x;
            x= j;
            for(; x>0; x--) {
                in[x] >>= 1;
                in[x] |= (in[x-1] & (DIGIT)0x01) << (DIGIT_SIZE_b-1);
            }
            in[x] >>= 1;
        }
    } else {
        for(j=length-1; j > 0; j--) {
            in[j] >>= 1;
            in[j] |= (in[j-1] & (DIGIT)0x01) << (DIGIT_SIZE_b-1);
        }
        in[j] >>= 1;
    }
#elif (defined HIGH_COMPATIBILITY_X86_64)
#define UNR 3
    int j;
    __m128i a,b,c,d,e,f;

    for (j = length-1; j > UNR*2 ; j=j-(UNR*2)) {

        a = _mm_lddqu_si128( (__m128i *)&in[j-1]);  //load in[j-1] and in[j]
        b = _mm_lddqu_si128( (__m128i *)&in[j-2]);  //load in[j-2] and in[j-1]
        c = _mm_lddqu_si128( (__m128i *)&in[j-3]);  //load in[j-3] and in[j-2]
        d = _mm_lddqu_si128( (__m128i *)&in[j-4]);  //load in[j-4] and in[j-3]
        e = _mm_lddqu_si128( (__m128i *)&in[j-5]);  //load in[j-5] and in[j-4]
        f = _mm_lddqu_si128( (__m128i *)&in[j-6]);  //load in[j-5] and in[j-6]

        a = _mm_srli_epi64(a, 1);
        b = _mm_slli_epi64(b, (DIGIT_SIZE_b-1));
        c = _mm_srli_epi64(c, 1);
        d = _mm_slli_epi64(d, (DIGIT_SIZE_b-1));
        e = _mm_srli_epi64(e, 1);
        f = _mm_slli_epi64(f, (DIGIT_SIZE_b-1));

        _mm_storeu_si128(((__m128i *)&in[j-1]), _mm_or_si128(a, b));
        _mm_storeu_si128(((__m128i *)&in[j-3]), _mm_or_si128(c, d));
        _mm_storeu_si128(((__m128i *)&in[j-5]), _mm_or_si128(e, f));

    }

    for(; j > 0; j--) {
        in[j] >>= 1;
        in[j] |= (in[j-1] & (DIGIT)0x01) << (DIGIT_SIZE_b-1);
    }
    in[j] >>= 1;
#else
    int j;
    for (j = length-1; j > 0 ; j--) {
        in[j] >>= 1;
        in[j] |=  (in[j-1] & (DIGIT)0x01) << (DIGIT_SIZE_b-1);
    }
    in[j] >>=1;
#endif
} // end right_bit_shift

/*----------------------------------------------------------------------------*/
/* PRE: max allowed shift: DIGIT_SIZE_b */
static inline
void right_bit_shift_n(const int length, DIGIT in[], const int amount) {


#if (defined HIGH_PERFORMANCE_X86_64)
    int j;
    if(length>=5) {
        __m256i v,u,x,v_tmp;

        v = _mm256_lddqu_si256( (__m256i *)&in[(length-1)-3]);
        u = _mm256_setzero_si256();
        u = _mm256_insert_epi64(u, in[(length-1)-4], 0);
        x = v;
        x = _mm256_permute4x64_epi64(x,0x93);
        x = _mm256_blend_epi32 (x,u, 0x03);

        _mm256_storeu_si256( ((__m256i *)&in[(length-1)-3]),
                             _mm256_or_si256( _mm256_srli_epi64(v, amount),
                                              _mm256_slli_epi64(x,DIGIT_SIZE_b-amount)
                                            )
                           );
        u=_mm256_permute4x64_epi64(u,0x39);
        j=(length-1)-8;
        for(; j >= 0; j = j-4) {
            v = _mm256_lddqu_si256( (__m256i *)&in[j]);
            /* shuffle V so that V = [8 7 6 5] -> V = [7 6 5 8] to be blended with
               u[X X X 0]*/
            v_tmp = _mm256_permute4x64_epi64(v,0x39);
            x = _mm256_blend_epi32 (v_tmp,u, 0xC0);
            _mm256_storeu_si256( ((__m256i *)&in[j+1]),
                                 _mm256_or_si256( _mm256_srli_epi64(x, amount),
                                                  _mm256_slli_epi64(v,DIGIT_SIZE_b-amount)
                                                )
                               );
            u=v_tmp;
            /* useless, I'll just not blend the non-relevant part
            u= _mm256_and_si256(u,u_hi_mask); */
        }
        j+=4;
        /*here the highest word of u contains the unshifted MSW before head*/
        if(j == 0) {
            u=_mm256_srli_epi64(u, amount);
            in[j] = _mm256_extract_epi64 (u, 3);
        }
        if (j > 0) {
            /* stops GCC loop optimizer from complaining from an UB due to signed
             * integer underflow */
            unsigned x;
            x= j;
            DIGIT mask;
            mask = ((DIGIT)0x01 << amount) - 1;
            for(; x>0; x--) {
                in[x] >>= amount;
                in[x] |= (in[x-1] & mask) << (DIGIT_SIZE_b-amount);
            }
            in[0] >>= amount;
        }
    } else {
        DIGIT mask;
        mask = ((DIGIT)0x01 << amount) - 1;
        for(j=length-1; j > 0; j--) {
            in[j] >>= amount;
            in[j] |= (in[j-1] & mask) << (DIGIT_SIZE_b-amount);
        }
        in[j] >>= amount;
    }
#elif (defined HIGH_COMPATIBILITY_X86_64)
#define UNR 3
    int j;
    __m128i a,b,c,d,e,f;

    for (j = length-1; j > UNR*2 ; j=j-(UNR*2)) {

        a = _mm_lddqu_si128( (__m128i *)&in[j-1]);  //load in[j-1] and in[j]
        b = _mm_lddqu_si128( (__m128i *)&in[j-2]);  //load in[j-2] and in[j-1]
        c = _mm_lddqu_si128( (__m128i *)&in[j-3]);  //load in[j-3] and in[j-2]
        d = _mm_lddqu_si128( (__m128i *)&in[j-4]);  //load in[j-4] and in[j-3]
        e = _mm_lddqu_si128( (__m128i *)&in[j-5]);  //load in[j-5] and in[j-4]
        f = _mm_lddqu_si128( (__m128i *)&in[j-6]);  //load in[j-5] and in[j-6]

        a = _mm_srli_epi64(a, 1);
        b = _mm_slli_epi64(b, (DIGIT_SIZE_b-1));
        c = _mm_srli_epi64(c, 1);
        d = _mm_slli_epi64(d, (DIGIT_SIZE_b-1));
        e = _mm_srli_epi64(e, 1);
        f = _mm_slli_epi64(f, (DIGIT_SIZE_b-1));

        _mm_storeu_si128(((__m128i *)&in[j-1]), _mm_or_si128(a, b));
        _mm_storeu_si128(((__m128i *)&in[j-3]), _mm_or_si128(c, d));
        _mm_storeu_si128(((__m128i *)&in[j-5]), _mm_or_si128(e, f));

    }
    DIGIT mask;
    mask = ((DIGIT)0x01 << amount) - 1;
    for(; j > 0; j--) {
        in[j] >>= 1;
        in[j] |= (in[j-1] & mask) << (DIGIT_SIZE_b-1);
    }
    in[j] >>= 1;
#else
    int j;
    DIGIT mask;
    mask = ((DIGIT)0x01 << amount) - 1;
    for (j = length-1; j > 0 ; j--) {
        in[j] >>= amount;
        in[j] |=  (in[j-1] & mask) << (DIGIT_SIZE_b - amount);
    }
    in[j] >>= amount;
#endif
} // end right_bit_shift_n

/*----------------------------------------------------------------------------*/
/* Shifts by whole digits */
static
inline
void right_DIGIT_shift_n(const int length, DIGIT in[], int amount)
{
#if defined(HIGH_PERFORMANCE_X86_64)
    __m256i a;
    int j;
    if(length-amount > 4) {
        for(j = length-4; j >= amount+4; j = j-4) {
            /* load from j-amt store in j */
            a = _mm256_lddqu_si256(   (__m256i *) (&in[j - amount]));
            _mm256_storeu_si256(  (__m256i *) (&in[j]), a);
        }
        j = j + 3;
    } else {
        j = length - 1;
    }
    for (; j >= amount; j--) {
        in[j] = in[j-amount];
    }
    for (; j >=0 ; j--) {
        in[j] = (DIGIT)0;
    }
#else
    int j;
    for (j = length-1; j >= amount; j--) {
        in[j] = in[j-amount];
    }
    for (; j >=0 ; j--) {
        in[j] = (DIGIT)0;
    }
#endif
} // end right_DIGIT_shift_n

/*----------------------------------------------------------------------------*/
/* Shift by an arbitrary amount -- used by gf2x_mod_inverse_DJB*/
static inline
void right_bit_shift_wide_n(const int length, DIGIT in[], int amount)
{
    right_DIGIT_shift_n(length, in, amount / DIGIT_SIZE_b);
    right_bit_shift_n(length, in, amount % DIGIT_SIZE_b);
}

/*----------------------------------------------------------------------------*/
/* PRE: max allowed shift: DIGIT_SIZE_b - used by TC3 mul */
static inline
void left_bit_shift_n(const int length, DIGIT in[], const int amount) {
    if ( amount == 0 ) return;
#if (defined HIGH_PERFORMANCE_X86_64)
    int j;
    __m256i a,b;

    for(j = 0; j < (length-1)/4; j++) {

        a = _mm256_lddqu_si256( (__m256i *) &in[0] + j);  //load from in[j] to in[j+3]
        b = _mm256_lddqu_si256( (__m256i *) &in[1] + j);  //load from in[j+1] to in[j+4]

        a = _mm256_slli_epi64(a, amount);
        b = _mm256_srli_epi64(b, (DIGIT_SIZE_b-amount));

        _mm256_storeu_si256( (__m256i *) &in[0] + j, _mm256_or_si256(a,b));
    }

    for(j = j*4; j < length-1; j++) {
        in[j] <<= amount;
        in[j] |= in[j+1] >> (DIGIT_SIZE_b-amount);
    }

    in[length-1] <<= amount; //last element shift
#else
    int j;
    DIGIT mask;
    mask = ~(((DIGIT)0x01 << (DIGIT_SIZE_b - amount)) - 1);
    for (j = 0 ; j < length-1 ; j++) {
        in[j] <<= amount;
        in[j] |=  (in[j+1] & mask) >> (DIGIT_SIZE_b - amount);
    }
    in[j] <<= amount;
#endif
} // end left_bit_shift_n
/*----------------------------------------------------------------------------*/
/* shifts by whole digits - used by gf2x_mod_inverse_KTT */
static inline
void left_DIGIT_shift_n(const int length, DIGIT in[], int amount)
{

#if defined(HIGH_PERFORMANCE_X86_64)
    __m256i a;
    int j;
    if(length-amount > 4) {
        for(j = 0; j < length-amount-4; j = j+4) {
            /* load from j-amt store in j */
            a = _mm256_lddqu_si256(   (__m256i *) (&in[j + amount]));
            _mm256_storeu_si256(  (__m256i *) (&in[j]), a);
        }
        j = j - 1;
    } else {
        j = 0;
    }
    for (; j + amount < length; j++) {
        in[j] = in[j+amount];
    }
    for (; j < length; j++) {
        in[j] = (DIGIT)0;
    }
#else
    int j;
    for (j = 0; (j + amount) < length; j++) {
        in[j] = in[j+amount];
    }
    for (; j < length; j++) {
        in[j] = (DIGIT)0;
    }
#endif
} // end left_bit_shift_n


/*----------------------------------------------------------------------------*/
/* may shift by an arbitrary amount - used by NONE */
static inline
void left_bit_shift_wide_n(const int length, DIGIT in[], int amount)
{
    left_DIGIT_shift_n(length, in, amount / DIGIT_SIZE_b);
    left_bit_shift_n(length, in, amount % DIGIT_SIZE_b);
} // end left_bit_shift_n

/*----------------------------------------------------------------------------*/
