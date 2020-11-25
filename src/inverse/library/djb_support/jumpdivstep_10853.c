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

int jumpdivstep_10853(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[352];
	DIGIT p_01[352];
	DIGIT p_10[352];
	DIGIT p_11[352];
	
	DIGIT q_00[336];
	DIGIT q_01[336];
	DIGIT q_10[336];
	DIGIT q_11[336];
	
	DIGIT f_sum[1048];
	DIGIT g_sum[1048];
	
	DIGIT temp[684];
	DIGIT temp2[684];
	

	delta = divstepsx_256(255, delta, f+336, g+336, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+332+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g+332+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g+332+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f+332+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g+332+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+332+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g+332+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+328+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g+328+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f+328);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f+328+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g+328+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+316+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g+316+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g+316+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f+316+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g+316+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+316+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g+316+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f+296+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g+296+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f+296);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g+296);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f+296+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g+296+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g+296);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(p_00+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, p_00+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+16, 8, p_00+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+12, 8, p_00+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+8, 8, p_00+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+4, 8, p_00+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+0, 8, p_00+260+0, 8, temp);
	memset(p_01+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, p_01+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+16, 8, p_01+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+12, 8, p_01+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+8, 8, p_01+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+4, 8, p_01+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+0, 8, p_01+260+0, 8, temp);
	memset(p_10+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, p_10+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+16, 8, p_10+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+12, 8, p_10+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+8, 8, p_10+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+4, 8, p_10+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+0, 8, p_10+260+0, 8, temp);
	memset(p_11+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, p_11+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+16, 8, p_11+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+12, 8, p_11+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+8, 8, p_11+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+4, 8, p_11+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+0, 8, p_11+260+0, 8, temp);
	

	// Calculating left operands: n: 5610, depth: 2
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f+252+44, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g+252+44, 44, p_01+260);
	gf2x_add(88, f_sum+774+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f+252+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g+252+0, 44, p_01+260);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+774, 44, f_sum+774, 44, temp+44);
	right_bit_shift_n(88, f_sum+774, 53);
	GF2X_MUL(88, temp, 44, f+252+44, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g+252+44, 44, p_11+260);
	gf2x_add(88, g_sum+774+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f+252+0, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g+252+0, 44, p_11+260);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+774, 44, g_sum+774, 44, temp+44);
	right_bit_shift_n(88, g_sum+774, 53);
	

	delta = divstepsx_256(255, delta, f_sum+815, g_sum+815, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+811+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+811+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+811+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+811+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+807+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+807+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+807);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+807+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+807+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+807);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+795+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+795+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+795+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+795+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+775+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g_sum+775+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f_sum+775);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g_sum+775);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f_sum+775+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g_sum+775+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f_sum+775);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g_sum+775);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(q_00+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, q_00+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+16, 8, q_00+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+12, 8, q_00+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+8, 8, q_00+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+4, 8, q_00+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+0, 8, q_00+252+0, 8, temp);
	memset(q_01+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, q_01+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+16, 8, q_01+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+12, 8, q_01+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+8, 8, q_01+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+4, 8, q_01+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+0, 8, q_01+252+0, 8, temp);
	memset(q_10+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, q_10+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+16, 8, q_10+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+12, 8, q_10+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+8, 8, q_10+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+4, 8, q_10+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+0, 8, q_10+252+0, 8, temp);
	memset(q_11+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, q_11+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+16, 8, q_11+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+12, 8, q_11+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+8, 8, q_11+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+4, 8, q_11+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+0, 8, q_11+252+0, 8, temp);
	

	// Recombining results: n: 5610, depth: 2
	GF2X_MUL(88, temp, 44, q_00+252+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, q_01+252+0, 44, p_10+260);
	gf2x_add(88, p_00+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_00+252+0, 44, p_01+260);
	GF2X_MUL(88, temp2, 44, q_01+252+0, 44, p_11+260);
	gf2x_add(88, p_01+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+252+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, q_11+252+0, 44, p_10+260);
	gf2x_add(88, p_10+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+252+0, 44, p_01+260);
	GF2X_MUL(88, temp2, 44, q_11+252+0, 44, p_11+260);
	gf2x_add(88, p_11+172+0, 88, temp, 88, temp2);
	

	// Calculating left operands: n: 10965, depth: 1
	// Digits to shift: 87
	// Displacement: 88
	GF2X_MUL(176, temp, 88, f+168+84, 88, p_00+172);
	GF2X_MUL(176, temp2, 88, g+168+84, 88, p_01+172);
	gf2x_add(172, f_sum+513, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_00+172+4, 84, f+168);
	GF2X_MUL(168, temp2, 84, p_01+172+4, 84, g+168);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, f_sum+513, 84, f_sum+513, 84, temp+84);
	right_bit_shift_n(172, f_sum+513, 42);
	GF2X_MUL(176, temp, 88, f+168+84, 88, p_10+172);
	GF2X_MUL(176, temp2, 88, g+168+84, 88, p_11+172);
	gf2x_add(172, g_sum+513, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_10+172+4, 84, f+168);
	GF2X_MUL(168, temp2, 84, p_11+172+4, 84, g+168);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, g_sum+513, 84, g_sum+513, 84, temp+84);
	right_bit_shift_n(172, g_sum+513, 42);
	

	delta = divstepsx_256(255, delta, f_sum+594, g_sum+594, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+590+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+590+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+590+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+590+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+590+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+590+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+590+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+590+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+586+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+586+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+586);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+586);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+586+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+586+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+586);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+586);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+574+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+574+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+574+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+574+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+574+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+574+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+574+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+574+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+554+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g_sum+554+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f_sum+554);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g_sum+554);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f_sum+554+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g_sum+554+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f_sum+554);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g_sum+554);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(p_00+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, p_00+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+16, 8, p_00+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+12, 8, p_00+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+8, 8, p_00+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+4, 8, p_00+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+0, 8, p_00+260+0, 8, temp);
	memset(p_01+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, p_01+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+16, 8, p_01+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+12, 8, p_01+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+8, 8, p_01+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+4, 8, p_01+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+0, 8, p_01+260+0, 8, temp);
	memset(p_10+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, p_10+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+16, 8, p_10+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+12, 8, p_10+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+8, 8, p_10+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+4, 8, p_10+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+0, 8, p_10+260+0, 8, temp);
	memset(p_11+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, p_11+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+16, 8, p_11+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+12, 8, p_11+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+8, 8, p_11+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+4, 8, p_11+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+0, 8, p_11+260+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 2
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+514+40, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g_sum+514+40, 44, p_01+260);
	gf2x_add(84, f_sum+774, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+260+4, 40, f_sum+514);
	GF2X_MUL(80, temp2, 40, p_01+260+4, 40, g_sum+514);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+774, 40, f_sum+774, 40, temp+40);
	right_bit_shift_n(84, f_sum+774, 53);
	GF2X_MUL(88, temp, 44, f_sum+514+40, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g_sum+514+40, 44, p_11+260);
	gf2x_add(84, g_sum+774, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+260+4, 40, f_sum+514);
	GF2X_MUL(80, temp2, 40, p_11+260+4, 40, g_sum+514);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+774, 40, g_sum+774, 40, temp+40);
	right_bit_shift_n(84, g_sum+774, 53);
	

	delta = divstepsx_256(255, delta, f_sum+811, g_sum+811, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+807+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+807+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+807+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+807+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+807+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+807+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+807+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+807+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+803+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+803+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+803);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+803);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+803+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+803+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+803);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+803);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+795+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+795);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+795);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+795+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+795);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+795);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(p_00+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, p_00+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+304+4, 8, p_00+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+304+0, 8, p_00+304+0, 8, temp);
	memset(p_01+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, p_01+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+304+4, 8, p_01+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+304+0, 8, p_01+304+0, 8, temp);
	memset(p_10+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, p_10+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+304+4, 8, p_10+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+304+0, 8, p_10+304+0, 8, temp);
	memset(p_11+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, p_11+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+304+4, 8, p_11+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+304+0, 8, p_11+304+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 3
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+775+20, 20, p_00+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+20, 20, p_01+304);
	gf2x_add(40, f_sum+907+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+775+0, 20, p_00+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+0, 20, p_01+304);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(40, f_sum+907, 59);
	GF2X_MUL(40, temp, 20, f_sum+775+20, 20, p_10+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+20, 20, p_11+304);
	gf2x_add(40, g_sum+907+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+775+0, 20, p_10+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+0, 20, p_11+304);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(40, g_sum+907, 59);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 3
	GF2X_MUL(40, temp, 20, q_00+296+0, 20, p_00+304);
	GF2X_MUL(40, temp2, 20, q_01+296+0, 20, p_10+304);
	gf2x_add(40, q_00+252+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+296+0, 20, p_01+304);
	GF2X_MUL(40, temp2, 20, q_01+296+0, 20, p_11+304);
	gf2x_add(40, q_01+252+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+296+0, 20, p_00+304);
	GF2X_MUL(40, temp2, 20, q_11+296+0, 20, p_10+304);
	gf2x_add(40, q_10+252+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+296+0, 20, p_01+304);
	GF2X_MUL(40, temp2, 20, q_11+296+0, 20, p_11+304);
	gf2x_add(40, q_11+252+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 2
	memset(q_00+168, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+260+4, 40, q_00+252);
	GF2X_MUL(80, temp2, 40, p_10+260+4, 40, q_01+252);
	gf2x_add(80, q_00+168+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+252+36, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+36, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+36, 8, q_00+168+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+32, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+32, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+32, 8, q_00+168+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+28, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+28, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+28, 8, q_00+168+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+24, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+24, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+24, 8, q_00+168+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+20, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+20, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+20, 8, q_00+168+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+16, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+16, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+16, 8, q_00+168+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+12, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+12, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+12, 8, q_00+168+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+8, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+8, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+8, 8, q_00+168+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+4, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+4, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+4, 8, q_00+168+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+0, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_01+252+0, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+168+0, 8, q_00+168+0, 8, temp);
	memset(q_01+168, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+260+4, 40, q_00+252);
	GF2X_MUL(80, temp2, 40, p_11+260+4, 40, q_01+252);
	gf2x_add(80, q_01+168+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+252+36, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+36, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+36, 8, q_01+168+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+32, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+32, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+32, 8, q_01+168+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+28, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+28, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+28, 8, q_01+168+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+24, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+24, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+24, 8, q_01+168+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+20, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+20, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+20, 8, q_01+168+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+16, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+16, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+16, 8, q_01+168+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+12, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+12, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+12, 8, q_01+168+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+8, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+8, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+8, 8, q_01+168+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+4, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+4, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+4, 8, q_01+168+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+252+0, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_01+252+0, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+168+0, 8, q_01+168+0, 8, temp);
	memset(q_10+168, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+260+4, 40, q_10+252);
	GF2X_MUL(80, temp2, 40, p_10+260+4, 40, q_11+252);
	gf2x_add(80, q_10+168+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+252+36, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+36, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+36, 8, q_10+168+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+32, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+32, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+32, 8, q_10+168+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+28, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+28, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+28, 8, q_10+168+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+24, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+24, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+24, 8, q_10+168+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+20, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+20, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+20, 8, q_10+168+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+16, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+16, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+16, 8, q_10+168+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+12, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+12, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+12, 8, q_10+168+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+8, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+8, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+8, 8, q_10+168+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+4, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+4, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+4, 8, q_10+168+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+0, 4, p_00+260);
	GF2X_MUL(8, temp2, 4, q_11+252+0, 4, p_10+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+168+0, 8, q_10+168+0, 8, temp);
	memset(q_11+168, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+260+4, 40, q_10+252);
	GF2X_MUL(80, temp2, 40, p_11+260+4, 40, q_11+252);
	gf2x_add(80, q_11+168+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+252+36, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+36, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+36, 8, q_11+168+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+32, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+32, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+32, 8, q_11+168+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+28, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+28, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+28, 8, q_11+168+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+24, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+24, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+24, 8, q_11+168+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+20, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+20, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+20, 8, q_11+168+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+16, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+16, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+16, 8, q_11+168+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+12, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+12, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+12, 8, q_11+168+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+8, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+8, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+8, 8, q_11+168+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+4, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+4, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+4, 8, q_11+168+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+252+0, 4, p_01+260);
	GF2X_MUL(8, temp2, 4, q_11+252+0, 4, p_11+260);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+168+0, 8, q_11+168+0, 8, temp);
	

	// Recombining results: n: 10965, depth: 1
	memset(p_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+172+4, 84, q_00+168);
	GF2X_MUL(168, temp2, 84, p_10+172+4, 84, q_01+168);
	gf2x_add(168, p_00+0+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+168+80, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+80, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+80, 8, p_00+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+76, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+76, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+76, 8, p_00+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+72, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+72, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+72, 8, p_00+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+68, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+68, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+68, 8, p_00+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+64, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+64, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+64, 8, p_00+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+60, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+60, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+60, 8, p_00+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+56, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+56, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+56, 8, p_00+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+52, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+52, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+52, 8, p_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+48, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+48, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+48, 8, p_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+44, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+44, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+44, 8, p_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+40, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+40, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+40, 8, p_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+36, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+36, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+36, 8, p_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+32, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+32, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+32, 8, p_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+28, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+28, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+28, 8, p_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+24, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+24, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+24, 8, p_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+20, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+20, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+20, 8, p_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+16, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+16, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+16, 8, p_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+12, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+12, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+12, 8, p_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+8, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+8, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+8, 8, p_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+4, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+4, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+4, 8, p_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+0, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_01+168+0, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+0, 8, p_00+0+0, 8, temp);
	memset(p_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+172+4, 84, q_00+168);
	GF2X_MUL(168, temp2, 84, p_11+172+4, 84, q_01+168);
	gf2x_add(168, p_01+0+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+168+80, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+80, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+80, 8, p_01+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+76, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+76, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+76, 8, p_01+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+72, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+72, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+72, 8, p_01+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+68, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+68, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+68, 8, p_01+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+64, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+64, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+64, 8, p_01+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+60, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+60, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+60, 8, p_01+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+56, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+56, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+56, 8, p_01+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+52, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+52, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+52, 8, p_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+48, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+48, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+48, 8, p_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+44, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+44, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+44, 8, p_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+40, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+40, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+40, 8, p_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+36, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+36, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+36, 8, p_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+32, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+32, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+32, 8, p_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+28, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+28, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+28, 8, p_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+24, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+24, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+24, 8, p_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+20, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+20, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+20, 8, p_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+16, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+16, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+16, 8, p_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+12, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+12, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+12, 8, p_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+8, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+8, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+8, 8, p_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+4, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+4, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+4, 8, p_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+168+0, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_01+168+0, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+0, 8, p_01+0+0, 8, temp);
	memset(p_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+172+4, 84, q_10+168);
	GF2X_MUL(168, temp2, 84, p_10+172+4, 84, q_11+168);
	gf2x_add(168, p_10+0+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+168+80, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+80, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+80, 8, p_10+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+76, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+76, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+76, 8, p_10+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+72, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+72, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+72, 8, p_10+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+68, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+68, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+68, 8, p_10+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+64, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+64, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+64, 8, p_10+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+60, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+60, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+60, 8, p_10+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+56, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+56, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+56, 8, p_10+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+52, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+52, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+52, 8, p_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+48, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+48, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+48, 8, p_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+44, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+44, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+44, 8, p_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+40, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+40, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+40, 8, p_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+36, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+36, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+36, 8, p_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+32, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+32, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+32, 8, p_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+28, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+28, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+28, 8, p_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+24, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+24, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+24, 8, p_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+20, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+20, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+20, 8, p_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+16, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+16, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+16, 8, p_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+12, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+12, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+12, 8, p_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+8, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+8, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+8, 8, p_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+4, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+4, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+4, 8, p_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+0, 4, p_00+172);
	GF2X_MUL(8, temp2, 4, q_11+168+0, 4, p_10+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+0, 8, p_10+0+0, 8, temp);
	memset(p_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+172+4, 84, q_10+168);
	GF2X_MUL(168, temp2, 84, p_11+172+4, 84, q_11+168);
	gf2x_add(168, p_11+0+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+168+80, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+80, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+80, 8, p_11+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+76, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+76, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+76, 8, p_11+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+72, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+72, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+72, 8, p_11+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+68, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+68, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+68, 8, p_11+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+64, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+64, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+64, 8, p_11+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+60, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+60, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+60, 8, p_11+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+56, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+56, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+56, 8, p_11+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+52, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+52, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+52, 8, p_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+48, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+48, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+48, 8, p_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+44, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+44, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+44, 8, p_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+40, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+40, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+40, 8, p_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+36, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+36, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+36, 8, p_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+32, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+32, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+32, 8, p_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+28, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+28, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+28, 8, p_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+24, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+24, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+24, 8, p_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+20, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+20, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+20, 8, p_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+16, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+16, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+16, 8, p_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+12, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+12, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+12, 8, p_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+8, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+8, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+8, 8, p_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+4, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+4, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+4, 8, p_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+168+0, 4, p_01+172);
	GF2X_MUL(8, temp2, 4, q_11+168+0, 4, p_11+172);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+0, 8, p_11+0+0, 8, temp);
	

	// Calculating left operands: n: 21705, depth: 0
	// Digits to shift: 171
	// Displacement: 172
	GF2X_MUL(344, temp, 172, f+0+168, 172, p_00+0);
	GF2X_MUL(344, temp2, 172, g+0+168, 172, p_01+0);
	gf2x_add(340, f_sum+0, 340, temp+4, 340, temp2+4);
	GF2X_MUL(336, temp, 168, p_00+0+4, 168, f+0);
	GF2X_MUL(336, temp2, 168, p_01+0+4, 168, g+0);
	gf2x_add(336, temp, 336, temp, 336, temp2);
	gf2x_add(168, f_sum+0, 168, f_sum+0, 168, temp+168);
	right_bit_shift_n(340, f_sum+0, 21);
	GF2X_MUL(344, temp, 172, f+0+168, 172, p_10+0);
	GF2X_MUL(344, temp2, 172, g+0+168, 172, p_11+0);
	gf2x_add(340, g_sum+0, 340, temp+4, 340, temp2+4);
	GF2X_MUL(336, temp, 168, p_10+0+4, 168, f+0);
	GF2X_MUL(336, temp2, 168, p_11+0+4, 168, g+0);
	gf2x_add(336, temp, 336, temp, 336, temp2);
	gf2x_add(168, g_sum+0, 168, g_sum+0, 168, temp+168);
	right_bit_shift_n(340, g_sum+0, 21);
	

	delta = divstepsx_256(255, delta, f_sum+165, g_sum+165, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+161+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+161+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+161+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+161+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+161+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+161+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+161+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+161+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+157+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+157+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+157);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+157);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+157+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+157+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+157);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+157);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+145+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+145+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+145+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+145+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+145+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+145+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+145+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+145+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+125+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g_sum+125+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f_sum+125);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g_sum+125);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f_sum+125+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g_sum+125+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f_sum+125);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g_sum+125);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(p_00+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, p_00+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+16, 8, p_00+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+12, 8, p_00+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+8, 8, p_00+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+4, 8, p_00+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+0, 8, p_00+260+0, 8, temp);
	memset(p_01+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, p_01+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+16, 8, p_01+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+12, 8, p_01+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+8, 8, p_01+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+4, 8, p_01+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+0, 8, p_01+260+0, 8, temp);
	memset(p_10+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, p_10+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+16, 8, p_10+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+12, 8, p_10+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+8, 8, p_10+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+4, 8, p_10+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+0, 8, p_10+260+0, 8, temp);
	memset(p_11+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, p_11+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+16, 8, p_11+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+12, 8, p_11+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+8, 8, p_11+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+4, 8, p_11+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+0, 8, p_11+260+0, 8, temp);
	

	// Calculating left operands: n: 5610, depth: 2
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+81+44, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g_sum+81+44, 44, p_01+260);
	gf2x_add(88, f_sum+774+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f_sum+81+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g_sum+81+0, 44, p_01+260);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+774, 44, f_sum+774, 44, temp+44);
	right_bit_shift_n(88, f_sum+774, 53);
	GF2X_MUL(88, temp, 44, f_sum+81+44, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g_sum+81+44, 44, p_11+260);
	gf2x_add(88, g_sum+774+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f_sum+81+0, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g_sum+81+0, 44, p_11+260);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+774, 44, g_sum+774, 44, temp+44);
	right_bit_shift_n(88, g_sum+774, 53);
	

	delta = divstepsx_256(255, delta, f_sum+815, g_sum+815, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+811+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+811+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+811+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+811+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+811+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+807+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+807+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+807);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+807+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+807+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+807);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+795+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+795+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+795+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+795+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+795+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+775+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g_sum+775+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f_sum+775);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g_sum+775);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f_sum+775+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g_sum+775+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f_sum+775);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g_sum+775);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(q_00+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, q_00+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+16, 8, q_00+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+12, 8, q_00+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+8, 8, q_00+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+4, 8, q_00+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+252+0, 8, q_00+252+0, 8, temp);
	memset(q_01+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, q_01+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+16, 8, q_01+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+12, 8, q_01+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+8, 8, q_01+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+4, 8, q_01+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+252+0, 8, q_01+252+0, 8, temp);
	memset(q_10+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, q_10+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+16, 8, q_10+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+12, 8, q_10+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+8, 8, q_10+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+4, 8, q_10+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+252+0, 8, q_10+252+0, 8, temp);
	memset(q_11+252, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, q_11+252+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+16, 8, q_11+252+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+12, 8, q_11+252+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+8, 8, q_11+252+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+4, 8, q_11+252+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+252+0, 8, q_11+252+0, 8, temp);
	

	// Recombining results: n: 5610, depth: 2
	GF2X_MUL(88, temp, 44, q_00+252+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, q_01+252+0, 44, p_10+260);
	gf2x_add(88, p_00+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_00+252+0, 44, p_01+260);
	GF2X_MUL(88, temp2, 44, q_01+252+0, 44, p_11+260);
	gf2x_add(88, p_01+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+252+0, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, q_11+252+0, 44, p_10+260);
	gf2x_add(88, p_10+172+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+252+0, 44, p_01+260);
	GF2X_MUL(88, temp2, 44, q_11+252+0, 44, p_11+260);
	gf2x_add(88, p_11+172+0, 88, temp, 88, temp2);
	

	// Calculating left operands: n: 10740, depth: 1
	// Digits to shift: 87
	// Displacement: 87
	GF2X_MUL(176, temp, 88, f_sum+1+80, 88, p_00+172);
	GF2X_MUL(176, temp2, 88, g_sum+1+80, 88, p_01+172);
	gf2x_add(169, f_sum+513, 169, temp+7, 169, temp2+7);
	GF2X_MUL(160, temp, 80, p_00+172+8, 80, f_sum+1);
	GF2X_MUL(160, temp2, 80, p_01+172+8, 80, g_sum+1);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(81, f_sum+513, 81, f_sum+513, 81, temp+79);
	GF2X_MUL(16, temp, 8, f_sum+1+72, 8, p_00+172);
	GF2X_MUL(16, temp2, 8, g_sum+1+72, 8, p_01+172);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, f_sum+513, 1, f_sum+513, 1, temp+15);
	right_bit_shift_n(168, f_sum+513, 42);
	GF2X_MUL(176, temp, 88, f_sum+1+80, 88, p_10+172);
	GF2X_MUL(176, temp2, 88, g_sum+1+80, 88, p_11+172);
	gf2x_add(169, g_sum+513, 169, temp+7, 169, temp2+7);
	GF2X_MUL(160, temp, 80, p_10+172+8, 80, f_sum+1);
	GF2X_MUL(160, temp2, 80, p_11+172+8, 80, g_sum+1);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(81, g_sum+513, 81, g_sum+513, 81, temp+79);
	GF2X_MUL(16, temp, 8, f_sum+1+72, 8, p_10+172);
	GF2X_MUL(16, temp2, 8, g_sum+1+72, 8, p_11+172);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, g_sum+513, 1, g_sum+513, 1, temp+15);
	right_bit_shift_n(168, g_sum+513, 42);
	

	delta = divstepsx_256(255, delta, f_sum+591, g_sum+591, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+587+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+587+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+587+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+587+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+587+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+587+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+587+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+587+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+583+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+583+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+583);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+583+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+583+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+583);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+571+12, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+571+12, 12, p_01+328);
	gf2x_add(24, f_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+571+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+571+0, 12, p_01+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+976, 12, f_sum+976, 12, temp+12);
	right_bit_shift_n(24, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+571+12, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+571+12, 12, p_11+328);
	gf2x_add(24, g_sum+976+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+571+0, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+571+0, 12, p_11+328);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+976, 12, g_sum+976, 12, temp+12);
	right_bit_shift_n(24, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+985, g_sum+985, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+981+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+981+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+981+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+977+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+977+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+977);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+977);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(q_00+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, q_00+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+316+0, 8, q_00+316+0, 8, temp);
	memset(q_01+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, q_01+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+316+0, 8, q_01+316+0, 8, temp);
	memset(q_10+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, q_10+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+316+0, 8, q_10+316+0, 8, temp);
	memset(q_11+316, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, q_11+316+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+316+0, 8, q_11+316+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 4
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_10+328);
	gf2x_add(24, p_00+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_01+316+0, 12, p_11+328);
	gf2x_add(24, p_01+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_10+328);
	gf2x_add(24, p_10+304+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+316+0, 12, p_01+328);
	GF2X_MUL(24, temp2, 12, q_11+316+0, 12, p_11+328);
	gf2x_add(24, p_11+304+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 3
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+551+20, 24, p_00+304);
	GF2X_MUL(48, temp2, 24, g_sum+551+20, 24, p_01+304);
	gf2x_add(44, f_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, f_sum+551);
	GF2X_MUL(40, temp2, 20, p_01+304+4, 20, g_sum+551);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+907, 20, f_sum+907, 20, temp+20);
	right_bit_shift_n(44, f_sum+907, 58);
	GF2X_MUL(48, temp, 24, f_sum+551+20, 24, p_10+304);
	GF2X_MUL(48, temp2, 24, g_sum+551+20, 24, p_11+304);
	gf2x_add(44, g_sum+907, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+304+4, 20, f_sum+551);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, g_sum+551);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+907, 20, g_sum+907, 20, temp+20);
	right_bit_shift_n(44, g_sum+907, 58);
	

	delta = divstepsx_256(255, delta, f_sum+924, g_sum+924, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+920+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+920+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+920+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+916+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+916+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+916);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+916);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+908);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+908);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(q_00+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, q_00+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+4, 8, q_00+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+296+0, 8, q_00+296+0, 8, temp);
	memset(q_01+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, q_01+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+4, 8, q_01+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+296+0, 8, q_01+296+0, 8, temp);
	memset(q_10+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, q_10+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+4, 8, q_10+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+296+0, 8, q_10+296+0, 8, temp);
	memset(q_11+296, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, q_11+296+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+4, 8, q_11+296+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+296+0, 8, q_11+296+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 3
	memset(p_00+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_01+296);
	gf2x_add(40, p_00+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+16, 8, p_00+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+12, 8, p_00+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+8, 8, p_00+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+4, 8, p_00+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+260+0, 8, p_00+260+0, 8, temp);
	memset(p_01+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_00+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_01+296);
	gf2x_add(40, p_01+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+16, 8, p_01+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+12, 8, p_01+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+8, 8, p_01+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+4, 8, p_01+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_01+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+260+0, 8, p_01+260+0, 8, temp);
	memset(p_10+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_10+304+4, 20, q_11+296);
	gf2x_add(40, p_10+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+16, 8, p_10+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+12, 8, p_10+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+8, 8, p_10+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+4, 8, p_10+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_00+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_10+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+260+0, 8, p_10+260+0, 8, temp);
	memset(p_11+260, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+304+4, 20, q_10+296);
	GF2X_MUL(40, temp2, 20, p_11+304+4, 20, q_11+296);
	gf2x_add(40, p_11+260+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+296+16, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+16, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+16, 8, p_11+260+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+12, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+12, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+12, 8, p_11+260+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+8, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+8, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+8, 8, p_11+260+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+4, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+4, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+4, 8, p_11+260+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+296+0, 4, p_01+304);
	GF2X_MUL(8, temp2, 4, q_11+296+0, 4, p_11+304);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+260+0, 8, p_11+260+0, 8, temp);
	

	// Calculating left operands: n: 5130, depth: 2
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+514+37, 44, p_00+260);
	GF2X_MUL(88, temp2, 44, g_sum+514+37, 44, p_01+260);
	gf2x_add(81, f_sum+774, 81, temp+7, 81, temp2+7);
	GF2X_MUL(74, temp, 37, p_00+260+7, 37, f_sum+514);
	GF2X_MUL(74, temp2, 37, p_01+260+7, 37, g_sum+514);
	gf2x_add(74, temp, 74, temp, 74, temp2);
	gf2x_add(37, f_sum+774, 37, f_sum+774, 37, temp+37);
	right_bit_shift_n(81, f_sum+774, 53);
	GF2X_MUL(88, temp, 44, f_sum+514+37, 44, p_10+260);
	GF2X_MUL(88, temp2, 44, g_sum+514+37, 44, p_11+260);
	gf2x_add(81, g_sum+774, 81, temp+7, 81, temp2+7);
	GF2X_MUL(74, temp, 37, p_10+260+7, 37, f_sum+514);
	GF2X_MUL(74, temp2, 37, p_11+260+7, 37, g_sum+514);
	gf2x_add(74, temp, 74, temp, 74, temp2);
	gf2x_add(37, g_sum+774, 37, g_sum+774, 37, temp+37);
	right_bit_shift_n(81, g_sum+774, 53);
	

	delta = divstepsx_256(255, delta, f_sum+808, g_sum+808, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+804+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+804+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+804+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+804+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+804+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+804+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+804+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+804+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+800+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+800+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+800);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+800);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+800+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+800+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+800);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+800);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+792+8, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+792+8, 12, p_01+328);
	gf2x_add(20, f_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, f_sum+792);
	GF2X_MUL(16, temp2, 8, p_01+328+4, 8, g_sum+792);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+976, 8, f_sum+976, 8, temp+8);
	right_bit_shift_n(20, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+792+8, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+792+8, 12, p_11+328);
	gf2x_add(20, g_sum+976, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+328+4, 8, f_sum+792);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, g_sum+792);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+976, 8, g_sum+976, 8, temp+8);
	right_bit_shift_n(20, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+981, g_sum+981, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 510, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_01+340);
	gf2x_add(8, f_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_01+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(8, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+4, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+4, 4, p_11+340);
	gf2x_add(8, g_sum+1013+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+977+0, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(8, g_sum+1013, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 510, depth: 5
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, q_00+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, q_01+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, q_10+316+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, q_11+316+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 4
	memset(p_00+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_01+316);
	gf2x_add(16, p_00+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+304+4, 8, p_00+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+304+0, 8, p_00+304+0, 8, temp);
	memset(p_01+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_00+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_01+316);
	gf2x_add(16, p_01+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+304+4, 8, p_01+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_01+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+304+0, 8, p_01+304+0, 8, temp);
	memset(p_10+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_10+328+4, 8, q_11+316);
	gf2x_add(16, p_10+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+304+4, 8, p_10+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_00+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_10+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+304+0, 8, p_10+304+0, 8, temp);
	memset(p_11+304, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+328+4, 8, q_10+316);
	GF2X_MUL(16, temp2, 8, p_11+328+4, 8, q_11+316);
	gf2x_add(16, p_11+304+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+316+4, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+4, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+304+4, 8, p_11+304+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+316+0, 4, p_01+328);
	GF2X_MUL(8, temp2, 4, q_11+316+0, 4, p_11+328);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+304+0, 8, p_11+304+0, 8, temp);
	

	// Calculating left operands: n: 2325, depth: 3
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+775+17, 20, p_00+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+17, 20, p_01+304);
	gf2x_add(37, f_sum+907, 37, temp+3, 37, temp2+3);
	GF2X_MUL(34, temp, 17, p_00+304+3, 17, f_sum+775);
	GF2X_MUL(34, temp2, 17, p_01+304+3, 17, g_sum+775);
	gf2x_add(34, temp, 34, temp, 34, temp2);
	gf2x_add(17, f_sum+907, 17, f_sum+907, 17, temp+17);
	right_bit_shift_n(37, f_sum+907, 59);
	GF2X_MUL(40, temp, 20, f_sum+775+17, 20, p_10+304);
	GF2X_MUL(40, temp2, 20, g_sum+775+17, 20, p_11+304);
	gf2x_add(37, g_sum+907, 37, temp+3, 37, temp2+3);
	GF2X_MUL(34, temp, 17, p_10+304+3, 17, f_sum+775);
	GF2X_MUL(34, temp2, 17, p_11+304+3, 17, g_sum+775);
	gf2x_add(34, temp, 34, temp, 34, temp2);
	gf2x_add(17, g_sum+907, 17, g_sum+907, 17, temp+17);
	right_bit_shift_n(37, g_sum+907, 59);
	

	delta = divstepsx_256(255, delta, f_sum+921, g_sum+921, p_00+348, p_01+348, p_10+348, p_11+348);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+917+4, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+917+4, 4, p_01+348);
	gf2x_add(8, f_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+917+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, g_sum+917+0, 4, p_01+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1034, 4, f_sum+1034, 4, temp+4);
	right_bit_shift_n(8, f_sum+1034, 63);
	GF2X_MUL(8, temp, 4, f_sum+917+4, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+917+4, 4, p_11+348);
	gf2x_add(8, g_sum+1034+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+917+0, 4, p_10+348);
	GF2X_MUL(8, temp2, 4, g_sum+917+0, 4, p_11+348);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1034, 4, g_sum+1034, 4, temp+4);
	right_bit_shift_n(8, g_sum+1034, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1035, g_sum+1035, q_00+332, q_01+332, q_10+332, q_11+332);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_10+348);
	gf2x_add(8, p_00+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_01+332+0, 4, p_11+348);
	gf2x_add(8, p_01+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_00+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_10+348);
	gf2x_add(8, p_10+340+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+332+0, 4, p_01+348);
	GF2X_MUL(8, temp2, 4, q_11+332+0, 4, p_11+348);
	gf2x_add(8, p_11+340+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+913+4, 8, p_00+340);
	GF2X_MUL(16, temp2, 8, g_sum+913+4, 8, p_01+340);
	gf2x_add(12, f_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, f_sum+913);
	GF2X_MUL(8, temp2, 4, p_01+340+4, 4, g_sum+913);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1013, 4, f_sum+1013, 4, temp+4);
	right_bit_shift_n(12, f_sum+1013, 62);
	GF2X_MUL(16, temp, 8, f_sum+913+4, 8, p_10+340);
	GF2X_MUL(16, temp2, 8, g_sum+913+4, 8, p_11+340);
	gf2x_add(12, g_sum+1013, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+340+4, 4, f_sum+913);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, g_sum+913);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1013, 4, g_sum+1013, 4, temp+4);
	right_bit_shift_n(12, g_sum+1013, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1014, g_sum+1014, q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 765, depth: 5
	memset(p_00+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_01+328);
	gf2x_add(8, p_00+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+328+0, 8, p_00+328+0, 8, temp);
	memset(p_01+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_00+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_01+328);
	gf2x_add(8, p_01+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_01+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+328+0, 8, p_01+328+0, 8, temp);
	memset(p_10+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_10+340+4, 4, q_11+328);
	gf2x_add(8, p_10+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_10+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+328+0, 8, p_10+328+0, 8, temp);
	memset(p_11+328, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+340+4, 4, q_10+328);
	GF2X_MUL(8, temp2, 4, p_11+340+4, 4, q_11+328);
	gf2x_add(8, p_11+328+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+328+0, 4, p_01+340);
	GF2X_MUL(8, temp2, 4, q_11+328+0, 4, p_11+340);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+328+0, 8, p_11+328+0, 8, temp);
	

	// Calculating left operands: n: 1050, depth: 4
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+908+5, 12, p_00+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+5, 12, p_01+328);
	gf2x_add(17, f_sum+976, 17, temp+7, 17, temp2+7);
	GF2X_MUL(10, temp, 5, p_00+328+7, 5, f_sum+908);
	GF2X_MUL(10, temp2, 5, p_01+328+7, 5, g_sum+908);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(5, f_sum+976, 5, f_sum+976, 5, temp+5);
	right_bit_shift_n(17, f_sum+976, 61);
	GF2X_MUL(24, temp, 12, f_sum+908+5, 12, p_10+328);
	GF2X_MUL(24, temp2, 12, g_sum+908+5, 12, p_11+328);
	gf2x_add(17, g_sum+976, 17, temp+7, 17, temp2+7);
	GF2X_MUL(10, temp, 5, p_10+328+7, 5, f_sum+908);
	GF2X_MUL(10, temp2, 5, p_11+328+7, 5, g_sum+908);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(5, g_sum+976, 5, g_sum+976, 5, temp+5);
	right_bit_shift_n(17, g_sum+976, 61);
	

	delta = divstepsx_256(255, delta, f_sum+978, g_sum+978, p_00+340, p_01+340, p_10+340, p_11+340);

	// Calculating left operands: n: 285, depth: 5
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+977+1, 4, p_00+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+1, 4, p_01+340);
	gf2x_add(5, f_sum+1013, 5, temp+3, 5, temp2+3);
	GF2X_MUL(2, temp, 1, p_00+340+3, 1, f_sum+977);
	GF2X_MUL(2, temp2, 1, p_01+340+3, 1, g_sum+977);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1013, 1, f_sum+1013, 1, temp+1);
	right_bit_shift_n(5, f_sum+1013, 63);
	GF2X_MUL(8, temp, 4, f_sum+977+1, 4, p_10+340);
	GF2X_MUL(8, temp2, 4, g_sum+977+1, 4, p_11+340);
	gf2x_add(5, g_sum+1013, 5, temp+3, 5, temp2+3);
	GF2X_MUL(2, temp, 1, p_10+340+3, 1, f_sum+977);
	GF2X_MUL(2, temp2, 1, p_11+340+3, 1, g_sum+977);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1013, 1, g_sum+1013, 1, temp+1);
	right_bit_shift_n(5, g_sum+1013, 63);
	

	delta = divstepsx(30, delta, *(f_sum+1014), *(g_sum+1014), q_00+328, q_01+328, q_10+328, q_11+328);

	// Recombining results: n: 285, depth: 5
	memset(q_00+316, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+340+3, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_10+340+3, 1, q_01+328);
	gf2x_add(2, q_00+316+3, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+340+2, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_10+340+2, 1, q_01+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+316+2, 2, q_00+316+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+340+1, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_10+340+1, 1, q_01+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+316+1, 2, q_00+316+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+328+0, 1, p_00+340);
	GF2X_MUL(2, temp2, 1, q_01+328+0, 1, p_10+340);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+316+0, 2, q_00+316+0, 2, temp);
	memset(q_01+316, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+340+3, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_11+340+3, 1, q_01+328);
	gf2x_add(2, q_01+316+3, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+340+2, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_11+340+2, 1, q_01+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+316+2, 2, q_01+316+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+340+1, 1, q_00+328);
	GF2X_MUL(2, temp2, 1, p_11+340+1, 1, q_01+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+316+1, 2, q_01+316+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+328+0, 1, p_01+340);
	GF2X_MUL(2, temp2, 1, q_01+328+0, 1, p_11+340);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+316+0, 2, q_01+316+0, 2, temp);
	memset(q_10+316, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+340+3, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_10+340+3, 1, q_11+328);
	gf2x_add(2, q_10+316+3, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+340+2, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_10+340+2, 1, q_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+316+2, 2, q_10+316+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+340+1, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_10+340+1, 1, q_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+316+1, 2, q_10+316+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+328+0, 1, p_00+340);
	GF2X_MUL(2, temp2, 1, q_11+328+0, 1, p_10+340);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+316+0, 2, q_10+316+0, 2, temp);
	memset(q_11+316, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+340+3, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_11+340+3, 1, q_11+328);
	gf2x_add(2, q_11+316+3, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+340+2, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_11+340+2, 1, q_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+316+2, 2, q_11+316+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+340+1, 1, q_10+328);
	GF2X_MUL(2, temp2, 1, p_11+340+1, 1, q_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+316+1, 2, q_11+316+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+328+0, 1, p_01+340);
	GF2X_MUL(2, temp2, 1, q_11+328+0, 1, p_11+340);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+316+0, 2, q_11+316+0, 2, temp);
	

	// Recombining results: n: 1050, depth: 4
	memset(q_00+296, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(10, temp, 5, p_00+328+7, 5, q_00+316);
	GF2X_MUL(10, temp2, 5, p_10+328+7, 5, q_01+316);
	gf2x_add(10, q_00+296+7, 10, temp, 10, temp2);
	GF2X_MUL(10, temp, 5, p_00+328+2, 5, q_00+316);
	GF2X_MUL(10, temp2, 5, p_10+328+2, 5, q_01+316);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+296+2, 10, q_00+296+2, 10, temp);
	GF2X_MUL(4, temp, 2, q_00+316+3, 2, p_00+328);
	GF2X_MUL(4, temp2, 2, q_01+316+3, 2, p_10+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+296+3, 4, q_00+296+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+316+1, 2, p_00+328);
	GF2X_MUL(4, temp2, 2, q_01+316+1, 2, p_10+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+296+1, 4, q_00+296+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+328+1, 1, q_00+316);
	GF2X_MUL(2, temp2, 1, p_10+328+1, 1, q_01+316);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+296+1, 2, q_00+296+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+316+0, 1, p_00+328);
	GF2X_MUL(2, temp2, 1, q_01+316+0, 1, p_10+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+296+0, 2, q_00+296+0, 2, temp);
	memset(q_01+296, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(10, temp, 5, p_01+328+7, 5, q_00+316);
	GF2X_MUL(10, temp2, 5, p_11+328+7, 5, q_01+316);
	gf2x_add(10, q_01+296+7, 10, temp, 10, temp2);
	GF2X_MUL(10, temp, 5, p_01+328+2, 5, q_00+316);
	GF2X_MUL(10, temp2, 5, p_11+328+2, 5, q_01+316);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+296+2, 10, q_01+296+2, 10, temp);
	GF2X_MUL(4, temp, 2, q_00+316+3, 2, p_01+328);
	GF2X_MUL(4, temp2, 2, q_01+316+3, 2, p_11+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+296+3, 4, q_01+296+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+316+1, 2, p_01+328);
	GF2X_MUL(4, temp2, 2, q_01+316+1, 2, p_11+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+296+1, 4, q_01+296+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+328+1, 1, q_00+316);
	GF2X_MUL(2, temp2, 1, p_11+328+1, 1, q_01+316);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+296+1, 2, q_01+296+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+316+0, 1, p_01+328);
	GF2X_MUL(2, temp2, 1, q_01+316+0, 1, p_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+296+0, 2, q_01+296+0, 2, temp);
	memset(q_10+296, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(10, temp, 5, p_00+328+7, 5, q_10+316);
	GF2X_MUL(10, temp2, 5, p_10+328+7, 5, q_11+316);
	gf2x_add(10, q_10+296+7, 10, temp, 10, temp2);
	GF2X_MUL(10, temp, 5, p_00+328+2, 5, q_10+316);
	GF2X_MUL(10, temp2, 5, p_10+328+2, 5, q_11+316);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+296+2, 10, q_10+296+2, 10, temp);
	GF2X_MUL(4, temp, 2, q_10+316+3, 2, p_00+328);
	GF2X_MUL(4, temp2, 2, q_11+316+3, 2, p_10+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+296+3, 4, q_10+296+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+316+1, 2, p_00+328);
	GF2X_MUL(4, temp2, 2, q_11+316+1, 2, p_10+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+296+1, 4, q_10+296+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+328+1, 1, q_10+316);
	GF2X_MUL(2, temp2, 1, p_10+328+1, 1, q_11+316);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+296+1, 2, q_10+296+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+316+0, 1, p_00+328);
	GF2X_MUL(2, temp2, 1, q_11+316+0, 1, p_10+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+296+0, 2, q_10+296+0, 2, temp);
	memset(q_11+296, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(10, temp, 5, p_01+328+7, 5, q_10+316);
	GF2X_MUL(10, temp2, 5, p_11+328+7, 5, q_11+316);
	gf2x_add(10, q_11+296+7, 10, temp, 10, temp2);
	GF2X_MUL(10, temp, 5, p_01+328+2, 5, q_10+316);
	GF2X_MUL(10, temp2, 5, p_11+328+2, 5, q_11+316);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+296+2, 10, q_11+296+2, 10, temp);
	GF2X_MUL(4, temp, 2, q_10+316+3, 2, p_01+328);
	GF2X_MUL(4, temp2, 2, q_11+316+3, 2, p_11+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+296+3, 4, q_11+296+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+316+1, 2, p_01+328);
	GF2X_MUL(4, temp2, 2, q_11+316+1, 2, p_11+328);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+296+1, 4, q_11+296+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+328+1, 1, q_10+316);
	GF2X_MUL(2, temp2, 1, p_11+328+1, 1, q_11+316);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+296+1, 2, q_11+296+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+316+0, 1, p_01+328);
	GF2X_MUL(2, temp2, 1, q_11+316+0, 1, p_11+328);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+296+0, 2, q_11+296+0, 2, temp);
	

	// Recombining results: n: 2325, depth: 3
	memset(q_00+252, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(34, temp, 17, p_00+304+3, 17, q_00+296);
	GF2X_MUL(34, temp2, 17, p_10+304+3, 17, q_01+296);
	gf2x_add(34, q_00+252+3, 34, temp, 34, temp2);
	GF2X_MUL(6, temp, 3, q_00+296+14, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_01+296+14, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+252+14, 6, q_00+252+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+11, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_01+296+11, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+252+11, 6, q_00+252+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+8, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_01+296+8, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+252+8, 6, q_00+252+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+5, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_01+296+5, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+252+5, 6, q_00+252+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+2, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_01+296+2, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+252+2, 6, q_00+252+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+304+1, 2, q_00+296);
	GF2X_MUL(4, temp2, 2, p_10+304+1, 2, q_01+296);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+252+1, 4, q_00+252+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+296+1, 1, p_00+304);
	GF2X_MUL(2, temp2, 1, q_01+296+1, 1, p_10+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+252+1, 2, q_00+252+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+296+0, 1, p_00+304);
	GF2X_MUL(2, temp2, 1, q_01+296+0, 1, p_10+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+252+0, 2, q_00+252+0, 2, temp);
	memset(q_01+252, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(34, temp, 17, p_01+304+3, 17, q_00+296);
	GF2X_MUL(34, temp2, 17, p_11+304+3, 17, q_01+296);
	gf2x_add(34, q_01+252+3, 34, temp, 34, temp2);
	GF2X_MUL(6, temp, 3, q_00+296+14, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_01+296+14, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+252+14, 6, q_01+252+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+11, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_01+296+11, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+252+11, 6, q_01+252+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+8, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_01+296+8, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+252+8, 6, q_01+252+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+5, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_01+296+5, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+252+5, 6, q_01+252+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+296+2, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_01+296+2, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+252+2, 6, q_01+252+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+304+1, 2, q_00+296);
	GF2X_MUL(4, temp2, 2, p_11+304+1, 2, q_01+296);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+252+1, 4, q_01+252+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+296+1, 1, p_01+304);
	GF2X_MUL(2, temp2, 1, q_01+296+1, 1, p_11+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+252+1, 2, q_01+252+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+296+0, 1, p_01+304);
	GF2X_MUL(2, temp2, 1, q_01+296+0, 1, p_11+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+252+0, 2, q_01+252+0, 2, temp);
	memset(q_10+252, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(34, temp, 17, p_00+304+3, 17, q_10+296);
	GF2X_MUL(34, temp2, 17, p_10+304+3, 17, q_11+296);
	gf2x_add(34, q_10+252+3, 34, temp, 34, temp2);
	GF2X_MUL(6, temp, 3, q_10+296+14, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_11+296+14, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+252+14, 6, q_10+252+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+11, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_11+296+11, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+252+11, 6, q_10+252+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+8, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_11+296+8, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+252+8, 6, q_10+252+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+5, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_11+296+5, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+252+5, 6, q_10+252+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+2, 3, p_00+304);
	GF2X_MUL(6, temp2, 3, q_11+296+2, 3, p_10+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+252+2, 6, q_10+252+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+304+1, 2, q_10+296);
	GF2X_MUL(4, temp2, 2, p_10+304+1, 2, q_11+296);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+252+1, 4, q_10+252+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+296+1, 1, p_00+304);
	GF2X_MUL(2, temp2, 1, q_11+296+1, 1, p_10+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+252+1, 2, q_10+252+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+296+0, 1, p_00+304);
	GF2X_MUL(2, temp2, 1, q_11+296+0, 1, p_10+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+252+0, 2, q_10+252+0, 2, temp);
	memset(q_11+252, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(34, temp, 17, p_01+304+3, 17, q_10+296);
	GF2X_MUL(34, temp2, 17, p_11+304+3, 17, q_11+296);
	gf2x_add(34, q_11+252+3, 34, temp, 34, temp2);
	GF2X_MUL(6, temp, 3, q_10+296+14, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_11+296+14, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+252+14, 6, q_11+252+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+11, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_11+296+11, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+252+11, 6, q_11+252+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+8, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_11+296+8, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+252+8, 6, q_11+252+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+5, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_11+296+5, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+252+5, 6, q_11+252+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+296+2, 3, p_01+304);
	GF2X_MUL(6, temp2, 3, q_11+296+2, 3, p_11+304);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+252+2, 6, q_11+252+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+304+1, 2, q_10+296);
	GF2X_MUL(4, temp2, 2, p_11+304+1, 2, q_11+296);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+252+1, 4, q_11+252+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+296+1, 1, p_01+304);
	GF2X_MUL(2, temp2, 1, q_11+296+1, 1, p_11+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+252+1, 2, q_11+252+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+296+0, 1, p_01+304);
	GF2X_MUL(2, temp2, 1, q_11+296+0, 1, p_11+304);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+252+0, 2, q_11+252+0, 2, temp);
	

	// Recombining results: n: 5130, depth: 2
	memset(q_00+168, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(74, temp, 37, p_00+260+7, 37, q_00+252);
	GF2X_MUL(74, temp2, 37, p_10+260+7, 37, q_01+252);
	gf2x_add(74, q_00+168+7, 74, temp, 74, temp2);
	GF2X_MUL(14, temp, 7, q_00+252+30, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_01+252+30, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+168+30, 14, q_00+168+30, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+23, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_01+252+23, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+168+23, 14, q_00+168+23, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+16, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_01+252+16, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+168+16, 14, q_00+168+16, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+9, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_01+252+9, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+168+9, 14, q_00+168+9, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+2, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_01+252+2, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+168+2, 14, q_00+168+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+260+5, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_10+260+5, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+168+5, 4, q_00+168+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+260+3, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_10+260+3, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+168+3, 4, q_00+168+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+260+1, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_10+260+1, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+168+1, 4, q_00+168+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+252+1, 1, p_00+260);
	GF2X_MUL(2, temp2, 1, q_01+252+1, 1, p_10+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+168+1, 2, q_00+168+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+252+0, 1, p_00+260);
	GF2X_MUL(2, temp2, 1, q_01+252+0, 1, p_10+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+168+0, 2, q_00+168+0, 2, temp);
	memset(q_01+168, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(74, temp, 37, p_01+260+7, 37, q_00+252);
	GF2X_MUL(74, temp2, 37, p_11+260+7, 37, q_01+252);
	gf2x_add(74, q_01+168+7, 74, temp, 74, temp2);
	GF2X_MUL(14, temp, 7, q_00+252+30, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_01+252+30, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+168+30, 14, q_01+168+30, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+23, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_01+252+23, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+168+23, 14, q_01+168+23, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+16, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_01+252+16, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+168+16, 14, q_01+168+16, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+9, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_01+252+9, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+168+9, 14, q_01+168+9, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+252+2, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_01+252+2, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+168+2, 14, q_01+168+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+260+5, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_11+260+5, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+168+5, 4, q_01+168+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+260+3, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_11+260+3, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+168+3, 4, q_01+168+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+260+1, 2, q_00+252);
	GF2X_MUL(4, temp2, 2, p_11+260+1, 2, q_01+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+168+1, 4, q_01+168+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+252+1, 1, p_01+260);
	GF2X_MUL(2, temp2, 1, q_01+252+1, 1, p_11+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+168+1, 2, q_01+168+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+252+0, 1, p_01+260);
	GF2X_MUL(2, temp2, 1, q_01+252+0, 1, p_11+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+168+0, 2, q_01+168+0, 2, temp);
	memset(q_10+168, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(74, temp, 37, p_00+260+7, 37, q_10+252);
	GF2X_MUL(74, temp2, 37, p_10+260+7, 37, q_11+252);
	gf2x_add(74, q_10+168+7, 74, temp, 74, temp2);
	GF2X_MUL(14, temp, 7, q_10+252+30, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_11+252+30, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+168+30, 14, q_10+168+30, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+23, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_11+252+23, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+168+23, 14, q_10+168+23, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+16, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_11+252+16, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+168+16, 14, q_10+168+16, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+9, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_11+252+9, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+168+9, 14, q_10+168+9, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+2, 7, p_00+260);
	GF2X_MUL(14, temp2, 7, q_11+252+2, 7, p_10+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+168+2, 14, q_10+168+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+260+5, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_10+260+5, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+168+5, 4, q_10+168+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+260+3, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_10+260+3, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+168+3, 4, q_10+168+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+260+1, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_10+260+1, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+168+1, 4, q_10+168+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+252+1, 1, p_00+260);
	GF2X_MUL(2, temp2, 1, q_11+252+1, 1, p_10+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+168+1, 2, q_10+168+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+252+0, 1, p_00+260);
	GF2X_MUL(2, temp2, 1, q_11+252+0, 1, p_10+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+168+0, 2, q_10+168+0, 2, temp);
	memset(q_11+168, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(74, temp, 37, p_01+260+7, 37, q_10+252);
	GF2X_MUL(74, temp2, 37, p_11+260+7, 37, q_11+252);
	gf2x_add(74, q_11+168+7, 74, temp, 74, temp2);
	GF2X_MUL(14, temp, 7, q_10+252+30, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_11+252+30, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+168+30, 14, q_11+168+30, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+23, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_11+252+23, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+168+23, 14, q_11+168+23, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+16, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_11+252+16, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+168+16, 14, q_11+168+16, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+9, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_11+252+9, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+168+9, 14, q_11+168+9, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+252+2, 7, p_01+260);
	GF2X_MUL(14, temp2, 7, q_11+252+2, 7, p_11+260);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+168+2, 14, q_11+168+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+260+5, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_11+260+5, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+168+5, 4, q_11+168+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+260+3, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_11+260+3, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+168+3, 4, q_11+168+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+260+1, 2, q_10+252);
	GF2X_MUL(4, temp2, 2, p_11+260+1, 2, q_11+252);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+168+1, 4, q_11+168+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+252+1, 1, p_01+260);
	GF2X_MUL(2, temp2, 1, q_11+252+1, 1, p_11+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+168+1, 2, q_11+168+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+252+0, 1, p_01+260);
	GF2X_MUL(2, temp2, 1, q_11+252+0, 1, p_11+260);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+168+0, 2, q_11+168+0, 2, temp);
	

	// Recombining results: n: 10740, depth: 1
	memset(q_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(162, temp, 81, p_00+172+7, 81, q_00+168);
	GF2X_MUL(162, temp2, 81, p_10+172+7, 81, q_01+168);
	gf2x_add(162, q_00+0+6, 162, temp, 162, temp2);
	GF2X_MUL(14, temp, 7, q_00+168+74, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+74, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+73, 14, q_00+0+73, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+67, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+67, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+66, 14, q_00+0+66, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+60, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+60, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+59, 14, q_00+0+59, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+53, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+53, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+52, 14, q_00+0+52, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+46, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+46, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+45, 14, q_00+0+45, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+39, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+39, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+38, 14, q_00+0+38, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+32, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+32, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+31, 14, q_00+0+31, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+25, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+25, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+24, 14, q_00+0+24, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+18, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+18, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+17, 14, q_00+0+17, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+11, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+11, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+10, 14, q_00+0+10, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+4, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_01+168+4, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+0+3, 14, q_00+0+3, 14, temp);
	GF2X_MUL(8, temp, 4, p_00+172+3, 4, q_00+168);
	GF2X_MUL(8, temp2, 4, p_10+172+3, 4, q_01+168);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+2, 8, q_00+0+2, 8, temp);
	GF2X_MUL(6, temp, 3, q_00+168+1, 3, p_00+172);
	GF2X_MUL(6, temp2, 3, q_01+168+1, 3, p_10+172);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+0, 6, q_00+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+172+2, 1, q_00+168);
	GF2X_MUL(2, temp2, 1, p_10+172+2, 1, q_01+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+172+1, 1, q_00+168);
	GF2X_MUL(2, temp2, 1, p_10+172+1, 1, q_01+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+168+0, 1, p_00+172);
	GF2X_MUL(2, temp2, 1, q_01+168+0, 1, p_10+172);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+0, 1, q_00+0, 1, temp+1);
	memset(q_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(162, temp, 81, p_01+172+7, 81, q_00+168);
	GF2X_MUL(162, temp2, 81, p_11+172+7, 81, q_01+168);
	gf2x_add(162, q_01+0+6, 162, temp, 162, temp2);
	GF2X_MUL(14, temp, 7, q_00+168+74, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+74, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+73, 14, q_01+0+73, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+67, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+67, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+66, 14, q_01+0+66, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+60, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+60, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+59, 14, q_01+0+59, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+53, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+53, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+52, 14, q_01+0+52, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+46, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+46, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+45, 14, q_01+0+45, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+39, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+39, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+38, 14, q_01+0+38, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+32, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+32, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+31, 14, q_01+0+31, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+25, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+25, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+24, 14, q_01+0+24, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+18, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+18, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+17, 14, q_01+0+17, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+11, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+11, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+10, 14, q_01+0+10, 14, temp);
	GF2X_MUL(14, temp, 7, q_00+168+4, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_01+168+4, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+0+3, 14, q_01+0+3, 14, temp);
	GF2X_MUL(8, temp, 4, p_01+172+3, 4, q_00+168);
	GF2X_MUL(8, temp2, 4, p_11+172+3, 4, q_01+168);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+2, 8, q_01+0+2, 8, temp);
	GF2X_MUL(6, temp, 3, q_00+168+1, 3, p_01+172);
	GF2X_MUL(6, temp2, 3, q_01+168+1, 3, p_11+172);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+0, 6, q_01+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+172+2, 1, q_00+168);
	GF2X_MUL(2, temp2, 1, p_11+172+2, 1, q_01+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+172+1, 1, q_00+168);
	GF2X_MUL(2, temp2, 1, p_11+172+1, 1, q_01+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+168+0, 1, p_01+172);
	GF2X_MUL(2, temp2, 1, q_01+168+0, 1, p_11+172);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+0, 1, q_01+0, 1, temp+1);
	memset(q_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(162, temp, 81, p_00+172+7, 81, q_10+168);
	GF2X_MUL(162, temp2, 81, p_10+172+7, 81, q_11+168);
	gf2x_add(162, q_10+0+6, 162, temp, 162, temp2);
	GF2X_MUL(14, temp, 7, q_10+168+74, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+74, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+73, 14, q_10+0+73, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+67, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+67, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+66, 14, q_10+0+66, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+60, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+60, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+59, 14, q_10+0+59, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+53, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+53, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+52, 14, q_10+0+52, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+46, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+46, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+45, 14, q_10+0+45, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+39, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+39, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+38, 14, q_10+0+38, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+32, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+32, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+31, 14, q_10+0+31, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+25, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+25, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+24, 14, q_10+0+24, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+18, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+18, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+17, 14, q_10+0+17, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+11, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+11, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+10, 14, q_10+0+10, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+4, 7, p_00+172);
	GF2X_MUL(14, temp2, 7, q_11+168+4, 7, p_10+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+0+3, 14, q_10+0+3, 14, temp);
	GF2X_MUL(8, temp, 4, p_00+172+3, 4, q_10+168);
	GF2X_MUL(8, temp2, 4, p_10+172+3, 4, q_11+168);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+2, 8, q_10+0+2, 8, temp);
	GF2X_MUL(6, temp, 3, q_10+168+1, 3, p_00+172);
	GF2X_MUL(6, temp2, 3, q_11+168+1, 3, p_10+172);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+0, 6, q_10+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+172+2, 1, q_10+168);
	GF2X_MUL(2, temp2, 1, p_10+172+2, 1, q_11+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+172+1, 1, q_10+168);
	GF2X_MUL(2, temp2, 1, p_10+172+1, 1, q_11+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+168+0, 1, p_00+172);
	GF2X_MUL(2, temp2, 1, q_11+168+0, 1, p_10+172);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+0, 1, q_10+0, 1, temp+1);
	memset(q_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(162, temp, 81, p_01+172+7, 81, q_10+168);
	GF2X_MUL(162, temp2, 81, p_11+172+7, 81, q_11+168);
	gf2x_add(162, q_11+0+6, 162, temp, 162, temp2);
	GF2X_MUL(14, temp, 7, q_10+168+74, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+74, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+73, 14, q_11+0+73, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+67, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+67, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+66, 14, q_11+0+66, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+60, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+60, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+59, 14, q_11+0+59, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+53, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+53, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+52, 14, q_11+0+52, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+46, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+46, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+45, 14, q_11+0+45, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+39, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+39, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+38, 14, q_11+0+38, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+32, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+32, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+31, 14, q_11+0+31, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+25, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+25, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+24, 14, q_11+0+24, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+18, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+18, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+17, 14, q_11+0+17, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+11, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+11, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+10, 14, q_11+0+10, 14, temp);
	GF2X_MUL(14, temp, 7, q_10+168+4, 7, p_01+172);
	GF2X_MUL(14, temp2, 7, q_11+168+4, 7, p_11+172);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+0+3, 14, q_11+0+3, 14, temp);
	GF2X_MUL(8, temp, 4, p_01+172+3, 4, q_10+168);
	GF2X_MUL(8, temp2, 4, p_11+172+3, 4, q_11+168);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+2, 8, q_11+0+2, 8, temp);
	GF2X_MUL(6, temp, 3, q_10+168+1, 3, p_01+172);
	GF2X_MUL(6, temp2, 3, q_11+168+1, 3, p_11+172);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+0, 6, q_11+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+172+2, 1, q_10+168);
	GF2X_MUL(2, temp2, 1, p_11+172+2, 1, q_11+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+172+1, 1, q_10+168);
	GF2X_MUL(2, temp2, 1, p_11+172+1, 1, q_11+168);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+168+0, 1, p_01+172);
	GF2X_MUL(2, temp2, 1, q_11+168+0, 1, p_11+172);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+0, 1, q_11+0, 1, temp+1);
	

	// Recombining results: n: 21705, depth: 0
	memset(t_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_00+0+4, 168, q_00+0);
	GF2X_MUL(336, temp2, 168, p_10+0+4, 168, q_01+0);
	gf2x_add(336, t_00+0+4, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_00+0+164, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+164, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+164, 8, t_00+0+164, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+160, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+160, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+160, 8, t_00+0+160, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+156, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+156, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+156, 8, t_00+0+156, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+152, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+152, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+152, 8, t_00+0+152, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+148, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+148, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+148, 8, t_00+0+148, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+144, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+144, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+144, 8, t_00+0+144, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+140, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+140, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+140, 8, t_00+0+140, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+136, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+136, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+136, 8, t_00+0+136, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+132, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+132, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+132, 8, t_00+0+132, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+128, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+128, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+128, 8, t_00+0+128, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+124, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+124, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+124, 8, t_00+0+124, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+120, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+120, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+120, 8, t_00+0+120, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+116, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+116, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+116, 8, t_00+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+112, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+112, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+112, 8, t_00+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+108, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+108, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+108, 8, t_00+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+104, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+104, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+104, 8, t_00+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+100, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+100, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+100, 8, t_00+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+96, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+96, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+96, 8, t_00+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+92, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+92, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+92, 8, t_00+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+88, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+88, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+88, 8, t_00+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+84, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+84, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+84, 8, t_00+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+80, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+80, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+80, 8, t_00+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+76, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+76, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+76, 8, t_00+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+72, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+72, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+72, 8, t_00+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+68, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+68, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+68, 8, t_00+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+64, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+64, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+64, 8, t_00+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+60, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+60, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+60, 8, t_00+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+56, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+56, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+56, 8, t_00+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+52, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+52, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+52, 8, t_00+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+48, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+48, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+48, 8, t_00+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+44, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+44, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+44, 8, t_00+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+40, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+40, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+40, 8, t_00+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+36, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+36, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+36, 8, t_00+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+32, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+32, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+32, 8, t_00+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+28, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+28, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+28, 8, t_00+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+24, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+24, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+24, 8, t_00+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+20, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+20, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+20, 8, t_00+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+16, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+16, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+16, 8, t_00+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+12, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+12, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+12, 8, t_00+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+8, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+8, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+8, 8, t_00+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+4, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+4, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+4, 8, t_00+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+0, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_01+0+0, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_00+0+0, 8, t_00+0+0, 8, temp);
	memset(t_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_01+0+4, 168, q_00+0);
	GF2X_MUL(336, temp2, 168, p_11+0+4, 168, q_01+0);
	gf2x_add(336, t_01+0+4, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_00+0+164, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+164, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+164, 8, t_01+0+164, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+160, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+160, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+160, 8, t_01+0+160, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+156, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+156, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+156, 8, t_01+0+156, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+152, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+152, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+152, 8, t_01+0+152, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+148, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+148, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+148, 8, t_01+0+148, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+144, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+144, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+144, 8, t_01+0+144, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+140, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+140, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+140, 8, t_01+0+140, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+136, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+136, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+136, 8, t_01+0+136, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+132, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+132, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+132, 8, t_01+0+132, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+128, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+128, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+128, 8, t_01+0+128, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+124, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+124, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+124, 8, t_01+0+124, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+120, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+120, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+120, 8, t_01+0+120, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+116, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+116, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+116, 8, t_01+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+112, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+112, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+112, 8, t_01+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+108, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+108, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+108, 8, t_01+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+104, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+104, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+104, 8, t_01+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+100, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+100, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+100, 8, t_01+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+96, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+96, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+96, 8, t_01+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+92, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+92, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+92, 8, t_01+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+88, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+88, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+88, 8, t_01+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+84, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+84, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+84, 8, t_01+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+80, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+80, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+80, 8, t_01+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+76, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+76, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+76, 8, t_01+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+72, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+72, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+72, 8, t_01+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+68, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+68, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+68, 8, t_01+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+64, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+64, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+64, 8, t_01+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+60, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+60, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+60, 8, t_01+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+56, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+56, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+56, 8, t_01+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+52, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+52, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+52, 8, t_01+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+48, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+48, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+48, 8, t_01+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+44, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+44, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+44, 8, t_01+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+40, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+40, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+40, 8, t_01+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+36, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+36, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+36, 8, t_01+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+32, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+32, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+32, 8, t_01+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+28, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+28, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+28, 8, t_01+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+24, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+24, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+24, 8, t_01+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+20, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+20, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+20, 8, t_01+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+16, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+16, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+16, 8, t_01+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+12, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+12, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+12, 8, t_01+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+8, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+8, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+8, 8, t_01+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+4, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+4, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+4, 8, t_01+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+0+0, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_01+0+0, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_01+0+0, 8, t_01+0+0, 8, temp);
	memset(t_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_00+0+4, 168, q_10+0);
	GF2X_MUL(336, temp2, 168, p_10+0+4, 168, q_11+0);
	gf2x_add(336, t_10+0+4, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_10+0+164, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+164, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+164, 8, t_10+0+164, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+160, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+160, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+160, 8, t_10+0+160, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+156, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+156, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+156, 8, t_10+0+156, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+152, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+152, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+152, 8, t_10+0+152, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+148, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+148, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+148, 8, t_10+0+148, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+144, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+144, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+144, 8, t_10+0+144, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+140, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+140, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+140, 8, t_10+0+140, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+136, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+136, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+136, 8, t_10+0+136, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+132, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+132, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+132, 8, t_10+0+132, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+128, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+128, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+128, 8, t_10+0+128, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+124, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+124, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+124, 8, t_10+0+124, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+120, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+120, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+120, 8, t_10+0+120, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+116, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+116, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+116, 8, t_10+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+112, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+112, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+112, 8, t_10+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+108, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+108, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+108, 8, t_10+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+104, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+104, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+104, 8, t_10+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+100, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+100, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+100, 8, t_10+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+96, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+96, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+96, 8, t_10+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+92, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+92, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+92, 8, t_10+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+88, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+88, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+88, 8, t_10+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+84, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+84, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+84, 8, t_10+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+80, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+80, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+80, 8, t_10+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+76, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+76, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+76, 8, t_10+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+72, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+72, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+72, 8, t_10+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+68, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+68, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+68, 8, t_10+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+64, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+64, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+64, 8, t_10+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+60, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+60, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+60, 8, t_10+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+56, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+56, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+56, 8, t_10+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+52, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+52, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+52, 8, t_10+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+48, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+48, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+48, 8, t_10+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+44, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+44, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+44, 8, t_10+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+40, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+40, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+40, 8, t_10+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+36, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+36, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+36, 8, t_10+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+32, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+32, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+32, 8, t_10+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+28, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+28, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+28, 8, t_10+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+24, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+24, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+24, 8, t_10+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+20, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+20, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+20, 8, t_10+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+16, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+16, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+16, 8, t_10+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+12, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+12, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+12, 8, t_10+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+8, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+8, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+8, 8, t_10+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+4, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+4, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+4, 8, t_10+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+0, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, q_11+0+0, 4, p_10+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_10+0+0, 8, t_10+0+0, 8, temp);
	memset(t_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_01+0+4, 168, q_10+0);
	GF2X_MUL(336, temp2, 168, p_11+0+4, 168, q_11+0);
	gf2x_add(336, t_11+0+4, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_10+0+164, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+164, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+164, 8, t_11+0+164, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+160, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+160, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+160, 8, t_11+0+160, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+156, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+156, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+156, 8, t_11+0+156, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+152, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+152, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+152, 8, t_11+0+152, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+148, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+148, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+148, 8, t_11+0+148, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+144, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+144, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+144, 8, t_11+0+144, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+140, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+140, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+140, 8, t_11+0+140, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+136, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+136, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+136, 8, t_11+0+136, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+132, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+132, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+132, 8, t_11+0+132, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+128, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+128, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+128, 8, t_11+0+128, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+124, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+124, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+124, 8, t_11+0+124, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+120, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+120, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+120, 8, t_11+0+120, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+116, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+116, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+116, 8, t_11+0+116, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+112, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+112, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+112, 8, t_11+0+112, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+108, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+108, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+108, 8, t_11+0+108, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+104, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+104, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+104, 8, t_11+0+104, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+100, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+100, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+100, 8, t_11+0+100, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+96, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+96, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+96, 8, t_11+0+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+92, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+92, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+92, 8, t_11+0+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+88, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+88, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+88, 8, t_11+0+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+84, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+84, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+84, 8, t_11+0+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+80, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+80, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+80, 8, t_11+0+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+76, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+76, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+76, 8, t_11+0+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+72, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+72, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+72, 8, t_11+0+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+68, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+68, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+68, 8, t_11+0+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+64, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+64, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+64, 8, t_11+0+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+60, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+60, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+60, 8, t_11+0+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+56, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+56, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+56, 8, t_11+0+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+52, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+52, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+52, 8, t_11+0+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+48, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+48, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+48, 8, t_11+0+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+44, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+44, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+44, 8, t_11+0+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+40, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+40, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+40, 8, t_11+0+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+36, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+36, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+36, 8, t_11+0+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+32, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+32, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+32, 8, t_11+0+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+28, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+28, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+28, 8, t_11+0+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+24, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+24, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+24, 8, t_11+0+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+20, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+20, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+20, 8, t_11+0+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+16, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+16, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+16, 8, t_11+0+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+12, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+12, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+12, 8, t_11+0+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+8, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+8, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+8, 8, t_11+0+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+4, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+4, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+4, 8, t_11+0+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+0+0, 4, p_01+0);
	GF2X_MUL(8, temp2, 4, q_11+0+0, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, t_11+0+0, 8, t_11+0+0, 8, temp);
	

	return delta;
}