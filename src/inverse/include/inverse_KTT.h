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

int gf2x_mod_inverse_KTT(DIGIT out[], const DIGIT in[]) { /* in^{-1} mod x^P-1 */

#if NUM_DIGITS_GF2X_MODULUS == NUM_DIGITS_GF2X_ELEMENT
    DIGIT s[NUM_DIGITS_GF2X_ELEMENT+1] = {0},
                                         r[NUM_DIGITS_GF2X_ELEMENT+1];
    r[0]=0;
    memcpy(r+1,in, NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);

    /* S starts set to the modulus */
    s[NUM_DIGITS_GF2X_ELEMENT+1-1] = 1;
    s[0+1] |= ((DIGIT)1) << MSb_POSITION_IN_MSB_DIGIT_OF_MODULUS;
    DIGIT v[NUM_DIGITS_GF2X_ELEMENT+1] = {0},
                                         u[NUM_DIGITS_GF2X_ELEMENT+1] = {0};

    u[NUM_DIGITS_GF2X_ELEMENT +1 -1] = (DIGIT) 2; /* x */

    int deg_r = NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1;
    int deg_s = NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_b -1;

    int l=0;
    int l1=0;

    DIGIT c,d;
    DIGIT h00,h01,h10,h11;

    DIGIT hibitmask = ( (DIGIT) 1) << (DIGIT_SIZE_b-1);

    while(deg_r > 0) {
        c=r[1];
        d=s[1];
        if(c == 0) {
            left_DIGIT_shift_n(NUM_DIGITS_GF2X_ELEMENT+1,r,1);
            left_DIGIT_shift_n(NUM_DIGITS_GF2X_ELEMENT+1,u,1);
            deg_r = deg_r - DIGIT_SIZE_b;
        } else {
            /* H = I */
            h00 = 1;
            h01 = 0;
            h10 = 0;
            h11 = 1;
            for(int j = 1 ; (j < DIGIT_SIZE_b) && (deg_r > 0) ; j++) {
                if ( (c & hibitmask) == 0) { /* */
                    c = c << 1;
                    h00 = h00 << 1;
                    h01 = h01 << 1;
                    deg_r--;
                } else { /* hibit r[0] set */
                    if (deg_r == deg_s) {
                        deg_r--;
                        if ( (d & hibitmask) == hibitmask) { /* hibit r[0],s[0] set, deg_r == deg_s */
                            DIGIT temp = c;
                            c = (c^d) << 1; /* (c-d)*x */
                            d = temp;
                            DIGIT r00;
                            r00 = (h00 << 1) ^ (h10 << 1);
                            DIGIT r01;
                            r01 = (h01 << 1) ^ (h11 << 1);

                            h10 = h00;
                            h11 = h01;
                            h00 = r00;
                            h01 = r01;

                        } else { /* hibit r[0] set, s[0] unset, deg_r == deg_s */
                            DIGIT temp;
                            temp = c;
                            c = d << 1;
                            d = temp;
                            /*mult H*/
                            DIGIT r00;
                            r00 = (h10 << 1);
                            DIGIT r01;
                            r01 = (h11 << 1);

                            h10 = h00;
                            h11 = h01;

                            h00 = r00;
                            h01 = r01;
                        }
                    } else { /* if (deg_r != deg_s) */
                        deg_s--;
                        if ( (d & hibitmask) == hibitmask) { /* hibit r[0],s[0] set, deg_r != deg_s */
                            d = (c^d) << 1; /* (c-d) * x*/
                            h10 = (h00 << 1) ^ (h10 << 1);
                            h11 = (h01 << 1) ^ (h11 << 1);
                        } else { /* hibit r[0] set, s[0] unset, deg_r != deg_s */
                            d = d << 1;
                            h10 = h10 << 1;
                            h11 = h11 << 1;
                        }
                    } /*(deg_r == deg_s)*/
                } /* if ( (c & ((DIGIT 1) << (DIGIT_SIZE_b-1))) == 0) */
            } /* while */
            /*update r , s */

            DIGIT r_h00[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT s_h01[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT r_h10[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT s_h11[NUM_DIGITS_GF2X_ELEMENT+2] = {0};

            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, r_h00,
                                      NUM_DIGITS_GF2X_ELEMENT+1, r,
                                      h00);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, s_h01,
                                      NUM_DIGITS_GF2X_ELEMENT+1, s,
                                      h01);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, r_h10,
                                      NUM_DIGITS_GF2X_ELEMENT+1, r,
                                      h10);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, s_h11,
                                      NUM_DIGITS_GF2X_ELEMENT+1, s,
                                      h11);

            gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, r,
                     NUM_DIGITS_GF2X_ELEMENT+1, r_h00+1,
                     NUM_DIGITS_GF2X_ELEMENT+1, s_h01+1);

            gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, s,
                     NUM_DIGITS_GF2X_ELEMENT+1, r_h10+1,
                     NUM_DIGITS_GF2X_ELEMENT+1, s_h11+1);

            /* *********************** update u, v *************************/
            DIGIT  u_h00[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT  v_h01[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT  u_h10[NUM_DIGITS_GF2X_ELEMENT+2] = {0};
            DIGIT  v_h11[NUM_DIGITS_GF2X_ELEMENT+2] = {0};

            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, u_h00,
                                      NUM_DIGITS_GF2X_ELEMENT+1, u,
                                      h00);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, v_h01,
                                      NUM_DIGITS_GF2X_ELEMENT+1, v,
                                      h01);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, u_h10,
                                      NUM_DIGITS_GF2X_ELEMENT+1, u,
                                      h10);
            GF2X_DIGIT_TIMES_POLY_MUL(NUM_DIGITS_GF2X_ELEMENT+2, v_h11,
                                      NUM_DIGITS_GF2X_ELEMENT+1, v,
                                      h11);

            /*turn this into CTIME*/
            if((v_h01[NUM_DIGITS_GF2X_ELEMENT+1] ^ u_h00[NUM_DIGITS_GF2X_ELEMENT+1])==0
                    &&
                    (v_h11[NUM_DIGITS_GF2X_ELEMENT+1] ^ u_h10[NUM_DIGITS_GF2X_ELEMENT+1])==0
                    &&
                    l1<NUM_DIGITS_GF2X_ELEMENT-1
              ) {
                //right digit shift
                gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, u,
                         NUM_DIGITS_GF2X_ELEMENT+1, u_h00,
                         NUM_DIGITS_GF2X_ELEMENT+1, v_h01);

                gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, v,
                         NUM_DIGITS_GF2X_ELEMENT+1, u_h10,
                         NUM_DIGITS_GF2X_ELEMENT+1, v_h11);

                l1++;
            } else {
                gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, u,
                         NUM_DIGITS_GF2X_ELEMENT+1, u_h00+1,
                         NUM_DIGITS_GF2X_ELEMENT+1, v_h01+1);

                gf2x_add(NUM_DIGITS_GF2X_ELEMENT+1, v,
                         NUM_DIGITS_GF2X_ELEMENT+1, u_h10+1,
                         NUM_DIGITS_GF2X_ELEMENT+1, v_h11+1);
            }
            l++;
        }
    }

    if (deg_r == 0) {
        /*output u / Mdigits */
        memcpy(out,u,NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    }
    else {
        /*output v / Mdigits */
        memcpy(out,v,NUM_DIGITS_GF2X_ELEMENT*DIGIT_SIZE_B);
    }
#else
#error IMPLEMENT MEMCPY INTO A LARGER OPERAND
#endif

    return 0;
}
