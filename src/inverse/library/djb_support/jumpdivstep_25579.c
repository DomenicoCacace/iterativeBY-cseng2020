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

int jumpdivstep_25579(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[819];
	DIGIT p_01[819];
	DIGIT p_10[819];
	DIGIT p_11[819];
	
	DIGIT q_00[797];
	DIGIT q_01[797];
	DIGIT q_10[797];
	DIGIT q_11[797];
	
	DIGIT f_sum[2443];
	DIGIT g_sum[2443];
	
	DIGIT temp[1606];
	DIGIT temp2[1606];
	

	delta = divstepsx_256(255, delta, f+796, g+796, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+792+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g+792+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+792+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g+792+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f+792+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g+792+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+792+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g+792+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+784+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g+784+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+784+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g+784+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f+784+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g+784+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+784+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g+784+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+772+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g+772+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f+772);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g+772);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f+772+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g+772+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f+772);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g+772);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f+748+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g+748+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f+748);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g+748);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f+748+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g+748+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f+748);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g+748);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6630, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f+696+52, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g+696+52, 52, p_01+711);
	gf2x_add(104, f_sum+2121+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f+696+0, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g+696+0, 52, p_01+711);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, f_sum+2121, 52, f_sum+2121, 52, temp+52);
	right_bit_shift_n(104, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f+696+52, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g+696+52, 52, p_11+711);
	gf2x_add(104, g_sum+2121+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, f+696+0, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g+696+0, 52, p_11+711);
	gf2x_add(104, temp, 104, temp, 104, temp2);
	gf2x_add(52, g_sum+2121, 52, g_sum+2121, 52, temp+52);
	right_bit_shift_n(104, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2170, g_sum+2170, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2166+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2166+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2166+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2166+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2166+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2166+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2166+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2166+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2158+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+2158+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+2146+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+2146+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+2146);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+2146);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+2146+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+2146+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+2146);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+2146);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+2122+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+2122+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+2122);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+2122);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+2122+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+2122+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+2122);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+2122);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(q_00+697, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, q_00+697+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+20, 8, q_00+697+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+16, 8, q_00+697+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+12, 8, q_00+697+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+8, 8, q_00+697+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+4, 8, q_00+697+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+697+0, 8, q_00+697+0, 8, temp);
	memset(q_01+697, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, q_01+697+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+20, 8, q_01+697+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+16, 8, q_01+697+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+12, 8, q_01+697+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+8, 8, q_01+697+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+4, 8, q_01+697+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+697+0, 8, q_01+697+0, 8, temp);
	memset(q_10+697, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, q_10+697+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+20, 8, q_10+697+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+16, 8, q_10+697+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+12, 8, q_10+697+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+8, 8, q_10+697+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+4, 8, q_10+697+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+697+0, 8, q_10+697+0, 8, temp);
	memset(q_11+697, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, q_11+697+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+20, 8, q_11+697+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+16, 8, q_11+697+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+12, 8, q_11+697+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+8, 8, q_11+697+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+4, 8, q_11+697+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+697+0, 8, q_11+697+0, 8, temp);
	

	// Recombining results: n: 6630, depth: 3
	GF2X_MUL(104, temp, 52, q_00+697+0, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, q_01+697+0, 52, p_10+711);
	gf2x_add(104, p_00+607+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_00+697+0, 52, p_01+711);
	GF2X_MUL(104, temp2, 52, q_01+697+0, 52, p_11+711);
	gf2x_add(104, p_01+607+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+697+0, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, q_11+697+0, 52, p_10+711);
	gf2x_add(104, p_10+607+0, 104, temp, 104, temp2);
	GF2X_MUL(104, temp, 52, q_10+697+0, 52, p_01+711);
	GF2X_MUL(104, temp2, 52, q_11+697+0, 52, p_11+711);
	gf2x_add(104, p_11+607+0, 104, temp, 104, temp2);
	

	// Calculating left operands: n: 13005, depth: 2
	// Digits to shift: 103
	// Displacement: 104
	GF2X_MUL(208, temp, 104, f+596+100, 104, p_00+607);
	GF2X_MUL(208, temp2, 104, g+596+100, 104, p_01+607);
	gf2x_add(204, f_sum+1812, 204, temp+4, 204, temp2+4);
	GF2X_MUL(200, temp, 100, p_00+607+4, 100, f+596);
	GF2X_MUL(200, temp2, 100, p_01+607+4, 100, g+596);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, f_sum+1812, 100, f_sum+1812, 100, temp+100);
	right_bit_shift_n(204, f_sum+1812, 38);
	GF2X_MUL(208, temp, 104, f+596+100, 104, p_10+607);
	GF2X_MUL(208, temp2, 104, g+596+100, 104, p_11+607);
	gf2x_add(204, g_sum+1812, 204, temp+4, 204, temp2+4);
	GF2X_MUL(200, temp, 100, p_10+607+4, 100, f+596);
	GF2X_MUL(200, temp2, 100, p_11+607+4, 100, g+596);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, g_sum+1812, 100, g_sum+1812, 100, temp+100);
	right_bit_shift_n(204, g_sum+1812, 38);
	

	delta = divstepsx_256(255, delta, f_sum+1909, g_sum+1909, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(q_00+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, q_00+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+44, 8, q_00+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+40, 8, q_00+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+36, 8, q_00+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+32, 8, q_00+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+28, 8, q_00+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+24, 8, q_00+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+20, 8, q_00+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+16, 8, q_00+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+12, 8, q_00+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+8, 8, q_00+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+4, 8, q_00+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+0, 8, q_00+597+0, 8, temp);
	memset(q_01+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, q_01+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+44, 8, q_01+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+40, 8, q_01+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+36, 8, q_01+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+32, 8, q_01+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+28, 8, q_01+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+24, 8, q_01+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+20, 8, q_01+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+16, 8, q_01+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+12, 8, q_01+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+8, 8, q_01+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+4, 8, q_01+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+0, 8, q_01+597+0, 8, temp);
	memset(q_10+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, q_10+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+44, 8, q_10+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+40, 8, q_10+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+36, 8, q_10+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+32, 8, q_10+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+28, 8, q_10+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+24, 8, q_10+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+20, 8, q_10+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+16, 8, q_10+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+12, 8, q_10+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+8, 8, q_10+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+4, 8, q_10+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+0, 8, q_10+597+0, 8, temp);
	memset(q_11+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, q_11+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+44, 8, q_11+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+40, 8, q_11+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+36, 8, q_11+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+32, 8, q_11+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+28, 8, q_11+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+24, 8, q_11+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+20, 8, q_11+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+16, 8, q_11+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+12, 8, q_11+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+8, 8, q_11+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+4, 8, q_11+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+0, 8, q_11+597+0, 8, temp);
	

	// Recombining results: n: 13005, depth: 2
	memset(p_00+403, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_00+607+4, 100, q_00+597);
	GF2X_MUL(200, temp2, 100, p_10+607+4, 100, q_01+597);
	gf2x_add(200, p_00+403+4, 200, temp, 200, temp2);
	GF2X_MUL(8, temp, 4, q_00+597+96, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+96, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+96, 8, p_00+403+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+92, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+92, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+92, 8, p_00+403+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+88, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+88, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+88, 8, p_00+403+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+84, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+84, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+84, 8, p_00+403+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+80, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+80, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+80, 8, p_00+403+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+76, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+76, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+76, 8, p_00+403+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+72, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+72, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+72, 8, p_00+403+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+68, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+68, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+68, 8, p_00+403+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+64, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+64, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+64, 8, p_00+403+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+60, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+60, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+60, 8, p_00+403+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+56, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+56, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+56, 8, p_00+403+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+52, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+52, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+52, 8, p_00+403+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+48, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+48, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+48, 8, p_00+403+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+44, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+44, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+44, 8, p_00+403+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+40, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+40, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+40, 8, p_00+403+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+36, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+36, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+36, 8, p_00+403+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+32, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+32, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+32, 8, p_00+403+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+28, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+28, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+28, 8, p_00+403+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+24, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+24, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+24, 8, p_00+403+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+20, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+20, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+20, 8, p_00+403+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+16, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+16, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+16, 8, p_00+403+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+12, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+12, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+12, 8, p_00+403+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+8, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+8, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+8, 8, p_00+403+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+4, 8, p_00+403+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+597+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+403+0, 8, p_00+403+0, 8, temp);
	memset(p_01+403, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_01+607+4, 100, q_00+597);
	GF2X_MUL(200, temp2, 100, p_11+607+4, 100, q_01+597);
	gf2x_add(200, p_01+403+4, 200, temp, 200, temp2);
	GF2X_MUL(8, temp, 4, q_00+597+96, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+96, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+96, 8, p_01+403+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+92, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+92, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+92, 8, p_01+403+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+88, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+88, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+88, 8, p_01+403+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+84, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+84, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+84, 8, p_01+403+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+80, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+80, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+80, 8, p_01+403+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+76, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+76, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+76, 8, p_01+403+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+72, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+72, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+72, 8, p_01+403+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+68, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+68, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+68, 8, p_01+403+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+64, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+64, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+64, 8, p_01+403+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+60, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+60, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+60, 8, p_01+403+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+56, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+56, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+56, 8, p_01+403+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+52, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+52, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+52, 8, p_01+403+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+48, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+48, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+48, 8, p_01+403+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+44, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+44, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+44, 8, p_01+403+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+40, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+40, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+40, 8, p_01+403+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+36, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+36, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+36, 8, p_01+403+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+32, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+32, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+32, 8, p_01+403+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+28, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+28, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+28, 8, p_01+403+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+24, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+24, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+24, 8, p_01+403+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+20, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+20, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+20, 8, p_01+403+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+16, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+16, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+16, 8, p_01+403+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+12, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+12, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+12, 8, p_01+403+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+8, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+8, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+8, 8, p_01+403+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+4, 8, p_01+403+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+597+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+597+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+403+0, 8, p_01+403+0, 8, temp);
	memset(p_10+403, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_00+607+4, 100, q_10+597);
	GF2X_MUL(200, temp2, 100, p_10+607+4, 100, q_11+597);
	gf2x_add(200, p_10+403+4, 200, temp, 200, temp2);
	GF2X_MUL(8, temp, 4, q_10+597+96, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+96, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+96, 8, p_10+403+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+92, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+92, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+92, 8, p_10+403+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+88, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+88, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+88, 8, p_10+403+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+84, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+84, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+84, 8, p_10+403+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+80, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+80, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+80, 8, p_10+403+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+76, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+76, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+76, 8, p_10+403+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+72, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+72, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+72, 8, p_10+403+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+68, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+68, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+68, 8, p_10+403+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+64, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+64, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+64, 8, p_10+403+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+60, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+60, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+60, 8, p_10+403+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+56, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+56, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+56, 8, p_10+403+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+52, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+52, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+52, 8, p_10+403+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+48, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+48, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+48, 8, p_10+403+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+44, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+44, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+44, 8, p_10+403+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+40, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+40, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+40, 8, p_10+403+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+36, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+36, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+36, 8, p_10+403+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+32, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+32, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+32, 8, p_10+403+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+28, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+28, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+28, 8, p_10+403+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+24, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+24, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+24, 8, p_10+403+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+20, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+20, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+20, 8, p_10+403+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+16, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+16, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+16, 8, p_10+403+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+12, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+12, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+12, 8, p_10+403+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+8, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+8, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+8, 8, p_10+403+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+4, 8, p_10+403+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+597+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+403+0, 8, p_10+403+0, 8, temp);
	memset(p_11+403, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(200, temp, 100, p_01+607+4, 100, q_10+597);
	GF2X_MUL(200, temp2, 100, p_11+607+4, 100, q_11+597);
	gf2x_add(200, p_11+403+4, 200, temp, 200, temp2);
	GF2X_MUL(8, temp, 4, q_10+597+96, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+96, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+96, 8, p_11+403+96, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+92, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+92, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+92, 8, p_11+403+92, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+88, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+88, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+88, 8, p_11+403+88, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+84, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+84, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+84, 8, p_11+403+84, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+80, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+80, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+80, 8, p_11+403+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+76, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+76, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+76, 8, p_11+403+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+72, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+72, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+72, 8, p_11+403+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+68, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+68, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+68, 8, p_11+403+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+64, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+64, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+64, 8, p_11+403+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+60, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+60, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+60, 8, p_11+403+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+56, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+56, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+56, 8, p_11+403+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+52, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+52, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+52, 8, p_11+403+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+48, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+48, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+48, 8, p_11+403+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+44, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+44, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+44, 8, p_11+403+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+40, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+40, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+40, 8, p_11+403+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+36, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+36, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+36, 8, p_11+403+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+32, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+32, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+32, 8, p_11+403+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+28, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+28, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+28, 8, p_11+403+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+24, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+24, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+24, 8, p_11+403+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+20, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+20, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+20, 8, p_11+403+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+16, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+16, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+16, 8, p_11+403+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+12, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+12, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+12, 8, p_11+403+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+8, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+8, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+8, 8, p_11+403+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+4, 8, p_11+403+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+597+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+597+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+403+0, 8, p_11+403+0, 8, temp);
	

	// Calculating left operands: n: 25755, depth: 1
	// Digits to shift: 203
	// Displacement: 203
	GF2X_MUL(408, temp, 204, f+397+199, 204, p_00+403);
	GF2X_MUL(408, temp2, 204, g+397+199, 204, p_01+403);
	gf2x_add(404, f_sum+1204, 404, temp+4, 404, temp2+4);
	GF2X_MUL(398, temp, 199, p_00+403+5, 199, f+397);
	GF2X_MUL(398, temp2, 199, p_01+403+5, 199, g+397);
	gf2x_add(398, temp, 398, temp, 398, temp2);
	gf2x_add(200, f_sum+1204, 200, f_sum+1204, 200, temp+198);
	GF2X_MUL(10, temp, 5, f+397+194, 5, p_00+403);
	GF2X_MUL(10, temp2, 5, g+397+194, 5, p_01+403);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+1204, 1, f_sum+1204, 1, temp+9);
	right_bit_shift_n(403, f_sum+1204, 13);
	GF2X_MUL(408, temp, 204, f+397+199, 204, p_10+403);
	GF2X_MUL(408, temp2, 204, g+397+199, 204, p_11+403);
	gf2x_add(404, g_sum+1204, 404, temp+4, 404, temp2+4);
	GF2X_MUL(398, temp, 199, p_10+403+5, 199, f+397);
	GF2X_MUL(398, temp2, 199, p_11+403+5, 199, g+397);
	gf2x_add(398, temp, 398, temp, 398, temp2);
	gf2x_add(200, g_sum+1204, 200, g_sum+1204, 200, temp+198);
	GF2X_MUL(10, temp, 5, f+397+194, 5, p_10+403);
	GF2X_MUL(10, temp2, 5, g+397+194, 5, p_11+403);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+1204, 1, g_sum+1204, 1, temp+9);
	right_bit_shift_n(403, g_sum+1204, 13);
	

	delta = divstepsx_256(255, delta, f_sum+1401, g_sum+1401, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1397+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1397+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1397+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1397+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1397+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1397+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1397+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1397+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1389+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1389+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1389+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1389+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1389+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1389+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1389+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1389+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1377+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1377+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1377);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1377);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1377+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1377+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1377);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1377);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1353+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1353+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1353);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1353);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1353+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1353+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1353);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1353);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1305+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1305+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+1305);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+1305);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1305+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1305+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+1305);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+1305);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, p_00+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+44, 8, p_00+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+40, 8, p_00+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+36, 8, p_00+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+32, 8, p_00+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+28, 8, p_00+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+24, 8, p_00+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+20, 8, p_00+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+16, 8, p_00+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+12, 8, p_00+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+8, 8, p_00+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+4, 8, p_00+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, p_01+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+44, 8, p_01+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+40, 8, p_01+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+36, 8, p_01+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+32, 8, p_01+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+28, 8, p_01+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+24, 8, p_01+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+20, 8, p_01+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+16, 8, p_01+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+12, 8, p_01+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+8, 8, p_01+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+4, 8, p_01+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, p_10+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+44, 8, p_10+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+40, 8, p_10+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+36, 8, p_10+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+32, 8, p_10+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+28, 8, p_10+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+24, 8, p_10+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+20, 8, p_10+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+16, 8, p_10+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+12, 8, p_10+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+8, 8, p_10+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+4, 8, p_10+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, p_11+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+44, 8, p_11+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+40, 8, p_11+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+36, 8, p_11+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+32, 8, p_11+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+28, 8, p_11+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+24, 8, p_11+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+20, 8, p_11+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+16, 8, p_11+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+12, 8, p_11+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+8, 8, p_11+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+4, 8, p_11+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 12750, depth: 2
	// Digits to shift: 99
	// Displacement: 100
	GF2X_MUL(200, temp, 100, f_sum+1205+100, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+100, 100, p_01+607);
	gf2x_add(200, f_sum+1812+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, f_sum+1205+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+0, 100, p_01+607);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, f_sum+1812, 100, f_sum+1812, 100, temp+100);
	right_bit_shift_n(200, f_sum+1812, 39);
	GF2X_MUL(200, temp, 100, f_sum+1205+100, 100, p_10+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+100, 100, p_11+607);
	gf2x_add(200, g_sum+1812+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, f_sum+1205+0, 100, p_10+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+0, 100, p_11+607);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, g_sum+1812, 100, g_sum+1812, 100, temp+100);
	right_bit_shift_n(200, g_sum+1812, 39);
	

	delta = divstepsx_256(255, delta, f_sum+1909, g_sum+1909, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(q_00+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, q_00+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+44, 8, q_00+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+40, 8, q_00+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+36, 8, q_00+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+32, 8, q_00+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+28, 8, q_00+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+24, 8, q_00+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+20, 8, q_00+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+16, 8, q_00+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+12, 8, q_00+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+8, 8, q_00+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+4, 8, q_00+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+0, 8, q_00+597+0, 8, temp);
	memset(q_01+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, q_01+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+44, 8, q_01+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+40, 8, q_01+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+36, 8, q_01+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+32, 8, q_01+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+28, 8, q_01+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+24, 8, q_01+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+20, 8, q_01+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+16, 8, q_01+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+12, 8, q_01+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+8, 8, q_01+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+4, 8, q_01+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+0, 8, q_01+597+0, 8, temp);
	memset(q_10+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, q_10+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+44, 8, q_10+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+40, 8, q_10+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+36, 8, q_10+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+32, 8, q_10+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+28, 8, q_10+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+24, 8, q_10+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+20, 8, q_10+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+16, 8, q_10+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+12, 8, q_10+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+8, 8, q_10+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+4, 8, q_10+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+0, 8, q_10+597+0, 8, temp);
	memset(q_11+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, q_11+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+44, 8, q_11+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+40, 8, q_11+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+36, 8, q_11+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+32, 8, q_11+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+28, 8, q_11+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+24, 8, q_11+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+20, 8, q_11+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+16, 8, q_11+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+12, 8, q_11+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+8, 8, q_11+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+4, 8, q_11+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+0, 8, q_11+597+0, 8, temp);
	

	// Recombining results: n: 12750, depth: 2
	GF2X_MUL(200, temp, 100, q_00+597+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, q_01+597+0, 100, p_10+607);
	gf2x_add(200, q_00+397+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_00+597+0, 100, p_01+607);
	GF2X_MUL(200, temp2, 100, q_01+597+0, 100, p_11+607);
	gf2x_add(200, q_01+397+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_10+597+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, q_11+597+0, 100, p_10+607);
	gf2x_add(200, q_10+397+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_10+597+0, 100, p_01+607);
	GF2X_MUL(200, temp2, 100, q_11+597+0, 100, p_11+607);
	gf2x_add(200, q_11+397+0, 200, temp, 200, temp2);
	

	// Recombining results: n: 25755, depth: 1
	memset(p_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(400, temp, 200, p_00+403+4, 200, q_00+397);
	GF2X_MUL(400, temp2, 200, p_10+403+4, 200, q_01+397);
	gf2x_add(400, p_00+0+3, 400, temp, 400, temp2);
	GF2X_MUL(8, temp, 4, q_00+397+196, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+196, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+195, 8, p_00+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+192, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+192, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+191, 8, p_00+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+188, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+188, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+187, 8, p_00+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+184, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+184, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+183, 8, p_00+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+180, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+180, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+179, 8, p_00+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+176, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+176, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+175, 8, p_00+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+172, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+172, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+171, 8, p_00+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+168, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+168, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+167, 8, p_00+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+164, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+164, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+163, 8, p_00+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+160, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+160, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+159, 8, p_00+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+156, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+156, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+155, 8, p_00+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+152, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+152, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+151, 8, p_00+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+148, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+148, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+147, 8, p_00+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+144, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+144, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+143, 8, p_00+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+140, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+140, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+139, 8, p_00+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+136, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+136, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+135, 8, p_00+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+132, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+132, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+131, 8, p_00+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+128, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+128, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+127, 8, p_00+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+124, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+124, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+123, 8, p_00+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+120, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+120, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+119, 8, p_00+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+116, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+116, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+115, 8, p_00+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+112, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+112, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+111, 8, p_00+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+108, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+108, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+107, 8, p_00+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+104, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+104, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+103, 8, p_00+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+100, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+100, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+99, 8, p_00+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+96, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+96, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+95, 8, p_00+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+92, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+92, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+91, 8, p_00+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+88, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+88, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+87, 8, p_00+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+84, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+84, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+83, 8, p_00+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+80, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+80, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+79, 8, p_00+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+76, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+76, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+75, 8, p_00+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+72, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+72, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+71, 8, p_00+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+68, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+68, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+67, 8, p_00+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+64, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+64, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+63, 8, p_00+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+60, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+60, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+59, 8, p_00+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+56, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+56, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+55, 8, p_00+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+52, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+52, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+51, 8, p_00+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+48, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+48, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+47, 8, p_00+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+44, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+44, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+43, 8, p_00+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+40, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+40, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+39, 8, p_00+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+36, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+36, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+35, 8, p_00+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+32, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+32, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+31, 8, p_00+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+28, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+28, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+27, 8, p_00+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+24, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+24, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+23, 8, p_00+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+20, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+20, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+19, 8, p_00+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+16, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+16, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+15, 8, p_00+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+12, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+12, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+11, 8, p_00+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+8, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+8, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+7, 8, p_00+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+4, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+4, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+3, 8, p_00+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+0, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_01+397+0, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_00+0, 7, p_00+0, 7, temp+1);
	memset(p_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(400, temp, 200, p_01+403+4, 200, q_00+397);
	GF2X_MUL(400, temp2, 200, p_11+403+4, 200, q_01+397);
	gf2x_add(400, p_01+0+3, 400, temp, 400, temp2);
	GF2X_MUL(8, temp, 4, q_00+397+196, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+196, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+195, 8, p_01+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+192, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+192, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+191, 8, p_01+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+188, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+188, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+187, 8, p_01+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+184, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+184, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+183, 8, p_01+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+180, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+180, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+179, 8, p_01+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+176, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+176, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+175, 8, p_01+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+172, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+172, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+171, 8, p_01+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+168, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+168, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+167, 8, p_01+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+164, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+164, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+163, 8, p_01+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+160, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+160, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+159, 8, p_01+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+156, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+156, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+155, 8, p_01+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+152, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+152, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+151, 8, p_01+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+148, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+148, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+147, 8, p_01+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+144, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+144, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+143, 8, p_01+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+140, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+140, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+139, 8, p_01+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+136, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+136, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+135, 8, p_01+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+132, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+132, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+131, 8, p_01+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+128, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+128, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+127, 8, p_01+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+124, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+124, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+123, 8, p_01+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+120, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+120, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+119, 8, p_01+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+116, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+116, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+115, 8, p_01+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+112, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+112, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+111, 8, p_01+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+108, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+108, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+107, 8, p_01+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+104, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+104, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+103, 8, p_01+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+100, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+100, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+99, 8, p_01+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+96, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+96, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+95, 8, p_01+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+92, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+92, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+91, 8, p_01+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+88, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+88, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+87, 8, p_01+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+84, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+84, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+83, 8, p_01+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+80, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+80, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+79, 8, p_01+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+76, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+76, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+75, 8, p_01+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+72, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+72, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+71, 8, p_01+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+68, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+68, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+67, 8, p_01+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+64, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+64, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+63, 8, p_01+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+60, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+60, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+59, 8, p_01+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+56, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+56, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+55, 8, p_01+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+52, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+52, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+51, 8, p_01+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+48, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+48, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+47, 8, p_01+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+44, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+44, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+43, 8, p_01+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+40, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+40, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+39, 8, p_01+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+36, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+36, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+35, 8, p_01+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+32, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+32, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+31, 8, p_01+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+28, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+28, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+27, 8, p_01+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+24, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+24, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+23, 8, p_01+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+20, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+20, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+19, 8, p_01+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+16, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+16, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+15, 8, p_01+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+12, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+12, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+11, 8, p_01+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+8, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+8, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+7, 8, p_01+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+4, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+4, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+3, 8, p_01+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+397+0, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_01+397+0, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_01+0, 7, p_01+0, 7, temp+1);
	memset(p_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(400, temp, 200, p_00+403+4, 200, q_10+397);
	GF2X_MUL(400, temp2, 200, p_10+403+4, 200, q_11+397);
	gf2x_add(400, p_10+0+3, 400, temp, 400, temp2);
	GF2X_MUL(8, temp, 4, q_10+397+196, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+196, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+195, 8, p_10+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+192, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+192, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+191, 8, p_10+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+188, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+188, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+187, 8, p_10+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+184, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+184, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+183, 8, p_10+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+180, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+180, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+179, 8, p_10+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+176, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+176, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+175, 8, p_10+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+172, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+172, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+171, 8, p_10+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+168, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+168, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+167, 8, p_10+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+164, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+164, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+163, 8, p_10+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+160, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+160, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+159, 8, p_10+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+156, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+156, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+155, 8, p_10+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+152, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+152, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+151, 8, p_10+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+148, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+148, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+147, 8, p_10+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+144, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+144, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+143, 8, p_10+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+140, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+140, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+139, 8, p_10+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+136, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+136, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+135, 8, p_10+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+132, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+132, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+131, 8, p_10+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+128, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+128, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+127, 8, p_10+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+124, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+124, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+123, 8, p_10+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+120, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+120, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+119, 8, p_10+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+116, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+116, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+115, 8, p_10+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+112, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+112, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+111, 8, p_10+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+108, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+108, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+107, 8, p_10+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+104, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+104, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+103, 8, p_10+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+100, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+100, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+99, 8, p_10+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+96, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+96, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+95, 8, p_10+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+92, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+92, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+91, 8, p_10+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+88, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+88, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+87, 8, p_10+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+84, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+84, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+83, 8, p_10+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+80, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+80, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+79, 8, p_10+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+76, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+76, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+75, 8, p_10+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+72, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+72, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+71, 8, p_10+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+68, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+68, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+67, 8, p_10+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+64, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+64, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+63, 8, p_10+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+60, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+60, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+59, 8, p_10+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+56, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+56, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+55, 8, p_10+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+52, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+52, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+51, 8, p_10+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+48, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+48, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+47, 8, p_10+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+44, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+44, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+43, 8, p_10+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+40, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+40, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+39, 8, p_10+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+36, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+36, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+35, 8, p_10+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+32, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+32, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+31, 8, p_10+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+28, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+28, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+27, 8, p_10+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+24, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+24, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+23, 8, p_10+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+20, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+20, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+19, 8, p_10+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+16, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+16, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+15, 8, p_10+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+12, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+12, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+11, 8, p_10+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+8, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+8, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+7, 8, p_10+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+4, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+4, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+3, 8, p_10+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+0, 4, p_00+403);
	GF2X_MUL(8, temp2, 4, q_11+397+0, 4, p_10+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_10+0, 7, p_10+0, 7, temp+1);
	memset(p_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(400, temp, 200, p_01+403+4, 200, q_10+397);
	GF2X_MUL(400, temp2, 200, p_11+403+4, 200, q_11+397);
	gf2x_add(400, p_11+0+3, 400, temp, 400, temp2);
	GF2X_MUL(8, temp, 4, q_10+397+196, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+196, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+195, 8, p_11+0+195, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+192, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+192, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+191, 8, p_11+0+191, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+188, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+188, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+187, 8, p_11+0+187, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+184, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+184, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+183, 8, p_11+0+183, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+180, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+180, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+179, 8, p_11+0+179, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+176, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+176, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+175, 8, p_11+0+175, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+172, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+172, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+171, 8, p_11+0+171, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+168, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+168, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+167, 8, p_11+0+167, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+164, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+164, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+163, 8, p_11+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+160, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+160, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+159, 8, p_11+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+156, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+156, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+155, 8, p_11+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+152, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+152, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+151, 8, p_11+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+148, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+148, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+147, 8, p_11+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+144, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+144, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+143, 8, p_11+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+140, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+140, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+139, 8, p_11+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+136, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+136, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+135, 8, p_11+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+132, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+132, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+131, 8, p_11+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+128, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+128, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+127, 8, p_11+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+124, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+124, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+123, 8, p_11+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+120, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+120, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+119, 8, p_11+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+116, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+116, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+115, 8, p_11+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+112, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+112, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+111, 8, p_11+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+108, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+108, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+107, 8, p_11+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+104, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+104, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+103, 8, p_11+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+100, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+100, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+99, 8, p_11+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+96, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+96, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+95, 8, p_11+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+92, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+92, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+91, 8, p_11+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+88, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+88, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+87, 8, p_11+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+84, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+84, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+83, 8, p_11+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+80, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+80, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+79, 8, p_11+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+76, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+76, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+75, 8, p_11+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+72, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+72, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+71, 8, p_11+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+68, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+68, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+67, 8, p_11+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+64, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+64, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+63, 8, p_11+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+60, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+60, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+59, 8, p_11+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+56, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+56, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+55, 8, p_11+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+52, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+52, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+51, 8, p_11+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+48, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+48, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+47, 8, p_11+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+44, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+44, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+43, 8, p_11+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+40, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+40, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+39, 8, p_11+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+36, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+36, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+35, 8, p_11+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+32, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+32, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+31, 8, p_11+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+28, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+28, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+27, 8, p_11+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+24, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+24, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+23, 8, p_11+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+20, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+20, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+19, 8, p_11+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+16, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+16, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+15, 8, p_11+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+12, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+12, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+11, 8, p_11+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+8, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+8, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+7, 8, p_11+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+4, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+4, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+3, 8, p_11+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+397+0, 4, p_01+403);
	GF2X_MUL(8, temp2, 4, q_11+397+0, 4, p_11+403);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_11+0, 7, p_11+0, 7, temp+1);
	

	// Calculating left operands: n: 51157, depth: 0
	// Digits to shift: 402
	// Displacement: 403
	GF2X_MUL(806, temp, 403, f+0+397, 403, p_00+0);
	GF2X_MUL(806, temp2, 403, g+0+397, 403, p_01+0);
	gf2x_add(800, f_sum+0, 800, temp+6, 800, temp2+6);
	GF2X_MUL(794, temp, 397, p_00+0+6, 397, f+0);
	GF2X_MUL(794, temp2, 397, p_01+0+6, 397, g+0);
	gf2x_add(794, temp, 794, temp, 794, temp2);
	gf2x_add(397, f_sum+0, 397, f_sum+0, 397, temp+397);
	right_bit_shift_n(800, f_sum+0, 27);
	GF2X_MUL(806, temp, 403, f+0+397, 403, p_10+0);
	GF2X_MUL(806, temp2, 403, g+0+397, 403, p_11+0);
	gf2x_add(800, g_sum+0, 800, temp+6, 800, temp2+6);
	GF2X_MUL(794, temp, 397, p_10+0+6, 397, f+0);
	GF2X_MUL(794, temp2, 397, p_11+0+6, 397, g+0);
	gf2x_add(794, temp, 794, temp, 794, temp2);
	gf2x_add(397, g_sum+0, 397, g_sum+0, 397, temp+397);
	right_bit_shift_n(800, g_sum+0, 27);
	

	delta = divstepsx_256(255, delta, f_sum+394, g_sum+394, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+390+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+390+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+390+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+390+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+390+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+390+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+390+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+390+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+382+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+382+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+382+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+382+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+382+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+382+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+382+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+382+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+370+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+370+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+370);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+370);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+370+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+370+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+370);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+370);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+346+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+346+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+346);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+346);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+346+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+346+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+346);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+346);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+298+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+298+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+298);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+298);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+298+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+298+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+298);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+298);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, p_00+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+44, 8, p_00+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+40, 8, p_00+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+36, 8, p_00+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+32, 8, p_00+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+28, 8, p_00+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+24, 8, p_00+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+20, 8, p_00+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+16, 8, p_00+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+12, 8, p_00+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+8, 8, p_00+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+4, 8, p_00+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, p_01+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+44, 8, p_01+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+40, 8, p_01+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+36, 8, p_01+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+32, 8, p_01+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+28, 8, p_01+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+24, 8, p_01+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+20, 8, p_01+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+16, 8, p_01+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+12, 8, p_01+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+8, 8, p_01+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+4, 8, p_01+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, p_10+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+44, 8, p_10+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+40, 8, p_10+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+36, 8, p_10+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+32, 8, p_10+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+28, 8, p_10+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+24, 8, p_10+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+20, 8, p_10+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+16, 8, p_10+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+12, 8, p_10+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+8, 8, p_10+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+4, 8, p_10+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, p_11+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+44, 8, p_11+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+40, 8, p_11+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+36, 8, p_11+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+32, 8, p_11+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+28, 8, p_11+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+24, 8, p_11+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+20, 8, p_11+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+16, 8, p_11+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+12, 8, p_11+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+8, 8, p_11+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+4, 8, p_11+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 12750, depth: 2
	// Digits to shift: 99
	// Displacement: 100
	GF2X_MUL(200, temp, 100, f_sum+198+100, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, g_sum+198+100, 100, p_01+607);
	gf2x_add(200, f_sum+1812+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, f_sum+198+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, g_sum+198+0, 100, p_01+607);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, f_sum+1812, 100, f_sum+1812, 100, temp+100);
	right_bit_shift_n(200, f_sum+1812, 39);
	GF2X_MUL(200, temp, 100, f_sum+198+100, 100, p_10+607);
	GF2X_MUL(200, temp2, 100, g_sum+198+100, 100, p_11+607);
	gf2x_add(200, g_sum+1812+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, f_sum+198+0, 100, p_10+607);
	GF2X_MUL(200, temp2, 100, g_sum+198+0, 100, p_11+607);
	gf2x_add(200, temp, 200, temp, 200, temp2);
	gf2x_add(100, g_sum+1812, 100, g_sum+1812, 100, temp+100);
	right_bit_shift_n(200, g_sum+1812, 39);
	

	delta = divstepsx_256(255, delta, f_sum+1909, g_sum+1909, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1905+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1905+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1905+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1897+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1897+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1897+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1885+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1885+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1885);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1885);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1861+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1861+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1861);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1861);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1813+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+1813);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+1813);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(q_00+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, q_00+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+44, 8, q_00+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+40, 8, q_00+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+36, 8, q_00+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+32, 8, q_00+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+28, 8, q_00+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+24, 8, q_00+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+20, 8, q_00+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+16, 8, q_00+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+12, 8, q_00+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+8, 8, q_00+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+4, 8, q_00+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+597+0, 8, q_00+597+0, 8, temp);
	memset(q_01+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, q_01+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+44, 8, q_01+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+40, 8, q_01+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+36, 8, q_01+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+32, 8, q_01+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+28, 8, q_01+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+24, 8, q_01+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+20, 8, q_01+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+16, 8, q_01+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+12, 8, q_01+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+8, 8, q_01+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+4, 8, q_01+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+597+0, 8, q_01+597+0, 8, temp);
	memset(q_10+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, q_10+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+44, 8, q_10+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+40, 8, q_10+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+36, 8, q_10+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+32, 8, q_10+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+28, 8, q_10+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+24, 8, q_10+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+20, 8, q_10+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+16, 8, q_10+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+12, 8, q_10+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+8, 8, q_10+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+4, 8, q_10+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+597+0, 8, q_10+597+0, 8, temp);
	memset(q_11+597, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, q_11+597+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+44, 8, q_11+597+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+40, 8, q_11+597+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+36, 8, q_11+597+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+32, 8, q_11+597+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+28, 8, q_11+597+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+24, 8, q_11+597+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+20, 8, q_11+597+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+16, 8, q_11+597+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+12, 8, q_11+597+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+8, 8, q_11+597+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+4, 8, q_11+597+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+597+0, 8, q_11+597+0, 8, temp);
	

	// Recombining results: n: 12750, depth: 2
	GF2X_MUL(200, temp, 100, q_00+597+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, q_01+597+0, 100, p_10+607);
	gf2x_add(200, p_00+403+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_00+597+0, 100, p_01+607);
	GF2X_MUL(200, temp2, 100, q_01+597+0, 100, p_11+607);
	gf2x_add(200, p_01+403+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_10+597+0, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, q_11+597+0, 100, p_10+607);
	gf2x_add(200, p_10+403+0, 200, temp, 200, temp2);
	GF2X_MUL(200, temp, 100, q_10+597+0, 100, p_01+607);
	GF2X_MUL(200, temp2, 100, q_11+597+0, 100, p_11+607);
	gf2x_add(200, p_11+403+0, 200, temp, 200, temp2);
	

	// Calculating left operands: n: 25402, depth: 1
	// Digits to shift: 199
	// Displacement: 199
	GF2X_MUL(400, temp, 200, f_sum+1+197, 200, p_00+403);
	GF2X_MUL(400, temp2, 200, g_sum+1+197, 200, p_01+403);
	gf2x_add(398, f_sum+1204, 398, temp+2, 398, temp2+2);
	GF2X_MUL(394, temp, 197, p_00+403+3, 197, f_sum+1);
	GF2X_MUL(394, temp2, 197, p_01+403+3, 197, g_sum+1);
	gf2x_add(394, temp, 394, temp, 394, temp2);
	gf2x_add(198, f_sum+1204, 198, f_sum+1204, 198, temp+196);
	GF2X_MUL(6, temp, 3, f_sum+1+194, 3, p_00+403);
	GF2X_MUL(6, temp2, 3, g_sum+1+194, 3, p_01+403);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+1204, 1, f_sum+1204, 1, temp+5);
	right_bit_shift_n(397, f_sum+1204, 14);
	GF2X_MUL(400, temp, 200, f_sum+1+197, 200, p_10+403);
	GF2X_MUL(400, temp2, 200, g_sum+1+197, 200, p_11+403);
	gf2x_add(398, g_sum+1204, 398, temp+2, 398, temp2+2);
	GF2X_MUL(394, temp, 197, p_10+403+3, 197, f_sum+1);
	GF2X_MUL(394, temp2, 197, p_11+403+3, 197, g_sum+1);
	gf2x_add(394, temp, 394, temp, 394, temp2);
	gf2x_add(198, g_sum+1204, 198, g_sum+1204, 198, temp+196);
	GF2X_MUL(6, temp, 3, f_sum+1+194, 3, p_10+403);
	GF2X_MUL(6, temp2, 3, g_sum+1+194, 3, p_11+403);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+1204, 1, g_sum+1204, 1, temp+5);
	right_bit_shift_n(397, g_sum+1204, 14);
	

	delta = divstepsx_256(255, delta, f_sum+1399, g_sum+1399, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1395+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1395+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1395+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1395+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1395+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1395+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1395+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1395+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1387+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1387+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1387+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1387+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1387+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1387+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1387+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1387+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1375+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1375+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1375);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1375);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1375+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1375+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1375);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1375);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1351+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1351+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1351);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1351);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1351+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1351+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1351);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1351);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6375, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1303+48, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1303+48, 52, p_01+711);
	gf2x_add(100, f_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, f_sum+1303);
	GF2X_MUL(96, temp2, 48, p_01+711+4, 48, g_sum+1303);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, f_sum+2121, 48, f_sum+2121, 48, temp+48);
	right_bit_shift_n(100, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1303+48, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1303+48, 52, p_11+711);
	gf2x_add(100, g_sum+2121, 100, temp+4, 100, temp2+4);
	GF2X_MUL(96, temp, 48, p_10+711+4, 48, f_sum+1303);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, g_sum+1303);
	gf2x_add(96, temp, 96, temp, 96, temp2);
	gf2x_add(48, g_sum+2121, 48, g_sum+2121, 48, temp+48);
	right_bit_shift_n(100, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2166, g_sum+2166, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2162+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2162+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2162+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2158+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2158+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2158);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2158);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2146+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2146+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2146+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_01+763);
	gf2x_add(48, f_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_01+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(48, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+24, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+24, 24, p_11+763);
	gf2x_add(48, g_sum+2278+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+2122+0, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+0, 24, p_11+763);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(48, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_10+763);
	gf2x_add(48, q_00+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_01+749+0, 24, p_11+763);
	gf2x_add(48, q_01+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_10+763);
	gf2x_add(48, q_10+697+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+749+0, 24, p_01+763);
	GF2X_MUL(48, temp2, 24, q_11+749+0, 24, p_11+763);
	gf2x_add(48, q_11+697+0, 48, temp, 48, temp2);
	

	// Recombining results: n: 6375, depth: 3
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_01+697);
	gf2x_add(96, p_00+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+44, 8, p_00+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+40, 8, p_00+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+36, 8, p_00+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+32, 8, p_00+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+28, 8, p_00+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+24, 8, p_00+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+20, 8, p_00+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+16, 8, p_00+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+12, 8, p_00+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+8, 8, p_00+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+4, 8, p_00+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_00+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_01+697);
	gf2x_add(96, p_01+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_00+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+44, 8, p_01+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+40, 8, p_01+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+36, 8, p_01+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+32, 8, p_01+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+28, 8, p_01+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+24, 8, p_01+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+20, 8, p_01+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+16, 8, p_01+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+12, 8, p_01+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+8, 8, p_01+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+4, 8, p_01+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_01+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_00+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_10+711+4, 48, q_11+697);
	gf2x_add(96, p_10+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+44, 8, p_10+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+40, 8, p_10+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+36, 8, p_10+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+32, 8, p_10+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+28, 8, p_10+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+24, 8, p_10+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+20, 8, p_10+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+16, 8, p_10+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+12, 8, p_10+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+8, 8, p_10+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+4, 8, p_10+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_00+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_10+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(96, temp, 48, p_01+711+4, 48, q_10+697);
	GF2X_MUL(96, temp2, 48, p_11+711+4, 48, q_11+697);
	gf2x_add(96, p_11+607+4, 96, temp, 96, temp2);
	GF2X_MUL(8, temp, 4, q_10+697+44, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+44, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+44, 8, p_11+607+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+40, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+40, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+40, 8, p_11+607+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+36, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+36, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+36, 8, p_11+607+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+32, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+32, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+32, 8, p_11+607+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+28, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+28, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+28, 8, p_11+607+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+24, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+24, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+24, 8, p_11+607+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+20, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+20, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+20, 8, p_11+607+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+16, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+16, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+16, 8, p_11+607+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+12, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+12, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+12, 8, p_11+607+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+8, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+8, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+8, 8, p_11+607+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+4, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+4, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+4, 8, p_11+607+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+697+0, 4, p_01+711);
	GF2X_MUL(8, temp2, 4, q_11+697+0, 4, p_11+711);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 12652, depth: 2
	// Digits to shift: 99
	// Displacement: 99
	GF2X_MUL(200, temp, 100, f_sum+1205+98, 100, p_00+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+98, 100, p_01+607);
	gf2x_add(199, f_sum+1812, 199, temp+1, 199, temp2+1);
	GF2X_MUL(196, temp, 98, p_00+607+2, 98, f_sum+1205);
	GF2X_MUL(196, temp2, 98, p_01+607+2, 98, g_sum+1205);
	gf2x_add(196, temp, 196, temp, 196, temp2);
	gf2x_add(99, f_sum+1812, 99, f_sum+1812, 99, temp+97);
	GF2X_MUL(4, temp, 2, f_sum+1205+96, 2, p_00+607);
	GF2X_MUL(4, temp2, 2, g_sum+1205+96, 2, p_01+607);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, f_sum+1812, 1, f_sum+1812, 1, temp+3);
	right_bit_shift_n(198, f_sum+1812, 39);
	GF2X_MUL(200, temp, 100, f_sum+1205+98, 100, p_10+607);
	GF2X_MUL(200, temp2, 100, g_sum+1205+98, 100, p_11+607);
	gf2x_add(199, g_sum+1812, 199, temp+1, 199, temp2+1);
	GF2X_MUL(196, temp, 98, p_10+607+2, 98, f_sum+1205);
	GF2X_MUL(196, temp2, 98, p_11+607+2, 98, g_sum+1205);
	gf2x_add(196, temp, 196, temp, 196, temp2);
	gf2x_add(99, g_sum+1812, 99, g_sum+1812, 99, temp+97);
	GF2X_MUL(4, temp, 2, f_sum+1205+96, 2, p_10+607);
	GF2X_MUL(4, temp2, 2, g_sum+1205+96, 2, p_11+607);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, g_sum+1812, 1, g_sum+1812, 1, temp+3);
	right_bit_shift_n(198, g_sum+1812, 39);
	

	delta = divstepsx_256(255, delta, f_sum+1908, g_sum+1908, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1904+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1904+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1904+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+1904+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+1904+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1904+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1904+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+1904+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1896+8, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1896+8, 8, p_01+807);
	gf2x_add(16, f_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1896+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+1896+0, 8, p_01+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2404, 8, f_sum+2404, 8, temp+8);
	right_bit_shift_n(16, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+1896+8, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1896+8, 8, p_11+807);
	gf2x_add(16, g_sum+2404+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1896+0, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+1896+0, 8, p_11+807);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2404, 8, g_sum+2404, 8, temp+8);
	right_bit_shift_n(16, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2409, g_sum+2409, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2405+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2405+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2405+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, q_00+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, q_01+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, q_10+785+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, q_11+785+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 6
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_10+807);
	gf2x_add(16, p_00+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_01+785+0, 8, p_11+807);
	gf2x_add(16, p_01+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_10+807);
	gf2x_add(16, p_10+791+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+785+0, 8, p_01+807);
	GF2X_MUL(16, temp2, 8, q_11+785+0, 8, p_11+807);
	gf2x_add(16, p_11+791+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1785, depth: 5
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1884+12, 16, p_00+791);
	GF2X_MUL(32, temp2, 16, g_sum+1884+12, 16, p_01+791);
	gf2x_add(28, f_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, f_sum+1884);
	GF2X_MUL(24, temp2, 12, p_01+791+4, 12, g_sum+1884);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(28, f_sum+2359, 60);
	GF2X_MUL(32, temp, 16, f_sum+1884+12, 16, p_10+791);
	GF2X_MUL(32, temp2, 16, g_sum+1884+12, 16, p_11+791);
	gf2x_add(28, g_sum+2359, 28, temp+4, 28, temp2+4);
	GF2X_MUL(24, temp, 12, p_10+791+4, 12, f_sum+1884);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, g_sum+1884);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(28, g_sum+2359, 60);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1785, depth: 5
	memset(p_00+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_01+773);
	gf2x_add(24, p_00+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+8, 8, p_00+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+4, 8, p_00+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+763+0, 8, p_00+763+0, 8, temp);
	memset(p_01+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_00+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_01+773);
	gf2x_add(24, p_01+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_00+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+8, 8, p_01+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+4, 8, p_01+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_01+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+763+0, 8, p_01+763+0, 8, temp);
	memset(p_10+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_00+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_10+791+4, 12, q_11+773);
	gf2x_add(24, p_10+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+8, 8, p_10+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+4, 8, p_10+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_00+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_10+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+763+0, 8, p_10+763+0, 8, temp);
	memset(p_11+763, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(24, temp, 12, p_01+791+4, 12, q_10+773);
	GF2X_MUL(24, temp2, 12, p_11+791+4, 12, q_11+773);
	gf2x_add(24, p_11+763+4, 24, temp, 24, temp2);
	GF2X_MUL(8, temp, 4, q_10+773+8, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+8, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+8, 8, p_11+763+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+4, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+4, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+4, 8, p_11+763+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+773+0, 4, p_01+791);
	GF2X_MUL(8, temp2, 4, q_11+773+0, 4, p_11+791);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+763+0, 8, p_11+763+0, 8, temp);
	

	// Calculating left operands: n: 3315, depth: 4
	// Digits to shift: 27
	// Displacement: 28
	GF2X_MUL(56, temp, 28, f_sum+1860+24, 28, p_00+763);
	GF2X_MUL(56, temp2, 28, g_sum+1860+24, 28, p_01+763);
	gf2x_add(52, f_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, f_sum+1860);
	GF2X_MUL(48, temp2, 24, p_01+763+4, 24, g_sum+1860);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2278, 24, f_sum+2278, 24, temp+24);
	right_bit_shift_n(52, f_sum+2278, 57);
	GF2X_MUL(56, temp, 28, f_sum+1860+24, 28, p_10+763);
	GF2X_MUL(56, temp2, 28, g_sum+1860+24, 28, p_11+763);
	gf2x_add(52, g_sum+2278, 52, temp+4, 52, temp2+4);
	GF2X_MUL(48, temp, 24, p_10+763+4, 24, f_sum+1860);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, g_sum+1860);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2278, 24, g_sum+2278, 24, temp+24);
	right_bit_shift_n(52, g_sum+2278, 57);
	

	delta = divstepsx_256(255, delta, f_sum+2299, g_sum+2299, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2295+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2295+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2295+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2291+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2291+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2291);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2291);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2279+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, q_00+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, q_01+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, q_10+749+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, q_11+749+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3315, depth: 4
	memset(p_00+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_01+749);
	gf2x_add(48, p_00+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+20, 8, p_00+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+16, 8, p_00+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+12, 8, p_00+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+8, 8, p_00+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+4, 8, p_00+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+711+0, 8, p_00+711+0, 8, temp);
	memset(p_01+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_00+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_01+749);
	gf2x_add(48, p_01+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_00+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+20, 8, p_01+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+16, 8, p_01+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+12, 8, p_01+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+8, 8, p_01+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+4, 8, p_01+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_01+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+711+0, 8, p_01+711+0, 8, temp);
	memset(p_10+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_10+763+4, 24, q_11+749);
	gf2x_add(48, p_10+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+20, 8, p_10+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+16, 8, p_10+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+12, 8, p_10+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+8, 8, p_10+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+4, 8, p_10+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_00+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_10+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+711+0, 8, p_10+711+0, 8, temp);
	memset(p_11+711, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+763+4, 24, q_10+749);
	GF2X_MUL(48, temp2, 24, p_11+763+4, 24, q_11+749);
	gf2x_add(48, p_11+711+4, 48, temp, 48, temp2);
	GF2X_MUL(8, temp, 4, q_10+749+20, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+20, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+20, 8, p_11+711+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+16, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+16, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+16, 8, p_11+711+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+12, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+12, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+12, 8, p_11+711+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+8, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+8, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+8, 8, p_11+711+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+4, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+4, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+4, 8, p_11+711+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+749+0, 4, p_01+763);
	GF2X_MUL(8, temp2, 4, q_11+749+0, 4, p_11+763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+711+0, 8, p_11+711+0, 8, temp);
	

	// Calculating left operands: n: 6277, depth: 3
	// Digits to shift: 51
	// Displacement: 52
	GF2X_MUL(104, temp, 52, f_sum+1813+47, 52, p_00+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+47, 52, p_01+711);
	gf2x_add(99, f_sum+2121, 99, temp+5, 99, temp2+5);
	GF2X_MUL(94, temp, 47, p_00+711+5, 47, f_sum+1813);
	GF2X_MUL(94, temp2, 47, p_01+711+5, 47, g_sum+1813);
	gf2x_add(94, temp, 94, temp, 94, temp2);
	gf2x_add(47, f_sum+2121, 47, f_sum+2121, 47, temp+47);
	right_bit_shift_n(99, f_sum+2121, 51);
	GF2X_MUL(104, temp, 52, f_sum+1813+47, 52, p_10+711);
	GF2X_MUL(104, temp2, 52, g_sum+1813+47, 52, p_11+711);
	gf2x_add(99, g_sum+2121, 99, temp+5, 99, temp2+5);
	GF2X_MUL(94, temp, 47, p_10+711+5, 47, f_sum+1813);
	GF2X_MUL(94, temp2, 47, p_11+711+5, 47, g_sum+1813);
	gf2x_add(94, temp, 94, temp, 94, temp2);
	gf2x_add(47, g_sum+2121, 47, g_sum+2121, 47, temp+47);
	right_bit_shift_n(99, g_sum+2121, 51);
	

	delta = divstepsx_256(255, delta, f_sum+2165, g_sum+2165, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2161+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2161+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2161+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2161+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2161+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2161+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2161+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2161+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2157+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2157+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2157);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2157);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2157+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2157+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2157);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2157);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2145+12, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2145+12, 12, p_01+791);
	gf2x_add(24, f_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2145+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2145+0, 12, p_01+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2359, 12, f_sum+2359, 12, temp+12);
	right_bit_shift_n(24, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2145+12, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2145+12, 12, p_11+791);
	gf2x_add(24, g_sum+2359+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2145+0, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2145+0, 12, p_11+791);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2359, 12, g_sum+2359, 12, temp+12);
	right_bit_shift_n(24, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2368, g_sum+2368, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2364+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2364+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2364+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2360);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2360);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(q_00+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, q_00+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+773+0, 8, q_00+773+0, 8, temp);
	memset(q_01+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, q_01+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+773+0, 8, q_01+773+0, 8, temp);
	memset(q_10+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, q_10+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+773+0, 8, q_10+773+0, 8, temp);
	memset(q_11+773, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, q_11+773+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+773+0, 8, q_11+773+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_10+791);
	gf2x_add(24, p_00+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_01+773+0, 12, p_11+791);
	gf2x_add(24, p_01+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_10+791);
	gf2x_add(24, p_10+763+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+773+0, 12, p_01+791);
	GF2X_MUL(24, temp2, 12, q_11+773+0, 12, p_11+791);
	gf2x_add(24, p_11+763+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2962, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+2122+23, 24, p_00+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+23, 24, p_01+763);
	gf2x_add(47, f_sum+2278, 47, temp+1, 47, temp2+1);
	GF2X_MUL(46, temp, 23, p_00+763+1, 23, f_sum+2122);
	GF2X_MUL(46, temp2, 23, p_01+763+1, 23, g_sum+2122);
	gf2x_add(46, temp, 46, temp, 46, temp2);
	gf2x_add(23, f_sum+2278, 23, f_sum+2278, 23, temp+23);
	right_bit_shift_n(47, f_sum+2278, 58);
	GF2X_MUL(48, temp, 24, f_sum+2122+23, 24, p_10+763);
	GF2X_MUL(48, temp2, 24, g_sum+2122+23, 24, p_11+763);
	gf2x_add(47, g_sum+2278, 47, temp+1, 47, temp2+1);
	GF2X_MUL(46, temp, 23, p_10+763+1, 23, f_sum+2122);
	GF2X_MUL(46, temp2, 23, p_11+763+1, 23, g_sum+2122);
	gf2x_add(46, temp, 46, temp, 46, temp2);
	gf2x_add(23, g_sum+2278, 23, g_sum+2278, 23, temp+23);
	right_bit_shift_n(47, g_sum+2278, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2298, g_sum+2298, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2294+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2294+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2294+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2294+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2294+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2294+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2294+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2294+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2290+4, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2290+4, 8, p_01+807);
	gf2x_add(12, f_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, f_sum+2290);
	GF2X_MUL(8, temp2, 4, p_01+807+4, 4, g_sum+2290);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2404, 4, f_sum+2404, 4, temp+4);
	right_bit_shift_n(12, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2290+4, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2290+4, 8, p_11+807);
	gf2x_add(12, g_sum+2404, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+807+4, 4, f_sum+2290);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, g_sum+2290);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2404, 4, g_sum+2404, 4, temp+4);
	right_bit_shift_n(12, g_sum+2404, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785);

	// Recombining results: n: 765, depth: 6
	memset(p_00+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_01+785);
	gf2x_add(8, p_00+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+791+0, 8, p_00+791+0, 8, temp);
	memset(p_01+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_00+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_01+785);
	gf2x_add(8, p_01+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_01+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+791+0, 8, p_01+791+0, 8, temp);
	memset(p_10+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_10+807+4, 4, q_11+785);
	gf2x_add(8, p_10+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_00+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_10+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+791+0, 8, p_10+791+0, 8, temp);
	memset(p_11+791, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+807+4, 4, q_10+785);
	GF2X_MUL(8, temp2, 4, p_11+807+4, 4, q_11+785);
	gf2x_add(8, p_11+791+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+785+0, 4, p_01+807);
	GF2X_MUL(8, temp2, 4, q_11+785+0, 4, p_11+807);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+791+0, 8, p_11+791+0, 8, temp);
	

	// Calculating left operands: n: 1432, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2279+11, 12, p_00+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+11, 12, p_01+791);
	gf2x_add(23, f_sum+2359, 23, temp+1, 23, temp2+1);
	GF2X_MUL(22, temp, 11, p_00+791+1, 11, f_sum+2279);
	GF2X_MUL(22, temp2, 11, p_01+791+1, 11, g_sum+2279);
	gf2x_add(22, temp, 22, temp, 22, temp2);
	gf2x_add(11, f_sum+2359, 11, f_sum+2359, 11, temp+11);
	right_bit_shift_n(23, f_sum+2359, 61);
	GF2X_MUL(24, temp, 12, f_sum+2279+11, 12, p_10+791);
	GF2X_MUL(24, temp2, 12, g_sum+2279+11, 12, p_11+791);
	gf2x_add(23, g_sum+2359, 23, temp+1, 23, temp2+1);
	GF2X_MUL(22, temp, 11, p_10+791+1, 11, f_sum+2279);
	GF2X_MUL(22, temp2, 11, p_11+791+1, 11, g_sum+2279);
	gf2x_add(22, temp, 22, temp, 22, temp2);
	gf2x_add(11, g_sum+2359, 11, g_sum+2359, 11, temp+11);
	right_bit_shift_n(23, g_sum+2359, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2367, g_sum+2367, p_00+815, p_01+815, p_10+815, p_11+815);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2363+4, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2363+4, 4, p_01+815);
	gf2x_add(8, f_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2363+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, g_sum+2363+0, 4, p_01+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2429, 4, f_sum+2429, 4, temp+4);
	right_bit_shift_n(8, f_sum+2429, 63);
	GF2X_MUL(8, temp, 4, f_sum+2363+4, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2363+4, 4, p_11+815);
	gf2x_add(8, g_sum+2429+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2363+0, 4, p_10+815);
	GF2X_MUL(8, temp2, 4, g_sum+2363+0, 4, p_11+815);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2429, 4, g_sum+2429, 4, temp+4);
	right_bit_shift_n(8, g_sum+2429, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2430, g_sum+2430, q_00+793, q_01+793, q_10+793, q_11+793);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_10+815);
	gf2x_add(8, p_00+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_01+793+0, 4, p_11+815);
	gf2x_add(8, p_01+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_00+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_10+815);
	gf2x_add(8, p_10+807+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+793+0, 4, p_01+815);
	GF2X_MUL(8, temp2, 4, q_11+793+0, 4, p_11+815);
	gf2x_add(8, p_11+807+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 667, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2360+3, 8, p_00+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+3, 8, p_01+807);
	gf2x_add(11, f_sum+2404, 11, temp+5, 11, temp2+5);
	GF2X_MUL(6, temp, 3, p_00+807+5, 3, f_sum+2360);
	GF2X_MUL(6, temp2, 3, p_01+807+5, 3, g_sum+2360);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, f_sum+2404, 3, f_sum+2404, 3, temp+3);
	right_bit_shift_n(11, f_sum+2404, 62);
	GF2X_MUL(16, temp, 8, f_sum+2360+3, 8, p_10+807);
	GF2X_MUL(16, temp2, 8, g_sum+2360+3, 8, p_11+807);
	gf2x_add(11, g_sum+2404, 11, temp+5, 11, temp2+5);
	GF2X_MUL(6, temp, 3, p_10+807+5, 3, f_sum+2360);
	GF2X_MUL(6, temp2, 3, p_11+807+5, 3, g_sum+2360);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, g_sum+2404, 3, g_sum+2404, 3, temp+3);
	right_bit_shift_n(11, g_sum+2404, 62);
	

	delta = support_jumpdivstep(157, delta, 3, f_sum+2405, g_sum+2405, q_00+785, q_01+785, q_10+785, q_11+785, x);

	// Recombining results: n: 667, depth: 6
	memset(q_00+773, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+807+5, 3, q_00+785);
	GF2X_MUL(6, temp2, 3, p_10+807+5, 3, q_01+785);
	gf2x_add(6, q_00+773+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_00+807+2, 3, q_00+785);
	GF2X_MUL(6, temp2, 3, p_10+807+2, 3, q_01+785);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+773+2, 6, q_00+773+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_00+785+1, 2, p_00+807);
	GF2X_MUL(4, temp2, 2, q_01+785+1, 2, p_10+807);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+773+1, 4, q_00+773+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+807+1, 1, q_00+785);
	GF2X_MUL(2, temp2, 1, p_10+807+1, 1, q_01+785);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+773+1, 2, q_00+773+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+785+0, 1, p_00+807);
	GF2X_MUL(2, temp2, 1, q_01+785+0, 1, p_10+807);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+773+0, 2, q_00+773+0, 2, temp);
	memset(q_01+773, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+807+5, 3, q_00+785);
	GF2X_MUL(6, temp2, 3, p_11+807+5, 3, q_01+785);
	gf2x_add(6, q_01+773+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_01+807+2, 3, q_00+785);
	GF2X_MUL(6, temp2, 3, p_11+807+2, 3, q_01+785);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+773+2, 6, q_01+773+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_00+785+1, 2, p_01+807);
	GF2X_MUL(4, temp2, 2, q_01+785+1, 2, p_11+807);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+773+1, 4, q_01+773+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+807+1, 1, q_00+785);
	GF2X_MUL(2, temp2, 1, p_11+807+1, 1, q_01+785);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+773+1, 2, q_01+773+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+785+0, 1, p_01+807);
	GF2X_MUL(2, temp2, 1, q_01+785+0, 1, p_11+807);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+773+0, 2, q_01+773+0, 2, temp);
	memset(q_10+773, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+807+5, 3, q_10+785);
	GF2X_MUL(6, temp2, 3, p_10+807+5, 3, q_11+785);
	gf2x_add(6, q_10+773+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_00+807+2, 3, q_10+785);
	GF2X_MUL(6, temp2, 3, p_10+807+2, 3, q_11+785);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+773+2, 6, q_10+773+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_10+785+1, 2, p_00+807);
	GF2X_MUL(4, temp2, 2, q_11+785+1, 2, p_10+807);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+773+1, 4, q_10+773+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+807+1, 1, q_10+785);
	GF2X_MUL(2, temp2, 1, p_10+807+1, 1, q_11+785);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+773+1, 2, q_10+773+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+785+0, 1, p_00+807);
	GF2X_MUL(2, temp2, 1, q_11+785+0, 1, p_10+807);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+773+0, 2, q_10+773+0, 2, temp);
	memset(q_11+773, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+807+5, 3, q_10+785);
	GF2X_MUL(6, temp2, 3, p_11+807+5, 3, q_11+785);
	gf2x_add(6, q_11+773+5, 6, temp, 6, temp2);
	GF2X_MUL(6, temp, 3, p_01+807+2, 3, q_10+785);
	GF2X_MUL(6, temp2, 3, p_11+807+2, 3, q_11+785);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+773+2, 6, q_11+773+2, 6, temp);
	GF2X_MUL(4, temp, 2, q_10+785+1, 2, p_01+807);
	GF2X_MUL(4, temp2, 2, q_11+785+1, 2, p_11+807);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+773+1, 4, q_11+773+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+807+1, 1, q_10+785);
	GF2X_MUL(2, temp2, 1, p_11+807+1, 1, q_11+785);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+773+1, 2, q_11+773+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+785+0, 1, p_01+807);
	GF2X_MUL(2, temp2, 1, q_11+785+0, 1, p_11+807);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+773+0, 2, q_11+773+0, 2, temp);
	

	// Recombining results: n: 1432, depth: 5
	memset(q_00+749, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_00+791+1, 11, q_00+773);
	GF2X_MUL(22, temp2, 11, p_10+791+1, 11, q_01+773);
	gf2x_add(22, q_00+749+1, 22, temp, 22, temp2);
	GF2X_MUL(2, temp, 1, q_00+773+10, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+10, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+10, 2, q_00+749+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+9, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+9, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+9, 2, q_00+749+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+8, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+8, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+8, 2, q_00+749+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+7, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+7, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+7, 2, q_00+749+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+6, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+6, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+6, 2, q_00+749+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+5, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+5, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+5, 2, q_00+749+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+4, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+4, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+4, 2, q_00+749+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+3, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+3, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+3, 2, q_00+749+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+2, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+2, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+2, 2, q_00+749+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+1, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+1, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+1, 2, q_00+749+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+0, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_01+773+0, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+749+0, 2, q_00+749+0, 2, temp);
	memset(q_01+749, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_01+791+1, 11, q_00+773);
	GF2X_MUL(22, temp2, 11, p_11+791+1, 11, q_01+773);
	gf2x_add(22, q_01+749+1, 22, temp, 22, temp2);
	GF2X_MUL(2, temp, 1, q_00+773+10, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+10, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+10, 2, q_01+749+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+9, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+9, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+9, 2, q_01+749+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+8, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+8, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+8, 2, q_01+749+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+7, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+7, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+7, 2, q_01+749+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+6, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+6, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+6, 2, q_01+749+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+5, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+5, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+5, 2, q_01+749+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+4, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+4, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+4, 2, q_01+749+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+3, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+3, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+3, 2, q_01+749+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+2, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+2, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+2, 2, q_01+749+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+1, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+1, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+1, 2, q_01+749+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+773+0, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_01+773+0, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+749+0, 2, q_01+749+0, 2, temp);
	memset(q_10+749, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_00+791+1, 11, q_10+773);
	GF2X_MUL(22, temp2, 11, p_10+791+1, 11, q_11+773);
	gf2x_add(22, q_10+749+1, 22, temp, 22, temp2);
	GF2X_MUL(2, temp, 1, q_10+773+10, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+10, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+10, 2, q_10+749+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+9, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+9, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+9, 2, q_10+749+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+8, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+8, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+8, 2, q_10+749+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+7, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+7, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+7, 2, q_10+749+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+6, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+6, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+6, 2, q_10+749+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+5, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+5, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+5, 2, q_10+749+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+4, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+4, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+4, 2, q_10+749+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+3, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+3, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+3, 2, q_10+749+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+2, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+2, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+2, 2, q_10+749+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+1, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+1, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+1, 2, q_10+749+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+0, 1, p_00+791);
	GF2X_MUL(2, temp2, 1, q_11+773+0, 1, p_10+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+749+0, 2, q_10+749+0, 2, temp);
	memset(q_11+749, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(22, temp, 11, p_01+791+1, 11, q_10+773);
	GF2X_MUL(22, temp2, 11, p_11+791+1, 11, q_11+773);
	gf2x_add(22, q_11+749+1, 22, temp, 22, temp2);
	GF2X_MUL(2, temp, 1, q_10+773+10, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+10, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+10, 2, q_11+749+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+9, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+9, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+9, 2, q_11+749+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+8, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+8, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+8, 2, q_11+749+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+7, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+7, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+7, 2, q_11+749+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+6, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+6, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+6, 2, q_11+749+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+5, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+5, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+5, 2, q_11+749+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+4, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+4, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+4, 2, q_11+749+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+3, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+3, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+3, 2, q_11+749+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+2, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+2, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+2, 2, q_11+749+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+1, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+1, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+1, 2, q_11+749+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+773+0, 1, p_01+791);
	GF2X_MUL(2, temp2, 1, q_11+773+0, 1, p_11+791);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+749+0, 2, q_11+749+0, 2, temp);
	

	// Recombining results: n: 2962, depth: 4
	memset(q_00+697, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(46, temp, 23, p_00+763+1, 23, q_00+749);
	GF2X_MUL(46, temp2, 23, p_10+763+1, 23, q_01+749);
	gf2x_add(46, q_00+697+1, 46, temp, 46, temp2);
	GF2X_MUL(2, temp, 1, q_00+749+22, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+22, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+22, 2, q_00+697+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+21, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+21, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+21, 2, q_00+697+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+20, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+20, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+20, 2, q_00+697+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+19, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+19, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+19, 2, q_00+697+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+18, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+18, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+18, 2, q_00+697+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+17, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+17, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+17, 2, q_00+697+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+16, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+16, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+16, 2, q_00+697+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+15, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+15, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+15, 2, q_00+697+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+14, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+14, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+14, 2, q_00+697+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+13, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+13, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+13, 2, q_00+697+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+12, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+12, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+12, 2, q_00+697+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+11, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+11, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+11, 2, q_00+697+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+10, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+10, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+10, 2, q_00+697+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+9, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+9, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+9, 2, q_00+697+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+8, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+8, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+8, 2, q_00+697+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+7, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+7, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+7, 2, q_00+697+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+6, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+6, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+6, 2, q_00+697+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+5, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+5, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+5, 2, q_00+697+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+4, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+4, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+4, 2, q_00+697+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+3, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+3, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+3, 2, q_00+697+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+2, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+2, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+2, 2, q_00+697+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+1, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+1, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+1, 2, q_00+697+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+0, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_01+749+0, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+697+0, 2, q_00+697+0, 2, temp);
	memset(q_01+697, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(46, temp, 23, p_01+763+1, 23, q_00+749);
	GF2X_MUL(46, temp2, 23, p_11+763+1, 23, q_01+749);
	gf2x_add(46, q_01+697+1, 46, temp, 46, temp2);
	GF2X_MUL(2, temp, 1, q_00+749+22, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+22, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+22, 2, q_01+697+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+21, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+21, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+21, 2, q_01+697+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+20, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+20, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+20, 2, q_01+697+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+19, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+19, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+19, 2, q_01+697+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+18, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+18, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+18, 2, q_01+697+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+17, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+17, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+17, 2, q_01+697+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+16, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+16, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+16, 2, q_01+697+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+15, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+15, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+15, 2, q_01+697+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+14, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+14, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+14, 2, q_01+697+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+13, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+13, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+13, 2, q_01+697+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+12, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+12, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+12, 2, q_01+697+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+11, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+11, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+11, 2, q_01+697+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+10, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+10, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+10, 2, q_01+697+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+9, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+9, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+9, 2, q_01+697+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+8, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+8, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+8, 2, q_01+697+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+7, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+7, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+7, 2, q_01+697+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+6, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+6, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+6, 2, q_01+697+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+5, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+5, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+5, 2, q_01+697+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+4, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+4, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+4, 2, q_01+697+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+3, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+3, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+3, 2, q_01+697+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+2, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+2, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+2, 2, q_01+697+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+1, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+1, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+1, 2, q_01+697+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+749+0, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_01+749+0, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+697+0, 2, q_01+697+0, 2, temp);
	memset(q_10+697, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(46, temp, 23, p_00+763+1, 23, q_10+749);
	GF2X_MUL(46, temp2, 23, p_10+763+1, 23, q_11+749);
	gf2x_add(46, q_10+697+1, 46, temp, 46, temp2);
	GF2X_MUL(2, temp, 1, q_10+749+22, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+22, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+22, 2, q_10+697+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+21, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+21, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+21, 2, q_10+697+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+20, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+20, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+20, 2, q_10+697+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+19, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+19, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+19, 2, q_10+697+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+18, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+18, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+18, 2, q_10+697+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+17, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+17, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+17, 2, q_10+697+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+16, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+16, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+16, 2, q_10+697+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+15, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+15, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+15, 2, q_10+697+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+14, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+14, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+14, 2, q_10+697+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+13, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+13, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+13, 2, q_10+697+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+12, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+12, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+12, 2, q_10+697+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+11, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+11, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+11, 2, q_10+697+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+10, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+10, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+10, 2, q_10+697+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+9, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+9, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+9, 2, q_10+697+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+8, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+8, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+8, 2, q_10+697+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+7, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+7, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+7, 2, q_10+697+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+6, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+6, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+6, 2, q_10+697+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+5, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+5, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+5, 2, q_10+697+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+4, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+4, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+4, 2, q_10+697+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+3, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+3, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+3, 2, q_10+697+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+2, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+2, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+2, 2, q_10+697+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+1, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+1, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+1, 2, q_10+697+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+0, 1, p_00+763);
	GF2X_MUL(2, temp2, 1, q_11+749+0, 1, p_10+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+697+0, 2, q_10+697+0, 2, temp);
	memset(q_11+697, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(46, temp, 23, p_01+763+1, 23, q_10+749);
	GF2X_MUL(46, temp2, 23, p_11+763+1, 23, q_11+749);
	gf2x_add(46, q_11+697+1, 46, temp, 46, temp2);
	GF2X_MUL(2, temp, 1, q_10+749+22, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+22, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+22, 2, q_11+697+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+21, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+21, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+21, 2, q_11+697+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+20, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+20, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+20, 2, q_11+697+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+19, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+19, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+19, 2, q_11+697+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+18, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+18, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+18, 2, q_11+697+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+17, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+17, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+17, 2, q_11+697+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+16, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+16, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+16, 2, q_11+697+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+15, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+15, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+15, 2, q_11+697+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+14, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+14, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+14, 2, q_11+697+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+13, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+13, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+13, 2, q_11+697+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+12, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+12, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+12, 2, q_11+697+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+11, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+11, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+11, 2, q_11+697+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+10, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+10, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+10, 2, q_11+697+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+9, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+9, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+9, 2, q_11+697+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+8, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+8, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+8, 2, q_11+697+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+7, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+7, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+7, 2, q_11+697+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+6, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+6, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+6, 2, q_11+697+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+5, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+5, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+5, 2, q_11+697+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+4, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+4, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+4, 2, q_11+697+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+3, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+3, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+3, 2, q_11+697+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+2, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+2, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+2, 2, q_11+697+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+1, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+1, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+1, 2, q_11+697+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+749+0, 1, p_01+763);
	GF2X_MUL(2, temp2, 1, q_11+749+0, 1, p_11+763);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+697+0, 2, q_11+697+0, 2, temp);
	

	// Recombining results: n: 6277, depth: 3
	memset(q_00+597, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(94, temp, 47, p_00+711+5, 47, q_00+697);
	GF2X_MUL(94, temp2, 47, p_10+711+5, 47, q_01+697);
	gf2x_add(94, q_00+597+5, 94, temp, 94, temp2);
	GF2X_MUL(10, temp, 5, q_00+697+42, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+42, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+42, 10, q_00+597+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+37, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+37, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+37, 10, q_00+597+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+32, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+32, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+32, 10, q_00+597+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+27, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+27, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+27, 10, q_00+597+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+22, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+22, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+22, 10, q_00+597+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+17, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+17, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+17, 10, q_00+597+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+12, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+12, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+12, 10, q_00+597+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+7, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+7, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+7, 10, q_00+597+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+2, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_01+697+2, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+597+2, 10, q_00+597+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+711+3, 2, q_00+697);
	GF2X_MUL(4, temp2, 2, p_10+711+3, 2, q_01+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+597+3, 4, q_00+597+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+711+1, 2, q_00+697);
	GF2X_MUL(4, temp2, 2, p_10+711+1, 2, q_01+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+597+1, 4, q_00+597+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+697+1, 1, p_00+711);
	GF2X_MUL(2, temp2, 1, q_01+697+1, 1, p_10+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+597+1, 2, q_00+597+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+697+0, 1, p_00+711);
	GF2X_MUL(2, temp2, 1, q_01+697+0, 1, p_10+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+597+0, 2, q_00+597+0, 2, temp);
	memset(q_01+597, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(94, temp, 47, p_01+711+5, 47, q_00+697);
	GF2X_MUL(94, temp2, 47, p_11+711+5, 47, q_01+697);
	gf2x_add(94, q_01+597+5, 94, temp, 94, temp2);
	GF2X_MUL(10, temp, 5, q_00+697+42, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+42, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+42, 10, q_01+597+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+37, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+37, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+37, 10, q_01+597+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+32, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+32, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+32, 10, q_01+597+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+27, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+27, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+27, 10, q_01+597+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+22, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+22, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+22, 10, q_01+597+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+17, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+17, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+17, 10, q_01+597+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+12, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+12, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+12, 10, q_01+597+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+7, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+7, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+7, 10, q_01+597+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+697+2, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_01+697+2, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+597+2, 10, q_01+597+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+711+3, 2, q_00+697);
	GF2X_MUL(4, temp2, 2, p_11+711+3, 2, q_01+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+597+3, 4, q_01+597+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+711+1, 2, q_00+697);
	GF2X_MUL(4, temp2, 2, p_11+711+1, 2, q_01+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+597+1, 4, q_01+597+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+697+1, 1, p_01+711);
	GF2X_MUL(2, temp2, 1, q_01+697+1, 1, p_11+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+597+1, 2, q_01+597+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+697+0, 1, p_01+711);
	GF2X_MUL(2, temp2, 1, q_01+697+0, 1, p_11+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+597+0, 2, q_01+597+0, 2, temp);
	memset(q_10+597, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(94, temp, 47, p_00+711+5, 47, q_10+697);
	GF2X_MUL(94, temp2, 47, p_10+711+5, 47, q_11+697);
	gf2x_add(94, q_10+597+5, 94, temp, 94, temp2);
	GF2X_MUL(10, temp, 5, q_10+697+42, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+42, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+42, 10, q_10+597+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+37, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+37, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+37, 10, q_10+597+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+32, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+32, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+32, 10, q_10+597+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+27, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+27, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+27, 10, q_10+597+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+22, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+22, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+22, 10, q_10+597+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+17, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+17, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+17, 10, q_10+597+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+12, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+12, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+12, 10, q_10+597+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+7, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+7, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+7, 10, q_10+597+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+2, 5, p_00+711);
	GF2X_MUL(10, temp2, 5, q_11+697+2, 5, p_10+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+597+2, 10, q_10+597+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+711+3, 2, q_10+697);
	GF2X_MUL(4, temp2, 2, p_10+711+3, 2, q_11+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+597+3, 4, q_10+597+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+711+1, 2, q_10+697);
	GF2X_MUL(4, temp2, 2, p_10+711+1, 2, q_11+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+597+1, 4, q_10+597+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+697+1, 1, p_00+711);
	GF2X_MUL(2, temp2, 1, q_11+697+1, 1, p_10+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+597+1, 2, q_10+597+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+697+0, 1, p_00+711);
	GF2X_MUL(2, temp2, 1, q_11+697+0, 1, p_10+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+597+0, 2, q_10+597+0, 2, temp);
	memset(q_11+597, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(94, temp, 47, p_01+711+5, 47, q_10+697);
	GF2X_MUL(94, temp2, 47, p_11+711+5, 47, q_11+697);
	gf2x_add(94, q_11+597+5, 94, temp, 94, temp2);
	GF2X_MUL(10, temp, 5, q_10+697+42, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+42, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+42, 10, q_11+597+42, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+37, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+37, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+37, 10, q_11+597+37, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+32, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+32, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+32, 10, q_11+597+32, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+27, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+27, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+27, 10, q_11+597+27, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+22, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+22, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+22, 10, q_11+597+22, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+17, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+17, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+17, 10, q_11+597+17, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+12, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+12, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+12, 10, q_11+597+12, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+7, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+7, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+7, 10, q_11+597+7, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+697+2, 5, p_01+711);
	GF2X_MUL(10, temp2, 5, q_11+697+2, 5, p_11+711);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+597+2, 10, q_11+597+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+711+3, 2, q_10+697);
	GF2X_MUL(4, temp2, 2, p_11+711+3, 2, q_11+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+597+3, 4, q_11+597+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+711+1, 2, q_10+697);
	GF2X_MUL(4, temp2, 2, p_11+711+1, 2, q_11+697);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+597+1, 4, q_11+597+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+697+1, 1, p_01+711);
	GF2X_MUL(2, temp2, 1, q_11+697+1, 1, p_11+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+597+1, 2, q_11+597+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+697+0, 1, p_01+711);
	GF2X_MUL(2, temp2, 1, q_11+697+0, 1, p_11+711);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+597+0, 2, q_11+597+0, 2, temp);
	

	// Recombining results: n: 12652, depth: 2
	GF2X_MUL(198, temp, 99, p_00+607+1, 99, q_00+597);
	GF2X_MUL(198, temp2, 99, p_10+607+1, 99, q_01+597);
	gf2x_add(198, q_00+397+0, 198, temp, 198, temp2);
	GF2X_MUL(2, temp, 1, q_00+597+98, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+98, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+97, 2, q_00+397+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+97, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+97, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+96, 2, q_00+397+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+96, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+96, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+95, 2, q_00+397+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+95, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+95, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+94, 2, q_00+397+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+94, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+94, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+93, 2, q_00+397+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+93, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+93, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+92, 2, q_00+397+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+92, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+92, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+91, 2, q_00+397+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+91, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+91, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+90, 2, q_00+397+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+90, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+90, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+89, 2, q_00+397+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+89, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+89, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+88, 2, q_00+397+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+88, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+88, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+87, 2, q_00+397+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+87, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+87, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+86, 2, q_00+397+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+86, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+86, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+85, 2, q_00+397+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+85, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+85, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+84, 2, q_00+397+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+84, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+84, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+83, 2, q_00+397+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+83, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+83, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+82, 2, q_00+397+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+82, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+82, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+81, 2, q_00+397+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+81, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+81, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+80, 2, q_00+397+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+80, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+80, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+79, 2, q_00+397+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+79, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+79, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+78, 2, q_00+397+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+78, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+78, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+77, 2, q_00+397+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+77, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+77, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+76, 2, q_00+397+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+76, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+76, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+75, 2, q_00+397+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+75, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+75, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+74, 2, q_00+397+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+74, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+74, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+73, 2, q_00+397+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+73, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+73, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+72, 2, q_00+397+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+72, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+72, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+71, 2, q_00+397+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+71, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+71, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+70, 2, q_00+397+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+70, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+70, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+69, 2, q_00+397+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+69, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+69, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+68, 2, q_00+397+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+68, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+68, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+67, 2, q_00+397+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+67, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+67, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+66, 2, q_00+397+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+66, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+66, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+65, 2, q_00+397+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+65, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+65, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+64, 2, q_00+397+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+64, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+64, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+63, 2, q_00+397+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+63, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+63, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+62, 2, q_00+397+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+62, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+62, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+61, 2, q_00+397+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+61, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+61, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+60, 2, q_00+397+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+60, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+60, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+59, 2, q_00+397+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+59, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+59, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+58, 2, q_00+397+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+58, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+58, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+57, 2, q_00+397+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+57, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+57, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+56, 2, q_00+397+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+56, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+56, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+55, 2, q_00+397+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+55, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+55, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+54, 2, q_00+397+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+54, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+54, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+53, 2, q_00+397+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+53, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+53, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+52, 2, q_00+397+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+52, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+52, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+51, 2, q_00+397+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+51, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+51, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+50, 2, q_00+397+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+50, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+50, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+49, 2, q_00+397+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+49, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+49, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+48, 2, q_00+397+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+48, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+48, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+47, 2, q_00+397+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+47, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+47, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+46, 2, q_00+397+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+46, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+46, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+45, 2, q_00+397+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+45, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+45, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+44, 2, q_00+397+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+44, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+44, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+43, 2, q_00+397+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+43, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+43, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+42, 2, q_00+397+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+42, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+42, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+41, 2, q_00+397+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+41, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+41, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+40, 2, q_00+397+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+40, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+40, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+39, 2, q_00+397+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+39, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+39, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+38, 2, q_00+397+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+38, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+38, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+37, 2, q_00+397+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+37, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+37, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+36, 2, q_00+397+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+36, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+36, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+35, 2, q_00+397+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+35, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+35, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+34, 2, q_00+397+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+34, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+34, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+33, 2, q_00+397+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+33, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+33, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+32, 2, q_00+397+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+32, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+32, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+31, 2, q_00+397+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+31, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+31, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+30, 2, q_00+397+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+30, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+30, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+29, 2, q_00+397+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+29, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+29, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+28, 2, q_00+397+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+28, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+28, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+27, 2, q_00+397+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+27, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+27, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+26, 2, q_00+397+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+26, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+26, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+25, 2, q_00+397+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+25, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+25, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+24, 2, q_00+397+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+24, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+24, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+23, 2, q_00+397+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+23, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+23, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+22, 2, q_00+397+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+22, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+22, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+21, 2, q_00+397+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+21, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+21, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+20, 2, q_00+397+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+20, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+20, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+19, 2, q_00+397+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+19, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+19, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+18, 2, q_00+397+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+18, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+18, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+17, 2, q_00+397+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+17, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+17, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+16, 2, q_00+397+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+16, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+16, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+15, 2, q_00+397+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+15, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+15, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+14, 2, q_00+397+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+14, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+14, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+13, 2, q_00+397+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+13, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+13, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+12, 2, q_00+397+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+12, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+12, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+11, 2, q_00+397+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+11, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+11, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+10, 2, q_00+397+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+10, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+10, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+9, 2, q_00+397+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+9, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+9, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+8, 2, q_00+397+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+8, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+8, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+7, 2, q_00+397+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+7, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+7, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+6, 2, q_00+397+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+6, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+6, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+5, 2, q_00+397+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+5, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+5, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+4, 2, q_00+397+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+4, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+4, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+3, 2, q_00+397+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+3, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+3, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+2, 2, q_00+397+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+2, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+2, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+1, 2, q_00+397+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+1, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+1, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+397+0, 2, q_00+397+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+0, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+597+0, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+397, 1, q_00+397, 1, temp+1);
	GF2X_MUL(198, temp, 99, p_01+607+1, 99, q_00+597);
	GF2X_MUL(198, temp2, 99, p_11+607+1, 99, q_01+597);
	gf2x_add(198, q_01+397+0, 198, temp, 198, temp2);
	GF2X_MUL(2, temp, 1, q_00+597+98, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+98, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+97, 2, q_01+397+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+97, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+97, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+96, 2, q_01+397+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+96, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+96, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+95, 2, q_01+397+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+95, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+95, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+94, 2, q_01+397+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+94, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+94, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+93, 2, q_01+397+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+93, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+93, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+92, 2, q_01+397+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+92, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+92, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+91, 2, q_01+397+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+91, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+91, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+90, 2, q_01+397+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+90, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+90, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+89, 2, q_01+397+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+89, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+89, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+88, 2, q_01+397+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+88, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+88, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+87, 2, q_01+397+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+87, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+87, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+86, 2, q_01+397+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+86, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+86, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+85, 2, q_01+397+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+85, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+85, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+84, 2, q_01+397+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+84, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+84, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+83, 2, q_01+397+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+83, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+83, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+82, 2, q_01+397+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+82, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+82, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+81, 2, q_01+397+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+81, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+81, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+80, 2, q_01+397+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+80, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+80, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+79, 2, q_01+397+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+79, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+79, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+78, 2, q_01+397+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+78, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+78, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+77, 2, q_01+397+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+77, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+77, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+76, 2, q_01+397+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+76, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+76, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+75, 2, q_01+397+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+75, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+75, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+74, 2, q_01+397+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+74, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+74, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+73, 2, q_01+397+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+73, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+73, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+72, 2, q_01+397+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+72, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+72, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+71, 2, q_01+397+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+71, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+71, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+70, 2, q_01+397+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+70, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+70, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+69, 2, q_01+397+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+69, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+69, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+68, 2, q_01+397+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+68, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+68, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+67, 2, q_01+397+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+67, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+67, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+66, 2, q_01+397+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+66, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+66, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+65, 2, q_01+397+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+65, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+65, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+64, 2, q_01+397+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+64, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+64, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+63, 2, q_01+397+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+63, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+63, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+62, 2, q_01+397+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+62, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+62, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+61, 2, q_01+397+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+61, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+61, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+60, 2, q_01+397+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+60, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+60, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+59, 2, q_01+397+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+59, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+59, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+58, 2, q_01+397+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+58, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+58, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+57, 2, q_01+397+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+57, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+57, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+56, 2, q_01+397+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+56, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+56, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+55, 2, q_01+397+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+55, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+55, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+54, 2, q_01+397+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+54, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+54, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+53, 2, q_01+397+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+53, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+53, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+52, 2, q_01+397+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+52, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+52, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+51, 2, q_01+397+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+51, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+51, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+50, 2, q_01+397+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+50, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+50, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+49, 2, q_01+397+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+49, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+49, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+48, 2, q_01+397+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+48, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+48, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+47, 2, q_01+397+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+47, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+47, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+46, 2, q_01+397+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+46, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+46, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+45, 2, q_01+397+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+45, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+45, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+44, 2, q_01+397+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+44, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+44, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+43, 2, q_01+397+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+43, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+43, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+42, 2, q_01+397+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+42, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+42, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+41, 2, q_01+397+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+41, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+41, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+40, 2, q_01+397+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+40, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+40, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+39, 2, q_01+397+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+39, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+39, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+38, 2, q_01+397+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+38, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+38, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+37, 2, q_01+397+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+37, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+37, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+36, 2, q_01+397+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+36, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+36, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+35, 2, q_01+397+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+35, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+35, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+34, 2, q_01+397+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+34, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+34, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+33, 2, q_01+397+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+33, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+33, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+32, 2, q_01+397+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+32, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+32, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+31, 2, q_01+397+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+31, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+31, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+30, 2, q_01+397+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+30, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+30, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+29, 2, q_01+397+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+29, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+29, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+28, 2, q_01+397+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+28, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+28, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+27, 2, q_01+397+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+27, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+27, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+26, 2, q_01+397+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+26, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+26, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+25, 2, q_01+397+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+25, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+25, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+24, 2, q_01+397+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+24, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+24, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+23, 2, q_01+397+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+23, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+23, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+22, 2, q_01+397+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+22, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+22, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+21, 2, q_01+397+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+21, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+21, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+20, 2, q_01+397+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+20, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+20, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+19, 2, q_01+397+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+19, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+19, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+18, 2, q_01+397+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+18, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+18, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+17, 2, q_01+397+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+17, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+17, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+16, 2, q_01+397+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+16, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+16, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+15, 2, q_01+397+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+15, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+15, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+14, 2, q_01+397+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+14, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+14, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+13, 2, q_01+397+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+13, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+13, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+12, 2, q_01+397+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+12, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+12, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+11, 2, q_01+397+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+11, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+11, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+10, 2, q_01+397+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+10, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+10, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+9, 2, q_01+397+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+9, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+9, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+8, 2, q_01+397+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+8, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+8, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+7, 2, q_01+397+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+7, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+7, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+6, 2, q_01+397+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+6, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+6, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+5, 2, q_01+397+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+5, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+5, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+4, 2, q_01+397+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+4, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+4, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+3, 2, q_01+397+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+3, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+3, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+2, 2, q_01+397+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+2, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+2, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+1, 2, q_01+397+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+1, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+1, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+397+0, 2, q_01+397+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+597+0, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+597+0, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+397, 1, q_01+397, 1, temp+1);
	GF2X_MUL(198, temp, 99, p_00+607+1, 99, q_10+597);
	GF2X_MUL(198, temp2, 99, p_10+607+1, 99, q_11+597);
	gf2x_add(198, q_10+397+0, 198, temp, 198, temp2);
	GF2X_MUL(2, temp, 1, q_10+597+98, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+98, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+97, 2, q_10+397+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+97, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+97, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+96, 2, q_10+397+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+96, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+96, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+95, 2, q_10+397+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+95, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+95, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+94, 2, q_10+397+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+94, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+94, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+93, 2, q_10+397+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+93, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+93, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+92, 2, q_10+397+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+92, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+92, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+91, 2, q_10+397+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+91, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+91, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+90, 2, q_10+397+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+90, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+90, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+89, 2, q_10+397+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+89, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+89, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+88, 2, q_10+397+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+88, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+88, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+87, 2, q_10+397+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+87, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+87, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+86, 2, q_10+397+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+86, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+86, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+85, 2, q_10+397+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+85, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+85, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+84, 2, q_10+397+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+84, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+84, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+83, 2, q_10+397+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+83, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+83, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+82, 2, q_10+397+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+82, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+82, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+81, 2, q_10+397+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+81, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+81, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+80, 2, q_10+397+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+80, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+80, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+79, 2, q_10+397+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+79, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+79, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+78, 2, q_10+397+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+78, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+78, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+77, 2, q_10+397+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+77, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+77, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+76, 2, q_10+397+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+76, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+76, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+75, 2, q_10+397+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+75, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+75, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+74, 2, q_10+397+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+74, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+74, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+73, 2, q_10+397+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+73, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+73, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+72, 2, q_10+397+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+72, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+72, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+71, 2, q_10+397+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+71, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+71, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+70, 2, q_10+397+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+70, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+70, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+69, 2, q_10+397+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+69, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+69, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+68, 2, q_10+397+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+68, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+68, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+67, 2, q_10+397+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+67, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+67, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+66, 2, q_10+397+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+66, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+66, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+65, 2, q_10+397+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+65, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+65, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+64, 2, q_10+397+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+64, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+64, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+63, 2, q_10+397+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+63, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+63, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+62, 2, q_10+397+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+62, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+62, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+61, 2, q_10+397+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+61, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+61, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+60, 2, q_10+397+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+60, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+60, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+59, 2, q_10+397+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+59, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+59, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+58, 2, q_10+397+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+58, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+58, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+57, 2, q_10+397+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+57, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+57, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+56, 2, q_10+397+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+56, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+56, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+55, 2, q_10+397+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+55, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+55, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+54, 2, q_10+397+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+54, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+54, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+53, 2, q_10+397+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+53, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+53, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+52, 2, q_10+397+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+52, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+52, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+51, 2, q_10+397+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+51, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+51, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+50, 2, q_10+397+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+50, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+50, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+49, 2, q_10+397+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+49, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+49, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+48, 2, q_10+397+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+48, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+48, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+47, 2, q_10+397+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+47, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+47, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+46, 2, q_10+397+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+46, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+46, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+45, 2, q_10+397+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+45, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+45, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+44, 2, q_10+397+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+44, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+44, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+43, 2, q_10+397+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+43, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+43, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+42, 2, q_10+397+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+42, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+42, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+41, 2, q_10+397+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+41, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+41, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+40, 2, q_10+397+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+40, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+40, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+39, 2, q_10+397+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+39, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+39, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+38, 2, q_10+397+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+38, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+38, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+37, 2, q_10+397+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+37, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+37, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+36, 2, q_10+397+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+36, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+36, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+35, 2, q_10+397+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+35, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+35, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+34, 2, q_10+397+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+34, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+34, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+33, 2, q_10+397+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+33, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+33, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+32, 2, q_10+397+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+32, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+32, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+31, 2, q_10+397+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+31, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+31, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+30, 2, q_10+397+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+30, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+30, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+29, 2, q_10+397+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+29, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+29, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+28, 2, q_10+397+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+28, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+28, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+27, 2, q_10+397+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+27, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+27, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+26, 2, q_10+397+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+26, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+26, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+25, 2, q_10+397+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+25, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+25, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+24, 2, q_10+397+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+24, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+24, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+23, 2, q_10+397+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+23, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+23, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+22, 2, q_10+397+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+22, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+22, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+21, 2, q_10+397+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+21, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+21, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+20, 2, q_10+397+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+20, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+20, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+19, 2, q_10+397+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+19, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+19, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+18, 2, q_10+397+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+18, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+18, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+17, 2, q_10+397+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+17, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+17, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+16, 2, q_10+397+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+16, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+16, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+15, 2, q_10+397+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+15, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+15, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+14, 2, q_10+397+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+14, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+14, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+13, 2, q_10+397+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+13, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+13, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+12, 2, q_10+397+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+12, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+12, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+11, 2, q_10+397+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+11, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+11, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+10, 2, q_10+397+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+10, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+10, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+9, 2, q_10+397+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+9, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+9, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+8, 2, q_10+397+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+8, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+8, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+7, 2, q_10+397+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+7, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+7, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+6, 2, q_10+397+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+6, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+6, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+5, 2, q_10+397+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+5, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+5, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+4, 2, q_10+397+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+4, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+4, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+3, 2, q_10+397+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+3, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+3, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+2, 2, q_10+397+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+2, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+2, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+1, 2, q_10+397+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+1, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+1, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+397+0, 2, q_10+397+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+0, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+597+0, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+397, 1, q_10+397, 1, temp+1);
	GF2X_MUL(198, temp, 99, p_01+607+1, 99, q_10+597);
	GF2X_MUL(198, temp2, 99, p_11+607+1, 99, q_11+597);
	gf2x_add(198, q_11+397+0, 198, temp, 198, temp2);
	GF2X_MUL(2, temp, 1, q_10+597+98, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+98, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+97, 2, q_11+397+97, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+97, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+97, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+96, 2, q_11+397+96, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+96, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+96, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+95, 2, q_11+397+95, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+95, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+95, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+94, 2, q_11+397+94, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+94, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+94, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+93, 2, q_11+397+93, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+93, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+93, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+92, 2, q_11+397+92, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+92, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+92, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+91, 2, q_11+397+91, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+91, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+91, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+90, 2, q_11+397+90, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+90, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+90, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+89, 2, q_11+397+89, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+89, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+89, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+88, 2, q_11+397+88, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+88, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+88, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+87, 2, q_11+397+87, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+87, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+87, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+86, 2, q_11+397+86, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+86, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+86, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+85, 2, q_11+397+85, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+85, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+85, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+84, 2, q_11+397+84, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+84, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+84, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+83, 2, q_11+397+83, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+83, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+83, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+82, 2, q_11+397+82, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+82, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+82, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+81, 2, q_11+397+81, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+81, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+81, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+80, 2, q_11+397+80, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+80, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+80, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+79, 2, q_11+397+79, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+79, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+79, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+78, 2, q_11+397+78, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+78, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+78, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+77, 2, q_11+397+77, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+77, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+77, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+76, 2, q_11+397+76, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+76, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+76, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+75, 2, q_11+397+75, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+75, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+75, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+74, 2, q_11+397+74, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+74, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+74, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+73, 2, q_11+397+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+73, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+73, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+72, 2, q_11+397+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+72, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+72, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+71, 2, q_11+397+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+71, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+71, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+70, 2, q_11+397+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+70, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+70, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+69, 2, q_11+397+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+69, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+69, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+68, 2, q_11+397+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+68, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+68, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+67, 2, q_11+397+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+67, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+67, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+66, 2, q_11+397+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+66, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+66, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+65, 2, q_11+397+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+65, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+65, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+64, 2, q_11+397+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+64, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+64, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+63, 2, q_11+397+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+63, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+63, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+62, 2, q_11+397+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+62, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+62, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+61, 2, q_11+397+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+61, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+61, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+60, 2, q_11+397+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+60, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+60, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+59, 2, q_11+397+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+59, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+59, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+58, 2, q_11+397+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+58, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+58, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+57, 2, q_11+397+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+57, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+57, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+56, 2, q_11+397+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+56, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+56, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+55, 2, q_11+397+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+55, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+55, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+54, 2, q_11+397+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+54, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+54, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+53, 2, q_11+397+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+53, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+53, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+52, 2, q_11+397+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+52, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+52, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+51, 2, q_11+397+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+51, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+51, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+50, 2, q_11+397+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+50, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+50, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+49, 2, q_11+397+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+49, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+49, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+48, 2, q_11+397+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+48, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+48, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+47, 2, q_11+397+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+47, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+47, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+46, 2, q_11+397+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+46, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+46, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+45, 2, q_11+397+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+45, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+45, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+44, 2, q_11+397+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+44, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+44, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+43, 2, q_11+397+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+43, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+43, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+42, 2, q_11+397+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+42, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+42, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+41, 2, q_11+397+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+41, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+41, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+40, 2, q_11+397+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+40, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+40, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+39, 2, q_11+397+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+39, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+39, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+38, 2, q_11+397+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+38, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+38, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+37, 2, q_11+397+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+37, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+37, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+36, 2, q_11+397+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+36, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+36, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+35, 2, q_11+397+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+35, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+35, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+34, 2, q_11+397+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+34, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+34, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+33, 2, q_11+397+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+33, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+33, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+32, 2, q_11+397+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+32, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+32, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+31, 2, q_11+397+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+31, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+31, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+30, 2, q_11+397+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+30, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+30, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+29, 2, q_11+397+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+29, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+29, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+28, 2, q_11+397+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+28, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+28, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+27, 2, q_11+397+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+27, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+27, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+26, 2, q_11+397+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+26, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+26, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+25, 2, q_11+397+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+25, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+25, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+24, 2, q_11+397+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+24, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+24, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+23, 2, q_11+397+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+23, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+23, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+22, 2, q_11+397+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+22, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+22, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+21, 2, q_11+397+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+21, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+21, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+20, 2, q_11+397+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+20, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+20, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+19, 2, q_11+397+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+19, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+19, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+18, 2, q_11+397+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+18, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+18, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+17, 2, q_11+397+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+17, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+17, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+16, 2, q_11+397+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+16, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+16, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+15, 2, q_11+397+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+15, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+15, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+14, 2, q_11+397+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+14, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+14, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+13, 2, q_11+397+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+13, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+13, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+12, 2, q_11+397+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+12, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+12, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+11, 2, q_11+397+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+11, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+11, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+10, 2, q_11+397+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+10, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+10, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+9, 2, q_11+397+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+9, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+9, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+8, 2, q_11+397+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+8, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+8, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+7, 2, q_11+397+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+7, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+7, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+6, 2, q_11+397+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+6, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+6, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+5, 2, q_11+397+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+5, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+5, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+4, 2, q_11+397+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+4, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+4, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+3, 2, q_11+397+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+3, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+3, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+2, 2, q_11+397+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+2, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+2, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+1, 2, q_11+397+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+1, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+1, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+397+0, 2, q_11+397+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+597+0, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+597+0, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+397, 1, q_11+397, 1, temp+1);
	

	// Recombining results: n: 25402, depth: 1
	memset(q_00+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(396, temp, 198, p_00+403+2, 198, q_00+397);
	GF2X_MUL(396, temp2, 198, p_10+403+2, 198, q_01+397);
	gf2x_add(396, q_00+0+1, 396, temp, 396, temp2);
	GF2X_MUL(4, temp, 2, q_00+397+196, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+196, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+195, 4, q_00+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+194, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+194, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+193, 4, q_00+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+192, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+192, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+191, 4, q_00+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+190, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+190, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+189, 4, q_00+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+188, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+188, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+187, 4, q_00+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+186, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+186, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+185, 4, q_00+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+184, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+184, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+183, 4, q_00+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+182, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+182, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+181, 4, q_00+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+180, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+180, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+179, 4, q_00+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+178, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+178, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+177, 4, q_00+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+176, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+176, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+175, 4, q_00+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+174, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+174, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+173, 4, q_00+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+172, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+172, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+171, 4, q_00+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+170, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+170, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+169, 4, q_00+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+168, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+168, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+167, 4, q_00+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+166, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+166, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+165, 4, q_00+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+164, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+164, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+163, 4, q_00+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+162, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+162, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+161, 4, q_00+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+160, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+160, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+159, 4, q_00+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+158, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+158, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+157, 4, q_00+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+156, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+156, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+155, 4, q_00+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+154, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+154, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+153, 4, q_00+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+152, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+152, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+151, 4, q_00+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+150, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+150, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+149, 4, q_00+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+148, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+148, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+147, 4, q_00+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+146, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+146, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+145, 4, q_00+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+144, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+144, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+143, 4, q_00+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+142, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+142, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+141, 4, q_00+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+140, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+140, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+139, 4, q_00+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+138, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+138, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+137, 4, q_00+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+136, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+136, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+135, 4, q_00+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+134, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+134, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+133, 4, q_00+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+132, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+132, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+131, 4, q_00+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+130, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+130, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+129, 4, q_00+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+128, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+128, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+127, 4, q_00+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+126, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+126, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+125, 4, q_00+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+124, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+124, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+123, 4, q_00+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+122, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+122, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+121, 4, q_00+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+120, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+120, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+119, 4, q_00+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+118, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+118, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+117, 4, q_00+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+116, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+116, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+115, 4, q_00+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+114, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+114, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+113, 4, q_00+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+112, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+112, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+111, 4, q_00+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+110, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+110, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+109, 4, q_00+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+108, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+108, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+107, 4, q_00+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+106, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+106, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+105, 4, q_00+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+104, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+104, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+103, 4, q_00+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+102, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+102, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+101, 4, q_00+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+100, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+100, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+99, 4, q_00+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+98, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+98, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+97, 4, q_00+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+96, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+96, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+95, 4, q_00+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+94, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+94, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+93, 4, q_00+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+92, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+92, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+91, 4, q_00+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+90, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+90, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+89, 4, q_00+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+88, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+88, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+87, 4, q_00+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+86, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+86, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+85, 4, q_00+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+84, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+84, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+83, 4, q_00+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+82, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+82, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+81, 4, q_00+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+80, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+80, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+79, 4, q_00+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+78, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+78, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+77, 4, q_00+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+76, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+76, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+75, 4, q_00+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+74, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+74, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+73, 4, q_00+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+72, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+72, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+71, 4, q_00+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+70, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+70, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+69, 4, q_00+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+68, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+68, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+67, 4, q_00+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+66, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+66, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+65, 4, q_00+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+64, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+64, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+63, 4, q_00+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+62, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+62, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+61, 4, q_00+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+60, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+60, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+59, 4, q_00+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+58, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+58, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+57, 4, q_00+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+56, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+56, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+55, 4, q_00+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+54, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+54, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+53, 4, q_00+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+52, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+52, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+51, 4, q_00+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+50, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+50, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+49, 4, q_00+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+48, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+48, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+47, 4, q_00+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+46, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+46, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+45, 4, q_00+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+44, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+44, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+43, 4, q_00+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+42, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+42, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+41, 4, q_00+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+40, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+40, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+39, 4, q_00+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+38, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+38, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+37, 4, q_00+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+36, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+36, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+35, 4, q_00+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+34, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+34, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+33, 4, q_00+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+32, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+32, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+31, 4, q_00+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+30, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+30, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+29, 4, q_00+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+28, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+28, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+27, 4, q_00+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+26, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+26, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+25, 4, q_00+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+24, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+24, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+23, 4, q_00+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+22, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+22, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+21, 4, q_00+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+20, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+20, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+19, 4, q_00+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+18, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+18, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+17, 4, q_00+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+16, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+16, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+15, 4, q_00+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+14, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+14, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+13, 4, q_00+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+12, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+12, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+11, 4, q_00+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+10, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+10, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+9, 4, q_00+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+8, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+8, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+7, 4, q_00+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+6, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+6, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+5, 4, q_00+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+4, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+4, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+3, 4, q_00+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+2, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+2, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+1, 4, q_00+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+0, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_01+397+0, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+0, 3, q_00+0, 3, temp+1);
	memset(q_01+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(396, temp, 198, p_01+403+2, 198, q_00+397);
	GF2X_MUL(396, temp2, 198, p_11+403+2, 198, q_01+397);
	gf2x_add(396, q_01+0+1, 396, temp, 396, temp2);
	GF2X_MUL(4, temp, 2, q_00+397+196, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+196, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+195, 4, q_01+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+194, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+194, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+193, 4, q_01+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+192, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+192, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+191, 4, q_01+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+190, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+190, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+189, 4, q_01+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+188, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+188, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+187, 4, q_01+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+186, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+186, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+185, 4, q_01+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+184, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+184, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+183, 4, q_01+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+182, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+182, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+181, 4, q_01+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+180, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+180, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+179, 4, q_01+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+178, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+178, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+177, 4, q_01+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+176, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+176, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+175, 4, q_01+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+174, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+174, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+173, 4, q_01+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+172, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+172, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+171, 4, q_01+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+170, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+170, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+169, 4, q_01+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+168, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+168, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+167, 4, q_01+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+166, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+166, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+165, 4, q_01+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+164, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+164, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+163, 4, q_01+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+162, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+162, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+161, 4, q_01+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+160, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+160, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+159, 4, q_01+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+158, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+158, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+157, 4, q_01+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+156, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+156, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+155, 4, q_01+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+154, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+154, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+153, 4, q_01+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+152, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+152, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+151, 4, q_01+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+150, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+150, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+149, 4, q_01+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+148, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+148, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+147, 4, q_01+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+146, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+146, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+145, 4, q_01+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+144, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+144, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+143, 4, q_01+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+142, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+142, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+141, 4, q_01+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+140, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+140, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+139, 4, q_01+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+138, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+138, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+137, 4, q_01+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+136, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+136, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+135, 4, q_01+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+134, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+134, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+133, 4, q_01+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+132, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+132, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+131, 4, q_01+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+130, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+130, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+129, 4, q_01+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+128, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+128, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+127, 4, q_01+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+126, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+126, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+125, 4, q_01+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+124, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+124, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+123, 4, q_01+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+122, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+122, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+121, 4, q_01+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+120, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+120, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+119, 4, q_01+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+118, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+118, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+117, 4, q_01+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+116, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+116, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+115, 4, q_01+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+114, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+114, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+113, 4, q_01+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+112, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+112, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+111, 4, q_01+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+110, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+110, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+109, 4, q_01+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+108, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+108, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+107, 4, q_01+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+106, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+106, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+105, 4, q_01+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+104, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+104, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+103, 4, q_01+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+102, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+102, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+101, 4, q_01+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+100, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+100, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+99, 4, q_01+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+98, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+98, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+97, 4, q_01+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+96, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+96, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+95, 4, q_01+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+94, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+94, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+93, 4, q_01+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+92, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+92, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+91, 4, q_01+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+90, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+90, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+89, 4, q_01+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+88, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+88, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+87, 4, q_01+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+86, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+86, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+85, 4, q_01+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+84, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+84, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+83, 4, q_01+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+82, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+82, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+81, 4, q_01+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+80, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+80, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+79, 4, q_01+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+78, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+78, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+77, 4, q_01+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+76, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+76, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+75, 4, q_01+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+74, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+74, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+73, 4, q_01+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+72, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+72, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+71, 4, q_01+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+70, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+70, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+69, 4, q_01+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+68, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+68, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+67, 4, q_01+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+66, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+66, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+65, 4, q_01+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+64, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+64, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+63, 4, q_01+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+62, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+62, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+61, 4, q_01+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+60, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+60, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+59, 4, q_01+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+58, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+58, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+57, 4, q_01+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+56, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+56, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+55, 4, q_01+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+54, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+54, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+53, 4, q_01+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+52, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+52, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+51, 4, q_01+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+50, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+50, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+49, 4, q_01+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+48, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+48, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+47, 4, q_01+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+46, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+46, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+45, 4, q_01+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+44, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+44, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+43, 4, q_01+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+42, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+42, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+41, 4, q_01+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+40, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+40, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+39, 4, q_01+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+38, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+38, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+37, 4, q_01+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+36, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+36, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+35, 4, q_01+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+34, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+34, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+33, 4, q_01+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+32, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+32, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+31, 4, q_01+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+30, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+30, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+29, 4, q_01+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+28, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+28, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+27, 4, q_01+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+26, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+26, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+25, 4, q_01+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+24, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+24, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+23, 4, q_01+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+22, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+22, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+21, 4, q_01+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+20, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+20, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+19, 4, q_01+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+18, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+18, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+17, 4, q_01+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+16, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+16, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+15, 4, q_01+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+14, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+14, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+13, 4, q_01+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+12, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+12, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+11, 4, q_01+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+10, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+10, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+9, 4, q_01+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+8, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+8, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+7, 4, q_01+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+6, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+6, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+5, 4, q_01+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+4, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+4, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+3, 4, q_01+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+2, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+2, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+1, 4, q_01+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+397+0, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_01+397+0, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+0, 3, q_01+0, 3, temp+1);
	memset(q_10+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(396, temp, 198, p_00+403+2, 198, q_10+397);
	GF2X_MUL(396, temp2, 198, p_10+403+2, 198, q_11+397);
	gf2x_add(396, q_10+0+1, 396, temp, 396, temp2);
	GF2X_MUL(4, temp, 2, q_10+397+196, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+196, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+195, 4, q_10+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+194, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+194, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+193, 4, q_10+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+192, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+192, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+191, 4, q_10+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+190, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+190, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+189, 4, q_10+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+188, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+188, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+187, 4, q_10+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+186, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+186, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+185, 4, q_10+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+184, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+184, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+183, 4, q_10+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+182, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+182, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+181, 4, q_10+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+180, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+180, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+179, 4, q_10+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+178, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+178, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+177, 4, q_10+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+176, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+176, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+175, 4, q_10+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+174, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+174, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+173, 4, q_10+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+172, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+172, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+171, 4, q_10+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+170, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+170, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+169, 4, q_10+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+168, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+168, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+167, 4, q_10+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+166, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+166, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+165, 4, q_10+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+164, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+164, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+163, 4, q_10+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+162, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+162, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+161, 4, q_10+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+160, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+160, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+159, 4, q_10+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+158, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+158, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+157, 4, q_10+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+156, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+156, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+155, 4, q_10+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+154, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+154, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+153, 4, q_10+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+152, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+152, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+151, 4, q_10+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+150, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+150, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+149, 4, q_10+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+148, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+148, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+147, 4, q_10+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+146, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+146, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+145, 4, q_10+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+144, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+144, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+143, 4, q_10+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+142, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+142, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+141, 4, q_10+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+140, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+140, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+139, 4, q_10+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+138, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+138, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+137, 4, q_10+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+136, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+136, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+135, 4, q_10+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+134, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+134, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+133, 4, q_10+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+132, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+132, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+131, 4, q_10+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+130, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+130, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+129, 4, q_10+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+128, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+128, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+127, 4, q_10+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+126, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+126, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+125, 4, q_10+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+124, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+124, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+123, 4, q_10+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+122, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+122, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+121, 4, q_10+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+120, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+120, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+119, 4, q_10+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+118, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+118, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+117, 4, q_10+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+116, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+116, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+115, 4, q_10+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+114, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+114, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+113, 4, q_10+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+112, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+112, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+111, 4, q_10+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+110, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+110, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+109, 4, q_10+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+108, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+108, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+107, 4, q_10+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+106, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+106, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+105, 4, q_10+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+104, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+104, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+103, 4, q_10+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+102, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+102, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+101, 4, q_10+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+100, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+100, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+99, 4, q_10+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+98, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+98, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+97, 4, q_10+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+96, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+96, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+95, 4, q_10+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+94, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+94, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+93, 4, q_10+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+92, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+92, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+91, 4, q_10+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+90, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+90, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+89, 4, q_10+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+88, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+88, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+87, 4, q_10+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+86, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+86, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+85, 4, q_10+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+84, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+84, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+83, 4, q_10+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+82, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+82, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+81, 4, q_10+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+80, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+80, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+79, 4, q_10+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+78, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+78, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+77, 4, q_10+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+76, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+76, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+75, 4, q_10+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+74, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+74, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+73, 4, q_10+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+72, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+72, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+71, 4, q_10+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+70, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+70, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+69, 4, q_10+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+68, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+68, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+67, 4, q_10+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+66, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+66, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+65, 4, q_10+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+64, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+64, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+63, 4, q_10+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+62, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+62, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+61, 4, q_10+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+60, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+60, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+59, 4, q_10+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+58, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+58, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+57, 4, q_10+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+56, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+56, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+55, 4, q_10+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+54, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+54, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+53, 4, q_10+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+52, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+52, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+51, 4, q_10+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+50, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+50, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+49, 4, q_10+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+48, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+48, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+47, 4, q_10+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+46, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+46, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+45, 4, q_10+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+44, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+44, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+43, 4, q_10+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+42, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+42, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+41, 4, q_10+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+40, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+40, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+39, 4, q_10+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+38, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+38, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+37, 4, q_10+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+36, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+36, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+35, 4, q_10+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+34, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+34, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+33, 4, q_10+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+32, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+32, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+31, 4, q_10+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+30, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+30, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+29, 4, q_10+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+28, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+28, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+27, 4, q_10+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+26, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+26, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+25, 4, q_10+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+24, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+24, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+23, 4, q_10+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+22, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+22, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+21, 4, q_10+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+20, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+20, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+19, 4, q_10+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+18, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+18, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+17, 4, q_10+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+16, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+16, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+15, 4, q_10+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+14, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+14, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+13, 4, q_10+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+12, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+12, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+11, 4, q_10+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+10, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+10, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+9, 4, q_10+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+8, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+8, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+7, 4, q_10+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+6, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+6, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+5, 4, q_10+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+4, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+4, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+3, 4, q_10+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+2, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+2, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+1, 4, q_10+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+0, 2, p_00+403);
	GF2X_MUL(4, temp2, 2, q_11+397+0, 2, p_10+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+0, 3, q_10+0, 3, temp+1);
	memset(q_11+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(396, temp, 198, p_01+403+2, 198, q_10+397);
	GF2X_MUL(396, temp2, 198, p_11+403+2, 198, q_11+397);
	gf2x_add(396, q_11+0+1, 396, temp, 396, temp2);
	GF2X_MUL(4, temp, 2, q_10+397+196, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+196, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+195, 4, q_11+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+194, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+194, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+193, 4, q_11+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+192, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+192, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+191, 4, q_11+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+190, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+190, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+189, 4, q_11+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+188, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+188, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+187, 4, q_11+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+186, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+186, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+185, 4, q_11+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+184, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+184, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+183, 4, q_11+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+182, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+182, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+181, 4, q_11+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+180, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+180, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+179, 4, q_11+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+178, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+178, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+177, 4, q_11+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+176, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+176, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+175, 4, q_11+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+174, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+174, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+173, 4, q_11+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+172, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+172, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+171, 4, q_11+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+170, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+170, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+169, 4, q_11+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+168, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+168, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+167, 4, q_11+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+166, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+166, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+165, 4, q_11+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+164, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+164, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+163, 4, q_11+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+162, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+162, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+161, 4, q_11+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+160, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+160, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+159, 4, q_11+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+158, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+158, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+157, 4, q_11+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+156, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+156, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+155, 4, q_11+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+154, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+154, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+153, 4, q_11+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+152, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+152, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+151, 4, q_11+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+150, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+150, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+149, 4, q_11+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+148, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+148, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+147, 4, q_11+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+146, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+146, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+145, 4, q_11+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+144, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+144, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+143, 4, q_11+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+142, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+142, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+141, 4, q_11+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+140, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+140, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+139, 4, q_11+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+138, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+138, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+137, 4, q_11+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+136, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+136, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+135, 4, q_11+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+134, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+134, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+133, 4, q_11+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+132, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+132, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+131, 4, q_11+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+130, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+130, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+129, 4, q_11+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+128, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+128, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+127, 4, q_11+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+126, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+126, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+125, 4, q_11+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+124, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+124, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+123, 4, q_11+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+122, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+122, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+121, 4, q_11+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+120, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+120, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+119, 4, q_11+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+118, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+118, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+117, 4, q_11+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+116, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+116, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+115, 4, q_11+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+114, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+114, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+113, 4, q_11+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+112, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+112, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+111, 4, q_11+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+110, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+110, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+109, 4, q_11+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+108, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+108, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+107, 4, q_11+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+106, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+106, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+105, 4, q_11+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+104, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+104, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+103, 4, q_11+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+102, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+102, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+101, 4, q_11+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+100, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+100, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+99, 4, q_11+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+98, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+98, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+97, 4, q_11+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+96, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+96, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+95, 4, q_11+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+94, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+94, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+93, 4, q_11+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+92, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+92, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+91, 4, q_11+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+90, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+90, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+89, 4, q_11+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+88, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+88, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+87, 4, q_11+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+86, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+86, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+85, 4, q_11+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+84, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+84, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+83, 4, q_11+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+82, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+82, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+81, 4, q_11+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+80, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+80, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+79, 4, q_11+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+78, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+78, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+77, 4, q_11+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+76, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+76, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+75, 4, q_11+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+74, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+74, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+73, 4, q_11+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+72, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+72, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+71, 4, q_11+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+70, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+70, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+69, 4, q_11+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+68, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+68, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+67, 4, q_11+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+66, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+66, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+65, 4, q_11+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+64, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+64, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+63, 4, q_11+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+62, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+62, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+61, 4, q_11+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+60, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+60, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+59, 4, q_11+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+58, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+58, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+57, 4, q_11+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+56, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+56, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+55, 4, q_11+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+54, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+54, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+53, 4, q_11+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+52, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+52, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+51, 4, q_11+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+50, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+50, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+49, 4, q_11+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+48, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+48, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+47, 4, q_11+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+46, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+46, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+45, 4, q_11+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+44, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+44, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+43, 4, q_11+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+42, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+42, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+41, 4, q_11+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+40, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+40, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+39, 4, q_11+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+38, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+38, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+37, 4, q_11+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+36, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+36, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+35, 4, q_11+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+34, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+34, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+33, 4, q_11+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+32, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+32, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+31, 4, q_11+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+30, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+30, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+29, 4, q_11+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+28, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+28, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+27, 4, q_11+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+26, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+26, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+25, 4, q_11+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+24, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+24, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+23, 4, q_11+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+22, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+22, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+21, 4, q_11+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+20, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+20, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+19, 4, q_11+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+18, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+18, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+17, 4, q_11+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+16, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+16, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+15, 4, q_11+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+14, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+14, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+13, 4, q_11+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+12, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+12, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+11, 4, q_11+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+10, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+10, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+9, 4, q_11+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+8, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+8, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+7, 4, q_11+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+6, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+6, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+5, 4, q_11+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+4, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+4, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+3, 4, q_11+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+2, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+2, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+1, 4, q_11+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+397+0, 2, p_01+403);
	GF2X_MUL(4, temp2, 2, q_11+397+0, 2, p_11+403);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+0, 3, q_11+0, 3, temp+1);
	

	// Recombining results: n: 51157, depth: 0
	memset(t_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(794, temp, 397, p_00+0+6, 397, q_00+0);
	GF2X_MUL(794, temp2, 397, p_10+0+6, 397, q_01+0);
	gf2x_add(794, t_00+0+6, 794, temp, 794, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+391, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+391, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+391, 12, t_00+0+391, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+385, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+385, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+385, 12, t_00+0+385, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+379, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+379, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+379, 12, t_00+0+379, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+373, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+373, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+373, 12, t_00+0+373, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+367, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+367, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+367, 12, t_00+0+367, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+361, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+361, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+361, 12, t_00+0+361, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+355, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+355, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+355, 12, t_00+0+355, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+349, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+349, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+349, 12, t_00+0+349, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+343, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+343, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+343, 12, t_00+0+343, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+337, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+337, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+337, 12, t_00+0+337, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+331, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+331, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+331, 12, t_00+0+331, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+325, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+325, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+325, 12, t_00+0+325, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+319, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+319, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+319, 12, t_00+0+319, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+313, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+313, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+313, 12, t_00+0+313, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+307, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+307, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+307, 12, t_00+0+307, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+301, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+301, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+301, 12, t_00+0+301, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+295, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+295, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+295, 12, t_00+0+295, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+289, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+289, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+289, 12, t_00+0+289, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+283, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+283, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+283, 12, t_00+0+283, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+277, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+277, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+277, 12, t_00+0+277, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+271, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+271, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+271, 12, t_00+0+271, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+265, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+265, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+265, 12, t_00+0+265, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+259, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+259, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+259, 12, t_00+0+259, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+253, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+253, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+253, 12, t_00+0+253, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+247, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+247, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+247, 12, t_00+0+247, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+241, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+241, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+241, 12, t_00+0+241, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+235, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+235, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+235, 12, t_00+0+235, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+229, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+229, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+229, 12, t_00+0+229, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+223, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+223, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+223, 12, t_00+0+223, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+217, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+217, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+217, 12, t_00+0+217, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+211, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+211, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+211, 12, t_00+0+211, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+205, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+205, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+205, 12, t_00+0+205, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+199, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+199, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+199, 12, t_00+0+199, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+193, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+193, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+193, 12, t_00+0+193, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+187, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+187, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+187, 12, t_00+0+187, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+181, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+181, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+181, 12, t_00+0+181, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+175, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+175, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+175, 12, t_00+0+175, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+169, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+169, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+169, 12, t_00+0+169, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+163, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+163, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+163, 12, t_00+0+163, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+157, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+157, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+157, 12, t_00+0+157, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+151, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+151, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+151, 12, t_00+0+151, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+145, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+145, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+145, 12, t_00+0+145, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+139, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+139, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+139, 12, t_00+0+139, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+133, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+133, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+133, 12, t_00+0+133, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+127, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+127, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+127, 12, t_00+0+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+121, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+121, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+121, 12, t_00+0+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+115, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+115, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+115, 12, t_00+0+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+109, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+109, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+109, 12, t_00+0+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+103, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+103, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+103, 12, t_00+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+97, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+97, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+97, 12, t_00+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+91, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+91, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+91, 12, t_00+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+85, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+85, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+85, 12, t_00+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+79, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+79, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+79, 12, t_00+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+73, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+73, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+73, 12, t_00+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+67, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+67, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+67, 12, t_00+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+61, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+61, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+61, 12, t_00+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+55, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+55, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+55, 12, t_00+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+49, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+49, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+49, 12, t_00+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+43, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+43, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+43, 12, t_00+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+37, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+37, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+37, 12, t_00+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+31, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+31, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+31, 12, t_00+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+25, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+25, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+25, 12, t_00+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+19, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+19, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+19, 12, t_00+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+13, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+13, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+13, 12, t_00+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+7, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+7, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+7, 12, t_00+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+1, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_01+0+1, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_00+0+1, 12, t_00+0+1, 12, temp);
	GF2X_MUL(2, temp, 1, p_00+0+5, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+5, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+5, 2, t_00+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+4, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+4, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+4, 2, t_00+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+3, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+3, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+3, 2, t_00+0+3, 2, temp);
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
	memset(t_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(794, temp, 397, p_01+0+6, 397, q_00+0);
	GF2X_MUL(794, temp2, 397, p_11+0+6, 397, q_01+0);
	gf2x_add(794, t_01+0+6, 794, temp, 794, temp2);
	GF2X_MUL(12, temp, 6, q_00+0+391, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+391, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+391, 12, t_01+0+391, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+385, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+385, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+385, 12, t_01+0+385, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+379, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+379, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+379, 12, t_01+0+379, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+373, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+373, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+373, 12, t_01+0+373, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+367, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+367, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+367, 12, t_01+0+367, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+361, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+361, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+361, 12, t_01+0+361, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+355, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+355, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+355, 12, t_01+0+355, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+349, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+349, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+349, 12, t_01+0+349, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+343, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+343, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+343, 12, t_01+0+343, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+337, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+337, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+337, 12, t_01+0+337, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+331, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+331, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+331, 12, t_01+0+331, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+325, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+325, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+325, 12, t_01+0+325, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+319, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+319, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+319, 12, t_01+0+319, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+313, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+313, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+313, 12, t_01+0+313, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+307, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+307, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+307, 12, t_01+0+307, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+301, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+301, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+301, 12, t_01+0+301, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+295, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+295, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+295, 12, t_01+0+295, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+289, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+289, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+289, 12, t_01+0+289, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+283, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+283, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+283, 12, t_01+0+283, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+277, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+277, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+277, 12, t_01+0+277, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+271, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+271, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+271, 12, t_01+0+271, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+265, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+265, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+265, 12, t_01+0+265, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+259, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+259, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+259, 12, t_01+0+259, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+253, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+253, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+253, 12, t_01+0+253, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+247, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+247, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+247, 12, t_01+0+247, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+241, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+241, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+241, 12, t_01+0+241, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+235, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+235, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+235, 12, t_01+0+235, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+229, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+229, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+229, 12, t_01+0+229, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+223, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+223, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+223, 12, t_01+0+223, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+217, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+217, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+217, 12, t_01+0+217, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+211, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+211, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+211, 12, t_01+0+211, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+205, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+205, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+205, 12, t_01+0+205, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+199, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+199, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+199, 12, t_01+0+199, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+193, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+193, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+193, 12, t_01+0+193, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+187, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+187, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+187, 12, t_01+0+187, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+181, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+181, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+181, 12, t_01+0+181, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+175, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+175, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+175, 12, t_01+0+175, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+169, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+169, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+169, 12, t_01+0+169, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+163, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+163, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+163, 12, t_01+0+163, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+157, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+157, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+157, 12, t_01+0+157, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+151, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+151, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+151, 12, t_01+0+151, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+145, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+145, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+145, 12, t_01+0+145, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+139, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+139, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+139, 12, t_01+0+139, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+133, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+133, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+133, 12, t_01+0+133, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+127, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+127, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+127, 12, t_01+0+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+121, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+121, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+121, 12, t_01+0+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+115, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+115, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+115, 12, t_01+0+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+109, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+109, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+109, 12, t_01+0+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+103, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+103, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+103, 12, t_01+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+97, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+97, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+97, 12, t_01+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+91, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+91, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+91, 12, t_01+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+85, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+85, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+85, 12, t_01+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+79, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+79, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+79, 12, t_01+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+73, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+73, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+73, 12, t_01+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+67, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+67, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+67, 12, t_01+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+61, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+61, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+61, 12, t_01+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+55, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+55, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+55, 12, t_01+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+49, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+49, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+49, 12, t_01+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+43, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+43, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+43, 12, t_01+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+37, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+37, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+37, 12, t_01+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+31, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+31, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+31, 12, t_01+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+25, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+25, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+25, 12, t_01+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+19, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+19, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+19, 12, t_01+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+13, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+13, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+13, 12, t_01+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+7, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+7, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+7, 12, t_01+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+0+1, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_01+0+1, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_01+0+1, 12, t_01+0+1, 12, temp);
	GF2X_MUL(2, temp, 1, p_01+0+5, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+5, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+5, 2, t_01+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+4, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+4, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+4, 2, t_01+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+3, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+3, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+3, 2, t_01+0+3, 2, temp);
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
	memset(t_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(794, temp, 397, p_00+0+6, 397, q_10+0);
	GF2X_MUL(794, temp2, 397, p_10+0+6, 397, q_11+0);
	gf2x_add(794, t_10+0+6, 794, temp, 794, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+391, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+391, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+391, 12, t_10+0+391, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+385, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+385, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+385, 12, t_10+0+385, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+379, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+379, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+379, 12, t_10+0+379, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+373, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+373, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+373, 12, t_10+0+373, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+367, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+367, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+367, 12, t_10+0+367, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+361, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+361, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+361, 12, t_10+0+361, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+355, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+355, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+355, 12, t_10+0+355, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+349, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+349, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+349, 12, t_10+0+349, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+343, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+343, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+343, 12, t_10+0+343, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+337, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+337, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+337, 12, t_10+0+337, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+331, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+331, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+331, 12, t_10+0+331, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+325, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+325, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+325, 12, t_10+0+325, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+319, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+319, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+319, 12, t_10+0+319, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+313, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+313, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+313, 12, t_10+0+313, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+307, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+307, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+307, 12, t_10+0+307, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+301, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+301, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+301, 12, t_10+0+301, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+295, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+295, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+295, 12, t_10+0+295, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+289, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+289, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+289, 12, t_10+0+289, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+283, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+283, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+283, 12, t_10+0+283, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+277, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+277, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+277, 12, t_10+0+277, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+271, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+271, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+271, 12, t_10+0+271, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+265, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+265, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+265, 12, t_10+0+265, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+259, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+259, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+259, 12, t_10+0+259, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+253, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+253, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+253, 12, t_10+0+253, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+247, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+247, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+247, 12, t_10+0+247, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+241, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+241, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+241, 12, t_10+0+241, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+235, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+235, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+235, 12, t_10+0+235, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+229, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+229, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+229, 12, t_10+0+229, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+223, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+223, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+223, 12, t_10+0+223, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+217, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+217, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+217, 12, t_10+0+217, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+211, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+211, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+211, 12, t_10+0+211, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+205, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+205, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+205, 12, t_10+0+205, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+199, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+199, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+199, 12, t_10+0+199, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+193, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+193, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+193, 12, t_10+0+193, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+187, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+187, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+187, 12, t_10+0+187, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+181, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+181, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+181, 12, t_10+0+181, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+175, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+175, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+175, 12, t_10+0+175, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+169, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+169, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+169, 12, t_10+0+169, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+163, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+163, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+163, 12, t_10+0+163, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+157, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+157, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+157, 12, t_10+0+157, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+151, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+151, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+151, 12, t_10+0+151, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+145, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+145, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+145, 12, t_10+0+145, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+139, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+139, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+139, 12, t_10+0+139, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+133, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+133, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+133, 12, t_10+0+133, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+127, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+127, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+127, 12, t_10+0+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+121, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+121, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+121, 12, t_10+0+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+115, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+115, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+115, 12, t_10+0+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+109, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+109, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+109, 12, t_10+0+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+103, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+103, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+103, 12, t_10+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+97, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+97, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+97, 12, t_10+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+91, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+91, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+91, 12, t_10+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+85, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+85, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+85, 12, t_10+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+79, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+79, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+79, 12, t_10+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+73, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+73, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+73, 12, t_10+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+67, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+67, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+67, 12, t_10+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+61, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+61, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+61, 12, t_10+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+55, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+55, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+55, 12, t_10+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+49, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+49, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+49, 12, t_10+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+43, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+43, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+43, 12, t_10+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+37, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+37, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+37, 12, t_10+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+31, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+31, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+31, 12, t_10+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+25, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+25, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+25, 12, t_10+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+19, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+19, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+19, 12, t_10+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+13, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+13, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+13, 12, t_10+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+7, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+7, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+7, 12, t_10+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+1, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, q_11+0+1, 6, p_10+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_10+0+1, 12, t_10+0+1, 12, temp);
	GF2X_MUL(2, temp, 1, p_00+0+5, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+5, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+5, 2, t_10+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+4, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+4, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+4, 2, t_10+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+3, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+3, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+3, 2, t_10+0+3, 2, temp);
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
	memset(t_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(794, temp, 397, p_01+0+6, 397, q_10+0);
	GF2X_MUL(794, temp2, 397, p_11+0+6, 397, q_11+0);
	gf2x_add(794, t_11+0+6, 794, temp, 794, temp2);
	GF2X_MUL(12, temp, 6, q_10+0+391, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+391, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+391, 12, t_11+0+391, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+385, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+385, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+385, 12, t_11+0+385, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+379, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+379, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+379, 12, t_11+0+379, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+373, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+373, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+373, 12, t_11+0+373, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+367, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+367, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+367, 12, t_11+0+367, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+361, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+361, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+361, 12, t_11+0+361, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+355, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+355, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+355, 12, t_11+0+355, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+349, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+349, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+349, 12, t_11+0+349, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+343, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+343, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+343, 12, t_11+0+343, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+337, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+337, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+337, 12, t_11+0+337, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+331, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+331, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+331, 12, t_11+0+331, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+325, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+325, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+325, 12, t_11+0+325, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+319, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+319, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+319, 12, t_11+0+319, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+313, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+313, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+313, 12, t_11+0+313, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+307, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+307, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+307, 12, t_11+0+307, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+301, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+301, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+301, 12, t_11+0+301, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+295, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+295, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+295, 12, t_11+0+295, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+289, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+289, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+289, 12, t_11+0+289, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+283, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+283, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+283, 12, t_11+0+283, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+277, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+277, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+277, 12, t_11+0+277, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+271, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+271, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+271, 12, t_11+0+271, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+265, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+265, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+265, 12, t_11+0+265, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+259, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+259, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+259, 12, t_11+0+259, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+253, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+253, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+253, 12, t_11+0+253, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+247, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+247, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+247, 12, t_11+0+247, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+241, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+241, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+241, 12, t_11+0+241, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+235, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+235, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+235, 12, t_11+0+235, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+229, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+229, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+229, 12, t_11+0+229, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+223, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+223, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+223, 12, t_11+0+223, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+217, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+217, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+217, 12, t_11+0+217, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+211, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+211, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+211, 12, t_11+0+211, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+205, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+205, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+205, 12, t_11+0+205, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+199, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+199, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+199, 12, t_11+0+199, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+193, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+193, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+193, 12, t_11+0+193, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+187, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+187, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+187, 12, t_11+0+187, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+181, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+181, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+181, 12, t_11+0+181, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+175, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+175, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+175, 12, t_11+0+175, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+169, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+169, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+169, 12, t_11+0+169, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+163, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+163, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+163, 12, t_11+0+163, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+157, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+157, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+157, 12, t_11+0+157, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+151, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+151, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+151, 12, t_11+0+151, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+145, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+145, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+145, 12, t_11+0+145, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+139, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+139, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+139, 12, t_11+0+139, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+133, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+133, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+133, 12, t_11+0+133, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+127, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+127, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+127, 12, t_11+0+127, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+121, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+121, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+121, 12, t_11+0+121, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+115, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+115, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+115, 12, t_11+0+115, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+109, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+109, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+109, 12, t_11+0+109, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+103, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+103, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+103, 12, t_11+0+103, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+97, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+97, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+97, 12, t_11+0+97, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+91, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+91, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+91, 12, t_11+0+91, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+85, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+85, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+85, 12, t_11+0+85, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+79, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+79, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+79, 12, t_11+0+79, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+73, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+73, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+73, 12, t_11+0+73, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+67, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+67, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+67, 12, t_11+0+67, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+61, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+61, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+61, 12, t_11+0+61, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+55, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+55, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+55, 12, t_11+0+55, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+49, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+49, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+49, 12, t_11+0+49, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+43, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+43, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+43, 12, t_11+0+43, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+37, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+37, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+37, 12, t_11+0+37, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+31, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+31, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+31, 12, t_11+0+31, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+25, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+25, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+25, 12, t_11+0+25, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+19, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+19, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+19, 12, t_11+0+19, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+13, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+13, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+13, 12, t_11+0+13, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+7, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+7, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+7, 12, t_11+0+7, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+0+1, 6, p_01+0);
	GF2X_MUL(12, temp2, 6, q_11+0+1, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, t_11+0+1, 12, t_11+0+1, 12, temp);
	GF2X_MUL(2, temp, 1, p_01+0+5, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+5, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+5, 2, t_11+0+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+4, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+4, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+4, 2, t_11+0+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+3, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+3, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+3, 2, t_11+0+3, 2, temp);
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