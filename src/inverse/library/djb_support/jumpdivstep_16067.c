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

int jumpdivstep_16067(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[508];
	DIGIT p_01[508];
	DIGIT p_10[508];
	DIGIT p_11[508];
	
	DIGIT q_00[500];
	DIGIT q_01[500];
	DIGIT q_10[500];
	DIGIT q_11[500];
	
	DIGIT f_sum[1515];
	DIGIT g_sum[1515];
	
	DIGIT temp[1014];
	DIGIT recombine[1014];
	DIGIT temp2[1014];
	

	delta = divstepsx_256(255, delta, f+499, g+499, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f+495+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+495+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+495+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+495+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f+495+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+495+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+495+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+495+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f+487+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+487+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+487+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+487+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f+487+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+487+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+487+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+487+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f+471+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+471+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+471+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f+471+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+471+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+471+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f+439+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+439+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+439+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f+439+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+439+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+439+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f+375+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+375+64, 64, p_01+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+375+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(f_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f+375+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+375+64, 64, p_11+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+375+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(g_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, q_00+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, q_01+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, q_10+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, q_11+376+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_10+384);
	gf2x_add(128, p_00+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_11+384);
	gf2x_add(128, p_01+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_10+384);
	gf2x_add(128, p_10+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_11+384);
	gf2x_add(128, p_11+256+0, 128, temp, 128, temp2);
	

	// Calculating left operands: n: 16320, depth: 1
	memset(recombine, 0x00, 128*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, f+247+128, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+247+128, 128, p_01+256);
	gf2x_add(256, recombine+128, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+247+0, 128, p_01+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(256, recombine+0, 256, recombine+0, 256, temp);
	right_bit_shift_wide_n(384, recombine, 8160);
	memcpy(f_sum+759, recombine+256, 256*DIGIT_SIZE_B);
	memset(recombine, 0x00, 128*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, f+247+128, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+247+128, 128, p_11+256);
	gf2x_add(256, recombine+128, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247+0, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+247+0, 128, p_11+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(256, recombine+0, 256, recombine+0, 256, temp);
	right_bit_shift_wide_n(384, recombine, 8160);
	memcpy(g_sum+759, recombine+256, 256*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+883, g_sum+883, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+879+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+879+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+879+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+879+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+879+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+879+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+879+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+879+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+871+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+871+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+871+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+871+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+871+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+871+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+871+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+871+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+855+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+855+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+855+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+855+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+855+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+855+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+855+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+855+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+823+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+823+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+823+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+823+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+823+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+823+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+823+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+823+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+759+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+64, 64, p_01+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+759+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(f_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+759+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+64, 64, p_11+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+759+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(g_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, q_00+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, q_01+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, q_10+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, q_11+376+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_10+384);
	gf2x_add(128, q_00+248+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_11+384);
	gf2x_add(128, q_01+248+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_10+384);
	gf2x_add(128, q_10+248+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_11+384);
	gf2x_add(128, q_11+248+0, 128, temp, 128, temp2);
	

	// Recombining results: n: 16320, depth: 1
	GF2X_MUL(256, temp, 128, q_00+248+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_01+248+0, 128, p_10+256);
	gf2x_add(256, p_00+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_00+248+0, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_01+248+0, 128, p_11+256);
	gf2x_add(256, p_01+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+248+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_11+248+0, 128, p_10+256);
	gf2x_add(256, p_10+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+248+0, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_11+248+0, 128, p_11+256);
	gf2x_add(256, p_11+0+0, 256, temp, 256, temp2);
	

	// Calculating left operands: n: 32133, depth: 0
	memset(recombine, 0x00, 247*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, f+0+247, 256, p_00+0);
	GF2X_MUL(512, temp2, 256, g+0+247, 256, p_01+0);
	gf2x_add(512, recombine+247, 512, temp, 512, temp2);
	GF2X_MUL(494, temp, 247, p_00+0+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_01+0+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(494, recombine+9, 494, recombine+9, 494, temp);
	GF2X_MUL(18, temp, 9, f+0+238, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+238, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+238, 18, recombine+238, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+229, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+229, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+229, 18, recombine+229, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+220, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+220, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+220, 18, recombine+220, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+211, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+211, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+211, 18, recombine+211, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+202, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+202, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+202, 18, recombine+202, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+193, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+193, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+193, 18, recombine+193, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+184, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+184, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+184, 18, recombine+184, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+175, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+175, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+175, 18, recombine+175, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+166, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+166, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+166, 18, recombine+166, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+157, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+157, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+157, 18, recombine+157, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+148, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+148, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+148, 18, recombine+148, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+139, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+139, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+139, 18, recombine+139, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+130, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+130, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+130, 18, recombine+130, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+121, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+121, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+121, 18, recombine+121, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+112, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+112, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+112, 18, recombine+112, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+103, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+103, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+103, 18, recombine+103, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+94, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+94, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+94, 18, recombine+94, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+85, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+85, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+85, 18, recombine+85, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+76, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+76, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+76, 18, recombine+76, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+67, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+67, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+67, 18, recombine+67, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+58, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+58, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+58, 18, recombine+58, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+49, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+49, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+49, 18, recombine+49, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+40, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+40, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+40, 18, recombine+40, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+31, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+31, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+31, 18, recombine+31, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+22, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+22, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+22, 18, recombine+22, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+13, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+13, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+13, 18, recombine+13, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+4, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+4, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+4, 18, recombine+4, 18, temp);
	GF2X_MUL(8, temp, 4, p_00+0+5, 4, f+0);
	GF2X_MUL(8, temp2, 4, p_01+0+5, 4, g+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+5, 8, recombine+5, 8, temp);
	GF2X_MUL(8, temp, 4, p_00+0+1, 4, f+0);
	GF2X_MUL(8, temp2, 4, p_01+0+1, 4, g+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+1, 8, recombine+1, 8, temp);
	GF2X_MUL(2, temp, 1, f+0+3, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, g+0+3, 1, p_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+3, 2, recombine+3, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+2, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, g+0+2, 1, p_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+2, 2, recombine+2, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+1, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, g+0+1, 1, p_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, g+0+0, 1, p_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	right_bit_shift_wide_n(759, recombine, 16320);
	memcpy(f_sum+0, recombine+511, 503*DIGIT_SIZE_B);
	memset(recombine, 0x00, 247*DIGIT_SIZE_B);
	GF2X_MUL(512, temp, 256, f+0+247, 256, p_10+0);
	GF2X_MUL(512, temp2, 256, g+0+247, 256, p_11+0);
	gf2x_add(512, recombine+247, 512, temp, 512, temp2);
	GF2X_MUL(494, temp, 247, p_10+0+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_11+0+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(494, recombine+9, 494, recombine+9, 494, temp);
	GF2X_MUL(18, temp, 9, f+0+238, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+238, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+238, 18, recombine+238, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+229, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+229, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+229, 18, recombine+229, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+220, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+220, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+220, 18, recombine+220, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+211, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+211, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+211, 18, recombine+211, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+202, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+202, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+202, 18, recombine+202, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+193, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+193, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+193, 18, recombine+193, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+184, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+184, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+184, 18, recombine+184, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+175, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+175, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+175, 18, recombine+175, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+166, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+166, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+166, 18, recombine+166, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+157, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+157, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+157, 18, recombine+157, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+148, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+148, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+148, 18, recombine+148, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+139, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+139, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+139, 18, recombine+139, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+130, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+130, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+130, 18, recombine+130, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+121, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+121, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+121, 18, recombine+121, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+112, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+112, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+112, 18, recombine+112, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+103, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+103, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+103, 18, recombine+103, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+94, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+94, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+94, 18, recombine+94, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+85, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+85, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+85, 18, recombine+85, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+76, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+76, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+76, 18, recombine+76, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+67, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+67, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+67, 18, recombine+67, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+58, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+58, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+58, 18, recombine+58, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+49, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+49, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+49, 18, recombine+49, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+40, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+40, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+40, 18, recombine+40, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+31, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+31, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+31, 18, recombine+31, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+22, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+22, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+22, 18, recombine+22, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+13, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+13, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+13, 18, recombine+13, 18, temp);
	GF2X_MUL(18, temp, 9, f+0+4, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+4, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(18, recombine+4, 18, recombine+4, 18, temp);
	GF2X_MUL(8, temp, 4, p_10+0+5, 4, f+0);
	GF2X_MUL(8, temp2, 4, p_11+0+5, 4, g+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+5, 8, recombine+5, 8, temp);
	GF2X_MUL(8, temp, 4, p_10+0+1, 4, f+0);
	GF2X_MUL(8, temp2, 4, p_11+0+1, 4, g+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+1, 8, recombine+1, 8, temp);
	GF2X_MUL(2, temp, 1, f+0+3, 1, p_10+0);
	GF2X_MUL(2, temp2, 1, g+0+3, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+3, 2, recombine+3, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+2, 1, p_10+0);
	GF2X_MUL(2, temp2, 1, g+0+2, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+2, 2, recombine+2, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+1, 1, p_10+0);
	GF2X_MUL(2, temp2, 1, g+0+1, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, f+0+0, 1, p_10+0);
	GF2X_MUL(2, temp2, 1, g+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	right_bit_shift_wide_n(759, recombine, 16320);
	memcpy(g_sum+0, recombine+511, 503*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+244, g_sum+244, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+240+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+240+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+240+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+240+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+240+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+240+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+240+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+240+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+232+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+232+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+232+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+232+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+232+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+232+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+232+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+232+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+216+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+216+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+216+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+216+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+216+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+216+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+216+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+216+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+184+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+184+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+184+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+184+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+184+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+184+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+184+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+184+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+120+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+120+64, 64, p_01+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+120+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+120+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(f_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	memset(recombine, 0x00, 64*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+120+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+120+64, 64, p_11+384);
	gf2x_add(128, recombine+64, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+120+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+120+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(128, recombine+0, 128, recombine+0, 128, temp);
	right_bit_shift_wide_n(192, recombine, 4080);
	memcpy(g_sum+1143, recombine+128, 128*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1203, g_sum+1203, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1199+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1199+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1199+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1191+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1191+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1191+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1175+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1175+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1175+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1143+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, q_00+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, q_01+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, q_10+376+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, q_11+376+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_10+384);
	gf2x_add(128, p_00+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376+0, 64, p_11+384);
	gf2x_add(128, p_01+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_10+384);
	gf2x_add(128, p_10+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376+0, 64, p_11+384);
	gf2x_add(128, p_11+256+0, 128, temp, 128, temp2);
	

	// Calculating left operands: n: 15813, depth: 1
	memset(recombine, 0x00, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, f_sum+0+120, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g_sum+0+120, 128, p_01+256);
	gf2x_add(256, recombine+120, 256, temp, 256, temp2);
	GF2X_MUL(240, temp, 120, p_00+256+8, 120, f_sum+0);
	GF2X_MUL(240, temp2, 120, p_01+256+8, 120, g_sum+0);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(240, recombine+8, 240, recombine+8, 240, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+112, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+112, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+104, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+104, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+96, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+96, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+88, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+88, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+80, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+80, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+72, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+72, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+64, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+64, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+56, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+56, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+48, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+48, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+40, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+40, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+32, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+32, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+24, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+24, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+16, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+16, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+8, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+0, 8, p_01+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(376, recombine, 8160);
	memcpy(f_sum+759, recombine+256, 248*DIGIT_SIZE_B);
	memset(recombine, 0x00, 120*DIGIT_SIZE_B);
	GF2X_MUL(256, temp, 128, f_sum+0+120, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g_sum+0+120, 128, p_11+256);
	gf2x_add(256, recombine+120, 256, temp, 256, temp2);
	GF2X_MUL(240, temp, 120, p_10+256+8, 120, f_sum+0);
	GF2X_MUL(240, temp2, 120, p_11+256+8, 120, g_sum+0);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(240, recombine+8, 240, recombine+8, 240, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+112, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+112, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+104, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+104, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+96, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+96, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+88, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+88, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+80, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+80, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+72, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+72, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+64, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+64, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+56, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+56, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+48, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+48, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+40, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+40, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+32, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+32, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+24, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+24, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+16, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+16, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+8, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+8, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+0+0, 8, p_10+256);
	GF2X_MUL(16, temp2, 8, g_sum+0+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(376, recombine, 8160);
	memcpy(g_sum+759, recombine+256, 248*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+875, g_sum+875, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+871+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+871+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+871+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+871+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+871+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+871+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+871+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+871+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+863+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+863+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+863+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+863+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+863+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+863+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+863+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+863+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+847+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+847+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+847+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+847+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+847+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+847+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+847+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+847+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+815+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+815+32, 32, p_01+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+815+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+815+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	memset(recombine, 0x00, 32*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+815+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+815+32, 32, p_11+448);
	gf2x_add(64, recombine+32, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+815+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+815+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(64, recombine+0, 64, recombine+0, 64, temp);
	right_bit_shift_wide_n(96, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 64*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1363, g_sum+1363, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1359+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1359+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1359+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1351+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1351+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1351+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1335+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, q_00+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, q_01+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, q_10+440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, q_11+440+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 7653, depth: 2
	memset(recombine, 0x00, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+759+56, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+56, 64, p_01+384);
	gf2x_add(128, recombine+56, 128, temp, 128, temp2);
	GF2X_MUL(112, temp, 56, p_00+384+8, 56, f_sum+759);
	GF2X_MUL(112, temp2, 56, p_01+384+8, 56, g_sum+759);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(112, recombine+8, 112, recombine+8, 112, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+48, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+48, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+40, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+40, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+32, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+32, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+24, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+24, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+16, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+16, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+8, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+8, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+0, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+0, 8, p_01+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(184, recombine, 4080);
	memcpy(f_sum+1143, recombine+128, 120*DIGIT_SIZE_B);
	memset(recombine, 0x00, 56*DIGIT_SIZE_B);
	GF2X_MUL(128, temp, 64, f_sum+759+56, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+759+56, 64, p_11+384);
	gf2x_add(128, recombine+56, 128, temp, 128, temp2);
	GF2X_MUL(112, temp, 56, p_10+384+8, 56, f_sum+759);
	GF2X_MUL(112, temp2, 56, p_11+384+8, 56, g_sum+759);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(112, recombine+8, 112, recombine+8, 112, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+48, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+48, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+40, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+40, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+32, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+32, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+24, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+24, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+16, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+16, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+8, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+8, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+759+0, 8, p_10+384);
	GF2X_MUL(16, temp2, 8, g_sum+759+0, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(184, recombine, 4080);
	memcpy(g_sum+1143, recombine+128, 120*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1195, g_sum+1195, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1191+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1191+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1191+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1191+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1191+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1191+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1191+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1191+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1183+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1183+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1183+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1183+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1183+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1183+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1183+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1183+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1167+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1167+16, 16, p_01+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1167+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1167+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(f_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	memset(recombine, 0x00, 16*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1167+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1167+16, 16, p_11+480);
	gf2x_add(32, recombine+16, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1167+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1167+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(32, recombine+0, 32, recombine+0, 32, temp);
	right_bit_shift_wide_n(48, recombine, 1020);
	memcpy(g_sum+1431, recombine+32, 32*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1443, g_sum+1443, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1439+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1439+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1439+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1431+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, q_00+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, q_01+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, q_10+472+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, q_11+472+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3573, depth: 3
	memset(recombine, 0x00, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+24, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+24, 32, p_01+448);
	gf2x_add(64, recombine+24, 64, temp, 64, temp2);
	GF2X_MUL(48, temp, 24, p_00+448+8, 24, f_sum+1143);
	GF2X_MUL(48, temp2, 24, p_01+448+8, 24, g_sum+1143);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(48, recombine+8, 48, recombine+8, 48, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+16, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+16, 8, p_01+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+8, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+8, 8, p_01+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+0, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+0, 8, p_01+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(88, recombine, 2040);
	memcpy(f_sum+1335, recombine+64, 56*DIGIT_SIZE_B);
	memset(recombine, 0x00, 24*DIGIT_SIZE_B);
	GF2X_MUL(64, temp, 32, f_sum+1143+24, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1143+24, 32, p_11+448);
	gf2x_add(64, recombine+24, 64, temp, 64, temp2);
	GF2X_MUL(48, temp, 24, p_10+448+8, 24, f_sum+1143);
	GF2X_MUL(48, temp2, 24, p_11+448+8, 24, g_sum+1143);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(48, recombine+8, 48, recombine+8, 48, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+16, 8, p_10+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+16, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+8, 8, p_10+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+8, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1143+0, 8, p_10+448);
	GF2X_MUL(16, temp2, 8, g_sum+1143+0, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(88, recombine, 2040);
	memcpy(g_sum+1335, recombine+64, 56*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1355, g_sum+1355, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1351+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1351+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1351+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1351+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1351+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1351+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1351+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1351+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1343+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1343+8, 8, p_01+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1343+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1343+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1343+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1343+8, 8, p_11+496);
	gf2x_add(16, recombine+8, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1343+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1343+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(24, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 16*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1483, g_sum+1483, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1479+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1479+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1479+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, q_00+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, q_01+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, q_10+488+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, q_11+488+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+488+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+488+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+488+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1533, depth: 4
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+8, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+8, 16, p_01+480);
	gf2x_add(32, recombine+8, 32, temp, 32, temp2);
	GF2X_MUL(16, temp, 8, p_00+480+8, 8, f_sum+1335);
	GF2X_MUL(16, temp2, 8, p_01+480+8, 8, g_sum+1335);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1335+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1335+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(40, recombine, 1020);
	memcpy(f_sum+1431, recombine+31, 24*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, f_sum+1335+8, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1335+8, 16, p_11+480);
	gf2x_add(32, recombine+8, 32, temp, 32, temp2);
	GF2X_MUL(16, temp, 8, p_10+480+8, 8, f_sum+1335);
	GF2X_MUL(16, temp2, 8, p_11+480+8, 8, g_sum+1335);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, f_sum+1335+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1335+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	right_bit_shift_wide_n(40, recombine, 1020);
	memcpy(g_sum+1431, recombine+31, 24*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1436, g_sum+1436, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1432+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1432+4, 4, p_01+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1432+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1432+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(f_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	memset(recombine, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, f_sum+1432+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1432+4, 4, p_11+504);
	gf2x_add(8, recombine+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1432+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1432+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, recombine+0, 8, recombine+0, 8, temp);
	right_bit_shift_wide_n(12, recombine, 255);
	memcpy(g_sum+1503, recombine+8, 8*DIGIT_SIZE_B);
	

	delta = divstepsx_256(255, delta, f_sum+1503, g_sum+1503, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+496+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+496+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+496+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 513, depth: 5
	memset(recombine, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+1, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+1, 8, p_01+496);
	gf2x_add(16, recombine+1, 16, temp, 16, temp2);
	GF2X_MUL(2, temp, 1, p_00+496+7, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+7, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+7, 2, recombine+7, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+6, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+6, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+6, 2, recombine+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+5, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+5, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+5, 2, recombine+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+4, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+4, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+4, 2, recombine+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+3, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+3, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+3, 2, recombine+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+2, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+2, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+2, 2, recombine+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+1, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_01+496+1, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, f_sum+1431+0, 1, p_00+496);
	GF2X_MUL(2, temp2, 1, g_sum+1431+0, 1, p_01+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	right_bit_shift_wide_n(17, recombine, 510);
	memcpy(f_sum+1479, recombine+16, 9*DIGIT_SIZE_B);
	memset(recombine, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, f_sum+1431+1, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1431+1, 8, p_11+496);
	gf2x_add(16, recombine+1, 16, temp, 16, temp2);
	GF2X_MUL(2, temp, 1, p_10+496+7, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+7, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+7, 2, recombine+7, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+6, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+6, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+6, 2, recombine+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+5, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+5, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+5, 2, recombine+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+4, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+4, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+4, 2, recombine+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+3, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+3, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+3, 2, recombine+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+2, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+2, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+2, 2, recombine+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_10+496+1, 1, f_sum+1431);
	GF2X_MUL(2, temp2, 1, p_11+496+1, 1, g_sum+1431);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, f_sum+1431+0, 1, p_10+496);
	GF2X_MUL(2, temp2, 1, g_sum+1431+0, 1, p_11+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	right_bit_shift_wide_n(17, recombine, 510);
	memcpy(g_sum+1479, recombine+16, 9*DIGIT_SIZE_B);
	

	delta = divstepsx(3, delta, *(f_sum+1479), *(g_sum+1479), q_00+488, q_01+488, q_10+488, q_11+488);

	// Recombining results: n: 513, depth: 5
	memset(q_00+472, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+496+7, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+7, 1, q_01+488);
	gf2x_add(2, q_00+472+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+496+6, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+6, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+6, 2, q_00+472+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+5, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+5, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+5, 2, q_00+472+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+4, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+4, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+4, 2, q_00+472+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+3, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+3, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+3, 2, q_00+472+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+2, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+2, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+2, 2, q_00+472+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+1, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_10+496+1, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+1, 2, q_00+472+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+488+0, 1, p_00+496);
	GF2X_MUL(2, temp2, 1, q_01+488+0, 1, p_10+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472+0, 2, q_00+472+0, 2, temp);
	memset(q_01+472, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+496+7, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+7, 1, q_01+488);
	gf2x_add(2, q_01+472+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+496+6, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+6, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+6, 2, q_01+472+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+5, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+5, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+5, 2, q_01+472+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+4, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+4, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+4, 2, q_01+472+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+3, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+3, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+3, 2, q_01+472+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+2, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+2, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+2, 2, q_01+472+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+1, 1, q_00+488);
	GF2X_MUL(2, temp2, 1, p_11+496+1, 1, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+1, 2, q_01+472+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+488+0, 1, p_01+496);
	GF2X_MUL(2, temp2, 1, q_01+488+0, 1, p_11+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472+0, 2, q_01+472+0, 2, temp);
	memset(q_10+472, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_00+496+7, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+7, 1, q_11+488);
	gf2x_add(2, q_10+472+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_00+496+6, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+6, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+6, 2, q_10+472+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+5, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+5, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+5, 2, q_10+472+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+4, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+4, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+4, 2, q_10+472+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+3, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+3, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+3, 2, q_10+472+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+2, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+2, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+2, 2, q_10+472+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+496+1, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_10+496+1, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+1, 2, q_10+472+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+488+0, 1, p_00+496);
	GF2X_MUL(2, temp2, 1, q_11+488+0, 1, p_10+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472+0, 2, q_10+472+0, 2, temp);
	memset(q_11+472, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(2, temp, 1, p_01+496+7, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+7, 1, q_11+488);
	gf2x_add(2, q_11+472+7, 2, temp, 2, temp2);
	GF2X_MUL(2, temp, 1, p_01+496+6, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+6, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+6, 2, q_11+472+6, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+5, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+5, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+5, 2, q_11+472+5, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+4, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+4, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+4, 2, q_11+472+4, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+3, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+3, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+3, 2, q_11+472+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+2, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+2, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+2, 2, q_11+472+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+496+1, 1, q_10+488);
	GF2X_MUL(2, temp2, 1, p_11+496+1, 1, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+1, 2, q_11+472+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+488+0, 1, p_01+496);
	GF2X_MUL(2, temp2, 1, q_11+488+0, 1, p_11+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472+0, 2, q_11+472+0, 2, temp);
	

	// Recombining results: n: 1533, depth: 4
	memset(recombine, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+480+7, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_10+480+7, 9, q_01+472);
	gf2x_add(18, recombine+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+472+2, 7, p_00+480);
	GF2X_MUL(14, temp2, 7, q_01+472+2, 7, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, recombine+2, 14, recombine+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+480+5, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+5, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+5, 4, recombine+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+3, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+3, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+3, 4, recombine+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+1, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+1, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+1, 4, recombine+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+472+1, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_01+472+1, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+472+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_01+472+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	memcpy(q_00+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(recombine, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+480+7, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_11+480+7, 9, q_01+472);
	gf2x_add(18, recombine+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+472+2, 7, p_01+480);
	GF2X_MUL(14, temp2, 7, q_01+472+2, 7, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, recombine+2, 14, recombine+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+480+5, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+5, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+5, 4, recombine+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+3, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+3, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+3, 4, recombine+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+1, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+1, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+1, 4, recombine+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+472+1, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_01+472+1, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+472+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_01+472+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	memcpy(q_01+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(recombine, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+480+7, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_10+480+7, 9, q_11+472);
	gf2x_add(18, recombine+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+472+2, 7, p_00+480);
	GF2X_MUL(14, temp2, 7, q_11+472+2, 7, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, recombine+2, 14, recombine+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+480+5, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+5, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+5, 4, recombine+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+3, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+3, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+3, 4, recombine+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+1, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+1, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+1, 4, recombine+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+472+1, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_11+472+1, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+472+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_11+472+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	memcpy(q_10+440, recombine+1, 24*DIGIT_SIZE_B);
	memset(recombine, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+480+7, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_11+480+7, 9, q_11+472);
	gf2x_add(18, recombine+7, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+472+2, 7, p_01+480);
	GF2X_MUL(14, temp2, 7, q_11+472+2, 7, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, recombine+2, 14, recombine+2, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+480+5, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+5, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+5, 4, recombine+5, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+3, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+3, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+3, 4, recombine+3, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+1, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+1, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, recombine+1, 4, recombine+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+472+1, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_11+472+1, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+1, 2, recombine+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+472+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_11+472+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, recombine+0, 2, recombine+0, 2, temp);
	memcpy(q_11+440, recombine+1, 24*DIGIT_SIZE_B);
	

	// Recombining results: n: 3573, depth: 3
	memset(q_00+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+448+8, 24, q_00+440);
	GF2X_MUL(48, temp2, 24, p_10+448+8, 24, q_01+440);
	gf2x_add(48, q_00+376+8, 48, temp, 48, temp2);
	GF2X_MUL(16, temp, 8, q_00+440+16, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_01+440+16, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+376+16, 16, q_00+376+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+440+8, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_01+440+8, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+376+8, 16, q_00+376+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+440+0, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_01+440+0, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+376+0, 16, q_00+376+0, 16, temp);
	memset(q_01+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+448+8, 24, q_00+440);
	GF2X_MUL(48, temp2, 24, p_11+448+8, 24, q_01+440);
	gf2x_add(48, q_01+376+8, 48, temp, 48, temp2);
	GF2X_MUL(16, temp, 8, q_00+440+16, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_01+440+16, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+376+16, 16, q_01+376+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+440+8, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_01+440+8, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+376+8, 16, q_01+376+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+440+0, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_01+440+0, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+376+0, 16, q_01+376+0, 16, temp);
	memset(q_10+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+448+8, 24, q_10+440);
	GF2X_MUL(48, temp2, 24, p_10+448+8, 24, q_11+440);
	gf2x_add(48, q_10+376+8, 48, temp, 48, temp2);
	GF2X_MUL(16, temp, 8, q_10+440+16, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_11+440+16, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+376+16, 16, q_10+376+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+440+8, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_11+440+8, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+376+8, 16, q_10+376+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+440+0, 8, p_00+448);
	GF2X_MUL(16, temp2, 8, q_11+440+0, 8, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+376+0, 16, q_10+376+0, 16, temp);
	memset(q_11+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+448+8, 24, q_10+440);
	GF2X_MUL(48, temp2, 24, p_11+448+8, 24, q_11+440);
	gf2x_add(48, q_11+376+8, 48, temp, 48, temp2);
	GF2X_MUL(16, temp, 8, q_10+440+16, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_11+440+16, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+376+16, 16, q_11+376+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+440+8, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_11+440+8, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+376+8, 16, q_11+376+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+440+0, 8, p_01+448);
	GF2X_MUL(16, temp2, 8, q_11+440+0, 8, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+376+0, 16, q_11+376+0, 16, temp);
	

	// Recombining results: n: 7653, depth: 2
	memset(q_00+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+384+8, 56, q_00+376);
	GF2X_MUL(112, temp2, 56, p_10+384+8, 56, q_01+376);
	gf2x_add(112, q_00+248+8, 112, temp, 112, temp2);
	GF2X_MUL(16, temp, 8, q_00+376+48, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+48, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+48, 16, q_00+248+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+40, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+40, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+40, 16, q_00+248+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+32, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+32, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+32, 16, q_00+248+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+24, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+24, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+24, 16, q_00+248+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+16, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+16, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+16, 16, q_00+248+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+8, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+8, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+8, 16, q_00+248+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+0, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_01+376+0, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248+0, 16, q_00+248+0, 16, temp);
	memset(q_01+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+384+8, 56, q_00+376);
	GF2X_MUL(112, temp2, 56, p_11+384+8, 56, q_01+376);
	gf2x_add(112, q_01+248+8, 112, temp, 112, temp2);
	GF2X_MUL(16, temp, 8, q_00+376+48, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+48, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+48, 16, q_01+248+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+40, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+40, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+40, 16, q_01+248+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+32, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+32, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+32, 16, q_01+248+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+24, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+24, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+24, 16, q_01+248+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+16, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+16, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+16, 16, q_01+248+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+8, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+8, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+8, 16, q_01+248+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+376+0, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_01+376+0, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248+0, 16, q_01+248+0, 16, temp);
	memset(q_10+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+384+8, 56, q_10+376);
	GF2X_MUL(112, temp2, 56, p_10+384+8, 56, q_11+376);
	gf2x_add(112, q_10+248+8, 112, temp, 112, temp2);
	GF2X_MUL(16, temp, 8, q_10+376+48, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+48, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+48, 16, q_10+248+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+40, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+40, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+40, 16, q_10+248+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+32, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+32, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+32, 16, q_10+248+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+24, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+24, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+24, 16, q_10+248+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+16, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+16, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+16, 16, q_10+248+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+8, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+8, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+8, 16, q_10+248+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+0, 8, p_00+384);
	GF2X_MUL(16, temp2, 8, q_11+376+0, 8, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248+0, 16, q_10+248+0, 16, temp);
	memset(q_11+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+384+8, 56, q_10+376);
	GF2X_MUL(112, temp2, 56, p_11+384+8, 56, q_11+376);
	gf2x_add(112, q_11+248+8, 112, temp, 112, temp2);
	GF2X_MUL(16, temp, 8, q_10+376+48, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+48, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+48, 16, q_11+248+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+40, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+40, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+40, 16, q_11+248+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+32, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+32, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+32, 16, q_11+248+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+24, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+24, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+24, 16, q_11+248+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+16, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+16, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+16, 16, q_11+248+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+8, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+8, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+8, 16, q_11+248+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+376+0, 8, p_01+384);
	GF2X_MUL(16, temp2, 8, q_11+376+0, 8, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248+0, 16, q_11+248+0, 16, temp);
	

	// Recombining results: n: 15813, depth: 1
	memset(q_00+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+256+8, 120, q_00+248);
	GF2X_MUL(240, temp2, 120, p_10+256+8, 120, q_01+248);
	gf2x_add(240, q_00+0+8, 240, temp, 240, temp2);
	GF2X_MUL(16, temp, 8, q_00+248+112, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+112, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+112, 16, q_00+0+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+104, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+104, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+104, 16, q_00+0+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+96, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+96, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+96, 16, q_00+0+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+88, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+88, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+88, 16, q_00+0+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+80, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+80, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+80, 16, q_00+0+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+72, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+72, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+72, 16, q_00+0+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+64, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+64, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+64, 16, q_00+0+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+56, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+56, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+56, 16, q_00+0+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+48, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+48, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+48, 16, q_00+0+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+40, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+40, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+40, 16, q_00+0+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+32, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+32, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+32, 16, q_00+0+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+24, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+24, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+24, 16, q_00+0+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+16, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+16, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+16, 16, q_00+0+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+8, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+8, 16, q_00+0+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_01+248+0, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0+0, 16, q_00+0+0, 16, temp);
	memset(q_01+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+256+8, 120, q_00+248);
	GF2X_MUL(240, temp2, 120, p_11+256+8, 120, q_01+248);
	gf2x_add(240, q_01+0+8, 240, temp, 240, temp2);
	GF2X_MUL(16, temp, 8, q_00+248+112, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+112, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+112, 16, q_01+0+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+104, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+104, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+104, 16, q_01+0+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+96, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+96, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+96, 16, q_01+0+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+88, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+88, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+88, 16, q_01+0+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+80, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+80, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+80, 16, q_01+0+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+72, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+72, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+72, 16, q_01+0+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+64, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+64, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+64, 16, q_01+0+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+56, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+56, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+56, 16, q_01+0+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+48, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+48, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+48, 16, q_01+0+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+40, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+40, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+40, 16, q_01+0+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+32, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+32, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+32, 16, q_01+0+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+24, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+24, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+24, 16, q_01+0+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+16, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+16, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+16, 16, q_01+0+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+8, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+8, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+8, 16, q_01+0+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+248+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_01+248+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0+0, 16, q_01+0+0, 16, temp);
	memset(q_10+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+256+8, 120, q_10+248);
	GF2X_MUL(240, temp2, 120, p_10+256+8, 120, q_11+248);
	gf2x_add(240, q_10+0+8, 240, temp, 240, temp2);
	GF2X_MUL(16, temp, 8, q_10+248+112, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+112, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+112, 16, q_10+0+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+104, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+104, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+104, 16, q_10+0+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+96, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+96, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+96, 16, q_10+0+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+88, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+88, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+88, 16, q_10+0+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+80, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+80, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+80, 16, q_10+0+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+72, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+72, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+72, 16, q_10+0+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+64, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+64, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+64, 16, q_10+0+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+56, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+56, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+56, 16, q_10+0+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+48, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+48, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+48, 16, q_10+0+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+40, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+40, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+40, 16, q_10+0+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+32, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+32, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+32, 16, q_10+0+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+24, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+24, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+24, 16, q_10+0+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+16, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+16, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+16, 16, q_10+0+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+8, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+8, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+8, 16, q_10+0+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+0, 8, p_00+256);
	GF2X_MUL(16, temp2, 8, q_11+248+0, 8, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0+0, 16, q_10+0+0, 16, temp);
	memset(q_11+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+256+8, 120, q_10+248);
	GF2X_MUL(240, temp2, 120, p_11+256+8, 120, q_11+248);
	gf2x_add(240, q_11+0+8, 240, temp, 240, temp2);
	GF2X_MUL(16, temp, 8, q_10+248+112, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+112, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+112, 16, q_11+0+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+104, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+104, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+104, 16, q_11+0+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+96, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+96, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+96, 16, q_11+0+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+88, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+88, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+88, 16, q_11+0+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+80, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+80, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+80, 16, q_11+0+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+72, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+72, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+72, 16, q_11+0+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+64, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+64, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+64, 16, q_11+0+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+56, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+56, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+56, 16, q_11+0+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+48, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+48, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+48, 16, q_11+0+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+40, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+40, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+40, 16, q_11+0+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+32, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+32, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+32, 16, q_11+0+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+24, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+24, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+24, 16, q_11+0+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+16, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+16, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+16, 16, q_11+0+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+8, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+8, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+8, 16, q_11+0+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+248+0, 8, p_01+256);
	GF2X_MUL(16, temp2, 8, q_11+248+0, 8, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0+0, 16, q_11+0+0, 16, temp);
	

	// Recombining results: n: 32133, depth: 0
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+0+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_10+0+8, 248, q_01+0);
	gf2x_add(496, recombine+8, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_00+0+240, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+240, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+240, 16, recombine+240, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+232, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+232, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+232, 16, recombine+232, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+224, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+224, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+224, 16, recombine+224, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+216, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+216, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+216, 16, recombine+216, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+208, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+208, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+208, 16, recombine+208, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+200, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+200, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+200, 16, recombine+200, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+192, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+192, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+192, 16, recombine+192, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+184, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+184, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+184, 16, recombine+184, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+176, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+176, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+176, 16, recombine+176, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+168, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+168, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+168, 16, recombine+168, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+160, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+160, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+160, 16, recombine+160, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+152, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+152, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+152, 16, recombine+152, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+144, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+144, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+144, 16, recombine+144, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+136, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+136, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+136, 16, recombine+136, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+128, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+128, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+128, 16, recombine+128, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+120, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+120, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+120, 16, recombine+120, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+112, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+112, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+104, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+104, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+96, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+96, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+88, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+88, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+80, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+80, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+72, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+72, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+64, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+64, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+56, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+56, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+48, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+48, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+40, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+40, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+32, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+32, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+24, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+24, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+16, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+16, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+8, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+8, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+0, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+0, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	memcpy(t_00+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+0+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_11+0+8, 248, q_01+0);
	gf2x_add(496, recombine+8, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_00+0+240, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+240, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+240, 16, recombine+240, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+232, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+232, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+232, 16, recombine+232, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+224, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+224, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+224, 16, recombine+224, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+216, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+216, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+216, 16, recombine+216, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+208, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+208, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+208, 16, recombine+208, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+200, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+200, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+200, 16, recombine+200, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+192, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+192, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+192, 16, recombine+192, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+184, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+184, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+184, 16, recombine+184, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+176, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+176, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+176, 16, recombine+176, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+168, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+168, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+168, 16, recombine+168, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+160, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+160, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+160, 16, recombine+160, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+152, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+152, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+152, 16, recombine+152, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+144, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+144, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+144, 16, recombine+144, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+136, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+136, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+136, 16, recombine+136, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+128, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+128, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+128, 16, recombine+128, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+120, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+120, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+120, 16, recombine+120, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+112, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+112, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+104, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+104, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+96, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+96, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+88, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+88, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+80, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+80, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+72, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+72, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+64, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+64, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+56, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+56, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+48, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+48, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+40, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+40, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+32, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+32, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+24, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+24, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+16, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+16, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+8, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+8, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+0, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+0, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	memcpy(t_01+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+0+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_10+0+8, 248, q_11+0);
	gf2x_add(496, recombine+8, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_10+0+240, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+240, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+240, 16, recombine+240, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+232, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+232, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+232, 16, recombine+232, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+224, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+224, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+224, 16, recombine+224, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+216, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+216, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+216, 16, recombine+216, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+208, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+208, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+208, 16, recombine+208, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+200, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+200, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+200, 16, recombine+200, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+192, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+192, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+192, 16, recombine+192, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+184, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+184, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+184, 16, recombine+184, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+176, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+176, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+176, 16, recombine+176, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+168, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+168, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+168, 16, recombine+168, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+160, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+160, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+160, 16, recombine+160, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+152, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+152, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+152, 16, recombine+152, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+144, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+144, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+144, 16, recombine+144, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+136, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+136, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+136, 16, recombine+136, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+128, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+128, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+128, 16, recombine+128, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+120, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+120, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+120, 16, recombine+120, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+112, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+112, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+104, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+104, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+96, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+96, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+88, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+88, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+80, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+80, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+72, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+72, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+64, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+64, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+56, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+56, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+48, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+48, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+40, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+40, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+32, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+32, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+24, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+24, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+16, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+16, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+8, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+8, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+0, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+0, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	memcpy(t_10+0, recombine+1, 503*DIGIT_SIZE_B);
	memset(recombine, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+0+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_11+0+8, 248, q_11+0);
	gf2x_add(496, recombine+8, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_10+0+240, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+240, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+240, 16, recombine+240, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+232, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+232, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+232, 16, recombine+232, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+224, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+224, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+224, 16, recombine+224, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+216, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+216, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+216, 16, recombine+216, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+208, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+208, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+208, 16, recombine+208, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+200, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+200, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+200, 16, recombine+200, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+192, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+192, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+192, 16, recombine+192, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+184, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+184, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+184, 16, recombine+184, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+176, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+176, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+176, 16, recombine+176, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+168, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+168, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+168, 16, recombine+168, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+160, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+160, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+160, 16, recombine+160, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+152, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+152, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+152, 16, recombine+152, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+144, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+144, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+144, 16, recombine+144, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+136, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+136, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+136, 16, recombine+136, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+128, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+128, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+128, 16, recombine+128, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+120, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+120, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+120, 16, recombine+120, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+112, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+112, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+112, 16, recombine+112, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+104, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+104, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+104, 16, recombine+104, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+96, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+96, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+96, 16, recombine+96, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+88, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+88, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+88, 16, recombine+88, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+80, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+80, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+80, 16, recombine+80, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+72, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+72, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+72, 16, recombine+72, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+64, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+64, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+64, 16, recombine+64, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+56, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+56, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+56, 16, recombine+56, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+48, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+48, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+48, 16, recombine+48, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+40, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+40, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+40, 16, recombine+40, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+32, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+32, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+32, 16, recombine+32, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+24, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+24, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+24, 16, recombine+24, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+16, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+16, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+16, 16, recombine+16, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+8, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+8, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+8, 16, recombine+8, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+0, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+0, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, recombine+0, 16, recombine+0, 16, temp);
	memcpy(t_11+0, recombine+1, 503*DIGIT_SIZE_B);
	

	return delta;
}