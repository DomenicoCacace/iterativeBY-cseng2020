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

int jumpdivstep_36629(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[1157];
	DIGIT p_01[1157];
	DIGIT p_10[1157];
	DIGIT p_11[1157];
	
	DIGIT q_00[1142];
	DIGIT q_01[1142];
	DIGIT q_10[1142];
	DIGIT q_11[1142];
	
	DIGIT f_sum[3465];
	DIGIT g_sum[3465];
	
	DIGIT temp[2293];
	DIGIT temp2[2293];
	

	delta = divstepsx_256(255, delta, f+1141, g+1141, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+1137+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g+1137+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1137+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g+1137+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f+1137+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g+1137+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1137+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g+1137+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+1133+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g+1133+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f+1133);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f+1133+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g+1133+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f+1133);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+1125+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g+1125+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f+1125);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g+1125);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f+1125+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g+1125+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f+1125);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g+1125);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f+1109+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g+1109+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f+1109);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g+1109);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f+1109+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g+1109+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f+1109);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g+1109);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f+1073+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g+1073+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f+1073+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g+1073+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f+1073+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g+1073+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f+1073+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g+1073+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f+1001+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g+1001+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f+1001+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g+1001+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f+1001+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g+1001+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f+1001+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g+1001+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, p_00+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, p_01+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, p_10+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, p_11+861+0, 144, temp, 144, temp2);
	

	// Calculating left operands: n: 18360, depth: 2
	// Digits to shift: 143
	// Displacement: 143
	GF2X_MUL(288, temp, 144, f+858+143, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, g+858+143, 144, p_01+861);
	gf2x_add(288, f_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_00+861+1, 143, f+858);
	GF2X_MUL(286, temp2, 143, p_01+861+1, 143, g+858);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, f_sum+2582, 144, f_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f+858+142, 1, p_00+861);
	GF2X_MUL(2, temp2, 1, g+858+142, 1, p_01+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2582, 1, f_sum+2582, 1, temp+1);
	right_bit_shift_n(287, f_sum+2582, 28);
	GF2X_MUL(288, temp, 144, f+858+143, 144, p_10+861);
	GF2X_MUL(288, temp2, 144, g+858+143, 144, p_11+861);
	gf2x_add(288, g_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_10+861+1, 143, f+858);
	GF2X_MUL(286, temp2, 143, p_11+861+1, 143, g+858);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, g_sum+2582, 144, g_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f+858+142, 1, p_10+861);
	GF2X_MUL(2, temp2, 1, g+858+142, 1, p_11+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2582, 1, g_sum+2582, 1, temp+1);
	right_bit_shift_n(287, g_sum+2582, 28);
	

	delta = divstepsx_256(255, delta, f_sum+2723, g_sum+2723, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, q_00+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, q_01+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, q_10+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, q_11+858+0, 144, temp, 144, temp2);
	

	// Recombining results: n: 18360, depth: 2
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_10+861);
	gf2x_add(287, p_00+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_11+861);
	gf2x_add(287, p_01+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_10+861);
	gf2x_add(287, p_10+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_11+861);
	gf2x_add(287, p_11+574, 287, temp+1, 287, temp2+1);
	

	// Calculating left operands: n: 36720, depth: 1
	// Digits to shift: 286
	// Displacement: 287
	GF2X_MUL(574, temp, 287, f+571+287, 287, p_00+574);
	GF2X_MUL(574, temp2, 287, g+571+287, 287, p_01+574);
	gf2x_add(574, f_sum+1720+0, 574, temp, 574, temp2);
	GF2X_MUL(574, temp, 287, f+571+0, 287, p_00+574);
	GF2X_MUL(574, temp2, 287, g+571+0, 287, p_01+574);
	gf2x_add(574, temp, 574, temp, 574, temp2);
	gf2x_add(287, f_sum+1720, 287, f_sum+1720, 287, temp+287);
	right_bit_shift_n(574, f_sum+1720, 56);
	GF2X_MUL(574, temp, 287, f+571+287, 287, p_10+574);
	GF2X_MUL(574, temp2, 287, g+571+287, 287, p_11+574);
	gf2x_add(574, g_sum+1720+0, 574, temp, 574, temp2);
	GF2X_MUL(574, temp, 287, f+571+0, 287, p_10+574);
	GF2X_MUL(574, temp2, 287, g+571+0, 287, p_11+574);
	gf2x_add(574, temp, 574, temp, 574, temp2);
	gf2x_add(287, g_sum+1720, 287, g_sum+1720, 287, temp+287);
	right_bit_shift_n(574, g_sum+1720, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2004, g_sum+2004, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2000+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2000+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2000+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2000+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+2000+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2000+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2000+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2000+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1996+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+1996+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+1996);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+1996);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+1996+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+1996+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+1996);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+1996);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1988+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+1988+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+1988);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+1988);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+1988+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+1988+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+1988);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+1988);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1972+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+1972+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+1972);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+1972);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+1972+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+1972+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+1972);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+1972);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+1936+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1936+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1936+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1936+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+1936+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1936+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1936+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1936+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+1864+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1864+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+1864+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1864+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+1864+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1864+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+1864+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1864+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, p_00+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, p_01+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, p_10+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, p_11+861+0, 144, temp, 144, temp2);
	

	// Calculating left operands: n: 18360, depth: 2
	// Digits to shift: 143
	// Displacement: 143
	GF2X_MUL(288, temp, 144, f_sum+1721+143, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, g_sum+1721+143, 144, p_01+861);
	gf2x_add(288, f_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_00+861+1, 143, f_sum+1721);
	GF2X_MUL(286, temp2, 143, p_01+861+1, 143, g_sum+1721);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, f_sum+2582, 144, f_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f_sum+1721+142, 1, p_00+861);
	GF2X_MUL(2, temp2, 1, g_sum+1721+142, 1, p_01+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2582, 1, f_sum+2582, 1, temp+1);
	right_bit_shift_n(287, f_sum+2582, 28);
	GF2X_MUL(288, temp, 144, f_sum+1721+143, 144, p_10+861);
	GF2X_MUL(288, temp2, 144, g_sum+1721+143, 144, p_11+861);
	gf2x_add(288, g_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_10+861+1, 143, f_sum+1721);
	GF2X_MUL(286, temp2, 143, p_11+861+1, 143, g_sum+1721);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, g_sum+2582, 144, g_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f_sum+1721+142, 1, p_10+861);
	GF2X_MUL(2, temp2, 1, g_sum+1721+142, 1, p_11+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2582, 1, g_sum+2582, 1, temp+1);
	right_bit_shift_n(287, g_sum+2582, 28);
	

	delta = divstepsx_256(255, delta, f_sum+2723, g_sum+2723, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, q_00+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, q_01+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, q_10+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, q_11+858+0, 144, temp, 144, temp2);
	

	// Recombining results: n: 18360, depth: 2
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_10+861);
	gf2x_add(287, q_00+571, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_11+861);
	gf2x_add(287, q_01+571, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_10+861);
	gf2x_add(287, q_10+571, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_11+861);
	gf2x_add(287, q_11+571, 287, temp+1, 287, temp2+1);
	

	// Recombining results: n: 36720, depth: 1
	GF2X_MUL(574, temp, 287, q_00+571+0, 287, p_00+574);
	GF2X_MUL(574, temp2, 287, q_01+571+0, 287, p_10+574);
	gf2x_add(574, p_00+0+0, 574, temp, 574, temp2);
	GF2X_MUL(574, temp, 287, q_00+571+0, 287, p_01+574);
	GF2X_MUL(574, temp2, 287, q_01+571+0, 287, p_11+574);
	gf2x_add(574, p_01+0+0, 574, temp, 574, temp2);
	GF2X_MUL(574, temp, 287, q_10+571+0, 287, p_00+574);
	GF2X_MUL(574, temp2, 287, q_11+571+0, 287, p_10+574);
	gf2x_add(574, p_10+0+0, 574, temp, 574, temp2);
	GF2X_MUL(574, temp, 287, q_10+571+0, 287, p_01+574);
	GF2X_MUL(574, temp2, 287, q_11+571+0, 287, p_11+574);
	gf2x_add(574, p_11+0+0, 574, temp, 574, temp2);
	

	// Calculating left operands: n: 73257, depth: 0
	// Digits to shift: 573
	// Displacement: 574
	GF2X_MUL(1148, temp, 574, f+0+571, 574, p_00+0);
	GF2X_MUL(1148, temp2, 574, g+0+571, 574, p_01+0);
	gf2x_add(1145, f_sum+0, 1145, temp+3, 1145, temp2+3);
	GF2X_MUL(1142, temp, 571, p_00+0+3, 571, f+0);
	GF2X_MUL(1142, temp2, 571, p_01+0+3, 571, g+0);
	gf2x_add(1142, temp, 1142, temp, 1142, temp2);
	gf2x_add(571, f_sum+0, 571, f_sum+0, 571, temp+571);
	right_bit_shift_n(1145, f_sum+0, 48);
	GF2X_MUL(1148, temp, 574, f+0+571, 574, p_10+0);
	GF2X_MUL(1148, temp2, 574, g+0+571, 574, p_11+0);
	gf2x_add(1145, g_sum+0, 1145, temp+3, 1145, temp2+3);
	GF2X_MUL(1142, temp, 571, p_10+0+3, 571, f+0);
	GF2X_MUL(1142, temp2, 571, p_11+0+3, 571, g+0);
	gf2x_add(1142, temp, 1142, temp, 1142, temp2);
	gf2x_add(571, g_sum+0, 571, g_sum+0, 571, temp+571);
	right_bit_shift_n(1145, g_sum+0, 48);
	

	delta = divstepsx_256(255, delta, f_sum+568, g_sum+568, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+564+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+564+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+564+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+564+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+564+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+564+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+564+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+564+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+560+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+560+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+560);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+560);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+560+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+560+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+560);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+560);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+552+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+552+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+552);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+552);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+552+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+552+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+552);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+552);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+536+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+536+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+536);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+536);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+536+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+536+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+536);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+536);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+500+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+500+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+500+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+500+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+500+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+500+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+500+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+500+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+428+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+428+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+428+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+428+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+428+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+428+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+428+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+428+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, p_00+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, p_01+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, p_10+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, p_11+861+0, 144, temp, 144, temp2);
	

	// Calculating left operands: n: 18360, depth: 2
	// Digits to shift: 143
	// Displacement: 143
	GF2X_MUL(288, temp, 144, f_sum+285+143, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, g_sum+285+143, 144, p_01+861);
	gf2x_add(288, f_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_00+861+1, 143, f_sum+285);
	GF2X_MUL(286, temp2, 143, p_01+861+1, 143, g_sum+285);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, f_sum+2582, 144, f_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f_sum+285+142, 1, p_00+861);
	GF2X_MUL(2, temp2, 1, g_sum+285+142, 1, p_01+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2582, 1, f_sum+2582, 1, temp+1);
	right_bit_shift_n(287, f_sum+2582, 28);
	GF2X_MUL(288, temp, 144, f_sum+285+143, 144, p_10+861);
	GF2X_MUL(288, temp2, 144, g_sum+285+143, 144, p_11+861);
	gf2x_add(288, g_sum+2582+0, 288, temp, 288, temp2);
	GF2X_MUL(286, temp, 143, p_10+861+1, 143, f_sum+285);
	GF2X_MUL(286, temp2, 143, p_11+861+1, 143, g_sum+285);
	gf2x_add(286, temp, 286, temp, 286, temp2);
	gf2x_add(144, g_sum+2582, 144, g_sum+2582, 144, temp+142);
	GF2X_MUL(2, temp, 1, f_sum+285+142, 1, p_10+861);
	GF2X_MUL(2, temp2, 1, g_sum+285+142, 1, p_11+861);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2582, 1, g_sum+2582, 1, temp+1);
	right_bit_shift_n(287, g_sum+2582, 28);
	

	delta = divstepsx_256(255, delta, f_sum+2723, g_sum+2723, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+2719+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2719+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2719+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+2715+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2715+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+2715);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+2715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+2707+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2707+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+2707);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+2707);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+2691+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2691+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+2691);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+2691);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+2655+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2655+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2655+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+2583+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+2583+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, q_00+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, q_01+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, q_10+858+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, q_11+858+0, 144, temp, 144, temp2);
	

	// Recombining results: n: 18360, depth: 2
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_10+861);
	gf2x_add(287, p_00+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_00+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_01+858+0, 144, p_11+861);
	gf2x_add(287, p_01+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_10+861);
	gf2x_add(287, p_10+574, 287, temp+1, 287, temp2+1);
	GF2X_MUL(288, temp, 144, q_10+858+0, 144, p_01+861);
	GF2X_MUL(288, temp2, 144, q_11+858+0, 144, p_11+861);
	gf2x_add(287, p_11+574, 287, temp+1, 287, temp2+1);
	

	// Calculating left operands: n: 36537, depth: 1
	// Digits to shift: 286
	// Displacement: 286
	GF2X_MUL(574, temp, 287, f_sum+1+284, 287, p_00+574);
	GF2X_MUL(574, temp2, 287, g_sum+1+284, 287, p_01+574);
	gf2x_add(572, f_sum+1720, 572, temp+2, 572, temp2+2);
	GF2X_MUL(568, temp, 284, p_00+574+3, 284, f_sum+1);
	GF2X_MUL(568, temp2, 284, p_01+574+3, 284, g_sum+1);
	gf2x_add(568, temp, 568, temp, 568, temp2);
	gf2x_add(285, f_sum+1720, 285, f_sum+1720, 285, temp+283);
	GF2X_MUL(6, temp, 3, f_sum+1+281, 3, p_00+574);
	GF2X_MUL(6, temp2, 3, g_sum+1+281, 3, p_01+574);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+1720, 1, f_sum+1720, 1, temp+5);
	right_bit_shift_n(571, f_sum+1720, 56);
	GF2X_MUL(574, temp, 287, f_sum+1+284, 287, p_10+574);
	GF2X_MUL(574, temp2, 287, g_sum+1+284, 287, p_11+574);
	gf2x_add(572, g_sum+1720, 572, temp+2, 572, temp2+2);
	GF2X_MUL(568, temp, 284, p_10+574+3, 284, f_sum+1);
	GF2X_MUL(568, temp2, 284, p_11+574+3, 284, g_sum+1);
	gf2x_add(568, temp, 568, temp, 568, temp2);
	gf2x_add(285, g_sum+1720, 285, g_sum+1720, 285, temp+283);
	GF2X_MUL(6, temp, 3, f_sum+1+281, 3, p_10+574);
	GF2X_MUL(6, temp2, 3, g_sum+1+281, 3, p_11+574);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+1720, 1, g_sum+1720, 1, temp+5);
	right_bit_shift_n(571, g_sum+1720, 56);
	

	delta = divstepsx_256(255, delta, f_sum+2002, g_sum+2002, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1998+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+1998+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1998+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+1998+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+1998+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+1998+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1998+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+1998+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1994+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+1994+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+1994);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+1994);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+1994+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+1994+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+1994);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+1994);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1986+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+1986+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+1986);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+1986);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+1986+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+1986+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+1986);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+1986);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1970+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+1970+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+1970);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+1970);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+1970+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+1970+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+1970);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+1970);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+1934+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1934+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1934+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1934+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+1934+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1934+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1934+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+1934+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 9180, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+1862+72, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1862+72, 72, p_01+1005);
	gf2x_add(144, f_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+1862+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1862+0, 72, p_01+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, f_sum+3014, 72, f_sum+3014, 72, temp+72);
	right_bit_shift_n(144, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+1862+72, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1862+72, 72, p_11+1005);
	gf2x_add(144, g_sum+3014+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, f_sum+1862+0, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+1862+0, 72, p_11+1005);
	gf2x_add(144, temp, 144, temp, 144, temp2);
	gf2x_add(72, g_sum+3014, 72, g_sum+3014, 72, temp+72);
	right_bit_shift_n(144, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3083, g_sum+3083, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3079+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3079+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3079+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3075+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3075+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3075);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3075);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3067+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3067+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3067);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3067);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3051+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3051+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3051);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3051);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+3015+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, q_00+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, q_01+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, q_10+1002+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, q_11+1002+0, 72, temp, 72, temp2);
	

	// Recombining results: n: 9180, depth: 3
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_10+1005);
	gf2x_add(144, p_00+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_00+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_01+1002+0, 72, p_11+1005);
	gf2x_add(144, p_01+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_10+1005);
	gf2x_add(144, p_10+861+0, 144, temp, 144, temp2);
	GF2X_MUL(144, temp, 72, q_10+1002+0, 72, p_01+1005);
	GF2X_MUL(144, temp2, 72, q_11+1002+0, 72, p_11+1005);
	gf2x_add(144, p_11+861+0, 144, temp, 144, temp2);
	

	// Calculating left operands: n: 18177, depth: 2
	// Digits to shift: 143
	// Displacement: 144
	GF2X_MUL(288, temp, 144, f_sum+1721+141, 144, p_00+861);
	GF2X_MUL(288, temp2, 144, g_sum+1721+141, 144, p_01+861);
	gf2x_add(285, f_sum+2582, 285, temp+3, 285, temp2+3);
	GF2X_MUL(282, temp, 141, p_00+861+3, 141, f_sum+1721);
	GF2X_MUL(282, temp2, 141, p_01+861+3, 141, g_sum+1721);
	gf2x_add(282, temp, 282, temp, 282, temp2);
	gf2x_add(141, f_sum+2582, 141, f_sum+2582, 141, temp+141);
	right_bit_shift_n(285, f_sum+2582, 28);
	GF2X_MUL(288, temp, 144, f_sum+1721+141, 144, p_10+861);
	GF2X_MUL(288, temp2, 144, g_sum+1721+141, 144, p_11+861);
	gf2x_add(285, g_sum+2582, 285, temp+3, 285, temp2+3);
	GF2X_MUL(282, temp, 141, p_10+861+3, 141, f_sum+1721);
	GF2X_MUL(282, temp2, 141, p_11+861+3, 141, g_sum+1721);
	gf2x_add(282, temp, 282, temp, 282, temp2);
	gf2x_add(141, g_sum+2582, 141, g_sum+2582, 141, temp+141);
	right_bit_shift_n(285, g_sum+2582, 28);
	

	delta = divstepsx_256(255, delta, f_sum+2720, g_sum+2720, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2716+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2716+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2716+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2716+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+2716+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2716+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2716+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+2716+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2712+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2712+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+2712);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+2712);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+2712+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+2712+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+2712);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+2712);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2704+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2704+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+2704);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+2704);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+2704+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+2704+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+2704);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+2704);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2688+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2688+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+2688);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+2688);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+2688+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+2688+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+2688);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+2688);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2652+36, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2652+36, 36, p_01+1077);
	gf2x_add(72, f_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2652+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2652+0, 36, p_01+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3231, 36, f_sum+3231, 36, temp+36);
	right_bit_shift_n(72, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+2652+36, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2652+36, 36, p_11+1077);
	gf2x_add(72, g_sum+3231+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2652+0, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+2652+0, 36, p_11+1077);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3231, 36, g_sum+3231, 36, temp+36);
	right_bit_shift_n(72, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3264, g_sum+3264, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3260+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3260+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3260+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3256+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3256+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3256);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3256);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3248+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3248+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3248);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3248);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3232);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3232);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, q_00+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+12, 8, q_00+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+8, 8, q_00+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+4, 8, q_00+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1074+0, 8, q_00+1074+0, 8, temp);
	memset(q_01+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, q_01+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+12, 8, q_01+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+8, 8, q_01+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+4, 8, q_01+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1074+0, 8, q_01+1074+0, 8, temp);
	memset(q_10+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, q_10+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+12, 8, q_10+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+8, 8, q_10+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+4, 8, q_10+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1074+0, 8, q_10+1074+0, 8, temp);
	memset(q_11+1074, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, q_11+1074+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+12, 8, q_11+1074+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+8, 8, q_11+1074+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+4, 8, q_11+1074+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1074+0, 8, q_11+1074+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_10+1077);
	gf2x_add(72, p_00+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_01+1074+0, 36, p_11+1077);
	gf2x_add(72, p_01+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_10+1077);
	gf2x_add(72, p_10+1005+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1074+0, 36, p_01+1077);
	GF2X_MUL(72, temp2, 36, q_11+1074+0, 36, p_11+1077);
	gf2x_add(72, p_11+1005+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8997, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2583+69, 72, p_00+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+69, 72, p_01+1005);
	gf2x_add(141, f_sum+3014, 141, temp+3, 141, temp2+3);
	GF2X_MUL(138, temp, 69, p_00+1005+3, 69, f_sum+2583);
	GF2X_MUL(138, temp2, 69, p_01+1005+3, 69, g_sum+2583);
	gf2x_add(138, temp, 138, temp, 138, temp2);
	gf2x_add(69, f_sum+3014, 69, f_sum+3014, 69, temp+69);
	right_bit_shift_n(141, f_sum+3014, 46);
	GF2X_MUL(144, temp, 72, f_sum+2583+69, 72, p_10+1005);
	GF2X_MUL(144, temp2, 72, g_sum+2583+69, 72, p_11+1005);
	gf2x_add(141, g_sum+3014, 141, temp+3, 141, temp2+3);
	GF2X_MUL(138, temp, 69, p_10+1005+3, 69, f_sum+2583);
	GF2X_MUL(138, temp2, 69, p_11+1005+3, 69, g_sum+2583);
	gf2x_add(138, temp, 138, temp, 138, temp2);
	gf2x_add(69, g_sum+3014, 69, g_sum+3014, 69, temp+69);
	right_bit_shift_n(141, g_sum+3014, 46);
	

	delta = divstepsx_256(255, delta, f_sum+3080, g_sum+3080, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3076+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3076+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3076+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3076+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3076+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3076+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3076+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3076+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3072+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3072+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3072);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3072);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3072+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3072+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3072);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3072);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3064+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3064+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3064);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3064);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3064+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3064+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3064);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3064);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3048+16, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3048+16, 20, p_01+1113);
	gf2x_add(36, f_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, f_sum+3048);
	GF2X_MUL(32, temp2, 16, p_01+1113+4, 16, g_sum+3048);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3340, 16, f_sum+3340, 16, temp+16);
	right_bit_shift_n(36, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3048+16, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3048+16, 20, p_11+1113);
	gf2x_add(36, g_sum+3340, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1113+4, 16, f_sum+3048);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, g_sum+3048);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3340, 16, g_sum+3340, 16, temp+16);
	right_bit_shift_n(36, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3353, g_sum+3353, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3349+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3349+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3349+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_01+1133);
	gf2x_add(16, f_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_01+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(16, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+8, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+8, 8, p_11+1133);
	gf2x_add(16, g_sum+3397+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3341+0, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+0, 8, p_11+1133);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(16, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_10+1133);
	gf2x_add(16, q_00+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_01+1126+0, 8, p_11+1133);
	gf2x_add(16, q_01+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_10+1133);
	gf2x_add(16, q_10+1110+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1126+0, 8, p_01+1133);
	GF2X_MUL(16, temp2, 8, q_11+1126+0, 8, p_11+1133);
	gf2x_add(16, q_11+1110+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_01+1110);
	gf2x_add(32, p_00+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+12, 8, p_00+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+8, 8, p_00+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+4, 8, p_00+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1077+0, 8, p_00+1077+0, 8, temp);
	memset(p_01+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_00+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_01+1110);
	gf2x_add(32, p_01+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+12, 8, p_01+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+8, 8, p_01+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+4, 8, p_01+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_01+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1077+0, 8, p_01+1077+0, 8, temp);
	memset(p_10+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_10+1113+4, 16, q_11+1110);
	gf2x_add(32, p_10+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+12, 8, p_10+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+8, 8, p_10+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+4, 8, p_10+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_00+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_10+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1077+0, 8, p_10+1077+0, 8, temp);
	memset(p_11+1077, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1113+4, 16, q_10+1110);
	GF2X_MUL(32, temp2, 16, p_11+1113+4, 16, q_11+1110);
	gf2x_add(32, p_11+1077+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1110+12, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+12, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+12, 8, p_11+1077+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+8, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+8, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+8, 8, p_11+1077+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+4, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+4, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+4, 8, p_11+1077+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1110+0, 4, p_01+1113);
	GF2X_MUL(8, temp2, 4, q_11+1110+0, 4, p_11+1113);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1077+0, 8, p_11+1077+0, 8, temp);
	

	// Calculating left operands: n: 4407, depth: 4
	// Digits to shift: 35
	// Displacement: 35
	GF2X_MUL(72, temp, 36, f_sum+3015+33, 36, p_00+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+33, 36, p_01+1077);
	gf2x_add(70, f_sum+3231, 70, temp+2, 70, temp2+2);
	GF2X_MUL(66, temp, 33, p_00+1077+3, 33, f_sum+3015);
	GF2X_MUL(66, temp2, 33, p_01+1077+3, 33, g_sum+3015);
	gf2x_add(66, temp, 66, temp, 66, temp2);
	gf2x_add(34, f_sum+3231, 34, f_sum+3231, 34, temp+32);
	GF2X_MUL(6, temp, 3, f_sum+3015+30, 3, p_00+1077);
	GF2X_MUL(6, temp2, 3, g_sum+3015+30, 3, p_01+1077);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+3231, 1, f_sum+3231, 1, temp+5);
	right_bit_shift_n(69, f_sum+3231, 55);
	GF2X_MUL(72, temp, 36, f_sum+3015+33, 36, p_10+1077);
	GF2X_MUL(72, temp2, 36, g_sum+3015+33, 36, p_11+1077);
	gf2x_add(70, g_sum+3231, 70, temp+2, 70, temp2+2);
	GF2X_MUL(66, temp, 33, p_10+1077+3, 33, f_sum+3015);
	GF2X_MUL(66, temp2, 33, p_11+1077+3, 33, g_sum+3015);
	gf2x_add(66, temp, 66, temp, 66, temp2);
	gf2x_add(34, g_sum+3231, 34, g_sum+3231, 34, temp+32);
	GF2X_MUL(6, temp, 3, f_sum+3015+30, 3, p_10+1077);
	GF2X_MUL(6, temp2, 3, g_sum+3015+30, 3, p_11+1077);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+3231, 1, g_sum+3231, 1, temp+5);
	right_bit_shift_n(69, g_sum+3231, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1153, p_01+1153, p_10+1153, p_11+1153);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1153);
	gf2x_add(8, f_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3451, 4, f_sum+3451, 4, temp+4);
	right_bit_shift_n(8, f_sum+3451, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1153);
	gf2x_add(8, g_sum+3451+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1153);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1153);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3451, 4, g_sum+3451, 4, temp+4);
	right_bit_shift_n(8, g_sum+3451, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3452, g_sum+3452, q_00+1138, q_01+1138, q_10+1138, q_11+1138);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_10+1153);
	gf2x_add(8, p_00+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_01+1138+0, 4, p_11+1153);
	gf2x_add(8, p_01+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_00+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_10+1153);
	gf2x_add(8, p_10+1145+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1138+0, 4, p_01+1153);
	GF2X_MUL(8, temp2, 4, q_11+1138+0, 4, p_11+1153);
	gf2x_add(8, p_11+1145+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3254+4, 8, p_00+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3254+4, 8, p_01+1145);
	gf2x_add(12, f_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, f_sum+3254);
	GF2X_MUL(8, temp2, 4, p_01+1145+4, 4, g_sum+3254);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(12, f_sum+3430, 62);
	GF2X_MUL(16, temp, 8, f_sum+3254+4, 8, p_10+1145);
	GF2X_MUL(16, temp2, 8, g_sum+3254+4, 8, p_11+1145);
	gf2x_add(12, g_sum+3430, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1145+4, 4, f_sum+3254);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, g_sum+3254);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(12, g_sum+3430, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_01+1134);
	gf2x_add(8, p_00+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1133+0, 8, p_00+1133+0, 8, temp);
	memset(p_01+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_00+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_01+1134);
	gf2x_add(8, p_01+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1133+0, 8, p_01+1133+0, 8, temp);
	memset(p_10+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_10+1145+4, 4, q_11+1134);
	gf2x_add(8, p_10+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1133+0, 8, p_10+1133+0, 8, temp);
	memset(p_11+1133, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1145+4, 4, q_10+1134);
	GF2X_MUL(8, temp2, 4, p_11+1145+4, 4, q_11+1134);
	gf2x_add(8, p_11+1133+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1133+0, 8, p_11+1133+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3246+8, 12, p_00+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3246+8, 12, p_01+1133);
	gf2x_add(20, f_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, f_sum+3246);
	GF2X_MUL(16, temp2, 8, p_01+1133+4, 8, g_sum+3246);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3397, 8, f_sum+3397, 8, temp+8);
	right_bit_shift_n(20, f_sum+3397, 61);
	GF2X_MUL(24, temp, 12, f_sum+3246+8, 12, p_10+1133);
	GF2X_MUL(24, temp2, 12, g_sum+3246+8, 12, p_11+1133);
	gf2x_add(20, g_sum+3397, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1133+4, 8, f_sum+3246);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, g_sum+3246);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3397, 8, g_sum+3397, 8, temp+8);
	right_bit_shift_n(20, g_sum+3397, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3402, g_sum+3402, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3398+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, q_00+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, q_01+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, q_10+1126+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, q_11+1126+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_01+1126);
	gf2x_add(16, p_00+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+4, 8, p_00+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1113+0, 8, p_00+1113+0, 8, temp);
	memset(p_01+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_00+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_01+1126);
	gf2x_add(16, p_01+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+4, 8, p_01+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_01+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1113+0, 8, p_01+1113+0, 8, temp);
	memset(p_10+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_10+1133+4, 8, q_11+1126);
	gf2x_add(16, p_10+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+4, 8, p_10+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_00+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_10+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1113+0, 8, p_10+1113+0, 8, temp);
	memset(p_11+1113, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1133+4, 8, q_10+1126);
	GF2X_MUL(16, temp2, 8, p_11+1133+4, 8, q_11+1126);
	gf2x_add(16, p_11+1113+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1126+4, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+4, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+4, 8, p_11+1113+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1126+0, 4, p_01+1133);
	GF2X_MUL(8, temp2, 4, q_11+1126+0, 4, p_11+1133);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1113+0, 8, p_11+1113+0, 8, temp);
	

	// Calculating left operands: n: 2112, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3232+14, 20, p_00+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+14, 20, p_01+1113);
	gf2x_add(34, f_sum+3340, 34, temp+6, 34, temp2+6);
	GF2X_MUL(28, temp, 14, p_00+1113+6, 14, f_sum+3232);
	GF2X_MUL(28, temp2, 14, p_01+1113+6, 14, g_sum+3232);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, f_sum+3340, 14, f_sum+3340, 14, temp+14);
	right_bit_shift_n(34, f_sum+3340, 59);
	GF2X_MUL(40, temp, 20, f_sum+3232+14, 20, p_10+1113);
	GF2X_MUL(40, temp2, 20, g_sum+3232+14, 20, p_11+1113);
	gf2x_add(34, g_sum+3340, 34, temp+6, 34, temp2+6);
	GF2X_MUL(28, temp, 14, p_10+1113+6, 14, f_sum+3232);
	GF2X_MUL(28, temp2, 14, p_11+1113+6, 14, g_sum+3232);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, g_sum+3340, 14, g_sum+3340, 14, temp+14);
	right_bit_shift_n(34, g_sum+3340, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3351, g_sum+3351, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3347+4, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3347+4, 4, p_01+1145);
	gf2x_add(8, f_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3347+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3347+0, 4, p_01+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3430, 4, f_sum+3430, 4, temp+4);
	right_bit_shift_n(8, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3347+4, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3347+4, 4, p_11+1145);
	gf2x_add(8, g_sum+3430+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3347+0, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3347+0, 4, p_11+1145);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3430, 4, g_sum+3430, 4, temp+4);
	right_bit_shift_n(8, g_sum+3430, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_10+1145);
	gf2x_add(8, p_00+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_01+1134+0, 4, p_11+1145);
	gf2x_add(8, p_01+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_10+1145);
	gf2x_add(8, p_10+1133+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1134+0, 4, p_01+1145);
	GF2X_MUL(8, temp2, 4, q_11+1134+0, 4, p_11+1145);
	gf2x_add(8, p_11+1133+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 837, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3341+6, 8, p_00+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+6, 8, p_01+1133);
	gf2x_add(14, f_sum+3397, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_00+1133+2, 6, f_sum+3341);
	GF2X_MUL(12, temp2, 6, p_01+1133+2, 6, g_sum+3341);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, f_sum+3397, 6, f_sum+3397, 6, temp+6);
	right_bit_shift_n(14, f_sum+3397, 62);
	GF2X_MUL(16, temp, 8, f_sum+3341+6, 8, p_10+1133);
	GF2X_MUL(16, temp2, 8, g_sum+3341+6, 8, p_11+1133);
	gf2x_add(14, g_sum+3397, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_10+1133+2, 6, f_sum+3341);
	GF2X_MUL(12, temp2, 6, p_11+1133+2, 6, g_sum+3341);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, g_sum+3397, 6, g_sum+3397, 6, temp+6);
	right_bit_shift_n(14, g_sum+3397, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3400, g_sum+3400, p_00+1145, p_01+1145, p_10+1145, p_11+1145);

	// Calculating left operands: n: 327, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3398+2, 4, p_00+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+2, 4, p_01+1145);
	gf2x_add(6, f_sum+3430, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_00+1145+2, 2, f_sum+3398);
	GF2X_MUL(4, temp2, 2, p_01+1145+2, 2, g_sum+3398);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+3430, 2, f_sum+3430, 2, temp+2);
	right_bit_shift_n(6, f_sum+3430, 63);
	GF2X_MUL(8, temp, 4, f_sum+3398+2, 4, p_10+1145);
	GF2X_MUL(8, temp2, 4, g_sum+3398+2, 4, p_11+1145);
	gf2x_add(6, g_sum+3430, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_10+1145+2, 2, f_sum+3398);
	GF2X_MUL(4, temp2, 2, p_11+1145+2, 2, g_sum+3398);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+3430, 2, g_sum+3430, 2, temp+2);
	right_bit_shift_n(6, g_sum+3430, 63);
	

	delta = divstepsx_128(72, delta, f_sum+3431, g_sum+3431, q_00+1134, q_01+1134, q_10+1134, q_11+1134);

	// Recombining results: n: 327, depth: 7
	memset(q_00+1126, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+1145+2, 2, q_00+1134);
	GF2X_MUL(4, temp2, 2, p_10+1145+2, 2, q_01+1134);
	gf2x_add(4, q_00+1126+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+1134+0, 2, p_00+1145);
	GF2X_MUL(4, temp2, 2, q_01+1134+0, 2, p_10+1145);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1126+0, 4, q_00+1126+0, 4, temp);
	memset(q_01+1126, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+1145+2, 2, q_00+1134);
	GF2X_MUL(4, temp2, 2, p_11+1145+2, 2, q_01+1134);
	gf2x_add(4, q_01+1126+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+1134+0, 2, p_01+1145);
	GF2X_MUL(4, temp2, 2, q_01+1134+0, 2, p_11+1145);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1126+0, 4, q_01+1126+0, 4, temp);
	memset(q_10+1126, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+1145+2, 2, q_10+1134);
	GF2X_MUL(4, temp2, 2, p_10+1145+2, 2, q_11+1134);
	gf2x_add(4, q_10+1126+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+1134+0, 2, p_00+1145);
	GF2X_MUL(4, temp2, 2, q_11+1134+0, 2, p_10+1145);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1126+0, 4, q_10+1126+0, 4, temp);
	memset(q_11+1126, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+1145+2, 2, q_10+1134);
	GF2X_MUL(4, temp2, 2, p_11+1145+2, 2, q_11+1134);
	gf2x_add(4, q_11+1126+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+1134+0, 2, p_01+1145);
	GF2X_MUL(4, temp2, 2, q_11+1134+0, 2, p_11+1145);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1126+0, 4, q_11+1126+0, 4, temp);
	

	// Recombining results: n: 837, depth: 6
	memset(q_00+1110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+1133+2, 6, q_00+1126);
	GF2X_MUL(12, temp2, 6, p_10+1133+2, 6, q_01+1126);
	gf2x_add(12, q_00+1110+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+1126+4, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+4, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1110+4, 4, q_00+1110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1126+2, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+2, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1110+2, 4, q_00+1110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1126+0, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+0, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1110+0, 4, q_00+1110+0, 4, temp);
	memset(q_01+1110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+1133+2, 6, q_00+1126);
	GF2X_MUL(12, temp2, 6, p_11+1133+2, 6, q_01+1126);
	gf2x_add(12, q_01+1110+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+1126+4, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+4, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1110+4, 4, q_01+1110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1126+2, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+2, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1110+2, 4, q_01+1110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1126+0, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_01+1126+0, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1110+0, 4, q_01+1110+0, 4, temp);
	memset(q_10+1110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+1133+2, 6, q_10+1126);
	GF2X_MUL(12, temp2, 6, p_10+1133+2, 6, q_11+1126);
	gf2x_add(12, q_10+1110+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+1126+4, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+4, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1110+4, 4, q_10+1110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1126+2, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+2, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1110+2, 4, q_10+1110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1126+0, 2, p_00+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+0, 2, p_10+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1110+0, 4, q_10+1110+0, 4, temp);
	memset(q_11+1110, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+1133+2, 6, q_10+1126);
	GF2X_MUL(12, temp2, 6, p_11+1133+2, 6, q_11+1126);
	gf2x_add(12, q_11+1110+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+1126+4, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+4, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1110+4, 4, q_11+1110+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1126+2, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+2, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1110+2, 4, q_11+1110+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1126+0, 2, p_01+1133);
	GF2X_MUL(4, temp2, 2, q_11+1126+0, 2, p_11+1133);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1110+0, 4, q_11+1110+0, 4, temp);
	

	// Recombining results: n: 2112, depth: 5
	memset(q_00+1074, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+1113+6, 14, q_00+1110);
	GF2X_MUL(28, temp2, 14, p_10+1113+6, 14, q_01+1110);
	gf2x_add(28, q_00+1074+6, 28, temp, 28, temp2);
	GF2X_MUL(12, temp, 6, q_00+1110+8, 6, p_00+1113);
	GF2X_MUL(12, temp2, 6, q_01+1110+8, 6, p_10+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+1074+8, 12, q_00+1074+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1110+2, 6, p_00+1113);
	GF2X_MUL(12, temp2, 6, q_01+1110+2, 6, p_10+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+1074+2, 12, q_00+1074+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+1113+4, 2, q_00+1110);
	GF2X_MUL(4, temp2, 2, p_10+1113+4, 2, q_01+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1074+4, 4, q_00+1074+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+1113+2, 2, q_00+1110);
	GF2X_MUL(4, temp2, 2, p_10+1113+2, 2, q_01+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1074+2, 4, q_00+1074+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1110+0, 2, p_00+1113);
	GF2X_MUL(4, temp2, 2, q_01+1110+0, 2, p_10+1113);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1074+0, 4, q_00+1074+0, 4, temp);
	memset(q_01+1074, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+1113+6, 14, q_00+1110);
	GF2X_MUL(28, temp2, 14, p_11+1113+6, 14, q_01+1110);
	gf2x_add(28, q_01+1074+6, 28, temp, 28, temp2);
	GF2X_MUL(12, temp, 6, q_00+1110+8, 6, p_01+1113);
	GF2X_MUL(12, temp2, 6, q_01+1110+8, 6, p_11+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+1074+8, 12, q_01+1074+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1110+2, 6, p_01+1113);
	GF2X_MUL(12, temp2, 6, q_01+1110+2, 6, p_11+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+1074+2, 12, q_01+1074+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+1113+4, 2, q_00+1110);
	GF2X_MUL(4, temp2, 2, p_11+1113+4, 2, q_01+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1074+4, 4, q_01+1074+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+1113+2, 2, q_00+1110);
	GF2X_MUL(4, temp2, 2, p_11+1113+2, 2, q_01+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1074+2, 4, q_01+1074+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1110+0, 2, p_01+1113);
	GF2X_MUL(4, temp2, 2, q_01+1110+0, 2, p_11+1113);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1074+0, 4, q_01+1074+0, 4, temp);
	memset(q_10+1074, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+1113+6, 14, q_10+1110);
	GF2X_MUL(28, temp2, 14, p_10+1113+6, 14, q_11+1110);
	gf2x_add(28, q_10+1074+6, 28, temp, 28, temp2);
	GF2X_MUL(12, temp, 6, q_10+1110+8, 6, p_00+1113);
	GF2X_MUL(12, temp2, 6, q_11+1110+8, 6, p_10+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+1074+8, 12, q_10+1074+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1110+2, 6, p_00+1113);
	GF2X_MUL(12, temp2, 6, q_11+1110+2, 6, p_10+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+1074+2, 12, q_10+1074+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+1113+4, 2, q_10+1110);
	GF2X_MUL(4, temp2, 2, p_10+1113+4, 2, q_11+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1074+4, 4, q_10+1074+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+1113+2, 2, q_10+1110);
	GF2X_MUL(4, temp2, 2, p_10+1113+2, 2, q_11+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1074+2, 4, q_10+1074+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1110+0, 2, p_00+1113);
	GF2X_MUL(4, temp2, 2, q_11+1110+0, 2, p_10+1113);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1074+0, 4, q_10+1074+0, 4, temp);
	memset(q_11+1074, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+1113+6, 14, q_10+1110);
	GF2X_MUL(28, temp2, 14, p_11+1113+6, 14, q_11+1110);
	gf2x_add(28, q_11+1074+6, 28, temp, 28, temp2);
	GF2X_MUL(12, temp, 6, q_10+1110+8, 6, p_01+1113);
	GF2X_MUL(12, temp2, 6, q_11+1110+8, 6, p_11+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+1074+8, 12, q_11+1074+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1110+2, 6, p_01+1113);
	GF2X_MUL(12, temp2, 6, q_11+1110+2, 6, p_11+1113);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+1074+2, 12, q_11+1074+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+1113+4, 2, q_10+1110);
	GF2X_MUL(4, temp2, 2, p_11+1113+4, 2, q_11+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1074+4, 4, q_11+1074+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+1113+2, 2, q_10+1110);
	GF2X_MUL(4, temp2, 2, p_11+1113+2, 2, q_11+1110);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1074+2, 4, q_11+1074+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1110+0, 2, p_01+1113);
	GF2X_MUL(4, temp2, 2, q_11+1110+0, 2, p_11+1113);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1074+0, 4, q_11+1074+0, 4, temp);
	

	// Recombining results: n: 4407, depth: 4
	memset(q_00+1002, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(68, temp, 34, p_00+1077+2, 34, q_00+1074);
	GF2X_MUL(68, temp2, 34, p_10+1077+2, 34, q_01+1074);
	gf2x_add(68, q_00+1002+1, 68, temp, 68, temp2);
	GF2X_MUL(4, temp, 2, q_00+1074+32, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+32, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+31, 4, q_00+1002+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+30, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+30, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+29, 4, q_00+1002+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+28, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+28, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+27, 4, q_00+1002+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+26, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+26, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+25, 4, q_00+1002+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+24, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+24, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+23, 4, q_00+1002+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+22, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+22, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+21, 4, q_00+1002+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+20, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+20, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+19, 4, q_00+1002+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+18, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+18, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+17, 4, q_00+1002+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+16, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+16, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+15, 4, q_00+1002+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+14, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+14, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+13, 4, q_00+1002+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+12, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+12, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+11, 4, q_00+1002+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+10, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+10, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+9, 4, q_00+1002+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+8, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+8, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+7, 4, q_00+1002+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+6, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+6, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+5, 4, q_00+1002+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+4, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+4, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+3, 4, q_00+1002+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+2, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+2, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1002+1, 4, q_00+1002+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+0, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+0, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+1002, 3, q_00+1002, 3, temp+1);
	memset(q_01+1002, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(68, temp, 34, p_01+1077+2, 34, q_00+1074);
	GF2X_MUL(68, temp2, 34, p_11+1077+2, 34, q_01+1074);
	gf2x_add(68, q_01+1002+1, 68, temp, 68, temp2);
	GF2X_MUL(4, temp, 2, q_00+1074+32, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+32, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+31, 4, q_01+1002+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+30, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+30, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+29, 4, q_01+1002+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+28, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+28, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+27, 4, q_01+1002+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+26, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+26, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+25, 4, q_01+1002+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+24, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+24, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+23, 4, q_01+1002+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+22, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+22, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+21, 4, q_01+1002+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+20, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+20, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+19, 4, q_01+1002+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+18, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+18, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+17, 4, q_01+1002+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+16, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+16, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+15, 4, q_01+1002+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+14, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+14, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+13, 4, q_01+1002+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+12, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+12, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+11, 4, q_01+1002+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+10, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+10, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+9, 4, q_01+1002+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+8, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+8, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+7, 4, q_01+1002+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+6, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+6, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+5, 4, q_01+1002+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+4, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+4, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+3, 4, q_01+1002+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+2, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+2, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1002+1, 4, q_01+1002+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1074+0, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_01+1074+0, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+1002, 3, q_01+1002, 3, temp+1);
	memset(q_10+1002, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(68, temp, 34, p_00+1077+2, 34, q_10+1074);
	GF2X_MUL(68, temp2, 34, p_10+1077+2, 34, q_11+1074);
	gf2x_add(68, q_10+1002+1, 68, temp, 68, temp2);
	GF2X_MUL(4, temp, 2, q_10+1074+32, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+32, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+31, 4, q_10+1002+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+30, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+30, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+29, 4, q_10+1002+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+28, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+28, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+27, 4, q_10+1002+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+26, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+26, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+25, 4, q_10+1002+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+24, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+24, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+23, 4, q_10+1002+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+22, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+22, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+21, 4, q_10+1002+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+20, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+20, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+19, 4, q_10+1002+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+18, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+18, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+17, 4, q_10+1002+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+16, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+16, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+15, 4, q_10+1002+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+14, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+14, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+13, 4, q_10+1002+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+12, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+12, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+11, 4, q_10+1002+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+10, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+10, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+9, 4, q_10+1002+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+8, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+8, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+7, 4, q_10+1002+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+6, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+6, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+5, 4, q_10+1002+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+4, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+4, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+3, 4, q_10+1002+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+2, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+2, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1002+1, 4, q_10+1002+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+0, 2, p_00+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+0, 2, p_10+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+1002, 3, q_10+1002, 3, temp+1);
	memset(q_11+1002, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(68, temp, 34, p_01+1077+2, 34, q_10+1074);
	GF2X_MUL(68, temp2, 34, p_11+1077+2, 34, q_11+1074);
	gf2x_add(68, q_11+1002+1, 68, temp, 68, temp2);
	GF2X_MUL(4, temp, 2, q_10+1074+32, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+32, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+31, 4, q_11+1002+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+30, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+30, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+29, 4, q_11+1002+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+28, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+28, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+27, 4, q_11+1002+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+26, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+26, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+25, 4, q_11+1002+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+24, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+24, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+23, 4, q_11+1002+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+22, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+22, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+21, 4, q_11+1002+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+20, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+20, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+19, 4, q_11+1002+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+18, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+18, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+17, 4, q_11+1002+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+16, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+16, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+15, 4, q_11+1002+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+14, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+14, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+13, 4, q_11+1002+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+12, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+12, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+11, 4, q_11+1002+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+10, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+10, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+9, 4, q_11+1002+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+8, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+8, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+7, 4, q_11+1002+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+6, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+6, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+5, 4, q_11+1002+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+4, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+4, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+3, 4, q_11+1002+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+2, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+2, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1002+1, 4, q_11+1002+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1074+0, 2, p_01+1077);
	GF2X_MUL(4, temp2, 2, q_11+1074+0, 2, p_11+1077);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+1002, 3, q_11+1002, 3, temp+1);
	

	// Recombining results: n: 8997, depth: 3
	memset(q_00+858, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(138, temp, 69, p_00+1005+3, 69, q_00+1002);
	GF2X_MUL(138, temp2, 69, p_10+1005+3, 69, q_01+1002);
	gf2x_add(138, q_00+858+3, 138, temp, 138, temp2);
	GF2X_MUL(6, temp, 3, q_00+1002+66, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+66, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+66, 6, q_00+858+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+63, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+63, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+63, 6, q_00+858+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+60, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+60, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+60, 6, q_00+858+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+57, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+57, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+57, 6, q_00+858+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+54, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+54, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+54, 6, q_00+858+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+51, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+51, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+51, 6, q_00+858+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+48, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+48, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+48, 6, q_00+858+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+45, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+45, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+45, 6, q_00+858+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+42, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+42, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+42, 6, q_00+858+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+39, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+39, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+39, 6, q_00+858+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+36, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+36, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+36, 6, q_00+858+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+33, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+33, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+33, 6, q_00+858+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+30, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+30, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+30, 6, q_00+858+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+27, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+27, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+27, 6, q_00+858+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+24, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+24, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+24, 6, q_00+858+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+21, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+21, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+21, 6, q_00+858+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+18, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+18, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+18, 6, q_00+858+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+15, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+15, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+15, 6, q_00+858+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+12, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+12, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+12, 6, q_00+858+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+9, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+9, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+9, 6, q_00+858+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+6, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+6, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+6, 6, q_00+858+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+3, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+3, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+3, 6, q_00+858+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+0, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+0, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+858+0, 6, q_00+858+0, 6, temp);
	memset(q_01+858, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(138, temp, 69, p_01+1005+3, 69, q_00+1002);
	GF2X_MUL(138, temp2, 69, p_11+1005+3, 69, q_01+1002);
	gf2x_add(138, q_01+858+3, 138, temp, 138, temp2);
	GF2X_MUL(6, temp, 3, q_00+1002+66, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+66, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+66, 6, q_01+858+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+63, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+63, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+63, 6, q_01+858+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+60, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+60, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+60, 6, q_01+858+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+57, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+57, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+57, 6, q_01+858+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+54, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+54, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+54, 6, q_01+858+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+51, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+51, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+51, 6, q_01+858+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+48, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+48, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+48, 6, q_01+858+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+45, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+45, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+45, 6, q_01+858+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+42, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+42, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+42, 6, q_01+858+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+39, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+39, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+39, 6, q_01+858+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+36, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+36, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+36, 6, q_01+858+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+33, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+33, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+33, 6, q_01+858+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+30, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+30, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+30, 6, q_01+858+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+27, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+27, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+27, 6, q_01+858+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+24, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+24, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+24, 6, q_01+858+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+21, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+21, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+21, 6, q_01+858+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+18, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+18, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+18, 6, q_01+858+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+15, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+15, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+15, 6, q_01+858+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+12, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+12, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+12, 6, q_01+858+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+9, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+9, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+9, 6, q_01+858+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+6, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+6, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+6, 6, q_01+858+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+3, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+3, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+3, 6, q_01+858+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+1002+0, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_01+1002+0, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+858+0, 6, q_01+858+0, 6, temp);
	memset(q_10+858, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(138, temp, 69, p_00+1005+3, 69, q_10+1002);
	GF2X_MUL(138, temp2, 69, p_10+1005+3, 69, q_11+1002);
	gf2x_add(138, q_10+858+3, 138, temp, 138, temp2);
	GF2X_MUL(6, temp, 3, q_10+1002+66, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+66, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+66, 6, q_10+858+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+63, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+63, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+63, 6, q_10+858+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+60, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+60, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+60, 6, q_10+858+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+57, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+57, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+57, 6, q_10+858+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+54, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+54, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+54, 6, q_10+858+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+51, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+51, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+51, 6, q_10+858+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+48, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+48, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+48, 6, q_10+858+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+45, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+45, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+45, 6, q_10+858+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+42, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+42, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+42, 6, q_10+858+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+39, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+39, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+39, 6, q_10+858+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+36, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+36, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+36, 6, q_10+858+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+33, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+33, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+33, 6, q_10+858+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+30, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+30, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+30, 6, q_10+858+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+27, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+27, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+27, 6, q_10+858+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+24, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+24, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+24, 6, q_10+858+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+21, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+21, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+21, 6, q_10+858+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+18, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+18, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+18, 6, q_10+858+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+15, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+15, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+15, 6, q_10+858+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+12, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+12, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+12, 6, q_10+858+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+9, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+9, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+9, 6, q_10+858+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+6, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+6, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+6, 6, q_10+858+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+3, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+3, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+3, 6, q_10+858+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+0, 3, p_00+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+0, 3, p_10+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+858+0, 6, q_10+858+0, 6, temp);
	memset(q_11+858, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(138, temp, 69, p_01+1005+3, 69, q_10+1002);
	GF2X_MUL(138, temp2, 69, p_11+1005+3, 69, q_11+1002);
	gf2x_add(138, q_11+858+3, 138, temp, 138, temp2);
	GF2X_MUL(6, temp, 3, q_10+1002+66, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+66, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+66, 6, q_11+858+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+63, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+63, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+63, 6, q_11+858+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+60, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+60, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+60, 6, q_11+858+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+57, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+57, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+57, 6, q_11+858+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+54, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+54, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+54, 6, q_11+858+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+51, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+51, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+51, 6, q_11+858+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+48, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+48, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+48, 6, q_11+858+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+45, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+45, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+45, 6, q_11+858+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+42, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+42, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+42, 6, q_11+858+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+39, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+39, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+39, 6, q_11+858+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+36, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+36, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+36, 6, q_11+858+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+33, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+33, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+33, 6, q_11+858+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+30, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+30, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+30, 6, q_11+858+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+27, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+27, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+27, 6, q_11+858+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+24, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+24, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+24, 6, q_11+858+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+21, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+21, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+21, 6, q_11+858+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+18, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+18, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+18, 6, q_11+858+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+15, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+15, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+15, 6, q_11+858+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+12, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+12, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+12, 6, q_11+858+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+9, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+9, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+9, 6, q_11+858+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+6, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+6, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+6, 6, q_11+858+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+3, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+3, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+3, 6, q_11+858+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+1002+0, 3, p_01+1005);
	GF2X_MUL(6, temp2, 3, q_11+1002+0, 3, p_11+1005);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+858+0, 6, q_11+858+0, 6, temp);
	

	// Recombining results: n: 18177, depth: 2
	memset(q_00+571, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(282, temp, 141, p_00+861+3, 141, q_00+858);
	GF2X_MUL(282, temp2, 141, p_10+861+3, 141, q_01+858);
	gf2x_add(282, q_00+571+3, 282, temp, 282, temp2);
	GF2X_MUL(6, temp, 3, q_00+858+138, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+138, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+138, 6, q_00+571+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+135, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+135, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+135, 6, q_00+571+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+132, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+132, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+132, 6, q_00+571+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+129, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+129, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+129, 6, q_00+571+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+126, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+126, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+126, 6, q_00+571+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+123, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+123, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+123, 6, q_00+571+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+120, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+120, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+120, 6, q_00+571+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+117, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+117, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+117, 6, q_00+571+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+114, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+114, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+114, 6, q_00+571+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+111, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+111, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+111, 6, q_00+571+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+108, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+108, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+108, 6, q_00+571+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+105, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+105, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+105, 6, q_00+571+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+102, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+102, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+102, 6, q_00+571+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+99, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+99, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+99, 6, q_00+571+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+96, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+96, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+96, 6, q_00+571+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+93, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+93, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+93, 6, q_00+571+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+90, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+90, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+90, 6, q_00+571+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+87, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+87, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+87, 6, q_00+571+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+84, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+84, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+84, 6, q_00+571+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+81, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+81, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+81, 6, q_00+571+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+78, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+78, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+78, 6, q_00+571+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+75, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+75, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+75, 6, q_00+571+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+72, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+72, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+72, 6, q_00+571+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+69, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+69, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+69, 6, q_00+571+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+66, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+66, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+66, 6, q_00+571+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+63, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+63, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+63, 6, q_00+571+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+60, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+60, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+60, 6, q_00+571+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+57, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+57, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+57, 6, q_00+571+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+54, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+54, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+54, 6, q_00+571+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+51, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+51, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+51, 6, q_00+571+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+48, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+48, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+48, 6, q_00+571+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+45, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+45, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+45, 6, q_00+571+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+42, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+42, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+42, 6, q_00+571+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+39, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+39, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+39, 6, q_00+571+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+36, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+36, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+36, 6, q_00+571+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+33, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+33, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+33, 6, q_00+571+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+30, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+30, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+30, 6, q_00+571+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+27, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+27, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+27, 6, q_00+571+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+24, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+24, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+24, 6, q_00+571+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+21, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+21, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+21, 6, q_00+571+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+18, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+18, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+18, 6, q_00+571+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+15, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+15, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+15, 6, q_00+571+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+12, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+12, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+12, 6, q_00+571+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+9, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+9, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+9, 6, q_00+571+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+6, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+6, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+6, 6, q_00+571+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+3, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+3, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+3, 6, q_00+571+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+0, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_01+858+0, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+571+0, 6, q_00+571+0, 6, temp);
	memset(q_01+571, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(282, temp, 141, p_01+861+3, 141, q_00+858);
	GF2X_MUL(282, temp2, 141, p_11+861+3, 141, q_01+858);
	gf2x_add(282, q_01+571+3, 282, temp, 282, temp2);
	GF2X_MUL(6, temp, 3, q_00+858+138, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+138, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+138, 6, q_01+571+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+135, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+135, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+135, 6, q_01+571+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+132, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+132, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+132, 6, q_01+571+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+129, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+129, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+129, 6, q_01+571+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+126, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+126, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+126, 6, q_01+571+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+123, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+123, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+123, 6, q_01+571+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+120, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+120, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+120, 6, q_01+571+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+117, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+117, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+117, 6, q_01+571+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+114, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+114, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+114, 6, q_01+571+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+111, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+111, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+111, 6, q_01+571+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+108, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+108, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+108, 6, q_01+571+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+105, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+105, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+105, 6, q_01+571+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+102, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+102, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+102, 6, q_01+571+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+99, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+99, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+99, 6, q_01+571+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+96, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+96, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+96, 6, q_01+571+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+93, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+93, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+93, 6, q_01+571+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+90, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+90, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+90, 6, q_01+571+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+87, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+87, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+87, 6, q_01+571+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+84, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+84, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+84, 6, q_01+571+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+81, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+81, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+81, 6, q_01+571+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+78, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+78, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+78, 6, q_01+571+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+75, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+75, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+75, 6, q_01+571+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+72, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+72, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+72, 6, q_01+571+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+69, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+69, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+69, 6, q_01+571+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+66, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+66, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+66, 6, q_01+571+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+63, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+63, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+63, 6, q_01+571+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+60, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+60, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+60, 6, q_01+571+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+57, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+57, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+57, 6, q_01+571+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+54, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+54, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+54, 6, q_01+571+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+51, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+51, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+51, 6, q_01+571+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+48, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+48, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+48, 6, q_01+571+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+45, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+45, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+45, 6, q_01+571+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+42, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+42, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+42, 6, q_01+571+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+39, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+39, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+39, 6, q_01+571+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+36, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+36, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+36, 6, q_01+571+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+33, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+33, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+33, 6, q_01+571+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+30, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+30, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+30, 6, q_01+571+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+27, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+27, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+27, 6, q_01+571+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+24, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+24, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+24, 6, q_01+571+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+21, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+21, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+21, 6, q_01+571+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+18, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+18, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+18, 6, q_01+571+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+15, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+15, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+15, 6, q_01+571+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+12, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+12, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+12, 6, q_01+571+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+9, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+9, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+9, 6, q_01+571+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+6, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+6, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+6, 6, q_01+571+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+3, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+3, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+3, 6, q_01+571+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+858+0, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_01+858+0, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+571+0, 6, q_01+571+0, 6, temp);
	memset(q_10+571, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(282, temp, 141, p_00+861+3, 141, q_10+858);
	GF2X_MUL(282, temp2, 141, p_10+861+3, 141, q_11+858);
	gf2x_add(282, q_10+571+3, 282, temp, 282, temp2);
	GF2X_MUL(6, temp, 3, q_10+858+138, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+138, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+138, 6, q_10+571+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+135, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+135, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+135, 6, q_10+571+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+132, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+132, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+132, 6, q_10+571+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+129, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+129, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+129, 6, q_10+571+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+126, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+126, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+126, 6, q_10+571+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+123, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+123, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+123, 6, q_10+571+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+120, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+120, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+120, 6, q_10+571+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+117, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+117, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+117, 6, q_10+571+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+114, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+114, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+114, 6, q_10+571+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+111, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+111, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+111, 6, q_10+571+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+108, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+108, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+108, 6, q_10+571+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+105, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+105, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+105, 6, q_10+571+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+102, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+102, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+102, 6, q_10+571+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+99, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+99, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+99, 6, q_10+571+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+96, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+96, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+96, 6, q_10+571+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+93, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+93, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+93, 6, q_10+571+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+90, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+90, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+90, 6, q_10+571+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+87, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+87, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+87, 6, q_10+571+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+84, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+84, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+84, 6, q_10+571+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+81, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+81, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+81, 6, q_10+571+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+78, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+78, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+78, 6, q_10+571+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+75, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+75, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+75, 6, q_10+571+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+72, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+72, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+72, 6, q_10+571+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+69, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+69, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+69, 6, q_10+571+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+66, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+66, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+66, 6, q_10+571+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+63, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+63, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+63, 6, q_10+571+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+60, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+60, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+60, 6, q_10+571+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+57, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+57, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+57, 6, q_10+571+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+54, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+54, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+54, 6, q_10+571+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+51, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+51, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+51, 6, q_10+571+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+48, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+48, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+48, 6, q_10+571+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+45, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+45, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+45, 6, q_10+571+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+42, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+42, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+42, 6, q_10+571+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+39, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+39, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+39, 6, q_10+571+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+36, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+36, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+36, 6, q_10+571+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+33, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+33, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+33, 6, q_10+571+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+30, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+30, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+30, 6, q_10+571+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+27, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+27, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+27, 6, q_10+571+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+24, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+24, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+24, 6, q_10+571+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+21, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+21, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+21, 6, q_10+571+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+18, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+18, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+18, 6, q_10+571+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+15, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+15, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+15, 6, q_10+571+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+12, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+12, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+12, 6, q_10+571+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+9, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+9, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+9, 6, q_10+571+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+6, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+6, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+6, 6, q_10+571+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+3, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+3, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+3, 6, q_10+571+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+0, 3, p_00+861);
	GF2X_MUL(6, temp2, 3, q_11+858+0, 3, p_10+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+571+0, 6, q_10+571+0, 6, temp);
	memset(q_11+571, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(282, temp, 141, p_01+861+3, 141, q_10+858);
	GF2X_MUL(282, temp2, 141, p_11+861+3, 141, q_11+858);
	gf2x_add(282, q_11+571+3, 282, temp, 282, temp2);
	GF2X_MUL(6, temp, 3, q_10+858+138, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+138, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+138, 6, q_11+571+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+135, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+135, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+135, 6, q_11+571+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+132, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+132, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+132, 6, q_11+571+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+129, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+129, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+129, 6, q_11+571+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+126, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+126, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+126, 6, q_11+571+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+123, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+123, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+123, 6, q_11+571+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+120, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+120, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+120, 6, q_11+571+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+117, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+117, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+117, 6, q_11+571+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+114, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+114, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+114, 6, q_11+571+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+111, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+111, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+111, 6, q_11+571+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+108, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+108, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+108, 6, q_11+571+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+105, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+105, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+105, 6, q_11+571+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+102, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+102, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+102, 6, q_11+571+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+99, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+99, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+99, 6, q_11+571+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+96, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+96, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+96, 6, q_11+571+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+93, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+93, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+93, 6, q_11+571+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+90, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+90, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+90, 6, q_11+571+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+87, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+87, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+87, 6, q_11+571+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+84, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+84, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+84, 6, q_11+571+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+81, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+81, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+81, 6, q_11+571+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+78, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+78, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+78, 6, q_11+571+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+75, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+75, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+75, 6, q_11+571+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+72, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+72, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+72, 6, q_11+571+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+69, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+69, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+69, 6, q_11+571+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+66, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+66, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+66, 6, q_11+571+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+63, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+63, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+63, 6, q_11+571+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+60, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+60, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+60, 6, q_11+571+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+57, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+57, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+57, 6, q_11+571+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+54, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+54, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+54, 6, q_11+571+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+51, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+51, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+51, 6, q_11+571+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+48, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+48, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+48, 6, q_11+571+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+45, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+45, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+45, 6, q_11+571+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+42, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+42, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+42, 6, q_11+571+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+39, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+39, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+39, 6, q_11+571+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+36, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+36, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+36, 6, q_11+571+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+33, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+33, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+33, 6, q_11+571+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+30, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+30, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+30, 6, q_11+571+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+27, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+27, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+27, 6, q_11+571+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+24, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+24, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+24, 6, q_11+571+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+21, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+21, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+21, 6, q_11+571+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+18, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+18, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+18, 6, q_11+571+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+15, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+15, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+15, 6, q_11+571+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+12, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+12, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+12, 6, q_11+571+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+9, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+9, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+9, 6, q_11+571+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+6, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+6, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+6, 6, q_11+571+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+3, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+3, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+3, 6, q_11+571+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+858+0, 3, p_01+861);
	GF2X_MUL(6, temp2, 3, q_11+858+0, 3, p_11+861);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+571+0, 6, q_11+571+0, 6, temp);
	

	// Recombining results: n: 36537, depth: 1
	memset(q_00+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(570, temp, 285, p_00+574+2, 285, q_00+571);
	GF2X_MUL(570, temp2, 285, p_10+574+2, 285, q_01+571);
	gf2x_add(570, q_00+0+1, 570, temp, 570, temp2);
	GF2X_MUL(4, temp, 2, q_00+571+283, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+283, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+282, 4, q_00+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+281, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+281, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+280, 4, q_00+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+279, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+279, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+278, 4, q_00+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+277, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+277, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+276, 4, q_00+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+275, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+275, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+274, 4, q_00+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+273, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+273, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+272, 4, q_00+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+271, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+271, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+270, 4, q_00+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+269, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+269, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+268, 4, q_00+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+267, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+267, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+266, 4, q_00+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+265, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+265, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+264, 4, q_00+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+263, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+263, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+262, 4, q_00+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+261, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+261, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+260, 4, q_00+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+259, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+259, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+258, 4, q_00+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+257, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+257, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+256, 4, q_00+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+255, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+255, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+254, 4, q_00+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+253, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+253, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+252, 4, q_00+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+251, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+251, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+250, 4, q_00+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+249, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+249, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+248, 4, q_00+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+247, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+247, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+246, 4, q_00+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+245, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+245, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+244, 4, q_00+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+243, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+243, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+242, 4, q_00+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+241, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+241, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+240, 4, q_00+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+239, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+239, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+238, 4, q_00+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+237, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+237, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+236, 4, q_00+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+235, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+235, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+234, 4, q_00+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+233, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+233, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+232, 4, q_00+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+231, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+231, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+230, 4, q_00+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+229, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+229, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+228, 4, q_00+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+227, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+227, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+226, 4, q_00+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+225, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+225, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+224, 4, q_00+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+223, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+223, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+222, 4, q_00+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+221, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+221, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+220, 4, q_00+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+219, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+219, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+218, 4, q_00+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+217, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+217, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+216, 4, q_00+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+215, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+215, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+214, 4, q_00+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+213, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+213, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+212, 4, q_00+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+211, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+211, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+210, 4, q_00+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+209, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+209, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+208, 4, q_00+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+207, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+207, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+206, 4, q_00+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+205, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+205, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+204, 4, q_00+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+203, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+203, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+202, 4, q_00+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+201, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+201, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+200, 4, q_00+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+199, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+199, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+198, 4, q_00+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+197, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+197, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+196, 4, q_00+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+195, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+195, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+194, 4, q_00+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+193, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+193, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+192, 4, q_00+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+191, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+191, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+190, 4, q_00+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+189, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+189, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+188, 4, q_00+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+187, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+187, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+186, 4, q_00+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+185, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+185, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+184, 4, q_00+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+183, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+183, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+182, 4, q_00+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+181, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+181, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+180, 4, q_00+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+179, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+179, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+178, 4, q_00+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+177, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+177, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+176, 4, q_00+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+175, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+175, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+174, 4, q_00+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+173, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+173, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+172, 4, q_00+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+171, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+171, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+170, 4, q_00+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+169, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+169, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+168, 4, q_00+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+167, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+167, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+166, 4, q_00+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+165, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+165, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+164, 4, q_00+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+163, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+163, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+162, 4, q_00+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+161, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+161, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+160, 4, q_00+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+159, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+159, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+158, 4, q_00+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+157, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+157, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+156, 4, q_00+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+155, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+155, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+154, 4, q_00+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+153, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+153, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+152, 4, q_00+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+151, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+151, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+150, 4, q_00+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+149, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+149, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+148, 4, q_00+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+147, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+147, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+146, 4, q_00+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+145, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+145, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+144, 4, q_00+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+143, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+143, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+142, 4, q_00+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+141, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+141, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+140, 4, q_00+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+139, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+139, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+138, 4, q_00+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+137, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+137, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+136, 4, q_00+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+135, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+135, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+134, 4, q_00+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+133, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+133, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+132, 4, q_00+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+131, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+131, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+130, 4, q_00+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+129, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+129, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+128, 4, q_00+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+127, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+127, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+126, 4, q_00+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+125, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+125, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+124, 4, q_00+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+123, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+123, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+122, 4, q_00+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+121, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+121, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+120, 4, q_00+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+119, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+119, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+118, 4, q_00+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+117, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+117, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+116, 4, q_00+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+115, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+115, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+114, 4, q_00+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+113, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+113, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+112, 4, q_00+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+111, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+111, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+110, 4, q_00+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+109, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+109, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+108, 4, q_00+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+107, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+107, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+106, 4, q_00+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+105, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+105, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+104, 4, q_00+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+103, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+103, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+102, 4, q_00+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+101, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+101, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+100, 4, q_00+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+99, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+99, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+98, 4, q_00+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+97, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+97, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+96, 4, q_00+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+95, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+95, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+94, 4, q_00+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+93, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+93, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+92, 4, q_00+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+91, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+91, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+90, 4, q_00+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+89, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+89, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+88, 4, q_00+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+87, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+87, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+86, 4, q_00+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+85, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+85, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+84, 4, q_00+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+83, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+83, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+82, 4, q_00+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+81, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+81, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+80, 4, q_00+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+79, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+79, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+78, 4, q_00+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+77, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+77, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+76, 4, q_00+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+75, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+75, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+74, 4, q_00+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+73, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+73, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+72, 4, q_00+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+71, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+71, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+70, 4, q_00+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+69, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+69, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+68, 4, q_00+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+67, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+67, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+66, 4, q_00+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+65, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+65, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+64, 4, q_00+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+63, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+63, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+62, 4, q_00+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+61, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+61, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+60, 4, q_00+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+59, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+59, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+58, 4, q_00+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+57, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+57, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+56, 4, q_00+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+55, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+55, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+54, 4, q_00+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+53, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+53, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+52, 4, q_00+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+51, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+51, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+50, 4, q_00+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+49, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+49, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+48, 4, q_00+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+47, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+47, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+46, 4, q_00+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+45, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+45, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+44, 4, q_00+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+43, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+43, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+42, 4, q_00+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+41, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+41, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+40, 4, q_00+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+39, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+39, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+38, 4, q_00+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+37, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+37, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+36, 4, q_00+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+35, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+35, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+34, 4, q_00+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+33, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+33, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+32, 4, q_00+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+31, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+31, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+30, 4, q_00+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+29, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+29, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+28, 4, q_00+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+27, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+27, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+26, 4, q_00+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+25, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+25, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+24, 4, q_00+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+23, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+23, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+22, 4, q_00+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+21, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+21, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+20, 4, q_00+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+19, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+19, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+18, 4, q_00+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+17, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+17, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+16, 4, q_00+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+15, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+15, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+14, 4, q_00+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+13, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+13, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+12, 4, q_00+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+11, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+11, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+10, 4, q_00+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+9, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+9, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+8, 4, q_00+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+7, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+7, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+6, 4, q_00+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+5, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+5, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+4, 4, q_00+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+3, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+3, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+2, 4, q_00+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+1, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_01+571+1, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+0, 4, q_00+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+574+1, 1, q_00+571);
	GF2X_MUL(2, temp2, 1, p_10+574+1, 1, q_01+571);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+571+0, 1, p_00+574);
	GF2X_MUL(2, temp2, 1, q_01+571+0, 1, p_10+574);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+0, 1, q_00+0, 1, temp+1);
	memset(q_01+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(570, temp, 285, p_01+574+2, 285, q_00+571);
	GF2X_MUL(570, temp2, 285, p_11+574+2, 285, q_01+571);
	gf2x_add(570, q_01+0+1, 570, temp, 570, temp2);
	GF2X_MUL(4, temp, 2, q_00+571+283, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+283, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+282, 4, q_01+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+281, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+281, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+280, 4, q_01+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+279, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+279, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+278, 4, q_01+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+277, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+277, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+276, 4, q_01+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+275, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+275, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+274, 4, q_01+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+273, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+273, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+272, 4, q_01+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+271, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+271, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+270, 4, q_01+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+269, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+269, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+268, 4, q_01+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+267, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+267, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+266, 4, q_01+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+265, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+265, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+264, 4, q_01+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+263, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+263, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+262, 4, q_01+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+261, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+261, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+260, 4, q_01+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+259, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+259, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+258, 4, q_01+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+257, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+257, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+256, 4, q_01+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+255, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+255, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+254, 4, q_01+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+253, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+253, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+252, 4, q_01+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+251, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+251, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+250, 4, q_01+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+249, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+249, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+248, 4, q_01+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+247, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+247, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+246, 4, q_01+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+245, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+245, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+244, 4, q_01+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+243, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+243, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+242, 4, q_01+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+241, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+241, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+240, 4, q_01+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+239, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+239, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+238, 4, q_01+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+237, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+237, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+236, 4, q_01+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+235, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+235, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+234, 4, q_01+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+233, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+233, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+232, 4, q_01+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+231, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+231, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+230, 4, q_01+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+229, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+229, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+228, 4, q_01+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+227, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+227, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+226, 4, q_01+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+225, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+225, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+224, 4, q_01+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+223, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+223, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+222, 4, q_01+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+221, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+221, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+220, 4, q_01+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+219, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+219, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+218, 4, q_01+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+217, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+217, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+216, 4, q_01+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+215, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+215, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+214, 4, q_01+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+213, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+213, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+212, 4, q_01+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+211, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+211, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+210, 4, q_01+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+209, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+209, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+208, 4, q_01+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+207, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+207, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+206, 4, q_01+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+205, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+205, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+204, 4, q_01+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+203, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+203, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+202, 4, q_01+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+201, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+201, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+200, 4, q_01+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+199, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+199, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+198, 4, q_01+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+197, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+197, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+196, 4, q_01+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+195, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+195, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+194, 4, q_01+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+193, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+193, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+192, 4, q_01+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+191, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+191, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+190, 4, q_01+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+189, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+189, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+188, 4, q_01+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+187, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+187, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+186, 4, q_01+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+185, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+185, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+184, 4, q_01+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+183, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+183, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+182, 4, q_01+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+181, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+181, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+180, 4, q_01+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+179, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+179, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+178, 4, q_01+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+177, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+177, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+176, 4, q_01+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+175, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+175, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+174, 4, q_01+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+173, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+173, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+172, 4, q_01+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+171, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+171, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+170, 4, q_01+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+169, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+169, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+168, 4, q_01+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+167, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+167, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+166, 4, q_01+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+165, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+165, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+164, 4, q_01+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+163, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+163, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+162, 4, q_01+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+161, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+161, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+160, 4, q_01+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+159, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+159, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+158, 4, q_01+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+157, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+157, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+156, 4, q_01+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+155, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+155, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+154, 4, q_01+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+153, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+153, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+152, 4, q_01+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+151, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+151, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+150, 4, q_01+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+149, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+149, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+148, 4, q_01+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+147, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+147, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+146, 4, q_01+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+145, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+145, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+144, 4, q_01+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+143, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+143, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+142, 4, q_01+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+141, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+141, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+140, 4, q_01+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+139, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+139, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+138, 4, q_01+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+137, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+137, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+136, 4, q_01+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+135, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+135, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+134, 4, q_01+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+133, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+133, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+132, 4, q_01+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+131, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+131, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+130, 4, q_01+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+129, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+129, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+128, 4, q_01+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+127, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+127, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+126, 4, q_01+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+125, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+125, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+124, 4, q_01+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+123, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+123, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+122, 4, q_01+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+121, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+121, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+120, 4, q_01+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+119, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+119, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+118, 4, q_01+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+117, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+117, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+116, 4, q_01+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+115, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+115, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+114, 4, q_01+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+113, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+113, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+112, 4, q_01+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+111, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+111, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+110, 4, q_01+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+109, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+109, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+108, 4, q_01+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+107, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+107, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+106, 4, q_01+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+105, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+105, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+104, 4, q_01+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+103, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+103, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+102, 4, q_01+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+101, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+101, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+100, 4, q_01+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+99, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+99, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+98, 4, q_01+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+97, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+97, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+96, 4, q_01+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+95, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+95, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+94, 4, q_01+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+93, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+93, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+92, 4, q_01+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+91, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+91, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+90, 4, q_01+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+89, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+89, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+88, 4, q_01+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+87, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+87, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+86, 4, q_01+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+85, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+85, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+84, 4, q_01+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+83, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+83, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+82, 4, q_01+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+81, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+81, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+80, 4, q_01+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+79, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+79, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+78, 4, q_01+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+77, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+77, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+76, 4, q_01+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+75, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+75, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+74, 4, q_01+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+73, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+73, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+72, 4, q_01+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+71, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+71, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+70, 4, q_01+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+69, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+69, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+68, 4, q_01+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+67, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+67, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+66, 4, q_01+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+65, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+65, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+64, 4, q_01+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+63, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+63, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+62, 4, q_01+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+61, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+61, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+60, 4, q_01+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+59, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+59, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+58, 4, q_01+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+57, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+57, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+56, 4, q_01+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+55, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+55, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+54, 4, q_01+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+53, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+53, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+52, 4, q_01+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+51, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+51, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+50, 4, q_01+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+49, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+49, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+48, 4, q_01+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+47, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+47, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+46, 4, q_01+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+45, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+45, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+44, 4, q_01+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+43, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+43, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+42, 4, q_01+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+41, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+41, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+40, 4, q_01+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+39, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+39, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+38, 4, q_01+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+37, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+37, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+36, 4, q_01+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+35, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+35, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+34, 4, q_01+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+33, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+33, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+32, 4, q_01+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+31, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+31, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+30, 4, q_01+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+29, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+29, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+28, 4, q_01+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+27, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+27, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+26, 4, q_01+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+25, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+25, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+24, 4, q_01+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+23, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+23, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+22, 4, q_01+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+21, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+21, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+20, 4, q_01+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+19, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+19, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+18, 4, q_01+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+17, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+17, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+16, 4, q_01+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+15, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+15, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+14, 4, q_01+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+13, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+13, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+12, 4, q_01+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+11, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+11, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+10, 4, q_01+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+9, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+9, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+8, 4, q_01+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+7, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+7, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+6, 4, q_01+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+5, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+5, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+4, 4, q_01+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+3, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+3, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+2, 4, q_01+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+571+1, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_01+571+1, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+0, 4, q_01+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+574+1, 1, q_00+571);
	GF2X_MUL(2, temp2, 1, p_11+574+1, 1, q_01+571);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+571+0, 1, p_01+574);
	GF2X_MUL(2, temp2, 1, q_01+571+0, 1, p_11+574);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+0, 1, q_01+0, 1, temp+1);
	memset(q_10+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(570, temp, 285, p_00+574+2, 285, q_10+571);
	GF2X_MUL(570, temp2, 285, p_10+574+2, 285, q_11+571);
	gf2x_add(570, q_10+0+1, 570, temp, 570, temp2);
	GF2X_MUL(4, temp, 2, q_10+571+283, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+283, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+282, 4, q_10+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+281, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+281, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+280, 4, q_10+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+279, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+279, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+278, 4, q_10+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+277, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+277, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+276, 4, q_10+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+275, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+275, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+274, 4, q_10+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+273, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+273, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+272, 4, q_10+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+271, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+271, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+270, 4, q_10+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+269, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+269, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+268, 4, q_10+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+267, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+267, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+266, 4, q_10+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+265, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+265, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+264, 4, q_10+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+263, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+263, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+262, 4, q_10+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+261, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+261, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+260, 4, q_10+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+259, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+259, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+258, 4, q_10+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+257, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+257, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+256, 4, q_10+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+255, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+255, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+254, 4, q_10+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+253, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+253, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+252, 4, q_10+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+251, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+251, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+250, 4, q_10+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+249, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+249, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+248, 4, q_10+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+247, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+247, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+246, 4, q_10+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+245, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+245, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+244, 4, q_10+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+243, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+243, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+242, 4, q_10+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+241, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+241, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+240, 4, q_10+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+239, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+239, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+238, 4, q_10+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+237, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+237, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+236, 4, q_10+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+235, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+235, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+234, 4, q_10+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+233, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+233, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+232, 4, q_10+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+231, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+231, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+230, 4, q_10+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+229, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+229, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+228, 4, q_10+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+227, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+227, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+226, 4, q_10+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+225, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+225, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+224, 4, q_10+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+223, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+223, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+222, 4, q_10+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+221, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+221, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+220, 4, q_10+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+219, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+219, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+218, 4, q_10+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+217, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+217, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+216, 4, q_10+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+215, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+215, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+214, 4, q_10+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+213, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+213, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+212, 4, q_10+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+211, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+211, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+210, 4, q_10+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+209, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+209, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+208, 4, q_10+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+207, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+207, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+206, 4, q_10+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+205, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+205, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+204, 4, q_10+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+203, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+203, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+202, 4, q_10+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+201, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+201, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+200, 4, q_10+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+199, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+199, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+198, 4, q_10+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+197, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+197, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+196, 4, q_10+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+195, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+195, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+194, 4, q_10+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+193, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+193, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+192, 4, q_10+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+191, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+191, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+190, 4, q_10+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+189, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+189, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+188, 4, q_10+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+187, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+187, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+186, 4, q_10+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+185, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+185, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+184, 4, q_10+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+183, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+183, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+182, 4, q_10+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+181, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+181, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+180, 4, q_10+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+179, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+179, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+178, 4, q_10+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+177, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+177, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+176, 4, q_10+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+175, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+175, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+174, 4, q_10+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+173, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+173, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+172, 4, q_10+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+171, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+171, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+170, 4, q_10+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+169, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+169, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+168, 4, q_10+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+167, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+167, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+166, 4, q_10+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+165, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+165, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+164, 4, q_10+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+163, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+163, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+162, 4, q_10+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+161, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+161, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+160, 4, q_10+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+159, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+159, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+158, 4, q_10+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+157, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+157, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+156, 4, q_10+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+155, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+155, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+154, 4, q_10+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+153, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+153, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+152, 4, q_10+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+151, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+151, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+150, 4, q_10+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+149, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+149, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+148, 4, q_10+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+147, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+147, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+146, 4, q_10+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+145, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+145, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+144, 4, q_10+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+143, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+143, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+142, 4, q_10+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+141, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+141, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+140, 4, q_10+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+139, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+139, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+138, 4, q_10+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+137, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+137, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+136, 4, q_10+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+135, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+135, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+134, 4, q_10+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+133, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+133, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+132, 4, q_10+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+131, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+131, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+130, 4, q_10+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+129, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+129, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+128, 4, q_10+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+127, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+127, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+126, 4, q_10+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+125, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+125, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+124, 4, q_10+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+123, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+123, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+122, 4, q_10+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+121, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+121, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+120, 4, q_10+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+119, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+119, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+118, 4, q_10+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+117, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+117, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+116, 4, q_10+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+115, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+115, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+114, 4, q_10+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+113, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+113, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+112, 4, q_10+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+111, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+111, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+110, 4, q_10+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+109, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+109, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+108, 4, q_10+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+107, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+107, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+106, 4, q_10+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+105, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+105, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+104, 4, q_10+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+103, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+103, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+102, 4, q_10+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+101, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+101, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+100, 4, q_10+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+99, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+99, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+98, 4, q_10+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+97, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+97, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+96, 4, q_10+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+95, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+95, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+94, 4, q_10+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+93, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+93, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+92, 4, q_10+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+91, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+91, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+90, 4, q_10+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+89, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+89, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+88, 4, q_10+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+87, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+87, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+86, 4, q_10+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+85, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+85, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+84, 4, q_10+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+83, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+83, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+82, 4, q_10+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+81, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+81, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+80, 4, q_10+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+79, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+79, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+78, 4, q_10+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+77, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+77, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+76, 4, q_10+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+75, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+75, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+74, 4, q_10+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+73, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+73, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+72, 4, q_10+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+71, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+71, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+70, 4, q_10+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+69, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+69, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+68, 4, q_10+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+67, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+67, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+66, 4, q_10+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+65, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+65, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+64, 4, q_10+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+63, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+63, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+62, 4, q_10+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+61, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+61, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+60, 4, q_10+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+59, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+59, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+58, 4, q_10+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+57, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+57, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+56, 4, q_10+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+55, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+55, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+54, 4, q_10+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+53, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+53, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+52, 4, q_10+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+51, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+51, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+50, 4, q_10+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+49, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+49, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+48, 4, q_10+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+47, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+47, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+46, 4, q_10+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+45, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+45, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+44, 4, q_10+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+43, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+43, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+42, 4, q_10+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+41, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+41, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+40, 4, q_10+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+39, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+39, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+38, 4, q_10+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+37, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+37, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+36, 4, q_10+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+35, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+35, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+34, 4, q_10+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+33, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+33, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+32, 4, q_10+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+31, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+31, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+30, 4, q_10+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+29, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+29, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+28, 4, q_10+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+27, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+27, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+26, 4, q_10+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+25, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+25, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+24, 4, q_10+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+23, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+23, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+22, 4, q_10+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+21, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+21, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+20, 4, q_10+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+19, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+19, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+18, 4, q_10+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+17, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+17, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+16, 4, q_10+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+15, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+15, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+14, 4, q_10+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+13, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+13, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+12, 4, q_10+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+11, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+11, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+10, 4, q_10+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+9, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+9, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+8, 4, q_10+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+7, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+7, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+6, 4, q_10+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+5, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+5, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+4, 4, q_10+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+3, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+3, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+2, 4, q_10+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+1, 2, p_00+574);
	GF2X_MUL(4, temp2, 2, q_11+571+1, 2, p_10+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+0, 4, q_10+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+574+1, 1, q_10+571);
	GF2X_MUL(2, temp2, 1, p_10+574+1, 1, q_11+571);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+571+0, 1, p_00+574);
	GF2X_MUL(2, temp2, 1, q_11+571+0, 1, p_10+574);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+0, 1, q_10+0, 1, temp+1);
	memset(q_11+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(570, temp, 285, p_01+574+2, 285, q_10+571);
	GF2X_MUL(570, temp2, 285, p_11+574+2, 285, q_11+571);
	gf2x_add(570, q_11+0+1, 570, temp, 570, temp2);
	GF2X_MUL(4, temp, 2, q_10+571+283, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+283, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+282, 4, q_11+0+282, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+281, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+281, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+280, 4, q_11+0+280, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+279, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+279, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+278, 4, q_11+0+278, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+277, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+277, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+276, 4, q_11+0+276, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+275, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+275, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+274, 4, q_11+0+274, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+273, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+273, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+272, 4, q_11+0+272, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+271, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+271, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+270, 4, q_11+0+270, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+269, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+269, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+268, 4, q_11+0+268, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+267, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+267, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+266, 4, q_11+0+266, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+265, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+265, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+264, 4, q_11+0+264, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+263, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+263, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+262, 4, q_11+0+262, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+261, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+261, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+260, 4, q_11+0+260, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+259, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+259, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+258, 4, q_11+0+258, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+257, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+257, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+256, 4, q_11+0+256, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+255, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+255, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+254, 4, q_11+0+254, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+253, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+253, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+252, 4, q_11+0+252, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+251, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+251, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+250, 4, q_11+0+250, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+249, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+249, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+248, 4, q_11+0+248, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+247, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+247, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+246, 4, q_11+0+246, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+245, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+245, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+244, 4, q_11+0+244, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+243, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+243, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+242, 4, q_11+0+242, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+241, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+241, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+240, 4, q_11+0+240, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+239, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+239, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+238, 4, q_11+0+238, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+237, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+237, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+236, 4, q_11+0+236, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+235, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+235, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+234, 4, q_11+0+234, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+233, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+233, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+232, 4, q_11+0+232, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+231, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+231, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+230, 4, q_11+0+230, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+229, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+229, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+228, 4, q_11+0+228, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+227, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+227, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+226, 4, q_11+0+226, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+225, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+225, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+224, 4, q_11+0+224, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+223, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+223, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+222, 4, q_11+0+222, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+221, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+221, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+220, 4, q_11+0+220, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+219, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+219, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+218, 4, q_11+0+218, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+217, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+217, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+216, 4, q_11+0+216, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+215, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+215, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+214, 4, q_11+0+214, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+213, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+213, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+212, 4, q_11+0+212, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+211, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+211, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+210, 4, q_11+0+210, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+209, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+209, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+208, 4, q_11+0+208, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+207, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+207, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+206, 4, q_11+0+206, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+205, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+205, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+204, 4, q_11+0+204, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+203, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+203, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+202, 4, q_11+0+202, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+201, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+201, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+200, 4, q_11+0+200, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+199, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+199, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+198, 4, q_11+0+198, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+197, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+197, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+196, 4, q_11+0+196, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+195, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+195, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+194, 4, q_11+0+194, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+193, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+193, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+192, 4, q_11+0+192, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+191, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+191, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+190, 4, q_11+0+190, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+189, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+189, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+188, 4, q_11+0+188, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+187, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+187, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+186, 4, q_11+0+186, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+185, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+185, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+184, 4, q_11+0+184, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+183, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+183, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+182, 4, q_11+0+182, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+181, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+181, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+180, 4, q_11+0+180, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+179, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+179, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+178, 4, q_11+0+178, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+177, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+177, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+176, 4, q_11+0+176, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+175, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+175, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+174, 4, q_11+0+174, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+173, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+173, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+172, 4, q_11+0+172, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+171, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+171, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+170, 4, q_11+0+170, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+169, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+169, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+168, 4, q_11+0+168, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+167, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+167, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+166, 4, q_11+0+166, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+165, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+165, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+164, 4, q_11+0+164, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+163, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+163, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+162, 4, q_11+0+162, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+161, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+161, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+160, 4, q_11+0+160, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+159, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+159, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+158, 4, q_11+0+158, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+157, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+157, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+156, 4, q_11+0+156, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+155, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+155, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+154, 4, q_11+0+154, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+153, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+153, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+152, 4, q_11+0+152, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+151, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+151, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+150, 4, q_11+0+150, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+149, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+149, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+148, 4, q_11+0+148, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+147, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+147, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+146, 4, q_11+0+146, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+145, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+145, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+144, 4, q_11+0+144, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+143, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+143, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+142, 4, q_11+0+142, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+141, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+141, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+140, 4, q_11+0+140, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+139, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+139, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+138, 4, q_11+0+138, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+137, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+137, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+136, 4, q_11+0+136, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+135, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+135, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+134, 4, q_11+0+134, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+133, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+133, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+132, 4, q_11+0+132, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+131, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+131, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+130, 4, q_11+0+130, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+129, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+129, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+128, 4, q_11+0+128, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+127, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+127, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+126, 4, q_11+0+126, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+125, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+125, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+124, 4, q_11+0+124, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+123, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+123, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+122, 4, q_11+0+122, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+121, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+121, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+120, 4, q_11+0+120, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+119, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+119, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+118, 4, q_11+0+118, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+117, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+117, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+116, 4, q_11+0+116, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+115, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+115, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+114, 4, q_11+0+114, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+113, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+113, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+112, 4, q_11+0+112, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+111, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+111, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+110, 4, q_11+0+110, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+109, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+109, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+108, 4, q_11+0+108, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+107, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+107, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+106, 4, q_11+0+106, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+105, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+105, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+104, 4, q_11+0+104, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+103, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+103, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+102, 4, q_11+0+102, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+101, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+101, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+100, 4, q_11+0+100, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+99, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+99, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+98, 4, q_11+0+98, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+97, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+97, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+96, 4, q_11+0+96, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+95, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+95, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+94, 4, q_11+0+94, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+93, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+93, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+92, 4, q_11+0+92, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+91, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+91, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+90, 4, q_11+0+90, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+89, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+89, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+88, 4, q_11+0+88, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+87, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+87, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+86, 4, q_11+0+86, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+85, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+85, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+84, 4, q_11+0+84, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+83, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+83, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+82, 4, q_11+0+82, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+81, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+81, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+80, 4, q_11+0+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+79, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+79, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+78, 4, q_11+0+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+77, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+77, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+76, 4, q_11+0+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+75, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+75, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+74, 4, q_11+0+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+73, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+73, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+72, 4, q_11+0+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+71, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+71, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+70, 4, q_11+0+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+69, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+69, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+68, 4, q_11+0+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+67, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+67, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+66, 4, q_11+0+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+65, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+65, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+64, 4, q_11+0+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+63, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+63, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+62, 4, q_11+0+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+61, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+61, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+60, 4, q_11+0+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+59, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+59, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+58, 4, q_11+0+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+57, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+57, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+56, 4, q_11+0+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+55, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+55, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+54, 4, q_11+0+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+53, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+53, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+52, 4, q_11+0+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+51, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+51, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+50, 4, q_11+0+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+49, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+49, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+48, 4, q_11+0+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+47, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+47, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+46, 4, q_11+0+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+45, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+45, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+44, 4, q_11+0+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+43, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+43, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+42, 4, q_11+0+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+41, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+41, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+40, 4, q_11+0+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+39, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+39, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+38, 4, q_11+0+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+37, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+37, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+36, 4, q_11+0+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+35, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+35, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+34, 4, q_11+0+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+33, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+33, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+32, 4, q_11+0+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+31, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+31, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+30, 4, q_11+0+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+29, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+29, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+28, 4, q_11+0+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+27, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+27, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+26, 4, q_11+0+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+25, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+25, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+24, 4, q_11+0+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+23, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+23, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+22, 4, q_11+0+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+21, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+21, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+20, 4, q_11+0+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+19, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+19, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+18, 4, q_11+0+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+17, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+17, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+16, 4, q_11+0+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+15, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+15, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+14, 4, q_11+0+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+13, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+13, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+12, 4, q_11+0+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+11, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+11, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+10, 4, q_11+0+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+9, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+9, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+8, 4, q_11+0+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+7, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+7, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+6, 4, q_11+0+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+5, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+5, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+4, 4, q_11+0+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+3, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+3, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+2, 4, q_11+0+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+571+1, 2, p_01+574);
	GF2X_MUL(4, temp2, 2, q_11+571+1, 2, p_11+574);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+0, 4, q_11+0+0, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+574+1, 1, q_10+571);
	GF2X_MUL(2, temp2, 1, p_11+574+1, 1, q_11+571);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+571+0, 1, p_01+574);
	GF2X_MUL(2, temp2, 1, q_11+571+0, 1, p_11+574);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+0, 1, q_11+0, 1, temp+1);
	

	// Recombining results: n: 73257, depth: 0
	memset(t_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(1142, temp, 571, p_00+0+3, 571, q_00+0);
	GF2X_MUL(1142, temp2, 571, p_10+0+3, 571, q_01+0);
	gf2x_add(1142, t_00+0+3, 1142, temp, 1142, temp2);
	GF2X_MUL(6, temp, 3, q_00+0+568, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+568, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+568, 6, t_00+0+568, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+565, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+565, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+565, 6, t_00+0+565, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+562, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+562, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+562, 6, t_00+0+562, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+559, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+559, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+559, 6, t_00+0+559, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+556, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+556, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+556, 6, t_00+0+556, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+553, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+553, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+553, 6, t_00+0+553, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+550, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+550, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+550, 6, t_00+0+550, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+547, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+547, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+547, 6, t_00+0+547, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+544, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+544, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+544, 6, t_00+0+544, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+541, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+541, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+541, 6, t_00+0+541, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+538, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+538, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+538, 6, t_00+0+538, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+535, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+535, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+535, 6, t_00+0+535, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+532, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+532, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+532, 6, t_00+0+532, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+529, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+529, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+529, 6, t_00+0+529, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+526, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+526, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+526, 6, t_00+0+526, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+523, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+523, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+523, 6, t_00+0+523, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+520, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+520, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+520, 6, t_00+0+520, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+517, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+517, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+517, 6, t_00+0+517, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+514, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+514, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+514, 6, t_00+0+514, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+511, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+511, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+511, 6, t_00+0+511, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+508, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+508, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+508, 6, t_00+0+508, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+505, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+505, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+505, 6, t_00+0+505, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+502, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+502, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+502, 6, t_00+0+502, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+499, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+499, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+499, 6, t_00+0+499, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+496, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+496, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+496, 6, t_00+0+496, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+493, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+493, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+493, 6, t_00+0+493, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+490, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+490, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+490, 6, t_00+0+490, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+487, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+487, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+487, 6, t_00+0+487, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+484, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+484, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+484, 6, t_00+0+484, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+481, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+481, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+481, 6, t_00+0+481, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+478, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+478, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+478, 6, t_00+0+478, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+475, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+475, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+475, 6, t_00+0+475, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+472, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+472, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+472, 6, t_00+0+472, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+469, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+469, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+469, 6, t_00+0+469, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+466, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+466, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+466, 6, t_00+0+466, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+463, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+463, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+463, 6, t_00+0+463, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+460, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+460, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+460, 6, t_00+0+460, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+457, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+457, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+457, 6, t_00+0+457, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+454, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+454, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+454, 6, t_00+0+454, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+451, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+451, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+451, 6, t_00+0+451, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+448, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+448, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+448, 6, t_00+0+448, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+445, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+445, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+445, 6, t_00+0+445, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+442, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+442, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+442, 6, t_00+0+442, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+439, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+439, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+439, 6, t_00+0+439, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+436, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+436, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+436, 6, t_00+0+436, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+433, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+433, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+433, 6, t_00+0+433, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+430, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+430, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+430, 6, t_00+0+430, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+427, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+427, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+427, 6, t_00+0+427, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+424, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+424, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+424, 6, t_00+0+424, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+421, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+421, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+421, 6, t_00+0+421, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+418, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+418, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+418, 6, t_00+0+418, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+415, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+415, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+415, 6, t_00+0+415, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+412, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+412, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+412, 6, t_00+0+412, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+409, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+409, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+409, 6, t_00+0+409, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+406, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+406, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+406, 6, t_00+0+406, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+403, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+403, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+403, 6, t_00+0+403, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+400, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+400, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+400, 6, t_00+0+400, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+397, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+397, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+397, 6, t_00+0+397, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+394, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+394, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+394, 6, t_00+0+394, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+391, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+391, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+391, 6, t_00+0+391, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+388, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+388, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+388, 6, t_00+0+388, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+385, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+385, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+385, 6, t_00+0+385, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+382, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+382, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+382, 6, t_00+0+382, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+379, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+379, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+379, 6, t_00+0+379, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+376, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+376, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+376, 6, t_00+0+376, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+373, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+373, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+373, 6, t_00+0+373, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+370, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+370, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+370, 6, t_00+0+370, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+367, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+367, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+367, 6, t_00+0+367, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+364, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+364, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+364, 6, t_00+0+364, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+361, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+361, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+361, 6, t_00+0+361, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+358, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+358, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+358, 6, t_00+0+358, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+355, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+355, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+355, 6, t_00+0+355, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+352, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+352, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+352, 6, t_00+0+352, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+349, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+349, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+349, 6, t_00+0+349, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+346, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+346, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+346, 6, t_00+0+346, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+343, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+343, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+343, 6, t_00+0+343, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+340, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+340, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+340, 6, t_00+0+340, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+337, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+337, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+337, 6, t_00+0+337, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+334, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+334, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+334, 6, t_00+0+334, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+331, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+331, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+331, 6, t_00+0+331, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+328, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+328, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+328, 6, t_00+0+328, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+325, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+325, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+325, 6, t_00+0+325, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+322, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+322, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+322, 6, t_00+0+322, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+319, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+319, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+319, 6, t_00+0+319, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+316, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+316, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+316, 6, t_00+0+316, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+313, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+313, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+313, 6, t_00+0+313, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+310, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+310, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+310, 6, t_00+0+310, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+307, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+307, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+307, 6, t_00+0+307, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+304, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+304, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+304, 6, t_00+0+304, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+301, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+301, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+301, 6, t_00+0+301, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+298, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+298, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+298, 6, t_00+0+298, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+295, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+295, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+295, 6, t_00+0+295, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+292, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+292, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+292, 6, t_00+0+292, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+289, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+289, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+289, 6, t_00+0+289, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+286, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+286, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+286, 6, t_00+0+286, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+283, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+283, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+283, 6, t_00+0+283, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+280, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+280, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+280, 6, t_00+0+280, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+277, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+277, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+277, 6, t_00+0+277, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+274, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+274, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+274, 6, t_00+0+274, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+271, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+271, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+271, 6, t_00+0+271, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+268, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+268, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+268, 6, t_00+0+268, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+265, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+265, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+265, 6, t_00+0+265, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+262, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+262, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+262, 6, t_00+0+262, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+259, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+259, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+259, 6, t_00+0+259, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+256, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+256, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+256, 6, t_00+0+256, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+253, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+253, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+253, 6, t_00+0+253, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+250, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+250, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+250, 6, t_00+0+250, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+247, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+247, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+247, 6, t_00+0+247, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+244, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+244, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+244, 6, t_00+0+244, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+241, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+241, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+241, 6, t_00+0+241, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+238, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+238, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+238, 6, t_00+0+238, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+235, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+235, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+235, 6, t_00+0+235, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+232, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+232, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+232, 6, t_00+0+232, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+229, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+229, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+229, 6, t_00+0+229, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+226, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+226, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+226, 6, t_00+0+226, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+223, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+223, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+223, 6, t_00+0+223, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+220, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+220, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+220, 6, t_00+0+220, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+217, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+217, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+217, 6, t_00+0+217, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+214, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+214, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+214, 6, t_00+0+214, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+211, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+211, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+211, 6, t_00+0+211, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+208, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+208, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+208, 6, t_00+0+208, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+205, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+205, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+205, 6, t_00+0+205, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+202, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+202, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+202, 6, t_00+0+202, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+199, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+199, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+199, 6, t_00+0+199, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+196, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+196, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+196, 6, t_00+0+196, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+193, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+193, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+193, 6, t_00+0+193, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+190, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+190, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+190, 6, t_00+0+190, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+187, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+187, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+187, 6, t_00+0+187, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+184, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+184, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+184, 6, t_00+0+184, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+181, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+181, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+181, 6, t_00+0+181, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+178, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+178, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+178, 6, t_00+0+178, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+175, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+175, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+175, 6, t_00+0+175, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+172, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+172, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+172, 6, t_00+0+172, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+169, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+169, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+169, 6, t_00+0+169, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+166, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+166, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+166, 6, t_00+0+166, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+163, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+163, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+163, 6, t_00+0+163, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+160, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+160, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+160, 6, t_00+0+160, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+157, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+157, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+157, 6, t_00+0+157, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+154, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+154, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+154, 6, t_00+0+154, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+151, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+151, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+151, 6, t_00+0+151, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+148, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+148, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+148, 6, t_00+0+148, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+145, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+145, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+145, 6, t_00+0+145, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+142, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+142, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+142, 6, t_00+0+142, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+139, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+139, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+139, 6, t_00+0+139, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+136, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+136, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+136, 6, t_00+0+136, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+133, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+133, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+133, 6, t_00+0+133, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+130, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+130, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+130, 6, t_00+0+130, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+127, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+127, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+127, 6, t_00+0+127, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+124, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+124, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+124, 6, t_00+0+124, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+121, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+121, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+121, 6, t_00+0+121, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+118, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+118, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+118, 6, t_00+0+118, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+115, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+115, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+115, 6, t_00+0+115, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+112, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+112, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+112, 6, t_00+0+112, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+109, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+109, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+109, 6, t_00+0+109, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+106, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+106, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+106, 6, t_00+0+106, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+103, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+103, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+103, 6, t_00+0+103, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+100, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+100, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+100, 6, t_00+0+100, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+97, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+97, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+97, 6, t_00+0+97, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+94, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+94, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+94, 6, t_00+0+94, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+91, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+91, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+91, 6, t_00+0+91, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+88, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+88, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+88, 6, t_00+0+88, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+85, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+85, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+85, 6, t_00+0+85, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+82, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+82, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+82, 6, t_00+0+82, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+79, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+79, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+79, 6, t_00+0+79, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+76, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+76, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+76, 6, t_00+0+76, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+73, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+73, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+73, 6, t_00+0+73, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+70, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+70, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+70, 6, t_00+0+70, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+67, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+67, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+67, 6, t_00+0+67, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+64, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+64, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+64, 6, t_00+0+64, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+61, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+61, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+61, 6, t_00+0+61, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+58, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+58, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+58, 6, t_00+0+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+55, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+55, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+55, 6, t_00+0+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+52, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+52, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+52, 6, t_00+0+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+49, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+49, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+49, 6, t_00+0+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+46, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+46, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+46, 6, t_00+0+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+43, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+43, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+43, 6, t_00+0+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+40, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+40, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+40, 6, t_00+0+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+37, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+37, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+37, 6, t_00+0+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+34, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+34, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+34, 6, t_00+0+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+31, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+31, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+31, 6, t_00+0+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+28, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+28, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+28, 6, t_00+0+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+25, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+25, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+25, 6, t_00+0+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+22, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+22, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+22, 6, t_00+0+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+19, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+19, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+19, 6, t_00+0+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+16, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+16, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+16, 6, t_00+0+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+13, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+13, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+13, 6, t_00+0+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+10, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+10, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+10, 6, t_00+0+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+7, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+7, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+7, 6, t_00+0+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+4, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+4, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+4, 6, t_00+0+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+1, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+1, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+1, 6, t_00+0+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+0+2, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+2, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+2, 2, t_00+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+1, 2, t_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	memset(t_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(1142, temp, 571, p_01+0+3, 571, q_00+0);
	GF2X_MUL(1142, temp2, 571, p_11+0+3, 571, q_01+0);
	gf2x_add(1142, t_01+0+3, 1142, temp, 1142, temp2);
	GF2X_MUL(6, temp, 3, q_00+0+568, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+568, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+568, 6, t_01+0+568, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+565, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+565, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+565, 6, t_01+0+565, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+562, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+562, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+562, 6, t_01+0+562, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+559, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+559, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+559, 6, t_01+0+559, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+556, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+556, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+556, 6, t_01+0+556, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+553, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+553, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+553, 6, t_01+0+553, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+550, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+550, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+550, 6, t_01+0+550, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+547, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+547, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+547, 6, t_01+0+547, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+544, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+544, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+544, 6, t_01+0+544, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+541, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+541, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+541, 6, t_01+0+541, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+538, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+538, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+538, 6, t_01+0+538, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+535, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+535, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+535, 6, t_01+0+535, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+532, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+532, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+532, 6, t_01+0+532, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+529, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+529, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+529, 6, t_01+0+529, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+526, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+526, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+526, 6, t_01+0+526, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+523, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+523, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+523, 6, t_01+0+523, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+520, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+520, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+520, 6, t_01+0+520, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+517, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+517, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+517, 6, t_01+0+517, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+514, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+514, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+514, 6, t_01+0+514, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+511, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+511, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+511, 6, t_01+0+511, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+508, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+508, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+508, 6, t_01+0+508, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+505, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+505, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+505, 6, t_01+0+505, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+502, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+502, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+502, 6, t_01+0+502, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+499, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+499, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+499, 6, t_01+0+499, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+496, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+496, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+496, 6, t_01+0+496, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+493, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+493, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+493, 6, t_01+0+493, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+490, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+490, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+490, 6, t_01+0+490, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+487, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+487, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+487, 6, t_01+0+487, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+484, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+484, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+484, 6, t_01+0+484, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+481, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+481, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+481, 6, t_01+0+481, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+478, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+478, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+478, 6, t_01+0+478, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+475, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+475, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+475, 6, t_01+0+475, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+472, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+472, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+472, 6, t_01+0+472, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+469, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+469, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+469, 6, t_01+0+469, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+466, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+466, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+466, 6, t_01+0+466, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+463, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+463, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+463, 6, t_01+0+463, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+460, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+460, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+460, 6, t_01+0+460, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+457, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+457, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+457, 6, t_01+0+457, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+454, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+454, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+454, 6, t_01+0+454, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+451, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+451, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+451, 6, t_01+0+451, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+448, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+448, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+448, 6, t_01+0+448, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+445, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+445, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+445, 6, t_01+0+445, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+442, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+442, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+442, 6, t_01+0+442, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+439, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+439, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+439, 6, t_01+0+439, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+436, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+436, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+436, 6, t_01+0+436, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+433, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+433, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+433, 6, t_01+0+433, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+430, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+430, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+430, 6, t_01+0+430, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+427, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+427, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+427, 6, t_01+0+427, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+424, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+424, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+424, 6, t_01+0+424, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+421, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+421, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+421, 6, t_01+0+421, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+418, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+418, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+418, 6, t_01+0+418, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+415, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+415, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+415, 6, t_01+0+415, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+412, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+412, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+412, 6, t_01+0+412, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+409, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+409, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+409, 6, t_01+0+409, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+406, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+406, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+406, 6, t_01+0+406, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+403, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+403, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+403, 6, t_01+0+403, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+400, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+400, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+400, 6, t_01+0+400, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+397, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+397, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+397, 6, t_01+0+397, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+394, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+394, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+394, 6, t_01+0+394, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+391, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+391, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+391, 6, t_01+0+391, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+388, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+388, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+388, 6, t_01+0+388, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+385, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+385, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+385, 6, t_01+0+385, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+382, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+382, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+382, 6, t_01+0+382, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+379, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+379, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+379, 6, t_01+0+379, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+376, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+376, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+376, 6, t_01+0+376, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+373, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+373, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+373, 6, t_01+0+373, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+370, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+370, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+370, 6, t_01+0+370, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+367, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+367, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+367, 6, t_01+0+367, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+364, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+364, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+364, 6, t_01+0+364, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+361, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+361, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+361, 6, t_01+0+361, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+358, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+358, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+358, 6, t_01+0+358, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+355, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+355, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+355, 6, t_01+0+355, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+352, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+352, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+352, 6, t_01+0+352, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+349, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+349, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+349, 6, t_01+0+349, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+346, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+346, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+346, 6, t_01+0+346, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+343, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+343, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+343, 6, t_01+0+343, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+340, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+340, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+340, 6, t_01+0+340, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+337, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+337, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+337, 6, t_01+0+337, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+334, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+334, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+334, 6, t_01+0+334, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+331, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+331, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+331, 6, t_01+0+331, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+328, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+328, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+328, 6, t_01+0+328, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+325, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+325, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+325, 6, t_01+0+325, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+322, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+322, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+322, 6, t_01+0+322, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+319, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+319, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+319, 6, t_01+0+319, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+316, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+316, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+316, 6, t_01+0+316, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+313, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+313, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+313, 6, t_01+0+313, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+310, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+310, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+310, 6, t_01+0+310, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+307, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+307, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+307, 6, t_01+0+307, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+304, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+304, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+304, 6, t_01+0+304, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+301, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+301, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+301, 6, t_01+0+301, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+298, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+298, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+298, 6, t_01+0+298, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+295, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+295, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+295, 6, t_01+0+295, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+292, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+292, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+292, 6, t_01+0+292, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+289, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+289, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+289, 6, t_01+0+289, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+286, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+286, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+286, 6, t_01+0+286, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+283, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+283, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+283, 6, t_01+0+283, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+280, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+280, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+280, 6, t_01+0+280, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+277, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+277, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+277, 6, t_01+0+277, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+274, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+274, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+274, 6, t_01+0+274, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+271, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+271, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+271, 6, t_01+0+271, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+268, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+268, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+268, 6, t_01+0+268, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+265, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+265, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+265, 6, t_01+0+265, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+262, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+262, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+262, 6, t_01+0+262, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+259, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+259, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+259, 6, t_01+0+259, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+256, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+256, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+256, 6, t_01+0+256, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+253, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+253, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+253, 6, t_01+0+253, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+250, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+250, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+250, 6, t_01+0+250, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+247, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+247, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+247, 6, t_01+0+247, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+244, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+244, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+244, 6, t_01+0+244, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+241, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+241, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+241, 6, t_01+0+241, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+238, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+238, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+238, 6, t_01+0+238, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+235, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+235, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+235, 6, t_01+0+235, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+232, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+232, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+232, 6, t_01+0+232, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+229, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+229, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+229, 6, t_01+0+229, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+226, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+226, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+226, 6, t_01+0+226, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+223, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+223, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+223, 6, t_01+0+223, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+220, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+220, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+220, 6, t_01+0+220, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+217, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+217, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+217, 6, t_01+0+217, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+214, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+214, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+214, 6, t_01+0+214, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+211, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+211, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+211, 6, t_01+0+211, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+208, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+208, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+208, 6, t_01+0+208, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+205, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+205, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+205, 6, t_01+0+205, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+202, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+202, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+202, 6, t_01+0+202, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+199, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+199, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+199, 6, t_01+0+199, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+196, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+196, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+196, 6, t_01+0+196, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+193, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+193, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+193, 6, t_01+0+193, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+190, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+190, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+190, 6, t_01+0+190, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+187, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+187, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+187, 6, t_01+0+187, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+184, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+184, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+184, 6, t_01+0+184, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+181, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+181, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+181, 6, t_01+0+181, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+178, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+178, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+178, 6, t_01+0+178, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+175, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+175, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+175, 6, t_01+0+175, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+172, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+172, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+172, 6, t_01+0+172, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+169, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+169, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+169, 6, t_01+0+169, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+166, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+166, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+166, 6, t_01+0+166, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+163, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+163, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+163, 6, t_01+0+163, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+160, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+160, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+160, 6, t_01+0+160, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+157, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+157, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+157, 6, t_01+0+157, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+154, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+154, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+154, 6, t_01+0+154, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+151, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+151, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+151, 6, t_01+0+151, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+148, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+148, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+148, 6, t_01+0+148, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+145, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+145, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+145, 6, t_01+0+145, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+142, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+142, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+142, 6, t_01+0+142, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+139, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+139, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+139, 6, t_01+0+139, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+136, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+136, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+136, 6, t_01+0+136, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+133, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+133, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+133, 6, t_01+0+133, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+130, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+130, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+130, 6, t_01+0+130, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+127, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+127, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+127, 6, t_01+0+127, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+124, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+124, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+124, 6, t_01+0+124, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+121, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+121, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+121, 6, t_01+0+121, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+118, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+118, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+118, 6, t_01+0+118, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+115, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+115, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+115, 6, t_01+0+115, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+112, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+112, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+112, 6, t_01+0+112, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+109, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+109, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+109, 6, t_01+0+109, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+106, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+106, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+106, 6, t_01+0+106, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+103, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+103, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+103, 6, t_01+0+103, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+100, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+100, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+100, 6, t_01+0+100, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+97, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+97, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+97, 6, t_01+0+97, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+94, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+94, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+94, 6, t_01+0+94, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+91, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+91, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+91, 6, t_01+0+91, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+88, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+88, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+88, 6, t_01+0+88, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+85, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+85, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+85, 6, t_01+0+85, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+82, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+82, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+82, 6, t_01+0+82, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+79, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+79, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+79, 6, t_01+0+79, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+76, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+76, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+76, 6, t_01+0+76, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+73, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+73, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+73, 6, t_01+0+73, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+70, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+70, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+70, 6, t_01+0+70, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+67, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+67, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+67, 6, t_01+0+67, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+64, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+64, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+64, 6, t_01+0+64, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+61, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+61, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+61, 6, t_01+0+61, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+58, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+58, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+58, 6, t_01+0+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+55, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+55, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+55, 6, t_01+0+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+52, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+52, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+52, 6, t_01+0+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+49, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+49, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+49, 6, t_01+0+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+46, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+46, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+46, 6, t_01+0+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+43, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+43, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+43, 6, t_01+0+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+40, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+40, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+40, 6, t_01+0+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+37, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+37, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+37, 6, t_01+0+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+34, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+34, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+34, 6, t_01+0+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+31, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+31, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+31, 6, t_01+0+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+28, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+28, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+28, 6, t_01+0+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+25, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+25, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+25, 6, t_01+0+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+22, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+22, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+22, 6, t_01+0+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+19, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+19, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+19, 6, t_01+0+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+16, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+16, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+16, 6, t_01+0+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+13, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+13, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+13, 6, t_01+0+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+10, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+10, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+10, 6, t_01+0+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+7, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+7, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+7, 6, t_01+0+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+4, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+4, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+4, 6, t_01+0+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+1, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+1, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+1, 6, t_01+0+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+0+2, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+2, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+2, 2, t_01+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+1, 2, t_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	memset(t_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(1142, temp, 571, p_00+0+3, 571, q_10+0);
	GF2X_MUL(1142, temp2, 571, p_10+0+3, 571, q_11+0);
	gf2x_add(1142, t_10+0+3, 1142, temp, 1142, temp2);
	GF2X_MUL(6, temp, 3, q_10+0+568, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+568, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+568, 6, t_10+0+568, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+565, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+565, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+565, 6, t_10+0+565, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+562, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+562, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+562, 6, t_10+0+562, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+559, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+559, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+559, 6, t_10+0+559, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+556, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+556, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+556, 6, t_10+0+556, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+553, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+553, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+553, 6, t_10+0+553, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+550, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+550, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+550, 6, t_10+0+550, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+547, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+547, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+547, 6, t_10+0+547, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+544, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+544, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+544, 6, t_10+0+544, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+541, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+541, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+541, 6, t_10+0+541, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+538, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+538, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+538, 6, t_10+0+538, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+535, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+535, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+535, 6, t_10+0+535, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+532, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+532, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+532, 6, t_10+0+532, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+529, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+529, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+529, 6, t_10+0+529, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+526, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+526, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+526, 6, t_10+0+526, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+523, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+523, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+523, 6, t_10+0+523, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+520, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+520, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+520, 6, t_10+0+520, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+517, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+517, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+517, 6, t_10+0+517, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+514, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+514, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+514, 6, t_10+0+514, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+511, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+511, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+511, 6, t_10+0+511, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+508, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+508, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+508, 6, t_10+0+508, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+505, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+505, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+505, 6, t_10+0+505, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+502, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+502, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+502, 6, t_10+0+502, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+499, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+499, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+499, 6, t_10+0+499, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+496, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+496, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+496, 6, t_10+0+496, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+493, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+493, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+493, 6, t_10+0+493, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+490, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+490, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+490, 6, t_10+0+490, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+487, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+487, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+487, 6, t_10+0+487, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+484, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+484, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+484, 6, t_10+0+484, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+481, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+481, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+481, 6, t_10+0+481, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+478, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+478, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+478, 6, t_10+0+478, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+475, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+475, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+475, 6, t_10+0+475, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+472, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+472, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+472, 6, t_10+0+472, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+469, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+469, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+469, 6, t_10+0+469, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+466, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+466, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+466, 6, t_10+0+466, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+463, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+463, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+463, 6, t_10+0+463, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+460, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+460, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+460, 6, t_10+0+460, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+457, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+457, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+457, 6, t_10+0+457, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+454, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+454, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+454, 6, t_10+0+454, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+451, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+451, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+451, 6, t_10+0+451, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+448, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+448, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+448, 6, t_10+0+448, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+445, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+445, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+445, 6, t_10+0+445, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+442, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+442, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+442, 6, t_10+0+442, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+439, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+439, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+439, 6, t_10+0+439, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+436, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+436, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+436, 6, t_10+0+436, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+433, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+433, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+433, 6, t_10+0+433, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+430, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+430, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+430, 6, t_10+0+430, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+427, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+427, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+427, 6, t_10+0+427, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+424, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+424, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+424, 6, t_10+0+424, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+421, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+421, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+421, 6, t_10+0+421, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+418, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+418, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+418, 6, t_10+0+418, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+415, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+415, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+415, 6, t_10+0+415, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+412, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+412, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+412, 6, t_10+0+412, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+409, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+409, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+409, 6, t_10+0+409, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+406, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+406, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+406, 6, t_10+0+406, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+403, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+403, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+403, 6, t_10+0+403, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+400, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+400, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+400, 6, t_10+0+400, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+397, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+397, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+397, 6, t_10+0+397, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+394, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+394, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+394, 6, t_10+0+394, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+391, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+391, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+391, 6, t_10+0+391, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+388, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+388, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+388, 6, t_10+0+388, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+385, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+385, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+385, 6, t_10+0+385, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+382, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+382, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+382, 6, t_10+0+382, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+379, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+379, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+379, 6, t_10+0+379, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+376, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+376, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+376, 6, t_10+0+376, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+373, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+373, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+373, 6, t_10+0+373, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+370, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+370, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+370, 6, t_10+0+370, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+367, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+367, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+367, 6, t_10+0+367, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+364, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+364, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+364, 6, t_10+0+364, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+361, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+361, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+361, 6, t_10+0+361, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+358, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+358, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+358, 6, t_10+0+358, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+355, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+355, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+355, 6, t_10+0+355, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+352, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+352, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+352, 6, t_10+0+352, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+349, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+349, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+349, 6, t_10+0+349, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+346, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+346, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+346, 6, t_10+0+346, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+343, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+343, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+343, 6, t_10+0+343, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+340, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+340, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+340, 6, t_10+0+340, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+337, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+337, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+337, 6, t_10+0+337, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+334, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+334, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+334, 6, t_10+0+334, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+331, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+331, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+331, 6, t_10+0+331, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+328, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+328, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+328, 6, t_10+0+328, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+325, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+325, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+325, 6, t_10+0+325, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+322, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+322, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+322, 6, t_10+0+322, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+319, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+319, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+319, 6, t_10+0+319, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+316, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+316, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+316, 6, t_10+0+316, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+313, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+313, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+313, 6, t_10+0+313, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+310, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+310, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+310, 6, t_10+0+310, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+307, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+307, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+307, 6, t_10+0+307, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+304, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+304, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+304, 6, t_10+0+304, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+301, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+301, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+301, 6, t_10+0+301, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+298, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+298, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+298, 6, t_10+0+298, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+295, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+295, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+295, 6, t_10+0+295, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+292, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+292, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+292, 6, t_10+0+292, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+289, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+289, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+289, 6, t_10+0+289, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+286, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+286, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+286, 6, t_10+0+286, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+283, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+283, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+283, 6, t_10+0+283, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+280, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+280, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+280, 6, t_10+0+280, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+277, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+277, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+277, 6, t_10+0+277, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+274, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+274, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+274, 6, t_10+0+274, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+271, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+271, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+271, 6, t_10+0+271, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+268, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+268, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+268, 6, t_10+0+268, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+265, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+265, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+265, 6, t_10+0+265, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+262, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+262, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+262, 6, t_10+0+262, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+259, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+259, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+259, 6, t_10+0+259, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+256, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+256, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+256, 6, t_10+0+256, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+253, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+253, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+253, 6, t_10+0+253, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+250, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+250, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+250, 6, t_10+0+250, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+247, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+247, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+247, 6, t_10+0+247, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+244, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+244, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+244, 6, t_10+0+244, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+241, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+241, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+241, 6, t_10+0+241, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+238, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+238, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+238, 6, t_10+0+238, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+235, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+235, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+235, 6, t_10+0+235, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+232, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+232, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+232, 6, t_10+0+232, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+229, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+229, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+229, 6, t_10+0+229, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+226, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+226, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+226, 6, t_10+0+226, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+223, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+223, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+223, 6, t_10+0+223, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+220, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+220, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+220, 6, t_10+0+220, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+217, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+217, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+217, 6, t_10+0+217, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+214, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+214, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+214, 6, t_10+0+214, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+211, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+211, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+211, 6, t_10+0+211, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+208, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+208, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+208, 6, t_10+0+208, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+205, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+205, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+205, 6, t_10+0+205, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+202, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+202, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+202, 6, t_10+0+202, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+199, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+199, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+199, 6, t_10+0+199, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+196, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+196, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+196, 6, t_10+0+196, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+193, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+193, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+193, 6, t_10+0+193, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+190, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+190, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+190, 6, t_10+0+190, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+187, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+187, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+187, 6, t_10+0+187, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+184, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+184, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+184, 6, t_10+0+184, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+181, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+181, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+181, 6, t_10+0+181, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+178, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+178, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+178, 6, t_10+0+178, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+175, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+175, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+175, 6, t_10+0+175, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+172, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+172, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+172, 6, t_10+0+172, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+169, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+169, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+169, 6, t_10+0+169, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+166, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+166, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+166, 6, t_10+0+166, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+163, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+163, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+163, 6, t_10+0+163, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+160, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+160, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+160, 6, t_10+0+160, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+157, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+157, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+157, 6, t_10+0+157, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+154, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+154, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+154, 6, t_10+0+154, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+151, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+151, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+151, 6, t_10+0+151, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+148, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+148, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+148, 6, t_10+0+148, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+145, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+145, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+145, 6, t_10+0+145, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+142, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+142, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+142, 6, t_10+0+142, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+139, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+139, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+139, 6, t_10+0+139, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+136, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+136, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+136, 6, t_10+0+136, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+133, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+133, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+133, 6, t_10+0+133, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+130, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+130, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+130, 6, t_10+0+130, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+127, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+127, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+127, 6, t_10+0+127, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+124, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+124, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+124, 6, t_10+0+124, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+121, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+121, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+121, 6, t_10+0+121, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+118, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+118, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+118, 6, t_10+0+118, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+115, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+115, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+115, 6, t_10+0+115, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+112, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+112, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+112, 6, t_10+0+112, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+109, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+109, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+109, 6, t_10+0+109, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+106, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+106, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+106, 6, t_10+0+106, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+103, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+103, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+103, 6, t_10+0+103, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+100, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+100, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+100, 6, t_10+0+100, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+97, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+97, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+97, 6, t_10+0+97, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+94, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+94, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+94, 6, t_10+0+94, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+91, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+91, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+91, 6, t_10+0+91, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+88, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+88, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+88, 6, t_10+0+88, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+85, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+85, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+85, 6, t_10+0+85, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+82, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+82, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+82, 6, t_10+0+82, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+79, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+79, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+79, 6, t_10+0+79, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+76, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+76, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+76, 6, t_10+0+76, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+73, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+73, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+73, 6, t_10+0+73, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+70, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+70, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+70, 6, t_10+0+70, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+67, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+67, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+67, 6, t_10+0+67, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+64, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+64, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+64, 6, t_10+0+64, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+61, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+61, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+61, 6, t_10+0+61, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+58, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+58, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+58, 6, t_10+0+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+55, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+55, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+55, 6, t_10+0+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+52, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+52, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+52, 6, t_10+0+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+49, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+49, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+49, 6, t_10+0+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+46, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+46, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+46, 6, t_10+0+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+43, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+43, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+43, 6, t_10+0+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+40, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+40, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+40, 6, t_10+0+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+37, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+37, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+37, 6, t_10+0+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+34, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+34, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+34, 6, t_10+0+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+31, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+31, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+31, 6, t_10+0+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+28, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+28, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+28, 6, t_10+0+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+25, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+25, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+25, 6, t_10+0+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+22, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+22, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+22, 6, t_10+0+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+19, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+19, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+19, 6, t_10+0+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+16, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+16, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+16, 6, t_10+0+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+13, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+13, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+13, 6, t_10+0+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+10, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+10, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+10, 6, t_10+0+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+7, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+7, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+7, 6, t_10+0+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+4, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+4, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+4, 6, t_10+0+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+1, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+1, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+1, 6, t_10+0+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+0+2, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+2, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+2, 2, t_10+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+1, 2, t_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	memset(t_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(1142, temp, 571, p_01+0+3, 571, q_10+0);
	GF2X_MUL(1142, temp2, 571, p_11+0+3, 571, q_11+0);
	gf2x_add(1142, t_11+0+3, 1142, temp, 1142, temp2);
	GF2X_MUL(6, temp, 3, q_10+0+568, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+568, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+568, 6, t_11+0+568, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+565, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+565, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+565, 6, t_11+0+565, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+562, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+562, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+562, 6, t_11+0+562, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+559, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+559, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+559, 6, t_11+0+559, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+556, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+556, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+556, 6, t_11+0+556, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+553, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+553, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+553, 6, t_11+0+553, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+550, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+550, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+550, 6, t_11+0+550, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+547, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+547, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+547, 6, t_11+0+547, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+544, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+544, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+544, 6, t_11+0+544, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+541, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+541, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+541, 6, t_11+0+541, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+538, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+538, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+538, 6, t_11+0+538, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+535, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+535, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+535, 6, t_11+0+535, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+532, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+532, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+532, 6, t_11+0+532, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+529, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+529, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+529, 6, t_11+0+529, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+526, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+526, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+526, 6, t_11+0+526, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+523, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+523, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+523, 6, t_11+0+523, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+520, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+520, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+520, 6, t_11+0+520, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+517, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+517, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+517, 6, t_11+0+517, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+514, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+514, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+514, 6, t_11+0+514, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+511, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+511, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+511, 6, t_11+0+511, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+508, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+508, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+508, 6, t_11+0+508, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+505, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+505, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+505, 6, t_11+0+505, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+502, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+502, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+502, 6, t_11+0+502, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+499, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+499, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+499, 6, t_11+0+499, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+496, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+496, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+496, 6, t_11+0+496, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+493, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+493, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+493, 6, t_11+0+493, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+490, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+490, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+490, 6, t_11+0+490, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+487, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+487, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+487, 6, t_11+0+487, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+484, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+484, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+484, 6, t_11+0+484, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+481, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+481, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+481, 6, t_11+0+481, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+478, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+478, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+478, 6, t_11+0+478, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+475, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+475, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+475, 6, t_11+0+475, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+472, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+472, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+472, 6, t_11+0+472, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+469, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+469, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+469, 6, t_11+0+469, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+466, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+466, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+466, 6, t_11+0+466, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+463, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+463, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+463, 6, t_11+0+463, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+460, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+460, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+460, 6, t_11+0+460, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+457, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+457, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+457, 6, t_11+0+457, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+454, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+454, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+454, 6, t_11+0+454, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+451, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+451, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+451, 6, t_11+0+451, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+448, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+448, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+448, 6, t_11+0+448, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+445, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+445, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+445, 6, t_11+0+445, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+442, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+442, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+442, 6, t_11+0+442, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+439, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+439, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+439, 6, t_11+0+439, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+436, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+436, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+436, 6, t_11+0+436, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+433, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+433, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+433, 6, t_11+0+433, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+430, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+430, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+430, 6, t_11+0+430, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+427, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+427, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+427, 6, t_11+0+427, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+424, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+424, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+424, 6, t_11+0+424, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+421, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+421, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+421, 6, t_11+0+421, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+418, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+418, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+418, 6, t_11+0+418, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+415, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+415, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+415, 6, t_11+0+415, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+412, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+412, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+412, 6, t_11+0+412, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+409, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+409, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+409, 6, t_11+0+409, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+406, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+406, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+406, 6, t_11+0+406, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+403, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+403, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+403, 6, t_11+0+403, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+400, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+400, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+400, 6, t_11+0+400, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+397, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+397, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+397, 6, t_11+0+397, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+394, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+394, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+394, 6, t_11+0+394, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+391, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+391, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+391, 6, t_11+0+391, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+388, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+388, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+388, 6, t_11+0+388, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+385, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+385, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+385, 6, t_11+0+385, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+382, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+382, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+382, 6, t_11+0+382, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+379, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+379, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+379, 6, t_11+0+379, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+376, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+376, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+376, 6, t_11+0+376, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+373, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+373, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+373, 6, t_11+0+373, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+370, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+370, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+370, 6, t_11+0+370, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+367, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+367, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+367, 6, t_11+0+367, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+364, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+364, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+364, 6, t_11+0+364, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+361, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+361, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+361, 6, t_11+0+361, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+358, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+358, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+358, 6, t_11+0+358, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+355, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+355, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+355, 6, t_11+0+355, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+352, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+352, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+352, 6, t_11+0+352, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+349, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+349, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+349, 6, t_11+0+349, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+346, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+346, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+346, 6, t_11+0+346, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+343, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+343, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+343, 6, t_11+0+343, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+340, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+340, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+340, 6, t_11+0+340, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+337, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+337, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+337, 6, t_11+0+337, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+334, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+334, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+334, 6, t_11+0+334, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+331, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+331, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+331, 6, t_11+0+331, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+328, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+328, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+328, 6, t_11+0+328, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+325, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+325, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+325, 6, t_11+0+325, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+322, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+322, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+322, 6, t_11+0+322, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+319, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+319, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+319, 6, t_11+0+319, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+316, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+316, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+316, 6, t_11+0+316, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+313, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+313, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+313, 6, t_11+0+313, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+310, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+310, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+310, 6, t_11+0+310, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+307, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+307, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+307, 6, t_11+0+307, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+304, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+304, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+304, 6, t_11+0+304, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+301, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+301, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+301, 6, t_11+0+301, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+298, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+298, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+298, 6, t_11+0+298, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+295, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+295, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+295, 6, t_11+0+295, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+292, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+292, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+292, 6, t_11+0+292, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+289, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+289, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+289, 6, t_11+0+289, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+286, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+286, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+286, 6, t_11+0+286, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+283, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+283, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+283, 6, t_11+0+283, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+280, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+280, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+280, 6, t_11+0+280, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+277, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+277, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+277, 6, t_11+0+277, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+274, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+274, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+274, 6, t_11+0+274, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+271, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+271, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+271, 6, t_11+0+271, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+268, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+268, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+268, 6, t_11+0+268, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+265, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+265, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+265, 6, t_11+0+265, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+262, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+262, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+262, 6, t_11+0+262, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+259, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+259, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+259, 6, t_11+0+259, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+256, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+256, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+256, 6, t_11+0+256, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+253, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+253, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+253, 6, t_11+0+253, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+250, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+250, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+250, 6, t_11+0+250, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+247, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+247, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+247, 6, t_11+0+247, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+244, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+244, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+244, 6, t_11+0+244, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+241, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+241, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+241, 6, t_11+0+241, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+238, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+238, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+238, 6, t_11+0+238, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+235, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+235, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+235, 6, t_11+0+235, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+232, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+232, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+232, 6, t_11+0+232, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+229, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+229, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+229, 6, t_11+0+229, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+226, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+226, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+226, 6, t_11+0+226, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+223, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+223, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+223, 6, t_11+0+223, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+220, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+220, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+220, 6, t_11+0+220, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+217, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+217, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+217, 6, t_11+0+217, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+214, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+214, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+214, 6, t_11+0+214, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+211, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+211, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+211, 6, t_11+0+211, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+208, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+208, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+208, 6, t_11+0+208, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+205, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+205, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+205, 6, t_11+0+205, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+202, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+202, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+202, 6, t_11+0+202, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+199, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+199, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+199, 6, t_11+0+199, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+196, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+196, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+196, 6, t_11+0+196, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+193, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+193, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+193, 6, t_11+0+193, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+190, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+190, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+190, 6, t_11+0+190, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+187, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+187, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+187, 6, t_11+0+187, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+184, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+184, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+184, 6, t_11+0+184, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+181, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+181, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+181, 6, t_11+0+181, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+178, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+178, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+178, 6, t_11+0+178, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+175, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+175, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+175, 6, t_11+0+175, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+172, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+172, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+172, 6, t_11+0+172, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+169, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+169, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+169, 6, t_11+0+169, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+166, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+166, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+166, 6, t_11+0+166, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+163, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+163, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+163, 6, t_11+0+163, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+160, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+160, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+160, 6, t_11+0+160, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+157, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+157, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+157, 6, t_11+0+157, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+154, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+154, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+154, 6, t_11+0+154, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+151, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+151, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+151, 6, t_11+0+151, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+148, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+148, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+148, 6, t_11+0+148, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+145, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+145, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+145, 6, t_11+0+145, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+142, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+142, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+142, 6, t_11+0+142, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+139, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+139, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+139, 6, t_11+0+139, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+136, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+136, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+136, 6, t_11+0+136, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+133, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+133, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+133, 6, t_11+0+133, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+130, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+130, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+130, 6, t_11+0+130, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+127, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+127, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+127, 6, t_11+0+127, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+124, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+124, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+124, 6, t_11+0+124, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+121, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+121, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+121, 6, t_11+0+121, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+118, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+118, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+118, 6, t_11+0+118, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+115, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+115, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+115, 6, t_11+0+115, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+112, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+112, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+112, 6, t_11+0+112, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+109, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+109, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+109, 6, t_11+0+109, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+106, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+106, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+106, 6, t_11+0+106, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+103, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+103, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+103, 6, t_11+0+103, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+100, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+100, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+100, 6, t_11+0+100, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+97, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+97, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+97, 6, t_11+0+97, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+94, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+94, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+94, 6, t_11+0+94, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+91, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+91, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+91, 6, t_11+0+91, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+88, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+88, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+88, 6, t_11+0+88, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+85, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+85, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+85, 6, t_11+0+85, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+82, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+82, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+82, 6, t_11+0+82, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+79, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+79, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+79, 6, t_11+0+79, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+76, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+76, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+76, 6, t_11+0+76, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+73, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+73, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+73, 6, t_11+0+73, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+70, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+70, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+70, 6, t_11+0+70, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+67, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+67, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+67, 6, t_11+0+67, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+64, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+64, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+64, 6, t_11+0+64, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+61, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+61, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+61, 6, t_11+0+61, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+58, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+58, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+58, 6, t_11+0+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+55, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+55, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+55, 6, t_11+0+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+52, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+52, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+52, 6, t_11+0+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+49, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+49, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+49, 6, t_11+0+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+46, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+46, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+46, 6, t_11+0+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+43, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+43, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+43, 6, t_11+0+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+40, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+40, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+40, 6, t_11+0+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+37, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+37, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+37, 6, t_11+0+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+34, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+34, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+34, 6, t_11+0+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+31, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+31, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+31, 6, t_11+0+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+28, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+28, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+28, 6, t_11+0+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+25, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+25, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+25, 6, t_11+0+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+22, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+22, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+22, 6, t_11+0+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+19, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+19, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+19, 6, t_11+0+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+16, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+16, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+16, 6, t_11+0+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+13, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+13, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+13, 6, t_11+0+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+10, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+10, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+10, 6, t_11+0+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+7, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+7, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+7, 6, t_11+0+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+4, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+4, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+4, 6, t_11+0+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+1, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+1, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+1, 6, t_11+0+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+0+2, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+2, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+2, 2, t_11+0+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+1, 2, t_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+0, 2, t_11+0+0, 2, temp);
	

	return delta;
}