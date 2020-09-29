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

/* Square, employing CLMUL */
void pow_2_A(DIGIT * poly_sq, DIGIT * poly);

/* Square, employing CLMUL, without folding */
void pow_2_C(DIGIT * poly_sq, DIGIT * poly);

void raise_2_i_clmul(DIGIT* a, int i);

/******************************************************************************/
void raise_2_i_direct_permute_wfunctions(DIGIT* a, int i);

void  init_direct_factors_table(void);
void raise_2_i_factor_permute(DIGIT* a, int i);

void  init_permutation_table(void);
void raise_2_i_perm_table(DIGIT* a, int i);

/******************************************************************************/
/* table is constant and preinitialized*/
void raise_2_i_factor_inverse_permute(DIGIT* a, int i);

void init_inverse_permutation_table(void);
void raise_2_i_inverse_perm_table(DIGIT* a, int i);

void init_inverse_index_permutation_table(void);
void raise_2_i_inverse_perm_table_linsweep(DIGIT* a, int i);

/******************************************************************************/
void raise_2_i_hybrid(DIGIT* a, int i);
void gf2x_mod_inverse_exp(DIGIT * polyInv, DIGIT * poly);
void gf2x_mod_inverse_exp_compactmem(DIGIT * polyInv, DIGIT * poly);
void gf2x_mod_inverse_exp_onlysquares(DIGIT * polyInv, DIGIT * poly);
