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

int jumpdivstep_20981(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[675];
	DIGIT p_01[675];
	DIGIT p_10[675];
	DIGIT p_11[675];
	
	DIGIT q_00[653];
	DIGIT q_01[653];
	DIGIT q_10[653];
	DIGIT q_11[653];
	
	DIGIT f_sum[2011];
	DIGIT g_sum[2011];
	
	DIGIT temp[1318];
	DIGIT temp2[1318];
	

	delta = divstepsx_256(255, delta, f+652, g+652, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+648+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g+648+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+648+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g+648+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f+648+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g+648+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+648+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g+648+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+644+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g+644+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f+644);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g+644);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f+644+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g+644+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f+644);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g+644);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+632+12, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g+632+12, 12, p_01+651);
	gf2x_add(24, f_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+632+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g+632+0, 12, p_01+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1939, 12, f_sum+1939, 12, temp+12);
	right_bit_shift_n(24, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f+632+12, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g+632+12, 12, p_11+651);
	gf2x_add(24, g_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+632+0, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g+632+0, 12, p_11+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1939, 12, g_sum+1939, 12, temp+12);
	right_bit_shift_n(24, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1948, g_sum+1948, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, q_00+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, q_01+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, q_10+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, q_11+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_10+651);
	gf2x_add(24, p_00+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_11+651);
	gf2x_add(24, p_01+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_10+651);
	gf2x_add(24, p_10+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_11+651);
	gf2x_add(24, p_11+627+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f+612+20, 24, p_00+627);
	GF2X_MUL(48, temp2, 24, g+612+20, 24, p_01+627);
	gf2x_add(44, f_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, f+612);
	GF2X_MUL(40, temp2, 20, p_01+627+4, 20, g+612);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(44, f_sum+1870, 58);
	GF2X_MUL(48, temp, 24, f+612+20, 24, p_10+627);
	GF2X_MUL(48, temp2, 24, g+612+20, 24, p_11+627);
	gf2x_add(44, g_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+627+4, 20, f+612);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, g+612);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(44, g_sum+1870, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_01+613);
	gf2x_add(40, p_00+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+16, 8, p_00+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+12, 8, p_00+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+8, 8, p_00+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+4, 8, p_00+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+0, 8, p_00+583+0, 8, temp);
	memset(p_01+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_01+613);
	gf2x_add(40, p_01+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+16, 8, p_01+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+12, 8, p_01+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+8, 8, p_01+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+4, 8, p_01+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+0, 8, p_01+583+0, 8, temp);
	memset(p_10+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_11+613);
	gf2x_add(40, p_10+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+16, 8, p_10+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+12, 8, p_10+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+8, 8, p_10+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+4, 8, p_10+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+0, 8, p_10+583+0, 8, temp);
	memset(p_11+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_11+613);
	gf2x_add(40, p_11+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+16, 8, p_11+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+12, 8, p_11+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+8, 8, p_11+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+4, 8, p_11+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+0, 8, p_11+583+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f+572+40, 44, p_00+583);
	GF2X_MUL(88, temp2, 44, g+572+40, 44, p_01+583);
	gf2x_add(84, f_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, f+572);
	GF2X_MUL(80, temp2, 40, p_01+583+4, 40, g+572);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(84, f_sum+1741, 53);
	GF2X_MUL(88, temp, 44, f+572+40, 44, p_10+583);
	GF2X_MUL(88, temp2, 44, g+572+40, 44, p_11+583);
	gf2x_add(84, g_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+583+4, 40, f+572);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, g+572);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(84, g_sum+1741, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_01+573);
	gf2x_add(80, p_00+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+36, 8, p_00+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+32, 8, p_00+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+28, 8, p_00+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+24, 8, p_00+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+20, 8, p_00+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+16, 8, p_00+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+12, 8, p_00+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+8, 8, p_00+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+4, 8, p_00+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+0, 8, p_00+499+0, 8, temp);
	memset(p_01+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_01+573);
	gf2x_add(80, p_01+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+36, 8, p_01+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+32, 8, p_01+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+28, 8, p_01+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+24, 8, p_01+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+20, 8, p_01+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+16, 8, p_01+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+12, 8, p_01+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+8, 8, p_01+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+4, 8, p_01+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+0, 8, p_01+499+0, 8, temp);
	memset(p_10+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_11+573);
	gf2x_add(80, p_10+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+36, 8, p_10+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+32, 8, p_10+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+28, 8, p_10+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+24, 8, p_10+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+20, 8, p_10+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+16, 8, p_10+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+12, 8, p_10+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+8, 8, p_10+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+4, 8, p_10+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+0, 8, p_10+499+0, 8, temp);
	memset(p_11+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_11+573);
	gf2x_add(80, p_11+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+36, 8, p_11+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+32, 8, p_11+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+28, 8, p_11+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+24, 8, p_11+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+20, 8, p_11+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+16, 8, p_11+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+12, 8, p_11+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+8, 8, p_11+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+4, 8, p_11+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+0, 8, p_11+499+0, 8, temp);
	

	// Calculating left operands: n: 10710, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f+488+84, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, g+488+84, 84, p_01+499);
	gf2x_add(168, f_sum+1488+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, f+488+0, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, g+488+0, 84, p_01+499);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, f_sum+1488, 84, f_sum+1488, 84, temp+84);
	right_bit_shift_n(168, f_sum+1488, 43);
	GF2X_MUL(168, temp, 84, f+488+84, 84, p_10+499);
	GF2X_MUL(168, temp2, 84, g+488+84, 84, p_11+499);
	gf2x_add(168, g_sum+1488+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, f+488+0, 84, p_10+499);
	GF2X_MUL(168, temp2, 84, g+488+0, 84, p_11+499);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, g_sum+1488, 84, g_sum+1488, 84, temp+84);
	right_bit_shift_n(168, g_sum+1488, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1569, g_sum+1569, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1565+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1565+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1565+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1565+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1565+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1565+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1565+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1565+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1561+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1561+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1561);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1561);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1561+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1561+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1561);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1561);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1549+12, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+12, 12, p_01+651);
	gf2x_add(24, f_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1549+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+0, 12, p_01+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1939, 12, f_sum+1939, 12, temp+12);
	right_bit_shift_n(24, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1549+12, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+12, 12, p_11+651);
	gf2x_add(24, g_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1549+0, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+0, 12, p_11+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1939, 12, g_sum+1939, 12, temp+12);
	right_bit_shift_n(24, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1948, g_sum+1948, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, q_00+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, q_01+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, q_10+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, q_11+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_10+651);
	gf2x_add(24, p_00+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_11+651);
	gf2x_add(24, p_01+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_10+651);
	gf2x_add(24, p_10+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_11+651);
	gf2x_add(24, p_11+627+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1529+20, 24, p_00+627);
	GF2X_MUL(48, temp2, 24, g_sum+1529+20, 24, p_01+627);
	gf2x_add(44, f_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, f_sum+1529);
	GF2X_MUL(40, temp2, 20, p_01+627+4, 20, g_sum+1529);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(44, f_sum+1870, 58);
	GF2X_MUL(48, temp, 24, f_sum+1529+20, 24, p_10+627);
	GF2X_MUL(48, temp2, 24, g_sum+1529+20, 24, p_11+627);
	gf2x_add(44, g_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+627+4, 20, f_sum+1529);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, g_sum+1529);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(44, g_sum+1870, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_01+613);
	gf2x_add(40, p_00+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+16, 8, p_00+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+12, 8, p_00+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+8, 8, p_00+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+4, 8, p_00+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+0, 8, p_00+583+0, 8, temp);
	memset(p_01+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_01+613);
	gf2x_add(40, p_01+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+16, 8, p_01+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+12, 8, p_01+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+8, 8, p_01+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+4, 8, p_01+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+0, 8, p_01+583+0, 8, temp);
	memset(p_10+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_11+613);
	gf2x_add(40, p_10+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+16, 8, p_10+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+12, 8, p_10+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+8, 8, p_10+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+4, 8, p_10+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+0, 8, p_10+583+0, 8, temp);
	memset(p_11+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_11+613);
	gf2x_add(40, p_11+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+16, 8, p_11+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+12, 8, p_11+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+8, 8, p_11+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+4, 8, p_11+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+0, 8, p_11+583+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1489+40, 44, p_00+583);
	GF2X_MUL(88, temp2, 44, g_sum+1489+40, 44, p_01+583);
	gf2x_add(84, f_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, f_sum+1489);
	GF2X_MUL(80, temp2, 40, p_01+583+4, 40, g_sum+1489);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(84, f_sum+1741, 53);
	GF2X_MUL(88, temp, 44, f_sum+1489+40, 44, p_10+583);
	GF2X_MUL(88, temp2, 44, g_sum+1489+40, 44, p_11+583);
	gf2x_add(84, g_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+583+4, 40, f_sum+1489);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, g_sum+1489);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(84, g_sum+1741, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(q_00+489, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_01+573);
	gf2x_add(80, q_00+489+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+36, 8, q_00+489+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+32, 8, q_00+489+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+28, 8, q_00+489+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+24, 8, q_00+489+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+20, 8, q_00+489+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+16, 8, q_00+489+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+12, 8, q_00+489+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+8, 8, q_00+489+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+4, 8, q_00+489+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+489+0, 8, q_00+489+0, 8, temp);
	memset(q_01+489, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_01+573);
	gf2x_add(80, q_01+489+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+36, 8, q_01+489+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+32, 8, q_01+489+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+28, 8, q_01+489+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+24, 8, q_01+489+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+20, 8, q_01+489+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+16, 8, q_01+489+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+12, 8, q_01+489+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+8, 8, q_01+489+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+4, 8, q_01+489+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+489+0, 8, q_01+489+0, 8, temp);
	memset(q_10+489, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_11+573);
	gf2x_add(80, q_10+489+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+36, 8, q_10+489+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+32, 8, q_10+489+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+28, 8, q_10+489+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+24, 8, q_10+489+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+20, 8, q_10+489+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+16, 8, q_10+489+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+12, 8, q_10+489+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+8, 8, q_10+489+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+4, 8, q_10+489+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+489+0, 8, q_10+489+0, 8, temp);
	memset(q_11+489, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_11+573);
	gf2x_add(80, q_11+489+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+36, 8, q_11+489+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+32, 8, q_11+489+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+28, 8, q_11+489+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+24, 8, q_11+489+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+20, 8, q_11+489+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+16, 8, q_11+489+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+12, 8, q_11+489+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+8, 8, q_11+489+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+4, 8, q_11+489+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+489+0, 8, q_11+489+0, 8, temp);
	

	// Recombining results: n: 10710, depth: 2
	GF2X_MUL(168, temp, 84, q_00+489+0, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, q_01+489+0, 84, p_10+499);
	gf2x_add(168, p_00+331+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_00+489+0, 84, p_01+499);
	GF2X_MUL(168, temp2, 84, q_01+489+0, 84, p_11+499);
	gf2x_add(168, p_01+331+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_10+489+0, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, q_11+489+0, 84, p_10+499);
	gf2x_add(168, p_10+331+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_10+489+0, 84, p_01+499);
	GF2X_MUL(168, temp2, 84, q_11+489+0, 84, p_11+499);
	gf2x_add(168, p_11+331+0, 168, temp, 168, temp2);
	

	// Calculating left operands: n: 21165, depth: 1
	// Digits to shift: 167
	// Displacement: 167
	GF2X_MUL(336, temp, 168, f+325+163, 168, p_00+331);
	GF2X_MUL(336, temp2, 168, g+325+163, 168, p_01+331);
	gf2x_add(332, f_sum+988, 332, temp+4, 332, temp2+4);
	GF2X_MUL(326, temp, 163, p_00+331+5, 163, f+325);
	GF2X_MUL(326, temp2, 163, p_01+331+5, 163, g+325);
	gf2x_add(326, temp, 326, temp, 326, temp2);
	gf2x_add(164, f_sum+988, 164, f_sum+988, 164, temp+162);
	GF2X_MUL(10, temp, 5, f+325+158, 5, p_00+331);
	GF2X_MUL(10, temp2, 5, g+325+158, 5, p_01+331);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+988, 1, f_sum+988, 1, temp+9);
	right_bit_shift_n(331, f_sum+988, 22);
	GF2X_MUL(336, temp, 168, f+325+163, 168, p_10+331);
	GF2X_MUL(336, temp2, 168, g+325+163, 168, p_11+331);
	gf2x_add(332, g_sum+988, 332, temp+4, 332, temp2+4);
	GF2X_MUL(326, temp, 163, p_10+331+5, 163, f+325);
	GF2X_MUL(326, temp2, 163, p_11+331+5, 163, g+325);
	gf2x_add(326, temp, 326, temp, 326, temp2);
	gf2x_add(164, g_sum+988, 164, g_sum+988, 164, temp+162);
	GF2X_MUL(10, temp, 5, f+325+158, 5, p_10+331);
	GF2X_MUL(10, temp2, 5, g+325+158, 5, p_11+331);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+988, 1, g_sum+988, 1, temp+9);
	right_bit_shift_n(331, g_sum+988, 22);
	

	delta = divstepsx_256(255, delta, f_sum+1149, g_sum+1149, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1145+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1145+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1145+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1145+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1145+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1145+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1145+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1145+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1141+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1141+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1141);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1141);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1141+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1141+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1141);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1141);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1129+12, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1129+12, 12, p_01+651);
	gf2x_add(24, f_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1129+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1129+0, 12, p_01+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1939, 12, f_sum+1939, 12, temp+12);
	right_bit_shift_n(24, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1129+12, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1129+12, 12, p_11+651);
	gf2x_add(24, g_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1129+0, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1129+0, 12, p_11+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1939, 12, g_sum+1939, 12, temp+12);
	right_bit_shift_n(24, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1948, g_sum+1948, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, q_00+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, q_01+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, q_10+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, q_11+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_10+651);
	gf2x_add(24, p_00+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_11+651);
	gf2x_add(24, p_01+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_10+651);
	gf2x_add(24, p_10+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_11+651);
	gf2x_add(24, p_11+627+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1109+20, 24, p_00+627);
	GF2X_MUL(48, temp2, 24, g_sum+1109+20, 24, p_01+627);
	gf2x_add(44, f_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, f_sum+1109);
	GF2X_MUL(40, temp2, 20, p_01+627+4, 20, g_sum+1109);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(44, f_sum+1870, 58);
	GF2X_MUL(48, temp, 24, f_sum+1109+20, 24, p_10+627);
	GF2X_MUL(48, temp2, 24, g_sum+1109+20, 24, p_11+627);
	gf2x_add(44, g_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+627+4, 20, f_sum+1109);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, g_sum+1109);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(44, g_sum+1870, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_01+613);
	gf2x_add(40, p_00+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+16, 8, p_00+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+12, 8, p_00+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+8, 8, p_00+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+4, 8, p_00+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+0, 8, p_00+583+0, 8, temp);
	memset(p_01+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_01+613);
	gf2x_add(40, p_01+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+16, 8, p_01+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+12, 8, p_01+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+8, 8, p_01+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+4, 8, p_01+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+0, 8, p_01+583+0, 8, temp);
	memset(p_10+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_11+613);
	gf2x_add(40, p_10+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+16, 8, p_10+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+12, 8, p_10+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+8, 8, p_10+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+4, 8, p_10+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+0, 8, p_10+583+0, 8, temp);
	memset(p_11+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_11+613);
	gf2x_add(40, p_11+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+16, 8, p_11+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+12, 8, p_11+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+8, 8, p_11+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+4, 8, p_11+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+0, 8, p_11+583+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1069+40, 44, p_00+583);
	GF2X_MUL(88, temp2, 44, g_sum+1069+40, 44, p_01+583);
	gf2x_add(84, f_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, f_sum+1069);
	GF2X_MUL(80, temp2, 40, p_01+583+4, 40, g_sum+1069);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(84, f_sum+1741, 53);
	GF2X_MUL(88, temp, 44, f_sum+1069+40, 44, p_10+583);
	GF2X_MUL(88, temp2, 44, g_sum+1069+40, 44, p_11+583);
	gf2x_add(84, g_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+583+4, 40, f_sum+1069);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, g_sum+1069);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(84, g_sum+1741, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_01+573);
	gf2x_add(80, p_00+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+36, 8, p_00+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+32, 8, p_00+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+28, 8, p_00+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+24, 8, p_00+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+20, 8, p_00+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+16, 8, p_00+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+12, 8, p_00+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+8, 8, p_00+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+4, 8, p_00+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+0, 8, p_00+499+0, 8, temp);
	memset(p_01+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_01+573);
	gf2x_add(80, p_01+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+36, 8, p_01+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+32, 8, p_01+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+28, 8, p_01+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+24, 8, p_01+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+20, 8, p_01+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+16, 8, p_01+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+12, 8, p_01+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+8, 8, p_01+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+4, 8, p_01+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+0, 8, p_01+499+0, 8, temp);
	memset(p_10+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_11+573);
	gf2x_add(80, p_10+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+36, 8, p_10+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+32, 8, p_10+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+28, 8, p_10+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+24, 8, p_10+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+20, 8, p_10+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+16, 8, p_10+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+12, 8, p_10+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+8, 8, p_10+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+4, 8, p_10+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+0, 8, p_10+499+0, 8, temp);
	memset(p_11+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_11+573);
	gf2x_add(80, p_11+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+36, 8, p_11+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+32, 8, p_11+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+28, 8, p_11+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+24, 8, p_11+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+20, 8, p_11+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+16, 8, p_11+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+12, 8, p_11+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+8, 8, p_11+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+4, 8, p_11+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+0, 8, p_11+499+0, 8, temp);
	

	// Calculating left operands: n: 10455, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f_sum+989+80, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, g_sum+989+80, 84, p_01+499);
	gf2x_add(164, f_sum+1488, 164, temp+4, 164, temp2+4);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, f_sum+989);
	GF2X_MUL(160, temp2, 80, p_01+499+4, 80, g_sum+989);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+1488, 80, f_sum+1488, 80, temp+80);
	right_bit_shift_n(164, f_sum+1488, 43);
	GF2X_MUL(168, temp, 84, f_sum+989+80, 84, p_10+499);
	GF2X_MUL(168, temp2, 84, g_sum+989+80, 84, p_11+499);
	gf2x_add(164, g_sum+1488, 164, temp+4, 164, temp2+4);
	GF2X_MUL(160, temp, 80, p_10+499+4, 80, f_sum+989);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, g_sum+989);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+1488, 80, g_sum+1488, 80, temp+80);
	right_bit_shift_n(164, g_sum+1488, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1565, g_sum+1565, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1561+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1561+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1561+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1561+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1557+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1557+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1557);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1557);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1557+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1557+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1557);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1557);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1549+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1549);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1549);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1549+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1549);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1549);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1529+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1529+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1529+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1529+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, p_00+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, p_01+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, p_10+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, p_11+583+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1489+40, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+40, 40, p_01+583);
	gf2x_add(80, f_sum+1741+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1489+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+0, 40, p_01+583);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(80, f_sum+1741, 54);
	GF2X_MUL(80, temp, 40, f_sum+1489+40, 40, p_10+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+40, 40, p_11+583);
	gf2x_add(80, g_sum+1741+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1489+0, 40, p_10+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+0, 40, p_11+583);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(80, g_sum+1741, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 3
	GF2X_MUL(80, temp, 40, q_00+573+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, q_01+573+0, 40, p_10+583);
	gf2x_add(80, q_00+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+573+0, 40, p_01+583);
	GF2X_MUL(80, temp2, 40, q_01+573+0, 40, p_11+583);
	gf2x_add(80, q_01+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+573+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, q_11+573+0, 40, p_10+583);
	gf2x_add(80, q_10+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+573+0, 40, p_01+583);
	GF2X_MUL(80, temp2, 40, q_11+573+0, 40, p_11+583);
	gf2x_add(80, q_11+489+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10455, depth: 2
	memset(q_00+325, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, q_00+489);
	GF2X_MUL(160, temp2, 80, p_10+499+4, 80, q_01+489);
	gf2x_add(160, q_00+325+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_00+489+76, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+76, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+76, 8, q_00+325+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+72, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+72, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+72, 8, q_00+325+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+68, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+68, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+68, 8, q_00+325+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+64, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+64, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+64, 8, q_00+325+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+60, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+60, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+60, 8, q_00+325+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+56, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+56, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+56, 8, q_00+325+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+52, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+52, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+52, 8, q_00+325+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+48, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+48, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+48, 8, q_00+325+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+44, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+44, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+44, 8, q_00+325+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+40, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+40, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+40, 8, q_00+325+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+36, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+36, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+36, 8, q_00+325+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+32, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+32, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+32, 8, q_00+325+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+28, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+28, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+28, 8, q_00+325+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+24, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+24, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+24, 8, q_00+325+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+20, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+20, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+20, 8, q_00+325+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+16, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+16, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+16, 8, q_00+325+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+12, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+12, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+12, 8, q_00+325+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+8, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+8, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+8, 8, q_00+325+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+4, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+4, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+4, 8, q_00+325+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+0, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+0, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+325+0, 8, q_00+325+0, 8, temp);
	memset(q_01+325, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_01+499+4, 80, q_00+489);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, q_01+489);
	gf2x_add(160, q_01+325+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_00+489+76, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+76, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+76, 8, q_01+325+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+72, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+72, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+72, 8, q_01+325+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+68, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+68, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+68, 8, q_01+325+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+64, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+64, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+64, 8, q_01+325+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+60, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+60, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+60, 8, q_01+325+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+56, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+56, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+56, 8, q_01+325+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+52, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+52, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+52, 8, q_01+325+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+48, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+48, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+48, 8, q_01+325+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+44, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+44, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+44, 8, q_01+325+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+40, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+40, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+40, 8, q_01+325+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+36, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+36, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+36, 8, q_01+325+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+32, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+32, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+32, 8, q_01+325+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+28, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+28, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+28, 8, q_01+325+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+24, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+24, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+24, 8, q_01+325+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+20, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+20, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+20, 8, q_01+325+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+16, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+16, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+16, 8, q_01+325+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+12, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+12, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+12, 8, q_01+325+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+8, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+8, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+8, 8, q_01+325+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+4, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+4, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+4, 8, q_01+325+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+0, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+0, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+325+0, 8, q_01+325+0, 8, temp);
	memset(q_10+325, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, q_10+489);
	GF2X_MUL(160, temp2, 80, p_10+499+4, 80, q_11+489);
	gf2x_add(160, q_10+325+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_10+489+76, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+76, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+76, 8, q_10+325+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+72, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+72, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+72, 8, q_10+325+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+68, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+68, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+68, 8, q_10+325+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+64, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+64, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+64, 8, q_10+325+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+60, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+60, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+60, 8, q_10+325+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+56, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+56, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+56, 8, q_10+325+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+52, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+52, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+52, 8, q_10+325+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+48, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+48, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+48, 8, q_10+325+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+44, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+44, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+44, 8, q_10+325+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+40, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+40, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+40, 8, q_10+325+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+36, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+36, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+36, 8, q_10+325+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+32, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+32, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+32, 8, q_10+325+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+28, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+28, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+28, 8, q_10+325+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+24, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+24, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+24, 8, q_10+325+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+20, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+20, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+20, 8, q_10+325+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+16, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+16, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+16, 8, q_10+325+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+12, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+12, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+12, 8, q_10+325+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+8, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+8, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+8, 8, q_10+325+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+4, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+4, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+4, 8, q_10+325+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+0, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+0, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+325+0, 8, q_10+325+0, 8, temp);
	memset(q_11+325, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_01+499+4, 80, q_10+489);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, q_11+489);
	gf2x_add(160, q_11+325+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_10+489+76, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+76, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+76, 8, q_11+325+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+72, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+72, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+72, 8, q_11+325+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+68, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+68, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+68, 8, q_11+325+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+64, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+64, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+64, 8, q_11+325+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+60, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+60, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+60, 8, q_11+325+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+56, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+56, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+56, 8, q_11+325+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+52, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+52, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+52, 8, q_11+325+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+48, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+48, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+48, 8, q_11+325+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+44, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+44, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+44, 8, q_11+325+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+40, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+40, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+40, 8, q_11+325+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+36, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+36, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+36, 8, q_11+325+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+32, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+32, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+32, 8, q_11+325+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+28, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+28, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+28, 8, q_11+325+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+24, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+24, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+24, 8, q_11+325+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+20, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+20, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+20, 8, q_11+325+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+16, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+16, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+16, 8, q_11+325+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+12, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+12, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+12, 8, q_11+325+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+8, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+8, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+8, 8, q_11+325+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+4, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+4, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+4, 8, q_11+325+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+0, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+0, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+325+0, 8, q_11+325+0, 8, temp);
	

	// Recombining results: n: 21165, depth: 1
	memset(p_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(328, temp, 164, p_00+331+4, 164, q_00+325);
	GF2X_MUL(328, temp2, 164, p_10+331+4, 164, q_01+325);
	gf2x_add(328, p_00+0+3, 328, temp, 328, temp2);
	GF2X_MUL(8, temp, 4, q_00+325+160, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+160, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+159, 8, p_00+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+156, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+156, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+155, 8, p_00+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+152, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+152, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+151, 8, p_00+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+148, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+148, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+147, 8, p_00+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+144, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+144, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+143, 8, p_00+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+140, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+140, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+139, 8, p_00+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+136, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+136, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+135, 8, p_00+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+132, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+132, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+131, 8, p_00+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+128, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+128, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+127, 8, p_00+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+124, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+124, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+123, 8, p_00+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+120, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+120, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+119, 8, p_00+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+116, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+116, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+115, 8, p_00+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+112, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+112, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+111, 8, p_00+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+108, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+108, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+107, 8, p_00+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+104, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+104, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+103, 8, p_00+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+100, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+100, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+99, 8, p_00+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+96, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+96, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+95, 8, p_00+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+92, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+92, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+91, 8, p_00+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+88, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+88, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+87, 8, p_00+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+84, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+84, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+83, 8, p_00+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+80, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+80, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+79, 8, p_00+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+76, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+76, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+75, 8, p_00+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+72, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+72, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+71, 8, p_00+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+68, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+68, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+67, 8, p_00+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+64, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+64, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+63, 8, p_00+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+60, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+60, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+59, 8, p_00+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+56, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+56, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+55, 8, p_00+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+52, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+52, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+51, 8, p_00+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+48, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+48, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+47, 8, p_00+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+44, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+44, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+43, 8, p_00+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+40, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+40, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+39, 8, p_00+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+36, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+36, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+35, 8, p_00+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+32, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+32, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+31, 8, p_00+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+28, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+28, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+27, 8, p_00+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+24, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+24, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+23, 8, p_00+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+20, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+20, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+19, 8, p_00+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+16, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+16, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+15, 8, p_00+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+12, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+12, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+11, 8, p_00+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+8, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+8, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+7, 8, p_00+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+4, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+4, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+3, 8, p_00+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+0, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_01+325+0, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_00+0, 7, p_00+0, 7, temp+1);
	memset(p_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(328, temp, 164, p_01+331+4, 164, q_00+325);
	GF2X_MUL(328, temp2, 164, p_11+331+4, 164, q_01+325);
	gf2x_add(328, p_01+0+3, 328, temp, 328, temp2);
	GF2X_MUL(8, temp, 4, q_00+325+160, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+160, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+159, 8, p_01+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+156, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+156, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+155, 8, p_01+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+152, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+152, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+151, 8, p_01+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+148, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+148, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+147, 8, p_01+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+144, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+144, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+143, 8, p_01+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+140, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+140, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+139, 8, p_01+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+136, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+136, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+135, 8, p_01+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+132, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+132, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+131, 8, p_01+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+128, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+128, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+127, 8, p_01+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+124, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+124, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+123, 8, p_01+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+120, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+120, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+119, 8, p_01+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+116, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+116, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+115, 8, p_01+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+112, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+112, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+111, 8, p_01+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+108, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+108, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+107, 8, p_01+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+104, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+104, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+103, 8, p_01+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+100, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+100, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+99, 8, p_01+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+96, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+96, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+95, 8, p_01+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+92, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+92, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+91, 8, p_01+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+88, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+88, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+87, 8, p_01+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+84, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+84, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+83, 8, p_01+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+80, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+80, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+79, 8, p_01+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+76, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+76, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+75, 8, p_01+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+72, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+72, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+71, 8, p_01+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+68, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+68, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+67, 8, p_01+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+64, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+64, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+63, 8, p_01+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+60, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+60, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+59, 8, p_01+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+56, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+56, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+55, 8, p_01+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+52, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+52, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+51, 8, p_01+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+48, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+48, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+47, 8, p_01+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+44, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+44, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+43, 8, p_01+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+40, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+40, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+39, 8, p_01+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+36, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+36, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+35, 8, p_01+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+32, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+32, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+31, 8, p_01+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+28, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+28, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+27, 8, p_01+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+24, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+24, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+23, 8, p_01+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+20, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+20, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+19, 8, p_01+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+16, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+16, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+15, 8, p_01+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+12, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+12, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+11, 8, p_01+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+8, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+8, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+7, 8, p_01+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+4, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+4, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+3, 8, p_01+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+325+0, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_01+325+0, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_01+0, 7, p_01+0, 7, temp+1);
	memset(p_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(328, temp, 164, p_00+331+4, 164, q_10+325);
	GF2X_MUL(328, temp2, 164, p_10+331+4, 164, q_11+325);
	gf2x_add(328, p_10+0+3, 328, temp, 328, temp2);
	GF2X_MUL(8, temp, 4, q_10+325+160, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+160, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+159, 8, p_10+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+156, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+156, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+155, 8, p_10+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+152, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+152, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+151, 8, p_10+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+148, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+148, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+147, 8, p_10+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+144, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+144, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+143, 8, p_10+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+140, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+140, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+139, 8, p_10+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+136, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+136, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+135, 8, p_10+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+132, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+132, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+131, 8, p_10+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+128, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+128, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+127, 8, p_10+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+124, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+124, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+123, 8, p_10+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+120, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+120, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+119, 8, p_10+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+116, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+116, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+115, 8, p_10+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+112, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+112, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+111, 8, p_10+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+108, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+108, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+107, 8, p_10+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+104, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+104, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+103, 8, p_10+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+100, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+100, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+99, 8, p_10+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+96, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+96, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+95, 8, p_10+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+92, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+92, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+91, 8, p_10+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+88, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+88, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+87, 8, p_10+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+84, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+84, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+83, 8, p_10+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+80, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+80, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+79, 8, p_10+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+76, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+76, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+75, 8, p_10+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+72, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+72, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+71, 8, p_10+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+68, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+68, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+67, 8, p_10+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+64, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+64, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+63, 8, p_10+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+60, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+60, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+59, 8, p_10+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+56, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+56, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+55, 8, p_10+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+52, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+52, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+51, 8, p_10+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+48, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+48, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+47, 8, p_10+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+44, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+44, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+43, 8, p_10+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+40, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+40, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+39, 8, p_10+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+36, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+36, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+35, 8, p_10+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+32, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+32, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+31, 8, p_10+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+28, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+28, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+27, 8, p_10+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+24, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+24, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+23, 8, p_10+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+20, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+20, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+19, 8, p_10+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+16, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+16, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+15, 8, p_10+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+12, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+12, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+11, 8, p_10+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+8, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+8, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+7, 8, p_10+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+4, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+4, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+3, 8, p_10+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+0, 4, p_00+331);
	GF2X_MUL(8, temp2, 4, q_11+325+0, 4, p_10+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_10+0, 7, p_10+0, 7, temp+1);
	memset(p_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(328, temp, 164, p_01+331+4, 164, q_10+325);
	GF2X_MUL(328, temp2, 164, p_11+331+4, 164, q_11+325);
	gf2x_add(328, p_11+0+3, 328, temp, 328, temp2);
	GF2X_MUL(8, temp, 4, q_10+325+160, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+160, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+159, 8, p_11+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+156, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+156, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+155, 8, p_11+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+152, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+152, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+151, 8, p_11+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+148, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+148, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+147, 8, p_11+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+144, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+144, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+143, 8, p_11+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+140, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+140, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+139, 8, p_11+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+136, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+136, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+135, 8, p_11+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+132, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+132, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+131, 8, p_11+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+128, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+128, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+127, 8, p_11+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+124, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+124, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+123, 8, p_11+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+120, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+120, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+119, 8, p_11+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+116, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+116, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+115, 8, p_11+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+112, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+112, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+111, 8, p_11+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+108, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+108, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+107, 8, p_11+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+104, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+104, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+103, 8, p_11+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+100, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+100, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+99, 8, p_11+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+96, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+96, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+95, 8, p_11+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+92, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+92, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+91, 8, p_11+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+88, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+88, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+87, 8, p_11+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+84, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+84, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+83, 8, p_11+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+80, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+80, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+79, 8, p_11+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+76, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+76, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+75, 8, p_11+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+72, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+72, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+71, 8, p_11+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+68, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+68, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+67, 8, p_11+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+64, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+64, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+63, 8, p_11+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+60, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+60, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+59, 8, p_11+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+56, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+56, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+55, 8, p_11+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+52, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+52, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+51, 8, p_11+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+48, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+48, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+47, 8, p_11+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+44, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+44, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+43, 8, p_11+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+40, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+40, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+39, 8, p_11+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+36, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+36, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+35, 8, p_11+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+32, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+32, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+31, 8, p_11+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+28, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+28, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+27, 8, p_11+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+24, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+24, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+23, 8, p_11+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+20, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+20, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+19, 8, p_11+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+16, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+16, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+15, 8, p_11+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+12, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+12, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+11, 8, p_11+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+8, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+8, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+7, 8, p_11+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+4, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+4, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+3, 8, p_11+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+325+0, 4, p_01+331);
	GF2X_MUL(8, temp2, 4, q_11+325+0, 4, p_11+331);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_11+0, 7, p_11+0, 7, temp+1);
	

	// Calculating left operands: n: 41961, depth: 0
	// Digits to shift: 330
	// Displacement: 331
	GF2X_MUL(662, temp, 331, f+0+325, 331, p_00+0);
	GF2X_MUL(662, temp2, 331, g+0+325, 331, p_01+0);
	gf2x_add(656, f_sum+0, 656, temp+6, 656, temp2+6);
	GF2X_MUL(650, temp, 325, p_00+0+6, 325, f+0);
	GF2X_MUL(650, temp2, 325, p_01+0+6, 325, g+0);
	gf2x_add(650, temp, 650, temp, 650, temp2);
	gf2x_add(325, f_sum+0, 325, f_sum+0, 325, temp+325);
	right_bit_shift_n(656, f_sum+0, 45);
	GF2X_MUL(662, temp, 331, f+0+325, 331, p_10+0);
	GF2X_MUL(662, temp2, 331, g+0+325, 331, p_11+0);
	gf2x_add(656, g_sum+0, 656, temp+6, 656, temp2+6);
	GF2X_MUL(650, temp, 325, p_10+0+6, 325, f+0);
	GF2X_MUL(650, temp2, 325, p_11+0+6, 325, g+0);
	gf2x_add(650, temp, 650, temp, 650, temp2);
	gf2x_add(325, g_sum+0, 325, g_sum+0, 325, temp+325);
	right_bit_shift_n(656, g_sum+0, 45);
	

	delta = divstepsx_256(255, delta, f_sum+322, g_sum+322, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+318+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+318+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+318+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+318+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+318+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+318+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+318+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+318+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+314+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+314+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+314);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+314);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+314+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+314+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+314);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+314);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+302+12, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+302+12, 12, p_01+651);
	gf2x_add(24, f_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+302+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+302+0, 12, p_01+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1939, 12, f_sum+1939, 12, temp+12);
	right_bit_shift_n(24, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+302+12, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+302+12, 12, p_11+651);
	gf2x_add(24, g_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+302+0, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+302+0, 12, p_11+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1939, 12, g_sum+1939, 12, temp+12);
	right_bit_shift_n(24, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1948, g_sum+1948, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, q_00+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, q_01+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, q_10+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, q_11+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_10+651);
	gf2x_add(24, p_00+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_11+651);
	gf2x_add(24, p_01+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_10+651);
	gf2x_add(24, p_10+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_11+651);
	gf2x_add(24, p_11+627+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+282+20, 24, p_00+627);
	GF2X_MUL(48, temp2, 24, g_sum+282+20, 24, p_01+627);
	gf2x_add(44, f_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, f_sum+282);
	GF2X_MUL(40, temp2, 20, p_01+627+4, 20, g_sum+282);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(44, f_sum+1870, 58);
	GF2X_MUL(48, temp, 24, f_sum+282+20, 24, p_10+627);
	GF2X_MUL(48, temp2, 24, g_sum+282+20, 24, p_11+627);
	gf2x_add(44, g_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+627+4, 20, f_sum+282);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, g_sum+282);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(44, g_sum+1870, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_01+613);
	gf2x_add(40, p_00+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+16, 8, p_00+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+12, 8, p_00+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+8, 8, p_00+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+4, 8, p_00+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+0, 8, p_00+583+0, 8, temp);
	memset(p_01+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_01+613);
	gf2x_add(40, p_01+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+16, 8, p_01+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+12, 8, p_01+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+8, 8, p_01+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+4, 8, p_01+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+0, 8, p_01+583+0, 8, temp);
	memset(p_10+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_11+613);
	gf2x_add(40, p_10+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+16, 8, p_10+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+12, 8, p_10+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+8, 8, p_10+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+4, 8, p_10+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+0, 8, p_10+583+0, 8, temp);
	memset(p_11+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_11+613);
	gf2x_add(40, p_11+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+16, 8, p_11+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+12, 8, p_11+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+8, 8, p_11+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+4, 8, p_11+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+0, 8, p_11+583+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+242+40, 44, p_00+583);
	GF2X_MUL(88, temp2, 44, g_sum+242+40, 44, p_01+583);
	gf2x_add(84, f_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, f_sum+242);
	GF2X_MUL(80, temp2, 40, p_01+583+4, 40, g_sum+242);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(84, f_sum+1741, 53);
	GF2X_MUL(88, temp, 44, f_sum+242+40, 44, p_10+583);
	GF2X_MUL(88, temp2, 44, g_sum+242+40, 44, p_11+583);
	gf2x_add(84, g_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+583+4, 40, f_sum+242);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, g_sum+242);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(84, g_sum+1741, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_01+573);
	gf2x_add(80, p_00+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+36, 8, p_00+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+32, 8, p_00+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+28, 8, p_00+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+24, 8, p_00+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+20, 8, p_00+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+16, 8, p_00+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+12, 8, p_00+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+8, 8, p_00+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+4, 8, p_00+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+0, 8, p_00+499+0, 8, temp);
	memset(p_01+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_01+573);
	gf2x_add(80, p_01+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+36, 8, p_01+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+32, 8, p_01+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+28, 8, p_01+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+24, 8, p_01+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+20, 8, p_01+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+16, 8, p_01+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+12, 8, p_01+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+8, 8, p_01+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+4, 8, p_01+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+0, 8, p_01+499+0, 8, temp);
	memset(p_10+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_11+573);
	gf2x_add(80, p_10+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+36, 8, p_10+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+32, 8, p_10+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+28, 8, p_10+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+24, 8, p_10+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+20, 8, p_10+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+16, 8, p_10+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+12, 8, p_10+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+8, 8, p_10+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+4, 8, p_10+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+0, 8, p_10+499+0, 8, temp);
	memset(p_11+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_11+573);
	gf2x_add(80, p_11+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+36, 8, p_11+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+32, 8, p_11+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+28, 8, p_11+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+24, 8, p_11+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+20, 8, p_11+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+16, 8, p_11+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+12, 8, p_11+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+8, 8, p_11+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+4, 8, p_11+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+0, 8, p_11+499+0, 8, temp);
	

	// Calculating left operands: n: 10455, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f_sum+162+80, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, g_sum+162+80, 84, p_01+499);
	gf2x_add(164, f_sum+1488, 164, temp+4, 164, temp2+4);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, f_sum+162);
	GF2X_MUL(160, temp2, 80, p_01+499+4, 80, g_sum+162);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, f_sum+1488, 80, f_sum+1488, 80, temp+80);
	right_bit_shift_n(164, f_sum+1488, 43);
	GF2X_MUL(168, temp, 84, f_sum+162+80, 84, p_10+499);
	GF2X_MUL(168, temp2, 84, g_sum+162+80, 84, p_11+499);
	gf2x_add(164, g_sum+1488, 164, temp+4, 164, temp2+4);
	GF2X_MUL(160, temp, 80, p_10+499+4, 80, f_sum+162);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, g_sum+162);
	gf2x_add(160, temp, 160, temp, 160, temp2);
	gf2x_add(80, g_sum+1488, 80, g_sum+1488, 80, temp+80);
	right_bit_shift_n(164, g_sum+1488, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1565, g_sum+1565, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1561+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1561+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1561+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1561+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1561+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1557+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1557+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1557);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1557);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1557+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1557+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1557);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1557);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1549+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1549);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1549);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1549+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1549+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1549);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1549);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1529+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1529+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1529+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1529+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1529+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, p_00+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, p_01+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, p_10+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, p_11+583+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1489+40, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+40, 40, p_01+583);
	gf2x_add(80, f_sum+1741+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1489+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+0, 40, p_01+583);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(80, f_sum+1741, 54);
	GF2X_MUL(80, temp, 40, f_sum+1489+40, 40, p_10+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+40, 40, p_11+583);
	gf2x_add(80, g_sum+1741+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1489+0, 40, p_10+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+0, 40, p_11+583);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(80, g_sum+1741, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 3
	GF2X_MUL(80, temp, 40, q_00+573+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, q_01+573+0, 40, p_10+583);
	gf2x_add(80, q_00+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+573+0, 40, p_01+583);
	GF2X_MUL(80, temp2, 40, q_01+573+0, 40, p_11+583);
	gf2x_add(80, q_01+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+573+0, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, q_11+573+0, 40, p_10+583);
	gf2x_add(80, q_10+489+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+573+0, 40, p_01+583);
	GF2X_MUL(80, temp2, 40, q_11+573+0, 40, p_11+583);
	gf2x_add(80, q_11+489+0, 80, temp, 80, temp2);
	

	// Recombining results: n: 10455, depth: 2
	memset(p_00+331, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, q_00+489);
	GF2X_MUL(160, temp2, 80, p_10+499+4, 80, q_01+489);
	gf2x_add(160, p_00+331+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_00+489+76, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+76, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+76, 8, p_00+331+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+72, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+72, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+72, 8, p_00+331+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+68, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+68, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+68, 8, p_00+331+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+64, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+64, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+64, 8, p_00+331+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+60, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+60, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+60, 8, p_00+331+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+56, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+56, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+56, 8, p_00+331+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+52, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+52, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+52, 8, p_00+331+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+48, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+48, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+48, 8, p_00+331+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+44, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+44, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+44, 8, p_00+331+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+40, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+40, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+40, 8, p_00+331+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+36, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+36, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+36, 8, p_00+331+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+32, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+32, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+32, 8, p_00+331+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+28, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+28, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+28, 8, p_00+331+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+24, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+24, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+24, 8, p_00+331+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+20, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+20, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+20, 8, p_00+331+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+16, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+16, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+16, 8, p_00+331+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+12, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+12, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+12, 8, p_00+331+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+8, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+8, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+8, 8, p_00+331+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+4, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+4, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+4, 8, p_00+331+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+0, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_01+489+0, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+331+0, 8, p_00+331+0, 8, temp);
	memset(p_01+331, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_01+499+4, 80, q_00+489);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, q_01+489);
	gf2x_add(160, p_01+331+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_00+489+76, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+76, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+76, 8, p_01+331+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+72, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+72, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+72, 8, p_01+331+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+68, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+68, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+68, 8, p_01+331+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+64, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+64, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+64, 8, p_01+331+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+60, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+60, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+60, 8, p_01+331+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+56, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+56, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+56, 8, p_01+331+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+52, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+52, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+52, 8, p_01+331+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+48, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+48, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+48, 8, p_01+331+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+44, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+44, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+44, 8, p_01+331+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+40, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+40, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+40, 8, p_01+331+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+36, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+36, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+36, 8, p_01+331+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+32, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+32, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+32, 8, p_01+331+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+28, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+28, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+28, 8, p_01+331+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+24, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+24, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+24, 8, p_01+331+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+20, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+20, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+20, 8, p_01+331+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+16, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+16, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+16, 8, p_01+331+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+12, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+12, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+12, 8, p_01+331+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+8, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+8, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+8, 8, p_01+331+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+4, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+4, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+4, 8, p_01+331+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+489+0, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_01+489+0, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+331+0, 8, p_01+331+0, 8, temp);
	memset(p_10+331, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_00+499+4, 80, q_10+489);
	GF2X_MUL(160, temp2, 80, p_10+499+4, 80, q_11+489);
	gf2x_add(160, p_10+331+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_10+489+76, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+76, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+76, 8, p_10+331+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+72, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+72, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+72, 8, p_10+331+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+68, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+68, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+68, 8, p_10+331+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+64, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+64, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+64, 8, p_10+331+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+60, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+60, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+60, 8, p_10+331+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+56, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+56, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+56, 8, p_10+331+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+52, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+52, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+52, 8, p_10+331+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+48, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+48, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+48, 8, p_10+331+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+44, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+44, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+44, 8, p_10+331+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+40, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+40, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+40, 8, p_10+331+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+36, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+36, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+36, 8, p_10+331+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+32, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+32, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+32, 8, p_10+331+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+28, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+28, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+28, 8, p_10+331+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+24, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+24, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+24, 8, p_10+331+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+20, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+20, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+20, 8, p_10+331+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+16, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+16, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+16, 8, p_10+331+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+12, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+12, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+12, 8, p_10+331+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+8, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+8, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+8, 8, p_10+331+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+4, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+4, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+4, 8, p_10+331+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+0, 4, p_00+499);
	GF2X_MUL(8, temp2, 4, q_11+489+0, 4, p_10+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+331+0, 8, p_10+331+0, 8, temp);
	memset(p_11+331, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(160, temp, 80, p_01+499+4, 80, q_10+489);
	GF2X_MUL(160, temp2, 80, p_11+499+4, 80, q_11+489);
	gf2x_add(160, p_11+331+4, 160, temp, 160, temp2);
	GF2X_MUL(8, temp, 4, q_10+489+76, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+76, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+76, 8, p_11+331+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+72, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+72, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+72, 8, p_11+331+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+68, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+68, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+68, 8, p_11+331+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+64, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+64, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+64, 8, p_11+331+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+60, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+60, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+60, 8, p_11+331+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+56, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+56, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+56, 8, p_11+331+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+52, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+52, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+52, 8, p_11+331+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+48, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+48, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+48, 8, p_11+331+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+44, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+44, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+44, 8, p_11+331+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+40, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+40, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+40, 8, p_11+331+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+36, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+36, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+36, 8, p_11+331+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+32, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+32, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+32, 8, p_11+331+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+28, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+28, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+28, 8, p_11+331+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+24, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+24, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+24, 8, p_11+331+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+20, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+20, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+20, 8, p_11+331+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+16, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+16, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+16, 8, p_11+331+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+12, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+12, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+12, 8, p_11+331+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+8, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+8, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+8, 8, p_11+331+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+4, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+4, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+4, 8, p_11+331+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+489+0, 4, p_01+499);
	GF2X_MUL(8, temp2, 4, q_11+489+0, 4, p_11+499);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+331+0, 8, p_11+331+0, 8, temp);
	

	// Calculating left operands: n: 20796, depth: 1
	// Digits to shift: 163
	// Displacement: 163
	GF2X_MUL(328, temp, 164, f_sum+1+161, 164, p_00+331);
	GF2X_MUL(328, temp2, 164, g_sum+1+161, 164, p_01+331);
	gf2x_add(326, f_sum+988, 326, temp+2, 326, temp2+2);
	GF2X_MUL(322, temp, 161, p_00+331+3, 161, f_sum+1);
	GF2X_MUL(322, temp2, 161, p_01+331+3, 161, g_sum+1);
	gf2x_add(322, temp, 322, temp, 322, temp2);
	gf2x_add(162, f_sum+988, 162, f_sum+988, 162, temp+160);
	GF2X_MUL(6, temp, 3, f_sum+1+158, 3, p_00+331);
	GF2X_MUL(6, temp2, 3, g_sum+1+158, 3, p_01+331);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+988, 1, f_sum+988, 1, temp+5);
	right_bit_shift_n(325, f_sum+988, 23);
	GF2X_MUL(328, temp, 164, f_sum+1+161, 164, p_10+331);
	GF2X_MUL(328, temp2, 164, g_sum+1+161, 164, p_11+331);
	gf2x_add(326, g_sum+988, 326, temp+2, 326, temp2+2);
	GF2X_MUL(322, temp, 161, p_10+331+3, 161, f_sum+1);
	GF2X_MUL(322, temp2, 161, p_11+331+3, 161, g_sum+1);
	gf2x_add(322, temp, 322, temp, 322, temp2);
	gf2x_add(162, g_sum+988, 162, g_sum+988, 162, temp+160);
	GF2X_MUL(6, temp, 3, f_sum+1+158, 3, p_10+331);
	GF2X_MUL(6, temp2, 3, g_sum+1+158, 3, p_11+331);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+988, 1, g_sum+988, 1, temp+5);
	right_bit_shift_n(325, g_sum+988, 23);
	

	delta = divstepsx_256(255, delta, f_sum+1147, g_sum+1147, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1143+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1143+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1143+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1143+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1143+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1143+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1143+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1143+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1139+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1139+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1139);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1139);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1139+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1139+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1139);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1139);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1127+12, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1127+12, 12, p_01+651);
	gf2x_add(24, f_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1127+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1127+0, 12, p_01+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1939, 12, f_sum+1939, 12, temp+12);
	right_bit_shift_n(24, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1127+12, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1127+12, 12, p_11+651);
	gf2x_add(24, g_sum+1939+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1127+0, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1127+0, 12, p_11+651);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1939, 12, g_sum+1939, 12, temp+12);
	right_bit_shift_n(24, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1948, g_sum+1948, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1944+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1944+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1944+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1940+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1940+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1940);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1940);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, q_00+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, q_01+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, q_10+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, q_11+633+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_10+651);
	gf2x_add(24, p_00+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_01+633+0, 12, p_11+651);
	gf2x_add(24, p_01+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_10+651);
	gf2x_add(24, p_10+627+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+633+0, 12, p_01+651);
	GF2X_MUL(24, temp2, 12, q_11+633+0, 12, p_11+651);
	gf2x_add(24, p_11+627+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1107+20, 24, p_00+627);
	GF2X_MUL(48, temp2, 24, g_sum+1107+20, 24, p_01+627);
	gf2x_add(44, f_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, f_sum+1107);
	GF2X_MUL(40, temp2, 20, p_01+627+4, 20, g_sum+1107);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(44, f_sum+1870, 58);
	GF2X_MUL(48, temp, 24, f_sum+1107+20, 24, p_10+627);
	GF2X_MUL(48, temp2, 24, g_sum+1107+20, 24, p_11+627);
	gf2x_add(44, g_sum+1870, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+627+4, 20, f_sum+1107);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, g_sum+1107);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(44, g_sum+1870, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_01+613);
	gf2x_add(40, p_00+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+16, 8, p_00+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+12, 8, p_00+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+8, 8, p_00+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+4, 8, p_00+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+583+0, 8, p_00+583+0, 8, temp);
	memset(p_01+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_00+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_01+613);
	gf2x_add(40, p_01+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+16, 8, p_01+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+12, 8, p_01+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+8, 8, p_01+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+4, 8, p_01+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+583+0, 8, p_01+583+0, 8, temp);
	memset(p_10+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_10+627+4, 20, q_11+613);
	gf2x_add(40, p_10+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+16, 8, p_10+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+12, 8, p_10+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+8, 8, p_10+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+4, 8, p_10+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_10+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+583+0, 8, p_10+583+0, 8, temp);
	memset(p_11+583, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+627+4, 20, q_10+613);
	GF2X_MUL(40, temp2, 20, p_11+627+4, 20, q_11+613);
	gf2x_add(40, p_11+583+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+613+16, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+16, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+16, 8, p_11+583+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+12, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+12, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+12, 8, p_11+583+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+8, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+8, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+8, 8, p_11+583+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+4, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+4, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+4, 8, p_11+583+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+613+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+613+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+583+0, 8, p_11+583+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1067+40, 44, p_00+583);
	GF2X_MUL(88, temp2, 44, g_sum+1067+40, 44, p_01+583);
	gf2x_add(84, f_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, f_sum+1067);
	GF2X_MUL(80, temp2, 40, p_01+583+4, 40, g_sum+1067);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1741, 40, f_sum+1741, 40, temp+40);
	right_bit_shift_n(84, f_sum+1741, 53);
	GF2X_MUL(88, temp, 44, f_sum+1067+40, 44, p_10+583);
	GF2X_MUL(88, temp2, 44, g_sum+1067+40, 44, p_11+583);
	gf2x_add(84, g_sum+1741, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+583+4, 40, f_sum+1067);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, g_sum+1067);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1741, 40, g_sum+1741, 40, temp+40);
	right_bit_shift_n(84, g_sum+1741, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1778, g_sum+1778, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1774+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1774+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1774+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1770+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1770+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1770);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1770);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1762+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1762+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1762);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1762);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1742+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, q_00+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, q_01+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, q_10+573+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, q_11+573+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_01+573);
	gf2x_add(80, p_00+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+36, 8, p_00+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+32, 8, p_00+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+28, 8, p_00+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+24, 8, p_00+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+20, 8, p_00+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+16, 8, p_00+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+12, 8, p_00+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+8, 8, p_00+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+4, 8, p_00+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+499+0, 8, p_00+499+0, 8, temp);
	memset(p_01+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_00+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_01+573);
	gf2x_add(80, p_01+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+36, 8, p_01+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+32, 8, p_01+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+28, 8, p_01+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+24, 8, p_01+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+20, 8, p_01+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+16, 8, p_01+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+12, 8, p_01+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+8, 8, p_01+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+4, 8, p_01+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_01+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+499+0, 8, p_01+499+0, 8, temp);
	memset(p_10+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_10+583+4, 40, q_11+573);
	gf2x_add(80, p_10+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+36, 8, p_10+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+32, 8, p_10+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+28, 8, p_10+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+24, 8, p_10+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+20, 8, p_10+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+16, 8, p_10+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+12, 8, p_10+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+8, 8, p_10+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+4, 8, p_10+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_00+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_10+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+499+0, 8, p_10+499+0, 8, temp);
	memset(p_11+499, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+583+4, 40, q_10+573);
	GF2X_MUL(80, temp2, 40, p_11+583+4, 40, q_11+573);
	gf2x_add(80, p_11+499+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+573+36, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+36, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+36, 8, p_11+499+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+32, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+32, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+32, 8, p_11+499+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+28, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+28, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+28, 8, p_11+499+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+24, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+24, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+24, 8, p_11+499+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+20, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+20, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+20, 8, p_11+499+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+16, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+16, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+16, 8, p_11+499+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+12, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+12, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+12, 8, p_11+499+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+8, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+8, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+8, 8, p_11+499+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+4, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+4, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+4, 8, p_11+499+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+573+0, 4, p_01+583);
	GF2X_MUL(8, temp2, 4, q_11+573+0, 4, p_11+583);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+499+0, 8, p_11+499+0, 8, temp);
	

	// Calculating left operands: n: 10341, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f_sum+989+78, 84, p_00+499);
	GF2X_MUL(168, temp2, 84, g_sum+989+78, 84, p_01+499);
	gf2x_add(162, f_sum+1488, 162, temp+6, 162, temp2+6);
	GF2X_MUL(156, temp, 78, p_00+499+6, 78, f_sum+989);
	GF2X_MUL(156, temp2, 78, p_01+499+6, 78, g_sum+989);
	gf2x_add(156, temp, 156, temp, 156, temp2);
	gf2x_add(78, f_sum+1488, 78, f_sum+1488, 78, temp+78);
	right_bit_shift_n(162, f_sum+1488, 43);
	GF2X_MUL(168, temp, 84, f_sum+989+78, 84, p_10+499);
	GF2X_MUL(168, temp2, 84, g_sum+989+78, 84, p_11+499);
	gf2x_add(162, g_sum+1488, 162, temp+6, 162, temp2+6);
	GF2X_MUL(156, temp, 78, p_10+499+6, 78, f_sum+989);
	GF2X_MUL(156, temp2, 78, p_11+499+6, 78, g_sum+989);
	gf2x_add(156, temp, 156, temp, 156, temp2);
	gf2x_add(78, g_sum+1488, 78, g_sum+1488, 78, temp+78);
	right_bit_shift_n(162, g_sum+1488, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1563, g_sum+1563, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1559+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1559+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1559+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1559+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1559+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1559+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1559+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1559+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1555+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1555+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1555);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1555);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1555+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1555+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1555);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1555);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1547+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1547+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1547);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1547);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1547+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1547+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1547);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1547);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1527+20, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1527+20, 20, p_01+627);
	gf2x_add(40, f_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1527+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1527+0, 20, p_01+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1870, 20, f_sum+1870, 20, temp+20);
	right_bit_shift_n(40, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1527+20, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1527+20, 20, p_11+627);
	gf2x_add(40, g_sum+1870+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1527+0, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1527+0, 20, p_11+627);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1870, 20, g_sum+1870, 20, temp+20);
	right_bit_shift_n(40, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1887, g_sum+1887, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1883+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1883+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1883+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1879+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1879+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1879);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1879);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1871);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1871);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, q_00+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+4, 8, q_00+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+613+0, 8, q_00+613+0, 8, temp);
	memset(q_01+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, q_01+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+4, 8, q_01+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+613+0, 8, q_01+613+0, 8, temp);
	memset(q_10+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, q_10+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+4, 8, q_10+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+613+0, 8, q_10+613+0, 8, temp);
	memset(q_11+613, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, q_11+613+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+4, 8, q_11+613+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+613+0, 8, q_11+613+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_10+627);
	gf2x_add(40, p_00+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_01+613+0, 20, p_11+627);
	gf2x_add(40, p_01+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_10+627);
	gf2x_add(40, p_10+583+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+613+0, 20, p_01+627);
	GF2X_MUL(40, temp2, 20, q_11+613+0, 20, p_11+627);
	gf2x_add(40, p_11+583+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4986, depth: 3
	// Digits to shift: 39
	// Displacement: 39
	GF2X_MUL(80, temp, 40, f_sum+1489+38, 40, p_00+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+38, 40, p_01+583);
	gf2x_add(79, f_sum+1741, 79, temp+1, 79, temp2+1);
	GF2X_MUL(76, temp, 38, p_00+583+2, 38, f_sum+1489);
	GF2X_MUL(76, temp2, 38, p_01+583+2, 38, g_sum+1489);
	gf2x_add(76, temp, 76, temp, 76, temp2);
	gf2x_add(39, f_sum+1741, 39, f_sum+1741, 39, temp+37);
	GF2X_MUL(4, temp, 2, f_sum+1489+36, 2, p_00+583);
	GF2X_MUL(4, temp2, 2, g_sum+1489+36, 2, p_01+583);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, f_sum+1741, 1, f_sum+1741, 1, temp+3);
	right_bit_shift_n(78, f_sum+1741, 54);
	GF2X_MUL(80, temp, 40, f_sum+1489+38, 40, p_10+583);
	GF2X_MUL(80, temp2, 40, g_sum+1489+38, 40, p_11+583);
	gf2x_add(79, g_sum+1741, 79, temp+1, 79, temp2+1);
	GF2X_MUL(76, temp, 38, p_10+583+2, 38, f_sum+1489);
	GF2X_MUL(76, temp2, 38, p_11+583+2, 38, g_sum+1489);
	gf2x_add(76, temp, 76, temp, 76, temp2);
	gf2x_add(39, g_sum+1741, 39, g_sum+1741, 39, temp+37);
	GF2X_MUL(4, temp, 2, f_sum+1489+36, 2, p_10+583);
	GF2X_MUL(4, temp2, 2, g_sum+1489+36, 2, p_11+583);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, g_sum+1741, 1, g_sum+1741, 1, temp+3);
	right_bit_shift_n(78, g_sum+1741, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1777, g_sum+1777, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1773+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1773+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1773+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1773+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1773+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1773+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1773+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1773+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1769+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1769+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1769);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1769);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1769+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1769+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1769);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1769);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1761+8, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1761+8, 12, p_01+651);
	gf2x_add(20, f_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, f_sum+1761);
	GF2X_MUL(16, temp2, 8, p_01+651+4, 8, g_sum+1761);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1939, 8, f_sum+1939, 8, temp+8);
	right_bit_shift_n(20, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1761+8, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1761+8, 12, p_11+651);
	gf2x_add(20, g_sum+1939, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+651+4, 8, f_sum+1761);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, g_sum+1761);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1939, 8, g_sum+1939, 8, temp+8);
	right_bit_shift_n(20, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1944, g_sum+1944, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_01+663);
	gf2x_add(8, f_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_01+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(8, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+4, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+4, 4, p_11+663);
	gf2x_add(8, g_sum+1976+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1940+0, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(8, g_sum+1976, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, q_00+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, q_01+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, q_10+633+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, q_11+633+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_01+633);
	gf2x_add(16, p_00+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+4, 8, p_00+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+627+0, 8, p_00+627+0, 8, temp);
	memset(p_01+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_00+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_01+633);
	gf2x_add(16, p_01+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+4, 8, p_01+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+627+0, 8, p_01+627+0, 8, temp);
	memset(p_10+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_10+651+4, 8, q_11+633);
	gf2x_add(16, p_10+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+4, 8, p_10+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+627+0, 8, p_10+627+0, 8, temp);
	memset(p_11+627, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+651+4, 8, q_10+633);
	GF2X_MUL(16, temp2, 8, p_11+651+4, 8, q_11+633);
	gf2x_add(16, p_11+627+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+4, 8, p_11+627+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+651);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+651);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+627+0, 8, p_11+627+0, 8, temp);
	

	// Calculating left operands: n: 2436, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1742+19, 20, p_00+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+19, 20, p_01+627);
	gf2x_add(39, f_sum+1870, 39, temp+1, 39, temp2+1);
	GF2X_MUL(38, temp, 19, p_00+627+1, 19, f_sum+1742);
	GF2X_MUL(38, temp2, 19, p_01+627+1, 19, g_sum+1742);
	gf2x_add(38, temp, 38, temp, 38, temp2);
	gf2x_add(19, f_sum+1870, 19, f_sum+1870, 19, temp+19);
	right_bit_shift_n(39, f_sum+1870, 59);
	GF2X_MUL(40, temp, 20, f_sum+1742+19, 20, p_10+627);
	GF2X_MUL(40, temp2, 20, g_sum+1742+19, 20, p_11+627);
	gf2x_add(39, g_sum+1870, 39, temp+1, 39, temp2+1);
	GF2X_MUL(38, temp, 19, p_10+627+1, 19, f_sum+1742);
	GF2X_MUL(38, temp2, 19, p_11+627+1, 19, g_sum+1742);
	gf2x_add(38, temp, 38, temp, 38, temp2);
	gf2x_add(19, g_sum+1870, 19, g_sum+1870, 19, temp+19);
	right_bit_shift_n(39, g_sum+1870, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1886, g_sum+1886, p_00+671, p_01+671, p_10+671, p_11+671);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1882+4, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1882+4, 4, p_01+671);
	gf2x_add(8, f_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1882+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, g_sum+1882+0, 4, p_01+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1997, 4, f_sum+1997, 4, temp+4);
	right_bit_shift_n(8, f_sum+1997, 63);
	GF2X_MUL(8, temp, 4, f_sum+1882+4, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1882+4, 4, p_11+671);
	gf2x_add(8, g_sum+1997+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1882+0, 4, p_10+671);
	GF2X_MUL(8, temp2, 4, g_sum+1882+0, 4, p_11+671);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1997, 4, g_sum+1997, 4, temp+4);
	right_bit_shift_n(8, g_sum+1997, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1998, g_sum+1998, q_00+649, q_01+649, q_10+649, q_11+649);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_10+671);
	gf2x_add(8, p_00+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_01+649+0, 4, p_11+671);
	gf2x_add(8, p_01+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_00+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_10+671);
	gf2x_add(8, p_10+663+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+649+0, 4, p_01+671);
	GF2X_MUL(8, temp2, 4, q_11+649+0, 4, p_11+671);
	gf2x_add(8, p_11+663+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1878+4, 8, p_00+663);
	GF2X_MUL(16, temp2, 8, g_sum+1878+4, 8, p_01+663);
	gf2x_add(12, f_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, f_sum+1878);
	GF2X_MUL(8, temp2, 4, p_01+663+4, 4, g_sum+1878);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1976, 4, f_sum+1976, 4, temp+4);
	right_bit_shift_n(12, f_sum+1976, 62);
	GF2X_MUL(16, temp, 8, f_sum+1878+4, 8, p_10+663);
	GF2X_MUL(16, temp2, 8, g_sum+1878+4, 8, p_11+663);
	gf2x_add(12, g_sum+1976, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+663+4, 4, f_sum+1878);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, g_sum+1878);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1976, 4, g_sum+1976, 4, temp+4);
	right_bit_shift_n(12, g_sum+1976, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645);

	// Recombining results: n: 765, depth: 6
	memset(p_00+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_01+645);
	gf2x_add(8, p_00+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+651+0, 8, p_00+651+0, 8, temp);
	memset(p_01+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_00+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_01+645);
	gf2x_add(8, p_01+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_01+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+651+0, 8, p_01+651+0, 8, temp);
	memset(p_10+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_10+663+4, 4, q_11+645);
	gf2x_add(8, p_10+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_10+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+651+0, 8, p_10+651+0, 8, temp);
	memset(p_11+651, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+663+4, 4, q_10+645);
	GF2X_MUL(8, temp2, 4, p_11+663+4, 4, q_11+645);
	gf2x_add(8, p_11+651+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+645+0, 4, p_01+663);
	GF2X_MUL(8, temp2, 4, q_11+645+0, 4, p_11+663);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+651+0, 8, p_11+651+0, 8, temp);
	

	// Calculating left operands: n: 1161, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1871+7, 12, p_00+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+7, 12, p_01+651);
	gf2x_add(19, f_sum+1939, 19, temp+5, 19, temp2+5);
	GF2X_MUL(14, temp, 7, p_00+651+5, 7, f_sum+1871);
	GF2X_MUL(14, temp2, 7, p_01+651+5, 7, g_sum+1871);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, f_sum+1939, 7, f_sum+1939, 7, temp+7);
	right_bit_shift_n(19, f_sum+1939, 61);
	GF2X_MUL(24, temp, 12, f_sum+1871+7, 12, p_10+651);
	GF2X_MUL(24, temp2, 12, g_sum+1871+7, 12, p_11+651);
	gf2x_add(19, g_sum+1939, 19, temp+5, 19, temp2+5);
	GF2X_MUL(14, temp, 7, p_10+651+5, 7, f_sum+1871);
	GF2X_MUL(14, temp2, 7, p_11+651+5, 7, g_sum+1871);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, g_sum+1939, 7, g_sum+1939, 7, temp+7);
	right_bit_shift_n(19, g_sum+1939, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1943, g_sum+1943, p_00+663, p_01+663, p_10+663, p_11+663);

	// Calculating left operands: n: 396, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1940+3, 4, p_00+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+3, 4, p_01+663);
	gf2x_add(7, f_sum+1976, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_00+663+1, 3, f_sum+1940);
	GF2X_MUL(6, temp2, 3, p_01+663+1, 3, g_sum+1940);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, f_sum+1976, 3, f_sum+1976, 3, temp+3);
	right_bit_shift_n(7, f_sum+1976, 63);
	GF2X_MUL(8, temp, 4, f_sum+1940+3, 4, p_10+663);
	GF2X_MUL(8, temp2, 4, g_sum+1940+3, 4, p_11+663);
	gf2x_add(7, g_sum+1976, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_10+663+1, 3, f_sum+1940);
	GF2X_MUL(6, temp2, 3, p_11+663+1, 3, g_sum+1940);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, g_sum+1976, 3, g_sum+1976, 3, temp+3);
	right_bit_shift_n(7, g_sum+1976, 63);
	

	delta = support_jumpdivstep(141, delta, 3, f_sum+1977, g_sum+1977, q_00+645, q_01+645, q_10+645, q_11+645, x);

	// Recombining results: n: 396, depth: 6
	memset(q_00+633, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+663+1, 3, q_00+645);
	GF2X_MUL(6, temp2, 3, p_10+663+1, 3, q_01+645);
	gf2x_add(6, q_00+633+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+645+2, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_01+645+2, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+633+2, 2, q_00+633+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+645+1, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_01+645+1, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+633+1, 2, q_00+633+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+645+0, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_01+645+0, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+633+0, 2, q_00+633+0, 2, temp);
	memset(q_01+633, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+663+1, 3, q_00+645);
	GF2X_MUL(6, temp2, 3, p_11+663+1, 3, q_01+645);
	gf2x_add(6, q_01+633+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+645+2, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_01+645+2, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+633+2, 2, q_01+633+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+645+1, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_01+645+1, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+633+1, 2, q_01+633+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+645+0, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_01+645+0, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+633+0, 2, q_01+633+0, 2, temp);
	memset(q_10+633, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+663+1, 3, q_10+645);
	GF2X_MUL(6, temp2, 3, p_10+663+1, 3, q_11+645);
	gf2x_add(6, q_10+633+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+645+2, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_11+645+2, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+633+2, 2, q_10+633+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+645+1, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_11+645+1, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+633+1, 2, q_10+633+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+645+0, 1, p_00+663);
	GF2X_MUL(2, temp2, 1, q_11+645+0, 1, p_10+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+633+0, 2, q_10+633+0, 2, temp);
	memset(q_11+633, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+663+1, 3, q_10+645);
	GF2X_MUL(6, temp2, 3, p_11+663+1, 3, q_11+645);
	gf2x_add(6, q_11+633+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+645+2, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_11+645+2, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+633+2, 2, q_11+633+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+645+1, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_11+645+1, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+633+1, 2, q_11+633+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+645+0, 1, p_01+663);
	GF2X_MUL(2, temp2, 1, q_11+645+0, 1, p_11+663);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+633+0, 2, q_11+633+0, 2, temp);
	

	// Recombining results: n: 1161, depth: 5
	memset(q_00+613, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+651+5, 7, q_00+633);
	GF2X_MUL(14, temp2, 7, p_10+651+5, 7, q_01+633);
	gf2x_add(14, q_00+613+5, 14, temp, 14, temp2);
	GF2X_MUL(10, temp, 5, q_00+633+2, 5, p_00+651);
	GF2X_MUL(10, temp2, 5, q_01+633+2, 5, p_10+651);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+613+2, 10, q_00+613+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+651+3, 2, q_00+633);
	GF2X_MUL(4, temp2, 2, p_10+651+3, 2, q_01+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+613+3, 4, q_00+613+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+651+1, 2, q_00+633);
	GF2X_MUL(4, temp2, 2, p_10+651+1, 2, q_01+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+613+1, 4, q_00+613+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+633+1, 1, p_00+651);
	GF2X_MUL(2, temp2, 1, q_01+633+1, 1, p_10+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+613+1, 2, q_00+613+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+633+0, 1, p_00+651);
	GF2X_MUL(2, temp2, 1, q_01+633+0, 1, p_10+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+613+0, 2, q_00+613+0, 2, temp);
	memset(q_01+613, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+651+5, 7, q_00+633);
	GF2X_MUL(14, temp2, 7, p_11+651+5, 7, q_01+633);
	gf2x_add(14, q_01+613+5, 14, temp, 14, temp2);
	GF2X_MUL(10, temp, 5, q_00+633+2, 5, p_01+651);
	GF2X_MUL(10, temp2, 5, q_01+633+2, 5, p_11+651);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+613+2, 10, q_01+613+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+651+3, 2, q_00+633);
	GF2X_MUL(4, temp2, 2, p_11+651+3, 2, q_01+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+613+3, 4, q_01+613+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+651+1, 2, q_00+633);
	GF2X_MUL(4, temp2, 2, p_11+651+1, 2, q_01+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+613+1, 4, q_01+613+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+633+1, 1, p_01+651);
	GF2X_MUL(2, temp2, 1, q_01+633+1, 1, p_11+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+613+1, 2, q_01+613+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+633+0, 1, p_01+651);
	GF2X_MUL(2, temp2, 1, q_01+633+0, 1, p_11+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+613+0, 2, q_01+613+0, 2, temp);
	memset(q_10+613, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+651+5, 7, q_10+633);
	GF2X_MUL(14, temp2, 7, p_10+651+5, 7, q_11+633);
	gf2x_add(14, q_10+613+5, 14, temp, 14, temp2);
	GF2X_MUL(10, temp, 5, q_10+633+2, 5, p_00+651);
	GF2X_MUL(10, temp2, 5, q_11+633+2, 5, p_10+651);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+613+2, 10, q_10+613+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_00+651+3, 2, q_10+633);
	GF2X_MUL(4, temp2, 2, p_10+651+3, 2, q_11+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+613+3, 4, q_10+613+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+651+1, 2, q_10+633);
	GF2X_MUL(4, temp2, 2, p_10+651+1, 2, q_11+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+613+1, 4, q_10+613+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+633+1, 1, p_00+651);
	GF2X_MUL(2, temp2, 1, q_11+633+1, 1, p_10+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+613+1, 2, q_10+613+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+633+0, 1, p_00+651);
	GF2X_MUL(2, temp2, 1, q_11+633+0, 1, p_10+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+613+0, 2, q_10+613+0, 2, temp);
	memset(q_11+613, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+651+5, 7, q_10+633);
	GF2X_MUL(14, temp2, 7, p_11+651+5, 7, q_11+633);
	gf2x_add(14, q_11+613+5, 14, temp, 14, temp2);
	GF2X_MUL(10, temp, 5, q_10+633+2, 5, p_01+651);
	GF2X_MUL(10, temp2, 5, q_11+633+2, 5, p_11+651);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+613+2, 10, q_11+613+2, 10, temp);
	GF2X_MUL(4, temp, 2, p_01+651+3, 2, q_10+633);
	GF2X_MUL(4, temp2, 2, p_11+651+3, 2, q_11+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+613+3, 4, q_11+613+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+651+1, 2, q_10+633);
	GF2X_MUL(4, temp2, 2, p_11+651+1, 2, q_11+633);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+613+1, 4, q_11+613+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+633+1, 1, p_01+651);
	GF2X_MUL(2, temp2, 1, q_11+633+1, 1, p_11+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+613+1, 2, q_11+613+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+633+0, 1, p_01+651);
	GF2X_MUL(2, temp2, 1, q_11+633+0, 1, p_11+651);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+613+0, 2, q_11+613+0, 2, temp);
	

	// Recombining results: n: 2436, depth: 4
	memset(q_00+573, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(38, temp, 19, p_00+627+1, 19, q_00+613);
	GF2X_MUL(38, temp2, 19, p_10+627+1, 19, q_01+613);
	gf2x_add(38, q_00+573+1, 38, temp, 38, temp2);
	GF2X_MUL(2, temp, 1, q_00+613+18, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+18, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+18, 2, q_00+573+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+17, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+17, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+17, 2, q_00+573+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+16, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+16, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+16, 2, q_00+573+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+15, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+15, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+15, 2, q_00+573+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+14, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+14, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+14, 2, q_00+573+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+13, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+13, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+13, 2, q_00+573+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+12, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+12, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+12, 2, q_00+573+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+11, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+11, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+11, 2, q_00+573+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+10, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+10, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+10, 2, q_00+573+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+9, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+9, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+9, 2, q_00+573+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+8, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+8, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+8, 2, q_00+573+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+7, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+7, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+7, 2, q_00+573+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+6, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+6, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+6, 2, q_00+573+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+5, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+5, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+5, 2, q_00+573+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+4, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+4, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+4, 2, q_00+573+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+3, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+3, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+3, 2, q_00+573+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+2, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+2, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+2, 2, q_00+573+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+1, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+1, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+1, 2, q_00+573+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+0, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_01+613+0, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+573+0, 2, q_00+573+0, 2, temp);
	memset(q_01+573, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(38, temp, 19, p_01+627+1, 19, q_00+613);
	GF2X_MUL(38, temp2, 19, p_11+627+1, 19, q_01+613);
	gf2x_add(38, q_01+573+1, 38, temp, 38, temp2);
	GF2X_MUL(2, temp, 1, q_00+613+18, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+18, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+18, 2, q_01+573+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+17, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+17, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+17, 2, q_01+573+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+16, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+16, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+16, 2, q_01+573+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+15, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+15, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+15, 2, q_01+573+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+14, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+14, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+14, 2, q_01+573+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+13, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+13, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+13, 2, q_01+573+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+12, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+12, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+12, 2, q_01+573+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+11, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+11, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+11, 2, q_01+573+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+10, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+10, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+10, 2, q_01+573+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+9, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+9, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+9, 2, q_01+573+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+8, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+8, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+8, 2, q_01+573+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+7, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+7, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+7, 2, q_01+573+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+6, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+6, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+6, 2, q_01+573+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+5, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+5, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+5, 2, q_01+573+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+4, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+4, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+4, 2, q_01+573+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+3, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+3, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+3, 2, q_01+573+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+2, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+2, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+2, 2, q_01+573+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+1, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+1, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+1, 2, q_01+573+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+613+0, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_01+613+0, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+573+0, 2, q_01+573+0, 2, temp);
	memset(q_10+573, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(38, temp, 19, p_00+627+1, 19, q_10+613);
	GF2X_MUL(38, temp2, 19, p_10+627+1, 19, q_11+613);
	gf2x_add(38, q_10+573+1, 38, temp, 38, temp2);
	GF2X_MUL(2, temp, 1, q_10+613+18, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+18, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+18, 2, q_10+573+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+17, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+17, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+17, 2, q_10+573+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+16, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+16, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+16, 2, q_10+573+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+15, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+15, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+15, 2, q_10+573+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+14, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+14, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+14, 2, q_10+573+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+13, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+13, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+13, 2, q_10+573+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+12, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+12, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+12, 2, q_10+573+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+11, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+11, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+11, 2, q_10+573+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+10, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+10, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+10, 2, q_10+573+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+9, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+9, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+9, 2, q_10+573+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+8, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+8, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+8, 2, q_10+573+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+7, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+7, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+7, 2, q_10+573+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+6, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+6, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+6, 2, q_10+573+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+5, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+5, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+5, 2, q_10+573+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+4, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+4, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+4, 2, q_10+573+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+3, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+3, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+3, 2, q_10+573+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+2, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+2, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+2, 2, q_10+573+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+1, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+1, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+1, 2, q_10+573+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+0, 1, p_00+627);
	GF2X_MUL(2, temp2, 1, q_11+613+0, 1, p_10+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+573+0, 2, q_10+573+0, 2, temp);
	memset(q_11+573, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(38, temp, 19, p_01+627+1, 19, q_10+613);
	GF2X_MUL(38, temp2, 19, p_11+627+1, 19, q_11+613);
	gf2x_add(38, q_11+573+1, 38, temp, 38, temp2);
	GF2X_MUL(2, temp, 1, q_10+613+18, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+18, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+18, 2, q_11+573+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+17, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+17, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+17, 2, q_11+573+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+16, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+16, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+16, 2, q_11+573+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+15, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+15, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+15, 2, q_11+573+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+14, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+14, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+14, 2, q_11+573+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+13, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+13, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+13, 2, q_11+573+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+12, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+12, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+12, 2, q_11+573+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+11, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+11, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+11, 2, q_11+573+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+10, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+10, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+10, 2, q_11+573+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+9, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+9, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+9, 2, q_11+573+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+8, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+8, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+8, 2, q_11+573+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+7, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+7, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+7, 2, q_11+573+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+6, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+6, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+6, 2, q_11+573+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+5, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+5, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+5, 2, q_11+573+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+4, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+4, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+4, 2, q_11+573+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+3, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+3, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+3, 2, q_11+573+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+2, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+2, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+2, 2, q_11+573+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+1, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+1, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+1, 2, q_11+573+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+613+0, 1, p_01+627);
	GF2X_MUL(2, temp2, 1, q_11+613+0, 1, p_11+627);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+573+0, 2, q_11+573+0, 2, temp);
	

	// Recombining results: n: 4986, depth: 3
	GF2X_MUL(78, temp, 39, p_00+583+1, 39, q_00+573);
	GF2X_MUL(78, temp2, 39, p_10+583+1, 39, q_01+573);
	gf2x_add(78, q_00+489+0, 78, temp, 78, temp2);
	GF2X_MUL(2, temp, 1, q_00+573+38, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+38, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+37, 2, q_00+489+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+37, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+37, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+36, 2, q_00+489+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+36, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+36, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+35, 2, q_00+489+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+35, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+35, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+34, 2, q_00+489+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+34, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+34, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+33, 2, q_00+489+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+33, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+33, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+32, 2, q_00+489+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+32, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+32, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+31, 2, q_00+489+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+31, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+31, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+30, 2, q_00+489+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+30, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+30, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+29, 2, q_00+489+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+29, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+29, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+28, 2, q_00+489+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+28, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+28, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+27, 2, q_00+489+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+27, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+27, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+26, 2, q_00+489+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+26, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+26, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+25, 2, q_00+489+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+25, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+25, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+24, 2, q_00+489+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+24, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+24, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+23, 2, q_00+489+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+23, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+23, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+22, 2, q_00+489+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+22, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+22, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+21, 2, q_00+489+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+21, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+21, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+20, 2, q_00+489+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+20, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+20, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+19, 2, q_00+489+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+19, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+19, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+18, 2, q_00+489+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+18, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+18, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+17, 2, q_00+489+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+17, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+17, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+16, 2, q_00+489+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+16, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+16, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+15, 2, q_00+489+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+15, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+15, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+14, 2, q_00+489+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+14, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+14, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+13, 2, q_00+489+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+13, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+13, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+12, 2, q_00+489+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+12, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+12, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+11, 2, q_00+489+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+11, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+11, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+10, 2, q_00+489+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+10, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+10, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+9, 2, q_00+489+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+9, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+9, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+8, 2, q_00+489+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+8, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+8, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+7, 2, q_00+489+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+7, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+7, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+6, 2, q_00+489+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+6, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+6, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+5, 2, q_00+489+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+5, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+5, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+4, 2, q_00+489+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+4, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+4, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+3, 2, q_00+489+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+3, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+3, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+2, 2, q_00+489+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+2, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+2, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+1, 2, q_00+489+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+1, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+1, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+489+0, 2, q_00+489+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+0, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_01+573+0, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+489, 1, q_00+489, 1, temp+1);
	GF2X_MUL(78, temp, 39, p_01+583+1, 39, q_00+573);
	GF2X_MUL(78, temp2, 39, p_11+583+1, 39, q_01+573);
	gf2x_add(78, q_01+489+0, 78, temp, 78, temp2);
	GF2X_MUL(2, temp, 1, q_00+573+38, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+38, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+37, 2, q_01+489+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+37, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+37, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+36, 2, q_01+489+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+36, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+36, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+35, 2, q_01+489+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+35, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+35, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+34, 2, q_01+489+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+34, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+34, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+33, 2, q_01+489+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+33, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+33, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+32, 2, q_01+489+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+32, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+32, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+31, 2, q_01+489+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+31, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+31, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+30, 2, q_01+489+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+30, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+30, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+29, 2, q_01+489+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+29, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+29, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+28, 2, q_01+489+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+28, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+28, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+27, 2, q_01+489+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+27, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+27, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+26, 2, q_01+489+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+26, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+26, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+25, 2, q_01+489+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+25, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+25, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+24, 2, q_01+489+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+24, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+24, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+23, 2, q_01+489+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+23, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+23, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+22, 2, q_01+489+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+22, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+22, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+21, 2, q_01+489+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+21, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+21, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+20, 2, q_01+489+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+20, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+20, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+19, 2, q_01+489+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+19, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+19, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+18, 2, q_01+489+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+18, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+18, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+17, 2, q_01+489+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+17, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+17, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+16, 2, q_01+489+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+16, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+16, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+15, 2, q_01+489+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+15, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+15, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+14, 2, q_01+489+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+14, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+14, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+13, 2, q_01+489+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+13, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+13, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+12, 2, q_01+489+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+12, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+12, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+11, 2, q_01+489+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+11, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+11, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+10, 2, q_01+489+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+10, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+10, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+9, 2, q_01+489+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+9, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+9, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+8, 2, q_01+489+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+8, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+8, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+7, 2, q_01+489+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+7, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+7, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+6, 2, q_01+489+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+6, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+6, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+5, 2, q_01+489+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+5, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+5, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+4, 2, q_01+489+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+4, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+4, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+3, 2, q_01+489+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+3, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+3, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+2, 2, q_01+489+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+2, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+2, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+1, 2, q_01+489+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+1, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+1, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+489+0, 2, q_01+489+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+573+0, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_01+573+0, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+489, 1, q_01+489, 1, temp+1);
	GF2X_MUL(78, temp, 39, p_00+583+1, 39, q_10+573);
	GF2X_MUL(78, temp2, 39, p_10+583+1, 39, q_11+573);
	gf2x_add(78, q_10+489+0, 78, temp, 78, temp2);
	GF2X_MUL(2, temp, 1, q_10+573+38, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+38, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+37, 2, q_10+489+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+37, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+37, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+36, 2, q_10+489+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+36, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+36, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+35, 2, q_10+489+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+35, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+35, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+34, 2, q_10+489+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+34, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+34, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+33, 2, q_10+489+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+33, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+33, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+32, 2, q_10+489+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+32, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+32, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+31, 2, q_10+489+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+31, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+31, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+30, 2, q_10+489+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+30, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+30, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+29, 2, q_10+489+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+29, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+29, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+28, 2, q_10+489+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+28, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+28, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+27, 2, q_10+489+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+27, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+27, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+26, 2, q_10+489+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+26, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+26, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+25, 2, q_10+489+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+25, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+25, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+24, 2, q_10+489+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+24, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+24, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+23, 2, q_10+489+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+23, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+23, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+22, 2, q_10+489+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+22, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+22, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+21, 2, q_10+489+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+21, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+21, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+20, 2, q_10+489+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+20, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+20, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+19, 2, q_10+489+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+19, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+19, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+18, 2, q_10+489+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+18, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+18, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+17, 2, q_10+489+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+17, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+17, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+16, 2, q_10+489+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+16, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+16, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+15, 2, q_10+489+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+15, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+15, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+14, 2, q_10+489+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+14, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+14, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+13, 2, q_10+489+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+13, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+13, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+12, 2, q_10+489+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+12, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+12, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+11, 2, q_10+489+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+11, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+11, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+10, 2, q_10+489+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+10, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+10, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+9, 2, q_10+489+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+9, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+9, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+8, 2, q_10+489+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+8, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+8, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+7, 2, q_10+489+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+7, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+7, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+6, 2, q_10+489+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+6, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+6, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+5, 2, q_10+489+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+5, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+5, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+4, 2, q_10+489+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+4, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+4, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+3, 2, q_10+489+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+3, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+3, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+2, 2, q_10+489+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+2, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+2, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+1, 2, q_10+489+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+1, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+1, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+489+0, 2, q_10+489+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+0, 1, p_00+583);
	GF2X_MUL(2, temp2, 1, q_11+573+0, 1, p_10+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+489, 1, q_10+489, 1, temp+1);
	GF2X_MUL(78, temp, 39, p_01+583+1, 39, q_10+573);
	GF2X_MUL(78, temp2, 39, p_11+583+1, 39, q_11+573);
	gf2x_add(78, q_11+489+0, 78, temp, 78, temp2);
	GF2X_MUL(2, temp, 1, q_10+573+38, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+38, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+37, 2, q_11+489+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+37, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+37, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+36, 2, q_11+489+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+36, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+36, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+35, 2, q_11+489+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+35, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+35, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+34, 2, q_11+489+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+34, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+34, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+33, 2, q_11+489+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+33, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+33, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+32, 2, q_11+489+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+32, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+32, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+31, 2, q_11+489+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+31, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+31, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+30, 2, q_11+489+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+30, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+30, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+29, 2, q_11+489+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+29, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+29, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+28, 2, q_11+489+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+28, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+28, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+27, 2, q_11+489+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+27, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+27, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+26, 2, q_11+489+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+26, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+26, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+25, 2, q_11+489+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+25, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+25, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+24, 2, q_11+489+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+24, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+24, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+23, 2, q_11+489+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+23, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+23, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+22, 2, q_11+489+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+22, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+22, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+21, 2, q_11+489+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+21, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+21, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+20, 2, q_11+489+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+20, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+20, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+19, 2, q_11+489+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+19, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+19, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+18, 2, q_11+489+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+18, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+18, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+17, 2, q_11+489+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+17, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+17, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+16, 2, q_11+489+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+16, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+16, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+15, 2, q_11+489+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+15, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+15, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+14, 2, q_11+489+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+14, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+14, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+13, 2, q_11+489+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+13, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+13, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+12, 2, q_11+489+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+12, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+12, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+11, 2, q_11+489+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+11, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+11, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+10, 2, q_11+489+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+10, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+10, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+9, 2, q_11+489+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+9, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+9, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+8, 2, q_11+489+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+8, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+8, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+7, 2, q_11+489+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+7, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+7, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+6, 2, q_11+489+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+6, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+6, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+5, 2, q_11+489+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+5, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+5, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+4, 2, q_11+489+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+4, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+4, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+3, 2, q_11+489+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+3, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+3, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+2, 2, q_11+489+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+2, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+2, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+1, 2, q_11+489+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+1, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+1, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+489+0, 2, q_11+489+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+573+0, 1, p_01+583);
	GF2X_MUL(2, temp2, 1, q_11+573+0, 1, p_11+583);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+489, 1, q_11+489, 1, temp+1);
	

	// Recombining results: n: 10341, depth: 2
	memset(q_00+325, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(156, temp, 78, p_00+499+6, 78, q_00+489);
	GF2X_MUL(156, temp2, 78, p_10+499+6, 78, q_01+489);
	gf2x_add(156, q_00+325+6, 156, temp, 156, temp2);
	GF2X_MUL(12, temp, 6, q_00+489+72, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+72, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+72, 12, q_00+325+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+66, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+66, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+66, 12, q_00+325+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+60, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+60, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+60, 12, q_00+325+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+54, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+54, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+54, 12, q_00+325+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+48, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+48, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+48, 12, q_00+325+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+42, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+42, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+42, 12, q_00+325+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+36, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+36, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+36, 12, q_00+325+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+30, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+30, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+30, 12, q_00+325+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+24, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+24, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+24, 12, q_00+325+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+18, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+18, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+18, 12, q_00+325+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+12, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+12, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+12, 12, q_00+325+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+6, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+6, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+6, 12, q_00+325+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+0, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_01+489+0, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+325+0, 12, q_00+325+0, 12, temp);
	memset(q_01+325, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(156, temp, 78, p_01+499+6, 78, q_00+489);
	GF2X_MUL(156, temp2, 78, p_11+499+6, 78, q_01+489);
	gf2x_add(156, q_01+325+6, 156, temp, 156, temp2);
	GF2X_MUL(12, temp, 6, q_00+489+72, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+72, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+72, 12, q_01+325+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+66, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+66, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+66, 12, q_01+325+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+60, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+60, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+60, 12, q_01+325+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+54, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+54, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+54, 12, q_01+325+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+48, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+48, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+48, 12, q_01+325+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+42, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+42, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+42, 12, q_01+325+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+36, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+36, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+36, 12, q_01+325+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+30, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+30, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+30, 12, q_01+325+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+24, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+24, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+24, 12, q_01+325+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+18, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+18, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+18, 12, q_01+325+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+12, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+12, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+12, 12, q_01+325+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+6, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+6, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+6, 12, q_01+325+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+489+0, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_01+489+0, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+325+0, 12, q_01+325+0, 12, temp);
	memset(q_10+325, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(156, temp, 78, p_00+499+6, 78, q_10+489);
	GF2X_MUL(156, temp2, 78, p_10+499+6, 78, q_11+489);
	gf2x_add(156, q_10+325+6, 156, temp, 156, temp2);
	GF2X_MUL(12, temp, 6, q_10+489+72, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+72, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+72, 12, q_10+325+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+66, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+66, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+66, 12, q_10+325+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+60, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+60, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+60, 12, q_10+325+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+54, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+54, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+54, 12, q_10+325+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+48, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+48, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+48, 12, q_10+325+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+42, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+42, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+42, 12, q_10+325+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+36, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+36, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+36, 12, q_10+325+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+30, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+30, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+30, 12, q_10+325+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+24, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+24, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+24, 12, q_10+325+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+18, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+18, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+18, 12, q_10+325+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+12, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+12, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+12, 12, q_10+325+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+6, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+6, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+6, 12, q_10+325+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+0, 6, p_00+499);
	GF2X_MUL(12, temp2, 6, q_11+489+0, 6, p_10+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+325+0, 12, q_10+325+0, 12, temp);
	memset(q_11+325, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(156, temp, 78, p_01+499+6, 78, q_10+489);
	GF2X_MUL(156, temp2, 78, p_11+499+6, 78, q_11+489);
	gf2x_add(156, q_11+325+6, 156, temp, 156, temp2);
	GF2X_MUL(12, temp, 6, q_10+489+72, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+72, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+72, 12, q_11+325+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+66, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+66, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+66, 12, q_11+325+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+60, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+60, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+60, 12, q_11+325+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+54, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+54, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+54, 12, q_11+325+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+48, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+48, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+48, 12, q_11+325+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+42, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+42, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+42, 12, q_11+325+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+36, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+36, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+36, 12, q_11+325+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+30, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+30, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+30, 12, q_11+325+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+24, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+24, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+24, 12, q_11+325+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+18, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+18, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+18, 12, q_11+325+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+12, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+12, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+12, 12, q_11+325+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+6, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+6, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+6, 12, q_11+325+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+489+0, 6, p_01+499);
	GF2X_MUL(12, temp2, 6, q_11+489+0, 6, p_11+499);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+325+0, 12, q_11+325+0, 12, temp);
	

	// Recombining results: n: 20796, depth: 1
	memset(q_00+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(324, temp, 162, p_00+331+2, 162, q_00+325);
	GF2X_MUL(324, temp2, 162, p_10+331+2, 162, q_01+325);
	gf2x_add(324, q_00+0+1, 324, temp, 324, temp2);
	GF2X_MUL(4, temp, 2, q_00+325+160, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+160, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+159, 4, q_00+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+158, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+158, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+157, 4, q_00+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+156, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+156, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+155, 4, q_00+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+154, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+154, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+153, 4, q_00+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+152, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+152, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+151, 4, q_00+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+150, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+150, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+149, 4, q_00+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+148, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+148, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+147, 4, q_00+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+146, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+146, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+145, 4, q_00+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+144, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+144, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+143, 4, q_00+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+142, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+142, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+141, 4, q_00+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+140, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+140, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+139, 4, q_00+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+138, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+138, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+137, 4, q_00+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+136, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+136, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+135, 4, q_00+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+134, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+134, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+133, 4, q_00+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+132, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+132, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+131, 4, q_00+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+130, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+130, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+129, 4, q_00+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+128, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+128, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+127, 4, q_00+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+126, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+126, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+125, 4, q_00+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+124, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+124, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+123, 4, q_00+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+122, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+122, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+121, 4, q_00+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+120, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+120, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+119, 4, q_00+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+118, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+118, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+117, 4, q_00+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+116, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+116, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+115, 4, q_00+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+114, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+114, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+113, 4, q_00+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+112, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+112, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+111, 4, q_00+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+110, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+110, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+109, 4, q_00+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+108, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+108, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+107, 4, q_00+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+106, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+106, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+105, 4, q_00+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+104, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+104, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+103, 4, q_00+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+102, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+102, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+101, 4, q_00+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+100, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+100, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+99, 4, q_00+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+98, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+98, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+97, 4, q_00+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+96, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+96, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+95, 4, q_00+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+94, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+94, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+93, 4, q_00+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+92, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+92, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+91, 4, q_00+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+90, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+90, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+89, 4, q_00+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+88, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+88, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+87, 4, q_00+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+86, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+86, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+85, 4, q_00+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+84, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+84, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+83, 4, q_00+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+82, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+82, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+81, 4, q_00+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+80, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+80, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+79, 4, q_00+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+78, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+78, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+77, 4, q_00+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+76, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+76, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+75, 4, q_00+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+74, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+74, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+73, 4, q_00+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+72, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+72, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+71, 4, q_00+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+70, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+70, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+69, 4, q_00+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+68, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+68, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+67, 4, q_00+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+66, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+66, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+65, 4, q_00+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+64, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+64, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+63, 4, q_00+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+62, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+62, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+61, 4, q_00+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+60, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+60, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+59, 4, q_00+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+58, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+58, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+57, 4, q_00+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+56, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+56, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+55, 4, q_00+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+54, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+54, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+53, 4, q_00+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+52, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+52, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+51, 4, q_00+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+50, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+50, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+49, 4, q_00+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+48, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+48, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+47, 4, q_00+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+46, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+46, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+45, 4, q_00+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+44, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+44, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+43, 4, q_00+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+42, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+42, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+41, 4, q_00+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+40, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+40, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+39, 4, q_00+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+38, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+38, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+37, 4, q_00+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+36, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+36, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+35, 4, q_00+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+34, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+34, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+33, 4, q_00+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+32, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+32, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+31, 4, q_00+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+30, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+30, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+29, 4, q_00+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+28, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+28, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+27, 4, q_00+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+26, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+26, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+25, 4, q_00+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+24, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+24, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+23, 4, q_00+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+22, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+22, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+21, 4, q_00+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+20, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+20, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+19, 4, q_00+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+18, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+18, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+17, 4, q_00+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+16, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+16, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+15, 4, q_00+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+14, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+14, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+13, 4, q_00+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+12, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+12, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+11, 4, q_00+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+10, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+10, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+9, 4, q_00+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+8, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+8, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+7, 4, q_00+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+6, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+6, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+5, 4, q_00+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+4, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+4, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+3, 4, q_00+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+2, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+2, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+1, 4, q_00+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+0, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_01+325+0, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+0, 3, q_00+0, 3, temp+1);
	memset(q_01+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(324, temp, 162, p_01+331+2, 162, q_00+325);
	GF2X_MUL(324, temp2, 162, p_11+331+2, 162, q_01+325);
	gf2x_add(324, q_01+0+1, 324, temp, 324, temp2);
	GF2X_MUL(4, temp, 2, q_00+325+160, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+160, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+159, 4, q_01+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+158, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+158, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+157, 4, q_01+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+156, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+156, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+155, 4, q_01+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+154, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+154, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+153, 4, q_01+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+152, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+152, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+151, 4, q_01+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+150, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+150, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+149, 4, q_01+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+148, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+148, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+147, 4, q_01+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+146, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+146, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+145, 4, q_01+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+144, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+144, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+143, 4, q_01+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+142, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+142, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+141, 4, q_01+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+140, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+140, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+139, 4, q_01+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+138, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+138, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+137, 4, q_01+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+136, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+136, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+135, 4, q_01+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+134, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+134, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+133, 4, q_01+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+132, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+132, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+131, 4, q_01+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+130, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+130, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+129, 4, q_01+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+128, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+128, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+127, 4, q_01+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+126, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+126, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+125, 4, q_01+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+124, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+124, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+123, 4, q_01+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+122, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+122, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+121, 4, q_01+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+120, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+120, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+119, 4, q_01+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+118, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+118, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+117, 4, q_01+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+116, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+116, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+115, 4, q_01+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+114, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+114, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+113, 4, q_01+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+112, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+112, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+111, 4, q_01+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+110, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+110, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+109, 4, q_01+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+108, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+108, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+107, 4, q_01+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+106, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+106, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+105, 4, q_01+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+104, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+104, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+103, 4, q_01+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+102, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+102, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+101, 4, q_01+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+100, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+100, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+99, 4, q_01+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+98, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+98, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+97, 4, q_01+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+96, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+96, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+95, 4, q_01+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+94, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+94, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+93, 4, q_01+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+92, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+92, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+91, 4, q_01+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+90, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+90, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+89, 4, q_01+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+88, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+88, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+87, 4, q_01+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+86, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+86, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+85, 4, q_01+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+84, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+84, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+83, 4, q_01+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+82, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+82, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+81, 4, q_01+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+80, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+80, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+79, 4, q_01+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+78, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+78, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+77, 4, q_01+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+76, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+76, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+75, 4, q_01+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+74, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+74, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+73, 4, q_01+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+72, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+72, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+71, 4, q_01+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+70, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+70, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+69, 4, q_01+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+68, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+68, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+67, 4, q_01+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+66, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+66, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+65, 4, q_01+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+64, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+64, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+63, 4, q_01+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+62, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+62, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+61, 4, q_01+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+60, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+60, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+59, 4, q_01+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+58, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+58, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+57, 4, q_01+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+56, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+56, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+55, 4, q_01+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+54, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+54, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+53, 4, q_01+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+52, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+52, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+51, 4, q_01+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+50, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+50, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+49, 4, q_01+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+48, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+48, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+47, 4, q_01+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+46, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+46, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+45, 4, q_01+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+44, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+44, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+43, 4, q_01+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+42, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+42, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+41, 4, q_01+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+40, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+40, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+39, 4, q_01+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+38, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+38, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+37, 4, q_01+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+36, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+36, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+35, 4, q_01+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+34, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+34, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+33, 4, q_01+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+32, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+32, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+31, 4, q_01+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+30, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+30, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+29, 4, q_01+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+28, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+28, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+27, 4, q_01+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+26, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+26, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+25, 4, q_01+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+24, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+24, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+23, 4, q_01+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+22, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+22, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+21, 4, q_01+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+20, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+20, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+19, 4, q_01+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+18, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+18, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+17, 4, q_01+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+16, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+16, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+15, 4, q_01+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+14, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+14, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+13, 4, q_01+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+12, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+12, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+11, 4, q_01+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+10, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+10, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+9, 4, q_01+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+8, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+8, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+7, 4, q_01+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+6, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+6, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+5, 4, q_01+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+4, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+4, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+3, 4, q_01+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+2, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+2, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+1, 4, q_01+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+325+0, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_01+325+0, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+0, 3, q_01+0, 3, temp+1);
	memset(q_10+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(324, temp, 162, p_00+331+2, 162, q_10+325);
	GF2X_MUL(324, temp2, 162, p_10+331+2, 162, q_11+325);
	gf2x_add(324, q_10+0+1, 324, temp, 324, temp2);
	GF2X_MUL(4, temp, 2, q_10+325+160, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+160, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+159, 4, q_10+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+158, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+158, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+157, 4, q_10+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+156, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+156, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+155, 4, q_10+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+154, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+154, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+153, 4, q_10+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+152, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+152, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+151, 4, q_10+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+150, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+150, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+149, 4, q_10+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+148, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+148, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+147, 4, q_10+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+146, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+146, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+145, 4, q_10+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+144, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+144, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+143, 4, q_10+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+142, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+142, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+141, 4, q_10+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+140, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+140, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+139, 4, q_10+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+138, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+138, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+137, 4, q_10+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+136, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+136, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+135, 4, q_10+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+134, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+134, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+133, 4, q_10+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+132, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+132, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+131, 4, q_10+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+130, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+130, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+129, 4, q_10+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+128, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+128, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+127, 4, q_10+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+126, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+126, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+125, 4, q_10+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+124, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+124, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+123, 4, q_10+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+122, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+122, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+121, 4, q_10+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+120, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+120, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+119, 4, q_10+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+118, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+118, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+117, 4, q_10+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+116, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+116, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+115, 4, q_10+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+114, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+114, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+113, 4, q_10+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+112, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+112, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+111, 4, q_10+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+110, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+110, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+109, 4, q_10+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+108, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+108, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+107, 4, q_10+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+106, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+106, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+105, 4, q_10+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+104, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+104, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+103, 4, q_10+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+102, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+102, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+101, 4, q_10+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+100, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+100, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+99, 4, q_10+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+98, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+98, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+97, 4, q_10+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+96, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+96, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+95, 4, q_10+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+94, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+94, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+93, 4, q_10+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+92, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+92, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+91, 4, q_10+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+90, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+90, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+89, 4, q_10+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+88, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+88, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+87, 4, q_10+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+86, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+86, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+85, 4, q_10+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+84, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+84, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+83, 4, q_10+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+82, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+82, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+81, 4, q_10+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+80, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+80, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+79, 4, q_10+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+78, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+78, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+77, 4, q_10+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+76, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+76, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+75, 4, q_10+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+74, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+74, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+73, 4, q_10+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+72, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+72, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+71, 4, q_10+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+70, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+70, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+69, 4, q_10+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+68, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+68, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+67, 4, q_10+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+66, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+66, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+65, 4, q_10+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+64, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+64, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+63, 4, q_10+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+62, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+62, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+61, 4, q_10+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+60, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+60, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+59, 4, q_10+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+58, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+58, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+57, 4, q_10+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+56, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+56, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+55, 4, q_10+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+54, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+54, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+53, 4, q_10+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+52, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+52, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+51, 4, q_10+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+50, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+50, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+49, 4, q_10+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+48, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+48, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+47, 4, q_10+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+46, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+46, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+45, 4, q_10+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+44, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+44, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+43, 4, q_10+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+42, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+42, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+41, 4, q_10+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+40, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+40, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+39, 4, q_10+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+38, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+38, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+37, 4, q_10+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+36, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+36, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+35, 4, q_10+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+34, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+34, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+33, 4, q_10+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+32, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+32, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+31, 4, q_10+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+30, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+30, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+29, 4, q_10+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+28, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+28, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+27, 4, q_10+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+26, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+26, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+25, 4, q_10+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+24, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+24, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+23, 4, q_10+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+22, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+22, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+21, 4, q_10+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+20, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+20, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+19, 4, q_10+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+18, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+18, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+17, 4, q_10+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+16, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+16, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+15, 4, q_10+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+14, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+14, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+13, 4, q_10+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+12, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+12, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+11, 4, q_10+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+10, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+10, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+9, 4, q_10+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+8, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+8, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+7, 4, q_10+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+6, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+6, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+5, 4, q_10+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+4, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+4, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+3, 4, q_10+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+2, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+2, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+1, 4, q_10+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+0, 2, p_00+331);
	GF2X_MUL(4, temp2, 2, q_11+325+0, 2, p_10+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+0, 3, q_10+0, 3, temp+1);
	memset(q_11+0, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(324, temp, 162, p_01+331+2, 162, q_10+325);
	GF2X_MUL(324, temp2, 162, p_11+331+2, 162, q_11+325);
	gf2x_add(324, q_11+0+1, 324, temp, 324, temp2);
	GF2X_MUL(4, temp, 2, q_10+325+160, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+160, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+159, 4, q_11+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+158, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+158, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+157, 4, q_11+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+156, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+156, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+155, 4, q_11+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+154, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+154, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+153, 4, q_11+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+152, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+152, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+151, 4, q_11+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+150, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+150, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+149, 4, q_11+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+148, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+148, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+147, 4, q_11+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+146, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+146, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+145, 4, q_11+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+144, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+144, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+143, 4, q_11+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+142, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+142, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+141, 4, q_11+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+140, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+140, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+139, 4, q_11+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+138, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+138, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+137, 4, q_11+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+136, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+136, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+135, 4, q_11+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+134, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+134, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+133, 4, q_11+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+132, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+132, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+131, 4, q_11+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+130, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+130, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+129, 4, q_11+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+128, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+128, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+127, 4, q_11+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+126, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+126, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+125, 4, q_11+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+124, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+124, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+123, 4, q_11+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+122, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+122, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+121, 4, q_11+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+120, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+120, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+119, 4, q_11+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+118, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+118, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+117, 4, q_11+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+116, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+116, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+115, 4, q_11+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+114, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+114, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+113, 4, q_11+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+112, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+112, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+111, 4, q_11+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+110, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+110, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+109, 4, q_11+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+108, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+108, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+107, 4, q_11+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+106, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+106, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+105, 4, q_11+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+104, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+104, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+103, 4, q_11+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+102, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+102, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+101, 4, q_11+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+100, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+100, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+99, 4, q_11+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+98, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+98, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+97, 4, q_11+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+96, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+96, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+95, 4, q_11+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+94, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+94, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+93, 4, q_11+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+92, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+92, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+91, 4, q_11+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+90, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+90, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+89, 4, q_11+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+88, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+88, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+87, 4, q_11+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+86, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+86, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+85, 4, q_11+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+84, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+84, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+83, 4, q_11+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+82, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+82, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+81, 4, q_11+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+80, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+80, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+79, 4, q_11+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+78, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+78, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+77, 4, q_11+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+76, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+76, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+75, 4, q_11+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+74, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+74, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+73, 4, q_11+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+72, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+72, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+71, 4, q_11+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+70, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+70, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+69, 4, q_11+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+68, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+68, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+67, 4, q_11+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+66, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+66, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+65, 4, q_11+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+64, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+64, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+63, 4, q_11+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+62, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+62, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+61, 4, q_11+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+60, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+60, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+59, 4, q_11+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+58, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+58, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+57, 4, q_11+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+56, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+56, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+55, 4, q_11+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+54, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+54, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+53, 4, q_11+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+52, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+52, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+51, 4, q_11+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+50, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+50, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+49, 4, q_11+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+48, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+48, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+47, 4, q_11+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+46, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+46, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+45, 4, q_11+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+44, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+44, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+43, 4, q_11+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+42, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+42, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+41, 4, q_11+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+40, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+40, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+39, 4, q_11+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+38, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+38, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+37, 4, q_11+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+36, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+36, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+35, 4, q_11+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+34, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+34, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+33, 4, q_11+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+32, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+32, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+31, 4, q_11+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+30, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+30, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+29, 4, q_11+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+28, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+28, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+27, 4, q_11+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+26, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+26, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+25, 4, q_11+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+24, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+24, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+23, 4, q_11+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+22, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+22, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+21, 4, q_11+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+20, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+20, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+19, 4, q_11+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+18, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+18, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+17, 4, q_11+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+16, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+16, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+15, 4, q_11+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+14, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+14, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+13, 4, q_11+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+12, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+12, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+11, 4, q_11+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+10, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+10, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+9, 4, q_11+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+8, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+8, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+7, 4, q_11+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+6, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+6, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+5, 4, q_11+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+4, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+4, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+3, 4, q_11+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+2, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+2, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+1, 4, q_11+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+325+0, 2, p_01+331);
	GF2X_MUL(4, temp2, 2, q_11+325+0, 2, p_11+331);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+0, 3, q_11+0, 3, temp+1);
	

	// Recombining results: n: 41961, depth: 0
	memset(t_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(650, temp, 325, p_00+0+6, 325, q_00+0);
	GF2X_MUL(650, temp2, 325, p_10+0+6, 325, q_01+0);
	gf2x_add(650, t_00+0+6, 650, temp, 650, temp2);
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
	GF2X_MUL(650, temp, 325, p_01+0+6, 325, q_00+0);
	GF2X_MUL(650, temp2, 325, p_11+0+6, 325, q_01+0);
	gf2x_add(650, t_01+0+6, 650, temp, 650, temp2);
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
	GF2X_MUL(650, temp, 325, p_00+0+6, 325, q_10+0);
	GF2X_MUL(650, temp2, 325, p_10+0+6, 325, q_11+0);
	gf2x_add(650, t_10+0+6, 650, temp, 650, temp2);
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
	GF2X_MUL(650, temp, 325, p_01+0+6, 325, q_10+0);
	GF2X_MUL(650, temp2, 325, p_11+0+6, 325, q_11+0);
	gf2x_add(650, t_11+0+6, 650, temp, 650, temp2);
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