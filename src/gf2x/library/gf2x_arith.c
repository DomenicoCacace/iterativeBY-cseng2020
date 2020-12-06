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

#include "../include/gf2x_arith.h"
#include <string.h>  // memset(...)
#include "../../common/include/architecture_detect.h"

/*----------------------------------------------------------------------------*/
#if (defined HIGH_PERFORMANCE_X86_64) || (defined HIGH_COMPATIBILITY_X86_64)

#define CAT(a, b, c) PRIMITIVE_CAT(a, b, c)
#define PRIMITIVE_CAT(a, b, c) a ## b ## c
#define CHUNK_SIZE 9

/* Arbitrary width multiplication exploiting 1x1 to CHUNK_SIZE x CHUNK_SIZE
 * atomic multiplications.
 * The strategy exploits the largest possible multiplications to compute the
 * partial products starting from the least significant digits
 * at the end of the computation of each set of CHUNK_SIZE intermediates,
 * the remaining remC = (lenght mod CHUNK_SIZE) digits are computed exploiting
 * a remC x remC multiplication and 1x1 multiplications for the remaining part
 * Once only remC intermediate results remain to be computed, a sequence of
 * remC x remC multiplications are employed to compute the length/remC*remC
 * digits.
 * Finally a single (length%remC)x(length%remC) multiplication and a sequence
 * of 1x1 ones are employed to complete the computation of the remaining digits
 */
void gf2x_mul_avx(const int nr, uint64_t Res[],
                  const int na, const uint64_t A[],
                  const int nb, const uint64_t B[]) {
    int i, j;
    int remC, quoC; /* remainder and quotient of operand length mod 9*/
    quoC = na / CHUNK_SIZE;
    remC = na % CHUNK_SIZE;
    int quorem = 0, remrem = 0; /*remainder and quotient of operand length mod (remainder of length mod CHUNK_SIZE) */
    if(remC !=0) {
        quorem = na / remC;
        remrem = na % remC;
    }
    alignas(32) uint64_t buffer[CHUNK_SIZE*2];

    memset(Res, 0x00, nr*sizeof(uint64_t));

    /* compute all the intermediate values allowing */
    for( j = 0; j < quoC; j++) { /* B macro-word idx */
        for( i = 0; i < quoC; i++) { /* A macro-word idx */
            /* CHUNK_SIZE x CHUNK_SIZE full block multiplication */
            CAT(gf2x_mul_,CHUNK_SIZE,_avx)(buffer,
                                           A+(na - CHUNK_SIZE*(i+1)  ),
                                           B+(nb - CHUNK_SIZE*(j+1)  ));
            gf2x_add(2*CHUNK_SIZE,Res+(nr - CHUNK_SIZE*(i+j+2)),
                     2*CHUNK_SIZE,buffer,
                     2*CHUNK_SIZE,Res+(nr - CHUNK_SIZE*(i+j+2)));
        }

        if (remC != 0) {
            /* remC x remC full block mul */
            switch(remC) {
            case 8:
                gf2x_mul_8_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 7:
                gf2x_mul_7_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 6:
                gf2x_mul_6_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 5:
                gf2x_mul_5_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 4:
                gf2x_mul_4_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 3:
                gf2x_mul_3_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 2:
                gf2x_mul_2_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 1:
                gf2x_mul_1_avx(buffer, A, B+(nb - CHUNK_SIZE*j - remC));
                break;
            case 0: ; /* do nothing */
            }
            int offset = CHUNK_SIZE*(quoC+j);
            gf2x_add(2*remC, Res+(nr - offset - 2*remC),
                     2*remC, buffer,
                     2*remC, Res+(nr - offset - 2*remC));
            /* complete the remaining remC x remrem muls */
            offset += remC;
            for (int k = 0; k < CHUNK_SIZE - remC ; k++) { /* remaining b uint64_ts */
                for (int l = 0; l < remC ; l++) { /* remaining a uint64_ts */
                    gf2x_mul_1_avx(buffer, A+(remC-1)-l, B+((nb - CHUNK_SIZE*j - remC-1) - k));
                    gf2x_add(2, Res+(nr - offset - 2 - (l+k)),
                             2, buffer,
                             2, Res+(nr - offset - 2 - (l+k)));
                }
            }
        }
    }

    if (remC != 0) {
        /* complete the multiplication computing the product of the most signif. remC uint64_ts of B
         * by the entire A */
        /* Start with na / remC = quorem, remC x remC muls */
        for ( i = 0; i < quorem ; i++ ) {
            switch(remC) {
            case 8:
                gf2x_mul_8_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 7:
                gf2x_mul_7_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 6:
                gf2x_mul_6_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 5:
                gf2x_mul_5_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 4:
                gf2x_mul_4_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 3:
                gf2x_mul_3_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 2:
                gf2x_mul_2_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 1:
                gf2x_mul_1_avx(buffer, A+(na - remC*(i+1)  ), B);
                break;
            case 0: ; /* do nothing */
            }
            gf2x_add(2*remC,Res+(nr - CHUNK_SIZE*(quoC)- remC*i - 2*remC),
                     2*remC,buffer,
                     2*remC,Res+(nr - CHUNK_SIZE*(quoC)- remC*i - 2*remC));
        }
        /* compute the remrem x remrem block */
        int offset = remC*quorem + CHUNK_SIZE*(quoC);
        switch(remrem) {
        case 8:
            gf2x_mul_8_avx( buffer, A, B+remC-remrem );
            break;
        case 7:
            gf2x_mul_7_avx( buffer, A, B+remC-remrem );
            break;
        case 6:
            gf2x_mul_6_avx( buffer, A, B+remC-remrem );
            break;
        case 5:
            gf2x_mul_5_avx( buffer, A, B+remC-remrem );
            break;
        case 4:
            gf2x_mul_4_avx( buffer, A, B+remC-remrem );
            break;
        case 3:
            gf2x_mul_3_avx( buffer, A, B+remC-remrem );
            break;
        case 2:
            gf2x_mul_2_avx( buffer, A, B+remC-remrem );
            break;
        case 1:
            gf2x_mul_1_avx( buffer, A, B+remC-remrem );
            break;
        case 0: ;/* do nothing */
        }
        gf2x_add(2*remrem, Res+(nr - offset - 2*remrem),
                 2*remrem, buffer,
                 2*remrem, Res+(nr - offset - 2*remrem));
        offset = offset + remrem;
        /* the remaining remrem uint64_ts of A are multiplied by the remC - remrem leading of  B*/
        for (int k = 0; k < remC - remrem; k++) { /* uint64_t index in B */
            for (int l = 0; l < remrem ; l++) {
                gf2x_mul_1_avx(buffer, A+(remrem-1)-l, B+(remC - remrem -1)-k);
                gf2x_add(2, Res+(nr - offset - 2 - (l+k)),
                         2, buffer,
                         2, Res+(nr - offset - 2 - (l+k)));
            }
        }
    }
}
/*----------------------------------------------------------------------------*/
#else

void gf2x_mul_comb(const int nr, DIGIT Res[],
                   const int na, const DIGIT A[],
                   const int nb, const DIGIT B[]) {
    int i, j, k;
    DIGIT u, h;

    memset(Res, 0x00, nr*sizeof(DIGIT));

    for (k = DIGIT_SIZE_b-1; k > 0; k--) {
        for (i = na-1; i >= 0; i--)
            if ( A[i] & (((DIGIT)0x1) << k) )
                for (j = nb-1; j >= 0; j--) Res[i+j+1] ^= B[j];


        u = Res[na+nb-1];
        Res[na+nb-1] = u << 0x1;
        for (j = 1; j < na+nb; ++j) {
            h = u >> (DIGIT_SIZE_b-1);
            u = Res[na+nb-1-j];
            Res[na+nb-1-j] = h^(u << 0x1);
        }
    }
    for (i = na-1; i >= 0; i--)
        if ( A[i] & ((DIGIT)0x1) )
            for (j = nb-1; j >= 0; j--) Res[i+j+1] ^= B[j];
}
#endif

/*---------------------------------------------------------------------------*/
/* allows the second operand to be shorter than the first */
/* the result should be as large as the first operand*/
static inline void gf2x_add_asymm(const int nr, DIGIT Res[],
                                  const int na, const DIGIT A[],
                                  const int nb, const DIGIT B[]) {
    int delta = na-nb;
    memcpy(Res,A,delta*DIGIT_SIZE_B);
    gf2x_add(nb, Res+delta,
             nb, A+delta,
             nb, B);
} // end gf2x_mul_comb

/*---------------------------------------------------------------------------*/

void gf2x_mul_Kar(const int nr, DIGIT Res[],
                  const int na, const DIGIT A[],
                  const int nb, const DIGIT B[]) {

    if(na < MIN_KAR_DIGITS || nb < MIN_KAR_DIGITS) {
        /* fall back to schoolbook */
#if (defined HIGH_PERFORMANCE_X86_64) || (defined HIGH_COMPATIBILITY_X86_64)
        gf2x_mul_avx(nr, Res, na, A, nb, B);
#else
        gf2x_mul_comb(nr, Res, na, A, nb, B);
#endif
        return;
    }

    if(na %2 == 0) {
        unsigned bih = na/2;
        DIGIT middle[2*bih], sumA[bih], sumB[bih];
        gf2x_add(bih,sumA,
                 bih,A,
                 bih,A+bih);
        gf2x_add(bih,sumB,
                 bih,B,
                 bih,B+bih);
        gf2x_mul_Kar(2*bih, middle,
                     bih, sumA,
                     bih, sumB);
        gf2x_mul_Kar(2*bih, Res+2*bih,
                     bih, A+bih,
                     bih, B+bih);
        gf2x_add(2*bih, middle,
                 2*bih, middle,
                 2*bih, Res+2*bih);
        gf2x_mul_Kar(2*bih, Res,
                     bih, A,
                     bih, B);
        gf2x_add(2*bih, middle,
                 2*bih, middle,
                 2*bih, Res);
        gf2x_add(2*bih, Res+bih,
                 2*bih, Res+bih,
                 2*bih, middle);
    } else {
        unsigned bih = na/2 + 1;
        DIGIT middle[2*bih], sumA[bih], sumB[bih];
        gf2x_add_asymm(bih,  sumA,
                       bih,  A+bih-1,
                       bih-1,A);
        gf2x_add_asymm(bih,  sumB,
                       bih,  B+bih-1,
                       bih-1,B);
        gf2x_mul_Kar(2*bih, middle,
                     bih, sumA,
                     bih, sumB);
        gf2x_mul_Kar(2*bih, Res+2*(bih-1),
                     bih, A+bih-1,
                     bih, B+bih-1);
        gf2x_add(2*bih, middle,
                 2*bih, middle,
                 2*bih, Res+2*(bih-1));
        gf2x_mul_Kar(2*(bih-1), Res,
                     (bih-1), A,
                     (bih-1), B);
        gf2x_add_asymm(2*bih, middle,
                       2*bih, middle,
                       2*(bih-1), Res);
        gf2x_add(2*bih, Res+bih-2,
                 2*bih, Res+bih-2,
                 2*bih, middle);
    }
}

/*----------------------------------------------------------------------------*/
#if (defined HIGH_PERFORMANCE_X86_64) || (defined HIGH_COMPATIBILITY_X86_64)
static inline void gf2x_exact_div_x_plus_one(const int na, DIGIT A[]) {
    DIGIT t = 0;
    int i;
    __m256i vec_t = _mm256_set_epi64x(0,0,0,0), tmp;
    for (i = na - 4; i >= 0; i=i-4) {
//  translation of  t ^= A[i];
        tmp = _mm256_lddqu_si256((__m256i*) (A+i));
        vec_t = _mm256_xor_si256(tmp,vec_t);
        for (int j = 1; j <= DIGIT_SIZE_b / 2; j = j * 2) {
//   translation of t ^= t << (unsigned) j;
            tmp = _mm256_slli_epi64(vec_t, j);
            vec_t = _mm256_xor_si256(tmp,vec_t);
        }

        DIGIT hicarry = 0, locarry =0;
        t = _mm256_extract_epi64 (vec_t, 3);
        t >>= DIGIT_SIZE_b - 1;
        locarry -= t;
        t = _mm256_extract_epi64 (vec_t, 1);
        t >>= DIGIT_SIZE_b - 1;
        hicarry -= t;
        tmp = _mm256_set_epi64x(0,locarry,0,hicarry);
        vec_t = _mm256_xor_si256(tmp,vec_t);

        t = _mm256_extract_epi64 (vec_t, 2);
        t >>= DIGIT_SIZE_b - 1;
        hicarry = (DIGIT)0 - t;
        tmp = _mm256_set_epi64x(0,0,hicarry,hicarry);
        vec_t = _mm256_xor_si256(tmp,vec_t);
// translation of =   A[i] = t;
        _mm256_storeu_si256( (__m256i *) (A+i),vec_t);
        t = _mm256_extract_epi64 (vec_t, 0);
        t >>= DIGIT_SIZE_b - 1;
        vec_t = _mm256_set_epi64x(t,0,0,0);
    }
    i = i >= -3 ? i+3 : i;
    for (; i >= 0; i--) {

        t ^= A[i];

        for (int j = 1; j <= DIGIT_SIZE_b / 2; j = j * 2) {
            t ^= t << (unsigned) j;
        }
        A[i] = t;
        t >>= DIGIT_SIZE_b - 1;
    }
} // end gf2x_exact_div_x_plus_one
#else
static inline void gf2x_exact_div_x_plus_one(const int na, DIGIT A[]) {
    DIGIT t = 0;
    for (int i = na - 1; i >= 0; i--) {

        t ^= A[i];

        for (int j = 1; j <= DIGIT_SIZE_b / 2; j = j * 2) {
            t ^= t << (unsigned) j;
        }

        A[i] = t;
        t >>= DIGIT_SIZE_b - 1;
    }
} // end gf2x_exact_div_x_plus_one
#endif


/*---------------------------------------------------------------------------*/
/* Toom-Cook 3 algorithm as reported in
 * Marco Bodrato: "Towards Optimal Toom-Cook Multiplication for Univariate and
 * Multivariate Polynomials in Characteristic 2 and 0". WAIFI 2007: 116-133   */

void gf2x_mul_TC3(const int nr, DIGIT Res[],
                  const int na, const DIGIT A[],
                  const int nb, const DIGIT B[]) {

    if(na < MIN_TOOM_DIGITS || nb < MIN_TOOM_DIGITS) {
        /* fall back to schoolbook */
        gf2x_mul_Kar(nr, Res, na, A, nb, B);
        return;
    }

    unsigned bih; //number of limbs for each part.
    if (na % 3 == 0) {
        bih = na / 3;
    } else {
        bih = na / 3 + 1;
    }

    DIGIT u2[bih], *u1, *u0;

    int leading_slack = (3 - (na) % 3) %3;
//     printf("leading slack %d",leading_slack);
    int i;
    for(i = 0; i < leading_slack ; i++) {
        u2[i] = 0;
    }
    for (; i < bih; ++i) {
        u2[i] = A[i-leading_slack];
    }
    u1= (DIGIT *) (A+bih-leading_slack);
    u0= (DIGIT *) (A+2*bih-leading_slack);

    DIGIT v2[bih], *v1, *v0; /* partitioned inputs */
    for(i = 0; i < leading_slack ; i++) {
        v2[i] = 0;
    }
    for (; i < bih; ++i) {
        v2[i] = B[i-leading_slack];
    }
    v1=(DIGIT *) (B+bih-leading_slack);
    v0=(DIGIT *) (B+2*bih-leading_slack);

    DIGIT sum_u[bih]; /*bih digit wide*/
    gf2x_add(bih, sum_u,
             bih, u0,
             bih, u1);
    gf2x_add(bih, sum_u,
             bih, sum_u,
             bih, u2);

    DIGIT sum_v[bih]; /*bih digit wide*/
    gf2x_add(bih, sum_v,
             bih, v0,
             bih, v1);
    gf2x_add(bih, sum_v,
             bih, sum_v,
             bih, v2);

    DIGIT w1[2*bih];
    gf2x_mul_TC3(2*bih, w1,
                 bih, sum_u,
                 bih, sum_v);

    DIGIT u2_x2[bih + 1];
    u2_x2[0] = 0;
    memcpy(u2_x2+1,u2,bih*DIGIT_SIZE_B);
    left_bit_shift_n(bih+1, u2_x2, 2);

    DIGIT u1_x[bih + 1];
    u1_x[0] = 0;
    memcpy(u1_x+1,u1,bih*DIGIT_SIZE_B);
    left_bit_shift_n(bih+1, u1_x, 1);

    DIGIT u1_x1_u2_x2[bih + 1];
    gf2x_add(bih+1, u1_x1_u2_x2,
             bih+1, u1_x,
             bih+1, u2_x2);

    DIGIT temp_u_components[bih + 1];
    gf2x_add_asymm(bih+1, temp_u_components,
                   bih+1, u1_x1_u2_x2,
                   bih, sum_u);

    DIGIT v2_x2[bih + 1];
    v2_x2[0] = 0;
    memcpy(v2_x2+1,v2,bih*DIGIT_SIZE_B);
    left_bit_shift_n(bih+1, v2_x2, 2);

    DIGIT v1_x[bih + 1];
    v1_x[0] = 0;
    memcpy(v1_x+1,v1,bih*DIGIT_SIZE_B);
    left_bit_shift_n(bih+1, v1_x, 1);

    DIGIT v1_x1_v2_x2[bih + 1];
    gf2x_add(bih+1, v1_x1_v2_x2,
             bih+1, v1_x,
             bih+1, v2_x2);

    DIGIT temp_v_components[bih + 1];
    gf2x_add_asymm(bih+1, temp_v_components,
                   bih+1, v1_x1_v2_x2,
                   bih, sum_v);

    DIGIT w3[2*bih+2];
    gf2x_mul_TC3(2*bih+2, w3,
                 bih+1, temp_u_components,
                 bih+1, temp_v_components);

    gf2x_add_asymm(bih+1, u1_x1_u2_x2,
                   bih+1, u1_x1_u2_x2,
                   bih, u0);
    gf2x_add_asymm(bih+1, v1_x1_v2_x2,
                   bih+1, v1_x1_v2_x2,
                   bih, v0);

    DIGIT w2[2*bih+2];
    gf2x_mul_TC3(2*bih+2, w2,
                 bih+1, u1_x1_u2_x2,
                 bih+1, v1_x1_v2_x2);

    DIGIT w4[2*bih];
    gf2x_mul_TC3(2*bih, w4,
                 bih, u2,
                 bih, v2);
    DIGIT w0[2*bih];
    gf2x_mul_TC3(2*bih, w0,
                 bih, u0,
                 bih, v0);

    // Interpolation starts
    gf2x_add(2*bih+2, w3,
             2*bih+2, w2,
             2*bih+2, w3);
    gf2x_add_asymm(2*bih+2, w2,
                   2*bih+2, w2,
                   2*bih, w0);
    right_bit_shift_n(2*bih+2, w2, 1);
    gf2x_add(2*bih+2, w2,
             2*bih+2, w2,
             2*bih+2, w3);

    // w2 + (w4 * x^3+1) = w2 + w4 + w4 << 3
    DIGIT w4_x3_plus_1[2*bih+1];
    w4_x3_plus_1[0] = 0;
    memcpy(w4_x3_plus_1+1,w4,2*bih*DIGIT_SIZE_B);
    left_bit_shift_n(2*bih+1, w4_x3_plus_1, 3);
    gf2x_add_asymm(2*bih+2, w2,
                   2*bih+2, w2,
                   2*bih, w4);
    gf2x_add_asymm(2*bih+2, w2,
                   2*bih+2, w2,
                   2*bih+1, w4_x3_plus_1);

    gf2x_exact_div_x_plus_one(2*bih+2, w2);

    gf2x_add(2*bih, w1,
             2*bih, w1,
             2*bih, w0);
    gf2x_add_asymm(2*bih+2, w3,
                   2*bih+2, w3,
                   2*bih, w1);

    right_bit_shift_n(2*bih+2, w3, 1);
    gf2x_exact_div_x_plus_one(2*bih+2, w3);

    gf2x_add(2*bih, w1,
             2*bih, w1,
             2*bih, w4);

    DIGIT w1_final[2*bih+2];
    gf2x_add_asymm(2*bih+2, w1_final,
                   2*bih+2, w2,
                   2*bih, w1);
    gf2x_add(2*bih+2, w2,
             2*bih+2, w2,
             2*bih+2, w3);

    // Result recombination starts here

    memset(Res,0,nr*DIGIT_SIZE_B);
    /* optimization: topmost slack digits should be computed, and not addedd,
     * zeroization can be avoided altogether with a proper merge of the
     * results */

    int leastSignifDigitIdx = nr - 1;
    for (int i = 0; i< 2*bih; i++) {
        Res[leastSignifDigitIdx - i] ^= w0[2*bih   - 1 - i];
    }
    leastSignifDigitIdx -= bih;
    for (int i = 0; i< 2*bih+2; i++) {
        Res[leastSignifDigitIdx - i] ^= w1_final[2*bih+2   - 1 - i];
    }
    leastSignifDigitIdx -= bih;
    for (int i = 0; i< 2*bih+2; i++) {
        Res[leastSignifDigitIdx - i] ^= w2[2*bih+2 - 1 - i];
    }
    leastSignifDigitIdx -= bih;
    for (int i = 0; i< 2*bih+2 ; i++) {
        Res[leastSignifDigitIdx - i] ^= w3[2*bih+2 - 1 - i];
    }
    leastSignifDigitIdx -= bih;
    for (int i = 0; i< 2*bih && (leastSignifDigitIdx - i >= 0) ; i++) {
        Res[leastSignifDigitIdx - i] ^= w4[2*bih   - 1 - i];
    }
}
