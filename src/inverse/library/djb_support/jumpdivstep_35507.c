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

int jumpdivstep_35507(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[1129];
	DIGIT p_01[1129];
	DIGIT p_10[1129];
	DIGIT p_11[1129];
	
	DIGIT q_00[1107];
	DIGIT q_01[1107];
	DIGIT q_10[1107];
	DIGIT q_11[1107];
	
	DIGIT f_sum[3374];
	DIGIT g_sum[3374];
	
	DIGIT temp[2226];
	DIGIT temp2[2226];
	

	delta = divstepsx_256(255, delta, f+1106, g+1106, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+1102+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g+1102+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1102+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g+1102+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f+1102+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g+1102+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1102+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g+1102+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+1098+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g+1098+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f+1098);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g+1098);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f+1098+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g+1098+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f+1098);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g+1098);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+1090+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g+1090+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f+1090);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g+1090);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f+1090+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g+1090+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f+1090);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g+1090);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f+1074+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g+1074+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f+1074);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g+1074);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f+1074+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g+1074+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f+1074);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g+1074);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f+1038+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g+1038+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f+1038+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g+1038+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f+1038+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g+1038+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f+1038+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g+1038+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f+970+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g+970+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f+970);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g+970);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f+970+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g+970+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f+970);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g+970);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(p_00+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, p_00+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+64, 8, p_00+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+60, 8, p_00+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+56, 8, p_00+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+52, 8, p_00+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+48, 8, p_00+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+44, 8, p_00+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+40, 8, p_00+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+36, 8, p_00+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+32, 8, p_00+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+28, 8, p_00+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+24, 8, p_00+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+20, 8, p_00+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+16, 8, p_00+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+12, 8, p_00+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+8, 8, p_00+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+4, 8, p_00+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+0, 8, p_00+837+0, 8, temp);
	memset(p_01+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, p_01+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+64, 8, p_01+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+60, 8, p_01+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+56, 8, p_01+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+52, 8, p_01+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+48, 8, p_01+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+44, 8, p_01+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+40, 8, p_01+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+36, 8, p_01+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+32, 8, p_01+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+28, 8, p_01+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+24, 8, p_01+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+20, 8, p_01+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+16, 8, p_01+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+12, 8, p_01+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+8, 8, p_01+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+4, 8, p_01+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+0, 8, p_01+837+0, 8, temp);
	memset(p_10+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, p_10+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+64, 8, p_10+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+60, 8, p_10+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+56, 8, p_10+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+52, 8, p_10+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+48, 8, p_10+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+44, 8, p_10+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+40, 8, p_10+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+36, 8, p_10+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+32, 8, p_10+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+28, 8, p_10+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+24, 8, p_10+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+20, 8, p_10+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+16, 8, p_10+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+12, 8, p_10+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+8, 8, p_10+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+4, 8, p_10+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+0, 8, p_10+837+0, 8, temp);
	memset(p_11+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, p_11+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+64, 8, p_11+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+60, 8, p_11+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+56, 8, p_11+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+52, 8, p_11+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+48, 8, p_11+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+44, 8, p_11+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+40, 8, p_11+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+36, 8, p_11+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+32, 8, p_11+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+28, 8, p_11+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+24, 8, p_11+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+20, 8, p_11+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+16, 8, p_11+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+12, 8, p_11+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+8, 8, p_11+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+4, 8, p_11+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+0, 8, p_11+837+0, 8, temp);
	

	// Calculating left operands: n: 17850, depth: 2
	// Digits to shift: 139
	// Displacement: 139
	GF2X_MUL(280, temp, 140, f+831+139, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, g+831+139, 140, p_01+837);
	gf2x_add(280, f_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_00+837+1, 139, f+831);
	GF2X_MUL(278, temp2, 139, p_01+837+1, 139, g+831);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, f_sum+2507, 140, f_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f+831+138, 1, p_00+837);
	GF2X_MUL(2, temp2, 1, g+831+138, 1, p_01+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2507, 1, f_sum+2507, 1, temp+1);
	right_bit_shift_n(279, f_sum+2507, 29);
	GF2X_MUL(280, temp, 140, f+831+139, 140, p_10+837);
	GF2X_MUL(280, temp2, 140, g+831+139, 140, p_11+837);
	gf2x_add(280, g_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_10+837+1, 139, f+831);
	GF2X_MUL(278, temp2, 139, p_11+837+1, 139, g+831);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, g_sum+2507, 140, g_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f+831+138, 1, p_10+837);
	GF2X_MUL(2, temp2, 1, g+831+138, 1, p_11+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2507, 1, g_sum+2507, 1, temp+1);
	right_bit_shift_n(279, g_sum+2507, 29);
	

	delta = divstepsx_256(255, delta, f_sum+2644, g_sum+2644, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(q_00+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, q_00+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+64, 8, q_00+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+60, 8, q_00+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+56, 8, q_00+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+52, 8, q_00+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+48, 8, q_00+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+44, 8, q_00+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+40, 8, q_00+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+36, 8, q_00+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+32, 8, q_00+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+28, 8, q_00+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+24, 8, q_00+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+20, 8, q_00+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+16, 8, q_00+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+12, 8, q_00+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+8, 8, q_00+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+4, 8, q_00+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+0, 8, q_00+831+0, 8, temp);
	memset(q_01+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, q_01+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+64, 8, q_01+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+60, 8, q_01+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+56, 8, q_01+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+52, 8, q_01+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+48, 8, q_01+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+44, 8, q_01+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+40, 8, q_01+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+36, 8, q_01+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+32, 8, q_01+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+28, 8, q_01+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+24, 8, q_01+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+20, 8, q_01+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+16, 8, q_01+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+12, 8, q_01+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+8, 8, q_01+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+4, 8, q_01+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+0, 8, q_01+831+0, 8, temp);
	memset(q_10+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, q_10+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+64, 8, q_10+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+60, 8, q_10+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+56, 8, q_10+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+52, 8, q_10+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+48, 8, q_10+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+44, 8, q_10+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+40, 8, q_10+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+36, 8, q_10+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+32, 8, q_10+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+28, 8, q_10+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+24, 8, q_10+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+20, 8, q_10+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+16, 8, q_10+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+12, 8, q_10+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+8, 8, q_10+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+4, 8, q_10+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+0, 8, q_10+831+0, 8, temp);
	memset(q_11+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, q_11+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+64, 8, q_11+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+60, 8, q_11+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+56, 8, q_11+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+52, 8, q_11+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+48, 8, q_11+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+44, 8, q_11+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+40, 8, q_11+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+36, 8, q_11+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+32, 8, q_11+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+28, 8, q_11+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+24, 8, q_11+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+20, 8, q_11+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+16, 8, q_11+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+12, 8, q_11+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+8, 8, q_11+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+4, 8, q_11+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+0, 8, q_11+831+0, 8, temp);
	

	// Recombining results: n: 17850, depth: 2
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_10+837);
	gf2x_add(279, p_00+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_11+837);
	gf2x_add(279, p_01+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_10+837);
	gf2x_add(279, p_10+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_11+837);
	gf2x_add(279, p_11+558, 279, temp+1, 279, temp2+1);
	

	// Calculating left operands: n: 35700, depth: 1
	// Digits to shift: 278
	// Displacement: 279
	GF2X_MUL(558, temp, 279, f+552+279, 279, p_00+558);
	GF2X_MUL(558, temp2, 279, g+552+279, 279, p_01+558);
	gf2x_add(558, f_sum+1669+0, 558, temp, 558, temp2);
	GF2X_MUL(558, temp, 279, f+552+0, 279, p_00+558);
	GF2X_MUL(558, temp2, 279, g+552+0, 279, p_01+558);
	gf2x_add(558, temp, 558, temp, 558, temp2);
	gf2x_add(279, f_sum+1669, 279, f_sum+1669, 279, temp+279);
	right_bit_shift_n(558, f_sum+1669, 58);
	GF2X_MUL(558, temp, 279, f+552+279, 279, p_10+558);
	GF2X_MUL(558, temp2, 279, g+552+279, 279, p_11+558);
	gf2x_add(558, g_sum+1669+0, 558, temp, 558, temp2);
	GF2X_MUL(558, temp, 279, f+552+0, 279, p_10+558);
	GF2X_MUL(558, temp2, 279, g+552+0, 279, p_11+558);
	gf2x_add(558, temp, 558, temp, 558, temp2);
	gf2x_add(279, g_sum+1669, 279, g_sum+1669, 279, temp+279);
	right_bit_shift_n(558, g_sum+1669, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1945, g_sum+1945, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1941+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1941+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1941+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1941+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+1941+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1941+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1941+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1941+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1937+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+1937+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+1937);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+1937);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+1937+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+1937+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+1937);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+1937);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1929+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+1929+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+1929);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+1929);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+1929+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+1929+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+1929);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+1929);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1913+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+1913+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+1913);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+1913);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+1913+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+1913+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+1913);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+1913);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+1877+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1877+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1877+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1877+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+1877+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1877+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1877+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1877+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+1809+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+1809+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+1809);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+1809);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+1809+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+1809+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+1809);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+1809);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(p_00+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, p_00+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+64, 8, p_00+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+60, 8, p_00+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+56, 8, p_00+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+52, 8, p_00+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+48, 8, p_00+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+44, 8, p_00+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+40, 8, p_00+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+36, 8, p_00+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+32, 8, p_00+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+28, 8, p_00+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+24, 8, p_00+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+20, 8, p_00+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+16, 8, p_00+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+12, 8, p_00+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+8, 8, p_00+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+4, 8, p_00+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+0, 8, p_00+837+0, 8, temp);
	memset(p_01+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, p_01+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+64, 8, p_01+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+60, 8, p_01+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+56, 8, p_01+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+52, 8, p_01+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+48, 8, p_01+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+44, 8, p_01+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+40, 8, p_01+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+36, 8, p_01+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+32, 8, p_01+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+28, 8, p_01+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+24, 8, p_01+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+20, 8, p_01+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+16, 8, p_01+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+12, 8, p_01+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+8, 8, p_01+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+4, 8, p_01+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+0, 8, p_01+837+0, 8, temp);
	memset(p_10+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, p_10+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+64, 8, p_10+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+60, 8, p_10+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+56, 8, p_10+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+52, 8, p_10+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+48, 8, p_10+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+44, 8, p_10+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+40, 8, p_10+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+36, 8, p_10+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+32, 8, p_10+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+28, 8, p_10+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+24, 8, p_10+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+20, 8, p_10+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+16, 8, p_10+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+12, 8, p_10+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+8, 8, p_10+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+4, 8, p_10+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+0, 8, p_10+837+0, 8, temp);
	memset(p_11+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, p_11+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+64, 8, p_11+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+60, 8, p_11+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+56, 8, p_11+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+52, 8, p_11+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+48, 8, p_11+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+44, 8, p_11+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+40, 8, p_11+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+36, 8, p_11+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+32, 8, p_11+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+28, 8, p_11+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+24, 8, p_11+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+20, 8, p_11+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+16, 8, p_11+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+12, 8, p_11+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+8, 8, p_11+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+4, 8, p_11+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+0, 8, p_11+837+0, 8, temp);
	

	// Calculating left operands: n: 17850, depth: 2
	// Digits to shift: 139
	// Displacement: 139
	GF2X_MUL(280, temp, 140, f_sum+1670+139, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, g_sum+1670+139, 140, p_01+837);
	gf2x_add(280, f_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_00+837+1, 139, f_sum+1670);
	GF2X_MUL(278, temp2, 139, p_01+837+1, 139, g_sum+1670);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, f_sum+2507, 140, f_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f_sum+1670+138, 1, p_00+837);
	GF2X_MUL(2, temp2, 1, g_sum+1670+138, 1, p_01+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2507, 1, f_sum+2507, 1, temp+1);
	right_bit_shift_n(279, f_sum+2507, 29);
	GF2X_MUL(280, temp, 140, f_sum+1670+139, 140, p_10+837);
	GF2X_MUL(280, temp2, 140, g_sum+1670+139, 140, p_11+837);
	gf2x_add(280, g_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_10+837+1, 139, f_sum+1670);
	GF2X_MUL(278, temp2, 139, p_11+837+1, 139, g_sum+1670);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, g_sum+2507, 140, g_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f_sum+1670+138, 1, p_10+837);
	GF2X_MUL(2, temp2, 1, g_sum+1670+138, 1, p_11+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2507, 1, g_sum+2507, 1, temp+1);
	right_bit_shift_n(279, g_sum+2507, 29);
	

	delta = divstepsx_256(255, delta, f_sum+2644, g_sum+2644, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(q_00+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, q_00+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+64, 8, q_00+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+60, 8, q_00+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+56, 8, q_00+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+52, 8, q_00+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+48, 8, q_00+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+44, 8, q_00+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+40, 8, q_00+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+36, 8, q_00+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+32, 8, q_00+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+28, 8, q_00+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+24, 8, q_00+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+20, 8, q_00+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+16, 8, q_00+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+12, 8, q_00+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+8, 8, q_00+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+4, 8, q_00+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+0, 8, q_00+831+0, 8, temp);
	memset(q_01+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, q_01+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+64, 8, q_01+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+60, 8, q_01+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+56, 8, q_01+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+52, 8, q_01+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+48, 8, q_01+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+44, 8, q_01+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+40, 8, q_01+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+36, 8, q_01+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+32, 8, q_01+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+28, 8, q_01+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+24, 8, q_01+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+20, 8, q_01+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+16, 8, q_01+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+12, 8, q_01+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+8, 8, q_01+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+4, 8, q_01+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+0, 8, q_01+831+0, 8, temp);
	memset(q_10+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, q_10+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+64, 8, q_10+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+60, 8, q_10+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+56, 8, q_10+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+52, 8, q_10+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+48, 8, q_10+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+44, 8, q_10+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+40, 8, q_10+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+36, 8, q_10+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+32, 8, q_10+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+28, 8, q_10+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+24, 8, q_10+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+20, 8, q_10+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+16, 8, q_10+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+12, 8, q_10+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+8, 8, q_10+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+4, 8, q_10+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+0, 8, q_10+831+0, 8, temp);
	memset(q_11+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, q_11+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+64, 8, q_11+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+60, 8, q_11+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+56, 8, q_11+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+52, 8, q_11+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+48, 8, q_11+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+44, 8, q_11+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+40, 8, q_11+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+36, 8, q_11+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+32, 8, q_11+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+28, 8, q_11+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+24, 8, q_11+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+20, 8, q_11+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+16, 8, q_11+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+12, 8, q_11+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+8, 8, q_11+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+4, 8, q_11+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+0, 8, q_11+831+0, 8, temp);
	

	// Recombining results: n: 17850, depth: 2
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_10+837);
	gf2x_add(279, q_00+552, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_11+837);
	gf2x_add(279, q_01+552, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_10+837);
	gf2x_add(279, q_10+552, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_11+837);
	gf2x_add(279, q_11+552, 279, temp+1, 279, temp2+1);
	

	// Recombining results: n: 35700, depth: 1
	GF2X_MUL(558, temp, 279, q_00+552+0, 279, p_00+558);
	GF2X_MUL(558, temp2, 279, q_01+552+0, 279, p_10+558);
	gf2x_add(558, p_00+0+0, 558, temp, 558, temp2);
	GF2X_MUL(558, temp, 279, q_00+552+0, 279, p_01+558);
	GF2X_MUL(558, temp2, 279, q_01+552+0, 279, p_11+558);
	gf2x_add(558, p_01+0+0, 558, temp, 558, temp2);
	GF2X_MUL(558, temp, 279, q_10+552+0, 279, p_00+558);
	GF2X_MUL(558, temp2, 279, q_11+552+0, 279, p_10+558);
	gf2x_add(558, p_10+0+0, 558, temp, 558, temp2);
	GF2X_MUL(558, temp, 279, q_10+552+0, 279, p_01+558);
	GF2X_MUL(558, temp2, 279, q_11+552+0, 279, p_11+558);
	gf2x_add(558, p_11+0+0, 558, temp, 558, temp2);
	

	// Calculating left operands: n: 71013, depth: 0
	// Digits to shift: 557
	// Displacement: 558
	GF2X_MUL(1116, temp, 558, f+0+552, 558, p_00+0);
	GF2X_MUL(1116, temp2, 558, g+0+552, 558, p_01+0);
	gf2x_add(1110, f_sum+0, 1110, temp+6, 1110, temp2+6);
	GF2X_MUL(1104, temp, 552, p_00+0+6, 552, f+0);
	GF2X_MUL(1104, temp2, 552, p_01+0+6, 552, g+0);
	gf2x_add(1104, temp, 1104, temp, 1104, temp2);
	gf2x_add(552, f_sum+0, 552, f_sum+0, 552, temp+552);
	right_bit_shift_n(1110, f_sum+0, 52);
	GF2X_MUL(1116, temp, 558, f+0+552, 558, p_10+0);
	GF2X_MUL(1116, temp2, 558, g+0+552, 558, p_11+0);
	gf2x_add(1110, g_sum+0, 1110, temp+6, 1110, temp2+6);
	GF2X_MUL(1104, temp, 552, p_10+0+6, 552, f+0);
	GF2X_MUL(1104, temp2, 552, p_11+0+6, 552, g+0);
	gf2x_add(1104, temp, 1104, temp, 1104, temp2);
	gf2x_add(552, g_sum+0, 552, g_sum+0, 552, temp+552);
	right_bit_shift_n(1110, g_sum+0, 52);
	

	delta = divstepsx_256(255, delta, f_sum+549, g_sum+549, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+545+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+545+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+545+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+545+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+545+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+545+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+545+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+545+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+541+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+541+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+541);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+541);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+541+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+541+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+541);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+541);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+533+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+533+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+533);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+533);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+533+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+533+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+533);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+533);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+517+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+517+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+517);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+517);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+517+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+517+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+517);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+517);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+481+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+481+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+481+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+481+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+481+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+481+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+481+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+481+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+413+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+413+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+413);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+413);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+413+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+413+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+413);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+413);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(p_00+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, p_00+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+64, 8, p_00+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+60, 8, p_00+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+56, 8, p_00+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+52, 8, p_00+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+48, 8, p_00+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+44, 8, p_00+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+40, 8, p_00+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+36, 8, p_00+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+32, 8, p_00+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+28, 8, p_00+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+24, 8, p_00+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+20, 8, p_00+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+16, 8, p_00+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+12, 8, p_00+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+8, 8, p_00+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+4, 8, p_00+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+0, 8, p_00+837+0, 8, temp);
	memset(p_01+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, p_01+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+64, 8, p_01+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+60, 8, p_01+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+56, 8, p_01+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+52, 8, p_01+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+48, 8, p_01+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+44, 8, p_01+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+40, 8, p_01+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+36, 8, p_01+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+32, 8, p_01+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+28, 8, p_01+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+24, 8, p_01+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+20, 8, p_01+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+16, 8, p_01+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+12, 8, p_01+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+8, 8, p_01+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+4, 8, p_01+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+0, 8, p_01+837+0, 8, temp);
	memset(p_10+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, p_10+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+64, 8, p_10+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+60, 8, p_10+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+56, 8, p_10+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+52, 8, p_10+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+48, 8, p_10+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+44, 8, p_10+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+40, 8, p_10+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+36, 8, p_10+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+32, 8, p_10+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+28, 8, p_10+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+24, 8, p_10+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+20, 8, p_10+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+16, 8, p_10+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+12, 8, p_10+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+8, 8, p_10+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+4, 8, p_10+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+0, 8, p_10+837+0, 8, temp);
	memset(p_11+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, p_11+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+64, 8, p_11+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+60, 8, p_11+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+56, 8, p_11+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+52, 8, p_11+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+48, 8, p_11+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+44, 8, p_11+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+40, 8, p_11+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+36, 8, p_11+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+32, 8, p_11+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+28, 8, p_11+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+24, 8, p_11+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+20, 8, p_11+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+16, 8, p_11+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+12, 8, p_11+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+8, 8, p_11+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+4, 8, p_11+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+0, 8, p_11+837+0, 8, temp);
	

	// Calculating left operands: n: 17850, depth: 2
	// Digits to shift: 139
	// Displacement: 139
	GF2X_MUL(280, temp, 140, f_sum+274+139, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, g_sum+274+139, 140, p_01+837);
	gf2x_add(280, f_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_00+837+1, 139, f_sum+274);
	GF2X_MUL(278, temp2, 139, p_01+837+1, 139, g_sum+274);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, f_sum+2507, 140, f_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f_sum+274+138, 1, p_00+837);
	GF2X_MUL(2, temp2, 1, g_sum+274+138, 1, p_01+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2507, 1, f_sum+2507, 1, temp+1);
	right_bit_shift_n(279, f_sum+2507, 29);
	GF2X_MUL(280, temp, 140, f_sum+274+139, 140, p_10+837);
	GF2X_MUL(280, temp2, 140, g_sum+274+139, 140, p_11+837);
	gf2x_add(280, g_sum+2507+0, 280, temp, 280, temp2);
	GF2X_MUL(278, temp, 139, p_10+837+1, 139, f_sum+274);
	GF2X_MUL(278, temp2, 139, p_11+837+1, 139, g_sum+274);
	gf2x_add(278, temp, 278, temp, 278, temp2);
	gf2x_add(140, g_sum+2507, 140, g_sum+2507, 140, temp+138);
	GF2X_MUL(2, temp, 1, f_sum+274+138, 1, p_10+837);
	GF2X_MUL(2, temp2, 1, g_sum+274+138, 1, p_11+837);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2507, 1, g_sum+2507, 1, temp+1);
	right_bit_shift_n(279, g_sum+2507, 29);
	

	delta = divstepsx_256(255, delta, f_sum+2644, g_sum+2644, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2640+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2640+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2640+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2636+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2636+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2636);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2636);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2628+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2628+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2628);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2628);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2612+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2612+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2612);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2612);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2576+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+2576+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2576+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+2508+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+2508+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+2508);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+2508);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(q_00+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, q_00+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+64, 8, q_00+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+60, 8, q_00+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+56, 8, q_00+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+52, 8, q_00+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+48, 8, q_00+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+44, 8, q_00+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+40, 8, q_00+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+36, 8, q_00+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+32, 8, q_00+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+28, 8, q_00+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+24, 8, q_00+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+20, 8, q_00+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+16, 8, q_00+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+12, 8, q_00+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+8, 8, q_00+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+4, 8, q_00+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+831+0, 8, q_00+831+0, 8, temp);
	memset(q_01+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, q_01+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+64, 8, q_01+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+60, 8, q_01+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+56, 8, q_01+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+52, 8, q_01+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+48, 8, q_01+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+44, 8, q_01+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+40, 8, q_01+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+36, 8, q_01+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+32, 8, q_01+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+28, 8, q_01+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+24, 8, q_01+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+20, 8, q_01+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+16, 8, q_01+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+12, 8, q_01+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+8, 8, q_01+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+4, 8, q_01+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+831+0, 8, q_01+831+0, 8, temp);
	memset(q_10+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, q_10+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+64, 8, q_10+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+60, 8, q_10+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+56, 8, q_10+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+52, 8, q_10+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+48, 8, q_10+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+44, 8, q_10+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+40, 8, q_10+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+36, 8, q_10+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+32, 8, q_10+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+28, 8, q_10+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+24, 8, q_10+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+20, 8, q_10+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+16, 8, q_10+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+12, 8, q_10+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+8, 8, q_10+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+4, 8, q_10+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+831+0, 8, q_10+831+0, 8, temp);
	memset(q_11+831, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, q_11+831+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+64, 8, q_11+831+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+60, 8, q_11+831+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+56, 8, q_11+831+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+52, 8, q_11+831+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+48, 8, q_11+831+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+44, 8, q_11+831+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+40, 8, q_11+831+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+36, 8, q_11+831+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+32, 8, q_11+831+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+28, 8, q_11+831+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+24, 8, q_11+831+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+20, 8, q_11+831+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+16, 8, q_11+831+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+12, 8, q_11+831+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+8, 8, q_11+831+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+4, 8, q_11+831+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+831+0, 8, q_11+831+0, 8, temp);
	

	// Recombining results: n: 17850, depth: 2
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_10+837);
	gf2x_add(279, p_00+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_00+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_01+831+0, 140, p_11+837);
	gf2x_add(279, p_01+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_10+837);
	gf2x_add(279, p_10+558, 279, temp+1, 279, temp2+1);
	GF2X_MUL(280, temp, 140, q_10+831+0, 140, p_01+837);
	GF2X_MUL(280, temp2, 140, q_11+831+0, 140, p_11+837);
	gf2x_add(279, p_11+558, 279, temp+1, 279, temp2+1);
	

	// Calculating left operands: n: 35313, depth: 1
	// Digits to shift: 278
	// Displacement: 279
	GF2X_MUL(558, temp, 279, f_sum+1+273, 279, p_00+558);
	GF2X_MUL(558, temp2, 279, g_sum+1+273, 279, p_01+558);
	gf2x_add(552, f_sum+1669, 552, temp+6, 552, temp2+6);
	GF2X_MUL(546, temp, 273, p_00+558+6, 273, f_sum+1);
	GF2X_MUL(546, temp2, 273, p_01+558+6, 273, g_sum+1);
	gf2x_add(546, temp, 546, temp, 546, temp2);
	gf2x_add(273, f_sum+1669, 273, f_sum+1669, 273, temp+273);
	right_bit_shift_n(552, f_sum+1669, 58);
	GF2X_MUL(558, temp, 279, f_sum+1+273, 279, p_10+558);
	GF2X_MUL(558, temp2, 279, g_sum+1+273, 279, p_11+558);
	gf2x_add(552, g_sum+1669, 552, temp+6, 552, temp2+6);
	GF2X_MUL(546, temp, 273, p_10+558+6, 273, f_sum+1);
	GF2X_MUL(546, temp2, 273, p_11+558+6, 273, g_sum+1);
	gf2x_add(546, temp, 546, temp, 546, temp2);
	gf2x_add(273, g_sum+1669, 273, g_sum+1669, 273, temp+273);
	right_bit_shift_n(552, g_sum+1669, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1907+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+1907+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+1907);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+1907);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+1907+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+1907+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+1907);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+1907);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4590, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+1871+36, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1871+36, 36, p_01+1049);
	gf2x_add(72, f_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1871+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1871+0, 36, p_01+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+3140, 36, f_sum+3140, 36, temp+36);
	right_bit_shift_n(72, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+1871+36, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1871+36, 36, p_11+1049);
	gf2x_add(72, g_sum+3140+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, f_sum+1871+0, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+1871+0, 36, p_11+1049);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+3140, 36, g_sum+3140, 36, temp+36);
	right_bit_shift_n(72, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3173, g_sum+3173, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+3169+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3169+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+3169+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+3165+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+3165+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+3165);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+3165);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+3157+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+3157+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+3157);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+3157);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+3141+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+3141+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+3141);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+3141);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(q_00+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, q_00+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+12, 8, q_00+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+8, 8, q_00+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+4, 8, q_00+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1039+0, 8, q_00+1039+0, 8, temp);
	memset(q_01+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, q_01+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+12, 8, q_01+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+8, 8, q_01+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+4, 8, q_01+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1039+0, 8, q_01+1039+0, 8, temp);
	memset(q_10+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, q_10+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+12, 8, q_10+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+8, 8, q_10+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+4, 8, q_10+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1039+0, 8, q_10+1039+0, 8, temp);
	memset(q_11+1039, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, q_11+1039+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+12, 8, q_11+1039+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+8, 8, q_11+1039+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+4, 8, q_11+1039+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1039+0, 8, q_11+1039+0, 8, temp);
	

	// Recombining results: n: 4590, depth: 4
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_10+1049);
	gf2x_add(72, p_00+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_00+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_01+1039+0, 36, p_11+1049);
	gf2x_add(72, p_01+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_10+1049);
	gf2x_add(72, p_10+977+0, 72, temp, 72, temp2);
	GF2X_MUL(72, temp, 36, q_10+1039+0, 36, p_01+1049);
	GF2X_MUL(72, temp2, 36, q_11+1039+0, 36, p_11+1049);
	gf2x_add(72, p_11+977+0, 72, temp, 72, temp2);
	

	// Calculating left operands: n: 8925, depth: 3
	// Digits to shift: 71
	// Displacement: 72
	GF2X_MUL(144, temp, 72, f_sum+1803+68, 72, p_00+977);
	GF2X_MUL(144, temp2, 72, g_sum+1803+68, 72, p_01+977);
	gf2x_add(140, f_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, f_sum+1803);
	GF2X_MUL(136, temp2, 68, p_01+977+4, 68, g_sum+1803);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, f_sum+2927, 68, f_sum+2927, 68, temp+68);
	right_bit_shift_n(140, f_sum+2927, 46);
	GF2X_MUL(144, temp, 72, f_sum+1803+68, 72, p_10+977);
	GF2X_MUL(144, temp2, 72, g_sum+1803+68, 72, p_11+977);
	gf2x_add(140, g_sum+2927, 140, temp+4, 140, temp2+4);
	GF2X_MUL(136, temp, 68, p_10+977+4, 68, f_sum+1803);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, g_sum+1803);
	gf2x_add(136, temp, 136, temp, 136, temp2);
	gf2x_add(68, g_sum+2927, 68, g_sum+2927, 68, temp+68);
	right_bit_shift_n(140, g_sum+2927, 46);
	

	delta = divstepsx_256(255, delta, f_sum+2992, g_sum+2992, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2988+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2988+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2988+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2984+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2984+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2984);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2984);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2976+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2976+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2976);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2976);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2960+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2960+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2960);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2960);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2928);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2928);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(q_00+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, q_00+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+28, 8, q_00+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+24, 8, q_00+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+20, 8, q_00+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+16, 8, q_00+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+12, 8, q_00+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+8, 8, q_00+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+4, 8, q_00+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+971+0, 8, q_00+971+0, 8, temp);
	memset(q_01+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, q_01+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+28, 8, q_01+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+24, 8, q_01+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+20, 8, q_01+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+16, 8, q_01+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+12, 8, q_01+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+8, 8, q_01+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+4, 8, q_01+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+971+0, 8, q_01+971+0, 8, temp);
	memset(q_10+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, q_10+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+28, 8, q_10+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+24, 8, q_10+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+20, 8, q_10+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+16, 8, q_10+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+12, 8, q_10+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+8, 8, q_10+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+4, 8, q_10+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+971+0, 8, q_10+971+0, 8, temp);
	memset(q_11+971, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, q_11+971+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+28, 8, q_11+971+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+24, 8, q_11+971+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+20, 8, q_11+971+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+16, 8, q_11+971+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+12, 8, q_11+971+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+8, 8, q_11+971+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+4, 8, q_11+971+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+971+0, 8, q_11+971+0, 8, temp);
	

	// Recombining results: n: 8925, depth: 3
	memset(p_00+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_01+971);
	gf2x_add(136, p_00+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+64, 8, p_00+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+60, 8, p_00+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+56, 8, p_00+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+52, 8, p_00+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+48, 8, p_00+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+44, 8, p_00+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+40, 8, p_00+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+36, 8, p_00+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+32, 8, p_00+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+28, 8, p_00+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+24, 8, p_00+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+20, 8, p_00+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+16, 8, p_00+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+12, 8, p_00+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+8, 8, p_00+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+4, 8, p_00+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+837+0, 8, p_00+837+0, 8, temp);
	memset(p_01+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_00+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_01+971);
	gf2x_add(136, p_01+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_00+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+64, 8, p_01+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+60, 8, p_01+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+56, 8, p_01+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+52, 8, p_01+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+48, 8, p_01+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+44, 8, p_01+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+40, 8, p_01+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+36, 8, p_01+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+32, 8, p_01+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+28, 8, p_01+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+24, 8, p_01+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+20, 8, p_01+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+16, 8, p_01+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+12, 8, p_01+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+8, 8, p_01+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+4, 8, p_01+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_01+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+837+0, 8, p_01+837+0, 8, temp);
	memset(p_10+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_00+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_10+977+4, 68, q_11+971);
	gf2x_add(136, p_10+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+64, 8, p_10+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+60, 8, p_10+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+56, 8, p_10+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+52, 8, p_10+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+48, 8, p_10+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+44, 8, p_10+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+40, 8, p_10+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+36, 8, p_10+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+32, 8, p_10+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+28, 8, p_10+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+24, 8, p_10+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+20, 8, p_10+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+16, 8, p_10+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+12, 8, p_10+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+8, 8, p_10+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+4, 8, p_10+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_00+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_10+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+837+0, 8, p_10+837+0, 8, temp);
	memset(p_11+837, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(136, temp, 68, p_01+977+4, 68, q_10+971);
	GF2X_MUL(136, temp2, 68, p_11+977+4, 68, q_11+971);
	gf2x_add(136, p_11+837+4, 136, temp, 136, temp2);
	GF2X_MUL(8, temp, 4, q_10+971+64, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+64, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+64, 8, p_11+837+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+60, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+60, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+60, 8, p_11+837+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+56, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+56, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+56, 8, p_11+837+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+52, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+52, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+52, 8, p_11+837+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+48, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+48, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+48, 8, p_11+837+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+44, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+44, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+44, 8, p_11+837+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+40, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+40, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+40, 8, p_11+837+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+36, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+36, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+36, 8, p_11+837+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+32, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+32, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+32, 8, p_11+837+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+28, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+28, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+28, 8, p_11+837+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+24, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+24, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+24, 8, p_11+837+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+20, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+20, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+20, 8, p_11+837+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+16, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+16, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+16, 8, p_11+837+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+12, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+12, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+12, 8, p_11+837+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+8, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+8, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+8, 8, p_11+837+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+4, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+4, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+4, 8, p_11+837+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+971+0, 4, p_01+977);
	GF2X_MUL(8, temp2, 4, q_11+971+0, 4, p_11+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+837+0, 8, p_11+837+0, 8, temp);
	

	// Calculating left operands: n: 17463, depth: 2
	// Digits to shift: 139
	// Displacement: 139
	GF2X_MUL(280, temp, 140, f_sum+1670+133, 140, p_00+837);
	GF2X_MUL(280, temp2, 140, g_sum+1670+133, 140, p_01+837);
	gf2x_add(274, f_sum+2507, 274, temp+6, 274, temp2+6);
	GF2X_MUL(266, temp, 133, p_00+837+7, 133, f_sum+1670);
	GF2X_MUL(266, temp2, 133, p_01+837+7, 133, g_sum+1670);
	gf2x_add(266, temp, 266, temp, 266, temp2);
	gf2x_add(134, f_sum+2507, 134, f_sum+2507, 134, temp+132);
	GF2X_MUL(14, temp, 7, f_sum+1670+126, 7, p_00+837);
	GF2X_MUL(14, temp2, 7, g_sum+1670+126, 7, p_01+837);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, f_sum+2507, 1, f_sum+2507, 1, temp+13);
	right_bit_shift_n(273, f_sum+2507, 29);
	GF2X_MUL(280, temp, 140, f_sum+1670+133, 140, p_10+837);
	GF2X_MUL(280, temp2, 140, g_sum+1670+133, 140, p_11+837);
	gf2x_add(274, g_sum+2507, 274, temp+6, 274, temp2+6);
	GF2X_MUL(266, temp, 133, p_10+837+7, 133, f_sum+1670);
	GF2X_MUL(266, temp2, 133, p_11+837+7, 133, g_sum+1670);
	gf2x_add(266, temp, 266, temp, 266, temp2);
	gf2x_add(134, g_sum+2507, 134, g_sum+2507, 134, temp+132);
	GF2X_MUL(14, temp, 7, f_sum+1670+126, 7, p_10+837);
	GF2X_MUL(14, temp2, 7, g_sum+1670+126, 7, p_11+837);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, g_sum+2507, 1, g_sum+2507, 1, temp+13);
	right_bit_shift_n(273, g_sum+2507, 29);
	

	delta = divstepsx_256(255, delta, f_sum+2638, g_sum+2638, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2634+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2634+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2634+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2634+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2634+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2634+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2634+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2634+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2630+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2630+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2630);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2630);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2630+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2630+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2630);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2630);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2622+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2622+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2622);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2622);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2622+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2622+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2622);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2622);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2606+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2606+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2606);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2606);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2606+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2606+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2606);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2606);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4335, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2574+32, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2574+32, 36, p_01+1049);
	gf2x_add(68, f_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, f_sum+2574);
	GF2X_MUL(64, temp2, 32, p_01+1049+4, 32, g_sum+2574);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+3140, 32, f_sum+3140, 32, temp+32);
	right_bit_shift_n(68, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2574+32, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2574+32, 36, p_11+1049);
	gf2x_add(68, g_sum+3140, 68, temp+4, 68, temp2+4);
	GF2X_MUL(64, temp, 32, p_10+1049+4, 32, f_sum+2574);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, g_sum+2574);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+3140, 32, g_sum+3140, 32, temp+32);
	right_bit_shift_n(68, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3169, g_sum+3169, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3165+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3165+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3165+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3157+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3157+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3157+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_01+1085);
	gf2x_add(32, f_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_01+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(32, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+16, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+16, 16, p_11+1085);
	gf2x_add(32, g_sum+3249+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+3141+0, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+0, 16, p_11+1085);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(32, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 5
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_10+1085);
	gf2x_add(32, q_00+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_01+1075+0, 16, p_11+1085);
	gf2x_add(32, q_01+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_10+1085);
	gf2x_add(32, q_10+1039+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+1075+0, 16, p_01+1085);
	GF2X_MUL(32, temp2, 16, q_11+1075+0, 16, p_11+1085);
	gf2x_add(32, q_11+1039+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4335, depth: 4
	memset(p_00+977, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_01+1039);
	gf2x_add(64, p_00+977+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+28, 8, p_00+977+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+24, 8, p_00+977+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+20, 8, p_00+977+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+16, 8, p_00+977+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+12, 8, p_00+977+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+8, 8, p_00+977+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+4, 8, p_00+977+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+977+0, 8, p_00+977+0, 8, temp);
	memset(p_01+977, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_00+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_01+1039);
	gf2x_add(64, p_01+977+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_00+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+28, 8, p_01+977+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+24, 8, p_01+977+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+20, 8, p_01+977+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+16, 8, p_01+977+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+12, 8, p_01+977+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+8, 8, p_01+977+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+4, 8, p_01+977+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_01+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+977+0, 8, p_01+977+0, 8, temp);
	memset(p_10+977, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_00+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_10+1049+4, 32, q_11+1039);
	gf2x_add(64, p_10+977+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+28, 8, p_10+977+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+24, 8, p_10+977+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+20, 8, p_10+977+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+16, 8, p_10+977+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+12, 8, p_10+977+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+8, 8, p_10+977+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+4, 8, p_10+977+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_00+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_10+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+977+0, 8, p_10+977+0, 8, temp);
	memset(p_11+977, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, p_01+1049+4, 32, q_10+1039);
	GF2X_MUL(64, temp2, 32, p_11+1049+4, 32, q_11+1039);
	gf2x_add(64, p_11+977+4, 64, temp, 64, temp2);
	GF2X_MUL(8, temp, 4, q_10+1039+28, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+28, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+28, 8, p_11+977+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+24, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+24, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+24, 8, p_11+977+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+20, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+20, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+20, 8, p_11+977+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+16, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+16, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+16, 8, p_11+977+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+12, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+12, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+12, 8, p_11+977+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+8, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+8, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+8, 8, p_11+977+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+4, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+4, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+4, 8, p_11+977+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1039+0, 4, p_01+1049);
	GF2X_MUL(8, temp2, 4, q_11+1039+0, 4, p_11+1049);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+977+0, 8, p_11+977+0, 8, temp);
	

	// Calculating left operands: n: 8538, depth: 3
	// Digits to shift: 67
	// Displacement: 68
	GF2X_MUL(136, temp, 68, f_sum+2508+66, 68, p_00+977);
	GF2X_MUL(136, temp2, 68, g_sum+2508+66, 68, p_01+977);
	gf2x_add(134, f_sum+2927, 134, temp+2, 134, temp2+2);
	GF2X_MUL(132, temp, 66, p_00+977+2, 66, f_sum+2508);
	GF2X_MUL(132, temp2, 66, p_01+977+2, 66, g_sum+2508);
	gf2x_add(132, temp, 132, temp, 132, temp2);
	gf2x_add(66, f_sum+2927, 66, f_sum+2927, 66, temp+66);
	right_bit_shift_n(134, f_sum+2927, 47);
	GF2X_MUL(136, temp, 68, f_sum+2508+66, 68, p_10+977);
	GF2X_MUL(136, temp2, 68, g_sum+2508+66, 68, p_11+977);
	gf2x_add(134, g_sum+2927, 134, temp+2, 134, temp2+2);
	GF2X_MUL(132, temp, 66, p_10+977+2, 66, f_sum+2508);
	GF2X_MUL(132, temp2, 66, p_11+977+2, 66, g_sum+2508);
	gf2x_add(132, temp, 132, temp, 132, temp2);
	gf2x_add(66, g_sum+2927, 66, g_sum+2927, 66, temp+66);
	right_bit_shift_n(134, g_sum+2927, 47);
	

	delta = divstepsx_256(255, delta, f_sum+2990, g_sum+2990, p_00+1125, p_01+1125, p_10+1125, p_11+1125);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2986+4, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2986+4, 4, p_01+1125);
	gf2x_add(8, f_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2986+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2986+0, 4, p_01+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3360, 4, f_sum+3360, 4, temp+4);
	right_bit_shift_n(8, f_sum+3360, 63);
	GF2X_MUL(8, temp, 4, f_sum+2986+4, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2986+4, 4, p_11+1125);
	gf2x_add(8, g_sum+3360+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2986+0, 4, p_10+1125);
	GF2X_MUL(8, temp2, 4, g_sum+2986+0, 4, p_11+1125);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3360, 4, g_sum+3360, 4, temp+4);
	right_bit_shift_n(8, g_sum+3360, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3361, g_sum+3361, q_00+1103, q_01+1103, q_10+1103, q_11+1103);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_10+1125);
	gf2x_add(8, p_00+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_01+1103+0, 4, p_11+1125);
	gf2x_add(8, p_01+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_00+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_10+1125);
	gf2x_add(8, p_10+1117+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1103+0, 4, p_01+1125);
	GF2X_MUL(8, temp2, 4, q_11+1103+0, 4, p_11+1125);
	gf2x_add(8, p_11+1117+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2982+4, 8, p_00+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2982+4, 8, p_01+1117);
	gf2x_add(12, f_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, f_sum+2982);
	GF2X_MUL(8, temp2, 4, p_01+1117+4, 4, g_sum+2982);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(12, f_sum+3339, 62);
	GF2X_MUL(16, temp, 8, f_sum+2982+4, 8, p_10+1117);
	GF2X_MUL(16, temp2, 8, g_sum+2982+4, 8, p_11+1117);
	gf2x_add(12, g_sum+3339, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1117+4, 4, f_sum+2982);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, g_sum+2982);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(12, g_sum+3339, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_01+1099);
	gf2x_add(8, p_00+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1105+0, 8, p_00+1105+0, 8, temp);
	memset(p_01+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_00+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_01+1099);
	gf2x_add(8, p_01+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1105+0, 8, p_01+1105+0, 8, temp);
	memset(p_10+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_10+1117+4, 4, q_11+1099);
	gf2x_add(8, p_10+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1105+0, 8, p_10+1105+0, 8, temp);
	memset(p_11+1105, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1117+4, 4, q_10+1099);
	GF2X_MUL(8, temp2, 4, p_11+1117+4, 4, q_11+1099);
	gf2x_add(8, p_11+1105+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1105+0, 8, p_11+1105+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2974+8, 12, p_00+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2974+8, 12, p_01+1105);
	gf2x_add(20, f_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, f_sum+2974);
	GF2X_MUL(16, temp2, 8, p_01+1105+4, 8, g_sum+2974);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(20, f_sum+3306, 61);
	GF2X_MUL(24, temp, 12, f_sum+2974+8, 12, p_10+1105);
	GF2X_MUL(24, temp2, 12, g_sum+2974+8, 12, p_11+1105);
	gf2x_add(20, g_sum+3306, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1105+4, 8, f_sum+2974);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, g_sum+2974);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(20, g_sum+3306, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_01+1091);
	gf2x_add(16, p_00+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+4, 8, p_00+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1085+0, 8, p_00+1085+0, 8, temp);
	memset(p_01+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_00+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_01+1091);
	gf2x_add(16, p_01+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+4, 8, p_01+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_01+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1085+0, 8, p_01+1085+0, 8, temp);
	memset(p_10+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_10+1105+4, 8, q_11+1091);
	gf2x_add(16, p_10+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+4, 8, p_10+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_00+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_10+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1085+0, 8, p_10+1085+0, 8, temp);
	memset(p_11+1085, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1105+4, 8, q_10+1091);
	GF2X_MUL(16, temp2, 8, p_11+1105+4, 8, q_11+1091);
	gf2x_add(16, p_11+1085+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1091+4, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+4, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+4, 8, p_11+1085+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1091+0, 4, p_01+1105);
	GF2X_MUL(8, temp2, 4, q_11+1091+0, 4, p_11+1105);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1085+0, 8, p_11+1085+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2958+16, 20, p_00+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2958+16, 20, p_01+1085);
	gf2x_add(36, f_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, f_sum+2958);
	GF2X_MUL(32, temp2, 16, p_01+1085+4, 16, g_sum+2958);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+3249, 16, f_sum+3249, 16, temp+16);
	right_bit_shift_n(36, f_sum+3249, 59);
	GF2X_MUL(40, temp, 20, f_sum+2958+16, 20, p_10+1085);
	GF2X_MUL(40, temp2, 20, g_sum+2958+16, 20, p_11+1085);
	gf2x_add(36, g_sum+3249, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+1085+4, 16, f_sum+2958);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, g_sum+2958);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+3249, 16, g_sum+3249, 16, temp+16);
	right_bit_shift_n(36, g_sum+3249, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3262, g_sum+3262, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3258+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3258+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3258+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3250+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, q_00+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, q_01+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, q_10+1075+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, q_11+1075+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 5
	memset(p_00+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_01+1075);
	gf2x_add(32, p_00+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+12, 8, p_00+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+8, 8, p_00+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+4, 8, p_00+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1049+0, 8, p_00+1049+0, 8, temp);
	memset(p_01+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_00+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_01+1075);
	gf2x_add(32, p_01+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+12, 8, p_01+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+8, 8, p_01+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+4, 8, p_01+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_01+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1049+0, 8, p_01+1049+0, 8, temp);
	memset(p_10+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_10+1085+4, 16, q_11+1075);
	gf2x_add(32, p_10+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+12, 8, p_10+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+8, 8, p_10+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+4, 8, p_10+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_00+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_10+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1049+0, 8, p_10+1049+0, 8, temp);
	memset(p_11+1049, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+1085+4, 16, q_10+1075);
	GF2X_MUL(32, temp2, 16, p_11+1085+4, 16, q_11+1075);
	gf2x_add(32, p_11+1049+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+1075+12, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+12, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+12, 8, p_11+1049+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+8, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+8, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+8, 8, p_11+1049+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+4, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+4, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+4, 8, p_11+1049+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1075+0, 4, p_01+1085);
	GF2X_MUL(8, temp2, 4, q_11+1075+0, 4, p_11+1085);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1049+0, 8, p_11+1049+0, 8, temp);
	

	// Calculating left operands: n: 4203, depth: 4
	// Digits to shift: 35
	// Displacement: 36
	GF2X_MUL(72, temp, 36, f_sum+2928+30, 36, p_00+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+30, 36, p_01+1049);
	gf2x_add(66, f_sum+3140, 66, temp+6, 66, temp2+6);
	GF2X_MUL(60, temp, 30, p_00+1049+6, 30, f_sum+2928);
	GF2X_MUL(60, temp2, 30, p_01+1049+6, 30, g_sum+2928);
	gf2x_add(60, temp, 60, temp, 60, temp2);
	gf2x_add(30, f_sum+3140, 30, f_sum+3140, 30, temp+30);
	right_bit_shift_n(66, f_sum+3140, 55);
	GF2X_MUL(72, temp, 36, f_sum+2928+30, 36, p_10+1049);
	GF2X_MUL(72, temp2, 36, g_sum+2928+30, 36, p_11+1049);
	gf2x_add(66, g_sum+3140, 66, temp+6, 66, temp2+6);
	GF2X_MUL(60, temp, 30, p_10+1049+6, 30, f_sum+2928);
	GF2X_MUL(60, temp2, 30, p_11+1049+6, 30, g_sum+2928);
	gf2x_add(60, temp, 60, temp, 60, temp2);
	gf2x_add(30, g_sum+3140, 30, g_sum+3140, 30, temp+30);
	right_bit_shift_n(66, g_sum+3140, 55);
	

	delta = divstepsx_256(255, delta, f_sum+3167, g_sum+3167, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3163+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3163+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3163+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3163+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3163+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3163+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3163+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3163+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3155+8, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3155+8, 8, p_01+1105);
	gf2x_add(16, f_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3155+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3155+0, 8, p_01+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3306, 8, f_sum+3306, 8, temp+8);
	right_bit_shift_n(16, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3155+8, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3155+8, 8, p_11+1105);
	gf2x_add(16, g_sum+3306+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+3155+0, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3155+0, 8, p_11+1105);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3306, 8, g_sum+3306, 8, temp+8);
	right_bit_shift_n(16, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3311, g_sum+3311, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3307+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, q_00+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, q_01+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, q_10+1091+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, q_11+1091+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_10+1105);
	gf2x_add(16, p_00+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_01+1091+0, 8, p_11+1105);
	gf2x_add(16, p_01+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_10+1105);
	gf2x_add(16, p_10+1085+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+1091+0, 8, p_01+1105);
	GF2X_MUL(16, temp2, 8, q_11+1091+0, 8, p_11+1105);
	gf2x_add(16, p_11+1085+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1908, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+3141+14, 16, p_00+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+14, 16, p_01+1085);
	gf2x_add(30, f_sum+3249, 30, temp+2, 30, temp2+2);
	GF2X_MUL(28, temp, 14, p_00+1085+2, 14, f_sum+3141);
	GF2X_MUL(28, temp2, 14, p_01+1085+2, 14, g_sum+3141);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, f_sum+3249, 14, f_sum+3249, 14, temp+14);
	right_bit_shift_n(30, f_sum+3249, 60);
	GF2X_MUL(32, temp, 16, f_sum+3141+14, 16, p_10+1085);
	GF2X_MUL(32, temp2, 16, g_sum+3141+14, 16, p_11+1085);
	gf2x_add(30, g_sum+3249, 30, temp+2, 30, temp2+2);
	GF2X_MUL(28, temp, 14, p_10+1085+2, 14, f_sum+3141);
	GF2X_MUL(28, temp2, 14, p_11+1085+2, 14, g_sum+3141);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, g_sum+3249, 14, g_sum+3249, 14, temp+14);
	right_bit_shift_n(30, g_sum+3249, 60);
	

	delta = divstepsx_256(255, delta, f_sum+3260, g_sum+3260, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3256+4, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3256+4, 4, p_01+1117);
	gf2x_add(8, f_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3256+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3256+0, 4, p_01+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3339, 4, f_sum+3339, 4, temp+4);
	right_bit_shift_n(8, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3256+4, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3256+4, 4, p_11+1117);
	gf2x_add(8, g_sum+3339+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3256+0, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3256+0, 4, p_11+1117);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3339, 4, g_sum+3339, 4, temp+4);
	right_bit_shift_n(8, g_sum+3339, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_10+1117);
	gf2x_add(8, p_00+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_01+1099+0, 4, p_11+1117);
	gf2x_add(8, p_01+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_10+1117);
	gf2x_add(8, p_10+1105+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1099+0, 4, p_01+1117);
	GF2X_MUL(8, temp2, 4, q_11+1099+0, 4, p_11+1117);
	gf2x_add(8, p_11+1105+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 888, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3250+6, 8, p_00+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+6, 8, p_01+1105);
	gf2x_add(14, f_sum+3306, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_00+1105+2, 6, f_sum+3250);
	GF2X_MUL(12, temp2, 6, p_01+1105+2, 6, g_sum+3250);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, f_sum+3306, 6, f_sum+3306, 6, temp+6);
	right_bit_shift_n(14, f_sum+3306, 62);
	GF2X_MUL(16, temp, 8, f_sum+3250+6, 8, p_10+1105);
	GF2X_MUL(16, temp2, 8, g_sum+3250+6, 8, p_11+1105);
	gf2x_add(14, g_sum+3306, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_10+1105+2, 6, f_sum+3250);
	GF2X_MUL(12, temp2, 6, p_11+1105+2, 6, g_sum+3250);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, g_sum+3306, 6, g_sum+3306, 6, temp+6);
	right_bit_shift_n(14, g_sum+3306, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3309, g_sum+3309, p_00+1117, p_01+1117, p_10+1117, p_11+1117);

	// Calculating left operands: n: 378, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3307+2, 4, p_00+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+2, 4, p_01+1117);
	gf2x_add(6, f_sum+3339, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_00+1117+2, 2, f_sum+3307);
	GF2X_MUL(4, temp2, 2, p_01+1117+2, 2, g_sum+3307);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+3339, 2, f_sum+3339, 2, temp+2);
	right_bit_shift_n(6, f_sum+3339, 63);
	GF2X_MUL(8, temp, 4, f_sum+3307+2, 4, p_10+1117);
	GF2X_MUL(8, temp2, 4, g_sum+3307+2, 4, p_11+1117);
	gf2x_add(6, g_sum+3339, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_10+1117+2, 2, f_sum+3307);
	GF2X_MUL(4, temp2, 2, p_11+1117+2, 2, g_sum+3307);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+3339, 2, g_sum+3339, 2, temp+2);
	right_bit_shift_n(6, g_sum+3339, 63);
	

	delta = divstepsx_128(123, delta, f_sum+3340, g_sum+3340, q_00+1099, q_01+1099, q_10+1099, q_11+1099);

	// Recombining results: n: 378, depth: 7
	memset(q_00+1091, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+1117+2, 2, q_00+1099);
	GF2X_MUL(4, temp2, 2, p_10+1117+2, 2, q_01+1099);
	gf2x_add(4, q_00+1091+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+1099+0, 2, p_00+1117);
	GF2X_MUL(4, temp2, 2, q_01+1099+0, 2, p_10+1117);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1091+0, 4, q_00+1091+0, 4, temp);
	memset(q_01+1091, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+1117+2, 2, q_00+1099);
	GF2X_MUL(4, temp2, 2, p_11+1117+2, 2, q_01+1099);
	gf2x_add(4, q_01+1091+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+1099+0, 2, p_01+1117);
	GF2X_MUL(4, temp2, 2, q_01+1099+0, 2, p_11+1117);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1091+0, 4, q_01+1091+0, 4, temp);
	memset(q_10+1091, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+1117+2, 2, q_10+1099);
	GF2X_MUL(4, temp2, 2, p_10+1117+2, 2, q_11+1099);
	gf2x_add(4, q_10+1091+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+1099+0, 2, p_00+1117);
	GF2X_MUL(4, temp2, 2, q_11+1099+0, 2, p_10+1117);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1091+0, 4, q_10+1091+0, 4, temp);
	memset(q_11+1091, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+1117+2, 2, q_10+1099);
	GF2X_MUL(4, temp2, 2, p_11+1117+2, 2, q_11+1099);
	gf2x_add(4, q_11+1091+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+1099+0, 2, p_01+1117);
	GF2X_MUL(4, temp2, 2, q_11+1099+0, 2, p_11+1117);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1091+0, 4, q_11+1091+0, 4, temp);
	

	// Recombining results: n: 888, depth: 6
	memset(q_00+1075, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+1105+2, 6, q_00+1091);
	GF2X_MUL(12, temp2, 6, p_10+1105+2, 6, q_01+1091);
	gf2x_add(12, q_00+1075+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+1091+4, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+4, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1075+4, 4, q_00+1075+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1091+2, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+2, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1075+2, 4, q_00+1075+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1091+0, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+0, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1075+0, 4, q_00+1075+0, 4, temp);
	memset(q_01+1075, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+1105+2, 6, q_00+1091);
	GF2X_MUL(12, temp2, 6, p_11+1105+2, 6, q_01+1091);
	gf2x_add(12, q_01+1075+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+1091+4, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+4, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1075+4, 4, q_01+1075+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1091+2, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+2, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1075+2, 4, q_01+1075+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1091+0, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_01+1091+0, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1075+0, 4, q_01+1075+0, 4, temp);
	memset(q_10+1075, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+1105+2, 6, q_10+1091);
	GF2X_MUL(12, temp2, 6, p_10+1105+2, 6, q_11+1091);
	gf2x_add(12, q_10+1075+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+1091+4, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+4, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1075+4, 4, q_10+1075+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1091+2, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+2, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1075+2, 4, q_10+1075+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1091+0, 2, p_00+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+0, 2, p_10+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1075+0, 4, q_10+1075+0, 4, temp);
	memset(q_11+1075, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+1105+2, 6, q_10+1091);
	GF2X_MUL(12, temp2, 6, p_11+1105+2, 6, q_11+1091);
	gf2x_add(12, q_11+1075+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+1091+4, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+4, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1075+4, 4, q_11+1075+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1091+2, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+2, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1075+2, 4, q_11+1075+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1091+0, 2, p_01+1105);
	GF2X_MUL(4, temp2, 2, q_11+1091+0, 2, p_11+1105);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1075+0, 4, q_11+1075+0, 4, temp);
	

	// Recombining results: n: 1908, depth: 5
	memset(q_00+1039, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+1085+2, 14, q_00+1075);
	GF2X_MUL(28, temp2, 14, p_10+1085+2, 14, q_01+1075);
	gf2x_add(28, q_00+1039+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_00+1075+12, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+12, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+12, 4, q_00+1039+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+10, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+10, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+10, 4, q_00+1039+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+8, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+8, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+8, 4, q_00+1039+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+6, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+6, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+6, 4, q_00+1039+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+4, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+4, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+4, 4, q_00+1039+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+2, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+2, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+2, 4, q_00+1039+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+0, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+0, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+1039+0, 4, q_00+1039+0, 4, temp);
	memset(q_01+1039, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+1085+2, 14, q_00+1075);
	GF2X_MUL(28, temp2, 14, p_11+1085+2, 14, q_01+1075);
	gf2x_add(28, q_01+1039+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_00+1075+12, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+12, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+12, 4, q_01+1039+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+10, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+10, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+10, 4, q_01+1039+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+8, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+8, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+8, 4, q_01+1039+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+6, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+6, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+6, 4, q_01+1039+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+4, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+4, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+4, 4, q_01+1039+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+2, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+2, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+2, 4, q_01+1039+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+1075+0, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_01+1075+0, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+1039+0, 4, q_01+1039+0, 4, temp);
	memset(q_10+1039, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+1085+2, 14, q_10+1075);
	GF2X_MUL(28, temp2, 14, p_10+1085+2, 14, q_11+1075);
	gf2x_add(28, q_10+1039+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_10+1075+12, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+12, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+12, 4, q_10+1039+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+10, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+10, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+10, 4, q_10+1039+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+8, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+8, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+8, 4, q_10+1039+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+6, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+6, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+6, 4, q_10+1039+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+4, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+4, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+4, 4, q_10+1039+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+2, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+2, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+2, 4, q_10+1039+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+0, 2, p_00+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+0, 2, p_10+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+1039+0, 4, q_10+1039+0, 4, temp);
	memset(q_11+1039, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+1085+2, 14, q_10+1075);
	GF2X_MUL(28, temp2, 14, p_11+1085+2, 14, q_11+1075);
	gf2x_add(28, q_11+1039+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_10+1075+12, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+12, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+12, 4, q_11+1039+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+10, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+10, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+10, 4, q_11+1039+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+8, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+8, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+8, 4, q_11+1039+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+6, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+6, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+6, 4, q_11+1039+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+4, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+4, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+4, 4, q_11+1039+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+2, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+2, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+2, 4, q_11+1039+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+1075+0, 2, p_01+1085);
	GF2X_MUL(4, temp2, 2, q_11+1075+0, 2, p_11+1085);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+1039+0, 4, q_11+1039+0, 4, temp);
	

	// Recombining results: n: 4203, depth: 4
	memset(q_00+971, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_00+1049+6, 30, q_00+1039);
	GF2X_MUL(60, temp2, 30, p_10+1049+6, 30, q_01+1039);
	gf2x_add(60, q_00+971+6, 60, temp, 60, temp2);
	GF2X_MUL(12, temp, 6, q_00+1039+24, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+24, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+971+24, 12, q_00+971+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+18, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+18, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+971+18, 12, q_00+971+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+12, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+12, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+971+12, 12, q_00+971+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+6, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+6, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+971+6, 12, q_00+971+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+0, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+0, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+971+0, 12, q_00+971+0, 12, temp);
	memset(q_01+971, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_01+1049+6, 30, q_00+1039);
	GF2X_MUL(60, temp2, 30, p_11+1049+6, 30, q_01+1039);
	gf2x_add(60, q_01+971+6, 60, temp, 60, temp2);
	GF2X_MUL(12, temp, 6, q_00+1039+24, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+24, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+971+24, 12, q_01+971+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+18, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+18, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+971+18, 12, q_01+971+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+12, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+12, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+971+12, 12, q_01+971+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+6, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+6, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+971+6, 12, q_01+971+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+1039+0, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_01+1039+0, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+971+0, 12, q_01+971+0, 12, temp);
	memset(q_10+971, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_00+1049+6, 30, q_10+1039);
	GF2X_MUL(60, temp2, 30, p_10+1049+6, 30, q_11+1039);
	gf2x_add(60, q_10+971+6, 60, temp, 60, temp2);
	GF2X_MUL(12, temp, 6, q_10+1039+24, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+24, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+971+24, 12, q_10+971+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+18, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+18, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+971+18, 12, q_10+971+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+12, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+12, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+971+12, 12, q_10+971+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+6, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+6, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+971+6, 12, q_10+971+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+0, 6, p_00+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+0, 6, p_10+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+971+0, 12, q_10+971+0, 12, temp);
	memset(q_11+971, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_01+1049+6, 30, q_10+1039);
	GF2X_MUL(60, temp2, 30, p_11+1049+6, 30, q_11+1039);
	gf2x_add(60, q_11+971+6, 60, temp, 60, temp2);
	GF2X_MUL(12, temp, 6, q_10+1039+24, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+24, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+971+24, 12, q_11+971+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+18, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+18, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+971+18, 12, q_11+971+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+12, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+12, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+971+12, 12, q_11+971+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+6, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+6, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+971+6, 12, q_11+971+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+1039+0, 6, p_01+1049);
	GF2X_MUL(12, temp2, 6, q_11+1039+0, 6, p_11+1049);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+971+0, 12, q_11+971+0, 12, temp);
	

	// Recombining results: n: 8538, depth: 3
	memset(q_00+831, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(132, temp, 66, p_00+977+2, 66, q_00+971);
	GF2X_MUL(132, temp2, 66, p_10+977+2, 66, q_01+971);
	gf2x_add(132, q_00+831+2, 132, temp, 132, temp2);
	GF2X_MUL(4, temp, 2, q_00+971+64, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+64, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+64, 4, q_00+831+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+62, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+62, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+62, 4, q_00+831+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+60, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+60, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+60, 4, q_00+831+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+58, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+58, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+58, 4, q_00+831+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+56, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+56, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+56, 4, q_00+831+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+54, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+54, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+54, 4, q_00+831+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+52, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+52, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+52, 4, q_00+831+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+50, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+50, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+50, 4, q_00+831+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+48, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+48, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+48, 4, q_00+831+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+46, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+46, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+46, 4, q_00+831+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+44, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+44, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+44, 4, q_00+831+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+42, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+42, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+42, 4, q_00+831+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+40, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+40, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+40, 4, q_00+831+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+38, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+38, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+38, 4, q_00+831+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+36, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+36, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+36, 4, q_00+831+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+34, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+34, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+34, 4, q_00+831+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+32, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+32, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+32, 4, q_00+831+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+30, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+30, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+30, 4, q_00+831+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+28, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+28, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+28, 4, q_00+831+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+26, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+26, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+26, 4, q_00+831+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+24, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+24, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+24, 4, q_00+831+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+22, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+22, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+22, 4, q_00+831+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+20, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+20, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+20, 4, q_00+831+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+18, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+18, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+18, 4, q_00+831+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+16, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+16, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+16, 4, q_00+831+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+14, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+14, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+14, 4, q_00+831+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+12, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+12, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+12, 4, q_00+831+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+10, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+10, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+10, 4, q_00+831+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+8, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+8, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+8, 4, q_00+831+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+6, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+6, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+6, 4, q_00+831+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+4, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+4, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+4, 4, q_00+831+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+2, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+2, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+2, 4, q_00+831+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+0, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_01+971+0, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+831+0, 4, q_00+831+0, 4, temp);
	memset(q_01+831, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(132, temp, 66, p_01+977+2, 66, q_00+971);
	GF2X_MUL(132, temp2, 66, p_11+977+2, 66, q_01+971);
	gf2x_add(132, q_01+831+2, 132, temp, 132, temp2);
	GF2X_MUL(4, temp, 2, q_00+971+64, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+64, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+64, 4, q_01+831+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+62, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+62, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+62, 4, q_01+831+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+60, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+60, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+60, 4, q_01+831+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+58, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+58, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+58, 4, q_01+831+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+56, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+56, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+56, 4, q_01+831+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+54, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+54, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+54, 4, q_01+831+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+52, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+52, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+52, 4, q_01+831+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+50, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+50, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+50, 4, q_01+831+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+48, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+48, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+48, 4, q_01+831+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+46, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+46, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+46, 4, q_01+831+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+44, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+44, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+44, 4, q_01+831+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+42, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+42, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+42, 4, q_01+831+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+40, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+40, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+40, 4, q_01+831+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+38, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+38, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+38, 4, q_01+831+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+36, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+36, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+36, 4, q_01+831+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+34, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+34, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+34, 4, q_01+831+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+32, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+32, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+32, 4, q_01+831+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+30, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+30, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+30, 4, q_01+831+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+28, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+28, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+28, 4, q_01+831+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+26, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+26, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+26, 4, q_01+831+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+24, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+24, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+24, 4, q_01+831+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+22, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+22, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+22, 4, q_01+831+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+20, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+20, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+20, 4, q_01+831+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+18, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+18, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+18, 4, q_01+831+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+16, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+16, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+16, 4, q_01+831+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+14, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+14, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+14, 4, q_01+831+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+12, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+12, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+12, 4, q_01+831+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+10, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+10, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+10, 4, q_01+831+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+8, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+8, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+8, 4, q_01+831+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+6, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+6, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+6, 4, q_01+831+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+4, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+4, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+4, 4, q_01+831+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+2, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+2, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+2, 4, q_01+831+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+971+0, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_01+971+0, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+831+0, 4, q_01+831+0, 4, temp);
	memset(q_10+831, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(132, temp, 66, p_00+977+2, 66, q_10+971);
	GF2X_MUL(132, temp2, 66, p_10+977+2, 66, q_11+971);
	gf2x_add(132, q_10+831+2, 132, temp, 132, temp2);
	GF2X_MUL(4, temp, 2, q_10+971+64, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+64, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+64, 4, q_10+831+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+62, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+62, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+62, 4, q_10+831+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+60, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+60, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+60, 4, q_10+831+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+58, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+58, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+58, 4, q_10+831+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+56, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+56, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+56, 4, q_10+831+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+54, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+54, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+54, 4, q_10+831+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+52, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+52, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+52, 4, q_10+831+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+50, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+50, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+50, 4, q_10+831+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+48, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+48, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+48, 4, q_10+831+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+46, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+46, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+46, 4, q_10+831+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+44, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+44, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+44, 4, q_10+831+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+42, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+42, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+42, 4, q_10+831+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+40, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+40, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+40, 4, q_10+831+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+38, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+38, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+38, 4, q_10+831+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+36, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+36, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+36, 4, q_10+831+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+34, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+34, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+34, 4, q_10+831+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+32, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+32, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+32, 4, q_10+831+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+30, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+30, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+30, 4, q_10+831+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+28, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+28, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+28, 4, q_10+831+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+26, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+26, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+26, 4, q_10+831+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+24, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+24, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+24, 4, q_10+831+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+22, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+22, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+22, 4, q_10+831+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+20, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+20, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+20, 4, q_10+831+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+18, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+18, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+18, 4, q_10+831+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+16, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+16, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+16, 4, q_10+831+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+14, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+14, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+14, 4, q_10+831+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+12, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+12, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+12, 4, q_10+831+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+10, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+10, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+10, 4, q_10+831+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+8, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+8, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+8, 4, q_10+831+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+6, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+6, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+6, 4, q_10+831+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+4, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+4, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+4, 4, q_10+831+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+2, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+2, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+2, 4, q_10+831+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+0, 2, p_00+977);
	GF2X_MUL(4, temp2, 2, q_11+971+0, 2, p_10+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+831+0, 4, q_10+831+0, 4, temp);
	memset(q_11+831, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(132, temp, 66, p_01+977+2, 66, q_10+971);
	GF2X_MUL(132, temp2, 66, p_11+977+2, 66, q_11+971);
	gf2x_add(132, q_11+831+2, 132, temp, 132, temp2);
	GF2X_MUL(4, temp, 2, q_10+971+64, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+64, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+64, 4, q_11+831+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+62, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+62, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+62, 4, q_11+831+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+60, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+60, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+60, 4, q_11+831+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+58, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+58, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+58, 4, q_11+831+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+56, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+56, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+56, 4, q_11+831+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+54, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+54, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+54, 4, q_11+831+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+52, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+52, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+52, 4, q_11+831+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+50, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+50, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+50, 4, q_11+831+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+48, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+48, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+48, 4, q_11+831+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+46, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+46, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+46, 4, q_11+831+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+44, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+44, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+44, 4, q_11+831+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+42, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+42, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+42, 4, q_11+831+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+40, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+40, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+40, 4, q_11+831+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+38, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+38, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+38, 4, q_11+831+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+36, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+36, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+36, 4, q_11+831+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+34, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+34, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+34, 4, q_11+831+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+32, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+32, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+32, 4, q_11+831+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+30, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+30, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+30, 4, q_11+831+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+28, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+28, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+28, 4, q_11+831+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+26, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+26, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+26, 4, q_11+831+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+24, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+24, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+24, 4, q_11+831+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+22, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+22, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+22, 4, q_11+831+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+20, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+20, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+20, 4, q_11+831+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+18, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+18, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+18, 4, q_11+831+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+16, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+16, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+16, 4, q_11+831+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+14, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+14, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+14, 4, q_11+831+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+12, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+12, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+12, 4, q_11+831+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+10, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+10, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+10, 4, q_11+831+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+8, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+8, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+8, 4, q_11+831+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+6, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+6, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+6, 4, q_11+831+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+4, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+4, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+4, 4, q_11+831+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+2, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+2, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+2, 4, q_11+831+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+971+0, 2, p_01+977);
	GF2X_MUL(4, temp2, 2, q_11+971+0, 2, p_11+977);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+831+0, 4, q_11+831+0, 4, temp);
	

	// Recombining results: n: 17463, depth: 2
	memset(q_00+552, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(268, temp, 134, p_00+837+6, 134, q_00+831);
	GF2X_MUL(268, temp2, 134, p_10+837+6, 134, q_01+831);
	gf2x_add(268, q_00+552+5, 268, temp, 268, temp2);
	GF2X_MUL(12, temp, 6, q_00+831+128, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+128, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+127, 12, q_00+552+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+122, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+122, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+121, 12, q_00+552+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+116, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+116, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+115, 12, q_00+552+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+110, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+110, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+109, 12, q_00+552+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+104, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+104, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+103, 12, q_00+552+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+98, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+98, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+97, 12, q_00+552+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+92, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+92, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+91, 12, q_00+552+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+86, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+86, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+85, 12, q_00+552+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+80, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+80, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+79, 12, q_00+552+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+74, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+74, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+73, 12, q_00+552+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+68, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+68, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+67, 12, q_00+552+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+62, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+62, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+61, 12, q_00+552+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+56, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+56, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+55, 12, q_00+552+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+50, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+50, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+49, 12, q_00+552+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+44, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+44, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+43, 12, q_00+552+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+38, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+38, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+37, 12, q_00+552+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+32, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+32, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+31, 12, q_00+552+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+26, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+26, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+25, 12, q_00+552+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+20, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+20, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+19, 12, q_00+552+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+14, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+14, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+13, 12, q_00+552+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+8, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+8, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+7, 12, q_00+552+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+2, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_01+831+2, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+552+1, 12, q_00+552+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+837+4, 2, q_00+831);
	GF2X_MUL(4, temp2, 2, p_10+837+4, 2, q_01+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+552+3, 4, q_00+552+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+837+2, 2, q_00+831);
	GF2X_MUL(4, temp2, 2, p_10+837+2, 2, q_01+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+552+1, 4, q_00+552+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+831+0, 2, p_00+837);
	GF2X_MUL(4, temp2, 2, q_01+831+0, 2, p_10+837);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+552, 3, q_00+552, 3, temp+1);
	memset(q_01+552, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(268, temp, 134, p_01+837+6, 134, q_00+831);
	GF2X_MUL(268, temp2, 134, p_11+837+6, 134, q_01+831);
	gf2x_add(268, q_01+552+5, 268, temp, 268, temp2);
	GF2X_MUL(12, temp, 6, q_00+831+128, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+128, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+127, 12, q_01+552+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+122, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+122, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+121, 12, q_01+552+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+116, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+116, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+115, 12, q_01+552+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+110, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+110, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+109, 12, q_01+552+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+104, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+104, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+103, 12, q_01+552+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+98, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+98, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+97, 12, q_01+552+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+92, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+92, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+91, 12, q_01+552+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+86, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+86, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+85, 12, q_01+552+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+80, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+80, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+79, 12, q_01+552+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+74, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+74, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+73, 12, q_01+552+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+68, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+68, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+67, 12, q_01+552+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+62, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+62, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+61, 12, q_01+552+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+56, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+56, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+55, 12, q_01+552+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+50, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+50, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+49, 12, q_01+552+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+44, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+44, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+43, 12, q_01+552+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+38, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+38, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+37, 12, q_01+552+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+32, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+32, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+31, 12, q_01+552+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+26, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+26, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+25, 12, q_01+552+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+20, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+20, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+19, 12, q_01+552+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+14, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+14, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+13, 12, q_01+552+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+8, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+8, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+7, 12, q_01+552+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+831+2, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_01+831+2, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+552+1, 12, q_01+552+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+837+4, 2, q_00+831);
	GF2X_MUL(4, temp2, 2, p_11+837+4, 2, q_01+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+552+3, 4, q_01+552+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+837+2, 2, q_00+831);
	GF2X_MUL(4, temp2, 2, p_11+837+2, 2, q_01+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+552+1, 4, q_01+552+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+831+0, 2, p_01+837);
	GF2X_MUL(4, temp2, 2, q_01+831+0, 2, p_11+837);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+552, 3, q_01+552, 3, temp+1);
	memset(q_10+552, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(268, temp, 134, p_00+837+6, 134, q_10+831);
	GF2X_MUL(268, temp2, 134, p_10+837+6, 134, q_11+831);
	gf2x_add(268, q_10+552+5, 268, temp, 268, temp2);
	GF2X_MUL(12, temp, 6, q_10+831+128, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+128, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+127, 12, q_10+552+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+122, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+122, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+121, 12, q_10+552+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+116, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+116, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+115, 12, q_10+552+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+110, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+110, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+109, 12, q_10+552+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+104, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+104, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+103, 12, q_10+552+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+98, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+98, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+97, 12, q_10+552+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+92, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+92, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+91, 12, q_10+552+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+86, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+86, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+85, 12, q_10+552+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+80, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+80, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+79, 12, q_10+552+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+74, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+74, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+73, 12, q_10+552+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+68, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+68, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+67, 12, q_10+552+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+62, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+62, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+61, 12, q_10+552+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+56, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+56, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+55, 12, q_10+552+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+50, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+50, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+49, 12, q_10+552+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+44, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+44, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+43, 12, q_10+552+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+38, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+38, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+37, 12, q_10+552+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+32, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+32, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+31, 12, q_10+552+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+26, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+26, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+25, 12, q_10+552+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+20, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+20, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+19, 12, q_10+552+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+14, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+14, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+13, 12, q_10+552+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+8, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+8, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+7, 12, q_10+552+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+2, 6, p_00+837);
	GF2X_MUL(12, temp2, 6, q_11+831+2, 6, p_10+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+552+1, 12, q_10+552+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+837+4, 2, q_10+831);
	GF2X_MUL(4, temp2, 2, p_10+837+4, 2, q_11+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+552+3, 4, q_10+552+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+837+2, 2, q_10+831);
	GF2X_MUL(4, temp2, 2, p_10+837+2, 2, q_11+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+552+1, 4, q_10+552+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+831+0, 2, p_00+837);
	GF2X_MUL(4, temp2, 2, q_11+831+0, 2, p_10+837);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+552, 3, q_10+552, 3, temp+1);
	memset(q_11+552, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(268, temp, 134, p_01+837+6, 134, q_10+831);
	GF2X_MUL(268, temp2, 134, p_11+837+6, 134, q_11+831);
	gf2x_add(268, q_11+552+5, 268, temp, 268, temp2);
	GF2X_MUL(12, temp, 6, q_10+831+128, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+128, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+127, 12, q_11+552+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+122, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+122, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+121, 12, q_11+552+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+116, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+116, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+115, 12, q_11+552+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+110, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+110, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+109, 12, q_11+552+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+104, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+104, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+103, 12, q_11+552+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+98, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+98, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+97, 12, q_11+552+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+92, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+92, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+91, 12, q_11+552+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+86, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+86, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+85, 12, q_11+552+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+80, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+80, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+79, 12, q_11+552+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+74, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+74, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+73, 12, q_11+552+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+68, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+68, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+67, 12, q_11+552+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+62, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+62, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+61, 12, q_11+552+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+56, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+56, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+55, 12, q_11+552+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+50, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+50, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+49, 12, q_11+552+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+44, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+44, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+43, 12, q_11+552+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+38, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+38, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+37, 12, q_11+552+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+32, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+32, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+31, 12, q_11+552+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+26, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+26, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+25, 12, q_11+552+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+20, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+20, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+19, 12, q_11+552+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+14, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+14, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+13, 12, q_11+552+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+8, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+8, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+7, 12, q_11+552+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+831+2, 6, p_01+837);
	GF2X_MUL(12, temp2, 6, q_11+831+2, 6, p_11+837);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+552+1, 12, q_11+552+1, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+837+4, 2, q_10+831);
	GF2X_MUL(4, temp2, 2, p_11+837+4, 2, q_11+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+552+3, 4, q_11+552+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+837+2, 2, q_10+831);
	GF2X_MUL(4, temp2, 2, p_11+837+2, 2, q_11+831);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+552+1, 4, q_11+552+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+831+0, 2, p_01+837);
	GF2X_MUL(4, temp2, 2, q_11+831+0, 2, p_11+837);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+552, 3, q_11+552, 3, temp+1);
	

	// Recombining results: n: 35313, depth: 1
	memset(q_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(546, temp, 273, p_00+558+6, 273, q_00+552);
	GF2X_MUL(546, temp2, 273, p_10+558+6, 273, q_01+552);
	gf2x_add(546, q_00+0+6, 546, temp, 546, temp2);
	GF2X_MUL(12, temp, 6, q_00+552+267, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+267, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+267, 12, q_00+0+267, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+261, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+261, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+261, 12, q_00+0+261, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+255, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+255, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+255, 12, q_00+0+255, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+249, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+249, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+249, 12, q_00+0+249, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+243, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+243, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+243, 12, q_00+0+243, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+237, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+237, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+237, 12, q_00+0+237, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+231, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+231, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+231, 12, q_00+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+225, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+225, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+225, 12, q_00+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+219, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+219, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+219, 12, q_00+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+213, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+213, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+213, 12, q_00+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+207, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+207, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+207, 12, q_00+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+201, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+201, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+201, 12, q_00+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+195, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+195, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+195, 12, q_00+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+189, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+189, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+189, 12, q_00+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+183, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+183, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+183, 12, q_00+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+177, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+177, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+177, 12, q_00+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+171, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+171, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+171, 12, q_00+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+165, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+165, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+165, 12, q_00+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+159, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+159, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+159, 12, q_00+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+153, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+153, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+153, 12, q_00+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+147, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+147, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+147, 12, q_00+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+141, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+141, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+141, 12, q_00+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+135, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+135, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+135, 12, q_00+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+129, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+129, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+129, 12, q_00+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+123, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+123, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+123, 12, q_00+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+117, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+117, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+117, 12, q_00+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+111, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+111, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+111, 12, q_00+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+105, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+105, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+105, 12, q_00+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+99, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+99, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+99, 12, q_00+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+93, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+93, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+93, 12, q_00+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+87, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+87, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+87, 12, q_00+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+81, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+81, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+81, 12, q_00+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+75, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+75, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+75, 12, q_00+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+69, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+69, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+69, 12, q_00+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+63, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+63, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+63, 12, q_00+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+57, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+57, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+57, 12, q_00+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+51, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+51, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+51, 12, q_00+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+45, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+45, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+45, 12, q_00+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+39, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+39, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+39, 12, q_00+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+33, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+33, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+33, 12, q_00+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+27, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+27, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+27, 12, q_00+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+21, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+21, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+21, 12, q_00+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+15, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+15, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+15, 12, q_00+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+9, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+9, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+9, 12, q_00+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+3, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_01+552+3, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+3, 12, q_00+0+3, 12, temp);
	GF2X_MUL(6, temp, 3, p_00+558+3, 3, q_00+552);
	GF2X_MUL(6, temp2, 3, p_10+558+3, 3, q_01+552);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+3, 6, q_00+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+552+0, 3, p_00+558);
	GF2X_MUL(6, temp2, 3, q_01+552+0, 3, p_10+558);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+0, 6, q_00+0+0, 6, temp);
	memset(q_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(546, temp, 273, p_01+558+6, 273, q_00+552);
	GF2X_MUL(546, temp2, 273, p_11+558+6, 273, q_01+552);
	gf2x_add(546, q_01+0+6, 546, temp, 546, temp2);
	GF2X_MUL(12, temp, 6, q_00+552+267, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+267, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+267, 12, q_01+0+267, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+261, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+261, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+261, 12, q_01+0+261, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+255, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+255, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+255, 12, q_01+0+255, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+249, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+249, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+249, 12, q_01+0+249, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+243, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+243, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+243, 12, q_01+0+243, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+237, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+237, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+237, 12, q_01+0+237, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+231, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+231, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+231, 12, q_01+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+225, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+225, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+225, 12, q_01+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+219, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+219, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+219, 12, q_01+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+213, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+213, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+213, 12, q_01+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+207, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+207, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+207, 12, q_01+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+201, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+201, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+201, 12, q_01+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+195, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+195, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+195, 12, q_01+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+189, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+189, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+189, 12, q_01+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+183, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+183, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+183, 12, q_01+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+177, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+177, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+177, 12, q_01+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+171, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+171, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+171, 12, q_01+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+165, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+165, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+165, 12, q_01+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+159, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+159, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+159, 12, q_01+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+153, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+153, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+153, 12, q_01+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+147, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+147, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+147, 12, q_01+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+141, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+141, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+141, 12, q_01+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+135, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+135, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+135, 12, q_01+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+129, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+129, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+129, 12, q_01+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+123, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+123, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+123, 12, q_01+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+117, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+117, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+117, 12, q_01+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+111, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+111, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+111, 12, q_01+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+105, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+105, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+105, 12, q_01+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+99, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+99, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+99, 12, q_01+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+93, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+93, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+93, 12, q_01+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+87, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+87, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+87, 12, q_01+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+81, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+81, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+81, 12, q_01+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+75, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+75, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+75, 12, q_01+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+69, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+69, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+69, 12, q_01+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+63, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+63, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+63, 12, q_01+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+57, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+57, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+57, 12, q_01+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+51, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+51, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+51, 12, q_01+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+45, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+45, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+45, 12, q_01+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+39, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+39, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+39, 12, q_01+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+33, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+33, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+33, 12, q_01+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+27, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+27, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+27, 12, q_01+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+21, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+21, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+21, 12, q_01+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+15, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+15, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+15, 12, q_01+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+9, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+9, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+9, 12, q_01+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+552+3, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_01+552+3, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+3, 12, q_01+0+3, 12, temp);
	GF2X_MUL(6, temp, 3, p_01+558+3, 3, q_00+552);
	GF2X_MUL(6, temp2, 3, p_11+558+3, 3, q_01+552);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+3, 6, q_01+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+552+0, 3, p_01+558);
	GF2X_MUL(6, temp2, 3, q_01+552+0, 3, p_11+558);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+0, 6, q_01+0+0, 6, temp);
	memset(q_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(546, temp, 273, p_00+558+6, 273, q_10+552);
	GF2X_MUL(546, temp2, 273, p_10+558+6, 273, q_11+552);
	gf2x_add(546, q_10+0+6, 546, temp, 546, temp2);
	GF2X_MUL(12, temp, 6, q_10+552+267, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+267, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+267, 12, q_10+0+267, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+261, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+261, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+261, 12, q_10+0+261, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+255, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+255, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+255, 12, q_10+0+255, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+249, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+249, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+249, 12, q_10+0+249, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+243, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+243, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+243, 12, q_10+0+243, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+237, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+237, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+237, 12, q_10+0+237, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+231, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+231, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+231, 12, q_10+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+225, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+225, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+225, 12, q_10+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+219, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+219, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+219, 12, q_10+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+213, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+213, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+213, 12, q_10+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+207, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+207, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+207, 12, q_10+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+201, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+201, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+201, 12, q_10+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+195, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+195, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+195, 12, q_10+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+189, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+189, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+189, 12, q_10+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+183, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+183, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+183, 12, q_10+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+177, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+177, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+177, 12, q_10+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+171, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+171, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+171, 12, q_10+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+165, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+165, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+165, 12, q_10+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+159, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+159, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+159, 12, q_10+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+153, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+153, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+153, 12, q_10+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+147, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+147, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+147, 12, q_10+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+141, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+141, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+141, 12, q_10+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+135, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+135, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+135, 12, q_10+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+129, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+129, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+129, 12, q_10+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+123, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+123, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+123, 12, q_10+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+117, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+117, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+117, 12, q_10+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+111, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+111, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+111, 12, q_10+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+105, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+105, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+105, 12, q_10+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+99, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+99, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+99, 12, q_10+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+93, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+93, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+93, 12, q_10+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+87, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+87, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+87, 12, q_10+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+81, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+81, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+81, 12, q_10+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+75, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+75, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+75, 12, q_10+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+69, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+69, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+69, 12, q_10+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+63, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+63, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+63, 12, q_10+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+57, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+57, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+57, 12, q_10+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+51, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+51, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+51, 12, q_10+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+45, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+45, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+45, 12, q_10+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+39, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+39, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+39, 12, q_10+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+33, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+33, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+33, 12, q_10+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+27, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+27, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+27, 12, q_10+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+21, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+21, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+21, 12, q_10+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+15, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+15, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+15, 12, q_10+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+9, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+9, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+9, 12, q_10+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+3, 6, p_00+558);
	GF2X_MUL(12, temp2, 6, q_11+552+3, 6, p_10+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+3, 12, q_10+0+3, 12, temp);
	GF2X_MUL(6, temp, 3, p_00+558+3, 3, q_10+552);
	GF2X_MUL(6, temp2, 3, p_10+558+3, 3, q_11+552);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+3, 6, q_10+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+552+0, 3, p_00+558);
	GF2X_MUL(6, temp2, 3, q_11+552+0, 3, p_10+558);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+0, 6, q_10+0+0, 6, temp);
	memset(q_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(546, temp, 273, p_01+558+6, 273, q_10+552);
	GF2X_MUL(546, temp2, 273, p_11+558+6, 273, q_11+552);
	gf2x_add(546, q_11+0+6, 546, temp, 546, temp2);
	GF2X_MUL(12, temp, 6, q_10+552+267, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+267, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+267, 12, q_11+0+267, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+261, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+261, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+261, 12, q_11+0+261, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+255, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+255, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+255, 12, q_11+0+255, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+249, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+249, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+249, 12, q_11+0+249, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+243, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+243, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+243, 12, q_11+0+243, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+237, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+237, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+237, 12, q_11+0+237, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+231, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+231, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+231, 12, q_11+0+231, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+225, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+225, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+225, 12, q_11+0+225, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+219, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+219, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+219, 12, q_11+0+219, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+213, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+213, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+213, 12, q_11+0+213, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+207, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+207, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+207, 12, q_11+0+207, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+201, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+201, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+201, 12, q_11+0+201, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+195, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+195, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+195, 12, q_11+0+195, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+189, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+189, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+189, 12, q_11+0+189, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+183, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+183, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+183, 12, q_11+0+183, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+177, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+177, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+177, 12, q_11+0+177, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+171, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+171, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+171, 12, q_11+0+171, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+165, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+165, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+165, 12, q_11+0+165, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+159, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+159, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+159, 12, q_11+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+153, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+153, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+153, 12, q_11+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+147, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+147, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+147, 12, q_11+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+141, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+141, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+141, 12, q_11+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+135, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+135, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+135, 12, q_11+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+129, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+129, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+129, 12, q_11+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+123, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+123, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+123, 12, q_11+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+117, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+117, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+117, 12, q_11+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+111, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+111, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+111, 12, q_11+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+105, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+105, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+105, 12, q_11+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+99, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+99, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+99, 12, q_11+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+93, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+93, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+93, 12, q_11+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+87, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+87, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+87, 12, q_11+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+81, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+81, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+81, 12, q_11+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+75, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+75, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+75, 12, q_11+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+69, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+69, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+69, 12, q_11+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+63, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+63, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+63, 12, q_11+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+57, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+57, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+57, 12, q_11+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+51, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+51, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+51, 12, q_11+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+45, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+45, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+45, 12, q_11+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+39, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+39, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+39, 12, q_11+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+33, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+33, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+33, 12, q_11+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+27, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+27, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+27, 12, q_11+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+21, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+21, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+21, 12, q_11+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+15, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+15, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+15, 12, q_11+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+9, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+9, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+9, 12, q_11+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+552+3, 6, p_01+558);
	GF2X_MUL(12, temp2, 6, q_11+552+3, 6, p_11+558);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+3, 12, q_11+0+3, 12, temp);
	GF2X_MUL(6, temp, 3, p_01+558+3, 3, q_10+552);
	GF2X_MUL(6, temp2, 3, p_11+558+3, 3, q_11+552);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+3, 6, q_11+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+552+0, 3, p_01+558);
	GF2X_MUL(6, temp2, 3, q_11+552+0, 3, p_11+558);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+0, 6, q_11+0+0, 6, temp);
	

	// Recombining results: n: 71013, depth: 0
	memset(t_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(1104, temp, 552, p_00+0+6, 552, q_00+0);
	GF2X_MUL(1104, temp2, 552, p_10+0+6, 552, q_01+0);
	gf2x_add(1104, t_00+0+6, 1104, temp, 1104, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+546, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+546, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+546, 12, t_00+0+546, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+540, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+540, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+540, 12, t_00+0+540, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+534, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+534, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+534, 12, t_00+0+534, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+528, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+528, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+528, 12, t_00+0+528, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+522, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+522, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+522, 12, t_00+0+522, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+516, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+516, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+516, 12, t_00+0+516, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+510, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+510, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+510, 12, t_00+0+510, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+504, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+504, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+504, 12, t_00+0+504, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+498, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+498, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+498, 12, t_00+0+498, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+492, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+492, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+492, 12, t_00+0+492, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+486, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+486, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+486, 12, t_00+0+486, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+480, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+480, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+480, 12, t_00+0+480, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+474, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+474, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+474, 12, t_00+0+474, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+468, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+468, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+468, 12, t_00+0+468, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+462, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+462, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+462, 12, t_00+0+462, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+456, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+456, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+456, 12, t_00+0+456, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+450, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+450, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+450, 12, t_00+0+450, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+444, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+444, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+444, 12, t_00+0+444, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+438, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+438, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+438, 12, t_00+0+438, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+432, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+432, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+432, 12, t_00+0+432, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+426, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+426, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+426, 12, t_00+0+426, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+420, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+420, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+420, 12, t_00+0+420, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+414, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+414, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+414, 12, t_00+0+414, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+408, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+408, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+408, 12, t_00+0+408, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+402, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+402, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+402, 12, t_00+0+402, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+396, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+396, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+396, 12, t_00+0+396, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+390, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+390, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+390, 12, t_00+0+390, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+384, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+384, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+384, 12, t_00+0+384, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+378, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+378, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+378, 12, t_00+0+378, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+372, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+372, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+372, 12, t_00+0+372, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+366, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+366, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+366, 12, t_00+0+366, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+360, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+360, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+360, 12, t_00+0+360, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+354, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+354, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+354, 12, t_00+0+354, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+348, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+348, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+348, 12, t_00+0+348, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+342, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+342, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+342, 12, t_00+0+342, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+336, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+336, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+336, 12, t_00+0+336, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+330, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+330, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+330, 12, t_00+0+330, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+324, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+324, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+324, 12, t_00+0+324, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+318, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+318, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+318, 12, t_00+0+318, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+312, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+312, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+312, 12, t_00+0+312, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+306, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+306, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+306, 12, t_00+0+306, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+300, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+300, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+300, 12, t_00+0+300, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+294, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+294, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+294, 12, t_00+0+294, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+288, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+288, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+288, 12, t_00+0+288, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+282, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+282, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+282, 12, t_00+0+282, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+276, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+276, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+276, 12, t_00+0+276, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+270, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+270, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+270, 12, t_00+0+270, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+264, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+264, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+264, 12, t_00+0+264, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+258, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+258, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+258, 12, t_00+0+258, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+252, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+252, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+252, 12, t_00+0+252, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+246, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+246, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+246, 12, t_00+0+246, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+240, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+240, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+240, 12, t_00+0+240, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+234, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+234, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+234, 12, t_00+0+234, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+228, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+228, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+228, 12, t_00+0+228, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+222, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+222, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+222, 12, t_00+0+222, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+216, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+216, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+216, 12, t_00+0+216, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+210, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+210, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+210, 12, t_00+0+210, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+204, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+204, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+204, 12, t_00+0+204, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+198, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+198, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+198, 12, t_00+0+198, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+192, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+192, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+192, 12, t_00+0+192, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+186, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+186, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+186, 12, t_00+0+186, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+180, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+180, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+180, 12, t_00+0+180, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+174, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+174, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+174, 12, t_00+0+174, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+168, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+168, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+168, 12, t_00+0+168, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+162, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+162, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+162, 12, t_00+0+162, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+156, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+156, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+156, 12, t_00+0+156, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+150, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+150, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+150, 12, t_00+0+150, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+144, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+144, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+144, 12, t_00+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+138, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+138, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+138, 12, t_00+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+132, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+132, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+132, 12, t_00+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+126, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+126, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+126, 12, t_00+0+126, 12, temp);
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
	GF2X_MUL(1104, temp, 552, p_01+0+6, 552, q_00+0);
	GF2X_MUL(1104, temp2, 552, p_11+0+6, 552, q_01+0);
	gf2x_add(1104, t_01+0+6, 1104, temp, 1104, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+546, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+546, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+546, 12, t_01+0+546, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+540, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+540, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+540, 12, t_01+0+540, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+534, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+534, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+534, 12, t_01+0+534, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+528, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+528, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+528, 12, t_01+0+528, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+522, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+522, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+522, 12, t_01+0+522, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+516, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+516, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+516, 12, t_01+0+516, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+510, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+510, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+510, 12, t_01+0+510, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+504, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+504, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+504, 12, t_01+0+504, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+498, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+498, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+498, 12, t_01+0+498, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+492, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+492, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+492, 12, t_01+0+492, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+486, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+486, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+486, 12, t_01+0+486, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+480, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+480, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+480, 12, t_01+0+480, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+474, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+474, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+474, 12, t_01+0+474, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+468, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+468, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+468, 12, t_01+0+468, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+462, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+462, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+462, 12, t_01+0+462, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+456, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+456, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+456, 12, t_01+0+456, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+450, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+450, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+450, 12, t_01+0+450, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+444, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+444, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+444, 12, t_01+0+444, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+438, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+438, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+438, 12, t_01+0+438, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+432, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+432, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+432, 12, t_01+0+432, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+426, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+426, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+426, 12, t_01+0+426, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+420, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+420, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+420, 12, t_01+0+420, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+414, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+414, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+414, 12, t_01+0+414, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+408, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+408, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+408, 12, t_01+0+408, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+402, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+402, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+402, 12, t_01+0+402, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+396, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+396, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+396, 12, t_01+0+396, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+390, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+390, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+390, 12, t_01+0+390, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+384, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+384, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+384, 12, t_01+0+384, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+378, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+378, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+378, 12, t_01+0+378, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+372, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+372, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+372, 12, t_01+0+372, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+366, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+366, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+366, 12, t_01+0+366, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+360, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+360, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+360, 12, t_01+0+360, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+354, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+354, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+354, 12, t_01+0+354, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+348, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+348, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+348, 12, t_01+0+348, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+342, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+342, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+342, 12, t_01+0+342, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+336, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+336, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+336, 12, t_01+0+336, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+330, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+330, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+330, 12, t_01+0+330, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+324, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+324, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+324, 12, t_01+0+324, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+318, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+318, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+318, 12, t_01+0+318, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+312, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+312, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+312, 12, t_01+0+312, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+306, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+306, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+306, 12, t_01+0+306, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+300, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+300, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+300, 12, t_01+0+300, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+294, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+294, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+294, 12, t_01+0+294, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+288, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+288, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+288, 12, t_01+0+288, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+282, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+282, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+282, 12, t_01+0+282, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+276, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+276, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+276, 12, t_01+0+276, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+270, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+270, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+270, 12, t_01+0+270, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+264, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+264, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+264, 12, t_01+0+264, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+258, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+258, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+258, 12, t_01+0+258, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+252, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+252, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+252, 12, t_01+0+252, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+246, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+246, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+246, 12, t_01+0+246, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+240, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+240, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+240, 12, t_01+0+240, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+234, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+234, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+234, 12, t_01+0+234, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+228, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+228, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+228, 12, t_01+0+228, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+222, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+222, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+222, 12, t_01+0+222, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+216, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+216, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+216, 12, t_01+0+216, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+210, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+210, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+210, 12, t_01+0+210, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+204, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+204, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+204, 12, t_01+0+204, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+198, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+198, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+198, 12, t_01+0+198, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+192, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+192, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+192, 12, t_01+0+192, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+186, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+186, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+186, 12, t_01+0+186, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+180, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+180, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+180, 12, t_01+0+180, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+174, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+174, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+174, 12, t_01+0+174, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+168, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+168, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+168, 12, t_01+0+168, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+162, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+162, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+162, 12, t_01+0+162, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+156, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+156, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+156, 12, t_01+0+156, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+150, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+150, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+150, 12, t_01+0+150, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+144, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+144, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+144, 12, t_01+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+138, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+138, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+138, 12, t_01+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+132, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+132, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+132, 12, t_01+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+126, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+126, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+126, 12, t_01+0+126, 12, temp);
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
	GF2X_MUL(1104, temp, 552, p_00+0+6, 552, q_10+0);
	GF2X_MUL(1104, temp2, 552, p_10+0+6, 552, q_11+0);
	gf2x_add(1104, t_10+0+6, 1104, temp, 1104, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+546, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+546, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+546, 12, t_10+0+546, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+540, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+540, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+540, 12, t_10+0+540, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+534, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+534, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+534, 12, t_10+0+534, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+528, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+528, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+528, 12, t_10+0+528, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+522, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+522, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+522, 12, t_10+0+522, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+516, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+516, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+516, 12, t_10+0+516, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+510, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+510, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+510, 12, t_10+0+510, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+504, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+504, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+504, 12, t_10+0+504, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+498, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+498, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+498, 12, t_10+0+498, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+492, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+492, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+492, 12, t_10+0+492, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+486, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+486, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+486, 12, t_10+0+486, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+480, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+480, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+480, 12, t_10+0+480, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+474, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+474, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+474, 12, t_10+0+474, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+468, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+468, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+468, 12, t_10+0+468, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+462, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+462, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+462, 12, t_10+0+462, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+456, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+456, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+456, 12, t_10+0+456, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+450, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+450, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+450, 12, t_10+0+450, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+444, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+444, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+444, 12, t_10+0+444, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+438, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+438, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+438, 12, t_10+0+438, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+432, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+432, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+432, 12, t_10+0+432, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+426, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+426, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+426, 12, t_10+0+426, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+420, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+420, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+420, 12, t_10+0+420, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+414, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+414, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+414, 12, t_10+0+414, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+408, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+408, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+408, 12, t_10+0+408, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+402, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+402, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+402, 12, t_10+0+402, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+396, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+396, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+396, 12, t_10+0+396, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+390, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+390, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+390, 12, t_10+0+390, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+384, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+384, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+384, 12, t_10+0+384, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+378, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+378, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+378, 12, t_10+0+378, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+372, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+372, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+372, 12, t_10+0+372, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+366, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+366, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+366, 12, t_10+0+366, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+360, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+360, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+360, 12, t_10+0+360, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+354, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+354, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+354, 12, t_10+0+354, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+348, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+348, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+348, 12, t_10+0+348, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+342, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+342, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+342, 12, t_10+0+342, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+336, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+336, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+336, 12, t_10+0+336, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+330, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+330, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+330, 12, t_10+0+330, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+324, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+324, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+324, 12, t_10+0+324, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+318, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+318, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+318, 12, t_10+0+318, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+312, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+312, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+312, 12, t_10+0+312, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+306, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+306, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+306, 12, t_10+0+306, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+300, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+300, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+300, 12, t_10+0+300, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+294, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+294, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+294, 12, t_10+0+294, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+288, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+288, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+288, 12, t_10+0+288, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+282, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+282, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+282, 12, t_10+0+282, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+276, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+276, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+276, 12, t_10+0+276, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+270, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+270, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+270, 12, t_10+0+270, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+264, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+264, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+264, 12, t_10+0+264, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+258, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+258, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+258, 12, t_10+0+258, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+252, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+252, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+252, 12, t_10+0+252, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+246, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+246, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+246, 12, t_10+0+246, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+240, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+240, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+240, 12, t_10+0+240, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+234, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+234, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+234, 12, t_10+0+234, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+228, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+228, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+228, 12, t_10+0+228, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+222, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+222, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+222, 12, t_10+0+222, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+216, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+216, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+216, 12, t_10+0+216, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+210, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+210, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+210, 12, t_10+0+210, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+204, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+204, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+204, 12, t_10+0+204, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+198, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+198, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+198, 12, t_10+0+198, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+192, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+192, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+192, 12, t_10+0+192, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+186, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+186, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+186, 12, t_10+0+186, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+180, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+180, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+180, 12, t_10+0+180, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+174, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+174, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+174, 12, t_10+0+174, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+168, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+168, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+168, 12, t_10+0+168, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+162, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+162, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+162, 12, t_10+0+162, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+156, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+156, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+156, 12, t_10+0+156, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+150, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+150, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+150, 12, t_10+0+150, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+144, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+144, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+144, 12, t_10+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+138, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+138, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+138, 12, t_10+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+132, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+132, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+132, 12, t_10+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+126, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+126, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+126, 12, t_10+0+126, 12, temp);
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
	GF2X_MUL(1104, temp, 552, p_01+0+6, 552, q_10+0);
	GF2X_MUL(1104, temp2, 552, p_11+0+6, 552, q_11+0);
	gf2x_add(1104, t_11+0+6, 1104, temp, 1104, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+546, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+546, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+546, 12, t_11+0+546, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+540, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+540, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+540, 12, t_11+0+540, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+534, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+534, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+534, 12, t_11+0+534, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+528, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+528, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+528, 12, t_11+0+528, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+522, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+522, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+522, 12, t_11+0+522, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+516, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+516, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+516, 12, t_11+0+516, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+510, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+510, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+510, 12, t_11+0+510, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+504, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+504, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+504, 12, t_11+0+504, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+498, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+498, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+498, 12, t_11+0+498, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+492, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+492, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+492, 12, t_11+0+492, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+486, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+486, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+486, 12, t_11+0+486, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+480, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+480, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+480, 12, t_11+0+480, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+474, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+474, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+474, 12, t_11+0+474, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+468, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+468, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+468, 12, t_11+0+468, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+462, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+462, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+462, 12, t_11+0+462, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+456, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+456, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+456, 12, t_11+0+456, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+450, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+450, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+450, 12, t_11+0+450, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+444, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+444, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+444, 12, t_11+0+444, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+438, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+438, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+438, 12, t_11+0+438, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+432, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+432, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+432, 12, t_11+0+432, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+426, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+426, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+426, 12, t_11+0+426, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+420, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+420, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+420, 12, t_11+0+420, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+414, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+414, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+414, 12, t_11+0+414, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+408, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+408, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+408, 12, t_11+0+408, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+402, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+402, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+402, 12, t_11+0+402, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+396, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+396, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+396, 12, t_11+0+396, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+390, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+390, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+390, 12, t_11+0+390, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+384, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+384, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+384, 12, t_11+0+384, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+378, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+378, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+378, 12, t_11+0+378, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+372, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+372, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+372, 12, t_11+0+372, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+366, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+366, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+366, 12, t_11+0+366, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+360, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+360, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+360, 12, t_11+0+360, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+354, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+354, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+354, 12, t_11+0+354, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+348, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+348, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+348, 12, t_11+0+348, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+342, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+342, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+342, 12, t_11+0+342, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+336, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+336, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+336, 12, t_11+0+336, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+330, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+330, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+330, 12, t_11+0+330, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+324, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+324, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+324, 12, t_11+0+324, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+318, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+318, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+318, 12, t_11+0+318, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+312, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+312, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+312, 12, t_11+0+312, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+306, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+306, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+306, 12, t_11+0+306, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+300, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+300, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+300, 12, t_11+0+300, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+294, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+294, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+294, 12, t_11+0+294, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+288, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+288, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+288, 12, t_11+0+288, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+282, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+282, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+282, 12, t_11+0+282, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+276, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+276, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+276, 12, t_11+0+276, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+270, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+270, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+270, 12, t_11+0+270, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+264, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+264, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+264, 12, t_11+0+264, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+258, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+258, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+258, 12, t_11+0+258, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+252, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+252, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+252, 12, t_11+0+252, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+246, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+246, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+246, 12, t_11+0+246, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+240, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+240, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+240, 12, t_11+0+240, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+234, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+234, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+234, 12, t_11+0+234, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+228, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+228, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+228, 12, t_11+0+228, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+222, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+222, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+222, 12, t_11+0+222, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+216, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+216, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+216, 12, t_11+0+216, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+210, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+210, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+210, 12, t_11+0+210, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+204, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+204, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+204, 12, t_11+0+204, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+198, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+198, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+198, 12, t_11+0+198, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+192, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+192, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+192, 12, t_11+0+192, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+186, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+186, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+186, 12, t_11+0+186, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+180, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+180, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+180, 12, t_11+0+180, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+174, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+174, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+174, 12, t_11+0+174, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+168, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+168, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+168, 12, t_11+0+168, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+162, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+162, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+162, 12, t_11+0+162, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+156, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+156, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+156, 12, t_11+0+156, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+150, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+150, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+150, 12, t_11+0+150, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+144, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+144, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+144, 12, t_11+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+138, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+138, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+138, 12, t_11+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+132, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+132, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+132, 12, t_11+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+126, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+126, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+126, 12, t_11+0+126, 12, temp);
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