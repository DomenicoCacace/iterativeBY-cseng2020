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
void rotate_bit_right(DIGIT in[])   /*  x^{-1} * in(x) mod x^P+1 */
{

    DIGIT rotated_bit = in[NUM_DIGITS_GF2X_ELEMENT-1] & ((DIGIT)0x1);
    right_bit_shift(NUM_DIGITS_GF2X_ELEMENT, in);

    if (NUM_DIGITS_GF2X_MODULUS == NUM_DIGITS_GF2X_ELEMENT) {
        int msb_offset_in_digit = MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS-1;
        rotated_bit = rotated_bit << msb_offset_in_digit;
    } else {
        /* NUM_DIGITS_GF2X_MODULUS == 1 + NUM_DIGITS_GF2X_ELEMENT and
                * MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS == 0
                */
        rotated_bit = rotated_bit << (DIGIT_SIZE_b-1);
    }
    in[0] |= rotated_bit;
} // end rotate_bit_right

void rotate_bit_left(DIGIT in[])   /*  equivalent to x * in(x) mod x^P+1 */
{

    DIGIT mask,rotated_bit;

    if (NUM_DIGITS_GF2X_MODULUS == NUM_DIGITS_GF2X_ELEMENT) {

        int msb_offset_in_digit = MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS-1;
        mask = ((DIGIT)0x1) << msb_offset_in_digit;
        rotated_bit = !!(in[0] & mask);
        in[0] &= ~mask;                     /* clear shifted bit */
        left_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, in,1);
    } else {
        /* NUM_DIGITS_GF2X_MODULUS == 1 + NUM_DIGITS_GF2X_ELEMENT and
                * MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS == 0
                */
        mask =  ((DIGIT)0x1) << (DIGIT_SIZE_b-1);
        rotated_bit = !!(in[0] & mask);
        in[0] &= ~mask;                     /* clear shifted bit */
        left_bit_shift_n(NUM_DIGITS_GF2X_ELEMENT, in,1);

    }
    in[NUM_DIGITS_GF2X_ELEMENT-1] |= rotated_bit;
} // end rotate_bit_left

int gf2x_mod_inverse_Brunner(DIGIT out[], const DIGIT in[]) {
    int i;
    long int delta = 0;
    DIGIT *f,*s,*u,*v;
    f = alloca(NUM_DIGITS_GF2X_MODULUS*DIGIT_SIZE_B);
    s = alloca(NUM_DIGITS_GF2X_MODULUS*DIGIT_SIZE_B);
    u = alloca(NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    v = alloca(NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);

    DIGIT mask;
    u[NUM_DIGITS_GF2X_ELEMENT-1] = 0x1;
    v[NUM_DIGITS_GF2X_ELEMENT-1] = 0x0;

    s[NUM_DIGITS_GF2X_MODULUS-1] = 0x1;
    if (MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS == 0)
        mask = 0x1;
    else
        mask = (((DIGIT)0x1) << MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS);
    s[0] |= mask;

#if (NUM_DIGITS_GF2X_MODULUS == 1 + NUM_DIGITS_GF2X_ELEMENT)
    for (i = NUM_DIGITS_GF2X_MODULUS-1; i >= 1 ; i--) f[i] = in[i-1];
#else  /* they are equal */
    for (i = NUM_DIGITS_GF2X_MODULUS-1; i >= 0 ; i--) f[i] = in[i];
#endif

    for (i = 1; i <= 2*P; i++) {
        if ( (f[0] & mask) == 0 ) {
            left_bit_shift_n(NUM_DIGITS_GF2X_MODULUS, f,1);
            rotate_bit_left(u);
            delta += 1;
        } else {
            if ( (s[0] & mask) != 0) {
                gf2x_add(NUM_DIGITS_GF2X_MODULUS, s,
                         NUM_DIGITS_GF2X_MODULUS, s,
                         NUM_DIGITS_GF2X_MODULUS, f);
                gf2x_mod_add(v, v, u);
            }
            left_bit_shift_n(NUM_DIGITS_GF2X_MODULUS, s,1);
            if ( delta == 0 ) {
                DIGIT *tmp_ptr;
                tmp_ptr = f;
                f = s;
                s = tmp_ptr;
                tmp_ptr = u;
                u = v;
                v = tmp_ptr;

                rotate_bit_left(u);
                delta = 1;
            } else {
                rotate_bit_right(u);
                delta = delta - 1;
            }
        }
    }
    for (i = NUM_DIGITS_GF2X_ELEMENT-1; i >= 0 ; i--) out[i] = u[i];
    return (delta == 0);
} // end gf2x_mod_inverse
