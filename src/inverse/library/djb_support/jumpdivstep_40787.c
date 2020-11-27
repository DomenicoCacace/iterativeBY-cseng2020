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

int jumpdivstep_40787(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[1281];
	DIGIT p_01[1281];
	DIGIT p_10[1281];
	DIGIT p_11[1281];
	
	DIGIT q_00[1273];
	DIGIT q_01[1273];
	DIGIT q_10[1273];
	DIGIT q_11[1273];
	
	DIGIT f_sum[3843];
	DIGIT g_sum[3843];
	
	DIGIT temp[2550];
	DIGIT temp2[2550];
	

	delta = divstepsx_256(255, delta, f+1271, g+1271, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+1267+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g+1267+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1267+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g+1267+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f+1267+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g+1267+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+1267+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g+1267+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+1263+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g+1263+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f+1263);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g+1263);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f+1263+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g+1263+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f+1263);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g+1263);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+1255+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g+1255+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f+1255);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g+1255);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f+1255+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g+1255+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f+1255);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g+1255);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f+1235+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g+1235+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f+1235+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g+1235+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f+1235+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g+1235+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f+1235+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g+1235+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f+1195+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g+1195+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f+1195+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g+1195+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f+1195+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g+1195+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f+1195+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g+1195+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f+1115+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g+1115+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f+1115+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g+1115+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f+1115+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g+1115+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f+1115+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g+1115+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, p_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, p_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, p_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, p_11+957+0, 160, temp, 160, temp2);
	

	// Calculating left operands: n: 20400, depth: 2
	// Digits to shift: 159
	// Displacement: 159
	GF2X_MUL(320, temp, 160, f+956+159, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, g+956+159, 160, p_01+957);
	gf2x_add(320, f_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, f+956);
	GF2X_MUL(318, temp2, 159, p_01+957+1, 159, g+956);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, f_sum+2872, 160, f_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f+956+158, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, g+956+158, 1, p_01+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2872, 1, f_sum+2872, 1, temp+1);
	right_bit_shift_n(319, f_sum+2872, 24);
	GF2X_MUL(320, temp, 160, f+956+159, 160, p_10+957);
	GF2X_MUL(320, temp2, 160, g+956+159, 160, p_11+957);
	gf2x_add(320, g_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_10+957+1, 159, f+956);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, g+956);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, g_sum+2872, 160, g_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f+956+158, 1, p_10+957);
	GF2X_MUL(2, temp2, 1, g+956+158, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2872, 1, g_sum+2872, 1, temp+1);
	right_bit_shift_n(319, g_sum+2872, 24);
	

	delta = divstepsx_256(255, delta, f_sum+3029, g_sum+3029, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, q_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, q_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, q_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, q_11+957+0, 160, temp, 160, temp2);
	

	// Recombining results: n: 20400, depth: 2
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_10+957);
	gf2x_add(319, p_00+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_11+957);
	gf2x_add(319, p_01+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_10+957);
	gf2x_add(319, p_10+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_11+957);
	gf2x_add(319, p_11+638, 319, temp+1, 319, temp2+1);
	

	// Calculating left operands: n: 40800, depth: 1
	// Digits to shift: 318
	// Displacement: 319
	GF2X_MUL(638, temp, 319, f+637+319, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, g+637+319, 319, p_01+638);
	gf2x_add(638, f_sum+1914+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, f+637+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, g+637+0, 319, p_01+638);
	gf2x_add(638, temp, 638, temp, 638, temp2);
	gf2x_add(319, f_sum+1914, 319, f_sum+1914, 319, temp+319);
	right_bit_shift_n(638, f_sum+1914, 48);
	GF2X_MUL(638, temp, 319, f+637+319, 319, p_10+638);
	GF2X_MUL(638, temp2, 319, g+637+319, 319, p_11+638);
	gf2x_add(638, g_sum+1914+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, f+637+0, 319, p_10+638);
	GF2X_MUL(638, temp2, 319, g+637+0, 319, p_11+638);
	gf2x_add(638, temp, 638, temp, 638, temp2);
	gf2x_add(319, g_sum+1914, 319, g_sum+1914, 319, temp+319);
	right_bit_shift_n(638, g_sum+1914, 48);
	

	delta = divstepsx_256(255, delta, f_sum+2230, g_sum+2230, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2226+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2226+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+2226+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2226+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2222+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+2222+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+2222);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+2222);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+2222+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+2222+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+2222);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+2222);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2214+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+2214+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+2214);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+2214);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+2214+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+2214+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+2214);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+2214);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2194+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2194+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2194+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2194+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2154+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2154+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2154+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2154+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+2074+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2074+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2074+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2074+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, p_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, p_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, p_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, p_11+957+0, 160, temp, 160, temp2);
	

	// Calculating left operands: n: 20400, depth: 2
	// Digits to shift: 159
	// Displacement: 159
	GF2X_MUL(320, temp, 160, f_sum+1915+159, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, g_sum+1915+159, 160, p_01+957);
	gf2x_add(320, f_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, f_sum+1915);
	GF2X_MUL(318, temp2, 159, p_01+957+1, 159, g_sum+1915);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, f_sum+2872, 160, f_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f_sum+1915+158, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, g_sum+1915+158, 1, p_01+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2872, 1, f_sum+2872, 1, temp+1);
	right_bit_shift_n(319, f_sum+2872, 24);
	GF2X_MUL(320, temp, 160, f_sum+1915+159, 160, p_10+957);
	GF2X_MUL(320, temp2, 160, g_sum+1915+159, 160, p_11+957);
	gf2x_add(320, g_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_10+957+1, 159, f_sum+1915);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, g_sum+1915);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, g_sum+2872, 160, g_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f_sum+1915+158, 1, p_10+957);
	GF2X_MUL(2, temp2, 1, g_sum+1915+158, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2872, 1, g_sum+2872, 1, temp+1);
	right_bit_shift_n(319, g_sum+2872, 24);
	

	delta = divstepsx_256(255, delta, f_sum+3029, g_sum+3029, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, q_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, q_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, q_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, q_11+957+0, 160, temp, 160, temp2);
	

	// Recombining results: n: 20400, depth: 2
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_10+957);
	gf2x_add(319, q_00+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_11+957);
	gf2x_add(319, q_01+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_10+957);
	gf2x_add(319, q_10+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_11+957);
	gf2x_add(319, q_11+638, 319, temp+1, 319, temp2+1);
	

	// Recombining results: n: 40800, depth: 1
	GF2X_MUL(638, temp, 319, q_00+638+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, q_01+638+0, 319, p_10+638);
	gf2x_add(638, p_00+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_00+638+0, 319, p_01+638);
	GF2X_MUL(638, temp2, 319, q_01+638+0, 319, p_11+638);
	gf2x_add(638, p_01+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_10+638+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, q_11+638+0, 319, p_10+638);
	gf2x_add(638, p_10+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_10+638+0, 319, p_01+638);
	GF2X_MUL(638, temp2, 319, q_11+638+0, 319, p_11+638);
	gf2x_add(638, p_11+0+0, 638, temp, 638, temp2);
	

	// Calculating left operands: n: 81573, depth: 0
	// Digits to shift: 637
	// Displacement: 637
	GF2X_MUL(1276, temp, 638, f+0+637, 638, p_00+0);
	GF2X_MUL(1276, temp2, 638, g+0+637, 638, p_01+0);
	gf2x_add(1276, f_sum+0+0, 1276, temp, 1276, temp2);
	GF2X_MUL(1274, temp, 637, p_00+0+1, 637, f+0);
	GF2X_MUL(1274, temp2, 637, p_01+0+1, 637, g+0);
	gf2x_add(1274, temp, 1274, temp, 1274, temp2);
	gf2x_add(638, f_sum+0, 638, f_sum+0, 638, temp+636);
	GF2X_MUL(2, temp, 1, f+0+636, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, g+0+636, 1, p_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+1);
	right_bit_shift_n(1275, f_sum+0, 32);
	GF2X_MUL(1276, temp, 638, f+0+637, 638, p_10+0);
	GF2X_MUL(1276, temp2, 638, g+0+637, 638, p_11+0);
	gf2x_add(1276, g_sum+0+0, 1276, temp, 1276, temp2);
	GF2X_MUL(1274, temp, 637, p_10+0+1, 637, f+0);
	GF2X_MUL(1274, temp2, 637, p_11+0+1, 637, g+0);
	gf2x_add(1274, temp, 1274, temp, 1274, temp2);
	gf2x_add(638, g_sum+0, 638, g_sum+0, 638, temp+636);
	GF2X_MUL(2, temp, 1, f+0+636, 1, p_10+0);
	GF2X_MUL(2, temp2, 1, g+0+636, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+1);
	right_bit_shift_n(1275, g_sum+0, 32);
	

	delta = divstepsx_256(255, delta, f_sum+635, g_sum+635, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+631+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+631+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+631+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+631+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+631+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+631+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+631+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+631+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+627+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+627+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+627);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+627+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+627+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+627);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+619+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+619+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+619);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+619);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+619+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+619+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+619);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+619);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+599+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+599+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+599+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+599+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+599+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+599+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+599+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+599+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+559+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+559+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+559+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+559+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+559+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+559+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+559+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+559+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+479+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+479+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+479+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+479+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+479+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+479+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+479+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+479+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, p_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, p_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, p_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, p_11+957+0, 160, temp, 160, temp2);
	

	// Calculating left operands: n: 20400, depth: 2
	// Digits to shift: 159
	// Displacement: 159
	GF2X_MUL(320, temp, 160, f_sum+320+159, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, g_sum+320+159, 160, p_01+957);
	gf2x_add(320, f_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, f_sum+320);
	GF2X_MUL(318, temp2, 159, p_01+957+1, 159, g_sum+320);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, f_sum+2872, 160, f_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f_sum+320+158, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, g_sum+320+158, 1, p_01+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+2872, 1, f_sum+2872, 1, temp+1);
	right_bit_shift_n(319, f_sum+2872, 24);
	GF2X_MUL(320, temp, 160, f_sum+320+159, 160, p_10+957);
	GF2X_MUL(320, temp2, 160, g_sum+320+159, 160, p_11+957);
	gf2x_add(320, g_sum+2872+0, 320, temp, 320, temp2);
	GF2X_MUL(318, temp, 159, p_10+957+1, 159, f_sum+320);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, g_sum+320);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(160, g_sum+2872, 160, g_sum+2872, 160, temp+158);
	GF2X_MUL(2, temp, 1, f_sum+320+158, 1, p_10+957);
	GF2X_MUL(2, temp2, 1, g_sum+320+158, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+2872, 1, g_sum+2872, 1, temp+1);
	right_bit_shift_n(319, g_sum+2872, 24);
	

	delta = divstepsx_256(255, delta, f_sum+3029, g_sum+3029, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3025+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3025+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3025+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3021+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3021+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3021);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3021);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3013+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3013+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3013);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3013);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2993+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2993+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2993+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2953+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2953+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2953+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2873+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2873+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, q_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, q_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, q_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, q_11+957+0, 160, temp, 160, temp2);
	

	// Recombining results: n: 20400, depth: 2
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_10+957);
	gf2x_add(319, p_00+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_00+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_01+957+0, 160, p_11+957);
	gf2x_add(319, p_01+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_10+957);
	gf2x_add(319, p_10+638, 319, temp+1, 319, temp2+1);
	GF2X_MUL(320, temp, 160, q_10+957+0, 160, p_01+957);
	GF2X_MUL(320, temp2, 160, q_11+957+0, 160, p_11+957);
	gf2x_add(319, p_11+638, 319, temp+1, 319, temp2+1);
	

	// Calculating left operands: n: 40773, depth: 1
	// Digits to shift: 318
	// Displacement: 319
	GF2X_MUL(638, temp, 319, f_sum+1+319, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, g_sum+1+319, 319, p_01+638);
	gf2x_add(638, f_sum+1914+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, f_sum+1+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, g_sum+1+0, 319, p_01+638);
	gf2x_add(638, temp, 638, temp, 638, temp2);
	gf2x_add(319, f_sum+1914, 319, f_sum+1914, 319, temp+319);
	right_bit_shift_n(638, f_sum+1914, 48);
	GF2X_MUL(638, temp, 319, f_sum+1+319, 319, p_10+638);
	GF2X_MUL(638, temp2, 319, g_sum+1+319, 319, p_11+638);
	gf2x_add(638, g_sum+1914+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, f_sum+1+0, 319, p_10+638);
	GF2X_MUL(638, temp2, 319, g_sum+1+0, 319, p_11+638);
	gf2x_add(638, temp, 638, temp, 638, temp2);
	gf2x_add(319, g_sum+1914, 319, g_sum+1914, 319, temp+319);
	right_bit_shift_n(638, g_sum+1914, 48);
	

	delta = divstepsx_256(255, delta, f_sum+2230, g_sum+2230, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2226+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2226+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+2226+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2226+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+2226+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2222+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+2222+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+2222);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+2222);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+2222+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+2222+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+2222);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+2222);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2214+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+2214+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+2214);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+2214);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+2214+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+2214+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+2214);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+2214);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2194+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2194+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2194+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2194+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2194+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2154+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2154+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2154+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2154+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2154+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10200, depth: 3
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+2074+80, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+80, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2074+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+0, 80, p_01+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+80);
	right_bit_shift_n(160, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2074+80, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+80, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, f_sum+2074+0, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2074+0, 80, p_11+1117);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+80);
	right_bit_shift_n(160, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10200, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(160, p_00+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(160, p_01+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(160, p_10+957+0, 160, temp, 160, temp2);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(160, p_11+957+0, 160, temp, 160, temp2);
	

	// Calculating left operands: n: 20373, depth: 2
	// Digits to shift: 159
	// Displacement: 160
	GF2X_MUL(320, temp, 160, f_sum+1915+159, 160, p_00+957);
	GF2X_MUL(320, temp2, 160, g_sum+1915+159, 160, p_01+957);
	gf2x_add(319, f_sum+2872, 319, temp+1, 319, temp2+1);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, f_sum+1915);
	GF2X_MUL(318, temp2, 159, p_01+957+1, 159, g_sum+1915);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(159, f_sum+2872, 159, f_sum+2872, 159, temp+159);
	right_bit_shift_n(319, f_sum+2872, 24);
	GF2X_MUL(320, temp, 160, f_sum+1915+159, 160, p_10+957);
	GF2X_MUL(320, temp2, 160, g_sum+1915+159, 160, p_11+957);
	gf2x_add(319, g_sum+2872, 319, temp+1, 319, temp2+1);
	GF2X_MUL(318, temp, 159, p_10+957+1, 159, f_sum+1915);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, g_sum+1915);
	gf2x_add(318, temp, 318, temp, 318, temp2);
	gf2x_add(159, g_sum+2872, 159, g_sum+2872, 159, temp+159);
	right_bit_shift_n(319, g_sum+2872, 24);
	

	delta = divstepsx_256(255, delta, f_sum+3028, g_sum+3028, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3024+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3024+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3024+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3024+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3024+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3024+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3024+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3024+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3020+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3020+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3020);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3020);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3020+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3020+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3020);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3020);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3012+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3012+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3012);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3012);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3012+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3012+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3012);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3012);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+2992+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2992+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2992+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2992+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+2992+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2992+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+2992+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+2992+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+2952+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2952+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2952+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2952+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+2952+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2952+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+2952+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+2952+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, p_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, p_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, p_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, p_11+1117+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 10173, depth: 3
	// Digits to shift: 79
	// Displacement: 79
	GF2X_MUL(160, temp, 80, f_sum+2873+79, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+79, 80, p_01+1117);
	gf2x_add(160, f_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(158, temp, 79, p_00+1117+1, 79, f_sum+2873);
	GF2X_MUL(158, temp2, 79, p_01+1117+1, 79, g_sum+2873);
	gf2x_add(158, temp, 158, temp, 158, temp2);
	gf2x_add(80, f_sum+3352, 80, f_sum+3352, 80, temp+78);
	GF2X_MUL(2, temp, 1, f_sum+2873+78, 1, p_00+1117);
	GF2X_MUL(2, temp2, 1, g_sum+2873+78, 1, p_01+1117);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+3352, 1, f_sum+3352, 1, temp+1);
	right_bit_shift_n(159, f_sum+3352, 44);
	GF2X_MUL(160, temp, 80, f_sum+2873+79, 80, p_10+1117);
	GF2X_MUL(160, temp2, 80, g_sum+2873+79, 80, p_11+1117);
	gf2x_add(160, g_sum+3352+0, 160, temp, 160, temp2);
	GF2X_MUL(158, temp, 79, p_10+1117+1, 79, f_sum+2873);
	GF2X_MUL(158, temp2, 79, p_11+1117+1, 79, g_sum+2873);
	gf2x_add(158, temp, 158, temp, 158, temp2);
	gf2x_add(80, g_sum+3352, 80, g_sum+3352, 80, temp+78);
	GF2X_MUL(2, temp, 1, f_sum+2873+78, 1, p_10+1117);
	GF2X_MUL(2, temp2, 1, g_sum+2873+78, 1, p_11+1117);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+3352, 1, g_sum+3352, 1, temp+1);
	right_bit_shift_n(159, g_sum+3352, 44);
	

	delta = divstepsx_256(255, delta, f_sum+3429, g_sum+3429, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3425+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3425+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3425+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3421+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3421+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3421);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3421);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3413+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3413+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3413);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3413);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3393+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3393+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3393+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, p_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, p_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, p_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, p_11+1197+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5073, depth: 4
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_01+1197);
	gf2x_add(80, f_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_01+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+3593, 40, f_sum+3593, 40, temp+40);
	right_bit_shift_n(80, f_sum+3593, 54);
	GF2X_MUL(80, temp, 40, f_sum+3353+40, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+40, 40, p_11+1197);
	gf2x_add(80, g_sum+3593+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+3353+0, 40, p_10+1197);
	GF2X_MUL(80, temp2, 40, g_sum+3353+0, 40, p_11+1197);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+3593, 40, g_sum+3593, 40, temp+40);
	right_bit_shift_n(80, g_sum+3593, 54);
	

	delta = divstepsx_256(255, delta, f_sum+3630, g_sum+3630, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3626+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3626+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3626+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3622+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3622+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3622);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3622);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3614+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3614+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3614);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3614);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 6
	memset(p_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, p_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+4, 8, p_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1237+0, 8, p_00+1237+0, 8, temp);
	memset(p_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, p_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+4, 8, p_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1237+0, 8, p_01+1237+0, 8, temp);
	memset(p_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, p_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+4, 8, p_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1237+0, 8, p_10+1237+0, 8, temp);
	memset(p_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, p_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+4, 8, p_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1237+0, 8, p_11+1237+0, 8, temp);
	

	// Calculating left operands: n: 2523, depth: 5
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_01+1237);
	gf2x_add(40, f_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_01+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+3714, 20, f_sum+3714, 20, temp+20);
	right_bit_shift_n(40, f_sum+3714, 59);
	GF2X_MUL(40, temp, 20, f_sum+3594+20, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+20, 20, p_11+1237);
	gf2x_add(40, g_sum+3714+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+3594+0, 20, p_10+1237);
	GF2X_MUL(40, temp2, 20, g_sum+3594+0, 20, p_11+1237);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+3714, 20, g_sum+3714, 20, temp+20);
	right_bit_shift_n(40, g_sum+3714, 59);
	

	delta = divstepsx_256(255, delta, f_sum+3731, g_sum+3731, p_00+1277, p_01+1277, p_10+1277, p_11+1277);

	// Calculating left operands: n: 510, depth: 8
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_01+1277);
	gf2x_add(8, f_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_01+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3829, 4, f_sum+3829, 4, temp+4);
	right_bit_shift_n(8, f_sum+3829, 63);
	GF2X_MUL(8, temp, 4, f_sum+3727+4, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+4, 4, p_11+1277);
	gf2x_add(8, g_sum+3829+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3727+0, 4, p_10+1277);
	GF2X_MUL(8, temp2, 4, g_sum+3727+0, 4, p_11+1277);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3829, 4, g_sum+3829, 4, temp+4);
	right_bit_shift_n(8, g_sum+3829, 63);
	

	delta = divstepsx_256(255, delta, f_sum+3830, g_sum+3830, q_00+1269, q_01+1269, q_10+1269, q_11+1269);

	// Recombining results: n: 510, depth: 8
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_10+1277);
	gf2x_add(8, p_00+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_01+1269+0, 4, p_11+1277);
	gf2x_add(8, p_01+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_00+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_10+1277);
	gf2x_add(8, p_10+1269+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1269+0, 4, p_01+1277);
	GF2X_MUL(8, temp2, 4, q_11+1269+0, 4, p_11+1277);
	gf2x_add(8, p_11+1269+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 7
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_00+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_01+1269);
	gf2x_add(12, f_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_01+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(12, f_sum+3808, 62);
	GF2X_MUL(16, temp, 8, f_sum+3723+4, 8, p_10+1269);
	GF2X_MUL(16, temp2, 8, g_sum+3723+4, 8, p_11+1269);
	gf2x_add(12, g_sum+3808, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+1269+4, 4, f_sum+3723);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, g_sum+3723);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(12, g_sum+3808, 62);
	

	delta = divstepsx_256(255, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 765, depth: 7
	memset(p_00+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_01+1265);
	gf2x_add(8, p_00+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+1257+0, 8, p_00+1257+0, 8, temp);
	memset(p_01+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_00+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_01+1265);
	gf2x_add(8, p_01+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+1257+0, 8, p_01+1257+0, 8, temp);
	memset(p_10+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_10+1269+4, 4, q_11+1265);
	gf2x_add(8, p_10+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+1257+0, 8, p_10+1257+0, 8, temp);
	memset(p_11+1257, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+1269+4, 4, q_10+1265);
	GF2X_MUL(8, temp2, 4, p_11+1269+4, 4, q_11+1265);
	gf2x_add(8, p_11+1257+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+1257+0, 8, p_11+1257+0, 8, temp);
	

	// Calculating left operands: n: 1248, depth: 6
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_00+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_01+1257);
	gf2x_add(20, f_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_01+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+3775, 8, f_sum+3775, 8, temp+8);
	right_bit_shift_n(20, f_sum+3775, 61);
	GF2X_MUL(24, temp, 12, f_sum+3715+8, 12, p_10+1257);
	GF2X_MUL(24, temp2, 12, g_sum+3715+8, 12, p_11+1257);
	gf2x_add(20, g_sum+3775, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+1257+4, 8, f_sum+3715);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, g_sum+3715);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+3775, 8, g_sum+3775, 8, temp+8);
	right_bit_shift_n(20, g_sum+3775, 61);
	

	delta = divstepsx_256(255, delta, f_sum+3780, g_sum+3780, p_00+1269, p_01+1269, p_10+1269, p_11+1269);

	// Calculating left operands: n: 483, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_01+1269);
	gf2x_add(8, f_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_01+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+3808, 4, f_sum+3808, 4, temp+4);
	right_bit_shift_n(8, f_sum+3808, 63);
	GF2X_MUL(8, temp, 4, f_sum+3776+4, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+4, 4, p_11+1269);
	gf2x_add(8, g_sum+3808+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+3776+0, 4, p_10+1269);
	GF2X_MUL(8, temp2, 4, g_sum+3776+0, 4, p_11+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+3808, 4, g_sum+3808, 4, temp+4);
	right_bit_shift_n(8, g_sum+3808, 63);
	

	delta = divstepsx_256(228, delta, f_sum+3809, g_sum+3809, q_00+1265, q_01+1265, q_10+1265, q_11+1265);

	// Recombining results: n: 483, depth: 7
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_10+1269);
	gf2x_add(8, q_00+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_01+1265+0, 4, p_11+1269);
	gf2x_add(8, q_01+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_00+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_10+1269);
	gf2x_add(8, q_10+1257+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+1265+0, 4, p_01+1269);
	GF2X_MUL(8, temp2, 4, q_11+1265+0, 4, p_11+1269);
	gf2x_add(8, q_11+1257+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1248, depth: 6
	memset(q_00+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_01+1257);
	gf2x_add(16, q_00+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+4, 8, q_00+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+1237+0, 8, q_00+1237+0, 8, temp);
	memset(q_01+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_00+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_01+1257);
	gf2x_add(16, q_01+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+4, 8, q_01+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_01+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+1237+0, 8, q_01+1237+0, 8, temp);
	memset(q_10+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_10+1257+4, 8, q_11+1257);
	gf2x_add(16, q_10+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+4, 8, q_10+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_00+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_10+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+1237+0, 8, q_10+1237+0, 8, temp);
	memset(q_11+1237, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+1257+4, 8, q_10+1257);
	GF2X_MUL(16, temp2, 8, p_11+1257+4, 8, q_11+1257);
	gf2x_add(16, q_11+1237+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+1257+4, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+4, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+4, 8, q_11+1237+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+1257+0, 4, p_01+1257);
	GF2X_MUL(8, temp2, 4, q_11+1257+0, 4, p_11+1257);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+1237+0, 8, q_11+1237+0, 8, temp);
	

	// Recombining results: n: 2523, depth: 5
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_10+1237);
	gf2x_add(40, q_00+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_01+1237+0, 20, p_11+1237);
	gf2x_add(40, q_01+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_00+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_10+1237);
	gf2x_add(40, q_10+1197+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+1237+0, 20, p_01+1237);
	GF2X_MUL(40, temp2, 20, q_11+1237+0, 20, p_11+1237);
	gf2x_add(40, q_11+1197+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5073, depth: 4
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_10+1197);
	gf2x_add(80, q_00+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_01+1197+0, 40, p_11+1197);
	gf2x_add(80, q_01+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_00+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_10+1197);
	gf2x_add(80, q_10+1117+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+1197+0, 40, p_01+1197);
	GF2X_MUL(80, temp2, 40, q_11+1197+0, 40, p_11+1197);
	gf2x_add(80, q_11+1117+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10173, depth: 3
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_10+1117);
	gf2x_add(159, q_00+957, 159, temp+1, 159, temp2+1);
	GF2X_MUL(160, temp, 80, q_00+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_01+1117+0, 80, p_11+1117);
	gf2x_add(159, q_01+957, 159, temp+1, 159, temp2+1);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_00+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_10+1117);
	gf2x_add(159, q_10+957, 159, temp+1, 159, temp2+1);
	GF2X_MUL(160, temp, 80, q_10+1117+0, 80, p_01+1117);
	GF2X_MUL(160, temp2, 80, q_11+1117+0, 80, p_11+1117);
	gf2x_add(159, q_11+957, 159, temp+1, 159, temp2+1);
	

	// Recombining results: n: 20373, depth: 2
	memset(q_00+638, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, q_00+957);
	GF2X_MUL(318, temp2, 159, p_10+957+1, 159, q_01+957);
	gf2x_add(318, q_00+638+1, 318, temp, 318, temp2);
	GF2X_MUL(2, temp, 1, q_00+957+158, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+158, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+158, 2, q_00+638+158, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+157, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+157, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+157, 2, q_00+638+157, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+156, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+156, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+156, 2, q_00+638+156, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+155, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+155, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+155, 2, q_00+638+155, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+154, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+154, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+154, 2, q_00+638+154, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+153, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+153, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+153, 2, q_00+638+153, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+152, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+152, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+152, 2, q_00+638+152, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+151, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+151, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+151, 2, q_00+638+151, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+150, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+150, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+150, 2, q_00+638+150, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+149, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+149, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+149, 2, q_00+638+149, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+148, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+148, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+148, 2, q_00+638+148, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+147, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+147, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+147, 2, q_00+638+147, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+146, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+146, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+146, 2, q_00+638+146, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+145, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+145, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+145, 2, q_00+638+145, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+144, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+144, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+144, 2, q_00+638+144, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+143, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+143, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+143, 2, q_00+638+143, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+142, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+142, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+142, 2, q_00+638+142, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+141, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+141, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+141, 2, q_00+638+141, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+140, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+140, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+140, 2, q_00+638+140, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+139, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+139, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+139, 2, q_00+638+139, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+138, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+138, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+138, 2, q_00+638+138, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+137, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+137, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+137, 2, q_00+638+137, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+136, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+136, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+136, 2, q_00+638+136, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+135, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+135, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+135, 2, q_00+638+135, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+134, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+134, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+134, 2, q_00+638+134, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+133, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+133, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+133, 2, q_00+638+133, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+132, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+132, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+132, 2, q_00+638+132, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+131, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+131, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+131, 2, q_00+638+131, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+130, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+130, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+130, 2, q_00+638+130, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+129, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+129, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+129, 2, q_00+638+129, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+128, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+128, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+128, 2, q_00+638+128, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+127, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+127, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+127, 2, q_00+638+127, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+126, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+126, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+126, 2, q_00+638+126, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+125, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+125, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+125, 2, q_00+638+125, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+124, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+124, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+124, 2, q_00+638+124, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+123, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+123, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+123, 2, q_00+638+123, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+122, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+122, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+122, 2, q_00+638+122, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+121, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+121, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+121, 2, q_00+638+121, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+120, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+120, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+120, 2, q_00+638+120, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+119, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+119, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+119, 2, q_00+638+119, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+118, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+118, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+118, 2, q_00+638+118, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+117, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+117, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+117, 2, q_00+638+117, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+116, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+116, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+116, 2, q_00+638+116, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+115, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+115, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+115, 2, q_00+638+115, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+114, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+114, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+114, 2, q_00+638+114, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+113, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+113, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+113, 2, q_00+638+113, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+112, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+112, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+112, 2, q_00+638+112, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+111, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+111, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+111, 2, q_00+638+111, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+110, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+110, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+110, 2, q_00+638+110, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+109, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+109, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+109, 2, q_00+638+109, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+108, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+108, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+108, 2, q_00+638+108, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+107, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+107, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+107, 2, q_00+638+107, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+106, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+106, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+106, 2, q_00+638+106, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+105, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+105, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+105, 2, q_00+638+105, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+104, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+104, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+104, 2, q_00+638+104, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+103, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+103, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+103, 2, q_00+638+103, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+102, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+102, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+102, 2, q_00+638+102, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+101, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+101, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+101, 2, q_00+638+101, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+100, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+100, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+100, 2, q_00+638+100, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+99, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+99, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+99, 2, q_00+638+99, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+98, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+98, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+98, 2, q_00+638+98, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+97, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+97, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+97, 2, q_00+638+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+96, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+96, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+96, 2, q_00+638+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+95, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+95, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+95, 2, q_00+638+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+94, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+94, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+94, 2, q_00+638+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+93, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+93, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+93, 2, q_00+638+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+92, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+92, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+92, 2, q_00+638+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+91, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+91, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+91, 2, q_00+638+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+90, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+90, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+90, 2, q_00+638+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+89, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+89, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+89, 2, q_00+638+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+88, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+88, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+88, 2, q_00+638+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+87, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+87, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+87, 2, q_00+638+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+86, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+86, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+86, 2, q_00+638+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+85, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+85, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+85, 2, q_00+638+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+84, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+84, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+84, 2, q_00+638+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+83, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+83, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+83, 2, q_00+638+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+82, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+82, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+82, 2, q_00+638+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+81, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+81, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+81, 2, q_00+638+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+80, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+80, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+80, 2, q_00+638+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+79, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+79, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+79, 2, q_00+638+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+78, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+78, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+78, 2, q_00+638+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+77, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+77, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+77, 2, q_00+638+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+76, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+76, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+76, 2, q_00+638+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+75, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+75, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+75, 2, q_00+638+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+74, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+74, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+74, 2, q_00+638+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+73, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+73, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+73, 2, q_00+638+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+72, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+72, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+72, 2, q_00+638+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+71, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+71, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+71, 2, q_00+638+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+70, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+70, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+70, 2, q_00+638+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+69, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+69, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+69, 2, q_00+638+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+68, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+68, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+68, 2, q_00+638+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+67, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+67, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+67, 2, q_00+638+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+66, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+66, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+66, 2, q_00+638+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+65, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+65, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+65, 2, q_00+638+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+64, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+64, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+64, 2, q_00+638+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+63, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+63, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+63, 2, q_00+638+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+62, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+62, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+62, 2, q_00+638+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+61, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+61, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+61, 2, q_00+638+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+60, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+60, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+60, 2, q_00+638+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+59, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+59, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+59, 2, q_00+638+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+58, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+58, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+58, 2, q_00+638+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+57, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+57, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+57, 2, q_00+638+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+56, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+56, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+56, 2, q_00+638+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+55, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+55, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+55, 2, q_00+638+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+54, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+54, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+54, 2, q_00+638+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+53, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+53, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+53, 2, q_00+638+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+52, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+52, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+52, 2, q_00+638+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+51, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+51, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+51, 2, q_00+638+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+50, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+50, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+50, 2, q_00+638+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+49, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+49, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+49, 2, q_00+638+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+48, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+48, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+48, 2, q_00+638+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+47, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+47, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+47, 2, q_00+638+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+46, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+46, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+46, 2, q_00+638+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+45, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+45, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+45, 2, q_00+638+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+44, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+44, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+44, 2, q_00+638+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+43, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+43, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+43, 2, q_00+638+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+42, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+42, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+42, 2, q_00+638+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+41, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+41, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+41, 2, q_00+638+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+40, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+40, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+40, 2, q_00+638+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+39, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+39, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+39, 2, q_00+638+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+38, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+38, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+38, 2, q_00+638+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+37, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+37, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+37, 2, q_00+638+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+36, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+36, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+36, 2, q_00+638+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+35, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+35, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+35, 2, q_00+638+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+34, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+34, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+34, 2, q_00+638+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+33, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+33, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+33, 2, q_00+638+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+32, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+32, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+32, 2, q_00+638+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+31, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+31, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+31, 2, q_00+638+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+30, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+30, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+30, 2, q_00+638+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+29, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+29, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+29, 2, q_00+638+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+28, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+28, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+28, 2, q_00+638+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+27, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+27, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+27, 2, q_00+638+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+26, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+26, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+26, 2, q_00+638+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+25, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+25, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+25, 2, q_00+638+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+24, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+24, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+24, 2, q_00+638+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+23, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+23, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+23, 2, q_00+638+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+22, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+22, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+22, 2, q_00+638+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+21, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+21, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+21, 2, q_00+638+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+20, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+20, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+20, 2, q_00+638+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+19, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+19, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+19, 2, q_00+638+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+18, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+18, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+18, 2, q_00+638+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+17, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+17, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+17, 2, q_00+638+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+16, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+16, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+16, 2, q_00+638+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+15, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+15, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+15, 2, q_00+638+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+14, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+14, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+14, 2, q_00+638+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+13, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+13, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+13, 2, q_00+638+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+12, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+12, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+12, 2, q_00+638+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+11, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+11, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+11, 2, q_00+638+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+10, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+10, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+10, 2, q_00+638+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+9, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+9, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+9, 2, q_00+638+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+8, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+8, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+8, 2, q_00+638+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+7, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+7, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+7, 2, q_00+638+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+6, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+6, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+6, 2, q_00+638+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+5, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+5, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+5, 2, q_00+638+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+4, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+4, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+4, 2, q_00+638+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+3, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+3, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+3, 2, q_00+638+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+2, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+2, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+2, 2, q_00+638+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+1, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+1, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+1, 2, q_00+638+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+0, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_01+957+0, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+638+0, 2, q_00+638+0, 2, temp);
	memset(q_01+638, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(318, temp, 159, p_01+957+1, 159, q_00+957);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, q_01+957);
	gf2x_add(318, q_01+638+1, 318, temp, 318, temp2);
	GF2X_MUL(2, temp, 1, q_00+957+158, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+158, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+158, 2, q_01+638+158, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+157, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+157, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+157, 2, q_01+638+157, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+156, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+156, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+156, 2, q_01+638+156, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+155, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+155, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+155, 2, q_01+638+155, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+154, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+154, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+154, 2, q_01+638+154, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+153, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+153, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+153, 2, q_01+638+153, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+152, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+152, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+152, 2, q_01+638+152, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+151, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+151, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+151, 2, q_01+638+151, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+150, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+150, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+150, 2, q_01+638+150, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+149, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+149, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+149, 2, q_01+638+149, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+148, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+148, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+148, 2, q_01+638+148, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+147, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+147, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+147, 2, q_01+638+147, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+146, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+146, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+146, 2, q_01+638+146, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+145, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+145, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+145, 2, q_01+638+145, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+144, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+144, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+144, 2, q_01+638+144, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+143, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+143, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+143, 2, q_01+638+143, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+142, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+142, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+142, 2, q_01+638+142, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+141, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+141, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+141, 2, q_01+638+141, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+140, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+140, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+140, 2, q_01+638+140, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+139, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+139, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+139, 2, q_01+638+139, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+138, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+138, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+138, 2, q_01+638+138, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+137, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+137, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+137, 2, q_01+638+137, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+136, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+136, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+136, 2, q_01+638+136, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+135, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+135, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+135, 2, q_01+638+135, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+134, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+134, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+134, 2, q_01+638+134, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+133, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+133, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+133, 2, q_01+638+133, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+132, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+132, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+132, 2, q_01+638+132, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+131, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+131, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+131, 2, q_01+638+131, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+130, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+130, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+130, 2, q_01+638+130, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+129, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+129, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+129, 2, q_01+638+129, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+128, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+128, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+128, 2, q_01+638+128, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+127, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+127, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+127, 2, q_01+638+127, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+126, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+126, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+126, 2, q_01+638+126, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+125, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+125, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+125, 2, q_01+638+125, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+124, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+124, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+124, 2, q_01+638+124, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+123, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+123, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+123, 2, q_01+638+123, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+122, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+122, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+122, 2, q_01+638+122, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+121, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+121, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+121, 2, q_01+638+121, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+120, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+120, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+120, 2, q_01+638+120, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+119, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+119, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+119, 2, q_01+638+119, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+118, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+118, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+118, 2, q_01+638+118, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+117, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+117, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+117, 2, q_01+638+117, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+116, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+116, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+116, 2, q_01+638+116, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+115, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+115, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+115, 2, q_01+638+115, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+114, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+114, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+114, 2, q_01+638+114, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+113, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+113, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+113, 2, q_01+638+113, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+112, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+112, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+112, 2, q_01+638+112, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+111, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+111, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+111, 2, q_01+638+111, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+110, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+110, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+110, 2, q_01+638+110, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+109, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+109, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+109, 2, q_01+638+109, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+108, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+108, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+108, 2, q_01+638+108, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+107, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+107, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+107, 2, q_01+638+107, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+106, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+106, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+106, 2, q_01+638+106, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+105, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+105, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+105, 2, q_01+638+105, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+104, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+104, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+104, 2, q_01+638+104, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+103, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+103, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+103, 2, q_01+638+103, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+102, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+102, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+102, 2, q_01+638+102, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+101, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+101, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+101, 2, q_01+638+101, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+100, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+100, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+100, 2, q_01+638+100, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+99, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+99, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+99, 2, q_01+638+99, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+98, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+98, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+98, 2, q_01+638+98, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+97, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+97, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+97, 2, q_01+638+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+96, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+96, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+96, 2, q_01+638+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+95, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+95, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+95, 2, q_01+638+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+94, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+94, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+94, 2, q_01+638+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+93, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+93, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+93, 2, q_01+638+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+92, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+92, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+92, 2, q_01+638+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+91, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+91, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+91, 2, q_01+638+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+90, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+90, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+90, 2, q_01+638+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+89, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+89, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+89, 2, q_01+638+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+88, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+88, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+88, 2, q_01+638+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+87, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+87, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+87, 2, q_01+638+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+86, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+86, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+86, 2, q_01+638+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+85, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+85, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+85, 2, q_01+638+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+84, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+84, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+84, 2, q_01+638+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+83, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+83, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+83, 2, q_01+638+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+82, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+82, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+82, 2, q_01+638+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+81, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+81, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+81, 2, q_01+638+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+80, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+80, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+80, 2, q_01+638+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+79, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+79, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+79, 2, q_01+638+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+78, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+78, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+78, 2, q_01+638+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+77, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+77, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+77, 2, q_01+638+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+76, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+76, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+76, 2, q_01+638+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+75, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+75, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+75, 2, q_01+638+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+74, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+74, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+74, 2, q_01+638+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+73, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+73, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+73, 2, q_01+638+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+72, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+72, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+72, 2, q_01+638+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+71, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+71, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+71, 2, q_01+638+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+70, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+70, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+70, 2, q_01+638+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+69, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+69, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+69, 2, q_01+638+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+68, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+68, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+68, 2, q_01+638+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+67, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+67, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+67, 2, q_01+638+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+66, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+66, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+66, 2, q_01+638+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+65, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+65, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+65, 2, q_01+638+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+64, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+64, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+64, 2, q_01+638+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+63, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+63, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+63, 2, q_01+638+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+62, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+62, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+62, 2, q_01+638+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+61, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+61, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+61, 2, q_01+638+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+60, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+60, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+60, 2, q_01+638+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+59, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+59, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+59, 2, q_01+638+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+58, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+58, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+58, 2, q_01+638+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+57, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+57, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+57, 2, q_01+638+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+56, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+56, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+56, 2, q_01+638+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+55, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+55, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+55, 2, q_01+638+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+54, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+54, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+54, 2, q_01+638+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+53, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+53, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+53, 2, q_01+638+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+52, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+52, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+52, 2, q_01+638+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+51, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+51, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+51, 2, q_01+638+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+50, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+50, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+50, 2, q_01+638+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+49, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+49, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+49, 2, q_01+638+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+48, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+48, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+48, 2, q_01+638+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+47, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+47, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+47, 2, q_01+638+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+46, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+46, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+46, 2, q_01+638+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+45, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+45, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+45, 2, q_01+638+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+44, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+44, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+44, 2, q_01+638+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+43, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+43, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+43, 2, q_01+638+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+42, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+42, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+42, 2, q_01+638+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+41, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+41, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+41, 2, q_01+638+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+40, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+40, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+40, 2, q_01+638+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+39, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+39, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+39, 2, q_01+638+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+38, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+38, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+38, 2, q_01+638+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+37, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+37, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+37, 2, q_01+638+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+36, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+36, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+36, 2, q_01+638+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+35, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+35, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+35, 2, q_01+638+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+34, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+34, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+34, 2, q_01+638+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+33, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+33, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+33, 2, q_01+638+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+32, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+32, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+32, 2, q_01+638+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+31, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+31, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+31, 2, q_01+638+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+30, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+30, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+30, 2, q_01+638+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+29, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+29, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+29, 2, q_01+638+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+28, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+28, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+28, 2, q_01+638+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+27, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+27, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+27, 2, q_01+638+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+26, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+26, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+26, 2, q_01+638+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+25, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+25, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+25, 2, q_01+638+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+24, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+24, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+24, 2, q_01+638+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+23, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+23, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+23, 2, q_01+638+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+22, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+22, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+22, 2, q_01+638+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+21, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+21, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+21, 2, q_01+638+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+20, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+20, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+20, 2, q_01+638+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+19, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+19, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+19, 2, q_01+638+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+18, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+18, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+18, 2, q_01+638+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+17, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+17, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+17, 2, q_01+638+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+16, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+16, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+16, 2, q_01+638+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+15, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+15, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+15, 2, q_01+638+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+14, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+14, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+14, 2, q_01+638+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+13, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+13, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+13, 2, q_01+638+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+12, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+12, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+12, 2, q_01+638+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+11, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+11, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+11, 2, q_01+638+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+10, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+10, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+10, 2, q_01+638+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+9, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+9, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+9, 2, q_01+638+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+8, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+8, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+8, 2, q_01+638+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+7, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+7, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+7, 2, q_01+638+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+6, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+6, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+6, 2, q_01+638+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+5, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+5, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+5, 2, q_01+638+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+4, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+4, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+4, 2, q_01+638+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+3, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+3, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+3, 2, q_01+638+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+2, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+2, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+2, 2, q_01+638+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+1, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+1, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+1, 2, q_01+638+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+957+0, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_01+957+0, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+638+0, 2, q_01+638+0, 2, temp);
	memset(q_10+638, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(318, temp, 159, p_00+957+1, 159, q_10+957);
	GF2X_MUL(318, temp2, 159, p_10+957+1, 159, q_11+957);
	gf2x_add(318, q_10+638+1, 318, temp, 318, temp2);
	GF2X_MUL(2, temp, 1, q_10+957+158, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+158, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+158, 2, q_10+638+158, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+157, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+157, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+157, 2, q_10+638+157, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+156, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+156, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+156, 2, q_10+638+156, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+155, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+155, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+155, 2, q_10+638+155, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+154, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+154, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+154, 2, q_10+638+154, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+153, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+153, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+153, 2, q_10+638+153, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+152, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+152, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+152, 2, q_10+638+152, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+151, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+151, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+151, 2, q_10+638+151, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+150, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+150, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+150, 2, q_10+638+150, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+149, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+149, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+149, 2, q_10+638+149, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+148, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+148, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+148, 2, q_10+638+148, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+147, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+147, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+147, 2, q_10+638+147, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+146, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+146, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+146, 2, q_10+638+146, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+145, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+145, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+145, 2, q_10+638+145, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+144, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+144, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+144, 2, q_10+638+144, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+143, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+143, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+143, 2, q_10+638+143, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+142, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+142, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+142, 2, q_10+638+142, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+141, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+141, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+141, 2, q_10+638+141, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+140, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+140, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+140, 2, q_10+638+140, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+139, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+139, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+139, 2, q_10+638+139, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+138, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+138, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+138, 2, q_10+638+138, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+137, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+137, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+137, 2, q_10+638+137, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+136, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+136, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+136, 2, q_10+638+136, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+135, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+135, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+135, 2, q_10+638+135, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+134, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+134, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+134, 2, q_10+638+134, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+133, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+133, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+133, 2, q_10+638+133, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+132, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+132, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+132, 2, q_10+638+132, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+131, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+131, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+131, 2, q_10+638+131, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+130, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+130, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+130, 2, q_10+638+130, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+129, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+129, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+129, 2, q_10+638+129, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+128, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+128, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+128, 2, q_10+638+128, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+127, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+127, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+127, 2, q_10+638+127, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+126, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+126, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+126, 2, q_10+638+126, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+125, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+125, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+125, 2, q_10+638+125, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+124, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+124, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+124, 2, q_10+638+124, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+123, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+123, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+123, 2, q_10+638+123, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+122, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+122, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+122, 2, q_10+638+122, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+121, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+121, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+121, 2, q_10+638+121, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+120, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+120, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+120, 2, q_10+638+120, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+119, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+119, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+119, 2, q_10+638+119, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+118, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+118, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+118, 2, q_10+638+118, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+117, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+117, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+117, 2, q_10+638+117, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+116, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+116, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+116, 2, q_10+638+116, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+115, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+115, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+115, 2, q_10+638+115, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+114, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+114, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+114, 2, q_10+638+114, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+113, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+113, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+113, 2, q_10+638+113, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+112, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+112, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+112, 2, q_10+638+112, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+111, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+111, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+111, 2, q_10+638+111, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+110, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+110, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+110, 2, q_10+638+110, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+109, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+109, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+109, 2, q_10+638+109, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+108, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+108, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+108, 2, q_10+638+108, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+107, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+107, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+107, 2, q_10+638+107, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+106, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+106, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+106, 2, q_10+638+106, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+105, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+105, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+105, 2, q_10+638+105, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+104, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+104, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+104, 2, q_10+638+104, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+103, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+103, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+103, 2, q_10+638+103, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+102, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+102, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+102, 2, q_10+638+102, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+101, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+101, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+101, 2, q_10+638+101, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+100, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+100, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+100, 2, q_10+638+100, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+99, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+99, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+99, 2, q_10+638+99, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+98, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+98, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+98, 2, q_10+638+98, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+97, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+97, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+97, 2, q_10+638+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+96, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+96, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+96, 2, q_10+638+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+95, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+95, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+95, 2, q_10+638+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+94, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+94, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+94, 2, q_10+638+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+93, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+93, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+93, 2, q_10+638+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+92, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+92, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+92, 2, q_10+638+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+91, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+91, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+91, 2, q_10+638+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+90, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+90, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+90, 2, q_10+638+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+89, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+89, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+89, 2, q_10+638+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+88, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+88, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+88, 2, q_10+638+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+87, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+87, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+87, 2, q_10+638+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+86, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+86, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+86, 2, q_10+638+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+85, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+85, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+85, 2, q_10+638+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+84, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+84, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+84, 2, q_10+638+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+83, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+83, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+83, 2, q_10+638+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+82, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+82, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+82, 2, q_10+638+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+81, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+81, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+81, 2, q_10+638+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+80, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+80, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+80, 2, q_10+638+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+79, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+79, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+79, 2, q_10+638+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+78, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+78, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+78, 2, q_10+638+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+77, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+77, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+77, 2, q_10+638+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+76, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+76, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+76, 2, q_10+638+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+75, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+75, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+75, 2, q_10+638+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+74, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+74, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+74, 2, q_10+638+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+73, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+73, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+73, 2, q_10+638+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+72, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+72, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+72, 2, q_10+638+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+71, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+71, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+71, 2, q_10+638+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+70, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+70, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+70, 2, q_10+638+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+69, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+69, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+69, 2, q_10+638+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+68, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+68, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+68, 2, q_10+638+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+67, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+67, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+67, 2, q_10+638+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+66, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+66, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+66, 2, q_10+638+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+65, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+65, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+65, 2, q_10+638+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+64, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+64, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+64, 2, q_10+638+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+63, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+63, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+63, 2, q_10+638+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+62, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+62, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+62, 2, q_10+638+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+61, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+61, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+61, 2, q_10+638+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+60, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+60, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+60, 2, q_10+638+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+59, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+59, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+59, 2, q_10+638+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+58, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+58, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+58, 2, q_10+638+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+57, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+57, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+57, 2, q_10+638+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+56, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+56, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+56, 2, q_10+638+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+55, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+55, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+55, 2, q_10+638+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+54, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+54, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+54, 2, q_10+638+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+53, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+53, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+53, 2, q_10+638+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+52, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+52, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+52, 2, q_10+638+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+51, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+51, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+51, 2, q_10+638+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+50, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+50, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+50, 2, q_10+638+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+49, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+49, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+49, 2, q_10+638+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+48, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+48, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+48, 2, q_10+638+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+47, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+47, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+47, 2, q_10+638+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+46, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+46, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+46, 2, q_10+638+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+45, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+45, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+45, 2, q_10+638+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+44, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+44, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+44, 2, q_10+638+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+43, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+43, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+43, 2, q_10+638+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+42, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+42, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+42, 2, q_10+638+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+41, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+41, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+41, 2, q_10+638+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+40, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+40, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+40, 2, q_10+638+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+39, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+39, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+39, 2, q_10+638+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+38, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+38, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+38, 2, q_10+638+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+37, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+37, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+37, 2, q_10+638+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+36, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+36, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+36, 2, q_10+638+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+35, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+35, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+35, 2, q_10+638+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+34, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+34, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+34, 2, q_10+638+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+33, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+33, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+33, 2, q_10+638+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+32, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+32, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+32, 2, q_10+638+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+31, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+31, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+31, 2, q_10+638+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+30, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+30, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+30, 2, q_10+638+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+29, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+29, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+29, 2, q_10+638+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+28, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+28, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+28, 2, q_10+638+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+27, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+27, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+27, 2, q_10+638+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+26, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+26, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+26, 2, q_10+638+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+25, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+25, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+25, 2, q_10+638+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+24, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+24, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+24, 2, q_10+638+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+23, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+23, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+23, 2, q_10+638+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+22, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+22, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+22, 2, q_10+638+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+21, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+21, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+21, 2, q_10+638+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+20, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+20, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+20, 2, q_10+638+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+19, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+19, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+19, 2, q_10+638+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+18, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+18, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+18, 2, q_10+638+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+17, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+17, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+17, 2, q_10+638+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+16, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+16, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+16, 2, q_10+638+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+15, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+15, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+15, 2, q_10+638+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+14, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+14, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+14, 2, q_10+638+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+13, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+13, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+13, 2, q_10+638+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+12, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+12, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+12, 2, q_10+638+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+11, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+11, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+11, 2, q_10+638+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+10, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+10, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+10, 2, q_10+638+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+9, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+9, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+9, 2, q_10+638+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+8, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+8, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+8, 2, q_10+638+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+7, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+7, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+7, 2, q_10+638+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+6, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+6, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+6, 2, q_10+638+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+5, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+5, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+5, 2, q_10+638+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+4, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+4, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+4, 2, q_10+638+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+3, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+3, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+3, 2, q_10+638+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+2, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+2, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+2, 2, q_10+638+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+1, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+1, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+1, 2, q_10+638+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+0, 1, p_00+957);
	GF2X_MUL(2, temp2, 1, q_11+957+0, 1, p_10+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+638+0, 2, q_10+638+0, 2, temp);
	memset(q_11+638, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(318, temp, 159, p_01+957+1, 159, q_10+957);
	GF2X_MUL(318, temp2, 159, p_11+957+1, 159, q_11+957);
	gf2x_add(318, q_11+638+1, 318, temp, 318, temp2);
	GF2X_MUL(2, temp, 1, q_10+957+158, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+158, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+158, 2, q_11+638+158, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+157, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+157, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+157, 2, q_11+638+157, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+156, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+156, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+156, 2, q_11+638+156, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+155, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+155, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+155, 2, q_11+638+155, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+154, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+154, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+154, 2, q_11+638+154, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+153, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+153, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+153, 2, q_11+638+153, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+152, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+152, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+152, 2, q_11+638+152, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+151, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+151, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+151, 2, q_11+638+151, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+150, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+150, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+150, 2, q_11+638+150, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+149, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+149, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+149, 2, q_11+638+149, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+148, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+148, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+148, 2, q_11+638+148, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+147, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+147, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+147, 2, q_11+638+147, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+146, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+146, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+146, 2, q_11+638+146, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+145, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+145, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+145, 2, q_11+638+145, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+144, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+144, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+144, 2, q_11+638+144, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+143, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+143, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+143, 2, q_11+638+143, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+142, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+142, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+142, 2, q_11+638+142, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+141, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+141, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+141, 2, q_11+638+141, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+140, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+140, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+140, 2, q_11+638+140, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+139, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+139, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+139, 2, q_11+638+139, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+138, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+138, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+138, 2, q_11+638+138, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+137, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+137, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+137, 2, q_11+638+137, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+136, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+136, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+136, 2, q_11+638+136, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+135, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+135, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+135, 2, q_11+638+135, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+134, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+134, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+134, 2, q_11+638+134, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+133, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+133, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+133, 2, q_11+638+133, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+132, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+132, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+132, 2, q_11+638+132, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+131, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+131, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+131, 2, q_11+638+131, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+130, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+130, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+130, 2, q_11+638+130, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+129, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+129, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+129, 2, q_11+638+129, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+128, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+128, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+128, 2, q_11+638+128, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+127, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+127, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+127, 2, q_11+638+127, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+126, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+126, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+126, 2, q_11+638+126, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+125, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+125, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+125, 2, q_11+638+125, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+124, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+124, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+124, 2, q_11+638+124, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+123, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+123, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+123, 2, q_11+638+123, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+122, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+122, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+122, 2, q_11+638+122, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+121, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+121, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+121, 2, q_11+638+121, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+120, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+120, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+120, 2, q_11+638+120, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+119, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+119, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+119, 2, q_11+638+119, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+118, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+118, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+118, 2, q_11+638+118, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+117, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+117, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+117, 2, q_11+638+117, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+116, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+116, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+116, 2, q_11+638+116, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+115, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+115, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+115, 2, q_11+638+115, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+114, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+114, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+114, 2, q_11+638+114, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+113, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+113, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+113, 2, q_11+638+113, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+112, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+112, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+112, 2, q_11+638+112, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+111, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+111, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+111, 2, q_11+638+111, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+110, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+110, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+110, 2, q_11+638+110, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+109, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+109, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+109, 2, q_11+638+109, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+108, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+108, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+108, 2, q_11+638+108, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+107, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+107, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+107, 2, q_11+638+107, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+106, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+106, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+106, 2, q_11+638+106, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+105, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+105, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+105, 2, q_11+638+105, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+104, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+104, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+104, 2, q_11+638+104, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+103, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+103, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+103, 2, q_11+638+103, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+102, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+102, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+102, 2, q_11+638+102, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+101, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+101, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+101, 2, q_11+638+101, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+100, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+100, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+100, 2, q_11+638+100, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+99, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+99, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+99, 2, q_11+638+99, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+98, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+98, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+98, 2, q_11+638+98, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+97, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+97, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+97, 2, q_11+638+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+96, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+96, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+96, 2, q_11+638+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+95, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+95, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+95, 2, q_11+638+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+94, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+94, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+94, 2, q_11+638+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+93, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+93, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+93, 2, q_11+638+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+92, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+92, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+92, 2, q_11+638+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+91, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+91, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+91, 2, q_11+638+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+90, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+90, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+90, 2, q_11+638+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+89, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+89, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+89, 2, q_11+638+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+88, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+88, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+88, 2, q_11+638+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+87, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+87, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+87, 2, q_11+638+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+86, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+86, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+86, 2, q_11+638+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+85, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+85, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+85, 2, q_11+638+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+84, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+84, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+84, 2, q_11+638+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+83, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+83, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+83, 2, q_11+638+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+82, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+82, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+82, 2, q_11+638+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+81, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+81, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+81, 2, q_11+638+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+80, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+80, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+80, 2, q_11+638+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+79, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+79, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+79, 2, q_11+638+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+78, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+78, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+78, 2, q_11+638+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+77, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+77, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+77, 2, q_11+638+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+76, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+76, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+76, 2, q_11+638+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+75, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+75, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+75, 2, q_11+638+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+74, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+74, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+74, 2, q_11+638+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+73, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+73, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+73, 2, q_11+638+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+72, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+72, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+72, 2, q_11+638+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+71, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+71, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+71, 2, q_11+638+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+70, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+70, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+70, 2, q_11+638+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+69, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+69, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+69, 2, q_11+638+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+68, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+68, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+68, 2, q_11+638+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+67, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+67, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+67, 2, q_11+638+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+66, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+66, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+66, 2, q_11+638+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+65, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+65, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+65, 2, q_11+638+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+64, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+64, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+64, 2, q_11+638+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+63, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+63, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+63, 2, q_11+638+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+62, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+62, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+62, 2, q_11+638+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+61, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+61, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+61, 2, q_11+638+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+60, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+60, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+60, 2, q_11+638+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+59, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+59, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+59, 2, q_11+638+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+58, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+58, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+58, 2, q_11+638+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+57, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+57, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+57, 2, q_11+638+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+56, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+56, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+56, 2, q_11+638+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+55, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+55, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+55, 2, q_11+638+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+54, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+54, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+54, 2, q_11+638+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+53, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+53, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+53, 2, q_11+638+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+52, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+52, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+52, 2, q_11+638+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+51, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+51, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+51, 2, q_11+638+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+50, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+50, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+50, 2, q_11+638+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+49, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+49, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+49, 2, q_11+638+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+48, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+48, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+48, 2, q_11+638+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+47, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+47, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+47, 2, q_11+638+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+46, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+46, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+46, 2, q_11+638+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+45, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+45, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+45, 2, q_11+638+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+44, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+44, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+44, 2, q_11+638+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+43, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+43, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+43, 2, q_11+638+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+42, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+42, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+42, 2, q_11+638+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+41, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+41, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+41, 2, q_11+638+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+40, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+40, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+40, 2, q_11+638+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+39, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+39, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+39, 2, q_11+638+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+38, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+38, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+38, 2, q_11+638+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+37, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+37, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+37, 2, q_11+638+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+36, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+36, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+36, 2, q_11+638+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+35, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+35, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+35, 2, q_11+638+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+34, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+34, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+34, 2, q_11+638+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+33, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+33, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+33, 2, q_11+638+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+32, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+32, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+32, 2, q_11+638+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+31, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+31, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+31, 2, q_11+638+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+30, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+30, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+30, 2, q_11+638+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+29, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+29, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+29, 2, q_11+638+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+28, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+28, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+28, 2, q_11+638+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+27, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+27, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+27, 2, q_11+638+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+26, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+26, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+26, 2, q_11+638+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+25, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+25, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+25, 2, q_11+638+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+24, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+24, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+24, 2, q_11+638+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+23, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+23, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+23, 2, q_11+638+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+22, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+22, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+22, 2, q_11+638+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+21, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+21, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+21, 2, q_11+638+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+20, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+20, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+20, 2, q_11+638+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+19, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+19, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+19, 2, q_11+638+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+18, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+18, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+18, 2, q_11+638+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+17, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+17, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+17, 2, q_11+638+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+16, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+16, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+16, 2, q_11+638+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+15, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+15, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+15, 2, q_11+638+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+14, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+14, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+14, 2, q_11+638+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+13, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+13, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+13, 2, q_11+638+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+12, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+12, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+12, 2, q_11+638+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+11, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+11, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+11, 2, q_11+638+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+10, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+10, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+10, 2, q_11+638+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+9, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+9, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+9, 2, q_11+638+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+8, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+8, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+8, 2, q_11+638+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+7, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+7, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+7, 2, q_11+638+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+6, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+6, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+6, 2, q_11+638+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+5, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+5, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+5, 2, q_11+638+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+4, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+4, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+4, 2, q_11+638+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+3, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+3, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+3, 2, q_11+638+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+2, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+2, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+2, 2, q_11+638+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+1, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+1, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+1, 2, q_11+638+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+957+0, 1, p_01+957);
	GF2X_MUL(2, temp2, 1, q_11+957+0, 1, p_11+957);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+638+0, 2, q_11+638+0, 2, temp);
	

	// Recombining results: n: 40773, depth: 1
	GF2X_MUL(638, temp, 319, q_00+638+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, q_01+638+0, 319, p_10+638);
	gf2x_add(638, q_00+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_00+638+0, 319, p_01+638);
	GF2X_MUL(638, temp2, 319, q_01+638+0, 319, p_11+638);
	gf2x_add(638, q_01+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_10+638+0, 319, p_00+638);
	GF2X_MUL(638, temp2, 319, q_11+638+0, 319, p_10+638);
	gf2x_add(638, q_10+0+0, 638, temp, 638, temp2);
	GF2X_MUL(638, temp, 319, q_10+638+0, 319, p_01+638);
	GF2X_MUL(638, temp2, 319, q_11+638+0, 319, p_11+638);
	gf2x_add(638, q_11+0+0, 638, temp, 638, temp2);
	

	// Recombining results: n: 81573, depth: 0
	GF2X_MUL(1276, temp, 638, q_00+0+0, 638, p_00+0);
	GF2X_MUL(1276, temp2, 638, q_01+0+0, 638, p_10+0);
	gf2x_add(1275, t_00+0, 1275, temp+1, 1275, temp2+1);
	GF2X_MUL(1276, temp, 638, q_00+0+0, 638, p_01+0);
	GF2X_MUL(1276, temp2, 638, q_01+0+0, 638, p_11+0);
	gf2x_add(1275, t_01+0, 1275, temp+1, 1275, temp2+1);
	GF2X_MUL(1276, temp, 638, q_10+0+0, 638, p_00+0);
	GF2X_MUL(1276, temp2, 638, q_11+0+0, 638, p_10+0);
	gf2x_add(1275, t_10+0, 1275, temp+1, 1275, temp2+1);
	GF2X_MUL(1276, temp, 638, q_10+0+0, 638, p_01+0);
	GF2X_MUL(1276, temp2, 638, q_11+0+0, 638, p_11+0);
	gf2x_add(1275, t_11+0, 1275, temp+1, 1275, temp2+1);
	

	return delta;
}