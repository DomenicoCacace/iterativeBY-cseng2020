/**
  * Software Artifact of the paper A Comprehensive Analysis of Constant-time
  * Polynomial Inversion for Post-quantum Cryptosystems
  *
  * @author Domenico Cacace <domenico.cacace@mail.polimi.it>
  * 
  * This code has been automatically generated
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

#include "../../include/inverse_DJB_facilities.h"

int jumpdivstep_8237(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[280];
	DIGIT p_01[280];
	DIGIT p_10[280];
	DIGIT p_11[280];
	
	DIGIT q_00[254];
	DIGIT q_01[254];
	DIGIT q_10[254];
	DIGIT q_11[254];
	
	DIGIT f_sum[822];
	DIGIT g_sum[822];
	
	DIGIT temp[522];
	DIGIT temp2[522];
	

	delta = divstepsx_256(255, delta, f+254, g+254, p_00+276, p_01+276, p_10+276, p_11+276);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+250+4, 4, p_00+276);
	GF2X_MUL(8, temp2, 4, g+250+4, 4, p_01+276);
	gf2x_add(8, f_sum+808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+250+0, 4, p_00+276);
	GF2X_MUL(8, temp2, 4, g+250+0, 4, p_01+276);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+808, 4, f_sum+808, 4, temp+4);
	right_bit_shift_n(8, f_sum+808, 63);
	GF2X_MUL(8, temp, 4, f+250+4, 4, p_10+276);
	GF2X_MUL(8, temp2, 4, g+250+4, 4, p_11+276);
	gf2x_add(8, g_sum+808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+250+0, 4, p_10+276);
	GF2X_MUL(8, temp2, 4, g+250+0, 4, p_11+276);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+808, 4, g_sum+808, 4, temp+4);
	right_bit_shift_n(8, g_sum+808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+809, g_sum+809, q_00+250, q_01+250, q_10+250, q_11+250);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+250+0, 4, p_00+276);
	GF2X_MUL(8, temp2, 4, q_01+250+0, 4, p_10+276);
	gf2x_add(8, p_00+268+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+250+0, 4, p_01+276);
	GF2X_MUL(8, temp2, 4, q_01+250+0, 4, p_11+276);
	gf2x_add(8, p_01+268+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+250+0, 4, p_00+276);
	GF2X_MUL(8, temp2, 4, q_11+250+0, 4, p_10+276);
	gf2x_add(8, p_10+268+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+250+0, 4, p_01+276);
	GF2X_MUL(8, temp2, 4, q_11+250+0, 4, p_11+276);
	gf2x_add(8, p_11+268+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+246+4, 8, p_00+268);
	GF2X_MUL(16, temp2, 8, g+246+4, 8, p_01+268);
	gf2x_add(12, f_sum+787, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+268+4, 4, f+246);
	GF2X_MUL(8, temp2, 4, p_01+268+4, 4, g+246);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(12, f_sum+787, 62);
	GF2X_MUL(16, temp, 8, f+246+4, 8, p_10+268);
	GF2X_MUL(16, temp2, 8, g+246+4, 8, p_11+268);
	gf2x_add(12, g_sum+787, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+268+4, 4, f+246);
	GF2X_MUL(8, temp2, 4, p_11+268+4, 4, g+246);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(12, g_sum+787, 62);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 765, depth: 5
	memset(p_00+256, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+268+4, 4, q_00+246);
	GF2X_MUL(8, temp2, 4, p_10+268+4, 4, q_01+246);
	gf2x_add(8, p_00+256+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+256+0, 8, p_00+256+0, 8, temp);
	memset(p_01+256, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+268+4, 4, q_00+246);
	GF2X_MUL(8, temp2, 4, p_11+268+4, 4, q_01+246);
	gf2x_add(8, p_01+256+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+256+0, 8, p_01+256+0, 8, temp);
	memset(p_10+256, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+268+4, 4, q_10+246);
	GF2X_MUL(8, temp2, 4, p_10+268+4, 4, q_11+246);
	gf2x_add(8, p_10+256+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+256+0, 8, p_10+256+0, 8, temp);
	memset(p_11+256, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+268+4, 4, q_10+246);
	GF2X_MUL(8, temp2, 4, p_11+268+4, 4, q_11+246);
	gf2x_add(8, p_11+256+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+256+0, 8, p_11+256+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+238+8, 12, p_00+256);
	GF2X_MUL(24, temp2, 12, g+238+8, 12, p_01+256);
	gf2x_add(20, f_sum+754, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+256+4, 8, f+238);
	GF2X_MUL(16, temp2, 8, p_01+256+4, 8, g+238);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(20, f_sum+754, 61);
	GF2X_MUL(24, temp, 12, f+238+8, 12, p_10+256);
	GF2X_MUL(24, temp2, 12, g+238+8, 12, p_11+256);
	gf2x_add(20, g_sum+754, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+256+4, 8, f+238);
	GF2X_MUL(16, temp2, 8, p_11+256+4, 8, g+238);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(20, g_sum+754, 61);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(p_00+236, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+256+4, 8, q_00+238);
	GF2X_MUL(16, temp2, 8, p_10+256+4, 8, q_01+238);
	gf2x_add(16, p_00+236+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+238+4, 4, p_00+256);
	GF2X_MUL(8, temp2, 4, q_01+238+4, 4, p_10+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+236+4, 8, p_00+236+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+238+0, 4, p_00+256);
	GF2X_MUL(8, temp2, 4, q_01+238+0, 4, p_10+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+236+0, 8, p_00+236+0, 8, temp);
	memset(p_01+236, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+256+4, 8, q_00+238);
	GF2X_MUL(16, temp2, 8, p_11+256+4, 8, q_01+238);
	gf2x_add(16, p_01+236+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+238+4, 4, p_01+256);
	GF2X_MUL(8, temp2, 4, q_01+238+4, 4, p_11+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+236+4, 8, p_01+236+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+238+0, 4, p_01+256);
	GF2X_MUL(8, temp2, 4, q_01+238+0, 4, p_11+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+236+0, 8, p_01+236+0, 8, temp);
	memset(p_10+236, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+256+4, 8, q_10+238);
	GF2X_MUL(16, temp2, 8, p_10+256+4, 8, q_11+238);
	gf2x_add(16, p_10+236+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+238+4, 4, p_00+256);
	GF2X_MUL(8, temp2, 4, q_11+238+4, 4, p_10+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+236+4, 8, p_10+236+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+238+0, 4, p_00+256);
	GF2X_MUL(8, temp2, 4, q_11+238+0, 4, p_10+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+236+0, 8, p_10+236+0, 8, temp);
	memset(p_11+236, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+256+4, 8, q_10+238);
	GF2X_MUL(16, temp2, 8, p_11+256+4, 8, q_11+238);
	gf2x_add(16, p_11+236+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+238+4, 4, p_01+256);
	GF2X_MUL(8, temp2, 4, q_11+238+4, 4, p_11+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+236+4, 8, p_11+236+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+238+0, 4, p_01+256);
	GF2X_MUL(8, temp2, 4, q_11+238+0, 4, p_11+256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+236+0, 8, p_11+236+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 3
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f+222+16, 20, p_00+236);
	GF2X_MUL(40, temp2, 20, g+222+16, 20, p_01+236);
	gf2x_add(36, f_sum+697, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+236+4, 16, f+222);
	GF2X_MUL(32, temp2, 16, p_01+236+4, 16, g+222);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(36, f_sum+697, 59);
	GF2X_MUL(40, temp, 20, f+222+16, 20, p_10+236);
	GF2X_MUL(40, temp2, 20, g+222+16, 20, p_11+236);
	gf2x_add(36, g_sum+697, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+236+4, 16, f+222);
	GF2X_MUL(32, temp2, 16, p_11+236+4, 16, g+222);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(36, g_sum+697, 59);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 3
	memset(p_00+200, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+236+4, 16, q_00+222);
	GF2X_MUL(32, temp2, 16, p_10+236+4, 16, q_01+222);
	gf2x_add(32, p_00+200+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+222+12, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_01+222+12, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+200+12, 8, p_00+200+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+8, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_01+222+8, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+200+8, 8, p_00+200+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+4, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_01+222+4, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+200+4, 8, p_00+200+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+0, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_01+222+0, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+200+0, 8, p_00+200+0, 8, temp);
	memset(p_01+200, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+236+4, 16, q_00+222);
	GF2X_MUL(32, temp2, 16, p_11+236+4, 16, q_01+222);
	gf2x_add(32, p_01+200+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+222+12, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_01+222+12, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+200+12, 8, p_01+200+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+8, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_01+222+8, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+200+8, 8, p_01+200+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+4, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_01+222+4, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+200+4, 8, p_01+200+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+222+0, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_01+222+0, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+200+0, 8, p_01+200+0, 8, temp);
	memset(p_10+200, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+236+4, 16, q_10+222);
	GF2X_MUL(32, temp2, 16, p_10+236+4, 16, q_11+222);
	gf2x_add(32, p_10+200+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+222+12, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_11+222+12, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+200+12, 8, p_10+200+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+8, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_11+222+8, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+200+8, 8, p_10+200+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+4, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_11+222+4, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+200+4, 8, p_10+200+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+0, 4, p_00+236);
	GF2X_MUL(8, temp2, 4, q_11+222+0, 4, p_10+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+200+0, 8, p_10+200+0, 8, temp);
	memset(p_11+200, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+236+4, 16, q_10+222);
	GF2X_MUL(32, temp2, 16, p_11+236+4, 16, q_11+222);
	gf2x_add(32, p_11+200+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+222+12, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_11+222+12, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+200+12, 8, p_11+200+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+8, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_11+222+8, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+200+8, 8, p_11+200+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+4, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_11+222+4, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+200+4, 8, p_11+200+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+222+0, 4, p_01+236);
	GF2X_MUL(8, temp2, 4, q_11+222+0, 4, p_11+236);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+200+0, 8, p_11+200+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 2
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f+190+32, 36, p_00+200);
	GF2X_MUL(72, temp2, 36, g+190+32, 36, p_01+200);
	gf2x_add(68, f_sum+592, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+200+4, 32, f+190);
	GF2X_MUL(64, temp2, 32, p_01+200+4, 32, g+190);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+592, 32, f_sum+592, 32, temp+32);
	right_bit_shift_n(68, f_sum+592, 55);
	GF2X_MUL(72, temp, 36, f+190+32, 36, p_10+200);
	GF2X_MUL(72, temp2, 36, g+190+32, 36, p_11+200);
	gf2x_add(68, g_sum+592, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+200+4, 32, f+190);
	GF2X_MUL(64, temp2, 32, p_11+200+4, 32, g+190);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+592, 32, g_sum+592, 32, temp+32);
	right_bit_shift_n(68, g_sum+592, 55);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, q_00+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, q_01+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, q_10+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, q_11+190+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 2
	memset(p_00+132, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+200+4, 32, q_00+190);
	GF2X_MUL(64, temp2, 32, p_10+200+4, 32, q_01+190);
	gf2x_add(64, p_00+132+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+190+28, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+28, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+28, 8, p_00+132+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+24, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+24, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+24, 8, p_00+132+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+20, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+20, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+20, 8, p_00+132+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+16, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+16, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+16, 8, p_00+132+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+12, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+12, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+12, 8, p_00+132+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+8, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+8, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+8, 8, p_00+132+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+4, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+4, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+4, 8, p_00+132+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+0, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_01+190+0, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+132+0, 8, p_00+132+0, 8, temp);
	memset(p_01+132, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+200+4, 32, q_00+190);
	GF2X_MUL(64, temp2, 32, p_11+200+4, 32, q_01+190);
	gf2x_add(64, p_01+132+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+190+28, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+28, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+28, 8, p_01+132+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+24, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+24, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+24, 8, p_01+132+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+20, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+20, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+20, 8, p_01+132+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+16, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+16, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+16, 8, p_01+132+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+12, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+12, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+12, 8, p_01+132+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+8, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+8, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+8, 8, p_01+132+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+4, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+4, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+4, 8, p_01+132+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+190+0, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_01+190+0, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+132+0, 8, p_01+132+0, 8, temp);
	memset(p_10+132, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+200+4, 32, q_10+190);
	GF2X_MUL(64, temp2, 32, p_10+200+4, 32, q_11+190);
	gf2x_add(64, p_10+132+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+190+28, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+28, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+28, 8, p_10+132+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+24, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+24, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+24, 8, p_10+132+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+20, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+20, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+20, 8, p_10+132+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+16, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+16, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+16, 8, p_10+132+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+12, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+12, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+12, 8, p_10+132+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+8, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+8, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+8, 8, p_10+132+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+4, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+4, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+4, 8, p_10+132+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+0, 4, p_00+200);
	GF2X_MUL(8, temp2, 4, q_11+190+0, 4, p_10+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+132+0, 8, p_10+132+0, 8, temp);
	memset(p_11+132, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+200+4, 32, q_10+190);
	GF2X_MUL(64, temp2, 32, p_11+200+4, 32, q_11+190);
	gf2x_add(64, p_11+132+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+190+28, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+28, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+28, 8, p_11+132+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+24, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+24, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+24, 8, p_11+132+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+20, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+20, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+20, 8, p_11+132+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+16, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+16, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+16, 8, p_11+132+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+12, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+12, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+12, 8, p_11+132+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+8, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+8, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+8, 8, p_11+132+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+4, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+4, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+4, 8, p_11+132+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+190+0, 4, p_01+200);
	GF2X_MUL(8, temp2, 4, q_11+190+0, 4, p_11+200);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+132+0, 8, p_11+132+0, 8, temp);
	

	// Calculating left operands: n: 8415, depth: 1
	// Digits to shift: 67
	// Displacement: 68
	GF2X_MUL(136, temp, 68, f+126+64, 68, p_00+132);
	GF2X_MUL(136, temp2, 68, g+126+64, 68, p_01+132);
	gf2x_add(132, f_sum+391, 132, temp+4, 132, temp2+4);
	GF2X_MUL(128, temp, 64, p_00+132+4, 64, f+126);
	GF2X_MUL(128, temp2, 64, p_01+132+4, 64, g+126);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+391, 64, f_sum+391, 64, temp+64);
	right_bit_shift_n(132, f_sum+391, 47);
	GF2X_MUL(136, temp, 68, f+126+64, 68, p_10+132);
	GF2X_MUL(136, temp2, 68, g+126+64, 68, p_11+132);
	gf2x_add(132, g_sum+391, 132, temp+4, 132, temp2+4);
	GF2X_MUL(128, temp, 64, p_10+132+4, 64, f+126);
	GF2X_MUL(128, temp2, 64, p_11+132+4, 64, g+126);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+391, 64, g_sum+391, 64, temp+64);
	right_bit_shift_n(132, g_sum+391, 47);
	

	delta = divstepsx_256(255, delta, f_sum+452, g_sum+452, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+448+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+448+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+448+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+448+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+448+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+448+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+448+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+448+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+440+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+440+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+440+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+440+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+440+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+440+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+440+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+440+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+424+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+424+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+424+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+424+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+424+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+424+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+424+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+424+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, p_00+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, p_01+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, p_10+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, p_11+200+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 2
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+392+32, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+32, 32, p_01+200);
	gf2x_add(64, f_sum+592+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+392+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+0, 32, p_01+200);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+592, 32, f_sum+592, 32, temp+32);
	right_bit_shift_n(64, f_sum+592, 56);
	GF2X_MUL(64, temp, 32, f_sum+392+32, 32, p_10+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+32, 32, p_11+200);
	gf2x_add(64, g_sum+592+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+392+0, 32, p_10+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+0, 32, p_11+200);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+592, 32, g_sum+592, 32, temp+32);
	right_bit_shift_n(64, g_sum+592, 56);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, q_00+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, q_01+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, q_10+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, q_11+190+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 2
	GF2X_MUL(64, temp, 32, q_00+190+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, q_01+190+0, 32, p_10+200);
	gf2x_add(64, q_00+126+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+190+0, 32, p_01+200);
	GF2X_MUL(64, temp2, 32, q_01+190+0, 32, p_11+200);
	gf2x_add(64, q_01+126+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+190+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, q_11+190+0, 32, p_10+200);
	gf2x_add(64, q_10+126+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+190+0, 32, p_01+200);
	GF2X_MUL(64, temp2, 32, q_11+190+0, 32, p_11+200);
	gf2x_add(64, q_11+126+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8415, depth: 1
	memset(p_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_00+132+4, 64, q_00+126);
	GF2X_MUL(128, temp2, 64, p_10+132+4, 64, q_01+126);
	gf2x_add(128, p_00+0+4, 128, temp, 128, temp2);
	GF2X_MUL(8, temp, 4, q_00+126+60, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+60, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+60, 8, p_00+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+56, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+56, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+56, 8, p_00+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+52, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+52, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+52, 8, p_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+48, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+48, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+48, 8, p_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+44, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+44, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+44, 8, p_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+40, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+40, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+40, 8, p_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+36, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+36, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+36, 8, p_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+32, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+32, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+32, 8, p_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+28, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+28, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+28, 8, p_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+24, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+24, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+24, 8, p_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+20, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+20, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+20, 8, p_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+16, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+16, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+16, 8, p_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+12, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+12, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+12, 8, p_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+8, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+8, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+8, 8, p_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+4, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+4, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+4, 8, p_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+0, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_01+126+0, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+0, 8, p_00+0+0, 8, temp);
	memset(p_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_01+132+4, 64, q_00+126);
	GF2X_MUL(128, temp2, 64, p_11+132+4, 64, q_01+126);
	gf2x_add(128, p_01+0+4, 128, temp, 128, temp2);
	GF2X_MUL(8, temp, 4, q_00+126+60, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+60, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+60, 8, p_01+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+56, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+56, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+56, 8, p_01+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+52, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+52, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+52, 8, p_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+48, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+48, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+48, 8, p_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+44, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+44, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+44, 8, p_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+40, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+40, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+40, 8, p_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+36, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+36, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+36, 8, p_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+32, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+32, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+32, 8, p_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+28, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+28, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+28, 8, p_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+24, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+24, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+24, 8, p_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+20, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+20, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+20, 8, p_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+16, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+16, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+16, 8, p_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+12, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+12, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+12, 8, p_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+8, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+8, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+8, 8, p_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+4, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+4, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+4, 8, p_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+126+0, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_01+126+0, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+0, 8, p_01+0+0, 8, temp);
	memset(p_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_00+132+4, 64, q_10+126);
	GF2X_MUL(128, temp2, 64, p_10+132+4, 64, q_11+126);
	gf2x_add(128, p_10+0+4, 128, temp, 128, temp2);
	GF2X_MUL(8, temp, 4, q_10+126+60, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+60, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+60, 8, p_10+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+56, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+56, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+56, 8, p_10+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+52, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+52, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+52, 8, p_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+48, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+48, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+48, 8, p_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+44, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+44, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+44, 8, p_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+40, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+40, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+40, 8, p_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+36, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+36, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+36, 8, p_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+32, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+32, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+32, 8, p_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+28, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+28, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+28, 8, p_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+24, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+24, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+24, 8, p_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+20, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+20, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+20, 8, p_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+16, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+16, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+16, 8, p_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+12, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+12, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+12, 8, p_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+8, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+8, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+8, 8, p_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+4, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+4, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+4, 8, p_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+0, 4, p_00+132);
	GF2X_MUL(8, temp2, 4, q_11+126+0, 4, p_10+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+0, 8, p_10+0+0, 8, temp);
	memset(p_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, p_01+132+4, 64, q_10+126);
	GF2X_MUL(128, temp2, 64, p_11+132+4, 64, q_11+126);
	gf2x_add(128, p_11+0+4, 128, temp, 128, temp2);
	GF2X_MUL(8, temp, 4, q_10+126+60, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+60, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+60, 8, p_11+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+56, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+56, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+56, 8, p_11+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+52, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+52, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+52, 8, p_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+48, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+48, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+48, 8, p_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+44, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+44, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+44, 8, p_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+40, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+40, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+40, 8, p_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+36, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+36, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+36, 8, p_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+32, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+32, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+32, 8, p_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+28, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+28, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+28, 8, p_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+24, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+24, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+24, 8, p_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+20, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+20, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+20, 8, p_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+16, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+16, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+16, 8, p_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+12, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+12, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+12, 8, p_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+8, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+8, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+8, 8, p_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+4, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+4, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+4, 8, p_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+126+0, 4, p_01+132);
	GF2X_MUL(8, temp2, 4, q_11+126+0, 4, p_11+132);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+0, 8, p_11+0+0, 8, temp);
	

	// Calculating left operands: n: 16473, depth: 0
	// Digits to shift: 131
	// Displacement: 132
	GF2X_MUL(264, temp, 132, f+0+126, 132, p_00+0);
	GF2X_MUL(264, temp2, 132, g+0+126, 132, p_01+0);
	gf2x_add(258, f_sum+0, 258, temp+6, 258, temp2+6);
	GF2X_MUL(252, temp, 126, p_00+0+6, 126, f+0);
	GF2X_MUL(252, temp2, 126, p_01+0+6, 126, g+0);
	gf2x_add(252, temp, 252, temp, 252, temp2);
	gf2x_add(126, f_sum+0, 126, f_sum+0, 126, temp+126);
	right_bit_shift_n(258, f_sum+0, 31);
	GF2X_MUL(264, temp, 132, f+0+126, 132, p_10+0);
	GF2X_MUL(264, temp2, 132, g+0+126, 132, p_11+0);
	gf2x_add(258, g_sum+0, 258, temp+6, 258, temp2+6);
	GF2X_MUL(252, temp, 126, p_10+0+6, 126, f+0);
	GF2X_MUL(252, temp2, 126, p_11+0+6, 126, g+0);
	gf2x_add(252, temp, 252, temp, 252, temp2);
	gf2x_add(126, g_sum+0, 126, g_sum+0, 126, temp+126);
	right_bit_shift_n(258, g_sum+0, 31);
	

	delta = divstepsx_256(255, delta, f_sum+123, g_sum+123, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+119+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+119+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+119+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+119+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+119+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+119+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+119+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+119+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+111+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+111+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+111+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+111+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+111+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+111+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+111+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+111+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+95+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+95+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+95+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+95+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+95+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+95+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+95+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+95+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, p_00+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, p_01+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, p_10+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, p_11+200+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 2
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+63+32, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, g_sum+63+32, 32, p_01+200);
	gf2x_add(64, f_sum+592+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+63+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, g_sum+63+0, 32, p_01+200);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+592, 32, f_sum+592, 32, temp+32);
	right_bit_shift_n(64, f_sum+592, 56);
	GF2X_MUL(64, temp, 32, f_sum+63+32, 32, p_10+200);
	GF2X_MUL(64, temp2, 32, g_sum+63+32, 32, p_11+200);
	gf2x_add(64, g_sum+592+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+63+0, 32, p_10+200);
	GF2X_MUL(64, temp2, 32, g_sum+63+0, 32, p_11+200);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+592, 32, g_sum+592, 32, temp+32);
	right_bit_shift_n(64, g_sum+592, 56);
	

	delta = divstepsx_256(255, delta, f_sum+621, g_sum+621, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+617+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+617+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+617+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+609+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+609+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+609+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+593+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+593+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, q_00+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, q_01+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, q_10+190+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, q_11+190+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 2
	GF2X_MUL(64, temp, 32, q_00+190+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, q_01+190+0, 32, p_10+200);
	gf2x_add(64, p_00+132+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+190+0, 32, p_01+200);
	GF2X_MUL(64, temp2, 32, q_01+190+0, 32, p_11+200);
	gf2x_add(64, p_01+132+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+190+0, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, q_11+190+0, 32, p_10+200);
	gf2x_add(64, p_10+132+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+190+0, 32, p_01+200);
	GF2X_MUL(64, temp2, 32, q_11+190+0, 32, p_11+200);
	gf2x_add(64, p_11+132+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8058, depth: 1
	// Digits to shift: 63
	// Displacement: 63
	GF2X_MUL(128, temp, 64, f_sum+1+62, 64, p_00+132);
	GF2X_MUL(128, temp2, 64, g_sum+1+62, 64, p_01+132);
	gf2x_add(127, f_sum+391, 127, temp+1, 127, temp2+1);
	GF2X_MUL(124, temp, 62, p_00+132+2, 62, f_sum+1);
	GF2X_MUL(124, temp2, 62, p_01+132+2, 62, g_sum+1);
	gf2x_add(124, temp, 124, temp, 124, temp2);
	gf2x_add(63, f_sum+391, 63, f_sum+391, 63, temp+61);
	GF2X_MUL(4, temp, 2, f_sum+1+60, 2, p_00+132);
	GF2X_MUL(4, temp2, 2, g_sum+1+60, 2, p_01+132);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, f_sum+391, 1, f_sum+391, 1, temp+3);
	right_bit_shift_n(126, f_sum+391, 48);
	GF2X_MUL(128, temp, 64, f_sum+1+62, 64, p_10+132);
	GF2X_MUL(128, temp2, 64, g_sum+1+62, 64, p_11+132);
	gf2x_add(127, g_sum+391, 127, temp+1, 127, temp2+1);
	GF2X_MUL(124, temp, 62, p_10+132+2, 62, f_sum+1);
	GF2X_MUL(124, temp2, 62, p_11+132+2, 62, g_sum+1);
	gf2x_add(124, temp, 124, temp, 124, temp2);
	gf2x_add(63, g_sum+391, 63, g_sum+391, 63, temp+61);
	GF2X_MUL(4, temp, 2, f_sum+1+60, 2, p_10+132);
	GF2X_MUL(4, temp2, 2, g_sum+1+60, 2, p_11+132);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, g_sum+391, 1, g_sum+391, 1, temp+3);
	right_bit_shift_n(126, g_sum+391, 48);
	

	delta = divstepsx_256(255, delta, f_sum+451, g_sum+451, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+447+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+447+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+447+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+447+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+447+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+447+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+447+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+447+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+439+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+439+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+439+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+439+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+439+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+439+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+439+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+439+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+423+16, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+423+16, 16, p_01+236);
	gf2x_add(32, f_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+423+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+423+0, 16, p_01+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+697, 16, f_sum+697, 16, temp+16);
	right_bit_shift_n(32, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+423+16, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+423+16, 16, p_11+236);
	gf2x_add(32, g_sum+697+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+423+0, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+423+0, 16, p_11+236);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+697, 16, g_sum+697, 16, temp+16);
	right_bit_shift_n(32, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+710, g_sum+710, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+706+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+706+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+706+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+698+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, q_00+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, q_01+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, q_10+222+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, q_11+222+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 3
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_10+236);
	gf2x_add(32, p_00+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_01+222+0, 16, p_11+236);
	gf2x_add(32, p_01+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_10+236);
	gf2x_add(32, p_10+200+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+222+0, 16, p_01+236);
	GF2X_MUL(32, temp2, 16, q_11+222+0, 16, p_11+236);
	gf2x_add(32, p_11+200+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3978, depth: 2
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+392+31, 32, p_00+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+31, 32, p_01+200);
	gf2x_add(63, f_sum+592, 63, temp+1, 63, temp2+1);
	GF2X_MUL(62, temp, 31, p_00+200+1, 31, f_sum+392);
	GF2X_MUL(62, temp2, 31, p_01+200+1, 31, g_sum+392);
	gf2x_add(62, temp, 62, temp, 62, temp2);
	gf2x_add(31, f_sum+592, 31, f_sum+592, 31, temp+31);
	right_bit_shift_n(63, f_sum+592, 56);
	GF2X_MUL(64, temp, 32, f_sum+392+31, 32, p_10+200);
	GF2X_MUL(64, temp2, 32, g_sum+392+31, 32, p_11+200);
	gf2x_add(63, g_sum+592, 63, temp+1, 63, temp2+1);
	GF2X_MUL(62, temp, 31, p_10+200+1, 31, f_sum+392);
	GF2X_MUL(62, temp2, 31, p_11+200+1, 31, g_sum+392);
	gf2x_add(62, temp, 62, temp, 62, temp2);
	gf2x_add(31, g_sum+592, 31, g_sum+592, 31, temp+31);
	right_bit_shift_n(63, g_sum+592, 56);
	

	delta = divstepsx_256(255, delta, f_sum+620, g_sum+620, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+616+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+616+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+616+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+616+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+616+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+616+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+616+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+616+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+608+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+608+8, 8, p_01+256);
	gf2x_add(16, f_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+608+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+608+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+754, 8, f_sum+754, 8, temp+8);
	right_bit_shift_n(16, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+608+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+608+8, 8, p_11+256);
	gf2x_add(16, g_sum+754+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+608+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+608+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+754, 8, g_sum+754, 8, temp+8);
	right_bit_shift_n(16, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+759, g_sum+759, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+755+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, q_00+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, q_01+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, q_10+238+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, q_11+238+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 4
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_10+256);
	gf2x_add(16, p_00+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+238+0, 8, p_11+256);
	gf2x_add(16, p_01+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_10+256);
	gf2x_add(16, p_10+236+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+238+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+238+0, 8, p_11+256);
	gf2x_add(16, p_11+236+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1938, depth: 3
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+593+15, 16, p_00+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+15, 16, p_01+236);
	gf2x_add(31, f_sum+697, 31, temp+1, 31, temp2+1);
	GF2X_MUL(30, temp, 15, p_00+236+1, 15, f_sum+593);
	GF2X_MUL(30, temp2, 15, p_01+236+1, 15, g_sum+593);
	gf2x_add(30, temp, 30, temp, 30, temp2);
	gf2x_add(15, f_sum+697, 15, f_sum+697, 15, temp+15);
	right_bit_shift_n(31, f_sum+697, 60);
	GF2X_MUL(32, temp, 16, f_sum+593+15, 16, p_10+236);
	GF2X_MUL(32, temp2, 16, g_sum+593+15, 16, p_11+236);
	gf2x_add(31, g_sum+697, 31, temp+1, 31, temp2+1);
	GF2X_MUL(30, temp, 15, p_10+236+1, 15, f_sum+593);
	GF2X_MUL(30, temp2, 15, p_11+236+1, 15, g_sum+593);
	gf2x_add(30, temp, 30, temp, 30, temp2);
	gf2x_add(15, g_sum+697, 15, g_sum+697, 15, temp+15);
	right_bit_shift_n(31, g_sum+697, 60);
	

	delta = divstepsx_256(255, delta, f_sum+709, g_sum+709, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+705+4, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+705+4, 4, p_01+268);
	gf2x_add(8, f_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+705+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+705+0, 4, p_01+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+787, 4, f_sum+787, 4, temp+4);
	right_bit_shift_n(8, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+705+4, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+705+4, 4, p_11+268);
	gf2x_add(8, g_sum+787+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+705+0, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+705+0, 4, p_11+268);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+787, 4, g_sum+787, 4, temp+4);
	right_bit_shift_n(8, g_sum+787, 63);
	

	delta = divstepsx_256(255, delta, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_10+268);
	gf2x_add(8, p_00+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_01+246+0, 4, p_11+268);
	gf2x_add(8, p_01+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_10+268);
	gf2x_add(8, p_10+256+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+246+0, 4, p_01+268);
	GF2X_MUL(8, temp2, 4, q_11+246+0, 4, p_11+268);
	gf2x_add(8, p_11+256+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 918, depth: 4
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+698+7, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+7, 8, p_01+256);
	gf2x_add(15, f_sum+754, 15, temp+1, 15, temp2+1);
	GF2X_MUL(14, temp, 7, p_00+256+1, 7, f_sum+698);
	GF2X_MUL(14, temp2, 7, p_01+256+1, 7, g_sum+698);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, f_sum+754, 7, f_sum+754, 7, temp+7);
	right_bit_shift_n(15, f_sum+754, 62);
	GF2X_MUL(16, temp, 8, f_sum+698+7, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+698+7, 8, p_11+256);
	gf2x_add(15, g_sum+754, 15, temp+1, 15, temp2+1);
	GF2X_MUL(14, temp, 7, p_10+256+1, 7, f_sum+698);
	GF2X_MUL(14, temp2, 7, p_11+256+1, 7, g_sum+698);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, g_sum+754, 7, g_sum+754, 7, temp+7);
	right_bit_shift_n(15, g_sum+754, 62);
	

	delta = divstepsx_256(255, delta, f_sum+758, g_sum+758, p_00+268, p_01+268, p_10+268, p_11+268);

	// Calculating left operands: n: 408, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+755+3, 4, p_00+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+3, 4, p_01+268);
	gf2x_add(7, f_sum+787, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_00+268+1, 3, f_sum+755);
	GF2X_MUL(6, temp2, 3, p_01+268+1, 3, g_sum+755);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, f_sum+787, 3, f_sum+787, 3, temp+3);
	right_bit_shift_n(7, f_sum+787, 63);
	GF2X_MUL(8, temp, 4, f_sum+755+3, 4, p_10+268);
	GF2X_MUL(8, temp2, 4, g_sum+755+3, 4, p_11+268);
	gf2x_add(7, g_sum+787, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_10+268+1, 3, f_sum+755);
	GF2X_MUL(6, temp2, 3, p_11+268+1, 3, g_sum+755);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, g_sum+787, 3, g_sum+787, 3, temp+3);
	right_bit_shift_n(7, g_sum+787, 63);
	

	delta = support_jumpdivstep(153, delta, 3, f_sum+788, g_sum+788, q_00+246, q_01+246, q_10+246, q_11+246, x);

	// Recombining results: n: 408, depth: 5
	memset(q_00+238, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+268+1, 3, q_00+246);
	GF2X_MUL(6, temp2, 3, p_10+268+1, 3, q_01+246);
	gf2x_add(6, q_00+238+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+246+2, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_01+246+2, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+238+2, 2, q_00+238+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+246+1, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_01+246+1, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+238+1, 2, q_00+238+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+246+0, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_01+246+0, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+238+0, 2, q_00+238+0, 2, temp);
	memset(q_01+238, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+268+1, 3, q_00+246);
	GF2X_MUL(6, temp2, 3, p_11+268+1, 3, q_01+246);
	gf2x_add(6, q_01+238+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+246+2, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_01+246+2, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+238+2, 2, q_01+238+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+246+1, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_01+246+1, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+238+1, 2, q_01+238+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+246+0, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_01+246+0, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+238+0, 2, q_01+238+0, 2, temp);
	memset(q_10+238, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+268+1, 3, q_10+246);
	GF2X_MUL(6, temp2, 3, p_10+268+1, 3, q_11+246);
	gf2x_add(6, q_10+238+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+246+2, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_11+246+2, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+238+2, 2, q_10+238+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+246+1, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_11+246+1, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+238+1, 2, q_10+238+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+246+0, 1, p_00+268);
	GF2X_MUL(2, temp2, 1, q_11+246+0, 1, p_10+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+238+0, 2, q_10+238+0, 2, temp);
	memset(q_11+238, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+268+1, 3, q_10+246);
	GF2X_MUL(6, temp2, 3, p_11+268+1, 3, q_11+246);
	gf2x_add(6, q_11+238+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+246+2, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_11+246+2, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+238+2, 2, q_11+238+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+246+1, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_11+246+1, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+238+1, 2, q_11+238+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+246+0, 1, p_01+268);
	GF2X_MUL(2, temp2, 1, q_11+246+0, 1, p_11+268);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+238+0, 2, q_11+238+0, 2, temp);
	

	// Recombining results: n: 918, depth: 4
	memset(q_00+222, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+256+1, 7, q_00+238);
	GF2X_MUL(14, temp2, 7, p_10+256+1, 7, q_01+238);
	gf2x_add(14, q_00+222+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_00+238+6, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+6, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+6, 2, q_00+222+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+5, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+5, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+5, 2, q_00+222+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+4, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+4, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+4, 2, q_00+222+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+3, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+3, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+3, 2, q_00+222+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+2, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+2, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+2, 2, q_00+222+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+1, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+1, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+1, 2, q_00+222+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+0, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+238+0, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+222+0, 2, q_00+222+0, 2, temp);
	memset(q_01+222, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+256+1, 7, q_00+238);
	GF2X_MUL(14, temp2, 7, p_11+256+1, 7, q_01+238);
	gf2x_add(14, q_01+222+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_00+238+6, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+6, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+6, 2, q_01+222+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+5, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+5, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+5, 2, q_01+222+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+4, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+4, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+4, 2, q_01+222+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+3, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+3, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+3, 2, q_01+222+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+2, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+2, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+2, 2, q_01+222+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+1, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+1, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+1, 2, q_01+222+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+238+0, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+238+0, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+222+0, 2, q_01+222+0, 2, temp);
	memset(q_10+222, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+256+1, 7, q_10+238);
	GF2X_MUL(14, temp2, 7, p_10+256+1, 7, q_11+238);
	gf2x_add(14, q_10+222+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_10+238+6, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+6, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+6, 2, q_10+222+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+5, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+5, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+5, 2, q_10+222+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+4, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+4, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+4, 2, q_10+222+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+3, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+3, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+3, 2, q_10+222+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+2, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+2, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+2, 2, q_10+222+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+1, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+1, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+1, 2, q_10+222+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+0, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+238+0, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+222+0, 2, q_10+222+0, 2, temp);
	memset(q_11+222, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+256+1, 7, q_10+238);
	GF2X_MUL(14, temp2, 7, p_11+256+1, 7, q_11+238);
	gf2x_add(14, q_11+222+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_10+238+6, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+6, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+6, 2, q_11+222+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+5, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+5, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+5, 2, q_11+222+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+4, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+4, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+4, 2, q_11+222+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+3, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+3, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+3, 2, q_11+222+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+2, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+2, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+2, 2, q_11+222+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+1, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+1, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+1, 2, q_11+222+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+238+0, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+238+0, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+222+0, 2, q_11+222+0, 2, temp);
	

	// Recombining results: n: 1938, depth: 3
	memset(q_00+190, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_00+236+1, 15, q_00+222);
	GF2X_MUL(30, temp2, 15, p_10+236+1, 15, q_01+222);
	gf2x_add(30, q_00+190+1, 30, temp, 30, temp2);
	GF2X_MUL(2, temp, 1, q_00+222+14, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+14, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+14, 2, q_00+190+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+13, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+13, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+13, 2, q_00+190+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+12, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+12, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+12, 2, q_00+190+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+11, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+11, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+11, 2, q_00+190+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+10, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+10, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+10, 2, q_00+190+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+9, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+9, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+9, 2, q_00+190+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+8, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+8, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+8, 2, q_00+190+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+7, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+7, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+7, 2, q_00+190+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+6, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+6, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+6, 2, q_00+190+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+5, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+5, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+5, 2, q_00+190+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+4, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+4, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+4, 2, q_00+190+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+3, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+3, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+3, 2, q_00+190+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+2, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+2, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+2, 2, q_00+190+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+1, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+1, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+1, 2, q_00+190+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+0, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_01+222+0, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+190+0, 2, q_00+190+0, 2, temp);
	memset(q_01+190, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_01+236+1, 15, q_00+222);
	GF2X_MUL(30, temp2, 15, p_11+236+1, 15, q_01+222);
	gf2x_add(30, q_01+190+1, 30, temp, 30, temp2);
	GF2X_MUL(2, temp, 1, q_00+222+14, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+14, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+14, 2, q_01+190+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+13, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+13, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+13, 2, q_01+190+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+12, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+12, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+12, 2, q_01+190+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+11, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+11, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+11, 2, q_01+190+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+10, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+10, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+10, 2, q_01+190+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+9, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+9, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+9, 2, q_01+190+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+8, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+8, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+8, 2, q_01+190+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+7, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+7, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+7, 2, q_01+190+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+6, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+6, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+6, 2, q_01+190+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+5, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+5, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+5, 2, q_01+190+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+4, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+4, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+4, 2, q_01+190+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+3, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+3, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+3, 2, q_01+190+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+2, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+2, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+2, 2, q_01+190+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+1, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+1, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+1, 2, q_01+190+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+222+0, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_01+222+0, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+190+0, 2, q_01+190+0, 2, temp);
	memset(q_10+190, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_00+236+1, 15, q_10+222);
	GF2X_MUL(30, temp2, 15, p_10+236+1, 15, q_11+222);
	gf2x_add(30, q_10+190+1, 30, temp, 30, temp2);
	GF2X_MUL(2, temp, 1, q_10+222+14, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+14, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+14, 2, q_10+190+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+13, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+13, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+13, 2, q_10+190+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+12, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+12, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+12, 2, q_10+190+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+11, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+11, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+11, 2, q_10+190+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+10, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+10, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+10, 2, q_10+190+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+9, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+9, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+9, 2, q_10+190+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+8, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+8, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+8, 2, q_10+190+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+7, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+7, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+7, 2, q_10+190+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+6, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+6, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+6, 2, q_10+190+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+5, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+5, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+5, 2, q_10+190+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+4, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+4, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+4, 2, q_10+190+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+3, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+3, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+3, 2, q_10+190+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+2, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+2, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+2, 2, q_10+190+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+1, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+1, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+1, 2, q_10+190+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+0, 1, p_00+236);
	GF2X_MUL(2, temp2, 1, q_11+222+0, 1, p_10+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+190+0, 2, q_10+190+0, 2, temp);
	memset(q_11+190, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_01+236+1, 15, q_10+222);
	GF2X_MUL(30, temp2, 15, p_11+236+1, 15, q_11+222);
	gf2x_add(30, q_11+190+1, 30, temp, 30, temp2);
	GF2X_MUL(2, temp, 1, q_10+222+14, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+14, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+14, 2, q_11+190+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+13, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+13, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+13, 2, q_11+190+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+12, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+12, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+12, 2, q_11+190+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+11, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+11, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+11, 2, q_11+190+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+10, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+10, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+10, 2, q_11+190+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+9, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+9, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+9, 2, q_11+190+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+8, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+8, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+8, 2, q_11+190+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+7, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+7, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+7, 2, q_11+190+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+6, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+6, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+6, 2, q_11+190+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+5, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+5, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+5, 2, q_11+190+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+4, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+4, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+4, 2, q_11+190+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+3, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+3, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+3, 2, q_11+190+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+2, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+2, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+2, 2, q_11+190+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+1, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+1, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+1, 2, q_11+190+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+222+0, 1, p_01+236);
	GF2X_MUL(2, temp2, 1, q_11+222+0, 1, p_11+236);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+190+0, 2, q_11+190+0, 2, temp);
	

	// Recombining results: n: 3978, depth: 2
	memset(q_00+126, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, p_00+200+1, 31, q_00+190);
	GF2X_MUL(62, temp2, 31, p_10+200+1, 31, q_01+190);
	gf2x_add(62, q_00+126+1, 62, temp, 62, temp2);
	GF2X_MUL(2, temp, 1, q_00+190+30, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+30, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+30, 2, q_00+126+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+29, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+29, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+29, 2, q_00+126+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+28, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+28, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+28, 2, q_00+126+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+27, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+27, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+27, 2, q_00+126+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+26, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+26, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+26, 2, q_00+126+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+25, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+25, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+25, 2, q_00+126+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+24, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+24, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+24, 2, q_00+126+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+23, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+23, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+23, 2, q_00+126+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+22, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+22, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+22, 2, q_00+126+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+21, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+21, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+21, 2, q_00+126+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+20, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+20, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+20, 2, q_00+126+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+19, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+19, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+19, 2, q_00+126+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+18, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+18, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+18, 2, q_00+126+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+17, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+17, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+17, 2, q_00+126+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+16, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+16, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+16, 2, q_00+126+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+15, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+15, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+15, 2, q_00+126+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+14, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+14, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+14, 2, q_00+126+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+13, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+13, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+13, 2, q_00+126+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+12, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+12, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+12, 2, q_00+126+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+11, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+11, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+11, 2, q_00+126+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+10, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+10, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+10, 2, q_00+126+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+9, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+9, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+9, 2, q_00+126+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+8, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+8, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+8, 2, q_00+126+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+7, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+7, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+7, 2, q_00+126+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+6, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+6, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+6, 2, q_00+126+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+5, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+5, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+5, 2, q_00+126+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+4, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+4, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+4, 2, q_00+126+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+3, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+3, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+3, 2, q_00+126+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+2, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+2, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+2, 2, q_00+126+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+1, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+1, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+1, 2, q_00+126+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+0, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_01+190+0, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+126+0, 2, q_00+126+0, 2, temp);
	memset(q_01+126, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, p_01+200+1, 31, q_00+190);
	GF2X_MUL(62, temp2, 31, p_11+200+1, 31, q_01+190);
	gf2x_add(62, q_01+126+1, 62, temp, 62, temp2);
	GF2X_MUL(2, temp, 1, q_00+190+30, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+30, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+30, 2, q_01+126+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+29, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+29, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+29, 2, q_01+126+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+28, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+28, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+28, 2, q_01+126+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+27, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+27, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+27, 2, q_01+126+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+26, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+26, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+26, 2, q_01+126+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+25, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+25, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+25, 2, q_01+126+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+24, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+24, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+24, 2, q_01+126+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+23, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+23, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+23, 2, q_01+126+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+22, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+22, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+22, 2, q_01+126+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+21, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+21, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+21, 2, q_01+126+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+20, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+20, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+20, 2, q_01+126+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+19, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+19, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+19, 2, q_01+126+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+18, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+18, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+18, 2, q_01+126+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+17, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+17, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+17, 2, q_01+126+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+16, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+16, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+16, 2, q_01+126+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+15, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+15, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+15, 2, q_01+126+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+14, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+14, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+14, 2, q_01+126+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+13, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+13, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+13, 2, q_01+126+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+12, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+12, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+12, 2, q_01+126+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+11, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+11, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+11, 2, q_01+126+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+10, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+10, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+10, 2, q_01+126+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+9, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+9, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+9, 2, q_01+126+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+8, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+8, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+8, 2, q_01+126+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+7, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+7, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+7, 2, q_01+126+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+6, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+6, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+6, 2, q_01+126+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+5, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+5, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+5, 2, q_01+126+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+4, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+4, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+4, 2, q_01+126+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+3, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+3, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+3, 2, q_01+126+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+2, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+2, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+2, 2, q_01+126+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+1, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+1, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+1, 2, q_01+126+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+190+0, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_01+190+0, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+126+0, 2, q_01+126+0, 2, temp);
	memset(q_10+126, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, p_00+200+1, 31, q_10+190);
	GF2X_MUL(62, temp2, 31, p_10+200+1, 31, q_11+190);
	gf2x_add(62, q_10+126+1, 62, temp, 62, temp2);
	GF2X_MUL(2, temp, 1, q_10+190+30, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+30, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+30, 2, q_10+126+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+29, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+29, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+29, 2, q_10+126+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+28, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+28, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+28, 2, q_10+126+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+27, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+27, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+27, 2, q_10+126+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+26, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+26, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+26, 2, q_10+126+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+25, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+25, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+25, 2, q_10+126+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+24, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+24, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+24, 2, q_10+126+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+23, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+23, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+23, 2, q_10+126+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+22, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+22, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+22, 2, q_10+126+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+21, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+21, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+21, 2, q_10+126+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+20, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+20, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+20, 2, q_10+126+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+19, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+19, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+19, 2, q_10+126+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+18, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+18, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+18, 2, q_10+126+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+17, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+17, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+17, 2, q_10+126+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+16, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+16, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+16, 2, q_10+126+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+15, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+15, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+15, 2, q_10+126+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+14, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+14, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+14, 2, q_10+126+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+13, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+13, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+13, 2, q_10+126+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+12, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+12, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+12, 2, q_10+126+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+11, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+11, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+11, 2, q_10+126+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+10, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+10, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+10, 2, q_10+126+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+9, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+9, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+9, 2, q_10+126+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+8, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+8, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+8, 2, q_10+126+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+7, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+7, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+7, 2, q_10+126+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+6, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+6, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+6, 2, q_10+126+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+5, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+5, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+5, 2, q_10+126+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+4, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+4, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+4, 2, q_10+126+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+3, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+3, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+3, 2, q_10+126+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+2, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+2, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+2, 2, q_10+126+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+1, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+1, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+1, 2, q_10+126+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+0, 1, p_00+200);
	GF2X_MUL(2, temp2, 1, q_11+190+0, 1, p_10+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+126+0, 2, q_10+126+0, 2, temp);
	memset(q_11+126, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(62, temp, 31, p_01+200+1, 31, q_10+190);
	GF2X_MUL(62, temp2, 31, p_11+200+1, 31, q_11+190);
	gf2x_add(62, q_11+126+1, 62, temp, 62, temp2);
	GF2X_MUL(2, temp, 1, q_10+190+30, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+30, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+30, 2, q_11+126+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+29, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+29, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+29, 2, q_11+126+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+28, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+28, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+28, 2, q_11+126+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+27, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+27, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+27, 2, q_11+126+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+26, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+26, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+26, 2, q_11+126+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+25, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+25, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+25, 2, q_11+126+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+24, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+24, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+24, 2, q_11+126+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+23, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+23, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+23, 2, q_11+126+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+22, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+22, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+22, 2, q_11+126+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+21, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+21, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+21, 2, q_11+126+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+20, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+20, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+20, 2, q_11+126+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+19, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+19, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+19, 2, q_11+126+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+18, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+18, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+18, 2, q_11+126+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+17, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+17, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+17, 2, q_11+126+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+16, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+16, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+16, 2, q_11+126+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+15, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+15, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+15, 2, q_11+126+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+14, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+14, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+14, 2, q_11+126+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+13, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+13, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+13, 2, q_11+126+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+12, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+12, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+12, 2, q_11+126+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+11, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+11, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+11, 2, q_11+126+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+10, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+10, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+10, 2, q_11+126+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+9, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+9, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+9, 2, q_11+126+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+8, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+8, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+8, 2, q_11+126+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+7, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+7, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+7, 2, q_11+126+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+6, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+6, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+6, 2, q_11+126+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+5, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+5, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+5, 2, q_11+126+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+4, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+4, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+4, 2, q_11+126+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+3, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+3, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+3, 2, q_11+126+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+2, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+2, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+2, 2, q_11+126+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+1, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+1, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+1, 2, q_11+126+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+190+0, 1, p_01+200);
	GF2X_MUL(2, temp2, 1, q_11+190+0, 1, p_11+200);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+126+0, 2, q_11+126+0, 2, temp);
	

	// Recombining results: n: 8058, depth: 1
	GF2X_MUL(126, temp, 63, p_00+132+1, 63, q_00+126);
	GF2X_MUL(126, temp2, 63, p_10+132+1, 63, q_01+126);
	gf2x_add(126, q_00+0+0, 126, temp, 126, temp2);
	GF2X_MUL(2, temp, 1, q_00+126+62, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+62, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+61, 2, q_00+0+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+61, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+61, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+60, 2, q_00+0+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+60, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+60, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+59, 2, q_00+0+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+59, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+59, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+58, 2, q_00+0+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+58, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+58, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+57, 2, q_00+0+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+57, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+57, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+56, 2, q_00+0+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+56, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+56, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+55, 2, q_00+0+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+55, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+55, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+54, 2, q_00+0+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+54, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+54, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+53, 2, q_00+0+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+53, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+53, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+52, 2, q_00+0+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+52, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+52, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+51, 2, q_00+0+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+51, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+51, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+50, 2, q_00+0+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+50, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+50, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+49, 2, q_00+0+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+49, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+49, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+48, 2, q_00+0+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+48, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+48, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+47, 2, q_00+0+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+47, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+47, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+46, 2, q_00+0+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+46, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+46, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+45, 2, q_00+0+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+45, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+45, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+44, 2, q_00+0+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+44, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+44, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+43, 2, q_00+0+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+43, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+43, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+42, 2, q_00+0+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+42, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+42, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+41, 2, q_00+0+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+41, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+41, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+40, 2, q_00+0+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+40, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+40, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+39, 2, q_00+0+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+39, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+39, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+38, 2, q_00+0+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+38, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+38, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+37, 2, q_00+0+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+37, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+37, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+36, 2, q_00+0+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+36, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+36, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+35, 2, q_00+0+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+35, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+35, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+34, 2, q_00+0+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+34, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+34, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+33, 2, q_00+0+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+33, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+33, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+32, 2, q_00+0+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+32, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+32, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+31, 2, q_00+0+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+31, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+31, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+30, 2, q_00+0+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+30, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+30, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+29, 2, q_00+0+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+29, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+29, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+28, 2, q_00+0+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+28, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+28, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+27, 2, q_00+0+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+27, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+27, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+26, 2, q_00+0+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+26, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+26, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+25, 2, q_00+0+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+25, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+25, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+24, 2, q_00+0+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+24, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+24, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+23, 2, q_00+0+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+23, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+23, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+22, 2, q_00+0+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+22, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+22, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+21, 2, q_00+0+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+21, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+21, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+20, 2, q_00+0+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+20, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+20, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+19, 2, q_00+0+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+19, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+19, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+18, 2, q_00+0+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+18, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+18, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+17, 2, q_00+0+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+17, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+17, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+16, 2, q_00+0+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+16, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+16, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+15, 2, q_00+0+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+15, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+15, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+14, 2, q_00+0+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+14, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+14, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+13, 2, q_00+0+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+13, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+13, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+12, 2, q_00+0+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+12, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+12, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+11, 2, q_00+0+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+11, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+11, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+10, 2, q_00+0+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+10, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+10, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+9, 2, q_00+0+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+9, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+9, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+8, 2, q_00+0+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+8, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+8, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+7, 2, q_00+0+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+7, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+7, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+6, 2, q_00+0+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+6, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+6, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+5, 2, q_00+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+5, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+5, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+4, 2, q_00+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+4, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+4, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+3, 2, q_00+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+3, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+3, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+2, 2, q_00+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+2, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+2, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+1, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+1, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+0, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_01+126+0, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+0, 1, q_00+0, 1, temp+1);
	GF2X_MUL(126, temp, 63, p_01+132+1, 63, q_00+126);
	GF2X_MUL(126, temp2, 63, p_11+132+1, 63, q_01+126);
	gf2x_add(126, q_01+0+0, 126, temp, 126, temp2);
	GF2X_MUL(2, temp, 1, q_00+126+62, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+62, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+61, 2, q_01+0+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+61, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+61, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+60, 2, q_01+0+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+60, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+60, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+59, 2, q_01+0+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+59, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+59, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+58, 2, q_01+0+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+58, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+58, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+57, 2, q_01+0+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+57, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+57, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+56, 2, q_01+0+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+56, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+56, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+55, 2, q_01+0+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+55, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+55, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+54, 2, q_01+0+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+54, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+54, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+53, 2, q_01+0+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+53, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+53, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+52, 2, q_01+0+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+52, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+52, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+51, 2, q_01+0+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+51, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+51, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+50, 2, q_01+0+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+50, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+50, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+49, 2, q_01+0+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+49, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+49, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+48, 2, q_01+0+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+48, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+48, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+47, 2, q_01+0+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+47, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+47, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+46, 2, q_01+0+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+46, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+46, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+45, 2, q_01+0+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+45, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+45, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+44, 2, q_01+0+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+44, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+44, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+43, 2, q_01+0+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+43, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+43, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+42, 2, q_01+0+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+42, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+42, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+41, 2, q_01+0+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+41, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+41, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+40, 2, q_01+0+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+40, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+40, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+39, 2, q_01+0+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+39, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+39, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+38, 2, q_01+0+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+38, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+38, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+37, 2, q_01+0+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+37, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+37, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+36, 2, q_01+0+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+36, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+36, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+35, 2, q_01+0+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+35, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+35, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+34, 2, q_01+0+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+34, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+34, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+33, 2, q_01+0+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+33, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+33, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+32, 2, q_01+0+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+32, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+32, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+31, 2, q_01+0+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+31, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+31, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+30, 2, q_01+0+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+30, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+30, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+29, 2, q_01+0+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+29, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+29, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+28, 2, q_01+0+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+28, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+28, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+27, 2, q_01+0+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+27, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+27, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+26, 2, q_01+0+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+26, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+26, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+25, 2, q_01+0+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+25, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+25, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+24, 2, q_01+0+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+24, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+24, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+23, 2, q_01+0+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+23, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+23, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+22, 2, q_01+0+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+22, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+22, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+21, 2, q_01+0+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+21, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+21, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+20, 2, q_01+0+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+20, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+20, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+19, 2, q_01+0+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+19, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+19, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+18, 2, q_01+0+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+18, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+18, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+17, 2, q_01+0+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+17, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+17, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+16, 2, q_01+0+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+16, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+16, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+15, 2, q_01+0+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+15, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+15, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+14, 2, q_01+0+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+14, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+14, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+13, 2, q_01+0+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+13, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+13, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+12, 2, q_01+0+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+12, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+12, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+11, 2, q_01+0+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+11, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+11, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+10, 2, q_01+0+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+10, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+10, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+9, 2, q_01+0+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+9, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+9, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+8, 2, q_01+0+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+8, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+8, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+7, 2, q_01+0+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+7, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+7, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+6, 2, q_01+0+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+6, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+6, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+5, 2, q_01+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+5, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+5, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+4, 2, q_01+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+4, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+4, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+3, 2, q_01+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+3, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+3, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+2, 2, q_01+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+2, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+2, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+1, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+1, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+126+0, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_01+126+0, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+0, 1, q_01+0, 1, temp+1);
	GF2X_MUL(126, temp, 63, p_00+132+1, 63, q_10+126);
	GF2X_MUL(126, temp2, 63, p_10+132+1, 63, q_11+126);
	gf2x_add(126, q_10+0+0, 126, temp, 126, temp2);
	GF2X_MUL(2, temp, 1, q_10+126+62, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+62, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+61, 2, q_10+0+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+61, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+61, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+60, 2, q_10+0+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+60, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+60, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+59, 2, q_10+0+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+59, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+59, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+58, 2, q_10+0+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+58, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+58, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+57, 2, q_10+0+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+57, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+57, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+56, 2, q_10+0+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+56, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+56, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+55, 2, q_10+0+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+55, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+55, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+54, 2, q_10+0+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+54, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+54, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+53, 2, q_10+0+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+53, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+53, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+52, 2, q_10+0+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+52, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+52, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+51, 2, q_10+0+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+51, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+51, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+50, 2, q_10+0+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+50, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+50, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+49, 2, q_10+0+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+49, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+49, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+48, 2, q_10+0+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+48, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+48, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+47, 2, q_10+0+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+47, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+47, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+46, 2, q_10+0+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+46, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+46, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+45, 2, q_10+0+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+45, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+45, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+44, 2, q_10+0+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+44, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+44, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+43, 2, q_10+0+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+43, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+43, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+42, 2, q_10+0+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+42, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+42, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+41, 2, q_10+0+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+41, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+41, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+40, 2, q_10+0+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+40, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+40, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+39, 2, q_10+0+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+39, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+39, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+38, 2, q_10+0+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+38, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+38, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+37, 2, q_10+0+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+37, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+37, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+36, 2, q_10+0+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+36, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+36, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+35, 2, q_10+0+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+35, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+35, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+34, 2, q_10+0+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+34, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+34, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+33, 2, q_10+0+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+33, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+33, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+32, 2, q_10+0+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+32, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+32, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+31, 2, q_10+0+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+31, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+31, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+30, 2, q_10+0+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+30, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+30, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+29, 2, q_10+0+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+29, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+29, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+28, 2, q_10+0+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+28, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+28, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+27, 2, q_10+0+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+27, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+27, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+26, 2, q_10+0+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+26, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+26, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+25, 2, q_10+0+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+25, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+25, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+24, 2, q_10+0+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+24, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+24, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+23, 2, q_10+0+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+23, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+23, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+22, 2, q_10+0+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+22, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+22, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+21, 2, q_10+0+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+21, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+21, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+20, 2, q_10+0+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+20, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+20, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+19, 2, q_10+0+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+19, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+19, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+18, 2, q_10+0+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+18, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+18, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+17, 2, q_10+0+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+17, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+17, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+16, 2, q_10+0+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+16, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+16, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+15, 2, q_10+0+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+15, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+15, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+14, 2, q_10+0+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+14, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+14, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+13, 2, q_10+0+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+13, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+13, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+12, 2, q_10+0+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+12, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+12, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+11, 2, q_10+0+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+11, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+11, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+10, 2, q_10+0+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+10, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+10, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+9, 2, q_10+0+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+9, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+9, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+8, 2, q_10+0+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+8, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+8, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+7, 2, q_10+0+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+7, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+7, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+6, 2, q_10+0+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+6, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+6, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+5, 2, q_10+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+5, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+5, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+4, 2, q_10+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+4, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+4, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+3, 2, q_10+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+3, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+3, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+2, 2, q_10+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+2, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+2, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+1, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+1, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+0, 1, p_00+132);
	GF2X_MUL(2, temp2, 1, q_11+126+0, 1, p_10+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+0, 1, q_10+0, 1, temp+1);
	GF2X_MUL(126, temp, 63, p_01+132+1, 63, q_10+126);
	GF2X_MUL(126, temp2, 63, p_11+132+1, 63, q_11+126);
	gf2x_add(126, q_11+0+0, 126, temp, 126, temp2);
	GF2X_MUL(2, temp, 1, q_10+126+62, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+62, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+61, 2, q_11+0+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+61, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+61, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+60, 2, q_11+0+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+60, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+60, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+59, 2, q_11+0+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+59, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+59, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+58, 2, q_11+0+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+58, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+58, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+57, 2, q_11+0+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+57, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+57, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+56, 2, q_11+0+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+56, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+56, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+55, 2, q_11+0+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+55, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+55, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+54, 2, q_11+0+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+54, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+54, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+53, 2, q_11+0+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+53, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+53, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+52, 2, q_11+0+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+52, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+52, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+51, 2, q_11+0+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+51, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+51, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+50, 2, q_11+0+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+50, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+50, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+49, 2, q_11+0+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+49, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+49, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+48, 2, q_11+0+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+48, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+48, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+47, 2, q_11+0+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+47, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+47, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+46, 2, q_11+0+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+46, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+46, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+45, 2, q_11+0+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+45, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+45, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+44, 2, q_11+0+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+44, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+44, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+43, 2, q_11+0+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+43, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+43, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+42, 2, q_11+0+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+42, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+42, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+41, 2, q_11+0+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+41, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+41, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+40, 2, q_11+0+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+40, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+40, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+39, 2, q_11+0+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+39, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+39, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+38, 2, q_11+0+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+38, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+38, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+37, 2, q_11+0+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+37, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+37, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+36, 2, q_11+0+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+36, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+36, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+35, 2, q_11+0+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+35, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+35, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+34, 2, q_11+0+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+34, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+34, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+33, 2, q_11+0+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+33, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+33, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+32, 2, q_11+0+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+32, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+32, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+31, 2, q_11+0+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+31, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+31, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+30, 2, q_11+0+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+30, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+30, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+29, 2, q_11+0+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+29, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+29, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+28, 2, q_11+0+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+28, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+28, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+27, 2, q_11+0+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+27, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+27, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+26, 2, q_11+0+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+26, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+26, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+25, 2, q_11+0+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+25, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+25, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+24, 2, q_11+0+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+24, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+24, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+23, 2, q_11+0+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+23, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+23, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+22, 2, q_11+0+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+22, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+22, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+21, 2, q_11+0+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+21, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+21, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+20, 2, q_11+0+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+20, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+20, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+19, 2, q_11+0+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+19, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+19, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+18, 2, q_11+0+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+18, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+18, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+17, 2, q_11+0+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+17, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+17, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+16, 2, q_11+0+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+16, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+16, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+15, 2, q_11+0+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+15, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+15, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+14, 2, q_11+0+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+14, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+14, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+13, 2, q_11+0+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+13, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+13, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+12, 2, q_11+0+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+12, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+12, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+11, 2, q_11+0+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+11, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+11, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+10, 2, q_11+0+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+10, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+10, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+9, 2, q_11+0+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+9, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+9, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+8, 2, q_11+0+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+8, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+8, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+7, 2, q_11+0+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+7, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+7, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+6, 2, q_11+0+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+6, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+6, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+5, 2, q_11+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+5, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+5, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+4, 2, q_11+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+4, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+4, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+3, 2, q_11+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+3, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+3, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+2, 2, q_11+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+2, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+2, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+1, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+1, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+126+0, 1, p_01+132);
	GF2X_MUL(2, temp2, 1, q_11+126+0, 1, p_11+132);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+0, 1, q_11+0, 1, temp+1);
	

	// Recombining results: n: 16473, depth: 0
	memset(t_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, p_00+0+6, 126, q_00+0);
	GF2X_MUL(252, temp2, 126, p_10+0+6, 126, q_01+0);
	gf2x_add(252, t_00+0+6, 252, temp, 252, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+120, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+120, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+120, 12, t_00+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+114, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+114, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+114, 12, t_00+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+108, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+108, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+108, 12, t_00+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+102, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+102, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+102, 12, t_00+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+96, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+96, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+96, 12, t_00+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+90, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+90, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+90, 12, t_00+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+84, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+84, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+84, 12, t_00+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+78, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+78, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+78, 12, t_00+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+72, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+72, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+72, 12, t_00+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+66, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+66, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+66, 12, t_00+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+60, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+60, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+60, 12, t_00+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+54, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+54, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+54, 12, t_00+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+48, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+48, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+48, 12, t_00+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+42, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+42, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+42, 12, t_00+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+36, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+36, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+36, 12, t_00+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+30, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+30, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+30, 12, t_00+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+24, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+24, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+24, 12, t_00+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+18, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+18, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+18, 12, t_00+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+12, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+12, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+12, 12, t_00+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+6, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+6, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+6, 12, t_00+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+0, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+0, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+0, 12, t_00+0+0, 12, temp);
	memset(t_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, p_01+0+6, 126, q_00+0);
	GF2X_MUL(252, temp2, 126, p_11+0+6, 126, q_01+0);
	gf2x_add(252, t_01+0+6, 252, temp, 252, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+120, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+120, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+120, 12, t_01+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+114, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+114, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+114, 12, t_01+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+108, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+108, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+108, 12, t_01+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+102, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+102, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+102, 12, t_01+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+96, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+96, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+96, 12, t_01+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+90, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+90, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+90, 12, t_01+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+84, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+84, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+84, 12, t_01+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+78, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+78, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+78, 12, t_01+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+72, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+72, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+72, 12, t_01+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+66, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+66, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+66, 12, t_01+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+60, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+60, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+60, 12, t_01+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+54, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+54, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+54, 12, t_01+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+48, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+48, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+48, 12, t_01+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+42, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+42, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+42, 12, t_01+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+36, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+36, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+36, 12, t_01+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+30, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+30, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+30, 12, t_01+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+24, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+24, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+24, 12, t_01+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+18, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+18, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+18, 12, t_01+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+12, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+12, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+12, 12, t_01+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+6, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+6, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+6, 12, t_01+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+0, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+0, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+0, 12, t_01+0+0, 12, temp);
	memset(t_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, p_00+0+6, 126, q_10+0);
	GF2X_MUL(252, temp2, 126, p_10+0+6, 126, q_11+0);
	gf2x_add(252, t_10+0+6, 252, temp, 252, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+120, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+120, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+120, 12, t_10+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+114, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+114, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+114, 12, t_10+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+108, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+108, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+108, 12, t_10+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+102, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+102, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+102, 12, t_10+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+96, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+96, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+96, 12, t_10+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+90, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+90, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+90, 12, t_10+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+84, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+84, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+84, 12, t_10+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+78, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+78, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+78, 12, t_10+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+72, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+72, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+72, 12, t_10+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+66, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+66, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+66, 12, t_10+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+60, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+60, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+60, 12, t_10+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+54, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+54, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+54, 12, t_10+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+48, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+48, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+48, 12, t_10+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+42, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+42, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+42, 12, t_10+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+36, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+36, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+36, 12, t_10+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+30, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+30, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+30, 12, t_10+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+24, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+24, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+24, 12, t_10+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+18, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+18, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+18, 12, t_10+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+12, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+12, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+12, 12, t_10+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+6, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+6, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+6, 12, t_10+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+0, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+0, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+0, 12, t_10+0+0, 12, temp);
	memset(t_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(252, temp, 126, p_01+0+6, 126, q_10+0);
	GF2X_MUL(252, temp2, 126, p_11+0+6, 126, q_11+0);
	gf2x_add(252, t_11+0+6, 252, temp, 252, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+120, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+120, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+120, 12, t_11+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+114, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+114, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+114, 12, t_11+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+108, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+108, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+108, 12, t_11+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+102, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+102, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+102, 12, t_11+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+96, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+96, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+96, 12, t_11+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+90, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+90, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+90, 12, t_11+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+84, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+84, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+84, 12, t_11+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+78, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+78, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+78, 12, t_11+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+72, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+72, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+72, 12, t_11+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+66, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+66, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+66, 12, t_11+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+60, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+60, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+60, 12, t_11+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+54, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+54, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+54, 12, t_11+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+48, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+48, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+48, 12, t_11+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+42, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+42, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+42, 12, t_11+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+36, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+36, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+36, 12, t_11+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+30, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+30, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+30, 12, t_11+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+24, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+24, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+24, 12, t_11+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+18, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+18, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+18, 12, t_11+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+12, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+12, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+12, 12, t_11+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+6, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+6, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+6, 12, t_11+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+0, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+0, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+0, 12, t_11+0+0, 12, temp);
	

	return delta;
}