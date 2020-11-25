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

int jumpdivstep_21611(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[691];
	DIGIT p_01[691];
	DIGIT p_10[691];
	DIGIT p_11[691];
	
	DIGIT q_00[673];
	DIGIT q_01[673];
	DIGIT q_10[673];
	DIGIT q_11[673];
	
	DIGIT f_sum[2063];
	DIGIT g_sum[2063];
	
	DIGIT temp[1354];
	DIGIT temp2[1354];
	

	delta = divstepsx_256(255, delta, f+672, g+672, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+668+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g+668+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+668+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g+668+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f+668+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g+668+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+668+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g+668+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+664+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g+664+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f+664);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g+664);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f+664+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g+664+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f+664);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g+664);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+652+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g+652+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+652+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g+652+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f+652+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g+652+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f+652+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g+652+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f+632+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g+632+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f+632);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g+632);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f+632+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g+632+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f+632);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g+632);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5610, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f+588+44, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g+588+44, 44, p_01+599);
	gf2x_add(88, f_sum+1789+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f+588+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g+588+0, 44, p_01+599);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1789, 44, f_sum+1789, 44, temp+44);
	right_bit_shift_n(88, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f+588+44, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g+588+44, 44, p_11+599);
	gf2x_add(88, g_sum+1789+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f+588+0, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g+588+0, 44, p_11+599);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1789, 44, g_sum+1789, 44, temp+44);
	right_bit_shift_n(88, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1830, g_sum+1830, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1826+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1826+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1826+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1826+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1822+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1822+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1822);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1822);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1822+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1822+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1822);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1822);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1810+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1810+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1790+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1790+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1790);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1790);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1790+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1790+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1790);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1790);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, q_00+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+16, 8, q_00+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+12, 8, q_00+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+8, 8, q_00+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+4, 8, q_00+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+0, 8, q_00+589+0, 8, temp);
	memset(q_01+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, q_01+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+16, 8, q_01+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+12, 8, q_01+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+8, 8, q_01+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+4, 8, q_01+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+0, 8, q_01+589+0, 8, temp);
	memset(q_10+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, q_10+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+16, 8, q_10+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+12, 8, q_10+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+8, 8, q_10+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+4, 8, q_10+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+0, 8, q_10+589+0, 8, temp);
	memset(q_11+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, q_11+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+16, 8, q_11+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+12, 8, q_11+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+8, 8, q_11+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+4, 8, q_11+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+0, 8, q_11+589+0, 8, temp);
	

	// Recombining results: n: 5610, depth: 3
	GF2X_MUL(88, temp, 44, q_00+589+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, q_01+589+0, 44, p_10+599);
	gf2x_add(88, p_00+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_00+589+0, 44, p_01+599);
	GF2X_MUL(88, temp2, 44, q_01+589+0, 44, p_11+599);
	gf2x_add(88, p_01+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+589+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, q_11+589+0, 44, p_10+599);
	gf2x_add(88, p_10+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+589+0, 44, p_01+599);
	GF2X_MUL(88, temp2, 44, q_11+589+0, 44, p_11+599);
	gf2x_add(88, p_11+511+0, 88, temp, 88, temp2);
	

	// Calculating left operands: n: 10965, depth: 2
	// Digits to shift: 87
	// Displacement: 88
	GF2X_MUL(176, temp, 88, f+504+84, 88, p_00+511);
	GF2X_MUL(176, temp2, 88, g+504+84, 88, p_01+511);
	gf2x_add(172, f_sum+1528, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, f+504);
	GF2X_MUL(168, temp2, 84, p_01+511+4, 84, g+504);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, f_sum+1528, 84, f_sum+1528, 84, temp+84);
	right_bit_shift_n(172, f_sum+1528, 42);
	GF2X_MUL(176, temp, 88, f+504+84, 88, p_10+511);
	GF2X_MUL(176, temp2, 88, g+504+84, 88, p_11+511);
	gf2x_add(172, g_sum+1528, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_10+511+4, 84, f+504);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, g+504);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, g_sum+1528, 84, g_sum+1528, 84, temp+84);
	right_bit_shift_n(172, g_sum+1528, 42);
	

	delta = divstepsx_256(255, delta, f_sum+1609, g_sum+1609, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_01+599);
	gf2x_add(84, f_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_01+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1789, 40, f_sum+1789, 40, temp+40);
	right_bit_shift_n(84, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_11+599);
	gf2x_add(84, g_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1789, 40, g_sum+1789, 40, temp+40);
	right_bit_shift_n(84, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1826, g_sum+1826, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_01+643);
	gf2x_add(40, f_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_01+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(40, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_11+643);
	gf2x_add(40, g_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_11+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(40, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_10+643);
	gf2x_add(40, q_00+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_11+643);
	gf2x_add(40, q_01+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_10+643);
	gf2x_add(40, q_10+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_11+643);
	gf2x_add(40, q_11+589+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(q_00+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_01+589);
	gf2x_add(80, q_00+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+36, 8, q_00+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+32, 8, q_00+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+28, 8, q_00+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+24, 8, q_00+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+20, 8, q_00+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+16, 8, q_00+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+12, 8, q_00+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+8, 8, q_00+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+4, 8, q_00+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+0, 8, q_00+505+0, 8, temp);
	memset(q_01+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_01+589);
	gf2x_add(80, q_01+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+36, 8, q_01+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+32, 8, q_01+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+28, 8, q_01+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+24, 8, q_01+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+20, 8, q_01+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+16, 8, q_01+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+12, 8, q_01+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+8, 8, q_01+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+4, 8, q_01+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+0, 8, q_01+505+0, 8, temp);
	memset(q_10+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_11+589);
	gf2x_add(80, q_10+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+36, 8, q_10+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+32, 8, q_10+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+28, 8, q_10+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+24, 8, q_10+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+20, 8, q_10+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+16, 8, q_10+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+12, 8, q_10+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+8, 8, q_10+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+4, 8, q_10+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+0, 8, q_10+505+0, 8, temp);
	memset(q_11+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_11+589);
	gf2x_add(80, q_11+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+36, 8, q_11+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+32, 8, q_11+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+28, 8, q_11+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+24, 8, q_11+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+20, 8, q_11+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+16, 8, q_11+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+12, 8, q_11+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+8, 8, q_11+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+4, 8, q_11+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+0, 8, q_11+505+0, 8, temp);
	

	// Recombining results: n: 10965, depth: 2
	memset(p_00+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, q_00+505);
	GF2X_MUL(168, temp2, 84, p_10+511+4, 84, q_01+505);
	gf2x_add(168, p_00+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+505+80, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+80, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+80, 8, p_00+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+76, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+76, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+76, 8, p_00+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+72, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+72, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+72, 8, p_00+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+68, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+68, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+68, 8, p_00+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+64, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+64, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+64, 8, p_00+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+60, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+60, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+60, 8, p_00+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+56, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+56, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+56, 8, p_00+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+52, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+52, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+52, 8, p_00+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+48, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+48, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+48, 8, p_00+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+44, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+44, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+44, 8, p_00+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+40, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+40, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+40, 8, p_00+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+36, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+36, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+36, 8, p_00+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+32, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+32, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+32, 8, p_00+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+28, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+28, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+28, 8, p_00+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+24, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+24, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+24, 8, p_00+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+20, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+20, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+20, 8, p_00+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+16, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+16, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+16, 8, p_00+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+12, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+12, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+12, 8, p_00+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+8, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+8, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+8, 8, p_00+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+4, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+4, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+4, 8, p_00+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+0, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+0, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+0, 8, p_00+339+0, 8, temp);
	memset(p_01+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+511+4, 84, q_00+505);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, q_01+505);
	gf2x_add(168, p_01+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+505+80, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+80, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+80, 8, p_01+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+76, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+76, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+76, 8, p_01+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+72, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+72, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+72, 8, p_01+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+68, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+68, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+68, 8, p_01+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+64, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+64, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+64, 8, p_01+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+60, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+60, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+60, 8, p_01+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+56, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+56, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+56, 8, p_01+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+52, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+52, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+52, 8, p_01+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+48, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+48, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+48, 8, p_01+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+44, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+44, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+44, 8, p_01+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+40, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+40, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+40, 8, p_01+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+36, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+36, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+36, 8, p_01+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+32, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+32, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+32, 8, p_01+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+28, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+28, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+28, 8, p_01+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+24, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+24, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+24, 8, p_01+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+20, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+20, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+20, 8, p_01+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+16, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+16, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+16, 8, p_01+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+12, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+12, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+12, 8, p_01+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+8, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+8, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+8, 8, p_01+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+4, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+4, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+4, 8, p_01+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+0, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+0, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+0, 8, p_01+339+0, 8, temp);
	memset(p_10+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, q_10+505);
	GF2X_MUL(168, temp2, 84, p_10+511+4, 84, q_11+505);
	gf2x_add(168, p_10+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+505+80, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+80, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+80, 8, p_10+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+76, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+76, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+76, 8, p_10+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+72, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+72, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+72, 8, p_10+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+68, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+68, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+68, 8, p_10+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+64, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+64, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+64, 8, p_10+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+60, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+60, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+60, 8, p_10+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+56, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+56, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+56, 8, p_10+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+52, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+52, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+52, 8, p_10+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+48, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+48, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+48, 8, p_10+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+44, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+44, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+44, 8, p_10+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+40, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+40, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+40, 8, p_10+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+36, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+36, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+36, 8, p_10+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+32, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+32, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+32, 8, p_10+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+28, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+28, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+28, 8, p_10+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+24, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+24, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+24, 8, p_10+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+20, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+20, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+20, 8, p_10+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+16, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+16, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+16, 8, p_10+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+12, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+12, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+12, 8, p_10+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+8, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+8, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+8, 8, p_10+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+4, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+4, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+4, 8, p_10+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+0, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+0, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+0, 8, p_10+339+0, 8, temp);
	memset(p_11+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+511+4, 84, q_10+505);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, q_11+505);
	gf2x_add(168, p_11+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+505+80, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+80, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+80, 8, p_11+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+76, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+76, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+76, 8, p_11+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+72, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+72, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+72, 8, p_11+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+68, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+68, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+68, 8, p_11+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+64, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+64, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+64, 8, p_11+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+60, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+60, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+60, 8, p_11+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+56, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+56, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+56, 8, p_11+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+52, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+52, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+52, 8, p_11+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+48, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+48, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+48, 8, p_11+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+44, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+44, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+44, 8, p_11+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+40, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+40, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+40, 8, p_11+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+36, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+36, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+36, 8, p_11+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+32, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+32, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+32, 8, p_11+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+28, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+28, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+28, 8, p_11+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+24, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+24, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+24, 8, p_11+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+20, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+20, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+20, 8, p_11+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+16, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+16, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+16, 8, p_11+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+12, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+12, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+12, 8, p_11+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+8, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+8, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+8, 8, p_11+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+4, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+4, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+4, 8, p_11+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+0, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+0, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+0, 8, p_11+339+0, 8, temp);
	

	// Calculating left operands: n: 21675, depth: 1
	// Digits to shift: 171
	// Displacement: 171
	GF2X_MUL(344, temp, 172, f+337+167, 172, p_00+339);
	GF2X_MUL(344, temp2, 172, g+337+167, 172, p_01+339);
	gf2x_add(340, f_sum+1016, 340, temp+4, 340, temp2+4);
	GF2X_MUL(334, temp, 167, p_00+339+5, 167, f+337);
	GF2X_MUL(334, temp2, 167, p_01+339+5, 167, g+337);
	gf2x_add(334, temp, 334, temp, 334, temp2);
	gf2x_add(168, f_sum+1016, 168, f_sum+1016, 168, temp+166);
	GF2X_MUL(10, temp, 5, f+337+162, 5, p_00+339);
	GF2X_MUL(10, temp2, 5, g+337+162, 5, p_01+339);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, f_sum+1016, 1, f_sum+1016, 1, temp+9);
	right_bit_shift_n(339, f_sum+1016, 21);
	GF2X_MUL(344, temp, 172, f+337+167, 172, p_10+339);
	GF2X_MUL(344, temp2, 172, g+337+167, 172, p_11+339);
	gf2x_add(340, g_sum+1016, 340, temp+4, 340, temp2+4);
	GF2X_MUL(334, temp, 167, p_10+339+5, 167, f+337);
	GF2X_MUL(334, temp2, 167, p_11+339+5, 167, g+337);
	gf2x_add(334, temp, 334, temp, 334, temp2);
	gf2x_add(168, g_sum+1016, 168, g_sum+1016, 168, temp+166);
	GF2X_MUL(10, temp, 5, f+337+162, 5, p_10+339);
	GF2X_MUL(10, temp2, 5, g+337+162, 5, p_11+339);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(1, g_sum+1016, 1, g_sum+1016, 1, temp+9);
	right_bit_shift_n(339, g_sum+1016, 21);
	

	delta = divstepsx_256(255, delta, f_sum+1181, g_sum+1181, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1177+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1177+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1177+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1177+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1177+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1177+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1177+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1177+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1173+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1173+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1173);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1173);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1173+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1173+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1173);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1173);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1161+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1161+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1161+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1161+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1161+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1161+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1161+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1161+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1141+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1141+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1141);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1141);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1141+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1141+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1141);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1141);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1101+40, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1101+40, 44, p_01+599);
	gf2x_add(84, f_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, f_sum+1101);
	GF2X_MUL(80, temp2, 40, p_01+599+4, 40, g_sum+1101);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1789, 40, f_sum+1789, 40, temp+40);
	right_bit_shift_n(84, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1101+40, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1101+40, 44, p_11+599);
	gf2x_add(84, g_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+599+4, 40, f_sum+1101);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, g_sum+1101);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1789, 40, g_sum+1789, 40, temp+40);
	right_bit_shift_n(84, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1826, g_sum+1826, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_01+643);
	gf2x_add(40, f_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_01+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(40, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_11+643);
	gf2x_add(40, g_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_11+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(40, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_10+643);
	gf2x_add(40, q_00+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_11+643);
	gf2x_add(40, q_01+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_10+643);
	gf2x_add(40, q_10+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_11+643);
	gf2x_add(40, q_11+589+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_01+589);
	gf2x_add(80, p_00+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+36, 8, p_00+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+32, 8, p_00+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+28, 8, p_00+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+24, 8, p_00+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+20, 8, p_00+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+16, 8, p_00+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+12, 8, p_00+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+8, 8, p_00+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+4, 8, p_00+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+0, 8, p_00+511+0, 8, temp);
	memset(p_01+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_01+589);
	gf2x_add(80, p_01+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+36, 8, p_01+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+32, 8, p_01+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+28, 8, p_01+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+24, 8, p_01+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+20, 8, p_01+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+16, 8, p_01+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+12, 8, p_01+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+8, 8, p_01+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+4, 8, p_01+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+0, 8, p_01+511+0, 8, temp);
	memset(p_10+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_11+589);
	gf2x_add(80, p_10+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+36, 8, p_10+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+32, 8, p_10+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+28, 8, p_10+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+24, 8, p_10+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+20, 8, p_10+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+16, 8, p_10+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+12, 8, p_10+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+8, 8, p_10+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+4, 8, p_10+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+0, 8, p_10+511+0, 8, temp);
	memset(p_11+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_11+589);
	gf2x_add(80, p_11+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+36, 8, p_11+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+32, 8, p_11+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+28, 8, p_11+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+24, 8, p_11+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+20, 8, p_11+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+16, 8, p_11+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+12, 8, p_11+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+8, 8, p_11+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+4, 8, p_11+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+0, 8, p_11+511+0, 8, temp);
	

	// Calculating left operands: n: 10710, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f_sum+1017+84, 84, p_00+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+84, 84, p_01+511);
	gf2x_add(168, f_sum+1528+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, f_sum+1017+0, 84, p_00+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+0, 84, p_01+511);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, f_sum+1528, 84, f_sum+1528, 84, temp+84);
	right_bit_shift_n(168, f_sum+1528, 43);
	GF2X_MUL(168, temp, 84, f_sum+1017+84, 84, p_10+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+84, 84, p_11+511);
	gf2x_add(168, g_sum+1528+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, f_sum+1017+0, 84, p_10+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+0, 84, p_11+511);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, g_sum+1528, 84, g_sum+1528, 84, temp+84);
	right_bit_shift_n(168, g_sum+1528, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1609, g_sum+1609, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_01+599);
	gf2x_add(84, f_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_01+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1789, 40, f_sum+1789, 40, temp+40);
	right_bit_shift_n(84, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_11+599);
	gf2x_add(84, g_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1789, 40, g_sum+1789, 40, temp+40);
	right_bit_shift_n(84, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1826, g_sum+1826, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_01+643);
	gf2x_add(40, f_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_01+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(40, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_11+643);
	gf2x_add(40, g_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_11+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(40, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_10+643);
	gf2x_add(40, q_00+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_11+643);
	gf2x_add(40, q_01+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_10+643);
	gf2x_add(40, q_10+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_11+643);
	gf2x_add(40, q_11+589+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(q_00+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_01+589);
	gf2x_add(80, q_00+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+36, 8, q_00+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+32, 8, q_00+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+28, 8, q_00+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+24, 8, q_00+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+20, 8, q_00+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+16, 8, q_00+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+12, 8, q_00+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+8, 8, q_00+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+4, 8, q_00+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+0, 8, q_00+505+0, 8, temp);
	memset(q_01+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_01+589);
	gf2x_add(80, q_01+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+36, 8, q_01+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+32, 8, q_01+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+28, 8, q_01+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+24, 8, q_01+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+20, 8, q_01+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+16, 8, q_01+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+12, 8, q_01+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+8, 8, q_01+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+4, 8, q_01+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+0, 8, q_01+505+0, 8, temp);
	memset(q_10+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_11+589);
	gf2x_add(80, q_10+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+36, 8, q_10+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+32, 8, q_10+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+28, 8, q_10+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+24, 8, q_10+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+20, 8, q_10+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+16, 8, q_10+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+12, 8, q_10+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+8, 8, q_10+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+4, 8, q_10+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+0, 8, q_10+505+0, 8, temp);
	memset(q_11+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_11+589);
	gf2x_add(80, q_11+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+36, 8, q_11+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+32, 8, q_11+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+28, 8, q_11+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+24, 8, q_11+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+20, 8, q_11+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+16, 8, q_11+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+12, 8, q_11+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+8, 8, q_11+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+4, 8, q_11+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+0, 8, q_11+505+0, 8, temp);
	

	// Recombining results: n: 10710, depth: 2
	GF2X_MUL(168, temp, 84, q_00+505+0, 84, p_00+511);
	GF2X_MUL(168, temp2, 84, q_01+505+0, 84, p_10+511);
	gf2x_add(168, q_00+337+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_00+505+0, 84, p_01+511);
	GF2X_MUL(168, temp2, 84, q_01+505+0, 84, p_11+511);
	gf2x_add(168, q_01+337+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_10+505+0, 84, p_00+511);
	GF2X_MUL(168, temp2, 84, q_11+505+0, 84, p_10+511);
	gf2x_add(168, q_10+337+0, 168, temp, 168, temp2);
	GF2X_MUL(168, temp, 84, q_10+505+0, 84, p_01+511);
	GF2X_MUL(168, temp2, 84, q_11+505+0, 84, p_11+511);
	gf2x_add(168, q_11+337+0, 168, temp, 168, temp2);
	

	// Recombining results: n: 21675, depth: 1
	memset(p_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_00+339+4, 168, q_00+337);
	GF2X_MUL(336, temp2, 168, p_10+339+4, 168, q_01+337);
	gf2x_add(336, p_00+0+3, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_00+337+164, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+164, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+163, 8, p_00+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+160, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+160, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+159, 8, p_00+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+156, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+156, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+155, 8, p_00+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+152, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+152, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+151, 8, p_00+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+148, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+148, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+147, 8, p_00+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+144, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+144, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+143, 8, p_00+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+140, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+140, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+139, 8, p_00+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+136, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+136, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+135, 8, p_00+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+132, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+132, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+131, 8, p_00+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+128, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+128, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+127, 8, p_00+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+124, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+124, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+123, 8, p_00+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+120, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+120, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+119, 8, p_00+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+116, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+116, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+115, 8, p_00+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+112, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+112, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+111, 8, p_00+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+108, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+108, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+107, 8, p_00+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+104, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+104, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+103, 8, p_00+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+100, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+100, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+99, 8, p_00+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+96, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+96, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+95, 8, p_00+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+92, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+92, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+91, 8, p_00+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+88, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+88, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+87, 8, p_00+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+84, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+84, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+83, 8, p_00+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+80, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+80, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+79, 8, p_00+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+76, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+76, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+75, 8, p_00+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+72, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+72, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+71, 8, p_00+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+68, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+68, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+67, 8, p_00+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+64, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+64, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+63, 8, p_00+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+60, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+60, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+59, 8, p_00+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+56, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+56, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+55, 8, p_00+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+52, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+52, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+51, 8, p_00+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+48, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+48, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+47, 8, p_00+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+44, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+44, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+43, 8, p_00+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+40, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+40, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+39, 8, p_00+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+36, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+36, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+35, 8, p_00+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+32, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+32, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+31, 8, p_00+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+28, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+28, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+27, 8, p_00+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+24, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+24, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+23, 8, p_00+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+20, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+20, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+19, 8, p_00+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+16, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+16, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+15, 8, p_00+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+12, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+12, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+11, 8, p_00+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+8, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+8, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+7, 8, p_00+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+4, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+4, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+0+3, 8, p_00+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+0, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_01+337+0, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_00+0, 7, p_00+0, 7, temp+1);
	memset(p_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_01+339+4, 168, q_00+337);
	GF2X_MUL(336, temp2, 168, p_11+339+4, 168, q_01+337);
	gf2x_add(336, p_01+0+3, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_00+337+164, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+164, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+163, 8, p_01+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+160, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+160, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+159, 8, p_01+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+156, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+156, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+155, 8, p_01+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+152, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+152, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+151, 8, p_01+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+148, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+148, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+147, 8, p_01+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+144, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+144, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+143, 8, p_01+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+140, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+140, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+139, 8, p_01+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+136, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+136, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+135, 8, p_01+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+132, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+132, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+131, 8, p_01+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+128, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+128, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+127, 8, p_01+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+124, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+124, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+123, 8, p_01+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+120, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+120, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+119, 8, p_01+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+116, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+116, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+115, 8, p_01+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+112, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+112, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+111, 8, p_01+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+108, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+108, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+107, 8, p_01+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+104, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+104, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+103, 8, p_01+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+100, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+100, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+99, 8, p_01+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+96, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+96, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+95, 8, p_01+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+92, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+92, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+91, 8, p_01+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+88, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+88, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+87, 8, p_01+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+84, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+84, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+83, 8, p_01+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+80, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+80, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+79, 8, p_01+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+76, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+76, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+75, 8, p_01+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+72, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+72, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+71, 8, p_01+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+68, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+68, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+67, 8, p_01+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+64, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+64, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+63, 8, p_01+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+60, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+60, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+59, 8, p_01+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+56, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+56, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+55, 8, p_01+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+52, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+52, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+51, 8, p_01+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+48, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+48, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+47, 8, p_01+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+44, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+44, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+43, 8, p_01+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+40, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+40, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+39, 8, p_01+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+36, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+36, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+35, 8, p_01+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+32, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+32, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+31, 8, p_01+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+28, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+28, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+27, 8, p_01+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+24, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+24, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+23, 8, p_01+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+20, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+20, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+19, 8, p_01+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+16, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+16, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+15, 8, p_01+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+12, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+12, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+11, 8, p_01+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+8, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+8, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+7, 8, p_01+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+4, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+4, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+0+3, 8, p_01+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+337+0, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_01+337+0, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_01+0, 7, p_01+0, 7, temp+1);
	memset(p_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_00+339+4, 168, q_10+337);
	GF2X_MUL(336, temp2, 168, p_10+339+4, 168, q_11+337);
	gf2x_add(336, p_10+0+3, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_10+337+164, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+164, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+163, 8, p_10+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+160, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+160, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+159, 8, p_10+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+156, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+156, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+155, 8, p_10+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+152, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+152, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+151, 8, p_10+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+148, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+148, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+147, 8, p_10+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+144, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+144, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+143, 8, p_10+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+140, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+140, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+139, 8, p_10+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+136, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+136, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+135, 8, p_10+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+132, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+132, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+131, 8, p_10+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+128, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+128, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+127, 8, p_10+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+124, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+124, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+123, 8, p_10+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+120, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+120, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+119, 8, p_10+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+116, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+116, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+115, 8, p_10+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+112, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+112, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+111, 8, p_10+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+108, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+108, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+107, 8, p_10+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+104, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+104, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+103, 8, p_10+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+100, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+100, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+99, 8, p_10+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+96, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+96, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+95, 8, p_10+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+92, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+92, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+91, 8, p_10+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+88, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+88, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+87, 8, p_10+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+84, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+84, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+83, 8, p_10+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+80, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+80, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+79, 8, p_10+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+76, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+76, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+75, 8, p_10+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+72, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+72, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+71, 8, p_10+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+68, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+68, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+67, 8, p_10+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+64, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+64, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+63, 8, p_10+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+60, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+60, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+59, 8, p_10+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+56, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+56, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+55, 8, p_10+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+52, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+52, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+51, 8, p_10+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+48, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+48, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+47, 8, p_10+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+44, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+44, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+43, 8, p_10+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+40, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+40, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+39, 8, p_10+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+36, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+36, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+35, 8, p_10+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+32, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+32, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+31, 8, p_10+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+28, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+28, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+27, 8, p_10+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+24, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+24, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+23, 8, p_10+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+20, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+20, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+19, 8, p_10+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+16, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+16, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+15, 8, p_10+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+12, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+12, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+11, 8, p_10+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+8, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+8, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+7, 8, p_10+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+4, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+4, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+0+3, 8, p_10+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+0, 4, p_00+339);
	GF2X_MUL(8, temp2, 4, q_11+337+0, 4, p_10+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_10+0, 7, p_10+0, 7, temp+1);
	memset(p_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(336, temp, 168, p_01+339+4, 168, q_10+337);
	GF2X_MUL(336, temp2, 168, p_11+339+4, 168, q_11+337);
	gf2x_add(336, p_11+0+3, 336, temp, 336, temp2);
	GF2X_MUL(8, temp, 4, q_10+337+164, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+164, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+163, 8, p_11+0+163, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+160, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+160, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+159, 8, p_11+0+159, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+156, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+156, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+155, 8, p_11+0+155, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+152, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+152, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+151, 8, p_11+0+151, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+148, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+148, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+147, 8, p_11+0+147, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+144, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+144, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+143, 8, p_11+0+143, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+140, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+140, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+139, 8, p_11+0+139, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+136, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+136, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+135, 8, p_11+0+135, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+132, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+132, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+131, 8, p_11+0+131, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+128, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+128, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+127, 8, p_11+0+127, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+124, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+124, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+123, 8, p_11+0+123, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+120, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+120, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+119, 8, p_11+0+119, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+116, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+116, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+115, 8, p_11+0+115, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+112, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+112, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+111, 8, p_11+0+111, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+108, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+108, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+107, 8, p_11+0+107, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+104, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+104, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+103, 8, p_11+0+103, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+100, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+100, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+99, 8, p_11+0+99, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+96, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+96, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+95, 8, p_11+0+95, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+92, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+92, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+91, 8, p_11+0+91, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+88, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+88, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+87, 8, p_11+0+87, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+84, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+84, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+83, 8, p_11+0+83, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+80, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+80, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+79, 8, p_11+0+79, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+76, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+76, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+75, 8, p_11+0+75, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+72, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+72, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+71, 8, p_11+0+71, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+68, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+68, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+67, 8, p_11+0+67, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+64, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+64, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+63, 8, p_11+0+63, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+60, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+60, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+59, 8, p_11+0+59, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+56, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+56, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+55, 8, p_11+0+55, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+52, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+52, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+51, 8, p_11+0+51, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+48, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+48, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+47, 8, p_11+0+47, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+44, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+44, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+43, 8, p_11+0+43, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+40, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+40, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+39, 8, p_11+0+39, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+36, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+36, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+35, 8, p_11+0+35, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+32, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+32, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+31, 8, p_11+0+31, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+28, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+28, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+27, 8, p_11+0+27, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+24, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+24, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+23, 8, p_11+0+23, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+20, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+20, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+19, 8, p_11+0+19, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+16, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+16, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+15, 8, p_11+0+15, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+12, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+12, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+11, 8, p_11+0+11, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+8, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+8, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+7, 8, p_11+0+7, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+4, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+4, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+0+3, 8, p_11+0+3, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+337+0, 4, p_01+339);
	GF2X_MUL(8, temp2, 4, q_11+337+0, 4, p_11+339);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(7, p_11+0, 7, p_11+0, 7, temp+1);
	

	// Calculating left operands: n: 43221, depth: 0
	// Digits to shift: 338
	// Displacement: 339
	GF2X_MUL(678, temp, 339, f+0+337, 339, p_00+0);
	GF2X_MUL(678, temp2, 339, g+0+337, 339, p_01+0);
	gf2x_add(676, f_sum+0, 676, temp+2, 676, temp2+2);
	GF2X_MUL(674, temp, 337, p_00+0+2, 337, f+0);
	GF2X_MUL(674, temp2, 337, p_01+0+2, 337, g+0);
	gf2x_add(674, temp, 674, temp, 674, temp2);
	gf2x_add(337, f_sum+0, 337, f_sum+0, 337, temp+337);
	right_bit_shift_n(676, f_sum+0, 43);
	GF2X_MUL(678, temp, 339, f+0+337, 339, p_10+0);
	GF2X_MUL(678, temp2, 339, g+0+337, 339, p_11+0);
	gf2x_add(676, g_sum+0, 676, temp+2, 676, temp2+2);
	GF2X_MUL(674, temp, 337, p_10+0+2, 337, f+0);
	GF2X_MUL(674, temp2, 337, p_11+0+2, 337, g+0);
	gf2x_add(674, temp, 674, temp, 674, temp2);
	gf2x_add(337, g_sum+0, 337, g_sum+0, 337, temp+337);
	right_bit_shift_n(676, g_sum+0, 43);
	

	delta = divstepsx_256(255, delta, f_sum+334, g_sum+334, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+330+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+330+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+330+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+330+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+330+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+330+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+330+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+330+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+326+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+326+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+326);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+326);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+326+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+326+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+326);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+326);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+314+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+314+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+314+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+314+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+314+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+314+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+314+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+314+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+294+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+294+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+294);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+294);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+294+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+294+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+294);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+294);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5610, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+250+44, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+250+44, 44, p_01+599);
	gf2x_add(88, f_sum+1789+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f_sum+250+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+250+0, 44, p_01+599);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, f_sum+1789, 44, f_sum+1789, 44, temp+44);
	right_bit_shift_n(88, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+250+44, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+250+44, 44, p_11+599);
	gf2x_add(88, g_sum+1789+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, f_sum+250+0, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+250+0, 44, p_11+599);
	gf2x_add(88, temp, 88, temp, 88, temp2);
	gf2x_add(44, g_sum+1789, 44, g_sum+1789, 44, temp+44);
	right_bit_shift_n(88, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1830, g_sum+1830, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1826+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1826+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1826+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1826+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1826+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1822+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1822+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1822);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1822);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1822+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1822+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1822);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1822);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1810+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1810+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1790+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1790+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1790);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1790);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1790+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1790+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1790);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1790);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(q_00+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, q_00+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+16, 8, q_00+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+12, 8, q_00+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+8, 8, q_00+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+4, 8, q_00+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+589+0, 8, q_00+589+0, 8, temp);
	memset(q_01+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, q_01+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+16, 8, q_01+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+12, 8, q_01+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+8, 8, q_01+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+4, 8, q_01+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+589+0, 8, q_01+589+0, 8, temp);
	memset(q_10+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, q_10+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+16, 8, q_10+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+12, 8, q_10+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+8, 8, q_10+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+4, 8, q_10+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+589+0, 8, q_10+589+0, 8, temp);
	memset(q_11+589, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, q_11+589+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+16, 8, q_11+589+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+12, 8, q_11+589+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+8, 8, q_11+589+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+4, 8, q_11+589+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+589+0, 8, q_11+589+0, 8, temp);
	

	// Recombining results: n: 5610, depth: 3
	GF2X_MUL(88, temp, 44, q_00+589+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, q_01+589+0, 44, p_10+599);
	gf2x_add(88, p_00+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_00+589+0, 44, p_01+599);
	GF2X_MUL(88, temp2, 44, q_01+589+0, 44, p_11+599);
	gf2x_add(88, p_01+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+589+0, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, q_11+589+0, 44, p_10+599);
	gf2x_add(88, p_10+511+0, 88, temp, 88, temp2);
	GF2X_MUL(88, temp, 44, q_10+589+0, 44, p_01+599);
	GF2X_MUL(88, temp2, 44, q_11+589+0, 44, p_11+599);
	gf2x_add(88, p_11+511+0, 88, temp, 88, temp2);
	

	// Calculating left operands: n: 10965, depth: 2
	// Digits to shift: 87
	// Displacement: 88
	GF2X_MUL(176, temp, 88, f_sum+166+84, 88, p_00+511);
	GF2X_MUL(176, temp2, 88, g_sum+166+84, 88, p_01+511);
	gf2x_add(172, f_sum+1528, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, f_sum+166);
	GF2X_MUL(168, temp2, 84, p_01+511+4, 84, g_sum+166);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, f_sum+1528, 84, f_sum+1528, 84, temp+84);
	right_bit_shift_n(172, f_sum+1528, 42);
	GF2X_MUL(176, temp, 88, f_sum+166+84, 88, p_10+511);
	GF2X_MUL(176, temp2, 88, g_sum+166+84, 88, p_11+511);
	gf2x_add(172, g_sum+1528, 172, temp+4, 172, temp2+4);
	GF2X_MUL(168, temp, 84, p_10+511+4, 84, f_sum+166);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, g_sum+166);
	gf2x_add(168, temp, 168, temp, 168, temp2);
	gf2x_add(84, g_sum+1528, 84, g_sum+1528, 84, temp+84);
	right_bit_shift_n(172, g_sum+1528, 42);
	

	delta = divstepsx_256(255, delta, f_sum+1609, g_sum+1609, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1605+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1605+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1605+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1601+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1601+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1601);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1601);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1589+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1589+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1589+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1569+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1569+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1569);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1569);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_01+599);
	gf2x_add(84, f_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_01+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1789, 40, f_sum+1789, 40, temp+40);
	right_bit_shift_n(84, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1529+40, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+40, 44, p_11+599);
	gf2x_add(84, g_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+599+4, 40, f_sum+1529);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, g_sum+1529);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1789, 40, g_sum+1789, 40, temp+40);
	right_bit_shift_n(84, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1826, g_sum+1826, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_01+643);
	gf2x_add(40, f_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_01+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(40, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_11+643);
	gf2x_add(40, g_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_11+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(40, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_10+643);
	gf2x_add(40, q_00+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_11+643);
	gf2x_add(40, q_01+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_10+643);
	gf2x_add(40, q_10+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_11+643);
	gf2x_add(40, q_11+589+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(q_00+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_01+589);
	gf2x_add(80, q_00+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+36, 8, q_00+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+32, 8, q_00+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+28, 8, q_00+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+24, 8, q_00+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+20, 8, q_00+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+16, 8, q_00+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+12, 8, q_00+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+8, 8, q_00+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+4, 8, q_00+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+505+0, 8, q_00+505+0, 8, temp);
	memset(q_01+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_01+589);
	gf2x_add(80, q_01+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+36, 8, q_01+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+32, 8, q_01+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+28, 8, q_01+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+24, 8, q_01+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+20, 8, q_01+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+16, 8, q_01+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+12, 8, q_01+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+8, 8, q_01+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+4, 8, q_01+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+505+0, 8, q_01+505+0, 8, temp);
	memset(q_10+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_11+589);
	gf2x_add(80, q_10+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+36, 8, q_10+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+32, 8, q_10+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+28, 8, q_10+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+24, 8, q_10+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+20, 8, q_10+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+16, 8, q_10+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+12, 8, q_10+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+8, 8, q_10+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+4, 8, q_10+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+505+0, 8, q_10+505+0, 8, temp);
	memset(q_11+505, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_11+589);
	gf2x_add(80, q_11+505+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+36, 8, q_11+505+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+32, 8, q_11+505+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+28, 8, q_11+505+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+24, 8, q_11+505+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+20, 8, q_11+505+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+16, 8, q_11+505+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+12, 8, q_11+505+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+8, 8, q_11+505+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+4, 8, q_11+505+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+505+0, 8, q_11+505+0, 8, temp);
	

	// Recombining results: n: 10965, depth: 2
	memset(p_00+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, q_00+505);
	GF2X_MUL(168, temp2, 84, p_10+511+4, 84, q_01+505);
	gf2x_add(168, p_00+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+505+80, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+80, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+80, 8, p_00+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+76, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+76, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+76, 8, p_00+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+72, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+72, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+72, 8, p_00+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+68, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+68, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+68, 8, p_00+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+64, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+64, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+64, 8, p_00+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+60, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+60, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+60, 8, p_00+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+56, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+56, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+56, 8, p_00+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+52, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+52, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+52, 8, p_00+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+48, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+48, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+48, 8, p_00+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+44, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+44, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+44, 8, p_00+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+40, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+40, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+40, 8, p_00+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+36, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+36, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+36, 8, p_00+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+32, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+32, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+32, 8, p_00+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+28, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+28, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+28, 8, p_00+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+24, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+24, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+24, 8, p_00+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+20, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+20, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+20, 8, p_00+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+16, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+16, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+16, 8, p_00+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+12, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+12, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+12, 8, p_00+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+8, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+8, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+8, 8, p_00+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+4, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+4, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+4, 8, p_00+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+0, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_01+505+0, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+339+0, 8, p_00+339+0, 8, temp);
	memset(p_01+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+511+4, 84, q_00+505);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, q_01+505);
	gf2x_add(168, p_01+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_00+505+80, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+80, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+80, 8, p_01+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+76, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+76, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+76, 8, p_01+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+72, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+72, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+72, 8, p_01+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+68, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+68, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+68, 8, p_01+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+64, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+64, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+64, 8, p_01+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+60, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+60, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+60, 8, p_01+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+56, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+56, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+56, 8, p_01+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+52, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+52, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+52, 8, p_01+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+48, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+48, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+48, 8, p_01+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+44, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+44, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+44, 8, p_01+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+40, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+40, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+40, 8, p_01+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+36, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+36, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+36, 8, p_01+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+32, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+32, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+32, 8, p_01+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+28, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+28, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+28, 8, p_01+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+24, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+24, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+24, 8, p_01+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+20, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+20, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+20, 8, p_01+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+16, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+16, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+16, 8, p_01+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+12, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+12, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+12, 8, p_01+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+8, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+8, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+8, 8, p_01+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+4, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+4, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+4, 8, p_01+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+505+0, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_01+505+0, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+339+0, 8, p_01+339+0, 8, temp);
	memset(p_10+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_00+511+4, 84, q_10+505);
	GF2X_MUL(168, temp2, 84, p_10+511+4, 84, q_11+505);
	gf2x_add(168, p_10+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+505+80, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+80, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+80, 8, p_10+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+76, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+76, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+76, 8, p_10+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+72, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+72, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+72, 8, p_10+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+68, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+68, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+68, 8, p_10+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+64, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+64, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+64, 8, p_10+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+60, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+60, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+60, 8, p_10+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+56, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+56, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+56, 8, p_10+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+52, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+52, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+52, 8, p_10+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+48, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+48, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+48, 8, p_10+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+44, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+44, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+44, 8, p_10+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+40, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+40, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+40, 8, p_10+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+36, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+36, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+36, 8, p_10+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+32, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+32, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+32, 8, p_10+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+28, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+28, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+28, 8, p_10+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+24, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+24, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+24, 8, p_10+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+20, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+20, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+20, 8, p_10+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+16, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+16, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+16, 8, p_10+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+12, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+12, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+12, 8, p_10+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+8, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+8, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+8, 8, p_10+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+4, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+4, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+4, 8, p_10+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+0, 4, p_00+511);
	GF2X_MUL(8, temp2, 4, q_11+505+0, 4, p_10+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+339+0, 8, p_10+339+0, 8, temp);
	memset(p_11+339, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(168, temp, 84, p_01+511+4, 84, q_10+505);
	GF2X_MUL(168, temp2, 84, p_11+511+4, 84, q_11+505);
	gf2x_add(168, p_11+339+4, 168, temp, 168, temp2);
	GF2X_MUL(8, temp, 4, q_10+505+80, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+80, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+80, 8, p_11+339+80, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+76, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+76, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+76, 8, p_11+339+76, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+72, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+72, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+72, 8, p_11+339+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+68, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+68, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+68, 8, p_11+339+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+64, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+64, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+64, 8, p_11+339+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+60, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+60, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+60, 8, p_11+339+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+56, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+56, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+56, 8, p_11+339+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+52, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+52, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+52, 8, p_11+339+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+48, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+48, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+48, 8, p_11+339+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+44, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+44, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+44, 8, p_11+339+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+40, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+40, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+40, 8, p_11+339+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+36, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+36, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+36, 8, p_11+339+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+32, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+32, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+32, 8, p_11+339+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+28, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+28, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+28, 8, p_11+339+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+24, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+24, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+24, 8, p_11+339+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+20, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+20, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+20, 8, p_11+339+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+16, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+16, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+16, 8, p_11+339+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+12, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+12, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+12, 8, p_11+339+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+8, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+8, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+8, 8, p_11+339+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+4, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+4, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+4, 8, p_11+339+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+505+0, 4, p_01+511);
	GF2X_MUL(8, temp2, 4, q_11+505+0, 4, p_11+511);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+339+0, 8, p_11+339+0, 8, temp);
	

	// Calculating left operands: n: 21546, depth: 1
	// Digits to shift: 171
	// Displacement: 171
	GF2X_MUL(344, temp, 172, f_sum+1+165, 172, p_00+339);
	GF2X_MUL(344, temp2, 172, g_sum+1+165, 172, p_01+339);
	gf2x_add(338, f_sum+1016, 338, temp+6, 338, temp2+6);
	GF2X_MUL(330, temp, 165, p_00+339+7, 165, f_sum+1);
	GF2X_MUL(330, temp2, 165, p_01+339+7, 165, g_sum+1);
	gf2x_add(330, temp, 330, temp, 330, temp2);
	gf2x_add(166, f_sum+1016, 166, f_sum+1016, 166, temp+164);
	GF2X_MUL(14, temp, 7, f_sum+1+158, 7, p_00+339);
	GF2X_MUL(14, temp2, 7, g_sum+1+158, 7, p_01+339);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, f_sum+1016, 1, f_sum+1016, 1, temp+13);
	right_bit_shift_n(337, f_sum+1016, 21);
	GF2X_MUL(344, temp, 172, f_sum+1+165, 172, p_10+339);
	GF2X_MUL(344, temp2, 172, g_sum+1+165, 172, p_11+339);
	gf2x_add(338, g_sum+1016, 338, temp+6, 338, temp2+6);
	GF2X_MUL(330, temp, 165, p_10+339+7, 165, f_sum+1);
	GF2X_MUL(330, temp2, 165, p_11+339+7, 165, g_sum+1);
	gf2x_add(330, temp, 330, temp, 330, temp2);
	gf2x_add(166, g_sum+1016, 166, g_sum+1016, 166, temp+164);
	GF2X_MUL(14, temp, 7, f_sum+1+158, 7, p_10+339);
	GF2X_MUL(14, temp2, 7, g_sum+1+158, 7, p_11+339);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(1, g_sum+1016, 1, g_sum+1016, 1, temp+13);
	right_bit_shift_n(337, g_sum+1016, 21);
	

	delta = divstepsx_256(255, delta, f_sum+1179, g_sum+1179, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1175+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1175+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1175+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1175+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1171+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1171+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1171);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1171);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1159+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1159+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1159+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1159+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1159+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1159+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1159+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1159+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1139+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1139+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1139);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1139);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1139+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1139+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1139);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1139);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5355, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1099+40, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1099+40, 44, p_01+599);
	gf2x_add(84, f_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, f_sum+1099);
	GF2X_MUL(80, temp2, 40, p_01+599+4, 40, g_sum+1099);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1789, 40, f_sum+1789, 40, temp+40);
	right_bit_shift_n(84, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1099+40, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1099+40, 44, p_11+599);
	gf2x_add(84, g_sum+1789, 84, temp+4, 84, temp2+4);
	GF2X_MUL(80, temp, 40, p_10+599+4, 40, f_sum+1099);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, g_sum+1099);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1789, 40, g_sum+1789, 40, temp+40);
	right_bit_shift_n(84, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1826, g_sum+1826, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1822+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1822+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1822+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1818+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1818+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1818);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1818);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1810+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1810+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1810);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1810);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_01+643);
	gf2x_add(40, f_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_01+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(40, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+20, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+20, 20, p_11+643);
	gf2x_add(40, g_sum+1922+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1790+0, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+0, 20, p_11+643);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(40, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_10+643);
	gf2x_add(40, q_00+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_01+633+0, 20, p_11+643);
	gf2x_add(40, q_01+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_10+643);
	gf2x_add(40, q_10+589+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+633+0, 20, p_01+643);
	GF2X_MUL(40, temp2, 20, q_11+633+0, 20, p_11+643);
	gf2x_add(40, q_11+589+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5355, depth: 3
	memset(p_00+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_01+589);
	gf2x_add(80, p_00+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+36, 8, p_00+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+32, 8, p_00+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+28, 8, p_00+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+24, 8, p_00+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+20, 8, p_00+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+16, 8, p_00+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+12, 8, p_00+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+8, 8, p_00+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+4, 8, p_00+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+511+0, 8, p_00+511+0, 8, temp);
	memset(p_01+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_00+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_01+589);
	gf2x_add(80, p_01+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_00+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+36, 8, p_01+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+32, 8, p_01+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+28, 8, p_01+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+24, 8, p_01+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+20, 8, p_01+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+16, 8, p_01+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+12, 8, p_01+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+8, 8, p_01+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+4, 8, p_01+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_01+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+511+0, 8, p_01+511+0, 8, temp);
	memset(p_10+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_00+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_10+599+4, 40, q_11+589);
	gf2x_add(80, p_10+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+36, 8, p_10+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+32, 8, p_10+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+28, 8, p_10+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+24, 8, p_10+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+20, 8, p_10+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+16, 8, p_10+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+12, 8, p_10+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+8, 8, p_10+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+4, 8, p_10+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_00+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_10+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+511+0, 8, p_10+511+0, 8, temp);
	memset(p_11+511, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(80, temp, 40, p_01+599+4, 40, q_10+589);
	GF2X_MUL(80, temp2, 40, p_11+599+4, 40, q_11+589);
	gf2x_add(80, p_11+511+4, 80, temp, 80, temp2);
	GF2X_MUL(8, temp, 4, q_10+589+36, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+36, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+36, 8, p_11+511+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+32, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+32, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+32, 8, p_11+511+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+28, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+28, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+28, 8, p_11+511+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+24, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+24, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+24, 8, p_11+511+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+20, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+20, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+20, 8, p_11+511+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+16, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+16, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+16, 8, p_11+511+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+12, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+12, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+12, 8, p_11+511+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+8, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+8, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+8, 8, p_11+511+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+4, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+4, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+4, 8, p_11+511+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+589+0, 4, p_01+599);
	GF2X_MUL(8, temp2, 4, q_11+589+0, 4, p_11+599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+511+0, 8, p_11+511+0, 8, temp);
	

	// Calculating left operands: n: 10581, depth: 2
	// Digits to shift: 83
	// Displacement: 84
	GF2X_MUL(168, temp, 84, f_sum+1017+82, 84, p_00+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+82, 84, p_01+511);
	gf2x_add(166, f_sum+1528, 166, temp+2, 166, temp2+2);
	GF2X_MUL(164, temp, 82, p_00+511+2, 82, f_sum+1017);
	GF2X_MUL(164, temp2, 82, p_01+511+2, 82, g_sum+1017);
	gf2x_add(164, temp, 164, temp, 164, temp2);
	gf2x_add(82, f_sum+1528, 82, f_sum+1528, 82, temp+82);
	right_bit_shift_n(166, f_sum+1528, 43);
	GF2X_MUL(168, temp, 84, f_sum+1017+82, 84, p_10+511);
	GF2X_MUL(168, temp2, 84, g_sum+1017+82, 84, p_11+511);
	gf2x_add(166, g_sum+1528, 166, temp+2, 166, temp2+2);
	GF2X_MUL(164, temp, 82, p_10+511+2, 82, f_sum+1017);
	GF2X_MUL(164, temp2, 82, p_11+511+2, 82, g_sum+1017);
	gf2x_add(164, temp, 164, temp, 164, temp2);
	gf2x_add(82, g_sum+1528, 82, g_sum+1528, 82, temp+82);
	right_bit_shift_n(166, g_sum+1528, 43);
	

	delta = divstepsx_256(255, delta, f_sum+1607, g_sum+1607, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1603+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1603+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1603+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1603+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1603+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1603+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1603+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1603+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1599+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1599+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1599);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1599+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1599+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1599);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1599);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1530, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1587+12, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1587+12, 12, p_01+667);
	gf2x_add(24, f_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1587+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1587+0, 12, p_01+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, f_sum+1991, 12, f_sum+1991, 12, temp+12);
	right_bit_shift_n(24, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1587+12, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1587+12, 12, p_11+667);
	gf2x_add(24, g_sum+1991+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, f_sum+1587+0, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1587+0, 12, p_11+667);
	gf2x_add(24, temp, 24, temp, 24, temp2);
	gf2x_add(12, g_sum+1991, 12, g_sum+1991, 12, temp+12);
	right_bit_shift_n(24, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+2000, g_sum+2000, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1996+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1996+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1996+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1992+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1992+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1992);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1992);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(q_00+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, q_00+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+653+0, 8, q_00+653+0, 8, temp);
	memset(q_01+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, q_01+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+653+0, 8, q_01+653+0, 8, temp);
	memset(q_10+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, q_10+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+653+0, 8, q_10+653+0, 8, temp);
	memset(q_11+653, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, q_11+653+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+653+0, 8, q_11+653+0, 8, temp);
	

	// Recombining results: n: 1530, depth: 5
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_10+667);
	gf2x_add(24, p_00+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_00+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_01+653+0, 12, p_11+667);
	gf2x_add(24, p_01+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_10+667);
	gf2x_add(24, p_10+643+0, 24, temp, 24, temp2);
	GF2X_MUL(24, temp, 12, q_10+653+0, 12, p_01+667);
	GF2X_MUL(24, temp2, 12, q_11+653+0, 12, p_11+667);
	gf2x_add(24, p_11+643+0, 24, temp, 24, temp2);
	

	// Calculating left operands: n: 2805, depth: 4
	// Digits to shift: 23
	// Displacement: 24
	GF2X_MUL(48, temp, 24, f_sum+1567+20, 24, p_00+643);
	GF2X_MUL(48, temp2, 24, g_sum+1567+20, 24, p_01+643);
	gf2x_add(44, f_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, f_sum+1567);
	GF2X_MUL(40, temp2, 20, p_01+643+4, 20, g_sum+1567);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1922, 20, f_sum+1922, 20, temp+20);
	right_bit_shift_n(44, f_sum+1922, 58);
	GF2X_MUL(48, temp, 24, f_sum+1567+20, 24, p_10+643);
	GF2X_MUL(48, temp2, 24, g_sum+1567+20, 24, p_11+643);
	gf2x_add(44, g_sum+1922, 44, temp+4, 44, temp2+4);
	GF2X_MUL(40, temp, 20, p_10+643+4, 20, f_sum+1567);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, g_sum+1567);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1922, 20, g_sum+1922, 20, temp+20);
	right_bit_shift_n(44, g_sum+1922, 58);
	

	delta = divstepsx_256(255, delta, f_sum+1939, g_sum+1939, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1935+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1935+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1935+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1931+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1931+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1931);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1931);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1923);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1923);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, q_00+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+4, 8, q_00+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+633+0, 8, q_00+633+0, 8, temp);
	memset(q_01+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, q_01+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+4, 8, q_01+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+633+0, 8, q_01+633+0, 8, temp);
	memset(q_10+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, q_10+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+4, 8, q_10+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+633+0, 8, q_10+633+0, 8, temp);
	memset(q_11+633, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, q_11+633+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+4, 8, q_11+633+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+633+0, 8, q_11+633+0, 8, temp);
	

	// Recombining results: n: 2805, depth: 4
	memset(p_00+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_01+633);
	gf2x_add(40, p_00+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+16, 8, p_00+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+12, 8, p_00+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+8, 8, p_00+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+4, 8, p_00+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+599+0, 8, p_00+599+0, 8, temp);
	memset(p_01+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_00+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_01+633);
	gf2x_add(40, p_01+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_00+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+16, 8, p_01+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+12, 8, p_01+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+8, 8, p_01+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+4, 8, p_01+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_01+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+599+0, 8, p_01+599+0, 8, temp);
	memset(p_10+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_00+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_10+643+4, 20, q_11+633);
	gf2x_add(40, p_10+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+16, 8, p_10+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+12, 8, p_10+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+8, 8, p_10+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+4, 8, p_10+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_00+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_10+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+599+0, 8, p_10+599+0, 8, temp);
	memset(p_11+599, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(40, temp, 20, p_01+643+4, 20, q_10+633);
	GF2X_MUL(40, temp2, 20, p_11+643+4, 20, q_11+633);
	gf2x_add(40, p_11+599+4, 40, temp, 40, temp2);
	GF2X_MUL(8, temp, 4, q_10+633+16, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+16, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+16, 8, p_11+599+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+12, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+12, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+12, 8, p_11+599+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+8, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+8, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+8, 8, p_11+599+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+4, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+4, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+4, 8, p_11+599+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+633+0, 4, p_01+643);
	GF2X_MUL(8, temp2, 4, q_11+633+0, 4, p_11+643);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+599+0, 8, p_11+599+0, 8, temp);
	

	// Calculating left operands: n: 5226, depth: 3
	// Digits to shift: 43
	// Displacement: 44
	GF2X_MUL(88, temp, 44, f_sum+1529+38, 44, p_00+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+38, 44, p_01+599);
	gf2x_add(82, f_sum+1789, 82, temp+6, 82, temp2+6);
	GF2X_MUL(76, temp, 38, p_00+599+6, 38, f_sum+1529);
	GF2X_MUL(76, temp2, 38, p_01+599+6, 38, g_sum+1529);
	gf2x_add(76, temp, 76, temp, 76, temp2);
	gf2x_add(38, f_sum+1789, 38, f_sum+1789, 38, temp+38);
	right_bit_shift_n(82, f_sum+1789, 53);
	GF2X_MUL(88, temp, 44, f_sum+1529+38, 44, p_10+599);
	GF2X_MUL(88, temp2, 44, g_sum+1529+38, 44, p_11+599);
	gf2x_add(82, g_sum+1789, 82, temp+6, 82, temp2+6);
	GF2X_MUL(76, temp, 38, p_10+599+6, 38, f_sum+1529);
	GF2X_MUL(76, temp2, 38, p_11+599+6, 38, g_sum+1529);
	gf2x_add(76, temp, 76, temp, 76, temp2);
	gf2x_add(38, g_sum+1789, 38, g_sum+1789, 38, temp+38);
	right_bit_shift_n(82, g_sum+1789, 53);
	

	delta = divstepsx_256(255, delta, f_sum+1824, g_sum+1824, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1820+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1820+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1820+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1820+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1820+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1820+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1820+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1820+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1816+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1816+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1816);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1816);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1816+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1816+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1816);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1816);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1808+8, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1808+8, 12, p_01+667);
	gf2x_add(20, f_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, f_sum+1808);
	GF2X_MUL(16, temp2, 8, p_01+667+4, 8, g_sum+1808);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1991, 8, f_sum+1991, 8, temp+8);
	right_bit_shift_n(20, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1808+8, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1808+8, 12, p_11+667);
	gf2x_add(20, g_sum+1991, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+667+4, 8, f_sum+1808);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, g_sum+1808);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1991, 8, g_sum+1991, 8, temp+8);
	right_bit_shift_n(20, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1996, g_sum+1996, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_01+679);
	gf2x_add(8, f_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_01+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(8, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+4, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+4, 4, p_11+679);
	gf2x_add(8, g_sum+2028+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1992+0, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(8, g_sum+2028, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, q_00+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, q_01+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, q_10+653+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, q_11+653+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_01+653);
	gf2x_add(16, p_00+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+4, 8, p_00+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+643+0, 8, p_00+643+0, 8, temp);
	memset(p_01+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_00+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_01+653);
	gf2x_add(16, p_01+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+4, 8, p_01+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_01+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+643+0, 8, p_01+643+0, 8, temp);
	memset(p_10+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_10+667+4, 8, q_11+653);
	gf2x_add(16, p_10+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+4, 8, p_10+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_00+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_10+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+643+0, 8, p_10+643+0, 8, temp);
	memset(p_11+643, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+667+4, 8, q_10+653);
	GF2X_MUL(16, temp2, 8, p_11+667+4, 8, q_11+653);
	gf2x_add(16, p_11+643+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+653+4, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+4, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+4, 8, p_11+643+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+653+0, 4, p_01+667);
	GF2X_MUL(8, temp2, 4, q_11+653+0, 4, p_11+667);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+643+0, 8, p_11+643+0, 8, temp);
	

	// Calculating left operands: n: 2421, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1790+18, 20, p_00+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+18, 20, p_01+643);
	gf2x_add(38, f_sum+1922, 38, temp+2, 38, temp2+2);
	GF2X_MUL(36, temp, 18, p_00+643+2, 18, f_sum+1790);
	GF2X_MUL(36, temp2, 18, p_01+643+2, 18, g_sum+1790);
	gf2x_add(36, temp, 36, temp, 36, temp2);
	gf2x_add(18, f_sum+1922, 18, f_sum+1922, 18, temp+18);
	right_bit_shift_n(38, f_sum+1922, 59);
	GF2X_MUL(40, temp, 20, f_sum+1790+18, 20, p_10+643);
	GF2X_MUL(40, temp2, 20, g_sum+1790+18, 20, p_11+643);
	gf2x_add(38, g_sum+1922, 38, temp+2, 38, temp2+2);
	GF2X_MUL(36, temp, 18, p_10+643+2, 18, f_sum+1790);
	GF2X_MUL(36, temp2, 18, p_11+643+2, 18, g_sum+1790);
	gf2x_add(36, temp, 36, temp, 36, temp2);
	gf2x_add(18, g_sum+1922, 18, g_sum+1922, 18, temp+18);
	right_bit_shift_n(38, g_sum+1922, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1937, g_sum+1937, p_00+687, p_01+687, p_10+687, p_11+687);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1933+4, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1933+4, 4, p_01+687);
	gf2x_add(8, f_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1933+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, g_sum+1933+0, 4, p_01+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2049, 4, f_sum+2049, 4, temp+4);
	right_bit_shift_n(8, f_sum+2049, 63);
	GF2X_MUL(8, temp, 4, f_sum+1933+4, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1933+4, 4, p_11+687);
	gf2x_add(8, g_sum+2049+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1933+0, 4, p_10+687);
	GF2X_MUL(8, temp2, 4, g_sum+1933+0, 4, p_11+687);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2049, 4, g_sum+2049, 4, temp+4);
	right_bit_shift_n(8, g_sum+2049, 63);
	

	delta = divstepsx_256(255, delta, f_sum+2050, g_sum+2050, q_00+669, q_01+669, q_10+669, q_11+669);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_10+687);
	gf2x_add(8, p_00+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_01+669+0, 4, p_11+687);
	gf2x_add(8, p_01+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_00+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_10+687);
	gf2x_add(8, p_10+679+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+669+0, 4, p_01+687);
	GF2X_MUL(8, temp2, 4, q_11+669+0, 4, p_11+687);
	gf2x_add(8, p_11+679+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1929+4, 8, p_00+679);
	GF2X_MUL(16, temp2, 8, g_sum+1929+4, 8, p_01+679);
	gf2x_add(12, f_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, f_sum+1929);
	GF2X_MUL(8, temp2, 4, p_01+679+4, 4, g_sum+1929);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+2028, 4, f_sum+2028, 4, temp+4);
	right_bit_shift_n(12, f_sum+2028, 62);
	GF2X_MUL(16, temp, 8, f_sum+1929+4, 8, p_10+679);
	GF2X_MUL(16, temp2, 8, g_sum+1929+4, 8, p_11+679);
	gf2x_add(12, g_sum+2028, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+679+4, 4, f_sum+1929);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, g_sum+1929);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+2028, 4, g_sum+2028, 4, temp+4);
	right_bit_shift_n(12, g_sum+2028, 62);
	

	delta = divstepsx_256(255, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 765, depth: 6
	memset(p_00+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_01+665);
	gf2x_add(8, p_00+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+667+0, 8, p_00+667+0, 8, temp);
	memset(p_01+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_00+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_01+665);
	gf2x_add(8, p_01+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_01+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+667+0, 8, p_01+667+0, 8, temp);
	memset(p_10+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_10+679+4, 4, q_11+665);
	gf2x_add(8, p_10+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_10+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+667+0, 8, p_10+667+0, 8, temp);
	memset(p_11+667, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+679+4, 4, q_10+665);
	GF2X_MUL(8, temp2, 4, p_11+679+4, 4, q_11+665);
	gf2x_add(8, p_11+667+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+665+0, 4, p_01+679);
	GF2X_MUL(8, temp2, 4, q_11+665+0, 4, p_11+679);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+667+0, 8, p_11+667+0, 8, temp);
	

	// Calculating left operands: n: 1146, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1923+6, 12, p_00+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+6, 12, p_01+667);
	gf2x_add(18, f_sum+1991, 18, temp+6, 18, temp2+6);
	GF2X_MUL(12, temp, 6, p_00+667+6, 6, f_sum+1923);
	GF2X_MUL(12, temp2, 6, p_01+667+6, 6, g_sum+1923);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, f_sum+1991, 6, f_sum+1991, 6, temp+6);
	right_bit_shift_n(18, f_sum+1991, 61);
	GF2X_MUL(24, temp, 12, f_sum+1923+6, 12, p_10+667);
	GF2X_MUL(24, temp2, 12, g_sum+1923+6, 12, p_11+667);
	gf2x_add(18, g_sum+1991, 18, temp+6, 18, temp2+6);
	GF2X_MUL(12, temp, 6, p_10+667+6, 6, f_sum+1923);
	GF2X_MUL(12, temp2, 6, p_11+667+6, 6, g_sum+1923);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, g_sum+1991, 6, g_sum+1991, 6, temp+6);
	right_bit_shift_n(18, g_sum+1991, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1994, g_sum+1994, p_00+679, p_01+679, p_10+679, p_11+679);

	// Calculating left operands: n: 381, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1992+2, 4, p_00+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+2, 4, p_01+679);
	gf2x_add(6, f_sum+2028, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_00+679+2, 2, f_sum+1992);
	GF2X_MUL(4, temp2, 2, p_01+679+2, 2, g_sum+1992);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+2028, 2, f_sum+2028, 2, temp+2);
	right_bit_shift_n(6, f_sum+2028, 63);
	GF2X_MUL(8, temp, 4, f_sum+1992+2, 4, p_10+679);
	GF2X_MUL(8, temp2, 4, g_sum+1992+2, 4, p_11+679);
	gf2x_add(6, g_sum+2028, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_10+679+2, 2, f_sum+1992);
	GF2X_MUL(4, temp2, 2, p_11+679+2, 2, g_sum+1992);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+2028, 2, g_sum+2028, 2, temp+2);
	right_bit_shift_n(6, g_sum+2028, 63);
	

	delta = divstepsx_128(126, delta, f_sum+2029, g_sum+2029, q_00+665, q_01+665, q_10+665, q_11+665);

	// Recombining results: n: 381, depth: 6
	memset(q_00+653, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+679+2, 2, q_00+665);
	GF2X_MUL(4, temp2, 2, p_10+679+2, 2, q_01+665);
	gf2x_add(4, q_00+653+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+665+0, 2, p_00+679);
	GF2X_MUL(4, temp2, 2, q_01+665+0, 2, p_10+679);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+653+0, 4, q_00+653+0, 4, temp);
	memset(q_01+653, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+679+2, 2, q_00+665);
	GF2X_MUL(4, temp2, 2, p_11+679+2, 2, q_01+665);
	gf2x_add(4, q_01+653+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+665+0, 2, p_01+679);
	GF2X_MUL(4, temp2, 2, q_01+665+0, 2, p_11+679);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+653+0, 4, q_01+653+0, 4, temp);
	memset(q_10+653, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+679+2, 2, q_10+665);
	GF2X_MUL(4, temp2, 2, p_10+679+2, 2, q_11+665);
	gf2x_add(4, q_10+653+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+665+0, 2, p_00+679);
	GF2X_MUL(4, temp2, 2, q_11+665+0, 2, p_10+679);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+653+0, 4, q_10+653+0, 4, temp);
	memset(q_11+653, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+679+2, 2, q_10+665);
	GF2X_MUL(4, temp2, 2, p_11+679+2, 2, q_11+665);
	gf2x_add(4, q_11+653+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+665+0, 2, p_01+679);
	GF2X_MUL(4, temp2, 2, q_11+665+0, 2, p_11+679);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+653+0, 4, q_11+653+0, 4, temp);
	

	// Recombining results: n: 1146, depth: 5
	memset(q_00+633, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+667+6, 6, q_00+653);
	GF2X_MUL(12, temp2, 6, p_10+667+6, 6, q_01+653);
	gf2x_add(12, q_00+633+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_00+653+0, 6, p_00+667);
	GF2X_MUL(12, temp2, 6, q_01+653+0, 6, p_10+667);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+633+0, 12, q_00+633+0, 12, temp);
	memset(q_01+633, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+667+6, 6, q_00+653);
	GF2X_MUL(12, temp2, 6, p_11+667+6, 6, q_01+653);
	gf2x_add(12, q_01+633+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_00+653+0, 6, p_01+667);
	GF2X_MUL(12, temp2, 6, q_01+653+0, 6, p_11+667);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+633+0, 12, q_01+633+0, 12, temp);
	memset(q_10+633, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+667+6, 6, q_10+653);
	GF2X_MUL(12, temp2, 6, p_10+667+6, 6, q_11+653);
	gf2x_add(12, q_10+633+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_10+653+0, 6, p_00+667);
	GF2X_MUL(12, temp2, 6, q_11+653+0, 6, p_10+667);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+633+0, 12, q_10+633+0, 12, temp);
	memset(q_11+633, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+667+6, 6, q_10+653);
	GF2X_MUL(12, temp2, 6, p_11+667+6, 6, q_11+653);
	gf2x_add(12, q_11+633+6, 12, temp, 12, temp2);
	GF2X_MUL(12, temp, 6, q_10+653+0, 6, p_01+667);
	GF2X_MUL(12, temp2, 6, q_11+653+0, 6, p_11+667);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+633+0, 12, q_11+633+0, 12, temp);
	

	// Recombining results: n: 2421, depth: 4
	memset(q_00+589, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_00+643+2, 18, q_00+633);
	GF2X_MUL(36, temp2, 18, p_10+643+2, 18, q_01+633);
	gf2x_add(36, q_00+589+2, 36, temp, 36, temp2);
	GF2X_MUL(4, temp, 2, q_00+633+16, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+16, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+16, 4, q_00+589+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+14, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+14, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+14, 4, q_00+589+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+12, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+12, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+12, 4, q_00+589+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+10, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+10, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+10, 4, q_00+589+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+8, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+8, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+8, 4, q_00+589+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+6, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+6, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+6, 4, q_00+589+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+4, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+4, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+4, 4, q_00+589+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+2, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+2, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+2, 4, q_00+589+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+0, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_01+633+0, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+589+0, 4, q_00+589+0, 4, temp);
	memset(q_01+589, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_01+643+2, 18, q_00+633);
	GF2X_MUL(36, temp2, 18, p_11+643+2, 18, q_01+633);
	gf2x_add(36, q_01+589+2, 36, temp, 36, temp2);
	GF2X_MUL(4, temp, 2, q_00+633+16, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+16, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+16, 4, q_01+589+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+14, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+14, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+14, 4, q_01+589+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+12, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+12, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+12, 4, q_01+589+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+10, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+10, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+10, 4, q_01+589+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+8, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+8, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+8, 4, q_01+589+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+6, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+6, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+6, 4, q_01+589+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+4, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+4, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+4, 4, q_01+589+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+2, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+2, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+2, 4, q_01+589+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+633+0, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_01+633+0, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+589+0, 4, q_01+589+0, 4, temp);
	memset(q_10+589, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_00+643+2, 18, q_10+633);
	GF2X_MUL(36, temp2, 18, p_10+643+2, 18, q_11+633);
	gf2x_add(36, q_10+589+2, 36, temp, 36, temp2);
	GF2X_MUL(4, temp, 2, q_10+633+16, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+16, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+16, 4, q_10+589+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+14, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+14, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+14, 4, q_10+589+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+12, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+12, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+12, 4, q_10+589+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+10, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+10, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+10, 4, q_10+589+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+8, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+8, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+8, 4, q_10+589+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+6, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+6, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+6, 4, q_10+589+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+4, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+4, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+4, 4, q_10+589+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+2, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+2, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+2, 4, q_10+589+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+0, 2, p_00+643);
	GF2X_MUL(4, temp2, 2, q_11+633+0, 2, p_10+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+589+0, 4, q_10+589+0, 4, temp);
	memset(q_11+589, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(36, temp, 18, p_01+643+2, 18, q_10+633);
	GF2X_MUL(36, temp2, 18, p_11+643+2, 18, q_11+633);
	gf2x_add(36, q_11+589+2, 36, temp, 36, temp2);
	GF2X_MUL(4, temp, 2, q_10+633+16, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+16, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+16, 4, q_11+589+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+14, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+14, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+14, 4, q_11+589+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+12, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+12, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+12, 4, q_11+589+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+10, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+10, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+10, 4, q_11+589+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+8, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+8, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+8, 4, q_11+589+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+6, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+6, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+6, 4, q_11+589+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+4, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+4, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+4, 4, q_11+589+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+2, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+2, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+2, 4, q_11+589+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+633+0, 2, p_01+643);
	GF2X_MUL(4, temp2, 2, q_11+633+0, 2, p_11+643);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+589+0, 4, q_11+589+0, 4, temp);
	

	// Recombining results: n: 5226, depth: 3
	memset(q_00+505, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(76, temp, 38, p_00+599+6, 38, q_00+589);
	GF2X_MUL(76, temp2, 38, p_10+599+6, 38, q_01+589);
	gf2x_add(76, q_00+505+6, 76, temp, 76, temp2);
	GF2X_MUL(12, temp, 6, q_00+589+32, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+32, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+32, 12, q_00+505+32, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+26, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+26, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+26, 12, q_00+505+26, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+20, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+20, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+20, 12, q_00+505+20, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+14, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+14, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+14, 12, q_00+505+14, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+8, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+8, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+8, 12, q_00+505+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+2, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_01+589+2, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+505+2, 12, q_00+505+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+599+4, 2, q_00+589);
	GF2X_MUL(4, temp2, 2, p_10+599+4, 2, q_01+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+505+4, 4, q_00+505+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+599+2, 2, q_00+589);
	GF2X_MUL(4, temp2, 2, p_10+599+2, 2, q_01+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+505+2, 4, q_00+505+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+589+0, 2, p_00+599);
	GF2X_MUL(4, temp2, 2, q_01+589+0, 2, p_10+599);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+505+0, 4, q_00+505+0, 4, temp);
	memset(q_01+505, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(76, temp, 38, p_01+599+6, 38, q_00+589);
	GF2X_MUL(76, temp2, 38, p_11+599+6, 38, q_01+589);
	gf2x_add(76, q_01+505+6, 76, temp, 76, temp2);
	GF2X_MUL(12, temp, 6, q_00+589+32, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+32, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+32, 12, q_01+505+32, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+26, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+26, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+26, 12, q_01+505+26, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+20, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+20, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+20, 12, q_01+505+20, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+14, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+14, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+14, 12, q_01+505+14, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+8, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+8, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+8, 12, q_01+505+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+589+2, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_01+589+2, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+505+2, 12, q_01+505+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+599+4, 2, q_00+589);
	GF2X_MUL(4, temp2, 2, p_11+599+4, 2, q_01+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+505+4, 4, q_01+505+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+599+2, 2, q_00+589);
	GF2X_MUL(4, temp2, 2, p_11+599+2, 2, q_01+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+505+2, 4, q_01+505+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+589+0, 2, p_01+599);
	GF2X_MUL(4, temp2, 2, q_01+589+0, 2, p_11+599);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+505+0, 4, q_01+505+0, 4, temp);
	memset(q_10+505, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(76, temp, 38, p_00+599+6, 38, q_10+589);
	GF2X_MUL(76, temp2, 38, p_10+599+6, 38, q_11+589);
	gf2x_add(76, q_10+505+6, 76, temp, 76, temp2);
	GF2X_MUL(12, temp, 6, q_10+589+32, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+32, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+32, 12, q_10+505+32, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+26, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+26, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+26, 12, q_10+505+26, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+20, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+20, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+20, 12, q_10+505+20, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+14, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+14, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+14, 12, q_10+505+14, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+8, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+8, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+8, 12, q_10+505+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+2, 6, p_00+599);
	GF2X_MUL(12, temp2, 6, q_11+589+2, 6, p_10+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+505+2, 12, q_10+505+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_00+599+4, 2, q_10+589);
	GF2X_MUL(4, temp2, 2, p_10+599+4, 2, q_11+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+505+4, 4, q_10+505+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+599+2, 2, q_10+589);
	GF2X_MUL(4, temp2, 2, p_10+599+2, 2, q_11+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+505+2, 4, q_10+505+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+589+0, 2, p_00+599);
	GF2X_MUL(4, temp2, 2, q_11+589+0, 2, p_10+599);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+505+0, 4, q_10+505+0, 4, temp);
	memset(q_11+505, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(76, temp, 38, p_01+599+6, 38, q_10+589);
	GF2X_MUL(76, temp2, 38, p_11+599+6, 38, q_11+589);
	gf2x_add(76, q_11+505+6, 76, temp, 76, temp2);
	GF2X_MUL(12, temp, 6, q_10+589+32, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+32, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+32, 12, q_11+505+32, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+26, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+26, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+26, 12, q_11+505+26, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+20, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+20, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+20, 12, q_11+505+20, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+14, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+14, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+14, 12, q_11+505+14, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+8, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+8, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+8, 12, q_11+505+8, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+589+2, 6, p_01+599);
	GF2X_MUL(12, temp2, 6, q_11+589+2, 6, p_11+599);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+505+2, 12, q_11+505+2, 12, temp);
	GF2X_MUL(4, temp, 2, p_01+599+4, 2, q_10+589);
	GF2X_MUL(4, temp2, 2, p_11+599+4, 2, q_11+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+505+4, 4, q_11+505+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+599+2, 2, q_10+589);
	GF2X_MUL(4, temp2, 2, p_11+599+2, 2, q_11+589);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+505+2, 4, q_11+505+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+589+0, 2, p_01+599);
	GF2X_MUL(4, temp2, 2, q_11+589+0, 2, p_11+599);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+505+0, 4, q_11+505+0, 4, temp);
	

	// Recombining results: n: 10581, depth: 2
	memset(q_00+337, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(164, temp, 82, p_00+511+2, 82, q_00+505);
	GF2X_MUL(164, temp2, 82, p_10+511+2, 82, q_01+505);
	gf2x_add(164, q_00+337+2, 164, temp, 164, temp2);
	GF2X_MUL(4, temp, 2, q_00+505+80, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+80, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+80, 4, q_00+337+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+78, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+78, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+78, 4, q_00+337+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+76, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+76, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+76, 4, q_00+337+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+74, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+74, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+74, 4, q_00+337+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+72, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+72, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+72, 4, q_00+337+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+70, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+70, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+70, 4, q_00+337+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+68, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+68, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+68, 4, q_00+337+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+66, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+66, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+66, 4, q_00+337+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+64, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+64, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+64, 4, q_00+337+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+62, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+62, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+62, 4, q_00+337+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+60, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+60, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+60, 4, q_00+337+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+58, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+58, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+58, 4, q_00+337+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+56, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+56, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+56, 4, q_00+337+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+54, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+54, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+54, 4, q_00+337+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+52, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+52, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+52, 4, q_00+337+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+50, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+50, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+50, 4, q_00+337+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+48, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+48, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+48, 4, q_00+337+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+46, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+46, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+46, 4, q_00+337+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+44, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+44, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+44, 4, q_00+337+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+42, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+42, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+42, 4, q_00+337+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+40, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+40, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+40, 4, q_00+337+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+38, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+38, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+38, 4, q_00+337+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+36, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+36, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+36, 4, q_00+337+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+34, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+34, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+34, 4, q_00+337+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+32, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+32, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+32, 4, q_00+337+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+30, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+30, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+30, 4, q_00+337+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+28, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+28, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+28, 4, q_00+337+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+26, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+26, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+26, 4, q_00+337+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+24, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+24, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+24, 4, q_00+337+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+22, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+22, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+22, 4, q_00+337+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+20, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+20, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+20, 4, q_00+337+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+18, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+18, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+18, 4, q_00+337+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+16, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+16, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+16, 4, q_00+337+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+14, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+14, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+14, 4, q_00+337+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+12, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+12, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+12, 4, q_00+337+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+10, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+10, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+10, 4, q_00+337+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+8, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+8, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+8, 4, q_00+337+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+6, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+6, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+6, 4, q_00+337+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+4, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+4, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+4, 4, q_00+337+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+2, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+2, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+2, 4, q_00+337+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+0, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_01+505+0, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+337+0, 4, q_00+337+0, 4, temp);
	memset(q_01+337, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(164, temp, 82, p_01+511+2, 82, q_00+505);
	GF2X_MUL(164, temp2, 82, p_11+511+2, 82, q_01+505);
	gf2x_add(164, q_01+337+2, 164, temp, 164, temp2);
	GF2X_MUL(4, temp, 2, q_00+505+80, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+80, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+80, 4, q_01+337+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+78, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+78, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+78, 4, q_01+337+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+76, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+76, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+76, 4, q_01+337+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+74, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+74, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+74, 4, q_01+337+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+72, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+72, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+72, 4, q_01+337+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+70, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+70, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+70, 4, q_01+337+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+68, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+68, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+68, 4, q_01+337+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+66, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+66, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+66, 4, q_01+337+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+64, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+64, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+64, 4, q_01+337+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+62, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+62, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+62, 4, q_01+337+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+60, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+60, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+60, 4, q_01+337+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+58, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+58, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+58, 4, q_01+337+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+56, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+56, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+56, 4, q_01+337+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+54, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+54, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+54, 4, q_01+337+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+52, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+52, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+52, 4, q_01+337+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+50, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+50, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+50, 4, q_01+337+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+48, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+48, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+48, 4, q_01+337+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+46, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+46, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+46, 4, q_01+337+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+44, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+44, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+44, 4, q_01+337+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+42, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+42, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+42, 4, q_01+337+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+40, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+40, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+40, 4, q_01+337+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+38, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+38, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+38, 4, q_01+337+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+36, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+36, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+36, 4, q_01+337+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+34, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+34, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+34, 4, q_01+337+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+32, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+32, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+32, 4, q_01+337+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+30, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+30, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+30, 4, q_01+337+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+28, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+28, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+28, 4, q_01+337+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+26, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+26, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+26, 4, q_01+337+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+24, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+24, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+24, 4, q_01+337+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+22, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+22, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+22, 4, q_01+337+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+20, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+20, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+20, 4, q_01+337+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+18, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+18, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+18, 4, q_01+337+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+16, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+16, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+16, 4, q_01+337+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+14, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+14, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+14, 4, q_01+337+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+12, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+12, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+12, 4, q_01+337+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+10, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+10, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+10, 4, q_01+337+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+8, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+8, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+8, 4, q_01+337+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+6, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+6, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+6, 4, q_01+337+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+4, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+4, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+4, 4, q_01+337+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+2, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+2, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+2, 4, q_01+337+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+505+0, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_01+505+0, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+337+0, 4, q_01+337+0, 4, temp);
	memset(q_10+337, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(164, temp, 82, p_00+511+2, 82, q_10+505);
	GF2X_MUL(164, temp2, 82, p_10+511+2, 82, q_11+505);
	gf2x_add(164, q_10+337+2, 164, temp, 164, temp2);
	GF2X_MUL(4, temp, 2, q_10+505+80, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+80, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+80, 4, q_10+337+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+78, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+78, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+78, 4, q_10+337+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+76, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+76, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+76, 4, q_10+337+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+74, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+74, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+74, 4, q_10+337+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+72, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+72, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+72, 4, q_10+337+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+70, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+70, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+70, 4, q_10+337+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+68, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+68, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+68, 4, q_10+337+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+66, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+66, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+66, 4, q_10+337+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+64, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+64, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+64, 4, q_10+337+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+62, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+62, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+62, 4, q_10+337+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+60, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+60, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+60, 4, q_10+337+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+58, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+58, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+58, 4, q_10+337+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+56, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+56, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+56, 4, q_10+337+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+54, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+54, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+54, 4, q_10+337+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+52, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+52, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+52, 4, q_10+337+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+50, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+50, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+50, 4, q_10+337+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+48, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+48, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+48, 4, q_10+337+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+46, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+46, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+46, 4, q_10+337+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+44, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+44, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+44, 4, q_10+337+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+42, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+42, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+42, 4, q_10+337+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+40, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+40, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+40, 4, q_10+337+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+38, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+38, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+38, 4, q_10+337+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+36, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+36, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+36, 4, q_10+337+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+34, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+34, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+34, 4, q_10+337+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+32, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+32, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+32, 4, q_10+337+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+30, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+30, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+30, 4, q_10+337+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+28, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+28, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+28, 4, q_10+337+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+26, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+26, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+26, 4, q_10+337+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+24, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+24, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+24, 4, q_10+337+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+22, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+22, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+22, 4, q_10+337+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+20, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+20, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+20, 4, q_10+337+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+18, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+18, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+18, 4, q_10+337+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+16, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+16, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+16, 4, q_10+337+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+14, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+14, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+14, 4, q_10+337+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+12, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+12, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+12, 4, q_10+337+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+10, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+10, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+10, 4, q_10+337+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+8, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+8, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+8, 4, q_10+337+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+6, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+6, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+6, 4, q_10+337+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+4, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+4, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+4, 4, q_10+337+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+2, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+2, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+2, 4, q_10+337+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+0, 2, p_00+511);
	GF2X_MUL(4, temp2, 2, q_11+505+0, 2, p_10+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+337+0, 4, q_10+337+0, 4, temp);
	memset(q_11+337, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(164, temp, 82, p_01+511+2, 82, q_10+505);
	GF2X_MUL(164, temp2, 82, p_11+511+2, 82, q_11+505);
	gf2x_add(164, q_11+337+2, 164, temp, 164, temp2);
	GF2X_MUL(4, temp, 2, q_10+505+80, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+80, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+80, 4, q_11+337+80, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+78, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+78, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+78, 4, q_11+337+78, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+76, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+76, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+76, 4, q_11+337+76, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+74, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+74, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+74, 4, q_11+337+74, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+72, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+72, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+72, 4, q_11+337+72, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+70, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+70, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+70, 4, q_11+337+70, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+68, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+68, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+68, 4, q_11+337+68, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+66, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+66, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+66, 4, q_11+337+66, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+64, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+64, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+64, 4, q_11+337+64, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+62, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+62, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+62, 4, q_11+337+62, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+60, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+60, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+60, 4, q_11+337+60, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+58, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+58, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+58, 4, q_11+337+58, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+56, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+56, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+56, 4, q_11+337+56, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+54, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+54, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+54, 4, q_11+337+54, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+52, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+52, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+52, 4, q_11+337+52, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+50, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+50, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+50, 4, q_11+337+50, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+48, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+48, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+48, 4, q_11+337+48, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+46, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+46, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+46, 4, q_11+337+46, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+44, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+44, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+44, 4, q_11+337+44, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+42, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+42, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+42, 4, q_11+337+42, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+40, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+40, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+40, 4, q_11+337+40, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+38, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+38, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+38, 4, q_11+337+38, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+36, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+36, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+36, 4, q_11+337+36, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+34, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+34, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+34, 4, q_11+337+34, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+32, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+32, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+32, 4, q_11+337+32, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+30, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+30, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+30, 4, q_11+337+30, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+28, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+28, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+28, 4, q_11+337+28, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+26, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+26, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+26, 4, q_11+337+26, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+24, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+24, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+24, 4, q_11+337+24, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+22, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+22, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+22, 4, q_11+337+22, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+20, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+20, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+20, 4, q_11+337+20, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+18, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+18, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+18, 4, q_11+337+18, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+16, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+16, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+16, 4, q_11+337+16, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+14, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+14, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+14, 4, q_11+337+14, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+12, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+12, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+12, 4, q_11+337+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+10, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+10, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+10, 4, q_11+337+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+8, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+8, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+8, 4, q_11+337+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+6, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+6, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+6, 4, q_11+337+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+4, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+4, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+4, 4, q_11+337+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+2, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+2, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+2, 4, q_11+337+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+505+0, 2, p_01+511);
	GF2X_MUL(4, temp2, 2, q_11+505+0, 2, p_11+511);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+337+0, 4, q_11+337+0, 4, temp);
	

	// Recombining results: n: 21546, depth: 1
	memset(q_00+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(332, temp, 166, p_00+339+6, 166, q_00+337);
	GF2X_MUL(332, temp2, 166, p_10+339+6, 166, q_01+337);
	gf2x_add(332, q_00+0+5, 332, temp, 332, temp2);
	GF2X_MUL(12, temp, 6, q_00+337+160, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+160, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+159, 12, q_00+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+154, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+154, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+153, 12, q_00+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+148, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+148, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+147, 12, q_00+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+142, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+142, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+141, 12, q_00+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+136, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+136, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+135, 12, q_00+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+130, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+130, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+129, 12, q_00+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+124, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+124, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+123, 12, q_00+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+118, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+118, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+117, 12, q_00+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+112, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+112, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+111, 12, q_00+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+106, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+106, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+105, 12, q_00+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+100, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+100, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+99, 12, q_00+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+94, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+94, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+93, 12, q_00+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+88, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+88, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+87, 12, q_00+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+82, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+82, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+81, 12, q_00+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+76, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+76, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+75, 12, q_00+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+70, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+70, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+69, 12, q_00+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+64, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+64, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+63, 12, q_00+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+58, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+58, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+57, 12, q_00+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+52, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+52, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+51, 12, q_00+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+46, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+46, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+45, 12, q_00+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+40, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+40, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+39, 12, q_00+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+34, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+34, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+33, 12, q_00+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+28, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+28, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+27, 12, q_00+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+22, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+22, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+21, 12, q_00+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+16, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+16, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+15, 12, q_00+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+10, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+10, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+9, 12, q_00+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+4, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_01+337+4, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+3, 12, q_00+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+339+2, 4, q_00+337);
	GF2X_MUL(8, temp2, 4, p_10+339+2, 4, q_01+337);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+0+1, 8, q_00+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+337+2, 2, p_00+339);
	GF2X_MUL(4, temp2, 2, q_01+337+2, 2, p_10+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+1, 4, q_00+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+337+0, 2, p_00+339);
	GF2X_MUL(4, temp2, 2, q_01+337+0, 2, p_10+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+0, 3, q_00+0, 3, temp+1);
	memset(q_01+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(332, temp, 166, p_01+339+6, 166, q_00+337);
	GF2X_MUL(332, temp2, 166, p_11+339+6, 166, q_01+337);
	gf2x_add(332, q_01+0+5, 332, temp, 332, temp2);
	GF2X_MUL(12, temp, 6, q_00+337+160, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+160, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+159, 12, q_01+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+154, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+154, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+153, 12, q_01+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+148, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+148, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+147, 12, q_01+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+142, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+142, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+141, 12, q_01+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+136, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+136, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+135, 12, q_01+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+130, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+130, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+129, 12, q_01+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+124, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+124, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+123, 12, q_01+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+118, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+118, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+117, 12, q_01+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+112, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+112, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+111, 12, q_01+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+106, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+106, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+105, 12, q_01+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+100, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+100, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+99, 12, q_01+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+94, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+94, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+93, 12, q_01+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+88, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+88, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+87, 12, q_01+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+82, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+82, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+81, 12, q_01+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+76, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+76, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+75, 12, q_01+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+70, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+70, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+69, 12, q_01+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+64, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+64, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+63, 12, q_01+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+58, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+58, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+57, 12, q_01+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+52, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+52, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+51, 12, q_01+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+46, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+46, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+45, 12, q_01+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+40, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+40, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+39, 12, q_01+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+34, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+34, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+33, 12, q_01+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+28, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+28, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+27, 12, q_01+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+22, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+22, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+21, 12, q_01+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+16, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+16, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+15, 12, q_01+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+10, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+10, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+9, 12, q_01+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+337+4, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_01+337+4, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+3, 12, q_01+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+339+2, 4, q_00+337);
	GF2X_MUL(8, temp2, 4, p_11+339+2, 4, q_01+337);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+0+1, 8, q_01+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_00+337+2, 2, p_01+339);
	GF2X_MUL(4, temp2, 2, q_01+337+2, 2, p_11+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+1, 4, q_01+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+337+0, 2, p_01+339);
	GF2X_MUL(4, temp2, 2, q_01+337+0, 2, p_11+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+0, 3, q_01+0, 3, temp+1);
	memset(q_10+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(332, temp, 166, p_00+339+6, 166, q_10+337);
	GF2X_MUL(332, temp2, 166, p_10+339+6, 166, q_11+337);
	gf2x_add(332, q_10+0+5, 332, temp, 332, temp2);
	GF2X_MUL(12, temp, 6, q_10+337+160, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+160, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+159, 12, q_10+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+154, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+154, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+153, 12, q_10+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+148, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+148, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+147, 12, q_10+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+142, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+142, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+141, 12, q_10+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+136, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+136, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+135, 12, q_10+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+130, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+130, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+129, 12, q_10+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+124, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+124, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+123, 12, q_10+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+118, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+118, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+117, 12, q_10+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+112, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+112, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+111, 12, q_10+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+106, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+106, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+105, 12, q_10+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+100, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+100, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+99, 12, q_10+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+94, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+94, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+93, 12, q_10+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+88, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+88, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+87, 12, q_10+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+82, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+82, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+81, 12, q_10+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+76, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+76, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+75, 12, q_10+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+70, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+70, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+69, 12, q_10+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+64, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+64, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+63, 12, q_10+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+58, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+58, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+57, 12, q_10+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+52, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+52, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+51, 12, q_10+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+46, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+46, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+45, 12, q_10+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+40, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+40, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+39, 12, q_10+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+34, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+34, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+33, 12, q_10+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+28, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+28, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+27, 12, q_10+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+22, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+22, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+21, 12, q_10+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+16, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+16, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+15, 12, q_10+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+10, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+10, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+9, 12, q_10+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+4, 6, p_00+339);
	GF2X_MUL(12, temp2, 6, q_11+337+4, 6, p_10+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+3, 12, q_10+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_00+339+2, 4, q_10+337);
	GF2X_MUL(8, temp2, 4, p_10+339+2, 4, q_11+337);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+0+1, 8, q_10+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+337+2, 2, p_00+339);
	GF2X_MUL(4, temp2, 2, q_11+337+2, 2, p_10+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+1, 4, q_10+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+337+0, 2, p_00+339);
	GF2X_MUL(4, temp2, 2, q_11+337+0, 2, p_10+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+0, 3, q_10+0, 3, temp+1);
	memset(q_11+0, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(332, temp, 166, p_01+339+6, 166, q_10+337);
	GF2X_MUL(332, temp2, 166, p_11+339+6, 166, q_11+337);
	gf2x_add(332, q_11+0+5, 332, temp, 332, temp2);
	GF2X_MUL(12, temp, 6, q_10+337+160, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+160, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+159, 12, q_11+0+159, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+154, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+154, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+153, 12, q_11+0+153, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+148, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+148, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+147, 12, q_11+0+147, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+142, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+142, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+141, 12, q_11+0+141, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+136, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+136, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+135, 12, q_11+0+135, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+130, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+130, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+129, 12, q_11+0+129, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+124, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+124, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+123, 12, q_11+0+123, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+118, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+118, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+117, 12, q_11+0+117, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+112, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+112, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+111, 12, q_11+0+111, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+106, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+106, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+105, 12, q_11+0+105, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+100, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+100, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+99, 12, q_11+0+99, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+94, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+94, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+93, 12, q_11+0+93, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+88, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+88, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+87, 12, q_11+0+87, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+82, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+82, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+81, 12, q_11+0+81, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+76, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+76, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+75, 12, q_11+0+75, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+70, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+70, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+69, 12, q_11+0+69, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+64, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+64, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+63, 12, q_11+0+63, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+58, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+58, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+57, 12, q_11+0+57, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+52, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+52, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+51, 12, q_11+0+51, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+46, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+46, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+45, 12, q_11+0+45, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+40, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+40, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+39, 12, q_11+0+39, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+34, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+34, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+33, 12, q_11+0+33, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+28, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+28, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+27, 12, q_11+0+27, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+22, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+22, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+21, 12, q_11+0+21, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+16, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+16, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+15, 12, q_11+0+15, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+10, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+10, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+9, 12, q_11+0+9, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+337+4, 6, p_01+339);
	GF2X_MUL(12, temp2, 6, q_11+337+4, 6, p_11+339);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+3, 12, q_11+0+3, 12, temp);
	GF2X_MUL(8, temp, 4, p_01+339+2, 4, q_10+337);
	GF2X_MUL(8, temp2, 4, p_11+339+2, 4, q_11+337);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+0+1, 8, q_11+0+1, 8, temp);
	GF2X_MUL(4, temp, 2, q_10+337+2, 2, p_01+339);
	GF2X_MUL(4, temp2, 2, q_11+337+2, 2, p_11+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+1, 4, q_11+0+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+337+0, 2, p_01+339);
	GF2X_MUL(4, temp2, 2, q_11+337+0, 2, p_11+339);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+0, 3, q_11+0, 3, temp+1);
	

	// Recombining results: n: 43221, depth: 0
	memset(t_00+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(674, temp, 337, p_00+0+2, 337, q_00+0);
	GF2X_MUL(674, temp2, 337, p_10+0+2, 337, q_01+0);
	gf2x_add(674, t_00+0+2, 674, temp, 674, temp2);
	GF2X_MUL(4, temp, 2, q_00+0+335, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+335, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+335, 4, t_00+0+335, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+333, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+333, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+333, 4, t_00+0+333, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+331, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+331, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+331, 4, t_00+0+331, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+329, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+329, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+329, 4, t_00+0+329, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+327, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+327, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+327, 4, t_00+0+327, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+325, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+325, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+325, 4, t_00+0+325, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+323, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+323, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+323, 4, t_00+0+323, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+321, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+321, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+321, 4, t_00+0+321, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+319, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+319, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+319, 4, t_00+0+319, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+317, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+317, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+317, 4, t_00+0+317, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+315, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+315, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+315, 4, t_00+0+315, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+313, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+313, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+313, 4, t_00+0+313, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+311, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+311, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+311, 4, t_00+0+311, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+309, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+309, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+309, 4, t_00+0+309, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+307, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+307, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+307, 4, t_00+0+307, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+305, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+305, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+305, 4, t_00+0+305, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+303, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+303, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+303, 4, t_00+0+303, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+301, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+301, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+301, 4, t_00+0+301, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+299, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+299, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+299, 4, t_00+0+299, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+297, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+297, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+297, 4, t_00+0+297, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+295, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+295, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+295, 4, t_00+0+295, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+293, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+293, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+293, 4, t_00+0+293, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+291, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+291, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+291, 4, t_00+0+291, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+289, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+289, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+289, 4, t_00+0+289, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+287, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+287, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+287, 4, t_00+0+287, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+285, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+285, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+285, 4, t_00+0+285, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+283, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+283, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+283, 4, t_00+0+283, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+281, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+281, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+281, 4, t_00+0+281, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+279, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+279, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+279, 4, t_00+0+279, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+277, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+277, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+277, 4, t_00+0+277, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+275, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+275, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+275, 4, t_00+0+275, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+273, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+273, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+273, 4, t_00+0+273, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+271, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+271, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+271, 4, t_00+0+271, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+269, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+269, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+269, 4, t_00+0+269, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+267, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+267, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+267, 4, t_00+0+267, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+265, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+265, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+265, 4, t_00+0+265, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+263, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+263, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+263, 4, t_00+0+263, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+261, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+261, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+261, 4, t_00+0+261, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+259, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+259, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+259, 4, t_00+0+259, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+257, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+257, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+257, 4, t_00+0+257, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+255, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+255, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+255, 4, t_00+0+255, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+253, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+253, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+253, 4, t_00+0+253, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+251, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+251, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+251, 4, t_00+0+251, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+249, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+249, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+249, 4, t_00+0+249, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+247, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+247, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+247, 4, t_00+0+247, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+245, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+245, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+245, 4, t_00+0+245, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+243, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+243, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+243, 4, t_00+0+243, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+241, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+241, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+241, 4, t_00+0+241, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+239, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+239, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+239, 4, t_00+0+239, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+237, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+237, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+237, 4, t_00+0+237, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+235, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+235, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+235, 4, t_00+0+235, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+233, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+233, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+233, 4, t_00+0+233, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+231, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+231, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+231, 4, t_00+0+231, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+229, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+229, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+229, 4, t_00+0+229, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+227, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+227, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+227, 4, t_00+0+227, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+225, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+225, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+225, 4, t_00+0+225, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+223, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+223, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+223, 4, t_00+0+223, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+221, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+221, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+221, 4, t_00+0+221, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+219, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+219, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+219, 4, t_00+0+219, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+217, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+217, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+217, 4, t_00+0+217, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+215, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+215, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+215, 4, t_00+0+215, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+213, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+213, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+213, 4, t_00+0+213, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+211, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+211, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+211, 4, t_00+0+211, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+209, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+209, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+209, 4, t_00+0+209, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+207, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+207, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+207, 4, t_00+0+207, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+205, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+205, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+205, 4, t_00+0+205, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+203, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+203, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+203, 4, t_00+0+203, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+201, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+201, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+201, 4, t_00+0+201, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+199, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+199, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+199, 4, t_00+0+199, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+197, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+197, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+197, 4, t_00+0+197, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+195, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+195, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+195, 4, t_00+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+193, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+193, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+193, 4, t_00+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+191, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+191, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+191, 4, t_00+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+189, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+189, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+189, 4, t_00+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+187, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+187, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+187, 4, t_00+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+185, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+185, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+185, 4, t_00+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+183, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+183, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+183, 4, t_00+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+181, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+181, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+181, 4, t_00+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+179, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+179, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+179, 4, t_00+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+177, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+177, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+177, 4, t_00+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+175, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+175, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+175, 4, t_00+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+173, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+173, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+173, 4, t_00+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+171, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+171, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+171, 4, t_00+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+169, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+169, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+169, 4, t_00+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+167, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+167, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+167, 4, t_00+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+165, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+165, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+165, 4, t_00+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+163, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+163, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+163, 4, t_00+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+161, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+161, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+161, 4, t_00+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+159, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+159, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+159, 4, t_00+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+157, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+157, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+157, 4, t_00+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+155, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+155, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+155, 4, t_00+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+153, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+153, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+153, 4, t_00+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+151, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+151, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+151, 4, t_00+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+149, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+149, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+149, 4, t_00+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+147, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+147, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+147, 4, t_00+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+145, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+145, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+145, 4, t_00+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+143, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+143, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+143, 4, t_00+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+141, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+141, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+141, 4, t_00+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+139, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+139, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+139, 4, t_00+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+137, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+137, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+137, 4, t_00+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+135, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+135, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+135, 4, t_00+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+133, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+133, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+133, 4, t_00+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+131, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+131, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+131, 4, t_00+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+129, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+129, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+129, 4, t_00+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+127, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+127, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+127, 4, t_00+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+125, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+125, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+125, 4, t_00+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+123, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+123, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+123, 4, t_00+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+121, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+121, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+121, 4, t_00+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+119, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+119, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+119, 4, t_00+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+117, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+117, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+117, 4, t_00+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+115, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+115, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+115, 4, t_00+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+113, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+113, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+113, 4, t_00+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+111, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+111, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+111, 4, t_00+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+109, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+109, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+109, 4, t_00+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+107, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+107, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+107, 4, t_00+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+105, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+105, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+105, 4, t_00+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+103, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+103, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+103, 4, t_00+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+101, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+101, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+101, 4, t_00+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+99, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+99, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+99, 4, t_00+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+97, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+97, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+97, 4, t_00+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+95, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+95, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+95, 4, t_00+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+93, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+93, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+93, 4, t_00+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+91, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+91, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+91, 4, t_00+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+89, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+89, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+89, 4, t_00+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+87, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+87, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+87, 4, t_00+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+85, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+85, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+85, 4, t_00+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+83, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+83, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+83, 4, t_00+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+81, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+81, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+81, 4, t_00+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+79, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+79, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+79, 4, t_00+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+77, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+77, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+77, 4, t_00+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+75, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+75, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+75, 4, t_00+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+73, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+73, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+73, 4, t_00+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+71, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+71, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+71, 4, t_00+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+69, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+69, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+69, 4, t_00+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+67, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+67, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+67, 4, t_00+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+65, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+65, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+65, 4, t_00+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+63, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+63, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+63, 4, t_00+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+61, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+61, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+61, 4, t_00+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+59, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+59, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+59, 4, t_00+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+57, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+57, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+57, 4, t_00+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+55, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+55, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+55, 4, t_00+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+53, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+53, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+53, 4, t_00+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+51, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+51, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+51, 4, t_00+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+49, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+49, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+49, 4, t_00+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+47, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+47, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+47, 4, t_00+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+45, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+45, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+45, 4, t_00+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+43, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+43, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+43, 4, t_00+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+41, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+41, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+41, 4, t_00+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+39, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+39, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+39, 4, t_00+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+37, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+37, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+37, 4, t_00+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+35, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+35, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+35, 4, t_00+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+33, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+33, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+33, 4, t_00+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+31, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+31, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+31, 4, t_00+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+29, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+29, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+29, 4, t_00+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+27, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+27, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+27, 4, t_00+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+25, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+25, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+25, 4, t_00+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+23, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+23, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+23, 4, t_00+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+21, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+21, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+21, 4, t_00+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+19, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+19, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+19, 4, t_00+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+17, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+17, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+17, 4, t_00+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+15, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+15, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+15, 4, t_00+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+13, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+13, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+13, 4, t_00+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+11, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+11, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+11, 4, t_00+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+9, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+9, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+9, 4, t_00+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+7, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+7, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+7, 4, t_00+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+5, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+5, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+5, 4, t_00+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+3, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+3, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+3, 4, t_00+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+1, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_01+0+1, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_00+0+1, 4, t_00+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+1, 2, t_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	memset(t_01+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(674, temp, 337, p_01+0+2, 337, q_00+0);
	GF2X_MUL(674, temp2, 337, p_11+0+2, 337, q_01+0);
	gf2x_add(674, t_01+0+2, 674, temp, 674, temp2);
	GF2X_MUL(4, temp, 2, q_00+0+335, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+335, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+335, 4, t_01+0+335, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+333, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+333, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+333, 4, t_01+0+333, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+331, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+331, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+331, 4, t_01+0+331, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+329, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+329, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+329, 4, t_01+0+329, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+327, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+327, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+327, 4, t_01+0+327, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+325, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+325, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+325, 4, t_01+0+325, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+323, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+323, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+323, 4, t_01+0+323, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+321, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+321, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+321, 4, t_01+0+321, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+319, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+319, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+319, 4, t_01+0+319, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+317, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+317, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+317, 4, t_01+0+317, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+315, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+315, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+315, 4, t_01+0+315, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+313, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+313, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+313, 4, t_01+0+313, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+311, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+311, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+311, 4, t_01+0+311, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+309, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+309, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+309, 4, t_01+0+309, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+307, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+307, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+307, 4, t_01+0+307, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+305, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+305, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+305, 4, t_01+0+305, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+303, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+303, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+303, 4, t_01+0+303, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+301, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+301, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+301, 4, t_01+0+301, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+299, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+299, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+299, 4, t_01+0+299, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+297, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+297, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+297, 4, t_01+0+297, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+295, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+295, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+295, 4, t_01+0+295, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+293, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+293, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+293, 4, t_01+0+293, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+291, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+291, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+291, 4, t_01+0+291, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+289, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+289, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+289, 4, t_01+0+289, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+287, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+287, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+287, 4, t_01+0+287, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+285, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+285, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+285, 4, t_01+0+285, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+283, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+283, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+283, 4, t_01+0+283, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+281, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+281, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+281, 4, t_01+0+281, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+279, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+279, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+279, 4, t_01+0+279, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+277, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+277, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+277, 4, t_01+0+277, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+275, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+275, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+275, 4, t_01+0+275, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+273, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+273, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+273, 4, t_01+0+273, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+271, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+271, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+271, 4, t_01+0+271, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+269, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+269, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+269, 4, t_01+0+269, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+267, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+267, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+267, 4, t_01+0+267, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+265, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+265, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+265, 4, t_01+0+265, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+263, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+263, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+263, 4, t_01+0+263, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+261, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+261, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+261, 4, t_01+0+261, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+259, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+259, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+259, 4, t_01+0+259, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+257, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+257, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+257, 4, t_01+0+257, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+255, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+255, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+255, 4, t_01+0+255, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+253, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+253, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+253, 4, t_01+0+253, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+251, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+251, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+251, 4, t_01+0+251, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+249, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+249, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+249, 4, t_01+0+249, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+247, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+247, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+247, 4, t_01+0+247, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+245, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+245, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+245, 4, t_01+0+245, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+243, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+243, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+243, 4, t_01+0+243, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+241, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+241, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+241, 4, t_01+0+241, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+239, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+239, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+239, 4, t_01+0+239, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+237, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+237, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+237, 4, t_01+0+237, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+235, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+235, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+235, 4, t_01+0+235, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+233, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+233, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+233, 4, t_01+0+233, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+231, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+231, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+231, 4, t_01+0+231, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+229, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+229, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+229, 4, t_01+0+229, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+227, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+227, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+227, 4, t_01+0+227, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+225, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+225, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+225, 4, t_01+0+225, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+223, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+223, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+223, 4, t_01+0+223, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+221, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+221, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+221, 4, t_01+0+221, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+219, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+219, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+219, 4, t_01+0+219, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+217, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+217, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+217, 4, t_01+0+217, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+215, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+215, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+215, 4, t_01+0+215, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+213, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+213, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+213, 4, t_01+0+213, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+211, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+211, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+211, 4, t_01+0+211, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+209, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+209, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+209, 4, t_01+0+209, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+207, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+207, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+207, 4, t_01+0+207, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+205, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+205, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+205, 4, t_01+0+205, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+203, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+203, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+203, 4, t_01+0+203, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+201, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+201, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+201, 4, t_01+0+201, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+199, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+199, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+199, 4, t_01+0+199, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+197, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+197, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+197, 4, t_01+0+197, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+195, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+195, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+195, 4, t_01+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+193, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+193, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+193, 4, t_01+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+191, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+191, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+191, 4, t_01+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+189, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+189, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+189, 4, t_01+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+187, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+187, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+187, 4, t_01+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+185, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+185, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+185, 4, t_01+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+183, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+183, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+183, 4, t_01+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+181, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+181, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+181, 4, t_01+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+179, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+179, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+179, 4, t_01+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+177, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+177, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+177, 4, t_01+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+175, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+175, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+175, 4, t_01+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+173, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+173, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+173, 4, t_01+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+171, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+171, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+171, 4, t_01+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+169, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+169, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+169, 4, t_01+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+167, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+167, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+167, 4, t_01+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+165, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+165, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+165, 4, t_01+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+163, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+163, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+163, 4, t_01+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+161, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+161, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+161, 4, t_01+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+159, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+159, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+159, 4, t_01+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+157, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+157, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+157, 4, t_01+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+155, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+155, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+155, 4, t_01+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+153, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+153, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+153, 4, t_01+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+151, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+151, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+151, 4, t_01+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+149, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+149, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+149, 4, t_01+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+147, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+147, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+147, 4, t_01+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+145, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+145, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+145, 4, t_01+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+143, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+143, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+143, 4, t_01+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+141, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+141, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+141, 4, t_01+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+139, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+139, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+139, 4, t_01+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+137, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+137, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+137, 4, t_01+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+135, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+135, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+135, 4, t_01+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+133, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+133, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+133, 4, t_01+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+131, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+131, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+131, 4, t_01+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+129, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+129, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+129, 4, t_01+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+127, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+127, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+127, 4, t_01+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+125, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+125, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+125, 4, t_01+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+123, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+123, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+123, 4, t_01+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+121, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+121, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+121, 4, t_01+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+119, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+119, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+119, 4, t_01+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+117, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+117, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+117, 4, t_01+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+115, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+115, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+115, 4, t_01+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+113, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+113, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+113, 4, t_01+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+111, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+111, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+111, 4, t_01+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+109, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+109, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+109, 4, t_01+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+107, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+107, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+107, 4, t_01+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+105, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+105, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+105, 4, t_01+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+103, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+103, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+103, 4, t_01+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+101, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+101, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+101, 4, t_01+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+99, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+99, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+99, 4, t_01+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+97, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+97, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+97, 4, t_01+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+95, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+95, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+95, 4, t_01+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+93, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+93, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+93, 4, t_01+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+91, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+91, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+91, 4, t_01+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+89, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+89, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+89, 4, t_01+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+87, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+87, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+87, 4, t_01+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+85, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+85, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+85, 4, t_01+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+83, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+83, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+83, 4, t_01+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+81, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+81, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+81, 4, t_01+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+79, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+79, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+79, 4, t_01+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+77, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+77, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+77, 4, t_01+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+75, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+75, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+75, 4, t_01+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+73, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+73, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+73, 4, t_01+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+71, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+71, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+71, 4, t_01+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+69, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+69, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+69, 4, t_01+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+67, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+67, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+67, 4, t_01+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+65, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+65, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+65, 4, t_01+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+63, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+63, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+63, 4, t_01+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+61, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+61, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+61, 4, t_01+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+59, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+59, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+59, 4, t_01+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+57, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+57, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+57, 4, t_01+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+55, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+55, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+55, 4, t_01+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+53, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+53, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+53, 4, t_01+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+51, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+51, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+51, 4, t_01+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+49, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+49, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+49, 4, t_01+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+47, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+47, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+47, 4, t_01+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+45, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+45, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+45, 4, t_01+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+43, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+43, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+43, 4, t_01+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+41, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+41, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+41, 4, t_01+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+39, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+39, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+39, 4, t_01+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+37, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+37, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+37, 4, t_01+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+35, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+35, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+35, 4, t_01+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+33, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+33, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+33, 4, t_01+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+31, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+31, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+31, 4, t_01+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+29, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+29, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+29, 4, t_01+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+27, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+27, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+27, 4, t_01+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+25, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+25, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+25, 4, t_01+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+23, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+23, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+23, 4, t_01+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+21, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+21, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+21, 4, t_01+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+19, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+19, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+19, 4, t_01+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+17, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+17, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+17, 4, t_01+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+15, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+15, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+15, 4, t_01+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+13, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+13, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+13, 4, t_01+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+11, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+11, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+11, 4, t_01+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+9, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+9, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+9, 4, t_01+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+7, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+7, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+7, 4, t_01+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+5, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+5, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+5, 4, t_01+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+3, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+3, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+3, 4, t_01+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+0+1, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_01+0+1, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_01+0+1, 4, t_01+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+1, 2, t_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	memset(t_10+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(674, temp, 337, p_00+0+2, 337, q_10+0);
	GF2X_MUL(674, temp2, 337, p_10+0+2, 337, q_11+0);
	gf2x_add(674, t_10+0+2, 674, temp, 674, temp2);
	GF2X_MUL(4, temp, 2, q_10+0+335, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+335, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+335, 4, t_10+0+335, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+333, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+333, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+333, 4, t_10+0+333, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+331, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+331, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+331, 4, t_10+0+331, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+329, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+329, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+329, 4, t_10+0+329, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+327, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+327, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+327, 4, t_10+0+327, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+325, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+325, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+325, 4, t_10+0+325, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+323, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+323, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+323, 4, t_10+0+323, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+321, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+321, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+321, 4, t_10+0+321, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+319, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+319, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+319, 4, t_10+0+319, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+317, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+317, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+317, 4, t_10+0+317, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+315, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+315, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+315, 4, t_10+0+315, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+313, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+313, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+313, 4, t_10+0+313, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+311, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+311, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+311, 4, t_10+0+311, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+309, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+309, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+309, 4, t_10+0+309, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+307, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+307, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+307, 4, t_10+0+307, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+305, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+305, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+305, 4, t_10+0+305, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+303, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+303, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+303, 4, t_10+0+303, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+301, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+301, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+301, 4, t_10+0+301, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+299, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+299, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+299, 4, t_10+0+299, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+297, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+297, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+297, 4, t_10+0+297, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+295, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+295, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+295, 4, t_10+0+295, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+293, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+293, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+293, 4, t_10+0+293, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+291, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+291, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+291, 4, t_10+0+291, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+289, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+289, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+289, 4, t_10+0+289, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+287, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+287, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+287, 4, t_10+0+287, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+285, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+285, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+285, 4, t_10+0+285, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+283, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+283, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+283, 4, t_10+0+283, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+281, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+281, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+281, 4, t_10+0+281, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+279, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+279, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+279, 4, t_10+0+279, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+277, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+277, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+277, 4, t_10+0+277, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+275, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+275, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+275, 4, t_10+0+275, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+273, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+273, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+273, 4, t_10+0+273, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+271, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+271, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+271, 4, t_10+0+271, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+269, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+269, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+269, 4, t_10+0+269, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+267, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+267, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+267, 4, t_10+0+267, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+265, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+265, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+265, 4, t_10+0+265, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+263, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+263, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+263, 4, t_10+0+263, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+261, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+261, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+261, 4, t_10+0+261, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+259, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+259, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+259, 4, t_10+0+259, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+257, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+257, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+257, 4, t_10+0+257, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+255, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+255, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+255, 4, t_10+0+255, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+253, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+253, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+253, 4, t_10+0+253, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+251, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+251, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+251, 4, t_10+0+251, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+249, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+249, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+249, 4, t_10+0+249, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+247, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+247, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+247, 4, t_10+0+247, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+245, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+245, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+245, 4, t_10+0+245, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+243, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+243, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+243, 4, t_10+0+243, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+241, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+241, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+241, 4, t_10+0+241, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+239, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+239, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+239, 4, t_10+0+239, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+237, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+237, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+237, 4, t_10+0+237, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+235, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+235, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+235, 4, t_10+0+235, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+233, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+233, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+233, 4, t_10+0+233, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+231, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+231, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+231, 4, t_10+0+231, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+229, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+229, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+229, 4, t_10+0+229, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+227, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+227, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+227, 4, t_10+0+227, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+225, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+225, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+225, 4, t_10+0+225, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+223, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+223, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+223, 4, t_10+0+223, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+221, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+221, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+221, 4, t_10+0+221, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+219, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+219, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+219, 4, t_10+0+219, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+217, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+217, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+217, 4, t_10+0+217, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+215, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+215, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+215, 4, t_10+0+215, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+213, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+213, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+213, 4, t_10+0+213, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+211, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+211, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+211, 4, t_10+0+211, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+209, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+209, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+209, 4, t_10+0+209, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+207, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+207, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+207, 4, t_10+0+207, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+205, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+205, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+205, 4, t_10+0+205, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+203, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+203, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+203, 4, t_10+0+203, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+201, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+201, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+201, 4, t_10+0+201, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+199, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+199, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+199, 4, t_10+0+199, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+197, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+197, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+197, 4, t_10+0+197, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+195, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+195, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+195, 4, t_10+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+193, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+193, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+193, 4, t_10+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+191, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+191, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+191, 4, t_10+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+189, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+189, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+189, 4, t_10+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+187, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+187, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+187, 4, t_10+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+185, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+185, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+185, 4, t_10+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+183, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+183, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+183, 4, t_10+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+181, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+181, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+181, 4, t_10+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+179, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+179, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+179, 4, t_10+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+177, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+177, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+177, 4, t_10+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+175, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+175, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+175, 4, t_10+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+173, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+173, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+173, 4, t_10+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+171, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+171, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+171, 4, t_10+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+169, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+169, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+169, 4, t_10+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+167, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+167, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+167, 4, t_10+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+165, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+165, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+165, 4, t_10+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+163, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+163, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+163, 4, t_10+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+161, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+161, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+161, 4, t_10+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+159, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+159, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+159, 4, t_10+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+157, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+157, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+157, 4, t_10+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+155, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+155, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+155, 4, t_10+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+153, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+153, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+153, 4, t_10+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+151, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+151, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+151, 4, t_10+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+149, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+149, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+149, 4, t_10+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+147, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+147, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+147, 4, t_10+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+145, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+145, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+145, 4, t_10+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+143, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+143, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+143, 4, t_10+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+141, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+141, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+141, 4, t_10+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+139, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+139, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+139, 4, t_10+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+137, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+137, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+137, 4, t_10+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+135, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+135, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+135, 4, t_10+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+133, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+133, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+133, 4, t_10+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+131, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+131, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+131, 4, t_10+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+129, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+129, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+129, 4, t_10+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+127, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+127, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+127, 4, t_10+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+125, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+125, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+125, 4, t_10+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+123, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+123, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+123, 4, t_10+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+121, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+121, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+121, 4, t_10+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+119, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+119, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+119, 4, t_10+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+117, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+117, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+117, 4, t_10+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+115, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+115, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+115, 4, t_10+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+113, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+113, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+113, 4, t_10+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+111, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+111, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+111, 4, t_10+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+109, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+109, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+109, 4, t_10+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+107, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+107, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+107, 4, t_10+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+105, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+105, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+105, 4, t_10+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+103, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+103, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+103, 4, t_10+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+101, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+101, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+101, 4, t_10+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+99, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+99, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+99, 4, t_10+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+97, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+97, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+97, 4, t_10+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+95, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+95, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+95, 4, t_10+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+93, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+93, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+93, 4, t_10+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+91, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+91, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+91, 4, t_10+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+89, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+89, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+89, 4, t_10+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+87, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+87, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+87, 4, t_10+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+85, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+85, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+85, 4, t_10+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+83, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+83, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+83, 4, t_10+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+81, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+81, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+81, 4, t_10+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+79, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+79, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+79, 4, t_10+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+77, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+77, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+77, 4, t_10+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+75, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+75, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+75, 4, t_10+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+73, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+73, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+73, 4, t_10+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+71, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+71, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+71, 4, t_10+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+69, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+69, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+69, 4, t_10+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+67, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+67, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+67, 4, t_10+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+65, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+65, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+65, 4, t_10+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+63, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+63, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+63, 4, t_10+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+61, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+61, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+61, 4, t_10+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+59, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+59, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+59, 4, t_10+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+57, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+57, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+57, 4, t_10+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+55, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+55, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+55, 4, t_10+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+53, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+53, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+53, 4, t_10+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+51, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+51, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+51, 4, t_10+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+49, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+49, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+49, 4, t_10+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+47, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+47, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+47, 4, t_10+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+45, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+45, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+45, 4, t_10+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+43, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+43, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+43, 4, t_10+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+41, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+41, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+41, 4, t_10+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+39, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+39, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+39, 4, t_10+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+37, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+37, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+37, 4, t_10+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+35, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+35, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+35, 4, t_10+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+33, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+33, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+33, 4, t_10+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+31, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+31, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+31, 4, t_10+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+29, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+29, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+29, 4, t_10+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+27, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+27, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+27, 4, t_10+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+25, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+25, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+25, 4, t_10+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+23, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+23, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+23, 4, t_10+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+21, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+21, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+21, 4, t_10+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+19, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+19, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+19, 4, t_10+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+17, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+17, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+17, 4, t_10+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+15, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+15, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+15, 4, t_10+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+13, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+13, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+13, 4, t_10+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+11, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+11, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+11, 4, t_10+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+9, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+9, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+9, 4, t_10+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+7, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+7, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+7, 4, t_10+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+5, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+5, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+5, 4, t_10+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+3, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+3, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+3, 4, t_10+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+1, 2, p_00+0);
	GF2X_MUL(4, temp2, 2, q_11+0+1, 2, p_10+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_10+0+1, 4, t_10+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+1, 2, t_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	memset(t_11+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(674, temp, 337, p_01+0+2, 337, q_10+0);
	GF2X_MUL(674, temp2, 337, p_11+0+2, 337, q_11+0);
	gf2x_add(674, t_11+0+2, 674, temp, 674, temp2);
	GF2X_MUL(4, temp, 2, q_10+0+335, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+335, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+335, 4, t_11+0+335, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+333, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+333, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+333, 4, t_11+0+333, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+331, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+331, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+331, 4, t_11+0+331, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+329, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+329, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+329, 4, t_11+0+329, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+327, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+327, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+327, 4, t_11+0+327, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+325, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+325, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+325, 4, t_11+0+325, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+323, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+323, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+323, 4, t_11+0+323, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+321, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+321, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+321, 4, t_11+0+321, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+319, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+319, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+319, 4, t_11+0+319, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+317, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+317, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+317, 4, t_11+0+317, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+315, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+315, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+315, 4, t_11+0+315, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+313, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+313, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+313, 4, t_11+0+313, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+311, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+311, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+311, 4, t_11+0+311, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+309, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+309, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+309, 4, t_11+0+309, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+307, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+307, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+307, 4, t_11+0+307, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+305, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+305, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+305, 4, t_11+0+305, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+303, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+303, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+303, 4, t_11+0+303, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+301, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+301, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+301, 4, t_11+0+301, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+299, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+299, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+299, 4, t_11+0+299, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+297, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+297, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+297, 4, t_11+0+297, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+295, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+295, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+295, 4, t_11+0+295, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+293, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+293, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+293, 4, t_11+0+293, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+291, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+291, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+291, 4, t_11+0+291, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+289, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+289, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+289, 4, t_11+0+289, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+287, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+287, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+287, 4, t_11+0+287, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+285, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+285, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+285, 4, t_11+0+285, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+283, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+283, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+283, 4, t_11+0+283, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+281, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+281, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+281, 4, t_11+0+281, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+279, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+279, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+279, 4, t_11+0+279, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+277, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+277, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+277, 4, t_11+0+277, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+275, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+275, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+275, 4, t_11+0+275, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+273, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+273, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+273, 4, t_11+0+273, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+271, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+271, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+271, 4, t_11+0+271, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+269, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+269, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+269, 4, t_11+0+269, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+267, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+267, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+267, 4, t_11+0+267, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+265, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+265, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+265, 4, t_11+0+265, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+263, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+263, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+263, 4, t_11+0+263, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+261, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+261, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+261, 4, t_11+0+261, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+259, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+259, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+259, 4, t_11+0+259, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+257, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+257, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+257, 4, t_11+0+257, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+255, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+255, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+255, 4, t_11+0+255, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+253, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+253, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+253, 4, t_11+0+253, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+251, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+251, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+251, 4, t_11+0+251, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+249, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+249, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+249, 4, t_11+0+249, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+247, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+247, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+247, 4, t_11+0+247, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+245, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+245, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+245, 4, t_11+0+245, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+243, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+243, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+243, 4, t_11+0+243, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+241, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+241, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+241, 4, t_11+0+241, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+239, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+239, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+239, 4, t_11+0+239, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+237, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+237, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+237, 4, t_11+0+237, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+235, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+235, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+235, 4, t_11+0+235, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+233, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+233, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+233, 4, t_11+0+233, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+231, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+231, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+231, 4, t_11+0+231, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+229, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+229, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+229, 4, t_11+0+229, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+227, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+227, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+227, 4, t_11+0+227, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+225, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+225, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+225, 4, t_11+0+225, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+223, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+223, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+223, 4, t_11+0+223, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+221, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+221, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+221, 4, t_11+0+221, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+219, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+219, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+219, 4, t_11+0+219, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+217, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+217, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+217, 4, t_11+0+217, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+215, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+215, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+215, 4, t_11+0+215, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+213, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+213, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+213, 4, t_11+0+213, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+211, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+211, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+211, 4, t_11+0+211, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+209, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+209, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+209, 4, t_11+0+209, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+207, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+207, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+207, 4, t_11+0+207, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+205, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+205, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+205, 4, t_11+0+205, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+203, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+203, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+203, 4, t_11+0+203, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+201, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+201, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+201, 4, t_11+0+201, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+199, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+199, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+199, 4, t_11+0+199, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+197, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+197, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+197, 4, t_11+0+197, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+195, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+195, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+195, 4, t_11+0+195, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+193, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+193, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+193, 4, t_11+0+193, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+191, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+191, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+191, 4, t_11+0+191, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+189, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+189, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+189, 4, t_11+0+189, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+187, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+187, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+187, 4, t_11+0+187, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+185, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+185, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+185, 4, t_11+0+185, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+183, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+183, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+183, 4, t_11+0+183, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+181, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+181, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+181, 4, t_11+0+181, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+179, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+179, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+179, 4, t_11+0+179, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+177, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+177, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+177, 4, t_11+0+177, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+175, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+175, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+175, 4, t_11+0+175, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+173, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+173, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+173, 4, t_11+0+173, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+171, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+171, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+171, 4, t_11+0+171, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+169, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+169, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+169, 4, t_11+0+169, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+167, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+167, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+167, 4, t_11+0+167, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+165, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+165, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+165, 4, t_11+0+165, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+163, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+163, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+163, 4, t_11+0+163, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+161, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+161, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+161, 4, t_11+0+161, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+159, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+159, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+159, 4, t_11+0+159, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+157, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+157, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+157, 4, t_11+0+157, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+155, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+155, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+155, 4, t_11+0+155, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+153, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+153, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+153, 4, t_11+0+153, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+151, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+151, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+151, 4, t_11+0+151, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+149, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+149, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+149, 4, t_11+0+149, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+147, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+147, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+147, 4, t_11+0+147, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+145, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+145, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+145, 4, t_11+0+145, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+143, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+143, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+143, 4, t_11+0+143, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+141, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+141, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+141, 4, t_11+0+141, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+139, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+139, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+139, 4, t_11+0+139, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+137, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+137, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+137, 4, t_11+0+137, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+135, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+135, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+135, 4, t_11+0+135, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+133, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+133, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+133, 4, t_11+0+133, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+131, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+131, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+131, 4, t_11+0+131, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+129, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+129, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+129, 4, t_11+0+129, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+127, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+127, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+127, 4, t_11+0+127, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+125, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+125, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+125, 4, t_11+0+125, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+123, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+123, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+123, 4, t_11+0+123, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+121, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+121, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+121, 4, t_11+0+121, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+119, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+119, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+119, 4, t_11+0+119, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+117, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+117, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+117, 4, t_11+0+117, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+115, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+115, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+115, 4, t_11+0+115, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+113, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+113, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+113, 4, t_11+0+113, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+111, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+111, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+111, 4, t_11+0+111, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+109, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+109, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+109, 4, t_11+0+109, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+107, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+107, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+107, 4, t_11+0+107, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+105, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+105, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+105, 4, t_11+0+105, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+103, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+103, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+103, 4, t_11+0+103, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+101, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+101, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+101, 4, t_11+0+101, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+99, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+99, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+99, 4, t_11+0+99, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+97, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+97, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+97, 4, t_11+0+97, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+95, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+95, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+95, 4, t_11+0+95, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+93, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+93, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+93, 4, t_11+0+93, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+91, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+91, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+91, 4, t_11+0+91, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+89, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+89, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+89, 4, t_11+0+89, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+87, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+87, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+87, 4, t_11+0+87, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+85, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+85, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+85, 4, t_11+0+85, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+83, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+83, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+83, 4, t_11+0+83, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+81, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+81, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+81, 4, t_11+0+81, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+79, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+79, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+79, 4, t_11+0+79, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+77, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+77, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+77, 4, t_11+0+77, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+75, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+75, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+75, 4, t_11+0+75, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+73, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+73, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+73, 4, t_11+0+73, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+71, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+71, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+71, 4, t_11+0+71, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+69, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+69, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+69, 4, t_11+0+69, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+67, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+67, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+67, 4, t_11+0+67, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+65, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+65, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+65, 4, t_11+0+65, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+63, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+63, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+63, 4, t_11+0+63, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+61, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+61, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+61, 4, t_11+0+61, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+59, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+59, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+59, 4, t_11+0+59, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+57, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+57, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+57, 4, t_11+0+57, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+55, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+55, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+55, 4, t_11+0+55, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+53, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+53, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+53, 4, t_11+0+53, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+51, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+51, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+51, 4, t_11+0+51, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+49, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+49, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+49, 4, t_11+0+49, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+47, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+47, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+47, 4, t_11+0+47, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+45, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+45, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+45, 4, t_11+0+45, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+43, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+43, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+43, 4, t_11+0+43, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+41, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+41, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+41, 4, t_11+0+41, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+39, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+39, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+39, 4, t_11+0+39, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+37, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+37, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+37, 4, t_11+0+37, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+35, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+35, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+35, 4, t_11+0+35, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+33, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+33, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+33, 4, t_11+0+33, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+31, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+31, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+31, 4, t_11+0+31, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+29, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+29, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+29, 4, t_11+0+29, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+27, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+27, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+27, 4, t_11+0+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+25, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+25, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+25, 4, t_11+0+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+23, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+23, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+23, 4, t_11+0+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+21, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+21, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+21, 4, t_11+0+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+19, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+19, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+19, 4, t_11+0+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+17, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+17, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+17, 4, t_11+0+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+15, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+15, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+15, 4, t_11+0+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+13, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+13, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+13, 4, t_11+0+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+11, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+11, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+11, 4, t_11+0+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+9, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+9, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+9, 4, t_11+0+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+7, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+7, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+7, 4, t_11+0+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+5, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+5, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+5, 4, t_11+0+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+3, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+3, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+3, 4, t_11+0+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+0+1, 2, p_01+0);
	GF2X_MUL(4, temp2, 2, q_11+0+1, 2, p_11+0);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, t_11+0+1, 4, t_11+0+1, 4, temp);
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