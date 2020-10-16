/**
 *
 * @author Alessandro Barenghi <alessandro.barenghi@polimi.it>
 * @author Gerardo Pelosi <gerardo.pelosi@polimi.it>
 * @author Domenico Cacace <domenico.cacace@mail.polimi.it>
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

inline static int countZeros(int dim, DIGIT *p0, DIGIT *p1) {
    int i;
    for(i = 0; i < dim; ++i) {
        if((p0[i] | p1[i]) != 0)
            break;
    }
    return i;
}

int skipped = 0;
void gf2x_scalarprod(int nr, DIGIT Res[],
                     int na, DIGIT a0[], DIGIT a1[],
                     int nb, DIGIT b0[], DIGIT b1[]) {
    
    int skip_a = countZeros(na, a0, a1);
    int skip_b = countZeros(nb, b0, b1);


    int dig_a = na - skip_a;
    int dig_b = nb - skip_b;
    int dig_res = dig_a + dig_b;

    if(dig_a == dig_b) {
        DIGIT tmp[dig_res];
        GF2X_MUL(dig_res, Res, dig_a, a0+skip_a, dig_b, b0+skip_b);
        GF2X_MUL(dig_res, tmp, dig_a, a1+skip_a, dig_b, b1+skip_b);
        gf2x_add(dig_res, tmp, dig_res, Res, dig_res, tmp);
        memset(Res, 0x00, (nr - dig_res)*DIGIT_SIZE_B);
        memcpy(Res+(nr-dig_res), tmp, dig_res*DIGIT_SIZE_B);
    }/*
    else if(dig_a > dig_b) {
        dig_res = 2*dig_a;
        DIGIT tmp[dig_res], tmp2[dig_res];

        DIGIT bufb[dig_a];
        memset(bufb,0x00,(dig_a-dig_b)*DIGIT_SIZE_B);

        memcpy(bufb+(dig_a-dig_b), b0+skip_b, dig_b*DIGIT_SIZE_B);
        GF2X_MUL(dig_res,tmp, dig_a, a0+skip_a, dig_a,bufb);


        memset(bufb,0x00,(dig_a-dig_b)*DIGIT_SIZE_B);

        memcpy(bufb+(dig_a-dig_b),b1+skip_b,dig_b*DIGIT_SIZE_B);
        GF2X_MUL(dig_res,tmp2, dig_a, a1+skip_a, dig_a,bufb);

        gf2x_add(dig_res, tmp, dig_res, tmp2, dig_res, tmp);
        memset(Res, 0x00, (nr-dig_res)*DIGIT_SIZE_B);
        memcpy(Res+(nr-dig_res), tmp+(dig_a-dig_b), (dig_res)*DIGIT_SIZE_B);
    }*/
  /*  else
    {
        dig_res = 2*dig_b;
        DIGIT tmp[dig_res], tmp2[dig_res];

        DIGIT bufa[dig_b];
        memset(bufa,0x00,(dig_b-dig_a)*DIGIT_SIZE_B);

        memcpy(bufa+(dig_b-dig_a), a0+skip_a, dig_a*DIGIT_SIZE_B);
        GF2X_MUL(dig_res,tmp, dig_b,bufa, dig_b, b0+skip_b);

        memset(bufa,0x00,(dig_b-dig_a)*DIGIT_SIZE_B);

        memcpy(bufa+(dig_b-dig_a),a1+skip_a,dig_a*DIGIT_SIZE_B);
        GF2X_MUL(dig_res, tmp2, dig_b, bufa, dig_b, b1+skip_b);

        gf2x_add(dig_res, tmp, dig_res, tmp2, dig_res, tmp);
        memset(Res, 0x00, (nr-dig_res)*DIGIT_SIZE_B);
        memcpy(Res+(nr-dig_res), tmp+dig_res-(dig_a+dig_b), (dig_a+dig_b)*DIGIT_SIZE_B);
    }*/
/*
    DIGIT tmp[2*op_dim];
    GF2X_MUL(2*op_dim, Res, op_dim, a0+(na - op_dim), op_dim, b0+(nb - op_dim));
    GF2X_MUL(2*op_dim, tmp, op_dim, a1+(na - op_dim), op_dim, b1+(nb - op_dim));
    gf2x_add(2*op_dim, tmp, 2*op_dim, Res, 2*op_dim, tmp);
    memset(Res, 0x00, (nr - 2*op_dim)*DIGIT_SIZE_B);  
    print_pol(tmp, "RES", 2*op_dim); 
    memcpy(Res+(nr - 2*op_dim), tmp, 2*op_dim*DIGIT_SIZE_B);
*/
    

    /*
       if(na == nb) {
        DIGIT tmp[nr];
        GF2X_MUL(nr,Res, na,a0, nb,b0);
        GF2X_MUL(nr,tmp, na,a1, nb,b1);
        gf2x_add(nr, Res, nr, tmp, nr, Res);
    } */
    else if (na > nb) {
        DIGIT   tmp[na*2];

        DIGIT  bufb[na];
        memset(bufb,0x00,(na-nb)*DIGIT_SIZE_B);
        memcpy(bufb+(na-nb),b0,nb*DIGIT_SIZE_B);
        GF2X_MUL(na*2,tmp, na,a0, na,bufb);

        DIGIT  tmp2[na*2];

        memset(bufb,0x00,(na-nb)*DIGIT_SIZE_B);
        memcpy(bufb+(na-nb),b1,nb*DIGIT_SIZE_B);

        GF2X_MUL(na*2,tmp2, na,a1, na,bufb);
        gf2x_add(na*2, tmp2, na*2, tmp, na*2, tmp2);

        memcpy(Res,tmp2+(na-nb),nr*DIGIT_SIZE_B);
    } 
    else { //nb > na
        DIGIT   tmp[nb*2];

        DIGIT  bufa[nb];
        memset(bufa,0x00,(nb-na)*DIGIT_SIZE_B);
        memcpy(bufa+(nb-na),a0,na*DIGIT_SIZE_B);
        GF2X_MUL(nb*2,tmp, nb, bufa, nb,b0);

        DIGIT  tmp2[nb*2];

        memset(bufa,0x00,(nb-na)*DIGIT_SIZE_B);
        memcpy(bufa+(nb-na),a1,na*DIGIT_SIZE_B);

        GF2X_MUL(nb*2,tmp2, nb,bufa, nb,b1);

        gf2x_add(nb*2, tmp2, nb*2, tmp, nb*2, tmp2);
        memcpy(Res,tmp2+(nb*2-(nb+na)),(na+nb)*DIGIT_SIZE_B);
    }
}

#if (defined HIGH_COMPATIBILITY_X86_64)
static inline
__m128i right_shift_128(__m128i in) {

    __m128i a,b;
    a = _mm_srli_epi64(in,1);
    b = _mm_slli_epi64(in,DIGIT_SIZE_b-1);

    //set the high part of b = 0
    b = _mm_unpacklo_epi64( _mm_setzero_si128(),b ); //o _mm_unpacklo_epi64???
    a = _mm_or_si128(a,b);

    return a;
}
#endif

#if (defined HIGH_PERFORMANCE_X86_64)
static inline
__m256i right_shift_256(__m256i in) {

    __m256i a,b,c;
    a = _mm256_srli_epi64(in,1);

    b = _mm256_slli_epi64(in,DIGIT_SIZE_b-1);

    c = _mm256_permute4x64_epi64(b,0x93);
    c = _mm256_insert_epi64(c, (DIGIT) 0, 0);

    a = _mm256_or_si256(a,c);

    return a;
}
#endif

/*************************************************************************/

#define CTIME_IF(mask,then,else)  ((mask&(then)) | (~mask&(else) ))

#define SIGNED_DIGIT int64_t
int divstepsx(int n,
              int delta,
              DIGIT f64, DIGIT g64,
              DIGIT * p00, DIGIT * p01,
              DIGIT * p10, DIGIT * p11) {
    DIGIT u, v, q, r;

    DIGIT g0, f0;

    u = ((DIGIT) 1) << n;
    v = 0;
    q = 0;
    r = ((DIGIT) 1) << n;
    DIGIT tmp,tmp2;

    while (n > 0) {
        SIGNED_DIGIT swap_mask = ((delta > 0) & ((g64 & 1) != 0));
        swap_mask = (swap_mask << (DIGIT_SIZE_b-1)) >> (DIGIT_SIZE_b-1);
        delta = CTIME_IF(swap_mask,-delta,delta);
        tmp  = CTIME_IF(swap_mask,g64,f64);
        tmp2 = CTIME_IF(swap_mask,f64,g64);
        f64  = tmp;
        g64  = tmp2;

        tmp  = CTIME_IF(swap_mask,q,u);
        tmp2 = CTIME_IF(swap_mask,u,q);
        u  = tmp;
        q  = tmp2;

        tmp  = CTIME_IF(swap_mask,r,v);
        tmp2 = CTIME_IF(swap_mask,v,r);
        v  = tmp;
        r  = tmp2;

        delta++;
        g0 = (DIGIT)0 - (g64 & (DIGIT) 0x1);
        f0 = (DIGIT)0 - (f64 & (DIGIT) 0x1);

        q =   (f0 & q) ^ (g0 & u);
        r =   (f0 & r) ^ (g0 & v);
        g64 = (f0 & g64) ^ (g0 & f64);
        g64 >>= 1;
        q >>= 1;
        r >>= 1;
        n--;
    } //end while
    *p00 = u;
    *p01 = v;
    *p10 = q;
    *p11 = r;

    return delta;
}

#if (defined HIGH_COMPATIBILITY_X86_64)

#define CTIME_IF_128(mask,then,else)  _mm_or_si128(_mm_and_si128(mask, then) ,_mm_andnot_si128(mask, else))
int divstepsx_128(int n,
                  int delta,
                  DIGIT f[], DIGIT g[],
                  DIGIT * p00, DIGIT * p01,
                  DIGIT * p10, DIGIT * p11) {

    if(n<64) {
        return delta = divstepsx (n,
                                  delta,
                                  f[0],
                                  g[0],
                                  p00, p01,
                                  p10, p11);
    }
    __m128i g0, f0, g128, f128;
    __m128i one_128 = _mm_set_epi64x((DIGIT) 1, (DIGIT) 0);
    __m128i mask_128 = _mm_set_epi64x((DIGIT) 1, (DIGIT) 1);
    __m128i zero_128 = _mm_setzero_si128();

    __m128i u, v, q, r;

    g128 = _mm_lddqu_si128((__m128i *)g);
    f128 = _mm_lddqu_si128((__m128i *)f);

    DIGIT  temp = ((DIGIT) 1)<< (n-64);
    u = _mm_set_epi64x( (DIGIT) 0, temp);
    r = _mm_set_epi64x( (DIGIT) 0, temp);
    v = _mm_setzero_si128();
    q = _mm_setzero_si128();

    __m128i delta_128 = _mm_set_epi64x((SIGNED_DIGIT) delta,(SIGNED_DIGIT) delta);

    __m128i tmp,tmp2;

    while (n > 0) {
        __m128i delta_mask = _mm_cmpgt_epi64(delta_128, zero_128);

        //something like [xxx....xxx | FFF....FFF] where x is the actual mask
        __m128i g128_mask = _mm_cmpeq_epi64(_mm_and_si128(g128, one_128), one_128);

        __m128i swap_mask = _mm_and_si128(delta_mask, (__m128i)_mm_shuffle_pd((__m128d) g128_mask, (__m128d) g128_mask, 3));


        delta_128 = _mm_add_epi64(_mm_xor_si128(delta_128, swap_mask), _mm_and_si128(mask_128, swap_mask));

        // delta = CTIME_IF(swap,-delta,delta);
        tmp  = CTIME_IF_128(swap_mask,g128,f128);
        tmp2 = CTIME_IF_128(swap_mask,f128,g128);


        f128  = tmp;
        g128  = tmp2;

        tmp  = CTIME_IF_128(swap_mask,q,u);
        tmp2 = CTIME_IF_128(swap_mask,u,q);


        u  = tmp;
        q  = tmp2;

        tmp  = CTIME_IF_128(swap_mask,r,v);
        tmp2 = CTIME_IF_128(swap_mask,v,r);

        v  = tmp;
        r  = tmp2;

        //delta++;
        delta_128 = _mm_add_epi64(delta_128, mask_128);

        g0 = _mm_cmpeq_epi64(_mm_and_si128(g128, one_128), one_128);
        g0 = (__m128i)_mm_shuffle_pd((__m128d) g0, (__m128d) g0, 3);

        f0 = _mm_cmpeq_epi64(_mm_and_si128(f128, one_128), one_128);
        f0 = (__m128i)_mm_shuffle_pd((__m128d) f0, (__m128d) f0, 3);

        q =   _mm_xor_si128(_mm_and_si128(f0,q), _mm_and_si128(g0,u)); //(f0 & q) ^ (g0 & u);
        r =   _mm_xor_si128(_mm_and_si128(f0,r), _mm_and_si128(g0,v)); //(f0 & r) ^ (g0 & v);
        g128 = _mm_xor_si128(_mm_and_si128(f0,g128), _mm_and_si128(g0,f128)); //(f0 & g64) ^ (g0 & f64);

        g128 = right_shift_128(g128);
        q = right_shift_128(q);
        r = right_shift_128(r);
        n--;
    } //end while

    _mm_storeu_si128((__m128i *) p00, u);
    _mm_storeu_si128((__m128i *) p01, v);
    _mm_storeu_si128((__m128i *) p10, q);
    _mm_storeu_si128((__m128i *) p11, r);

    return _mm_cvtsi128_si64x(delta_128);//_mm_extract_epi64(delta_128,1);
}
#endif

#if (defined HIGH_PERFORMANCE_X86_64)

#define CTIME_IF_256(mask,then,else)  _mm256_blendv_epi8(else, then, mask)
int divstepsx_256(int n,
                  int delta,
                  DIGIT f[], DIGIT g[],
                  DIGIT * p00, DIGIT * p01,
                  DIGIT * p10, DIGIT * p11) {
    if(n<128) {
        return delta = divstepsx_128 (n,delta,
                                      f,
                                      g,
                                      p00, p01,
                                      p10, p11);
    }
    __m256i g0, f0, g256, f256;
    __m256i one_256 = _mm256_set_epi64x((DIGIT) 1, (DIGIT) 0,(DIGIT) 0, (DIGIT) 0);
    __m256i mask_256 = _mm256_set_epi64x((DIGIT) 1, (DIGIT) 1,(DIGIT) 1, (DIGIT) 1);
    __m256i zero_256 = _mm256_setzero_si256();


    __m256i u, v, q, r;

    g256 = _mm256_lddqu_si256((__m256i *)g);
    f256 = _mm256_lddqu_si256((__m256i *)f);

    DIGIT  temp = ((DIGIT) 1)<< (n-192);
    u = _mm256_set_epi64x( (DIGIT) 0, (DIGIT) 0, (DIGIT) 0, temp);
    r = _mm256_set_epi64x( (DIGIT) 0, (DIGIT) 0, (DIGIT) 0, temp);
    v = _mm256_setzero_si256();
    q = _mm256_setzero_si256();

    __m256i delta_256 = _mm256_set_epi64x((SIGNED_DIGIT) delta,(SIGNED_DIGIT) delta, (SIGNED_DIGIT) delta,(SIGNED_DIGIT) delta);

    __m256i tmp,tmp2;

    while (n > 0) {
        __m256i delta_mask = _mm256_cmpgt_epi64(delta_256, zero_256);
        __m256i g256_mask = _mm256_cmpeq_epi64(_mm256_and_si256(g256, one_256), one_256);

        __m256i swap_mask = _mm256_and_si256(delta_mask, _mm256_permute4x64_epi64(g256_mask, 0xFF));


        //need to add 1 when changing sign with the xor
        delta_256 = _mm256_add_epi64(_mm256_xor_si256(delta_256, swap_mask), _mm256_and_si256(mask_256, swap_mask));
        tmp  = CTIME_IF_256(swap_mask,g256,f256);
        tmp2 = CTIME_IF_256(swap_mask,f256,g256);

        f256  = tmp;
        g256  = tmp2;

        tmp  = CTIME_IF_256(swap_mask,q,u);
        tmp2 = CTIME_IF_256(swap_mask,u,q);


        u  = tmp;
        q  = tmp2;

        tmp  = CTIME_IF_256(swap_mask,r,v);
        tmp2 = CTIME_IF_256(swap_mask,v,r);

        v  = tmp;
        r  = tmp2;

        delta_256 = _mm256_add_epi64(delta_256, mask_256);

        __m256i maskgf_tmp = _mm256_cmpeq_epi64(_mm256_and_si256(g256, one_256), one_256);
        g0 = _mm256_permute4x64_epi64(maskgf_tmp, 0xFF);

        maskgf_tmp = _mm256_cmpeq_epi64(_mm256_and_si256(f256, one_256), one_256);
        f0 = _mm256_permute4x64_epi64(maskgf_tmp, 0xFF);

        q =   _mm256_xor_si256(_mm256_and_si256(f0,q), _mm256_and_si256(g0,u));
        r =   _mm256_xor_si256(_mm256_and_si256(f0,r), _mm256_and_si256(g0,v));
        g256 = _mm256_xor_si256(_mm256_and_si256(f0,g256), _mm256_and_si256(g0,f256));

        g256 = right_shift_256(g256);
        q = right_shift_256(q);
        r = right_shift_256(r);
        n--;

    } //end while

    _mm256_storeu_si256((__m256i *) p00, u);
    _mm256_storeu_si256((__m256i *) p01, v);
    _mm256_storeu_si256((__m256i *) p10, q);
    _mm256_storeu_si256((__m256i *) p11, r);

    return _mm256_extract_epi64(delta_256, 0);
}
#endif

#if (defined HIGH_PERFORMANCE_X86_64)

int support_jumpdivstep(int n, int delta,
                        int nf, DIGIT   f[], DIGIT g[],
                        DIGIT t00[], DIGIT t01[],
                        DIGIT t10[], DIGIT t11[], float x)
{
    if (n < 128) {

        return delta = divstepsx_128(n, delta,
                                     f,
                                     g,
                                     t00, t01,
                                     t10, t11);

    }

    /* round the cutting point to a digit limit */
    int j = n*x;
    j = (j+128-2)/(128-1);
    j = j * (128-1);

    int num_digits_j       = (j/DIGIT_SIZE_b)+1; /* (j+DIGIT_SIZE_b-1)/DIGIT_SIZE_b */

    DIGIT p_00[num_digits_j],p_01[num_digits_j],
            p_10[num_digits_j],p_11[num_digits_j];

    delta = support_jumpdivstep(j, delta, num_digits_j,
                                f+(nf-num_digits_j),
                                g+(nf-num_digits_j),
                                p_00, p_01, p_10, p_11, x);

    /* note: entire f and g must be matrixmultiplied! use the ones from above */
    DIGIT f_sum[num_digits_j+nf];
    DIGIT g_sum[num_digits_j+nf];

    gf2x_scalarprod(num_digits_j+nf, f_sum,
                    num_digits_j,    p_00, p_01,
                    nf,                    f, g);

    gf2x_scalarprod(num_digits_j+nf, g_sum,
                    num_digits_j,    p_10, p_11,
                    nf,                    f, g);

    right_bit_shift_wide_n(num_digits_j+nf, f_sum, j);
    right_bit_shift_wide_n(num_digits_j+nf, g_sum, j);

    /* truncate to n-j degree, i.e. to n-j bits from the bottom */
    int num_digits_nminusj = (n-j)/DIGIT_SIZE_b+1;

    DIGIT  q_00[num_digits_nminusj],
            q_01[num_digits_nminusj],
            q_10[num_digits_nminusj],
            q_11[num_digits_nminusj];

    delta = support_jumpdivstep(n - j, delta,
                                num_digits_nminusj,
                                f_sum + (num_digits_j+nf - num_digits_nminusj),
                                g_sum + (num_digits_j+nf - num_digits_nminusj),
                                q_00, q_01, q_10, q_11, x);

    DIGIT large_tmp[num_digits_j+num_digits_nminusj];

    gf2x_scalarprod(num_digits_j+num_digits_nminusj, large_tmp,
                    num_digits_j,                    p_00, p_10,
                    num_digits_nminusj,                    q_00, q_01);
    memcpy(t00,
           large_tmp+(num_digits_j+num_digits_nminusj-nf),
           (nf)*DIGIT_SIZE_B);

    gf2x_scalarprod(num_digits_j+num_digits_nminusj, large_tmp,
                    num_digits_j,                    p_01, p_11,
                    num_digits_nminusj,                    q_00, q_01);
    memcpy(t01,
           large_tmp+(num_digits_j+num_digits_nminusj-nf),
           (nf)*DIGIT_SIZE_B);

    gf2x_scalarprod(num_digits_j+num_digits_nminusj, large_tmp,
                    num_digits_j,                    p_00, p_10,
                    num_digits_nminusj,                    q_10, q_11);
    memcpy(t10,
           large_tmp+(num_digits_j+num_digits_nminusj-nf),
           (nf)*DIGIT_SIZE_B);

    gf2x_scalarprod(num_digits_j+num_digits_nminusj, large_tmp,
                    num_digits_j,                    p_01, p_11,
                    num_digits_nminusj,                    q_10, q_11);
    memcpy(t11,
           large_tmp+(num_digits_j+num_digits_nminusj-nf),
           (nf)*DIGIT_SIZE_B);

    return delta;
}
#endif


#include <math.h>   //log2, might use a more efficient function (?)
typedef struct stk {
    int n;
    int j;

    DIGIT *f;
    DIGIT *g;

    DIGIT *t00;
    DIGIT *t01;
    DIGIT *t10;
    DIGIT *t11;

    int visits;
} stk;

static inline void assignT(struct stk *stack, DIGIT *T00, DIGIT *T01, DIGIT *T10, DIGIT *T11) {
    stack->t00 = T00;
    stack->t01 = T01;
    stack->t10 = T10;
    stack->t11 = T11;
}

static inline int machineWordSize() {
    #if (defined HIGH_PERFORMANCE_X86_64)
        return 256;
    #elif (defined HIGH_COMPATIBILITY_X86_64)
        return 128;   
    #endif
        
    return DIGIT_SIZE_b;
}

static inline int countSkippable(int dim, DIGIT *a, DIGIT *b) {
    int i = 0;
    for(i = 0; i < dim; i++) {
        if((a[i] | b[i]) != 0)
            break;
    }
    return i;
}
void printStackInfo(struct stk *stack, DIGIT *p00, DIGIT *p01, DIGIT *p10, DIGIT *p11, DIGIT *q00, DIGIT *q01, DIGIT *q10, DIGIT *q11) {
    int num_digits_n = stack->n / DIGIT_SIZE_B + 1;
    int num_digits_j = stack->j / DIGIT_SIZE_b + 1;
    int num_digits_nminusj = (stack->n - stack->j) / DIGIT_SIZE_b + 1;

    print_pol(p00, "p00", num_digits_j);
    print_pol(p01, "p01", num_digits_j);
    print_pol(p10, "p10", num_digits_j);
    print_pol(p11, "p11", num_digits_j);
    print_pol(q00, "q00", num_digits_nminusj);
    print_pol(q01, "q01", num_digits_nminusj);
    print_pol(q10, "q10", num_digits_nminusj);
    print_pol(q11, "q11", num_digits_nminusj);
    print_pol(stack->t00, "t00", num_digits_n);
    print_pol(stack->t01, "t01", num_digits_n);
    print_pol(stack->t10, "t10", num_digits_n);
    print_pol(stack->t11, "t11", num_digits_n);

}
int acc = 0;
int jumpdivstep(int n_in, int delta,
                int nf, DIGIT   f_in[], DIGIT g_in[],
                DIGIT t00[], DIGIT t01[],
                DIGIT t10[], DIGIT t11[], float x) {


    // determining the machine word size


    int ws = machineWordSize();

    int layers = log2(n_in / ws) + 1;    // includes the root node

    register int n, j, num_digits_n, num_digits_j, num_digits_nminusj, sp;
    register DIGIT *p00, *p01, *p10, *p11;
    register DIGIT *q00, *q01, *q10, *q11;

    struct stk *stack = alloca((layers+2) * sizeof(struct stk));    // to be checked
    register struct stk *parent;
    register int skippable = 0;
    sp = 0;

    stack->n = n_in;
    j = n_in * x;
    j = (j + ws - 2) / (ws - 1);
    j = j * (ws - 1);
    stack->j = j;

    num_digits_n = nf;
    num_digits_j = j / DIGIT_SIZE_b + 1;
    num_digits_nminusj = (n_in - j) / DIGIT_SIZE_b + 1;

    const int psize = num_digits_j;
    const int qsize = num_digits_nminusj;

    DIGIT P00[psize * layers + 1];
    DIGIT P01[psize * layers + 1];
    DIGIT P10[psize * layers + 1];
    DIGIT P11[psize * layers + 1];

    DIGIT Q00[qsize * layers + 1];
    DIGIT Q01[qsize * layers + 1];
    DIGIT Q10[qsize * layers + 1];
    DIGIT Q11[qsize * layers + 1];

    DIGIT temp[psize + qsize];

    DIGIT f_sum[num_digits_n + num_digits_j];
    DIGIT g_sum[num_digits_n + num_digits_j];

    stack->f = f_in;
    stack->g = g_in;

    assignT(stack, t00, t01, t10, t11);

    stack->visits = 0;

    while (sp != 0 || stack->visits < 2) {

        switch (stack->visits) {
        case 0:
            stack->visits++;
            parent = stack;
            stack++;

            stack->n = parent->j;
            j = stack->n * x;
            j = (j + ws - 2) / (ws - 1);
            j = j * (ws - 1);
            stack->j = j;

            num_digits_n = parent->n / DIGIT_SIZE_b + 1;
            num_digits_j = parent->j / DIGIT_SIZE_b + 1;

            stack->f = parent->f + (num_digits_n - num_digits_j);
            stack->g = parent->g + (num_digits_n - num_digits_j);


            p00 = P00 + (psize * sp);
            p01 = P01 + (psize * sp);
            p10 = P10 + (psize * sp);
            p11 = P11 + (psize * sp);

            assignT(stack, p00, p01, p10, p11);
            

            sp++;
            stack->visits = 0;
            break;
        case 1:
            parent = stack;
            stack->visits++;
            stack++;

            n = parent->n - parent->j;
            j = n * x;
            j = (j + ws - 2) / (ws - 1);
            j = j * (ws - 1);

            stack->n = n;
            stack->j = j;

            n = parent->n;
            j = parent->j;
            num_digits_n = n / DIGIT_SIZE_b + 1;
            num_digits_j = j / DIGIT_SIZE_b + 1;
            num_digits_nminusj = (n - j) / DIGIT_SIZE_b + 1;

            p00 = P00 + (psize * sp);
            p01 = P01 + (psize * sp);
            p10 = P10 + (psize * sp);
            p11 = P11 + (psize * sp);

            q00 = Q00 + (qsize * sp);
            q01 = Q01 + (qsize * sp);
            q10 = Q10 + (qsize * sp);
            q11 = Q11 + (qsize * sp);

            gf2x_scalarprod(num_digits_j + num_digits_n, f_sum,
                            num_digits_j, p00, p01,
                            num_digits_n, parent->f, parent->g);

            gf2x_scalarprod(num_digits_j + num_digits_n, g_sum,
                            num_digits_j, p10, p11,
                            num_digits_n, parent->f, parent->g);

            right_bit_shift_wide_n(num_digits_j + num_digits_n, f_sum, j);
            right_bit_shift_wide_n(num_digits_j + num_digits_n, g_sum, j);

            //fsum, gsum
            stack->f = f_sum + (num_digits_j + num_digits_n - num_digits_nminusj);
            stack->g = g_sum + (num_digits_j + num_digits_n - num_digits_nminusj);

/*
            print_pol(p00, "p00", num_digits_j);
            print_pol(p01, "p01", num_digits_j);
            print_pol(stack->f, "  f", num_digits_n);
            printf("\n");*/


            sp++;
            assignT(stack, q00, q01, q10, q11);

            stack->visits = 0;
            break;
        case 2:
            num_digits_n = stack->n / DIGIT_SIZE_b + 1;
            num_digits_j = stack->j / DIGIT_SIZE_b + 1;
            num_digits_nminusj = (stack->n - stack->j) / DIGIT_SIZE_b + 1;

            p00 = P00 + (psize * sp);
            p01 = P01 + (psize * sp);
            p10 = P10 + (psize * sp);
            p11 = P11 + (psize * sp);

            q00 = Q00 + (qsize * sp);
            q01 = Q01 + (qsize * sp);
            q10 = Q10 + (qsize * sp);
            q11 = Q11 + (qsize * sp);
    

            gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                            num_digits_j,                      p00, p10,
                            num_digits_nminusj,                q00, q01);

            memcpy(stack->t00,
                   temp + (num_digits_j + num_digits_nminusj - num_digits_n),
                   num_digits_n * DIGIT_SIZE_B);

            gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                            num_digits_j,                      p01, p11,
                            num_digits_nminusj,                q00, q01);
            memcpy(stack->t01,
                   temp + (num_digits_j + num_digits_nminusj - num_digits_n),
                   num_digits_n * DIGIT_SIZE_B);

            gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                            num_digits_j,                      p00, p10,
                            num_digits_nminusj,                q10, q11);
            memcpy(stack->t10,
                   temp + (num_digits_j + num_digits_nminusj - num_digits_n),
                   num_digits_n * DIGIT_SIZE_B);

            gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                            num_digits_j,                      p01, p11,
                            num_digits_nminusj,                q10, q11);
            memcpy(stack->t11,
                   temp + (num_digits_j + num_digits_nminusj - num_digits_n),
                   num_digits_n * DIGIT_SIZE_B);

            //printStackInfo(stack, p00, p01, p10, p11, q00, q01, q10, q11);

            stack--;
            sp--;
            break;
        default:
            break;
        }

#if (defined HIGH_PERFORMANCE_X86_64)
        if (stack->n < 256) {

            if(stack->n < 192) {
                delta = support_jumpdivstep(stack->n, delta,
                                            (stack->n / DIGIT_SIZE_b + 1), stack->f, stack->g,
                                            stack->t00, stack->t01,
                                            stack->t10, stack->t11, x);
                stack--;
                sp--;
            }
            else {
                delta = divstepsx_256(stack->n, delta,
                                      stack->f,
                                      stack->g,
                                      stack->t00, stack->t01,
                                      stack->t10, stack->t11);
                stack--;
                sp--;
            }
        }

#elif (defined HIGH_COMPATIBILITY_X86_64)
        if (stack->n < 128) {
        delta = divstepsx_128(stack->n, delta,
                                     stack->f,
                                     stack->g,
                                     stack->t00, stack->t01,
                                     stack->t10, stack->t11);
        stack--;
        sp--;
    }
#else
    if (stack->n <= 63) {
        delta = divstepsx(stack->n, delta, stack->f[0],
                                 stack->g[0],
                                 stack->t00, stack->t01,
                                 stack->t10, stack->t11);
        stack--;
        sp--;
    }
#endif
    }

    num_digits_n = nf;
    num_digits_j = stack->j / DIGIT_SIZE_b + 1;
    num_digits_nminusj = (stack->n - stack->j) / DIGIT_SIZE_b + 1;

    gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                    num_digits_j,                      P00, P10,
                    num_digits_nminusj,                Q00, Q01);

    memcpy(t00,
           temp + (num_digits_j + num_digits_nminusj - num_digits_n),
           num_digits_n * DIGIT_SIZE_B);


    gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                    num_digits_j,                      P01, P11,
                    num_digits_nminusj,                Q00, Q01);
    memcpy(t01,
           temp + (num_digits_j + num_digits_nminusj - num_digits_n),
           num_digits_n * DIGIT_SIZE_B);


    gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                    num_digits_j,                      P00, P10,
                    num_digits_nminusj,                P10, Q11);
    memcpy(t10,
           temp + (num_digits_j + num_digits_nminusj - num_digits_n),
           num_digits_n * DIGIT_SIZE_B);


    gf2x_scalarprod(num_digits_j + num_digits_nminusj, temp,
                    num_digits_j,                      P01, P11,
                    num_digits_nminusj,                Q10, Q11);

    memcpy(t11,
           temp + (num_digits_j + num_digits_nminusj - num_digits_n),
           num_digits_n * DIGIT_SIZE_B);

    //printf("total skipped: %d  ", acc);
    acc = 0;
    return delta;
}

#define MATRIX_ELEM_DIGITS ((2 * P - 1)/DIGIT_SIZE_b+1)// NUM_DIGITS_GF2X_ELEMENT+2
int inverse_DJB(DIGIT out[], const DIGIT in[], float x)
{
#if NUM_DIGITS_GF2X_MODULUS == NUM_DIGITS_GF2X_ELEMENT
    DIGIT   f[NUM_DIGITS_GF2X_ELEMENT] = { 0 },   // S(x)
    g[NUM_DIGITS_GF2X_ELEMENT] = { 0 };   // R(x)

    DIGIT   u[MATRIX_ELEM_DIGITS] = { 0 },
            v[MATRIX_ELEM_DIGITS] = { 0 },
            q[MATRIX_ELEM_DIGITS] = { 0 },
            r[MATRIX_ELEM_DIGITS] = { 0 };

    int delta = 1;

    memcpy(g, in, NUM_DIGITS_GF2X_ELEMENT * DIGIT_SIZE_B);

    f[0] |= (((DIGIT) 0x1) << MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS);
    f[NUM_DIGITS_GF2X_ELEMENT - 1] = 0x1;

    int slack_bits_amount = (DIGIT_SIZE_b * NUM_DIGITS_GF2X_ELEMENT) - P;

    gf2x_reflect_in_place(f);
    right_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, f, slack_bits_amount - 1);
    gf2x_reflect_in_place(g);
    right_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, g, slack_bits_amount);

    DIGIT   largef[MATRIX_ELEM_DIGITS], largeg[MATRIX_ELEM_DIGITS];
    memset(largef,0x00,MATRIX_ELEM_DIGITS*DIGIT_SIZE_B);
    memcpy(largef+(MATRIX_ELEM_DIGITS-NUM_DIGITS_GF2X_ELEMENT), f,NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    memset(largeg,0x00,MATRIX_ELEM_DIGITS*DIGIT_SIZE_B);
    memcpy(largeg+(MATRIX_ELEM_DIGITS-NUM_DIGITS_GF2X_ELEMENT), g,NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
/*
    DIGIT A[3], B[2], RES[5], ZERO[3];
    A[1] = 58;
    A[2] = 15;
    B[1] = 179;

    gf2x_scalarprod(5, RES, 3, A, ZERO, 2, B, ZERO);
    print_pol(RES, "res", 5);*/


    delta = jumpdivstep(2 * P - 1,
                        delta, MATRIX_ELEM_DIGITS,
                        largef, largeg, u, v, q, r, x);

    /* Since I should reverse d-1 I can just reverse on d after dividing by x
       return kx( x^(2*d-2)*P[0][1] /f[0]).reverse(d-1) */
    right_bit_shift_n(MATRIX_ELEM_DIGITS, v, 1);

    gf2x_reflect_in_place(v + (MATRIX_ELEM_DIGITS - NUM_DIGITS_GF2X_ELEMENT));

    /* reflection is full-word-wise, shift away the slack bits */
    right_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, v + (MATRIX_ELEM_DIGITS - NUM_DIGITS_GF2X_ELEMENT), slack_bits_amount);

    memcpy(out, v + (MATRIX_ELEM_DIGITS - NUM_DIGITS_GF2X_ELEMENT),NUM_DIGITS_GF2X_ELEMENT * DIGIT_SIZE_B);

    DIGIT clear_slack_mask = ( ((DIGIT) 1) << ((DIGIT_SIZE_b) - slack_bits_amount) ) - 1;
    out[0] = out[0] & clear_slack_mask;

#else
#error IMPLEMENT MEMCPY INTO A LARGER OPERAND
#endif
    return 0;
}
