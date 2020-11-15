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
#include "../include/inverse_DJB_specific.h"

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

    switch (P) {
        case  7187:
            delta = jumpdivstep_7187(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case  8237:
            delta = jumpdivstep_8237(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 10853:
            delta = jumpdivstep_10853(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 13109:
            delta = jumpdivstep_13109(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 13397:
            delta = jumpdivstep_13397(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 15331:
            delta = jumpdivstep_15331(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 16067:
            delta = jumpdivstep_16067(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 16229:
            delta = jumpdivstep_16229(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 19709:
            delta = jumpdivstep_19709(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 20981:
            delta = jumpdivstep_20981(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 21611:
            delta = jumpdivstep_21611(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 22901:
            delta = jumpdivstep_22901(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 23371:
            delta = jumpdivstep_23371(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 25579:
            delta = jumpdivstep_25579(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 28277:
            delta = jumpdivstep_28277(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 28411:
            delta = jumpdivstep_28411(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 30803:
            delta = jumpdivstep_30803(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 35117:
            delta = jumpdivstep_35117(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 35507:
            delta = jumpdivstep_35507(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 36629:
            delta = jumpdivstep_36629(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 40787:
            delta = jumpdivstep_40787(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 42677:
            delta = jumpdivstep_42677(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 48371:
            delta = jumpdivstep_48371(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 52667:
            delta = jumpdivstep_52667(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 58171:
            delta = jumpdivstep_58171(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 61717:
            delta = jumpdivstep_61717(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        case 83579:
            delta = jumpdivstep_83579(2 * P - 1, delta, MATRIX_ELEM_DIGITS, largef, largeg, u, v, q, r, x);
            break;
        default:
            break;
    }


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
