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


/* This tool outputs the bit permutation table to compute the inverse bit permutation
 * required to compute a(x)^(2^i) in the Fermat-method inverse.
 * The computation also takes into accound the endianness of the bits to be
 * performed, allowing to save the computation of the digit index and in-digit
 * position of the bit to be read.
 *
 * The tool computes the inverse permutation, to allow the computation to perform
 * coalesced write actions of the result.
 *
 * The tool can also output a more compact table, containing only the
 * values -2^(2^i) mod p
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int pow_pow_2_mod(int eexp, int modulus) {
    int64_t exp = (int64_t)1 << eexp;
    int result = 1;
    for(int i=0; i< exp; i++) {
        result = (2*result) %modulus;
    }
    return result;
}

int bits_to_represent(uint64_t value) {
    int num_bits = 0;
    while(value !=0) {
        num_bits++;
        value = value >> 1;
    }
    return num_bits;
}

/* compute modular inverse of a number via EEA
 * Pre: both value and modulus should fit in 32 bit signed integers.
 * Pre: modulus > value */
int inverse(int value, int modulus) {
    int64_t u[3],v[3],w[3] = {1,1,1};
    u[0] = modulus ;
    u[1] = 1;
    u[2] = 0;
    v[0] = value;
    v[1] = 0;
    v[2] = 1;
    while (w[0]!=0) {
        int64_t quotient = u[0] / v[0];
        w[0] = u[0] - quotient*v[0];
        w[1] = u[1] - quotient*v[1];
        w[2] = u[2] - quotient*v[2];
        u[0] = v[0];
        u[1] = v[1];
        u[2] = v[2];
        v[0] = w[0];
        v[1] = w[1];
        v[2] = w[2];
    }
    return (u[2]+modulus)%modulus; // force positive representative of rem class
}

void compute_inverse_factors_table(int modulus,
                                   unsigned int inverse_factors_table[]) {
    for (int i =0; i< bits_to_represent(modulus); i++) {
        inverse_factors_table[i]=inverse(pow_pow_2_mod(i,modulus),modulus);
    }
}

void pretty_print_factors_table(int modulus,
                                unsigned int factor_table[]) {
    int num_entries =bits_to_represent(modulus);
    printf("#if (P=%d)\nunsigned int inverse_factors_table[%d] = {\n",
           modulus,
           num_entries);
    for(int i = 0; i < num_entries-1; i++) {
        printf("  %d,\n",factor_table[i]);
    }
    printf("  %d}\n#endif\n",factor_table[num_entries-1]);
}


void compute_inverse_index_permutation_table(int modulus,
        size_t digit_size_b,
        /* argument needed only due to vararg parameter */
        size_t bits_to_represent_modulus,
        size_t gf2x_element_digits,
        unsigned int inverse_factors_table[bits_to_represent_modulus],
        int inverse_index_permutation_table[bits_to_represent_modulus][gf2x_element_digits*digit_size_b]
                                            ) {
    for(int eexp = 0; eexp < bits_to_represent(modulus); eexp++) {
        int64_t factor = inverse_factors_table[eexp];
        for(int dst_exp = 0; dst_exp < modulus; dst_exp++) {
            int64_t src_exp = (dst_exp*factor)%modulus;
            int64_t src_pos =  (gf2x_element_digits*digit_size_b -1) - src_exp;
            int64_t dst_pos =  (gf2x_element_digits*digit_size_b -1) - dst_exp;
            inverse_index_permutation_table[eexp][dst_pos] = src_pos;
        }
    }
}

void pretty_print_inverse_index_permutation_table(int modulus,
        size_t digit_size_b,
        /* argument needed only due to vararg parameter */
        size_t bits_to_represent_modulus,
        size_t gf2x_element_digits,
        int inverse_index_permutation_table[bits_to_represent_modulus][gf2x_element_digits*digit_size_b]
                                                 ) {

    printf("#if (P=%d)\n %s inverse_index_permutation_table[%d][%d] = {\n",
           modulus,
           (gf2x_element_digits*digit_size_b) < 65535 ? "uint16_t" : "uint32_t",
           bits_to_represent_modulus,
           gf2x_element_digits*digit_size_b);

    for(int i = 0; i < bits_to_represent_modulus-1; i++) {
        printf("{ ");
        for(int j = 0; j < gf2x_element_digits*digit_size_b-1; j++) {
            printf("  %d,",inverse_index_permutation_table[i][j]);
        }
        printf("  %d},\n",inverse_index_permutation_table[i][gf2x_element_digits*digit_size_b-1]);
    }
    printf("{ ");
    for(int j = 0; j < gf2x_element_digits*digit_size_b-1; j++) {
        printf("  %d,",inverse_index_permutation_table[bits_to_represent_modulus-1][j]);
    }
    printf("  %d}}\n#endif\n",inverse_index_permutation_table[bits_to_represent_modulus-1][gf2x_element_digits*digit_size_b-1]);
}


int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Index generator for binary polynomial double-exponentiation 2^(2^i)\n");
        printf("Usage: %s <modulus> <architecture_word_size_in_bits> <compact_table>\n");
        return 1;
    }

    int modulus,digit_size_b, compact_table;
    modulus= atoi(argv[1]);
    digit_size_b = atoi(argv[2]);
    compact_table = atoi(argv[3]);

    int bits_to_represent_modulus = bits_to_represent(modulus);
    int gf2x_element_digits = (modulus+digit_size_b-1)/digit_size_b;

    unsigned int inverse_factors_table_test[bits_to_represent_modulus];
    int inverse_index_permutation_table[bits_to_represent_modulus][gf2x_element_digits*digit_size_b];
    compute_inverse_factors_table(modulus, inverse_factors_table_test);
    compute_inverse_index_permutation_table(modulus,
                                            digit_size_b,
                                            bits_to_represent_modulus,
                                            gf2x_element_digits,
                                            inverse_factors_table, inverse_index_permutation_table);
    if(compact_table) {
        pretty_print_factors_table(modulus,inverse_factors_table_test);
    } else {
        pretty_print_inverse_index_permutation_table(modulus,
                digit_size_b,
                /* argument needed only due to vararg parameter */
                bits_to_represent_modulus,
                gf2x_element_digits,
                inverse_index_permutation_table);
    }
    return 0;
}
