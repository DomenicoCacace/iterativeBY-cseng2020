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

int jumpdivstep_23371(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[739];
	DIGIT p_01[739];
	DIGIT p_10[739];
	DIGIT p_11[739];
	
	DIGIT q_00[728];
	DIGIT q_01[728];
	DIGIT q_10[728];
	DIGIT q_11[728];
	
	DIGIT f_sum[2214];
	DIGIT g_sum[2214];
	
	DIGIT temp[1465];
	DIGIT temp2[1465];
	

	delta = divstepsx_256(255, delta, f+727, g+727, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+723+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g+723+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+723+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g+723+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f+723+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g+723+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+723+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g+723+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+719+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g+719+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f+719);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g+719);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f+719+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g+719+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f+719);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g+719);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+707+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g+707+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+707+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g+707+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f+707+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g+707+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+707+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g+707+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f+683+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g+683+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f+683+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g+683+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f+683+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g+683+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f+683+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g+683+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f+639+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g+639+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f+639);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g+639);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f+639+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g+639+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f+639);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g+639);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(p_00+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, p_00+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+40, 8, p_00+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+36, 8, p_00+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+32, 8, p_00+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+28, 8, p_00+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+24, 8, p_00+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+20, 8, p_00+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+16, 8, p_00+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+12, 8, p_00+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+8, 8, p_00+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+4, 8, p_00+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+0, 8, p_00+551+0, 8, temp);
	memset(p_01+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, p_01+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+40, 8, p_01+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+36, 8, p_01+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+32, 8, p_01+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+28, 8, p_01+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+24, 8, p_01+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+20, 8, p_01+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+16, 8, p_01+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+12, 8, p_01+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+8, 8, p_01+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+4, 8, p_01+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+0, 8, p_01+551+0, 8, temp);
	memset(p_10+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, p_10+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+40, 8, p_10+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+36, 8, p_10+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+32, 8, p_10+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+28, 8, p_10+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+24, 8, p_10+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+20, 8, p_10+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+16, 8, p_10+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+12, 8, p_10+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+8, 8, p_10+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+4, 8, p_10+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+0, 8, p_10+551+0, 8, temp);
	memset(p_11+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, p_11+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+40, 8, p_11+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+36, 8, p_11+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+32, 8, p_11+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+28, 8, p_11+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+24, 8, p_11+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+20, 8, p_11+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+16, 8, p_11+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+12, 8, p_11+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+8, 8, p_11+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+4, 8, p_11+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+0, 8, p_11+551+0, 8, temp);
	

	// Calculating left operands: n: 11730, depth: 2
	// Digits to shift: 91
	// Displacement: 92
	GF2X_MUL(184, temp, 92, f+547+92, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g+547+92, 92, p_01+551);
	gf2x_add(184, f_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f+547+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g+547+0, 92, p_01+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, f_sum+1651, 92, f_sum+1651, 92, temp+92);
	right_bit_shift_n(184, f_sum+1651, 41);
	GF2X_MUL(184, temp, 92, f+547+92, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g+547+92, 92, p_11+551);
	gf2x_add(184, g_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f+547+0, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g+547+0, 92, p_11+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, g_sum+1651, 92, g_sum+1651, 92, temp+92);
	right_bit_shift_n(184, g_sum+1651, 41);
	

	delta = divstepsx_256(255, delta, f_sum+1740, g_sum+1740, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(q_00+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, q_00+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+40, 8, q_00+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+36, 8, q_00+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+32, 8, q_00+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+28, 8, q_00+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+24, 8, q_00+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+20, 8, q_00+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+16, 8, q_00+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+12, 8, q_00+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+8, 8, q_00+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+4, 8, q_00+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+0, 8, q_00+548+0, 8, temp);
	memset(q_01+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, q_01+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+40, 8, q_01+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+36, 8, q_01+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+32, 8, q_01+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+28, 8, q_01+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+24, 8, q_01+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+20, 8, q_01+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+16, 8, q_01+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+12, 8, q_01+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+8, 8, q_01+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+4, 8, q_01+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+0, 8, q_01+548+0, 8, temp);
	memset(q_10+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, q_10+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+40, 8, q_10+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+36, 8, q_10+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+32, 8, q_10+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+28, 8, q_10+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+24, 8, q_10+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+20, 8, q_10+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+16, 8, q_10+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+12, 8, q_10+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+8, 8, q_10+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+4, 8, q_10+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+0, 8, q_10+548+0, 8, temp);
	memset(q_11+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, q_11+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+40, 8, q_11+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+36, 8, q_11+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+32, 8, q_11+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+28, 8, q_11+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+24, 8, q_11+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+20, 8, q_11+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+16, 8, q_11+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+12, 8, q_11+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+8, 8, q_11+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+4, 8, q_11+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+0, 8, q_11+548+0, 8, temp);
	

	// Recombining results: n: 11730, depth: 2
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_10+551);
	gf2x_add(184, p_00+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_11+551);
	gf2x_add(184, p_01+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_10+551);
	gf2x_add(184, p_10+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_11+551);
	gf2x_add(184, p_11+367+0, 184, temp, 184, temp2);
	

	// Calculating left operands: n: 23460, depth: 1
	// Digits to shift: 183
	// Displacement: 183
	GF2X_MUL(368, temp, 184, f+364+183, 184, p_00+367);
	GF2X_MUL(368, temp2, 184, g+364+183, 184, p_01+367);
	gf2x_add(368, f_sum+1099+0, 368, temp, 368, temp2);
	GF2X_MUL(366, temp, 183, p_00+367+1, 183, f+364);
	GF2X_MUL(366, temp2, 183, p_01+367+1, 183, g+364);
	gf2x_add(366, temp, 366, temp, 366, temp2);
	gf2x_add(184, f_sum+1099, 184, f_sum+1099, 184, temp+182);
	GF2X_MUL(2, temp, 1, f+364+182, 1, p_00+367);
	GF2X_MUL(2, temp2, 1, g+364+182, 1, p_01+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1099, 1, f_sum+1099, 1, temp+1);
	right_bit_shift_n(367, f_sum+1099, 18);
	GF2X_MUL(368, temp, 184, f+364+183, 184, p_10+367);
	GF2X_MUL(368, temp2, 184, g+364+183, 184, p_11+367);
	gf2x_add(368, g_sum+1099+0, 368, temp, 368, temp2);
	GF2X_MUL(366, temp, 183, p_10+367+1, 183, f+364);
	GF2X_MUL(366, temp2, 183, p_11+367+1, 183, g+364);
	gf2x_add(366, temp, 366, temp, 366, temp2);
	gf2x_add(184, g_sum+1099, 184, g_sum+1099, 184, temp+182);
	GF2X_MUL(2, temp, 1, f+364+182, 1, p_10+367);
	GF2X_MUL(2, temp2, 1, g+364+182, 1, p_11+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1099, 1, g_sum+1099, 1, temp+1);
	right_bit_shift_n(367, g_sum+1099, 18);
	

	delta = divstepsx_256(255, delta, f_sum+1280, g_sum+1280, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1276+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1276+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1276+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1276+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1276+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1276+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1276+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1276+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1272+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1272+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1272);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1272);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1272+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1272+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1272);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1272);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1260+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1260+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1260+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1260+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1260+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1260+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1260+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1260+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1236+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1236+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1236+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1236+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1236+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1236+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1236+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1236+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+1192+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1192+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+1192);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+1192);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1192+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1192+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+1192);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+1192);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(p_00+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, p_00+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+40, 8, p_00+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+36, 8, p_00+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+32, 8, p_00+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+28, 8, p_00+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+24, 8, p_00+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+20, 8, p_00+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+16, 8, p_00+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+12, 8, p_00+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+8, 8, p_00+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+4, 8, p_00+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+0, 8, p_00+551+0, 8, temp);
	memset(p_01+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, p_01+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+40, 8, p_01+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+36, 8, p_01+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+32, 8, p_01+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+28, 8, p_01+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+24, 8, p_01+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+20, 8, p_01+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+16, 8, p_01+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+12, 8, p_01+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+8, 8, p_01+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+4, 8, p_01+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+0, 8, p_01+551+0, 8, temp);
	memset(p_10+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, p_10+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+40, 8, p_10+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+36, 8, p_10+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+32, 8, p_10+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+28, 8, p_10+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+24, 8, p_10+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+20, 8, p_10+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+16, 8, p_10+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+12, 8, p_10+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+8, 8, p_10+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+4, 8, p_10+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+0, 8, p_10+551+0, 8, temp);
	memset(p_11+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, p_11+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+40, 8, p_11+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+36, 8, p_11+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+32, 8, p_11+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+28, 8, p_11+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+24, 8, p_11+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+20, 8, p_11+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+16, 8, p_11+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+12, 8, p_11+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+8, 8, p_11+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+4, 8, p_11+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+0, 8, p_11+551+0, 8, temp);
	

	// Calculating left operands: n: 11730, depth: 2
	// Digits to shift: 91
	// Displacement: 92
	GF2X_MUL(184, temp, 92, f_sum+1100+92, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+92, 92, p_01+551);
	gf2x_add(184, f_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f_sum+1100+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+0, 92, p_01+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, f_sum+1651, 92, f_sum+1651, 92, temp+92);
	right_bit_shift_n(184, f_sum+1651, 41);
	GF2X_MUL(184, temp, 92, f_sum+1100+92, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+92, 92, p_11+551);
	gf2x_add(184, g_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f_sum+1100+0, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+0, 92, p_11+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, g_sum+1651, 92, g_sum+1651, 92, temp+92);
	right_bit_shift_n(184, g_sum+1651, 41);
	

	delta = divstepsx_256(255, delta, f_sum+1740, g_sum+1740, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(q_00+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, q_00+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+40, 8, q_00+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+36, 8, q_00+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+32, 8, q_00+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+28, 8, q_00+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+24, 8, q_00+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+20, 8, q_00+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+16, 8, q_00+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+12, 8, q_00+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+8, 8, q_00+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+4, 8, q_00+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+0, 8, q_00+548+0, 8, temp);
	memset(q_01+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, q_01+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+40, 8, q_01+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+36, 8, q_01+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+32, 8, q_01+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+28, 8, q_01+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+24, 8, q_01+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+20, 8, q_01+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+16, 8, q_01+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+12, 8, q_01+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+8, 8, q_01+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+4, 8, q_01+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+0, 8, q_01+548+0, 8, temp);
	memset(q_10+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, q_10+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+40, 8, q_10+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+36, 8, q_10+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+32, 8, q_10+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+28, 8, q_10+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+24, 8, q_10+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+20, 8, q_10+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+16, 8, q_10+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+12, 8, q_10+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+8, 8, q_10+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+4, 8, q_10+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+0, 8, q_10+548+0, 8, temp);
	memset(q_11+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, q_11+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+40, 8, q_11+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+36, 8, q_11+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+32, 8, q_11+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+28, 8, q_11+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+24, 8, q_11+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+20, 8, q_11+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+16, 8, q_11+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+12, 8, q_11+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+8, 8, q_11+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+4, 8, q_11+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+0, 8, q_11+548+0, 8, temp);
	

	// Recombining results: n: 11730, depth: 2
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_10+551);
	gf2x_add(184, q_00+364+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_11+551);
	gf2x_add(184, q_01+364+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_10+551);
	gf2x_add(184, q_10+364+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_11+551);
	gf2x_add(184, q_11+364+0, 184, temp, 184, temp2);
	

	// Recombining results: n: 23460, depth: 1
	GF2X_MUL(368, temp, 184, q_00+364+0, 184, p_00+367);
	GF2X_MUL(368, temp2, 184, q_01+364+0, 184, p_10+367);
	gf2x_add(367, p_00+0, 367, temp+1, 367, temp2+1);
	GF2X_MUL(368, temp, 184, q_00+364+0, 184, p_01+367);
	GF2X_MUL(368, temp2, 184, q_01+364+0, 184, p_11+367);
	gf2x_add(367, p_01+0, 367, temp+1, 367, temp2+1);
	GF2X_MUL(368, temp, 184, q_10+364+0, 184, p_00+367);
	GF2X_MUL(368, temp2, 184, q_11+364+0, 184, p_10+367);
	gf2x_add(367, p_10+0, 367, temp+1, 367, temp2+1);
	GF2X_MUL(368, temp, 184, q_10+364+0, 184, p_01+367);
	GF2X_MUL(368, temp2, 184, q_11+364+0, 184, p_11+367);
	gf2x_add(367, p_11+0, 367, temp+1, 367, temp2+1);
	

	// Calculating left operands: n: 46741, depth: 0
	// Digits to shift: 366
	// Displacement: 367
	GF2X_MUL(734, temp, 367, f+0+364, 367, p_00+0);
	GF2X_MUL(734, temp2, 367, g+0+364, 367, p_01+0);
	gf2x_add(731, f_sum+0, 731, temp+3, 731, temp2+3);
	GF2X_MUL(728, temp, 364, p_00+0+3, 364, f+0);
	GF2X_MUL(728, temp2, 364, p_01+0+3, 364, g+0);
	gf2x_add(728, temp, 728, temp, 728, temp2);
	gf2x_add(364, f_sum+0, 364, f_sum+0, 364, temp+364);
	right_bit_shift_n(731, f_sum+0, 36);
	GF2X_MUL(734, temp, 367, f+0+364, 367, p_10+0);
	GF2X_MUL(734, temp2, 367, g+0+364, 367, p_11+0);
	gf2x_add(731, g_sum+0, 731, temp+3, 731, temp2+3);
	GF2X_MUL(728, temp, 364, p_10+0+3, 364, f+0);
	GF2X_MUL(728, temp2, 364, p_11+0+3, 364, g+0);
	gf2x_add(728, temp, 728, temp, 728, temp2);
	gf2x_add(364, g_sum+0, 364, g_sum+0, 364, temp+364);
	right_bit_shift_n(731, g_sum+0, 36);
	

	delta = divstepsx_256(255, delta, f_sum+361, g_sum+361, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+357+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+357+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+357+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+357+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+357+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+357+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+357+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+357+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+353+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+353+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+353);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+353);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+353+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+353+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+353);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+353);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+341+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+341+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+341+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+341+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+341+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+341+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+341+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+341+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+317+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+317+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+317+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+317+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+317+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+317+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+317+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+317+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+273+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+273+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+273);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+273);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+273+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+273+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+273);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+273);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(p_00+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, p_00+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+40, 8, p_00+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+36, 8, p_00+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+32, 8, p_00+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+28, 8, p_00+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+24, 8, p_00+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+20, 8, p_00+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+16, 8, p_00+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+12, 8, p_00+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+8, 8, p_00+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+4, 8, p_00+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+0, 8, p_00+551+0, 8, temp);
	memset(p_01+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, p_01+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+40, 8, p_01+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+36, 8, p_01+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+32, 8, p_01+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+28, 8, p_01+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+24, 8, p_01+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+20, 8, p_01+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+16, 8, p_01+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+12, 8, p_01+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+8, 8, p_01+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+4, 8, p_01+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+0, 8, p_01+551+0, 8, temp);
	memset(p_10+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, p_10+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+40, 8, p_10+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+36, 8, p_10+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+32, 8, p_10+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+28, 8, p_10+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+24, 8, p_10+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+20, 8, p_10+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+16, 8, p_10+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+12, 8, p_10+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+8, 8, p_10+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+4, 8, p_10+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+0, 8, p_10+551+0, 8, temp);
	memset(p_11+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, p_11+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+40, 8, p_11+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+36, 8, p_11+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+32, 8, p_11+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+28, 8, p_11+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+24, 8, p_11+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+20, 8, p_11+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+16, 8, p_11+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+12, 8, p_11+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+8, 8, p_11+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+4, 8, p_11+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+0, 8, p_11+551+0, 8, temp);
	

	// Calculating left operands: n: 11730, depth: 2
	// Digits to shift: 91
	// Displacement: 92
	GF2X_MUL(184, temp, 92, f_sum+181+92, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g_sum+181+92, 92, p_01+551);
	gf2x_add(184, f_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f_sum+181+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g_sum+181+0, 92, p_01+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, f_sum+1651, 92, f_sum+1651, 92, temp+92);
	right_bit_shift_n(184, f_sum+1651, 41);
	GF2X_MUL(184, temp, 92, f_sum+181+92, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g_sum+181+92, 92, p_11+551);
	gf2x_add(184, g_sum+1651+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, f_sum+181+0, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g_sum+181+0, 92, p_11+551);
	gf2x_add(184, temp, 184, temp, 184, temp2);
	gf2x_add(92, g_sum+1651, 92, g_sum+1651, 92, temp+92);
	right_bit_shift_n(184, g_sum+1651, 41);
	

	delta = divstepsx_256(255, delta, f_sum+1740, g_sum+1740, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1736+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1736+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1736+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1732+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1732+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1732);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1732);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1720+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1720+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1720+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1696+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1696+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1696+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1652+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+1652);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+1652);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(q_00+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, q_00+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+40, 8, q_00+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+36, 8, q_00+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+32, 8, q_00+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+28, 8, q_00+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+24, 8, q_00+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+20, 8, q_00+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+16, 8, q_00+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+12, 8, q_00+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+8, 8, q_00+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+4, 8, q_00+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+548+0, 8, q_00+548+0, 8, temp);
	memset(q_01+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, q_01+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+40, 8, q_01+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+36, 8, q_01+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+32, 8, q_01+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+28, 8, q_01+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+24, 8, q_01+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+20, 8, q_01+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+16, 8, q_01+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+12, 8, q_01+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+8, 8, q_01+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+4, 8, q_01+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+548+0, 8, q_01+548+0, 8, temp);
	memset(q_10+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, q_10+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+40, 8, q_10+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+36, 8, q_10+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+32, 8, q_10+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+28, 8, q_10+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+24, 8, q_10+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+20, 8, q_10+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+16, 8, q_10+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+12, 8, q_10+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+8, 8, q_10+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+4, 8, q_10+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+548+0, 8, q_10+548+0, 8, temp);
	memset(q_11+548, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, q_11+548+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+40, 8, q_11+548+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+36, 8, q_11+548+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+32, 8, q_11+548+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+28, 8, q_11+548+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+24, 8, q_11+548+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+20, 8, q_11+548+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+16, 8, q_11+548+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+12, 8, q_11+548+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+8, 8, q_11+548+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+4, 8, q_11+548+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+548+0, 8, q_11+548+0, 8, temp);
	

	// Recombining results: n: 11730, depth: 2
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_10+551);
	gf2x_add(184, p_00+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_00+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_01+548+0, 92, p_11+551);
	gf2x_add(184, p_01+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_10+551);
	gf2x_add(184, p_10+367+0, 184, temp, 184, temp2);
	GF2X_MUL(184, temp, 92, q_10+548+0, 92, p_01+551);
	GF2X_MUL(184, temp2, 92, q_11+548+0, 92, p_11+551);
	gf2x_add(184, p_11+367+0, 184, temp, 184, temp2);
	

	// Calculating left operands: n: 23281, depth: 1
	// Digits to shift: 183
	// Displacement: 183
	GF2X_MUL(368, temp, 184, f_sum+1+180, 184, p_00+367);
	GF2X_MUL(368, temp2, 184, g_sum+1+180, 184, p_01+367);
	gf2x_add(365, f_sum+1099, 365, temp+3, 365, temp2+3);
	GF2X_MUL(360, temp, 180, p_00+367+4, 180, f_sum+1);
	GF2X_MUL(360, temp2, 180, p_01+367+4, 180, g_sum+1);
	gf2x_add(360, temp, 360, temp, 360, temp2);
	gf2x_add(181, f_sum+1099, 181, f_sum+1099, 181, temp+179);
	GF2X_MUL(8, temp, 4, f_sum+1+176, 4, p_00+367);
	GF2X_MUL(8, temp2, 4, g_sum+1+176, 4, p_01+367);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, f_sum+1099, 1, f_sum+1099, 1, temp+7);
	right_bit_shift_n(364, f_sum+1099, 18);
	GF2X_MUL(368, temp, 184, f_sum+1+180, 184, p_10+367);
	GF2X_MUL(368, temp2, 184, g_sum+1+180, 184, p_11+367);
	gf2x_add(365, g_sum+1099, 365, temp+3, 365, temp2+3);
	GF2X_MUL(360, temp, 180, p_10+367+4, 180, f_sum+1);
	GF2X_MUL(360, temp2, 180, p_11+367+4, 180, g_sum+1);
	gf2x_add(360, temp, 360, temp, 360, temp2);
	gf2x_add(181, g_sum+1099, 181, g_sum+1099, 181, temp+179);
	GF2X_MUL(8, temp, 4, f_sum+1+176, 4, p_10+367);
	GF2X_MUL(8, temp2, 4, g_sum+1+176, 4, p_11+367);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, g_sum+1099, 1, g_sum+1099, 1, temp+7);
	right_bit_shift_n(364, g_sum+1099, 18);
	

	delta = divstepsx_256(255, delta, f_sum+1277, g_sum+1277, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1273+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1273+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1273+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1273+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1273+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1273+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1273+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1273+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1269+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1269+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1269);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1269+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1269+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1269);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1269);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1257+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1257+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1257+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1257+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1257+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1257+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1257+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1257+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1233+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1233+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1233+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1233+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1233+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1233+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1233+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1233+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5865, depth: 3
	// Digits to shift: 47
	// Displacement: 48
	GF2X_MUL(96, temp, 48, f_sum+1189+44, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1189+44, 48, p_01+643);
	gf2x_add(92, f_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, f_sum+1189);
	GF2X_MUL(88, temp2, 44, p_01+643+4, 44, g_sum+1189);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1928, 44, f_sum+1928, 44, temp+44);
	right_bit_shift_n(92, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1189+44, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1189+44, 48, p_11+643);
	gf2x_add(92, g_sum+1928, 92, temp+4, 92, temp2+4);
	GF2X_MUL(88, temp, 44, p_10+643+4, 44, f_sum+1189);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, g_sum+1189);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1928, 44, g_sum+1928, 44, temp+44);
	right_bit_shift_n(92, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1969, g_sum+1969, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1965+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1965+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1965+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1961+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1961+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1961);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1961);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1949+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1949+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1949+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_01+691);
	gf2x_add(44, f_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_01+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+2069, 20, f_sum+2069, 20, temp+20);
	right_bit_shift_n(44, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+20, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+20, 24, p_11+691);
	gf2x_add(44, g_sum+2069, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+691+4, 20, f_sum+1929);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, g_sum+1929);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+2069, 20, g_sum+2069, 20, temp+20);
	right_bit_shift_n(44, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2086, g_sum+2086, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2082+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2082+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2082+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2078+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2078+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2078);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2078);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_01+715);
	gf2x_add(20, f_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_01+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+2142, 8, f_sum+2142, 8, temp+8);
	right_bit_shift_n(20, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+8, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+8, 12, p_11+715);
	gf2x_add(20, g_sum+2142, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+715+4, 8, f_sum+2070);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, g_sum+2070);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+2142, 8, g_sum+2142, 8, temp+8);
	right_bit_shift_n(20, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2147, g_sum+2147, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_01+727);
	gf2x_add(8, f_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_01+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(8, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+4, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+4, 4, p_11+727);
	gf2x_add(8, g_sum+2179+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2143+0, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(8, g_sum+2179, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, q_00+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, q_01+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, q_10+708+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, q_11+708+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_01+708);
	gf2x_add(16, q_00+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+4, 8, q_00+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+684+0, 8, q_00+684+0, 8, temp);
	memset(q_01+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_00+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_01+708);
	gf2x_add(16, q_01+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+4, 8, q_01+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_01+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+684+0, 8, q_01+684+0, 8, temp);
	memset(q_10+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_10+715+4, 8, q_11+708);
	gf2x_add(16, q_10+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+4, 8, q_10+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_00+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_10+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+684+0, 8, q_10+684+0, 8, temp);
	memset(q_11+684, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+715+4, 8, q_10+708);
	GF2X_MUL(16, temp2, 8, p_11+715+4, 8, q_11+708);
	gf2x_add(16, q_11+684+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+708+4, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+4, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+4, 8, q_11+684+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+708+0, 4, p_01+715);
	GF2X_MUL(8, temp2, 4, q_11+708+0, 4, p_11+715);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+684+0, 8, q_11+684+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_01+684);
	gf2x_add(40, q_00+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+16, 8, q_00+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+12, 8, q_00+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+8, 8, q_00+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+4, 8, q_00+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+640+0, 8, q_00+640+0, 8, temp);
	memset(q_01+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_00+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_01+684);
	gf2x_add(40, q_01+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+16, 8, q_01+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+12, 8, q_01+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+8, 8, q_01+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+4, 8, q_01+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_01+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+640+0, 8, q_01+640+0, 8, temp);
	memset(q_10+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_10+691+4, 20, q_11+684);
	gf2x_add(40, q_10+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+16, 8, q_10+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+12, 8, q_10+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+8, 8, q_10+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+4, 8, q_10+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_00+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_10+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+640+0, 8, q_10+640+0, 8, temp);
	memset(q_11+640, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+691+4, 20, q_10+684);
	GF2X_MUL(40, temp2, 20, p_11+691+4, 20, q_11+684);
	gf2x_add(40, q_11+640+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+684+16, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+16, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+16, 8, q_11+640+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+12, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+12, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+12, 8, q_11+640+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+8, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+8, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+8, 8, q_11+640+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+4, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+4, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+4, 8, q_11+640+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+684+0, 4, p_01+691);
	GF2X_MUL(8, temp2, 4, q_11+684+0, 4, p_11+691);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+640+0, 8, q_11+640+0, 8, temp);
	

	// Recombining results: n: 5865, depth: 3
	memset(p_00+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_01+640);
	gf2x_add(88, p_00+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+40, 8, p_00+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+36, 8, p_00+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+32, 8, p_00+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+28, 8, p_00+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+24, 8, p_00+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+20, 8, p_00+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+16, 8, p_00+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+12, 8, p_00+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+8, 8, p_00+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+4, 8, p_00+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+551+0, 8, p_00+551+0, 8, temp);
	memset(p_01+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_00+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_01+640);
	gf2x_add(88, p_01+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_00+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+40, 8, p_01+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+36, 8, p_01+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+32, 8, p_01+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+28, 8, p_01+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+24, 8, p_01+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+20, 8, p_01+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+16, 8, p_01+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+12, 8, p_01+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+8, 8, p_01+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+4, 8, p_01+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+551+0, 8, p_01+551+0, 8, temp);
	memset(p_10+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_00+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_10+643+4, 44, q_11+640);
	gf2x_add(88, p_10+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+40, 8, p_10+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+36, 8, p_10+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+32, 8, p_10+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+28, 8, p_10+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+24, 8, p_10+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+20, 8, p_10+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+16, 8, p_10+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+12, 8, p_10+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+8, 8, p_10+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+4, 8, p_10+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+551+0, 8, p_10+551+0, 8, temp);
	memset(p_11+551, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(88, temp, 44, p_01+643+4, 44, q_10+640);
	GF2X_MUL(88, temp2, 44, p_11+643+4, 44, q_11+640);
	gf2x_add(88, p_11+551+4, 88, temp, 88, temp2);
	GF2X_MUL(8, temp, 4, q_10+640+40, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+40, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+40, 8, p_11+551+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+36, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+36, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+36, 8, p_11+551+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+32, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+32, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+32, 8, p_11+551+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+28, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+28, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+28, 8, p_11+551+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+24, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+24, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+24, 8, p_11+551+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+20, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+20, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+20, 8, p_11+551+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+16, 8, p_11+551+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+12, 8, p_11+551+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+8, 8, p_11+551+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+4, 8, p_11+551+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+640+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+640+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+551+0, 8, p_11+551+0, 8, temp);
	

	// Calculating left operands: n: 11551, depth: 2
	// Digits to shift: 91
	// Displacement: 92
	GF2X_MUL(184, temp, 92, f_sum+1100+89, 92, p_00+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+89, 92, p_01+551);
	gf2x_add(181, f_sum+1651, 181, temp+3, 181, temp2+3);
	GF2X_MUL(178, temp, 89, p_00+551+3, 89, f_sum+1100);
	GF2X_MUL(178, temp2, 89, p_01+551+3, 89, g_sum+1100);
	gf2x_add(178, temp, 178, temp, 178, temp2);
	gf2x_add(89, f_sum+1651, 89, f_sum+1651, 89, temp+89);
	right_bit_shift_n(181, f_sum+1651, 41);
	GF2X_MUL(184, temp, 92, f_sum+1100+89, 92, p_10+551);
	GF2X_MUL(184, temp2, 92, g_sum+1100+89, 92, p_11+551);
	gf2x_add(181, g_sum+1651, 181, temp+3, 181, temp2+3);
	GF2X_MUL(178, temp, 89, p_10+551+3, 89, f_sum+1100);
	GF2X_MUL(178, temp2, 89, p_11+551+3, 89, g_sum+1100);
	gf2x_add(178, temp, 178, temp, 178, temp2);
	gf2x_add(89, g_sum+1651, 89, g_sum+1651, 89, temp+89);
	right_bit_shift_n(181, g_sum+1651, 41);
	

	delta = divstepsx_256(255, delta, f_sum+1737, g_sum+1737, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1733+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1733+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1733+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1733+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1733+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1733+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1733+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1733+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1729+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1729+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1729);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1729);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1729+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1729+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1729);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1729);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1717+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1717+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1717+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1717+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1717+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1717+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1717+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1717+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 3060, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1693+24, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1693+24, 24, p_01+691);
	gf2x_add(48, f_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1693+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1693+0, 24, p_01+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+2069, 24, f_sum+2069, 24, temp+24);
	right_bit_shift_n(48, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1693+24, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1693+24, 24, p_11+691);
	gf2x_add(48, g_sum+2069+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, f_sum+1693+0, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1693+0, 24, p_11+691);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+2069, 24, g_sum+2069, 24, temp+24);
	right_bit_shift_n(48, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2090, g_sum+2090, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2086+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2086+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2086+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2082+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2082+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2082);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2082);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+2070+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, q_00+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, q_01+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, q_10+684+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, q_11+684+0, 24, temp, 24, temp2);
	

	// Recombining results: n: 3060, depth: 4
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_10+691);
	gf2x_add(48, p_00+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_00+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_01+684+0, 24, p_11+691);
	gf2x_add(48, p_01+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_10+691);
	gf2x_add(48, p_10+643+0, 48, temp, 48, temp2);
	GF2X_MUL(48, temp, 24, q_10+684+0, 24, p_01+691);
	GF2X_MUL(48, temp2, 24, q_11+684+0, 24, p_11+691);
	gf2x_add(48, p_11+643+0, 48, temp, 48, temp2);
	

	// Calculating left operands: n: 5686, depth: 3
	// Digits to shift: 47
	// Displacement: 47
	GF2X_MUL(96, temp, 48, f_sum+1652+41, 48, p_00+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+41, 48, p_01+643);
	gf2x_add(90, f_sum+1928, 90, temp+6, 90, temp2+6);
	GF2X_MUL(82, temp, 41, p_00+643+7, 41, f_sum+1652);
	GF2X_MUL(82, temp2, 41, p_01+643+7, 41, g_sum+1652);
	gf2x_add(82, temp, 82, temp, 82, temp2);
	gf2x_add(42, f_sum+1928, 42, f_sum+1928, 42, temp+40);
	GF2X_MUL(14, temp, 7, f_sum+1652+34, 7, p_00+643);
	GF2X_MUL(14, temp2, 7, g_sum+1652+34, 7, p_01+643);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, f_sum+1928, 1, f_sum+1928, 1, temp+13);
	right_bit_shift_n(89, f_sum+1928, 52);
	GF2X_MUL(96, temp, 48, f_sum+1652+41, 48, p_10+643);
	GF2X_MUL(96, temp2, 48, g_sum+1652+41, 48, p_11+643);
	gf2x_add(90, g_sum+1928, 90, temp+6, 90, temp2+6);
	GF2X_MUL(82, temp, 41, p_10+643+7, 41, f_sum+1652);
	GF2X_MUL(82, temp2, 41, p_11+643+7, 41, g_sum+1652);
	gf2x_add(82, temp, 82, temp, 82, temp2);
	gf2x_add(42, g_sum+1928, 42, g_sum+1928, 42, temp+40);
	GF2X_MUL(14, temp, 7, f_sum+1652+34, 7, p_10+643);
	GF2X_MUL(14, temp2, 7, g_sum+1652+34, 7, p_11+643);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, g_sum+1928, 1, g_sum+1928, 1, temp+13);
	right_bit_shift_n(89, g_sum+1928, 52);
	

	delta = divstepsx_256(255, delta, f_sum+1967, g_sum+1967, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1963+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1963+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1963+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+1963+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+1963+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1963+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1963+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+1963+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1959+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+1959+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+1959);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+1959);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+1959+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+1959+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+1959);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+1959);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1947+12, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1947+12, 12, p_01+715);
	gf2x_add(24, f_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1947+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+1947+0, 12, p_01+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+2142, 12, f_sum+2142, 12, temp+12);
	right_bit_shift_n(24, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+1947+12, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1947+12, 12, p_11+715);
	gf2x_add(24, g_sum+2142+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1947+0, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+1947+0, 12, p_11+715);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+2142, 12, g_sum+2142, 12, temp+12);
	right_bit_shift_n(24, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2151, g_sum+2151, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2147+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2147+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2147+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2143+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2143+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2143);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2143);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(q_00+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, q_00+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+708+0, 8, q_00+708+0, 8, temp);
	memset(q_01+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, q_01+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+708+0, 8, q_01+708+0, 8, temp);
	memset(q_10+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, q_10+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+708+0, 8, q_10+708+0, 8, temp);
	memset(q_11+708, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, q_11+708+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+708+0, 8, q_11+708+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_10+715);
	gf2x_add(24, p_00+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_01+708+0, 12, p_11+715);
	gf2x_add(24, p_01+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_10+715);
	gf2x_add(24, p_10+691+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+708+0, 12, p_01+715);
	GF2X_MUL(24, temp2, 12, q_11+708+0, 12, p_11+715);
	gf2x_add(24, p_11+691+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2626, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1929+18, 24, p_00+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+18, 24, p_01+691);
	gf2x_add(42, f_sum+2069, 42, temp+6, 42, temp2+6);
	GF2X_MUL(36, temp, 18, p_00+691+6, 18, f_sum+1929);
	GF2X_MUL(36, temp2, 18, p_01+691+6, 18, g_sum+1929);
	gf2x_add(36, temp, 36, temp, 36, temp2);
	gf2x_add(18, f_sum+2069, 18, f_sum+2069, 18, temp+18);
	right_bit_shift_n(42, f_sum+2069, 58);
	GF2X_MUL(48, temp, 24, f_sum+1929+18, 24, p_10+691);
	GF2X_MUL(48, temp2, 24, g_sum+1929+18, 24, p_11+691);
	gf2x_add(42, g_sum+2069, 42, temp+6, 42, temp2+6);
	GF2X_MUL(36, temp, 18, p_10+691+6, 18, f_sum+1929);
	GF2X_MUL(36, temp2, 18, p_11+691+6, 18, g_sum+1929);
	gf2x_add(36, temp, 36, temp, 36, temp2);
	gf2x_add(18, g_sum+2069, 18, g_sum+2069, 18, temp+18);
	right_bit_shift_n(42, g_sum+2069, 58);
	

	delta = divstepsx_256(255, delta, f_sum+2084, g_sum+2084, p_00+735, p_01+735, p_10+735, p_11+735);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2080+4, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2080+4, 4, p_01+735);
	gf2x_add(8, f_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2080+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, g_sum+2080+0, 4, p_01+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2200, 4, f_sum+2200, 4, temp+4);
	right_bit_shift_n(8, f_sum+2200, 63);
	GF2X_MUL(8, temp, 4, f_sum+2080+4, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2080+4, 4, p_11+735);
	gf2x_add(8, g_sum+2200+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+2080+0, 4, p_10+735);
	GF2X_MUL(8, temp2, 4, g_sum+2080+0, 4, p_11+735);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2200, 4, g_sum+2200, 4, temp+4);
	right_bit_shift_n(8, g_sum+2200, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2201, g_sum+2201, q_00+724, q_01+724, q_10+724, q_11+724);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_10+735);
	gf2x_add(8, p_00+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_01+724+0, 4, p_11+735);
	gf2x_add(8, p_01+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_00+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_10+735);
	gf2x_add(8, p_10+727+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+724+0, 4, p_01+735);
	GF2X_MUL(8, temp2, 4, q_11+724+0, 4, p_11+735);
	gf2x_add(8, p_11+727+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+2076+4, 8, p_00+727);
	GF2X_MUL(16, temp2, 8, g_sum+2076+4, 8, p_01+727);
	gf2x_add(12, f_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, f_sum+2076);
	GF2X_MUL(8, temp2, 4, p_01+727+4, 4, g_sum+2076);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2179, 4, f_sum+2179, 4, temp+4);
	right_bit_shift_n(12, f_sum+2179, 62);
	GF2X_MUL(16, temp, 8, f_sum+2076+4, 8, p_10+727);
	GF2X_MUL(16, temp2, 8, g_sum+2076+4, 8, p_11+727);
	gf2x_add(12, g_sum+2179, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+727+4, 4, f_sum+2076);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, g_sum+2076);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2179, 4, g_sum+2179, 4, temp+4);
	right_bit_shift_n(12, g_sum+2179, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 765, depth: 6
	memset(p_00+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_01+720);
	gf2x_add(8, p_00+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+715+0, 8, p_00+715+0, 8, temp);
	memset(p_01+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_00+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_01+720);
	gf2x_add(8, p_01+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_01+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+715+0, 8, p_01+715+0, 8, temp);
	memset(p_10+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_10+727+4, 4, q_11+720);
	gf2x_add(8, p_10+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_10+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+715+0, 8, p_10+715+0, 8, temp);
	memset(p_11+715, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+727+4, 4, q_10+720);
	GF2X_MUL(8, temp2, 4, p_11+727+4, 4, q_11+720);
	gf2x_add(8, p_11+715+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+720+0, 4, p_01+727);
	GF2X_MUL(8, temp2, 4, q_11+720+0, 4, p_11+727);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+715+0, 8, p_11+715+0, 8, temp);
	

	// Calculating left operands: n: 1096, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+2070+6, 12, p_00+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+6, 12, p_01+715);
	gf2x_add(18, f_sum+2142, 18, temp+6, 18, temp2+6);
	GF2X_MUL(12, temp, 6, p_00+715+6, 6, f_sum+2070);
	GF2X_MUL(12, temp2, 6, p_01+715+6, 6, g_sum+2070);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, f_sum+2142, 6, f_sum+2142, 6, temp+6);
	right_bit_shift_n(18, f_sum+2142, 61);
	GF2X_MUL(24, temp, 12, f_sum+2070+6, 12, p_10+715);
	GF2X_MUL(24, temp2, 12, g_sum+2070+6, 12, p_11+715);
	gf2x_add(18, g_sum+2142, 18, temp+6, 18, temp2+6);
	GF2X_MUL(12, temp, 6, p_10+715+6, 6, f_sum+2070);
	GF2X_MUL(12, temp2, 6, p_11+715+6, 6, g_sum+2070);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, g_sum+2142, 6, g_sum+2142, 6, temp+6);
	right_bit_shift_n(18, g_sum+2142, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2145, g_sum+2145, p_00+727, p_01+727, p_10+727, p_11+727);

	// Calculating left operands: n: 331, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+2143+2, 4, p_00+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+2, 4, p_01+727);
	gf2x_add(6, f_sum+2179, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_00+727+2, 2, f_sum+2143);
	GF2X_MUL(4, temp2, 2, p_01+727+2, 2, g_sum+2143);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+2179, 2, f_sum+2179, 2, temp+2);
	right_bit_shift_n(6, f_sum+2179, 63);
	GF2X_MUL(8, temp, 4, f_sum+2143+2, 4, p_10+727);
	GF2X_MUL(8, temp2, 4, g_sum+2143+2, 4, p_11+727);
	gf2x_add(6, g_sum+2179, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_10+727+2, 2, f_sum+2143);
	GF2X_MUL(4, temp2, 2, p_11+727+2, 2, g_sum+2143);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+2179, 2, g_sum+2179, 2, temp+2);
	right_bit_shift_n(6, g_sum+2179, 63);
	

	delta = divstepsx_128(76, delta, f_sum+2180, g_sum+2180, q_00+720, q_01+720, q_10+720, q_11+720);

	// Recombining results: n: 331, depth: 6
	memset(q_00+708, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+727+2, 2, q_00+720);
	GF2X_MUL(4, temp2, 2, p_10+727+2, 2, q_01+720);
	gf2x_add(4, q_00+708+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+720+0, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_01+720+0, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+708+0, 4, q_00+708+0, 4, temp);
	memset(q_01+708, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+727+2, 2, q_00+720);
	GF2X_MUL(4, temp2, 2, p_11+727+2, 2, q_01+720);
	gf2x_add(4, q_01+708+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+720+0, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_01+720+0, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+708+0, 4, q_01+708+0, 4, temp);
	memset(q_10+708, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+727+2, 2, q_10+720);
	GF2X_MUL(4, temp2, 2, p_10+727+2, 2, q_11+720);
	gf2x_add(4, q_10+708+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+720+0, 2, p_00+727);
	GF2X_MUL(4, temp2, 2, q_11+720+0, 2, p_10+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+708+0, 4, q_10+708+0, 4, temp);
	memset(q_11+708, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+727+2, 2, q_10+720);
	GF2X_MUL(4, temp2, 2, p_11+727+2, 2, q_11+720);
	gf2x_add(4, q_11+708+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+720+0, 2, p_01+727);
	GF2X_MUL(4, temp2, 2, q_11+720+0, 2, p_11+727);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+708+0, 4, q_11+708+0, 4, temp);
	

	// Recombining results: n: 1096, depth: 5
	memset(q_00+684, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+715+6, 6, q_00+708);
	GF2X_MUL(12, temp2, 6, p_10+715+6, 6, q_01+708);
	gf2x_add(12, q_00+684+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_00+708+0, 6, p_00+715);
	GF2X_MUL(12, temp2, 6, q_01+708+0, 6, p_10+715);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+684+0, 12, q_00+684+0, 12, temp);
	memset(q_01+684, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+715+6, 6, q_00+708);
	GF2X_MUL(12, temp2, 6, p_11+715+6, 6, q_01+708);
	gf2x_add(12, q_01+684+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_00+708+0, 6, p_01+715);
	GF2X_MUL(12, temp2, 6, q_01+708+0, 6, p_11+715);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+684+0, 12, q_01+684+0, 12, temp);
	memset(q_10+684, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+715+6, 6, q_10+708);
	GF2X_MUL(12, temp2, 6, p_10+715+6, 6, q_11+708);
	gf2x_add(12, q_10+684+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_10+708+0, 6, p_00+715);
	GF2X_MUL(12, temp2, 6, q_11+708+0, 6, p_10+715);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+684+0, 12, q_10+684+0, 12, temp);
	memset(q_11+684, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+715+6, 6, q_10+708);
	GF2X_MUL(12, temp2, 6, p_11+715+6, 6, q_11+708);
	gf2x_add(12, q_11+684+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_10+708+0, 6, p_01+715);
	GF2X_MUL(12, temp2, 6, q_11+708+0, 6, p_11+715);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+684+0, 12, q_11+684+0, 12, temp);
	

	// Recombining results: n: 2626, depth: 4
	memset(q_00+640, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_00+691+6, 18, q_00+684);
	GF2X_MUL(36, temp2, 18, p_10+691+6, 18, q_01+684);
	gf2x_add(36, q_00+640+6, 36, temp, 36, temp2);
	GF2X_MUL(12, temp, 6, q_00+684+12, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_01+684+12, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+640+12, 12, q_00+640+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+684+6, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_01+684+6, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+640+6, 12, q_00+640+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+684+0, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_01+684+0, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+640+0, 12, q_00+640+0, 12, temp);
	memset(q_01+640, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_01+691+6, 18, q_00+684);
	GF2X_MUL(36, temp2, 18, p_11+691+6, 18, q_01+684);
	gf2x_add(36, q_01+640+6, 36, temp, 36, temp2);
	GF2X_MUL(12, temp, 6, q_00+684+12, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_01+684+12, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+640+12, 12, q_01+640+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+684+6, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_01+684+6, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+640+6, 12, q_01+640+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+684+0, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_01+684+0, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+640+0, 12, q_01+640+0, 12, temp);
	memset(q_10+640, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_00+691+6, 18, q_10+684);
	GF2X_MUL(36, temp2, 18, p_10+691+6, 18, q_11+684);
	gf2x_add(36, q_10+640+6, 36, temp, 36, temp2);
	GF2X_MUL(12, temp, 6, q_10+684+12, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_11+684+12, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+640+12, 12, q_10+640+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+684+6, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_11+684+6, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+640+6, 12, q_10+640+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+684+0, 6, p_00+691);
	GF2X_MUL(12, temp2, 6, q_11+684+0, 6, p_10+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+640+0, 12, q_10+640+0, 12, temp);
	memset(q_11+640, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_01+691+6, 18, q_10+684);
	GF2X_MUL(36, temp2, 18, p_11+691+6, 18, q_11+684);
	gf2x_add(36, q_11+640+6, 36, temp, 36, temp2);
	GF2X_MUL(12, temp, 6, q_10+684+12, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_11+684+12, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+640+12, 12, q_11+640+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+684+6, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_11+684+6, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+640+6, 12, q_11+640+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+684+0, 6, p_01+691);
	GF2X_MUL(12, temp2, 6, q_11+684+0, 6, p_11+691);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+640+0, 12, q_11+640+0, 12, temp);
	

	// Recombining results: n: 5686, depth: 3
	memset(q_00+548, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(84, temp, 42, p_00+643+6, 42, q_00+640);
	GF2X_MUL(84, temp2, 42, p_10+643+6, 42, q_01+640);
	gf2x_add(84, q_00+548+5, 84, temp, 84, temp2);
	GF2X_MUL(12, temp, 6, q_00+640+36, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+36, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+35, 12, q_00+548+35, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+30, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+30, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+29, 12, q_00+548+29, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+24, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+24, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+23, 12, q_00+548+23, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+18, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+18, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+17, 12, q_00+548+17, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+12, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+12, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+11, 12, q_00+548+11, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+6, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+6, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+548+5, 12, q_00+548+5, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+0, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_01+640+0, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(11, q_00+548, 11, q_00+548, 11, temp+1);
	memset(q_01+548, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(84, temp, 42, p_01+643+6, 42, q_00+640);
	GF2X_MUL(84, temp2, 42, p_11+643+6, 42, q_01+640);
	gf2x_add(84, q_01+548+5, 84, temp, 84, temp2);
	GF2X_MUL(12, temp, 6, q_00+640+36, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+36, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+35, 12, q_01+548+35, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+30, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+30, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+29, 12, q_01+548+29, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+24, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+24, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+23, 12, q_01+548+23, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+18, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+18, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+17, 12, q_01+548+17, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+12, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+12, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+11, 12, q_01+548+11, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+6, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+6, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+548+5, 12, q_01+548+5, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+640+0, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_01+640+0, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(11, q_01+548, 11, q_01+548, 11, temp+1);
	memset(q_10+548, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(84, temp, 42, p_00+643+6, 42, q_10+640);
	GF2X_MUL(84, temp2, 42, p_10+643+6, 42, q_11+640);
	gf2x_add(84, q_10+548+5, 84, temp, 84, temp2);
	GF2X_MUL(12, temp, 6, q_10+640+36, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+36, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+35, 12, q_10+548+35, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+30, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+30, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+29, 12, q_10+548+29, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+24, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+24, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+23, 12, q_10+548+23, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+18, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+18, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+17, 12, q_10+548+17, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+12, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+12, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+11, 12, q_10+548+11, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+6, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+6, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+548+5, 12, q_10+548+5, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+0, 6, p_00+643);
	GF2X_MUL(12, temp2, 6, q_11+640+0, 6, p_10+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(11, q_10+548, 11, q_10+548, 11, temp+1);
	memset(q_11+548, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(84, temp, 42, p_01+643+6, 42, q_10+640);
	GF2X_MUL(84, temp2, 42, p_11+643+6, 42, q_11+640);
	gf2x_add(84, q_11+548+5, 84, temp, 84, temp2);
	GF2X_MUL(12, temp, 6, q_10+640+36, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+36, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+35, 12, q_11+548+35, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+30, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+30, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+29, 12, q_11+548+29, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+24, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+24, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+23, 12, q_11+548+23, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+18, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+18, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+17, 12, q_11+548+17, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+12, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+12, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+11, 12, q_11+548+11, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+6, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+6, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+548+5, 12, q_11+548+5, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+640+0, 6, p_01+643);
	GF2X_MUL(12, temp2, 6, q_11+640+0, 6, p_11+643);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(11, q_11+548, 11, q_11+548, 11, temp+1);
	

	// Recombining results: n: 11551, depth: 2
	memset(q_00+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(178, temp, 89, p_00+551+3, 89, q_00+548);
	GF2X_MUL(178, temp2, 89, p_10+551+3, 89, q_01+548);
	gf2x_add(178, q_00+364+3, 178, temp, 178, temp2);
	GF2X_MUL(6, temp, 3, q_00+548+86, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+86, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+86, 6, q_00+364+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+83, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+83, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+83, 6, q_00+364+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+80, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+80, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+80, 6, q_00+364+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+77, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+77, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+77, 6, q_00+364+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+74, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+74, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+74, 6, q_00+364+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+71, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+71, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+71, 6, q_00+364+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+68, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+68, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+68, 6, q_00+364+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+65, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+65, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+65, 6, q_00+364+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+62, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+62, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+62, 6, q_00+364+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+59, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+59, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+59, 6, q_00+364+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+56, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+56, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+56, 6, q_00+364+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+53, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+53, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+53, 6, q_00+364+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+50, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+50, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+50, 6, q_00+364+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+47, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+47, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+47, 6, q_00+364+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+44, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+44, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+44, 6, q_00+364+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+41, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+41, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+41, 6, q_00+364+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+38, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+38, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+38, 6, q_00+364+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+35, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+35, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+35, 6, q_00+364+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+32, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+32, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+32, 6, q_00+364+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+29, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+29, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+29, 6, q_00+364+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+26, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+26, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+26, 6, q_00+364+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+23, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+23, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+23, 6, q_00+364+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+20, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+20, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+20, 6, q_00+364+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+17, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+17, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+17, 6, q_00+364+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+14, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+14, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+14, 6, q_00+364+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+11, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+11, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+11, 6, q_00+364+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+8, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+8, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+8, 6, q_00+364+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+5, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+5, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+5, 6, q_00+364+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+2, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_01+548+2, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+364+2, 6, q_00+364+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+551+1, 2, q_00+548);
	GF2X_MUL(4, temp2, 2, p_10+551+1, 2, q_01+548);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+364+1, 4, q_00+364+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+548+1, 1, p_00+551);
	GF2X_MUL(2, temp2, 1, q_01+548+1, 1, p_10+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+364+1, 2, q_00+364+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+548+0, 1, p_00+551);
	GF2X_MUL(2, temp2, 1, q_01+548+0, 1, p_10+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+364+0, 2, q_00+364+0, 2, temp);
	memset(q_01+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(178, temp, 89, p_01+551+3, 89, q_00+548);
	GF2X_MUL(178, temp2, 89, p_11+551+3, 89, q_01+548);
	gf2x_add(178, q_01+364+3, 178, temp, 178, temp2);
	GF2X_MUL(6, temp, 3, q_00+548+86, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+86, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+86, 6, q_01+364+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+83, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+83, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+83, 6, q_01+364+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+80, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+80, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+80, 6, q_01+364+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+77, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+77, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+77, 6, q_01+364+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+74, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+74, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+74, 6, q_01+364+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+71, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+71, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+71, 6, q_01+364+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+68, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+68, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+68, 6, q_01+364+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+65, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+65, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+65, 6, q_01+364+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+62, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+62, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+62, 6, q_01+364+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+59, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+59, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+59, 6, q_01+364+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+56, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+56, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+56, 6, q_01+364+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+53, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+53, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+53, 6, q_01+364+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+50, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+50, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+50, 6, q_01+364+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+47, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+47, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+47, 6, q_01+364+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+44, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+44, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+44, 6, q_01+364+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+41, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+41, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+41, 6, q_01+364+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+38, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+38, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+38, 6, q_01+364+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+35, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+35, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+35, 6, q_01+364+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+32, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+32, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+32, 6, q_01+364+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+29, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+29, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+29, 6, q_01+364+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+26, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+26, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+26, 6, q_01+364+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+23, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+23, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+23, 6, q_01+364+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+20, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+20, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+20, 6, q_01+364+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+17, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+17, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+17, 6, q_01+364+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+14, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+14, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+14, 6, q_01+364+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+11, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+11, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+11, 6, q_01+364+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+8, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+8, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+8, 6, q_01+364+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+5, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+5, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+5, 6, q_01+364+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+548+2, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_01+548+2, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+364+2, 6, q_01+364+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+551+1, 2, q_00+548);
	GF2X_MUL(4, temp2, 2, p_11+551+1, 2, q_01+548);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+364+1, 4, q_01+364+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+548+1, 1, p_01+551);
	GF2X_MUL(2, temp2, 1, q_01+548+1, 1, p_11+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+364+1, 2, q_01+364+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+548+0, 1, p_01+551);
	GF2X_MUL(2, temp2, 1, q_01+548+0, 1, p_11+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+364+0, 2, q_01+364+0, 2, temp);
	memset(q_10+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(178, temp, 89, p_00+551+3, 89, q_10+548);
	GF2X_MUL(178, temp2, 89, p_10+551+3, 89, q_11+548);
	gf2x_add(178, q_10+364+3, 178, temp, 178, temp2);
	GF2X_MUL(6, temp, 3, q_10+548+86, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+86, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+86, 6, q_10+364+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+83, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+83, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+83, 6, q_10+364+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+80, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+80, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+80, 6, q_10+364+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+77, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+77, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+77, 6, q_10+364+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+74, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+74, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+74, 6, q_10+364+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+71, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+71, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+71, 6, q_10+364+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+68, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+68, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+68, 6, q_10+364+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+65, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+65, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+65, 6, q_10+364+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+62, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+62, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+62, 6, q_10+364+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+59, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+59, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+59, 6, q_10+364+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+56, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+56, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+56, 6, q_10+364+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+53, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+53, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+53, 6, q_10+364+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+50, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+50, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+50, 6, q_10+364+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+47, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+47, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+47, 6, q_10+364+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+44, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+44, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+44, 6, q_10+364+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+41, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+41, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+41, 6, q_10+364+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+38, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+38, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+38, 6, q_10+364+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+35, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+35, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+35, 6, q_10+364+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+32, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+32, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+32, 6, q_10+364+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+29, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+29, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+29, 6, q_10+364+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+26, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+26, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+26, 6, q_10+364+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+23, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+23, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+23, 6, q_10+364+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+20, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+20, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+20, 6, q_10+364+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+17, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+17, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+17, 6, q_10+364+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+14, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+14, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+14, 6, q_10+364+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+11, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+11, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+11, 6, q_10+364+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+8, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+8, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+8, 6, q_10+364+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+5, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+5, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+5, 6, q_10+364+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+2, 3, p_00+551);
	GF2X_MUL(6, temp2, 3, q_11+548+2, 3, p_10+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+364+2, 6, q_10+364+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+551+1, 2, q_10+548);
	GF2X_MUL(4, temp2, 2, p_10+551+1, 2, q_11+548);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+364+1, 4, q_10+364+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+548+1, 1, p_00+551);
	GF2X_MUL(2, temp2, 1, q_11+548+1, 1, p_10+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+364+1, 2, q_10+364+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+548+0, 1, p_00+551);
	GF2X_MUL(2, temp2, 1, q_11+548+0, 1, p_10+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+364+0, 2, q_10+364+0, 2, temp);
	memset(q_11+364, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(178, temp, 89, p_01+551+3, 89, q_10+548);
	GF2X_MUL(178, temp2, 89, p_11+551+3, 89, q_11+548);
	gf2x_add(178, q_11+364+3, 178, temp, 178, temp2);
	GF2X_MUL(6, temp, 3, q_10+548+86, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+86, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+86, 6, q_11+364+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+83, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+83, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+83, 6, q_11+364+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+80, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+80, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+80, 6, q_11+364+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+77, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+77, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+77, 6, q_11+364+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+74, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+74, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+74, 6, q_11+364+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+71, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+71, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+71, 6, q_11+364+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+68, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+68, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+68, 6, q_11+364+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+65, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+65, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+65, 6, q_11+364+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+62, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+62, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+62, 6, q_11+364+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+59, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+59, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+59, 6, q_11+364+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+56, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+56, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+56, 6, q_11+364+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+53, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+53, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+53, 6, q_11+364+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+50, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+50, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+50, 6, q_11+364+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+47, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+47, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+47, 6, q_11+364+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+44, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+44, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+44, 6, q_11+364+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+41, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+41, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+41, 6, q_11+364+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+38, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+38, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+38, 6, q_11+364+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+35, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+35, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+35, 6, q_11+364+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+32, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+32, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+32, 6, q_11+364+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+29, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+29, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+29, 6, q_11+364+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+26, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+26, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+26, 6, q_11+364+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+23, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+23, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+23, 6, q_11+364+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+20, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+20, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+20, 6, q_11+364+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+17, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+17, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+17, 6, q_11+364+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+14, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+14, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+14, 6, q_11+364+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+11, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+11, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+11, 6, q_11+364+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+8, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+8, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+8, 6, q_11+364+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+5, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+5, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+5, 6, q_11+364+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+548+2, 3, p_01+551);
	GF2X_MUL(6, temp2, 3, q_11+548+2, 3, p_11+551);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+364+2, 6, q_11+364+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+551+1, 2, q_10+548);
	GF2X_MUL(4, temp2, 2, p_11+551+1, 2, q_11+548);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+364+1, 4, q_11+364+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+548+1, 1, p_01+551);
	GF2X_MUL(2, temp2, 1, q_11+548+1, 1, p_11+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+364+1, 2, q_11+364+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+548+0, 1, p_01+551);
	GF2X_MUL(2, temp2, 1, q_11+548+0, 1, p_11+551);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+364+0, 2, q_11+364+0, 2, temp);
	

	// Recombining results: n: 23281, depth: 1
	memset(q_00+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(362, temp, 181, p_00+367+3, 181, q_00+364);
	GF2X_MUL(362, temp2, 181, p_10+367+3, 181, q_01+364);
	gf2x_add(362, q_00+0+2, 362, temp, 362, temp2);
	GF2X_MUL(6, temp, 3, q_00+364+178, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+178, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+177, 6, q_00+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+175, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+175, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+174, 6, q_00+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+172, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+172, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+171, 6, q_00+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+169, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+169, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+168, 6, q_00+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+166, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+166, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+165, 6, q_00+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+163, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+163, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+162, 6, q_00+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+160, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+160, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+159, 6, q_00+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+157, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+157, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+156, 6, q_00+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+154, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+154, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+153, 6, q_00+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+151, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+151, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+150, 6, q_00+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+148, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+148, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+147, 6, q_00+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+145, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+145, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+144, 6, q_00+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+142, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+142, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+141, 6, q_00+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+139, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+139, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+138, 6, q_00+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+136, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+136, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+135, 6, q_00+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+133, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+133, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+132, 6, q_00+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+130, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+130, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+129, 6, q_00+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+127, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+127, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+126, 6, q_00+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+124, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+124, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+123, 6, q_00+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+121, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+121, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+120, 6, q_00+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+118, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+118, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+117, 6, q_00+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+115, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+115, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+114, 6, q_00+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+112, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+112, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+111, 6, q_00+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+109, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+109, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+108, 6, q_00+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+106, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+106, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+105, 6, q_00+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+103, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+103, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+102, 6, q_00+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+100, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+100, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+99, 6, q_00+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+97, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+97, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+96, 6, q_00+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+94, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+94, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+93, 6, q_00+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+91, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+91, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+90, 6, q_00+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+88, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+88, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+87, 6, q_00+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+85, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+85, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+84, 6, q_00+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+82, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+82, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+81, 6, q_00+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+79, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+79, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+78, 6, q_00+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+76, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+76, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+75, 6, q_00+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+73, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+73, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+72, 6, q_00+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+70, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+70, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+69, 6, q_00+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+67, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+67, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+66, 6, q_00+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+64, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+64, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+63, 6, q_00+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+61, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+61, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+60, 6, q_00+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+58, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+58, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+57, 6, q_00+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+55, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+55, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+54, 6, q_00+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+52, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+52, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+51, 6, q_00+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+49, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+49, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+48, 6, q_00+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+46, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+46, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+45, 6, q_00+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+43, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+43, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+42, 6, q_00+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+40, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+40, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+39, 6, q_00+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+37, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+37, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+36, 6, q_00+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+34, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+34, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+33, 6, q_00+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+31, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+31, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+30, 6, q_00+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+28, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+28, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+27, 6, q_00+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+25, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+25, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+24, 6, q_00+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+22, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+22, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+21, 6, q_00+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+19, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+19, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+18, 6, q_00+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+16, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+16, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+15, 6, q_00+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+13, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+13, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+12, 6, q_00+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+10, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+10, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+9, 6, q_00+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+7, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+7, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+6, 6, q_00+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+4, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+4, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+3, 6, q_00+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+1, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_01+364+1, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+0, 6, q_00+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+367+2, 1, q_00+364);
	GF2X_MUL(2, temp2, 1, p_10+367+2, 1, q_01+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+367+1, 1, q_00+364);
	GF2X_MUL(2, temp2, 1, p_10+367+1, 1, q_01+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+364+0, 1, p_00+367);
	GF2X_MUL(2, temp2, 1, q_01+364+0, 1, p_10+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+0, 1, q_00+0, 1, temp+1);
	memset(q_01+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(362, temp, 181, p_01+367+3, 181, q_00+364);
	GF2X_MUL(362, temp2, 181, p_11+367+3, 181, q_01+364);
	gf2x_add(362, q_01+0+2, 362, temp, 362, temp2);
	GF2X_MUL(6, temp, 3, q_00+364+178, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+178, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+177, 6, q_01+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+175, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+175, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+174, 6, q_01+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+172, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+172, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+171, 6, q_01+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+169, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+169, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+168, 6, q_01+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+166, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+166, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+165, 6, q_01+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+163, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+163, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+162, 6, q_01+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+160, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+160, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+159, 6, q_01+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+157, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+157, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+156, 6, q_01+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+154, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+154, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+153, 6, q_01+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+151, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+151, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+150, 6, q_01+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+148, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+148, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+147, 6, q_01+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+145, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+145, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+144, 6, q_01+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+142, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+142, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+141, 6, q_01+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+139, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+139, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+138, 6, q_01+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+136, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+136, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+135, 6, q_01+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+133, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+133, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+132, 6, q_01+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+130, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+130, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+129, 6, q_01+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+127, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+127, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+126, 6, q_01+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+124, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+124, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+123, 6, q_01+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+121, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+121, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+120, 6, q_01+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+118, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+118, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+117, 6, q_01+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+115, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+115, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+114, 6, q_01+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+112, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+112, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+111, 6, q_01+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+109, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+109, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+108, 6, q_01+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+106, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+106, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+105, 6, q_01+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+103, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+103, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+102, 6, q_01+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+100, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+100, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+99, 6, q_01+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+97, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+97, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+96, 6, q_01+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+94, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+94, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+93, 6, q_01+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+91, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+91, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+90, 6, q_01+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+88, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+88, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+87, 6, q_01+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+85, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+85, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+84, 6, q_01+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+82, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+82, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+81, 6, q_01+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+79, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+79, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+78, 6, q_01+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+76, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+76, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+75, 6, q_01+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+73, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+73, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+72, 6, q_01+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+70, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+70, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+69, 6, q_01+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+67, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+67, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+66, 6, q_01+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+64, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+64, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+63, 6, q_01+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+61, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+61, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+60, 6, q_01+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+58, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+58, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+57, 6, q_01+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+55, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+55, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+54, 6, q_01+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+52, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+52, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+51, 6, q_01+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+49, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+49, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+48, 6, q_01+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+46, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+46, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+45, 6, q_01+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+43, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+43, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+42, 6, q_01+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+40, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+40, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+39, 6, q_01+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+37, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+37, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+36, 6, q_01+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+34, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+34, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+33, 6, q_01+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+31, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+31, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+30, 6, q_01+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+28, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+28, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+27, 6, q_01+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+25, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+25, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+24, 6, q_01+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+22, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+22, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+21, 6, q_01+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+19, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+19, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+18, 6, q_01+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+16, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+16, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+15, 6, q_01+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+13, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+13, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+12, 6, q_01+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+10, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+10, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+9, 6, q_01+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+7, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+7, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+6, 6, q_01+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+4, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+4, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+3, 6, q_01+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+364+1, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_01+364+1, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+0, 6, q_01+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+367+2, 1, q_00+364);
	GF2X_MUL(2, temp2, 1, p_11+367+2, 1, q_01+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+367+1, 1, q_00+364);
	GF2X_MUL(2, temp2, 1, p_11+367+1, 1, q_01+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+364+0, 1, p_01+367);
	GF2X_MUL(2, temp2, 1, q_01+364+0, 1, p_11+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+0, 1, q_01+0, 1, temp+1);
	memset(q_10+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(362, temp, 181, p_00+367+3, 181, q_10+364);
	GF2X_MUL(362, temp2, 181, p_10+367+3, 181, q_11+364);
	gf2x_add(362, q_10+0+2, 362, temp, 362, temp2);
	GF2X_MUL(6, temp, 3, q_10+364+178, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+178, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+177, 6, q_10+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+175, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+175, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+174, 6, q_10+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+172, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+172, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+171, 6, q_10+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+169, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+169, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+168, 6, q_10+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+166, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+166, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+165, 6, q_10+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+163, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+163, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+162, 6, q_10+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+160, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+160, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+159, 6, q_10+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+157, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+157, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+156, 6, q_10+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+154, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+154, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+153, 6, q_10+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+151, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+151, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+150, 6, q_10+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+148, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+148, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+147, 6, q_10+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+145, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+145, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+144, 6, q_10+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+142, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+142, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+141, 6, q_10+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+139, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+139, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+138, 6, q_10+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+136, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+136, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+135, 6, q_10+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+133, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+133, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+132, 6, q_10+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+130, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+130, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+129, 6, q_10+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+127, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+127, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+126, 6, q_10+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+124, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+124, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+123, 6, q_10+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+121, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+121, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+120, 6, q_10+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+118, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+118, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+117, 6, q_10+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+115, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+115, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+114, 6, q_10+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+112, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+112, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+111, 6, q_10+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+109, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+109, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+108, 6, q_10+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+106, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+106, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+105, 6, q_10+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+103, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+103, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+102, 6, q_10+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+100, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+100, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+99, 6, q_10+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+97, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+97, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+96, 6, q_10+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+94, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+94, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+93, 6, q_10+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+91, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+91, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+90, 6, q_10+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+88, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+88, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+87, 6, q_10+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+85, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+85, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+84, 6, q_10+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+82, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+82, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+81, 6, q_10+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+79, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+79, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+78, 6, q_10+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+76, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+76, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+75, 6, q_10+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+73, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+73, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+72, 6, q_10+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+70, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+70, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+69, 6, q_10+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+67, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+67, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+66, 6, q_10+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+64, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+64, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+63, 6, q_10+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+61, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+61, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+60, 6, q_10+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+58, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+58, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+57, 6, q_10+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+55, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+55, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+54, 6, q_10+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+52, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+52, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+51, 6, q_10+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+49, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+49, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+48, 6, q_10+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+46, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+46, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+45, 6, q_10+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+43, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+43, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+42, 6, q_10+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+40, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+40, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+39, 6, q_10+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+37, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+37, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+36, 6, q_10+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+34, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+34, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+33, 6, q_10+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+31, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+31, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+30, 6, q_10+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+28, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+28, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+27, 6, q_10+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+25, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+25, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+24, 6, q_10+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+22, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+22, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+21, 6, q_10+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+19, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+19, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+18, 6, q_10+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+16, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+16, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+15, 6, q_10+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+13, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+13, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+12, 6, q_10+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+10, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+10, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+9, 6, q_10+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+7, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+7, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+6, 6, q_10+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+4, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+4, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+3, 6, q_10+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+1, 3, p_00+367);
	GF2X_MUL(6, temp2, 3, q_11+364+1, 3, p_10+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+0, 6, q_10+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+367+2, 1, q_10+364);
	GF2X_MUL(2, temp2, 1, p_10+367+2, 1, q_11+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+367+1, 1, q_10+364);
	GF2X_MUL(2, temp2, 1, p_10+367+1, 1, q_11+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+364+0, 1, p_00+367);
	GF2X_MUL(2, temp2, 1, q_11+364+0, 1, p_10+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+0, 1, q_10+0, 1, temp+1);
	memset(q_11+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(362, temp, 181, p_01+367+3, 181, q_10+364);
	GF2X_MUL(362, temp2, 181, p_11+367+3, 181, q_11+364);
	gf2x_add(362, q_11+0+2, 362, temp, 362, temp2);
	GF2X_MUL(6, temp, 3, q_10+364+178, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+178, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+177, 6, q_11+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+175, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+175, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+174, 6, q_11+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+172, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+172, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+171, 6, q_11+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+169, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+169, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+168, 6, q_11+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+166, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+166, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+165, 6, q_11+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+163, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+163, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+162, 6, q_11+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+160, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+160, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+159, 6, q_11+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+157, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+157, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+156, 6, q_11+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+154, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+154, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+153, 6, q_11+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+151, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+151, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+150, 6, q_11+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+148, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+148, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+147, 6, q_11+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+145, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+145, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+144, 6, q_11+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+142, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+142, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+141, 6, q_11+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+139, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+139, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+138, 6, q_11+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+136, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+136, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+135, 6, q_11+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+133, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+133, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+132, 6, q_11+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+130, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+130, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+129, 6, q_11+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+127, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+127, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+126, 6, q_11+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+124, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+124, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+123, 6, q_11+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+121, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+121, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+120, 6, q_11+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+118, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+118, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+117, 6, q_11+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+115, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+115, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+114, 6, q_11+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+112, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+112, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+111, 6, q_11+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+109, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+109, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+108, 6, q_11+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+106, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+106, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+105, 6, q_11+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+103, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+103, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+102, 6, q_11+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+100, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+100, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+99, 6, q_11+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+97, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+97, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+96, 6, q_11+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+94, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+94, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+93, 6, q_11+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+91, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+91, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+90, 6, q_11+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+88, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+88, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+87, 6, q_11+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+85, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+85, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+84, 6, q_11+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+82, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+82, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+81, 6, q_11+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+79, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+79, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+78, 6, q_11+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+76, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+76, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+75, 6, q_11+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+73, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+73, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+72, 6, q_11+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+70, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+70, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+69, 6, q_11+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+67, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+67, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+66, 6, q_11+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+64, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+64, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+63, 6, q_11+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+61, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+61, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+60, 6, q_11+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+58, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+58, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+57, 6, q_11+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+55, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+55, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+54, 6, q_11+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+52, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+52, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+51, 6, q_11+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+49, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+49, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+48, 6, q_11+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+46, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+46, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+45, 6, q_11+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+43, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+43, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+42, 6, q_11+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+40, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+40, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+39, 6, q_11+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+37, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+37, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+36, 6, q_11+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+34, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+34, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+33, 6, q_11+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+31, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+31, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+30, 6, q_11+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+28, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+28, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+27, 6, q_11+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+25, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+25, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+24, 6, q_11+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+22, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+22, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+21, 6, q_11+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+19, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+19, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+18, 6, q_11+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+16, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+16, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+15, 6, q_11+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+13, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+13, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+12, 6, q_11+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+10, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+10, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+9, 6, q_11+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+7, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+7, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+6, 6, q_11+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+4, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+4, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+3, 6, q_11+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+364+1, 3, p_01+367);
	GF2X_MUL(6, temp2, 3, q_11+364+1, 3, p_11+367);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+0, 6, q_11+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+367+2, 1, q_10+364);
	GF2X_MUL(2, temp2, 1, p_11+367+2, 1, q_11+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+367+1, 1, q_10+364);
	GF2X_MUL(2, temp2, 1, p_11+367+1, 1, q_11+364);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+364+0, 1, p_01+367);
	GF2X_MUL(2, temp2, 1, q_11+364+0, 1, p_11+367);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+0, 1, q_11+0, 1, temp+1);
	

	// Recombining results: n: 46741, depth: 0
	memset(t_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(728, temp, 364, p_00+0+3, 364, q_00+0);
	GF2X_MUL(728, temp2, 364, p_10+0+3, 364, q_01+0);
	gf2x_add(728, t_00+0+3, 728, temp, 728, temp2);
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
	GF2X_MUL(728, temp, 364, p_01+0+3, 364, q_00+0);
	GF2X_MUL(728, temp2, 364, p_11+0+3, 364, q_01+0);
	gf2x_add(728, t_01+0+3, 728, temp, 728, temp2);
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
	GF2X_MUL(728, temp, 364, p_00+0+3, 364, q_10+0);
	GF2X_MUL(728, temp2, 364, p_10+0+3, 364, q_11+0);
	gf2x_add(728, t_10+0+3, 728, temp, 728, temp2);
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
	GF2X_MUL(728, temp, 364, p_01+0+3, 364, q_10+0);
	GF2X_MUL(728, temp2, 364, p_11+0+3, 364, q_11+0);
	gf2x_add(728, t_11+0+3, 728, temp, 728, temp2);
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