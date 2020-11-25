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

int jumpdivstep_16229(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[508];
	DIGIT p_01[508];
	DIGIT p_10[508];
	DIGIT p_11[508];
	
	DIGIT q_00[505];
	DIGIT q_01[505];
	DIGIT q_10[505];
	DIGIT q_11[505];
	
	DIGIT f_sum[1528];
	DIGIT g_sum[1528];
	
	DIGIT temp[1019];
	DIGIT temp2[1019];
	

	delta = divstepsx_256(255, delta, f+504, g+504, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+500+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+500+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+500+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+500+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f+500+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+500+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+500+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+500+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+492+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+492+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+492+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+492+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f+492+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+492+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+492+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+492+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+476+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+476+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+476+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+476+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f+476+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+476+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+476+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+476+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f+444+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+444+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+444+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+444+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f+444+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+444+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+444+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+444+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f+380+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+380+64, 64, p_01+384);
	gf2x_add(128, f_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+380+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+380+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1150, 64, f_sum+1150, 64, temp+64);
	right_bit_shift_n(128, f_sum+1150, 48);
	GF2X_MUL(128, temp, 64, f+380+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+380+64, 64, p_11+384);
	gf2x_add(128, g_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+380+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+380+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1150, 64, g_sum+1150, 64, temp+64);
	right_bit_shift_n(128, g_sum+1150, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1211, g_sum+1211, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, q_00+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, q_01+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, q_10+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, q_11+381+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_10+384);
	gf2x_add(128, p_00+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_11+384);
	gf2x_add(128, p_01+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_10+384);
	gf2x_add(128, p_10+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_11+384);
	gf2x_add(128, p_11+256+0, 128, temp, 128, temp2);
	

	// Calculating left operands: n: 16320, depth: 1
	// Digits to shift: 127
	// Displacement: 128
	GF2X_MUL(256, temp, 128, f+252+128, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+252+128, 128, p_01+256);
	gf2x_add(256, f_sum+765+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+252+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+252+0, 128, p_01+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, f_sum+765, 128, f_sum+765, 128, temp+128);
	right_bit_shift_n(256, f_sum+765, 32);
	GF2X_MUL(256, temp, 128, f+252+128, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+252+128, 128, p_11+256);
	gf2x_add(256, g_sum+765+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+252+0, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+252+0, 128, p_11+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, g_sum+765, 128, g_sum+765, 128, temp+128);
	right_bit_shift_n(256, g_sum+765, 32);
	

	delta = divstepsx_256(255, delta, f_sum+890, g_sum+890, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+886+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+886+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+886+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+886+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+886+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+886+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+886+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+886+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+878+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+878+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+878+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+878+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+878+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+878+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+878+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+878+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+862+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+862+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+862+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+862+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+862+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+862+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+862+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+862+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+830+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+830+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+830+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+830+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+830+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+830+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+830+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+830+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+766+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+64, 64, p_01+384);
	gf2x_add(128, f_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+766+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1150, 64, f_sum+1150, 64, temp+64);
	right_bit_shift_n(128, f_sum+1150, 48);
	GF2X_MUL(128, temp, 64, f_sum+766+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+64, 64, p_11+384);
	gf2x_add(128, g_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+766+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1150, 64, g_sum+1150, 64, temp+64);
	right_bit_shift_n(128, g_sum+1150, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1211, g_sum+1211, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, q_00+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, q_01+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, q_10+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, q_11+381+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_10+384);
	gf2x_add(128, q_00+253+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_11+384);
	gf2x_add(128, q_01+253+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_10+384);
	gf2x_add(128, q_10+253+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_11+384);
	gf2x_add(128, q_11+253+0, 128, temp, 128, temp2);
	

	// Recombining results: n: 16320, depth: 1
	GF2X_MUL(256, temp, 128, q_00+253+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_01+253+0, 128, p_10+256);
	gf2x_add(256, p_00+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_00+253+0, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_01+253+0, 128, p_11+256);
	gf2x_add(256, p_01+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+253+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_11+253+0, 128, p_10+256);
	gf2x_add(256, p_10+0+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+253+0, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_11+253+0, 128, p_11+256);
	gf2x_add(256, p_11+0+0, 256, temp, 256, temp2);
	

	// Calculating left operands: n: 32457, depth: 0
	// Digits to shift: 255
	// Displacement: 255
	GF2X_MUL(512, temp, 256, f+0+252, 256, p_00+0);
	GF2X_MUL(512, temp2, 256, g+0+252, 256, p_01+0);
	gf2x_add(509, f_sum+0, 509, temp+3, 509, temp2+3);
	GF2X_MUL(504, temp, 252, p_00+0+4, 252, f+0);
	GF2X_MUL(504, temp2, 252, p_01+0+4, 252, g+0);
	gf2x_add(504, temp, 504, temp, 504, temp2);
	gf2x_add(253, f_sum+0, 253, f_sum+0, 253, temp+251);
	GF2X_MUL(8, temp, 4, f+0+248, 4, p_00+0);
	GF2X_MUL(8, temp2, 4, g+0+248, 4, p_01+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+7);
	right_bit_shift_n(508, f_sum+0, 0);
	GF2X_MUL(512, temp, 256, f+0+252, 256, p_10+0);
	GF2X_MUL(512, temp2, 256, g+0+252, 256, p_11+0);
	gf2x_add(509, g_sum+0, 509, temp+3, 509, temp2+3);
	GF2X_MUL(504, temp, 252, p_10+0+4, 252, f+0);
	GF2X_MUL(504, temp2, 252, p_11+0+4, 252, g+0);
	gf2x_add(504, temp, 504, temp, 504, temp2);
	gf2x_add(253, g_sum+0, 253, g_sum+0, 253, temp+251);
	GF2X_MUL(8, temp, 4, f+0+248, 4, p_10+0);
	GF2X_MUL(8, temp2, 4, g+0+248, 4, p_11+0);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+7);
	right_bit_shift_n(508, g_sum+0, 0);
	

	delta = divstepsx_256(255, delta, f_sum+250, g_sum+250, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+246+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+246+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+246+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+246+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+246+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+246+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+246+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+246+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+238+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+238+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+238+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+238+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+238+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+238+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+238+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+238+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+222+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+222+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+222+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+222+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+222+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+222+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+222+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+222+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+190+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+190+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+190+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+190+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+190+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+190+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+190+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+190+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 8160, depth: 2
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+126+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+126+64, 64, p_01+384);
	gf2x_add(128, f_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+126+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+126+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1150, 64, f_sum+1150, 64, temp+64);
	right_bit_shift_n(128, f_sum+1150, 48);
	GF2X_MUL(128, temp, 64, f_sum+126+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+126+64, 64, p_11+384);
	gf2x_add(128, g_sum+1150+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+126+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+126+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1150, 64, g_sum+1150, 64, temp+64);
	right_bit_shift_n(128, g_sum+1150, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1211, g_sum+1211, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1207+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1207+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1207+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1199+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1199+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1199+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1183+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1183+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1183+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+1151+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1151+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, q_00+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, q_01+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, q_10+381+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, q_11+381+0, 64, temp, 64, temp2);
	

	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_10+384);
	gf2x_add(128, p_00+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+381+0, 64, p_11+384);
	gf2x_add(128, p_01+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_10+384);
	gf2x_add(128, p_10+256+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+381+0, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+381+0, 64, p_11+384);
	gf2x_add(128, p_11+256+0, 128, temp, 128, temp2);
	

	// Calculating left operands: n: 16137, depth: 1
	// Digits to shift: 127
	// Displacement: 128
	GF2X_MUL(256, temp, 128, f_sum+1+125, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g_sum+1+125, 128, p_01+256);
	gf2x_add(253, f_sum+765, 253, temp+3, 253, temp2+3);
	GF2X_MUL(250, temp, 125, p_00+256+3, 125, f_sum+1);
	GF2X_MUL(250, temp2, 125, p_01+256+3, 125, g_sum+1);
	gf2x_add(250, temp, 250, temp, 250, temp2);
	gf2x_add(125, f_sum+765, 125, f_sum+765, 125, temp+125);
	right_bit_shift_n(253, f_sum+765, 32);
	GF2X_MUL(256, temp, 128, f_sum+1+125, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g_sum+1+125, 128, p_11+256);
	gf2x_add(253, g_sum+765, 253, temp+3, 253, temp2+3);
	GF2X_MUL(250, temp, 125, p_10+256+3, 125, f_sum+1);
	GF2X_MUL(250, temp2, 125, p_11+256+3, 125, g_sum+1);
	gf2x_add(250, temp, 250, temp, 250, temp2);
	gf2x_add(125, g_sum+765, 125, g_sum+765, 125, temp+125);
	right_bit_shift_n(253, g_sum+765, 32);
	

	delta = divstepsx_256(255, delta, f_sum+887, g_sum+887, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+883+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+883+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+883+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+883+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+883+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+883+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+883+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+883+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+875+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+875+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+875+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+875+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+875+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+875+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+875+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+875+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+859+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+859+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+859+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+859+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+859+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+859+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+859+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+859+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 4080, depth: 3
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+827+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+827+32, 32, p_01+448);
	gf2x_add(64, f_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+827+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+827+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1343, 32, f_sum+1343, 32, temp+32);
	right_bit_shift_n(64, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+827+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+827+32, 32, p_11+448);
	gf2x_add(64, g_sum+1343+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+827+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+827+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1343, 32, g_sum+1343, 32, temp+32);
	right_bit_shift_n(64, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1372, g_sum+1372, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1368+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1368+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1368+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1360+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1360+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1360+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1344+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, q_00+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, q_01+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, q_10+445+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, q_11+445+0, 32, temp, 32, temp2);
	

	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_10+448);
	gf2x_add(64, p_00+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+445+0, 32, p_11+448);
	gf2x_add(64, p_01+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_10+448);
	gf2x_add(64, p_10+384+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+445+0, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+445+0, 32, p_11+448);
	gf2x_add(64, p_11+384+0, 64, temp, 64, temp2);
	

	// Calculating left operands: n: 7977, depth: 2
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+766+61, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+61, 64, p_01+384);
	gf2x_add(125, f_sum+1150, 125, temp+3, 125, temp2+3);
	GF2X_MUL(122, temp, 61, p_00+384+3, 61, f_sum+766);
	GF2X_MUL(122, temp2, 61, p_01+384+3, 61, g_sum+766);
	gf2x_add(122, temp, 122, temp, 122, temp2);
	gf2x_add(61, f_sum+1150, 61, f_sum+1150, 61, temp+61);
	right_bit_shift_n(125, f_sum+1150, 48);
	GF2X_MUL(128, temp, 64, f_sum+766+61, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+766+61, 64, p_11+384);
	gf2x_add(125, g_sum+1150, 125, temp+3, 125, temp2+3);
	GF2X_MUL(122, temp, 61, p_10+384+3, 61, f_sum+766);
	GF2X_MUL(122, temp2, 61, p_11+384+3, 61, g_sum+766);
	gf2x_add(122, temp, 122, temp, 122, temp2);
	gf2x_add(61, g_sum+1150, 61, g_sum+1150, 61, temp+61);
	right_bit_shift_n(125, g_sum+1150, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1208, g_sum+1208, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1204+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1204+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1204+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1204+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1204+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1204+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1204+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1204+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1196+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1196+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1196+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1196+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1196+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1196+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1196+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1196+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 2040, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1180+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1180+16, 16, p_01+480);
	gf2x_add(32, f_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1180+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1180+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1440, 16, f_sum+1440, 16, temp+16);
	right_bit_shift_n(32, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1180+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1180+16, 16, p_11+480);
	gf2x_add(32, g_sum+1440+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1180+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1180+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1440, 16, g_sum+1440, 16, temp+16);
	right_bit_shift_n(32, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1453, g_sum+1453, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1449+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1449+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1449+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1441+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, q_00+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, q_01+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, q_10+477+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, q_11+477+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_10+480);
	gf2x_add(32, p_00+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+477+0, 16, p_11+480);
	gf2x_add(32, p_01+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_10+480);
	gf2x_add(32, p_10+448+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+477+0, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+477+0, 16, p_11+480);
	gf2x_add(32, p_11+448+0, 32, temp, 32, temp2);
	

	// Calculating left operands: n: 3897, depth: 3
	// Digits to shift: 31
	// Displacement: 31
	GF2X_MUL(64, temp, 32, f_sum+1151+29, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+29, 32, p_01+448);
	gf2x_add(62, f_sum+1343, 62, temp+2, 62, temp2+2);
	GF2X_MUL(58, temp, 29, p_00+448+3, 29, f_sum+1151);
	GF2X_MUL(58, temp2, 29, p_01+448+3, 29, g_sum+1151);
	gf2x_add(58, temp, 58, temp, 58, temp2);
	gf2x_add(30, f_sum+1343, 30, f_sum+1343, 30, temp+28);
	GF2X_MUL(6, temp, 3, f_sum+1151+26, 3, p_00+448);
	GF2X_MUL(6, temp2, 3, g_sum+1151+26, 3, p_01+448);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, f_sum+1343, 1, f_sum+1343, 1, temp+5);
	right_bit_shift_n(61, f_sum+1343, 56);
	GF2X_MUL(64, temp, 32, f_sum+1151+29, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1151+29, 32, p_11+448);
	gf2x_add(62, g_sum+1343, 62, temp+2, 62, temp2+2);
	GF2X_MUL(58, temp, 29, p_10+448+3, 29, f_sum+1151);
	GF2X_MUL(58, temp2, 29, p_11+448+3, 29, g_sum+1151);
	gf2x_add(58, temp, 58, temp, 58, temp2);
	gf2x_add(30, g_sum+1343, 30, g_sum+1343, 30, temp+28);
	GF2X_MUL(6, temp, 3, f_sum+1151+26, 3, p_10+448);
	GF2X_MUL(6, temp2, 3, g_sum+1151+26, 3, p_11+448);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(1, g_sum+1343, 1, g_sum+1343, 1, temp+5);
	right_bit_shift_n(61, g_sum+1343, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1370, g_sum+1370, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1366+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1366+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1366+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1366+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1366+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1366+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1366+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1366+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1358+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1358+8, 8, p_01+496);
	gf2x_add(16, f_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1358+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1358+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1489, 8, f_sum+1489, 8, temp+8);
	right_bit_shift_n(16, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1358+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1358+8, 8, p_11+496);
	gf2x_add(16, g_sum+1489+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1358+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1358+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1489, 8, g_sum+1489, 8, temp+8);
	right_bit_shift_n(16, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1494, g_sum+1494, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1490+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, q_00+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, q_01+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, q_10+493+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, q_11+493+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_10+496);
	gf2x_add(16, p_00+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_01+493+0, 8, p_11+496);
	gf2x_add(16, p_01+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_10+496);
	gf2x_add(16, p_10+480+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+493+0, 8, p_01+496);
	GF2X_MUL(16, temp2, 8, q_11+493+0, 8, p_11+496);
	gf2x_add(16, p_11+480+0, 16, temp, 16, temp2);
	

	// Calculating left operands: n: 1857, depth: 4
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1344+14, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+14, 16, p_01+480);
	gf2x_add(30, f_sum+1440, 30, temp+2, 30, temp2+2);
	GF2X_MUL(28, temp, 14, p_00+480+2, 14, f_sum+1344);
	GF2X_MUL(28, temp2, 14, p_01+480+2, 14, g_sum+1344);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, f_sum+1440, 14, f_sum+1440, 14, temp+14);
	right_bit_shift_n(30, f_sum+1440, 60);
	GF2X_MUL(32, temp, 16, f_sum+1344+14, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1344+14, 16, p_11+480);
	gf2x_add(30, g_sum+1440, 30, temp+2, 30, temp2+2);
	GF2X_MUL(28, temp, 14, p_10+480+2, 14, f_sum+1344);
	GF2X_MUL(28, temp2, 14, p_11+480+2, 14, g_sum+1344);
	gf2x_add(28, temp, 28, temp, 28, temp2);
	gf2x_add(14, g_sum+1440, 14, g_sum+1440, 14, temp+14);
	right_bit_shift_n(30, g_sum+1440, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1451, g_sum+1451, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1447+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1447+4, 4, p_01+504);
	gf2x_add(8, f_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1447+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1447+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1514, 4, f_sum+1514, 4, temp+4);
	right_bit_shift_n(8, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1447+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1447+4, 4, p_11+504);
	gf2x_add(8, g_sum+1514+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1447+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1447+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1514, 4, g_sum+1514, 4, temp+4);
	right_bit_shift_n(8, g_sum+1514, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_10+504);
	gf2x_add(8, p_00+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_01+501+0, 4, p_11+504);
	gf2x_add(8, p_01+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_10+504);
	gf2x_add(8, p_10+496+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+501+0, 4, p_01+504);
	GF2X_MUL(8, temp2, 4, q_11+501+0, 4, p_11+504);
	gf2x_add(8, p_11+496+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 837, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1441+6, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+6, 8, p_01+496);
	gf2x_add(14, f_sum+1489, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_00+496+2, 6, f_sum+1441);
	GF2X_MUL(12, temp2, 6, p_01+496+2, 6, g_sum+1441);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, f_sum+1489, 6, f_sum+1489, 6, temp+6);
	right_bit_shift_n(14, f_sum+1489, 62);
	GF2X_MUL(16, temp, 8, f_sum+1441+6, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1441+6, 8, p_11+496);
	gf2x_add(14, g_sum+1489, 14, temp+2, 14, temp2+2);
	GF2X_MUL(12, temp, 6, p_10+496+2, 6, f_sum+1441);
	GF2X_MUL(12, temp2, 6, p_11+496+2, 6, g_sum+1441);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(6, g_sum+1489, 6, g_sum+1489, 6, temp+6);
	right_bit_shift_n(14, g_sum+1489, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1492, g_sum+1492, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 327, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1490+2, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+2, 4, p_01+504);
	gf2x_add(6, f_sum+1514, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_00+504+2, 2, f_sum+1490);
	GF2X_MUL(4, temp2, 2, p_01+504+2, 2, g_sum+1490);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, f_sum+1514, 2, f_sum+1514, 2, temp+2);
	right_bit_shift_n(6, f_sum+1514, 63);
	GF2X_MUL(8, temp, 4, f_sum+1490+2, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1490+2, 4, p_11+504);
	gf2x_add(6, g_sum+1514, 6, temp+2, 6, temp2+2);
	GF2X_MUL(4, temp, 2, p_10+504+2, 2, f_sum+1490);
	GF2X_MUL(4, temp2, 2, p_11+504+2, 2, g_sum+1490);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(2, g_sum+1514, 2, g_sum+1514, 2, temp+2);
	right_bit_shift_n(6, g_sum+1514, 63);
	

	delta = divstepsx_128(72, delta, f_sum+1515, g_sum+1515, q_00+501, q_01+501, q_10+501, q_11+501);

	// Recombining results: n: 327, depth: 6
	memset(q_00+493, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+504+2, 2, q_00+501);
	GF2X_MUL(4, temp2, 2, p_10+504+2, 2, q_01+501);
	gf2x_add(4, q_00+493+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+501+0, 2, p_00+504);
	GF2X_MUL(4, temp2, 2, q_01+501+0, 2, p_10+504);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+493+0, 4, q_00+493+0, 4, temp);
	memset(q_01+493, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+504+2, 2, q_00+501);
	GF2X_MUL(4, temp2, 2, p_11+504+2, 2, q_01+501);
	gf2x_add(4, q_01+493+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_00+501+0, 2, p_01+504);
	GF2X_MUL(4, temp2, 2, q_01+501+0, 2, p_11+504);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+493+0, 4, q_01+493+0, 4, temp);
	memset(q_10+493, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_00+504+2, 2, q_10+501);
	GF2X_MUL(4, temp2, 2, p_10+504+2, 2, q_11+501);
	gf2x_add(4, q_10+493+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+501+0, 2, p_00+504);
	GF2X_MUL(4, temp2, 2, q_11+501+0, 2, p_10+504);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+493+0, 4, q_10+493+0, 4, temp);
	memset(q_11+493, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(4, temp, 2, p_01+504+2, 2, q_10+501);
	GF2X_MUL(4, temp2, 2, p_11+504+2, 2, q_11+501);
	gf2x_add(4, q_11+493+2, 4, temp, 4, temp2);
	GF2X_MUL(4, temp, 2, q_10+501+0, 2, p_01+504);
	GF2X_MUL(4, temp2, 2, q_11+501+0, 2, p_11+504);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+493+0, 4, q_11+493+0, 4, temp);
	

	// Recombining results: n: 837, depth: 5
	memset(q_00+477, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+496+2, 6, q_00+493);
	GF2X_MUL(12, temp2, 6, p_10+496+2, 6, q_01+493);
	gf2x_add(12, q_00+477+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+493+4, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_01+493+4, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+477+4, 4, q_00+477+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+493+2, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_01+493+2, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+477+2, 4, q_00+477+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+493+0, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_01+493+0, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+477+0, 4, q_00+477+0, 4, temp);
	memset(q_01+477, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+496+2, 6, q_00+493);
	GF2X_MUL(12, temp2, 6, p_11+496+2, 6, q_01+493);
	gf2x_add(12, q_01+477+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_00+493+4, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_01+493+4, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+477+4, 4, q_01+477+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+493+2, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_01+493+2, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+477+2, 4, q_01+477+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+493+0, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_01+493+0, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+477+0, 4, q_01+477+0, 4, temp);
	memset(q_10+477, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_00+496+2, 6, q_10+493);
	GF2X_MUL(12, temp2, 6, p_10+496+2, 6, q_11+493);
	gf2x_add(12, q_10+477+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+493+4, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_11+493+4, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+477+4, 4, q_10+477+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+493+2, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_11+493+2, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+477+2, 4, q_10+477+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+493+0, 2, p_00+496);
	GF2X_MUL(4, temp2, 2, q_11+493+0, 2, p_10+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+477+0, 4, q_10+477+0, 4, temp);
	memset(q_11+477, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(12, temp, 6, p_01+496+2, 6, q_10+493);
	GF2X_MUL(12, temp2, 6, p_11+496+2, 6, q_11+493);
	gf2x_add(12, q_11+477+2, 12, temp, 12, temp2);
	GF2X_MUL(4, temp, 2, q_10+493+4, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_11+493+4, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+477+4, 4, q_11+477+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+493+2, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_11+493+2, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+477+2, 4, q_11+477+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+493+0, 2, p_01+496);
	GF2X_MUL(4, temp2, 2, q_11+493+0, 2, p_11+496);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+477+0, 4, q_11+477+0, 4, temp);
	

	// Recombining results: n: 1857, depth: 4
	memset(q_00+445, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+480+2, 14, q_00+477);
	GF2X_MUL(28, temp2, 14, p_10+480+2, 14, q_01+477);
	gf2x_add(28, q_00+445+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_00+477+12, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+12, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+12, 4, q_00+445+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+10, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+10, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+10, 4, q_00+445+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+8, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+8, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+8, 4, q_00+445+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+6, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+6, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+6, 4, q_00+445+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+4, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+4, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+4, 4, q_00+445+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+2, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+2, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+2, 4, q_00+445+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+0, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_01+477+0, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+445+0, 4, q_00+445+0, 4, temp);
	memset(q_01+445, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+480+2, 14, q_00+477);
	GF2X_MUL(28, temp2, 14, p_11+480+2, 14, q_01+477);
	gf2x_add(28, q_01+445+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_00+477+12, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+12, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+12, 4, q_01+445+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+10, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+10, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+10, 4, q_01+445+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+8, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+8, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+8, 4, q_01+445+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+6, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+6, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+6, 4, q_01+445+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+4, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+4, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+4, 4, q_01+445+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+2, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+2, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+2, 4, q_01+445+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+477+0, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_01+477+0, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+445+0, 4, q_01+445+0, 4, temp);
	memset(q_10+445, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_00+480+2, 14, q_10+477);
	GF2X_MUL(28, temp2, 14, p_10+480+2, 14, q_11+477);
	gf2x_add(28, q_10+445+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_10+477+12, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+12, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+12, 4, q_10+445+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+10, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+10, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+10, 4, q_10+445+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+8, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+8, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+8, 4, q_10+445+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+6, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+6, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+6, 4, q_10+445+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+4, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+4, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+4, 4, q_10+445+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+2, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+2, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+2, 4, q_10+445+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+0, 2, p_00+480);
	GF2X_MUL(4, temp2, 2, q_11+477+0, 2, p_10+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+445+0, 4, q_10+445+0, 4, temp);
	memset(q_11+445, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(28, temp, 14, p_01+480+2, 14, q_10+477);
	GF2X_MUL(28, temp2, 14, p_11+480+2, 14, q_11+477);
	gf2x_add(28, q_11+445+2, 28, temp, 28, temp2);
	GF2X_MUL(4, temp, 2, q_10+477+12, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+12, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+12, 4, q_11+445+12, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+10, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+10, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+10, 4, q_11+445+10, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+8, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+8, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+8, 4, q_11+445+8, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+6, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+6, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+6, 4, q_11+445+6, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+4, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+4, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+4, 4, q_11+445+4, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+2, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+2, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+2, 4, q_11+445+2, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+477+0, 2, p_01+480);
	GF2X_MUL(4, temp2, 2, q_11+477+0, 2, p_11+480);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+445+0, 4, q_11+445+0, 4, temp);
	

	// Recombining results: n: 3897, depth: 3
	memset(q_00+381, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_00+448+2, 30, q_00+445);
	GF2X_MUL(60, temp2, 30, p_10+448+2, 30, q_01+445);
	gf2x_add(60, q_00+381+1, 60, temp, 60, temp2);
	GF2X_MUL(4, temp, 2, q_00+445+28, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+28, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+27, 4, q_00+381+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+26, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+26, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+25, 4, q_00+381+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+24, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+24, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+23, 4, q_00+381+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+22, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+22, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+21, 4, q_00+381+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+20, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+20, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+19, 4, q_00+381+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+18, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+18, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+17, 4, q_00+381+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+16, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+16, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+15, 4, q_00+381+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+14, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+14, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+13, 4, q_00+381+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+12, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+12, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+11, 4, q_00+381+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+10, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+10, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+9, 4, q_00+381+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+8, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+8, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+7, 4, q_00+381+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+6, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+6, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+5, 4, q_00+381+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+4, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+4, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+3, 4, q_00+381+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+2, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+2, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+381+1, 4, q_00+381+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+0, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_01+445+0, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_00+381, 3, q_00+381, 3, temp+1);
	memset(q_01+381, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_01+448+2, 30, q_00+445);
	GF2X_MUL(60, temp2, 30, p_11+448+2, 30, q_01+445);
	gf2x_add(60, q_01+381+1, 60, temp, 60, temp2);
	GF2X_MUL(4, temp, 2, q_00+445+28, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+28, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+27, 4, q_01+381+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+26, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+26, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+25, 4, q_01+381+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+24, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+24, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+23, 4, q_01+381+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+22, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+22, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+21, 4, q_01+381+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+20, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+20, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+19, 4, q_01+381+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+18, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+18, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+17, 4, q_01+381+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+16, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+16, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+15, 4, q_01+381+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+14, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+14, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+13, 4, q_01+381+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+12, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+12, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+11, 4, q_01+381+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+10, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+10, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+9, 4, q_01+381+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+8, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+8, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+7, 4, q_01+381+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+6, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+6, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+5, 4, q_01+381+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+4, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+4, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+3, 4, q_01+381+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+2, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+2, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+381+1, 4, q_01+381+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_00+445+0, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_01+445+0, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_01+381, 3, q_01+381, 3, temp+1);
	memset(q_10+381, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_00+448+2, 30, q_10+445);
	GF2X_MUL(60, temp2, 30, p_10+448+2, 30, q_11+445);
	gf2x_add(60, q_10+381+1, 60, temp, 60, temp2);
	GF2X_MUL(4, temp, 2, q_10+445+28, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+28, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+27, 4, q_10+381+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+26, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+26, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+25, 4, q_10+381+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+24, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+24, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+23, 4, q_10+381+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+22, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+22, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+21, 4, q_10+381+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+20, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+20, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+19, 4, q_10+381+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+18, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+18, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+17, 4, q_10+381+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+16, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+16, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+15, 4, q_10+381+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+14, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+14, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+13, 4, q_10+381+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+12, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+12, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+11, 4, q_10+381+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+10, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+10, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+9, 4, q_10+381+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+8, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+8, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+7, 4, q_10+381+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+6, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+6, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+5, 4, q_10+381+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+4, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+4, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+3, 4, q_10+381+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+2, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+2, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+381+1, 4, q_10+381+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+0, 2, p_00+448);
	GF2X_MUL(4, temp2, 2, q_11+445+0, 2, p_10+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_10+381, 3, q_10+381, 3, temp+1);
	memset(q_11+381, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(60, temp, 30, p_01+448+2, 30, q_10+445);
	GF2X_MUL(60, temp2, 30, p_11+448+2, 30, q_11+445);
	gf2x_add(60, q_11+381+1, 60, temp, 60, temp2);
	GF2X_MUL(4, temp, 2, q_10+445+28, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+28, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+27, 4, q_11+381+27, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+26, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+26, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+25, 4, q_11+381+25, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+24, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+24, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+23, 4, q_11+381+23, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+22, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+22, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+21, 4, q_11+381+21, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+20, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+20, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+19, 4, q_11+381+19, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+18, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+18, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+17, 4, q_11+381+17, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+16, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+16, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+15, 4, q_11+381+15, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+14, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+14, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+13, 4, q_11+381+13, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+12, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+12, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+11, 4, q_11+381+11, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+10, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+10, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+9, 4, q_11+381+9, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+8, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+8, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+7, 4, q_11+381+7, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+6, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+6, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+5, 4, q_11+381+5, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+4, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+4, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+3, 4, q_11+381+3, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+2, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+2, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+381+1, 4, q_11+381+1, 4, temp);
	GF2X_MUL(4, temp, 2, q_10+445+0, 2, p_01+448);
	GF2X_MUL(4, temp2, 2, q_11+445+0, 2, p_11+448);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(3, q_11+381, 3, q_11+381, 3, temp+1);
	

	// Recombining results: n: 7977, depth: 2
	memset(q_00+253, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, p_00+384+3, 61, q_00+381);
	GF2X_MUL(122, temp2, 61, p_10+384+3, 61, q_01+381);
	gf2x_add(122, q_00+253+3, 122, temp, 122, temp2);
	GF2X_MUL(6, temp, 3, q_00+381+58, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+58, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+58, 6, q_00+253+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+55, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+55, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+55, 6, q_00+253+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+52, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+52, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+52, 6, q_00+253+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+49, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+49, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+49, 6, q_00+253+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+46, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+46, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+46, 6, q_00+253+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+43, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+43, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+43, 6, q_00+253+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+40, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+40, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+40, 6, q_00+253+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+37, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+37, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+37, 6, q_00+253+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+34, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+34, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+34, 6, q_00+253+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+31, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+31, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+31, 6, q_00+253+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+28, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+28, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+28, 6, q_00+253+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+25, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+25, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+25, 6, q_00+253+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+22, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+22, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+22, 6, q_00+253+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+19, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+19, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+19, 6, q_00+253+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+16, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+16, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+16, 6, q_00+253+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+13, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+13, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+13, 6, q_00+253+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+10, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+10, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+10, 6, q_00+253+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+7, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+7, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+7, 6, q_00+253+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+4, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+4, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+4, 6, q_00+253+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+1, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_01+381+1, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+253+1, 6, q_00+253+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+384+2, 1, q_00+381);
	GF2X_MUL(2, temp2, 1, p_10+384+2, 1, q_01+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+253+2, 2, q_00+253+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+384+1, 1, q_00+381);
	GF2X_MUL(2, temp2, 1, p_10+384+1, 1, q_01+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+253+1, 2, q_00+253+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+381+0, 1, p_00+384);
	GF2X_MUL(2, temp2, 1, q_01+381+0, 1, p_10+384);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+253+0, 2, q_00+253+0, 2, temp);
	memset(q_01+253, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, p_01+384+3, 61, q_00+381);
	GF2X_MUL(122, temp2, 61, p_11+384+3, 61, q_01+381);
	gf2x_add(122, q_01+253+3, 122, temp, 122, temp2);
	GF2X_MUL(6, temp, 3, q_00+381+58, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+58, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+58, 6, q_01+253+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+55, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+55, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+55, 6, q_01+253+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+52, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+52, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+52, 6, q_01+253+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+49, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+49, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+49, 6, q_01+253+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+46, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+46, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+46, 6, q_01+253+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+43, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+43, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+43, 6, q_01+253+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+40, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+40, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+40, 6, q_01+253+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+37, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+37, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+37, 6, q_01+253+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+34, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+34, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+34, 6, q_01+253+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+31, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+31, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+31, 6, q_01+253+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+28, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+28, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+28, 6, q_01+253+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+25, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+25, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+25, 6, q_01+253+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+22, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+22, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+22, 6, q_01+253+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+19, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+19, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+19, 6, q_01+253+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+16, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+16, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+16, 6, q_01+253+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+13, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+13, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+13, 6, q_01+253+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+10, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+10, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+10, 6, q_01+253+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+7, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+7, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+7, 6, q_01+253+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+4, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+4, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+4, 6, q_01+253+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+381+1, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_01+381+1, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+253+1, 6, q_01+253+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+384+2, 1, q_00+381);
	GF2X_MUL(2, temp2, 1, p_11+384+2, 1, q_01+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+253+2, 2, q_01+253+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+384+1, 1, q_00+381);
	GF2X_MUL(2, temp2, 1, p_11+384+1, 1, q_01+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+253+1, 2, q_01+253+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+381+0, 1, p_01+384);
	GF2X_MUL(2, temp2, 1, q_01+381+0, 1, p_11+384);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+253+0, 2, q_01+253+0, 2, temp);
	memset(q_10+253, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, p_00+384+3, 61, q_10+381);
	GF2X_MUL(122, temp2, 61, p_10+384+3, 61, q_11+381);
	gf2x_add(122, q_10+253+3, 122, temp, 122, temp2);
	GF2X_MUL(6, temp, 3, q_10+381+58, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+58, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+58, 6, q_10+253+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+55, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+55, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+55, 6, q_10+253+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+52, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+52, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+52, 6, q_10+253+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+49, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+49, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+49, 6, q_10+253+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+46, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+46, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+46, 6, q_10+253+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+43, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+43, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+43, 6, q_10+253+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+40, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+40, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+40, 6, q_10+253+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+37, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+37, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+37, 6, q_10+253+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+34, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+34, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+34, 6, q_10+253+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+31, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+31, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+31, 6, q_10+253+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+28, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+28, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+28, 6, q_10+253+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+25, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+25, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+25, 6, q_10+253+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+22, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+22, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+22, 6, q_10+253+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+19, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+19, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+19, 6, q_10+253+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+16, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+16, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+16, 6, q_10+253+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+13, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+13, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+13, 6, q_10+253+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+10, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+10, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+10, 6, q_10+253+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+7, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+7, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+7, 6, q_10+253+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+4, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+4, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+4, 6, q_10+253+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+1, 3, p_00+384);
	GF2X_MUL(6, temp2, 3, q_11+381+1, 3, p_10+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+253+1, 6, q_10+253+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+384+2, 1, q_10+381);
	GF2X_MUL(2, temp2, 1, p_10+384+2, 1, q_11+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+253+2, 2, q_10+253+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+384+1, 1, q_10+381);
	GF2X_MUL(2, temp2, 1, p_10+384+1, 1, q_11+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+253+1, 2, q_10+253+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+381+0, 1, p_00+384);
	GF2X_MUL(2, temp2, 1, q_11+381+0, 1, p_10+384);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+253+0, 2, q_10+253+0, 2, temp);
	memset(q_11+253, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(122, temp, 61, p_01+384+3, 61, q_10+381);
	GF2X_MUL(122, temp2, 61, p_11+384+3, 61, q_11+381);
	gf2x_add(122, q_11+253+3, 122, temp, 122, temp2);
	GF2X_MUL(6, temp, 3, q_10+381+58, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+58, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+58, 6, q_11+253+58, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+55, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+55, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+55, 6, q_11+253+55, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+52, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+52, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+52, 6, q_11+253+52, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+49, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+49, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+49, 6, q_11+253+49, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+46, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+46, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+46, 6, q_11+253+46, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+43, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+43, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+43, 6, q_11+253+43, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+40, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+40, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+40, 6, q_11+253+40, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+37, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+37, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+37, 6, q_11+253+37, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+34, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+34, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+34, 6, q_11+253+34, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+31, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+31, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+31, 6, q_11+253+31, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+28, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+28, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+28, 6, q_11+253+28, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+25, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+25, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+25, 6, q_11+253+25, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+22, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+22, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+22, 6, q_11+253+22, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+19, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+19, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+19, 6, q_11+253+19, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+16, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+16, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+16, 6, q_11+253+16, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+13, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+13, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+13, 6, q_11+253+13, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+10, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+10, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+10, 6, q_11+253+10, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+7, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+7, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+7, 6, q_11+253+7, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+4, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+4, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+4, 6, q_11+253+4, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+381+1, 3, p_01+384);
	GF2X_MUL(6, temp2, 3, q_11+381+1, 3, p_11+384);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+253+1, 6, q_11+253+1, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+384+2, 1, q_10+381);
	GF2X_MUL(2, temp2, 1, p_11+384+2, 1, q_11+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+253+2, 2, q_11+253+2, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+384+1, 1, q_10+381);
	GF2X_MUL(2, temp2, 1, p_11+384+1, 1, q_11+381);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+253+1, 2, q_11+253+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+381+0, 1, p_01+384);
	GF2X_MUL(2, temp2, 1, q_11+381+0, 1, p_11+384);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+253+0, 2, q_11+253+0, 2, temp);
	

	// Recombining results: n: 16137, depth: 1
	memset(q_00+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, p_00+256+3, 125, q_00+253);
	GF2X_MUL(250, temp2, 125, p_10+256+3, 125, q_01+253);
	gf2x_add(250, q_00+0+3, 250, temp, 250, temp2);
	GF2X_MUL(6, temp, 3, q_00+253+122, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+122, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+122, 6, q_00+0+122, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+119, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+119, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+119, 6, q_00+0+119, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+116, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+116, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+116, 6, q_00+0+116, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+113, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+113, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+113, 6, q_00+0+113, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+110, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+110, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+110, 6, q_00+0+110, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+107, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+107, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+107, 6, q_00+0+107, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+104, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+104, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+104, 6, q_00+0+104, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+101, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+101, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+101, 6, q_00+0+101, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+98, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+98, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+98, 6, q_00+0+98, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+95, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+95, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+95, 6, q_00+0+95, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+92, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+92, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+92, 6, q_00+0+92, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+89, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+89, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+89, 6, q_00+0+89, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+86, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+86, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+86, 6, q_00+0+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+83, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+83, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+83, 6, q_00+0+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+80, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+80, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+80, 6, q_00+0+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+77, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+77, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+77, 6, q_00+0+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+74, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+74, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+74, 6, q_00+0+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+71, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+71, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+71, 6, q_00+0+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+68, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+68, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+68, 6, q_00+0+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+65, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+65, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+65, 6, q_00+0+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+62, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+62, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+62, 6, q_00+0+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+59, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+59, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+59, 6, q_00+0+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+56, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+56, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+56, 6, q_00+0+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+53, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+53, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+53, 6, q_00+0+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+50, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+50, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+50, 6, q_00+0+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+47, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+47, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+47, 6, q_00+0+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+44, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+44, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+44, 6, q_00+0+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+41, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+41, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+41, 6, q_00+0+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+38, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+38, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+38, 6, q_00+0+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+35, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+35, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+35, 6, q_00+0+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+32, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+32, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+32, 6, q_00+0+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+29, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+29, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+29, 6, q_00+0+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+26, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+26, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+26, 6, q_00+0+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+23, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+23, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+23, 6, q_00+0+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+20, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+20, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+20, 6, q_00+0+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+17, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+17, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+17, 6, q_00+0+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+14, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+14, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+14, 6, q_00+0+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+11, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+11, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+11, 6, q_00+0+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+8, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+8, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+8, 6, q_00+0+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+5, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+5, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+5, 6, q_00+0+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+2, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_01+253+2, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_00+0+2, 6, q_00+0+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+256+1, 2, q_00+253);
	GF2X_MUL(4, temp2, 2, p_10+256+1, 2, q_01+253);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+0+1, 4, q_00+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+253+1, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+253+1, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+1, 2, q_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+253+0, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_01+253+0, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+0+0, 2, q_00+0+0, 2, temp);
	memset(q_01+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, p_01+256+3, 125, q_00+253);
	GF2X_MUL(250, temp2, 125, p_11+256+3, 125, q_01+253);
	gf2x_add(250, q_01+0+3, 250, temp, 250, temp2);
	GF2X_MUL(6, temp, 3, q_00+253+122, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+122, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+122, 6, q_01+0+122, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+119, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+119, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+119, 6, q_01+0+119, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+116, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+116, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+116, 6, q_01+0+116, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+113, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+113, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+113, 6, q_01+0+113, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+110, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+110, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+110, 6, q_01+0+110, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+107, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+107, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+107, 6, q_01+0+107, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+104, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+104, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+104, 6, q_01+0+104, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+101, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+101, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+101, 6, q_01+0+101, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+98, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+98, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+98, 6, q_01+0+98, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+95, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+95, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+95, 6, q_01+0+95, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+92, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+92, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+92, 6, q_01+0+92, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+89, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+89, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+89, 6, q_01+0+89, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+86, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+86, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+86, 6, q_01+0+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+83, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+83, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+83, 6, q_01+0+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+80, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+80, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+80, 6, q_01+0+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+77, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+77, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+77, 6, q_01+0+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+74, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+74, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+74, 6, q_01+0+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+71, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+71, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+71, 6, q_01+0+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+68, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+68, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+68, 6, q_01+0+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+65, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+65, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+65, 6, q_01+0+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+62, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+62, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+62, 6, q_01+0+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+59, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+59, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+59, 6, q_01+0+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+56, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+56, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+56, 6, q_01+0+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+53, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+53, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+53, 6, q_01+0+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+50, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+50, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+50, 6, q_01+0+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+47, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+47, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+47, 6, q_01+0+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+44, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+44, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+44, 6, q_01+0+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+41, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+41, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+41, 6, q_01+0+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+38, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+38, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+38, 6, q_01+0+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+35, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+35, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+35, 6, q_01+0+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+32, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+32, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+32, 6, q_01+0+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+29, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+29, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+29, 6, q_01+0+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+26, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+26, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+26, 6, q_01+0+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+23, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+23, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+23, 6, q_01+0+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+20, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+20, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+20, 6, q_01+0+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+17, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+17, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+17, 6, q_01+0+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+14, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+14, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+14, 6, q_01+0+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+11, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+11, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+11, 6, q_01+0+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+8, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+8, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+8, 6, q_01+0+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+5, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+5, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+5, 6, q_01+0+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+253+2, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_01+253+2, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_01+0+2, 6, q_01+0+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+256+1, 2, q_00+253);
	GF2X_MUL(4, temp2, 2, p_11+256+1, 2, q_01+253);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+0+1, 4, q_01+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+253+1, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+253+1, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+1, 2, q_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+253+0, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_01+253+0, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+0+0, 2, q_01+0+0, 2, temp);
	memset(q_10+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, p_00+256+3, 125, q_10+253);
	GF2X_MUL(250, temp2, 125, p_10+256+3, 125, q_11+253);
	gf2x_add(250, q_10+0+3, 250, temp, 250, temp2);
	GF2X_MUL(6, temp, 3, q_10+253+122, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+122, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+122, 6, q_10+0+122, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+119, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+119, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+119, 6, q_10+0+119, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+116, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+116, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+116, 6, q_10+0+116, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+113, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+113, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+113, 6, q_10+0+113, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+110, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+110, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+110, 6, q_10+0+110, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+107, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+107, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+107, 6, q_10+0+107, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+104, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+104, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+104, 6, q_10+0+104, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+101, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+101, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+101, 6, q_10+0+101, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+98, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+98, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+98, 6, q_10+0+98, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+95, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+95, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+95, 6, q_10+0+95, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+92, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+92, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+92, 6, q_10+0+92, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+89, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+89, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+89, 6, q_10+0+89, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+86, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+86, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+86, 6, q_10+0+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+83, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+83, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+83, 6, q_10+0+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+80, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+80, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+80, 6, q_10+0+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+77, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+77, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+77, 6, q_10+0+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+74, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+74, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+74, 6, q_10+0+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+71, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+71, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+71, 6, q_10+0+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+68, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+68, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+68, 6, q_10+0+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+65, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+65, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+65, 6, q_10+0+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+62, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+62, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+62, 6, q_10+0+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+59, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+59, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+59, 6, q_10+0+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+56, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+56, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+56, 6, q_10+0+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+53, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+53, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+53, 6, q_10+0+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+50, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+50, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+50, 6, q_10+0+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+47, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+47, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+47, 6, q_10+0+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+44, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+44, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+44, 6, q_10+0+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+41, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+41, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+41, 6, q_10+0+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+38, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+38, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+38, 6, q_10+0+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+35, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+35, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+35, 6, q_10+0+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+32, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+32, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+32, 6, q_10+0+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+29, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+29, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+29, 6, q_10+0+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+26, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+26, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+26, 6, q_10+0+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+23, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+23, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+23, 6, q_10+0+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+20, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+20, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+20, 6, q_10+0+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+17, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+17, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+17, 6, q_10+0+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+14, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+14, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+14, 6, q_10+0+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+11, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+11, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+11, 6, q_10+0+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+8, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+8, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+8, 6, q_10+0+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+5, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+5, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+5, 6, q_10+0+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+2, 3, p_00+256);
	GF2X_MUL(6, temp2, 3, q_11+253+2, 3, p_10+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_10+0+2, 6, q_10+0+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_00+256+1, 2, q_10+253);
	GF2X_MUL(4, temp2, 2, p_10+256+1, 2, q_11+253);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+0+1, 4, q_10+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+253+1, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+253+1, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+1, 2, q_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+253+0, 1, p_00+256);
	GF2X_MUL(2, temp2, 1, q_11+253+0, 1, p_10+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+0+0, 2, q_10+0+0, 2, temp);
	memset(q_11+0, 0x00, 3*DIGIT_SIZE_B);
	GF2X_MUL(250, temp, 125, p_01+256+3, 125, q_10+253);
	GF2X_MUL(250, temp2, 125, p_11+256+3, 125, q_11+253);
	gf2x_add(250, q_11+0+3, 250, temp, 250, temp2);
	GF2X_MUL(6, temp, 3, q_10+253+122, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+122, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+122, 6, q_11+0+122, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+119, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+119, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+119, 6, q_11+0+119, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+116, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+116, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+116, 6, q_11+0+116, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+113, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+113, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+113, 6, q_11+0+113, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+110, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+110, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+110, 6, q_11+0+110, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+107, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+107, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+107, 6, q_11+0+107, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+104, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+104, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+104, 6, q_11+0+104, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+101, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+101, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+101, 6, q_11+0+101, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+98, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+98, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+98, 6, q_11+0+98, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+95, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+95, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+95, 6, q_11+0+95, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+92, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+92, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+92, 6, q_11+0+92, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+89, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+89, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+89, 6, q_11+0+89, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+86, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+86, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+86, 6, q_11+0+86, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+83, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+83, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+83, 6, q_11+0+83, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+80, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+80, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+80, 6, q_11+0+80, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+77, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+77, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+77, 6, q_11+0+77, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+74, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+74, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+74, 6, q_11+0+74, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+71, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+71, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+71, 6, q_11+0+71, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+68, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+68, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+68, 6, q_11+0+68, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+65, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+65, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+65, 6, q_11+0+65, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+62, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+62, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+62, 6, q_11+0+62, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+59, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+59, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+59, 6, q_11+0+59, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+56, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+56, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+56, 6, q_11+0+56, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+53, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+53, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+53, 6, q_11+0+53, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+50, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+50, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+50, 6, q_11+0+50, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+47, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+47, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+47, 6, q_11+0+47, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+44, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+44, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+44, 6, q_11+0+44, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+41, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+41, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+41, 6, q_11+0+41, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+38, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+38, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+38, 6, q_11+0+38, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+35, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+35, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+35, 6, q_11+0+35, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+32, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+32, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+32, 6, q_11+0+32, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+29, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+29, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+29, 6, q_11+0+29, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+26, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+26, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+26, 6, q_11+0+26, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+23, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+23, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+23, 6, q_11+0+23, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+20, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+20, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+20, 6, q_11+0+20, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+17, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+17, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+17, 6, q_11+0+17, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+14, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+14, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+14, 6, q_11+0+14, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+11, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+11, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+11, 6, q_11+0+11, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+8, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+8, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+8, 6, q_11+0+8, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+5, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+5, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+5, 6, q_11+0+5, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+253+2, 3, p_01+256);
	GF2X_MUL(6, temp2, 3, q_11+253+2, 3, p_11+256);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, q_11+0+2, 6, q_11+0+2, 6, temp);
	GF2X_MUL(4, temp, 2, p_01+256+1, 2, q_10+253);
	GF2X_MUL(4, temp2, 2, p_11+256+1, 2, q_11+253);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+0+1, 4, q_11+0+1, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+253+1, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+253+1, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+1, 2, q_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+253+0, 1, p_01+256);
	GF2X_MUL(2, temp2, 1, q_11+253+0, 1, p_11+256);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+0+0, 2, q_11+0+0, 2, temp);
	

	// Recombining results: n: 32457, depth: 0
	memset(t_00+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, p_00+0+3, 253, q_00+0);
	GF2X_MUL(506, temp2, 253, p_10+0+3, 253, q_01+0);
	gf2x_add(506, t_00+0+2, 506, temp, 506, temp2);
	GF2X_MUL(6, temp, 3, q_00+0+250, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+250, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+249, 6, t_00+0+249, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+247, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+247, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+246, 6, t_00+0+246, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+244, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+244, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+243, 6, t_00+0+243, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+241, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+241, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+240, 6, t_00+0+240, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+238, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+238, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+237, 6, t_00+0+237, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+235, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+235, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+234, 6, t_00+0+234, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+232, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+232, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+231, 6, t_00+0+231, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+229, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+229, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+228, 6, t_00+0+228, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+226, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+226, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+225, 6, t_00+0+225, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+223, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+223, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+222, 6, t_00+0+222, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+220, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+220, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+219, 6, t_00+0+219, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+217, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+217, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+216, 6, t_00+0+216, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+214, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+214, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+213, 6, t_00+0+213, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+211, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+211, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+210, 6, t_00+0+210, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+208, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+208, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+207, 6, t_00+0+207, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+205, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+205, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+204, 6, t_00+0+204, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+202, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+202, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+201, 6, t_00+0+201, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+199, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+199, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+198, 6, t_00+0+198, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+196, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+196, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+195, 6, t_00+0+195, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+193, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+193, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+192, 6, t_00+0+192, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+190, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+190, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+189, 6, t_00+0+189, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+187, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+187, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+186, 6, t_00+0+186, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+184, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+184, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+183, 6, t_00+0+183, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+181, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+181, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+180, 6, t_00+0+180, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+178, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+178, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+177, 6, t_00+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+175, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+175, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+174, 6, t_00+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+172, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+172, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+171, 6, t_00+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+169, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+169, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+168, 6, t_00+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+166, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+166, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+165, 6, t_00+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+163, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+163, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+162, 6, t_00+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+160, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+160, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+159, 6, t_00+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+157, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+157, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+156, 6, t_00+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+154, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+154, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+153, 6, t_00+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+151, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+151, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+150, 6, t_00+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+148, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+148, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+147, 6, t_00+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+145, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+145, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+144, 6, t_00+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+142, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+142, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+141, 6, t_00+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+139, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+139, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+138, 6, t_00+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+136, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+136, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+135, 6, t_00+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+133, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+133, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+132, 6, t_00+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+130, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+130, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+129, 6, t_00+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+127, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+127, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+126, 6, t_00+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+124, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+124, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+123, 6, t_00+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+121, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+121, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+120, 6, t_00+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+118, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+118, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+117, 6, t_00+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+115, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+115, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+114, 6, t_00+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+112, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+112, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+111, 6, t_00+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+109, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+109, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+108, 6, t_00+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+106, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+106, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+105, 6, t_00+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+103, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+103, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+102, 6, t_00+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+100, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+100, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+99, 6, t_00+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+97, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+97, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+96, 6, t_00+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+94, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+94, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+93, 6, t_00+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+91, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+91, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+90, 6, t_00+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+88, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+88, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+87, 6, t_00+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+85, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+85, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+84, 6, t_00+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+82, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+82, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+81, 6, t_00+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+79, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+79, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+78, 6, t_00+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+76, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+76, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+75, 6, t_00+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+73, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+73, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+72, 6, t_00+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+70, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+70, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+69, 6, t_00+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+67, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+67, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+66, 6, t_00+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+64, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+64, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+63, 6, t_00+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+61, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+61, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+60, 6, t_00+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+58, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+58, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+57, 6, t_00+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+55, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+55, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+54, 6, t_00+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+52, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+52, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+51, 6, t_00+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+49, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+49, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+48, 6, t_00+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+46, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+46, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+45, 6, t_00+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+43, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+43, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+42, 6, t_00+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+40, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+40, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+39, 6, t_00+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+37, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+37, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+36, 6, t_00+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+34, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+34, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+33, 6, t_00+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+31, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+31, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+30, 6, t_00+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+28, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+28, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+27, 6, t_00+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+25, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+25, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+24, 6, t_00+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+22, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+22, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+21, 6, t_00+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+19, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+19, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+18, 6, t_00+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+16, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+16, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+15, 6, t_00+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+13, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+13, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+12, 6, t_00+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+10, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+10, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+9, 6, t_00+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+7, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+7, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+6, 6, t_00+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+4, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+4, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+3, 6, t_00+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+1, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_01+0+1, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_00+0+0, 6, t_00+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+0+2, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+2, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+1, 2, t_00+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+0, 2, t_00+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_00+0, 1, t_00+0, 1, temp+1);
	memset(t_01+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, p_01+0+3, 253, q_00+0);
	GF2X_MUL(506, temp2, 253, p_11+0+3, 253, q_01+0);
	gf2x_add(506, t_01+0+2, 506, temp, 506, temp2);
	GF2X_MUL(6, temp, 3, q_00+0+250, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+250, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+249, 6, t_01+0+249, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+247, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+247, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+246, 6, t_01+0+246, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+244, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+244, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+243, 6, t_01+0+243, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+241, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+241, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+240, 6, t_01+0+240, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+238, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+238, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+237, 6, t_01+0+237, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+235, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+235, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+234, 6, t_01+0+234, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+232, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+232, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+231, 6, t_01+0+231, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+229, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+229, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+228, 6, t_01+0+228, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+226, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+226, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+225, 6, t_01+0+225, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+223, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+223, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+222, 6, t_01+0+222, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+220, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+220, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+219, 6, t_01+0+219, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+217, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+217, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+216, 6, t_01+0+216, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+214, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+214, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+213, 6, t_01+0+213, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+211, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+211, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+210, 6, t_01+0+210, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+208, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+208, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+207, 6, t_01+0+207, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+205, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+205, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+204, 6, t_01+0+204, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+202, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+202, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+201, 6, t_01+0+201, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+199, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+199, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+198, 6, t_01+0+198, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+196, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+196, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+195, 6, t_01+0+195, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+193, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+193, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+192, 6, t_01+0+192, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+190, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+190, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+189, 6, t_01+0+189, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+187, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+187, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+186, 6, t_01+0+186, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+184, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+184, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+183, 6, t_01+0+183, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+181, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+181, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+180, 6, t_01+0+180, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+178, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+178, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+177, 6, t_01+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+175, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+175, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+174, 6, t_01+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+172, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+172, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+171, 6, t_01+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+169, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+169, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+168, 6, t_01+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+166, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+166, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+165, 6, t_01+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+163, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+163, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+162, 6, t_01+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+160, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+160, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+159, 6, t_01+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+157, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+157, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+156, 6, t_01+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+154, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+154, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+153, 6, t_01+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+151, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+151, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+150, 6, t_01+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+148, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+148, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+147, 6, t_01+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+145, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+145, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+144, 6, t_01+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+142, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+142, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+141, 6, t_01+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+139, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+139, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+138, 6, t_01+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+136, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+136, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+135, 6, t_01+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+133, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+133, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+132, 6, t_01+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+130, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+130, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+129, 6, t_01+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+127, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+127, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+126, 6, t_01+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+124, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+124, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+123, 6, t_01+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+121, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+121, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+120, 6, t_01+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+118, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+118, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+117, 6, t_01+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+115, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+115, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+114, 6, t_01+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+112, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+112, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+111, 6, t_01+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+109, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+109, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+108, 6, t_01+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+106, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+106, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+105, 6, t_01+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+103, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+103, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+102, 6, t_01+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+100, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+100, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+99, 6, t_01+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+97, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+97, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+96, 6, t_01+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+94, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+94, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+93, 6, t_01+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+91, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+91, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+90, 6, t_01+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+88, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+88, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+87, 6, t_01+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+85, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+85, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+84, 6, t_01+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+82, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+82, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+81, 6, t_01+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+79, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+79, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+78, 6, t_01+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+76, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+76, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+75, 6, t_01+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+73, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+73, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+72, 6, t_01+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+70, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+70, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+69, 6, t_01+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+67, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+67, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+66, 6, t_01+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+64, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+64, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+63, 6, t_01+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+61, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+61, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+60, 6, t_01+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+58, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+58, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+57, 6, t_01+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+55, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+55, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+54, 6, t_01+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+52, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+52, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+51, 6, t_01+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+49, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+49, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+48, 6, t_01+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+46, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+46, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+45, 6, t_01+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+43, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+43, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+42, 6, t_01+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+40, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+40, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+39, 6, t_01+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+37, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+37, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+36, 6, t_01+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+34, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+34, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+33, 6, t_01+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+31, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+31, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+30, 6, t_01+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+28, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+28, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+27, 6, t_01+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+25, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+25, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+24, 6, t_01+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+22, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+22, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+21, 6, t_01+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+19, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+19, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+18, 6, t_01+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+16, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+16, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+15, 6, t_01+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+13, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+13, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+12, 6, t_01+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+10, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+10, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+9, 6, t_01+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+7, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+7, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+6, 6, t_01+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+4, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+4, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+3, 6, t_01+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_00+0+1, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_01+0+1, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_01+0+0, 6, t_01+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+0+2, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+2, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+1, 2, t_01+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+0, 2, t_01+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_01+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_01+0, 1, t_01+0, 1, temp+1);
	memset(t_10+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, p_00+0+3, 253, q_10+0);
	GF2X_MUL(506, temp2, 253, p_10+0+3, 253, q_11+0);
	gf2x_add(506, t_10+0+2, 506, temp, 506, temp2);
	GF2X_MUL(6, temp, 3, q_10+0+250, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+250, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+249, 6, t_10+0+249, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+247, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+247, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+246, 6, t_10+0+246, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+244, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+244, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+243, 6, t_10+0+243, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+241, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+241, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+240, 6, t_10+0+240, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+238, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+238, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+237, 6, t_10+0+237, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+235, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+235, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+234, 6, t_10+0+234, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+232, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+232, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+231, 6, t_10+0+231, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+229, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+229, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+228, 6, t_10+0+228, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+226, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+226, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+225, 6, t_10+0+225, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+223, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+223, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+222, 6, t_10+0+222, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+220, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+220, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+219, 6, t_10+0+219, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+217, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+217, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+216, 6, t_10+0+216, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+214, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+214, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+213, 6, t_10+0+213, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+211, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+211, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+210, 6, t_10+0+210, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+208, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+208, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+207, 6, t_10+0+207, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+205, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+205, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+204, 6, t_10+0+204, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+202, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+202, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+201, 6, t_10+0+201, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+199, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+199, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+198, 6, t_10+0+198, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+196, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+196, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+195, 6, t_10+0+195, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+193, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+193, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+192, 6, t_10+0+192, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+190, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+190, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+189, 6, t_10+0+189, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+187, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+187, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+186, 6, t_10+0+186, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+184, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+184, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+183, 6, t_10+0+183, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+181, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+181, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+180, 6, t_10+0+180, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+178, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+178, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+177, 6, t_10+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+175, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+175, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+174, 6, t_10+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+172, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+172, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+171, 6, t_10+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+169, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+169, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+168, 6, t_10+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+166, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+166, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+165, 6, t_10+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+163, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+163, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+162, 6, t_10+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+160, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+160, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+159, 6, t_10+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+157, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+157, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+156, 6, t_10+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+154, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+154, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+153, 6, t_10+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+151, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+151, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+150, 6, t_10+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+148, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+148, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+147, 6, t_10+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+145, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+145, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+144, 6, t_10+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+142, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+142, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+141, 6, t_10+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+139, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+139, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+138, 6, t_10+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+136, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+136, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+135, 6, t_10+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+133, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+133, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+132, 6, t_10+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+130, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+130, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+129, 6, t_10+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+127, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+127, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+126, 6, t_10+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+124, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+124, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+123, 6, t_10+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+121, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+121, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+120, 6, t_10+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+118, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+118, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+117, 6, t_10+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+115, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+115, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+114, 6, t_10+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+112, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+112, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+111, 6, t_10+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+109, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+109, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+108, 6, t_10+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+106, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+106, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+105, 6, t_10+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+103, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+103, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+102, 6, t_10+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+100, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+100, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+99, 6, t_10+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+97, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+97, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+96, 6, t_10+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+94, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+94, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+93, 6, t_10+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+91, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+91, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+90, 6, t_10+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+88, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+88, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+87, 6, t_10+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+85, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+85, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+84, 6, t_10+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+82, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+82, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+81, 6, t_10+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+79, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+79, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+78, 6, t_10+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+76, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+76, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+75, 6, t_10+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+73, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+73, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+72, 6, t_10+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+70, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+70, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+69, 6, t_10+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+67, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+67, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+66, 6, t_10+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+64, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+64, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+63, 6, t_10+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+61, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+61, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+60, 6, t_10+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+58, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+58, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+57, 6, t_10+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+55, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+55, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+54, 6, t_10+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+52, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+52, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+51, 6, t_10+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+49, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+49, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+48, 6, t_10+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+46, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+46, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+45, 6, t_10+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+43, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+43, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+42, 6, t_10+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+40, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+40, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+39, 6, t_10+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+37, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+37, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+36, 6, t_10+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+34, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+34, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+33, 6, t_10+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+31, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+31, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+30, 6, t_10+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+28, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+28, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+27, 6, t_10+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+25, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+25, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+24, 6, t_10+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+22, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+22, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+21, 6, t_10+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+19, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+19, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+18, 6, t_10+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+16, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+16, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+15, 6, t_10+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+13, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+13, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+12, 6, t_10+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+10, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+10, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+9, 6, t_10+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+7, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+7, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+6, 6, t_10+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+4, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+4, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+3, 6, t_10+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+1, 3, p_00+0);
	GF2X_MUL(6, temp2, 3, q_11+0+1, 3, p_10+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_10+0+0, 6, t_10+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_00+0+2, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+2, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+1, 2, t_10+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+0, 2, t_10+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_00+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_10+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_10+0, 1, t_10+0, 1, temp+1);
	memset(t_11+0, 0x00, 2*DIGIT_SIZE_B);
	GF2X_MUL(506, temp, 253, p_01+0+3, 253, q_10+0);
	GF2X_MUL(506, temp2, 253, p_11+0+3, 253, q_11+0);
	gf2x_add(506, t_11+0+2, 506, temp, 506, temp2);
	GF2X_MUL(6, temp, 3, q_10+0+250, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+250, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+249, 6, t_11+0+249, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+247, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+247, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+246, 6, t_11+0+246, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+244, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+244, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+243, 6, t_11+0+243, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+241, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+241, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+240, 6, t_11+0+240, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+238, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+238, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+237, 6, t_11+0+237, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+235, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+235, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+234, 6, t_11+0+234, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+232, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+232, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+231, 6, t_11+0+231, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+229, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+229, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+228, 6, t_11+0+228, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+226, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+226, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+225, 6, t_11+0+225, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+223, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+223, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+222, 6, t_11+0+222, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+220, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+220, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+219, 6, t_11+0+219, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+217, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+217, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+216, 6, t_11+0+216, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+214, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+214, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+213, 6, t_11+0+213, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+211, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+211, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+210, 6, t_11+0+210, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+208, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+208, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+207, 6, t_11+0+207, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+205, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+205, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+204, 6, t_11+0+204, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+202, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+202, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+201, 6, t_11+0+201, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+199, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+199, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+198, 6, t_11+0+198, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+196, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+196, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+195, 6, t_11+0+195, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+193, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+193, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+192, 6, t_11+0+192, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+190, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+190, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+189, 6, t_11+0+189, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+187, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+187, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+186, 6, t_11+0+186, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+184, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+184, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+183, 6, t_11+0+183, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+181, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+181, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+180, 6, t_11+0+180, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+178, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+178, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+177, 6, t_11+0+177, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+175, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+175, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+174, 6, t_11+0+174, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+172, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+172, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+171, 6, t_11+0+171, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+169, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+169, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+168, 6, t_11+0+168, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+166, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+166, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+165, 6, t_11+0+165, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+163, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+163, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+162, 6, t_11+0+162, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+160, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+160, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+159, 6, t_11+0+159, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+157, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+157, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+156, 6, t_11+0+156, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+154, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+154, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+153, 6, t_11+0+153, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+151, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+151, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+150, 6, t_11+0+150, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+148, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+148, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+147, 6, t_11+0+147, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+145, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+145, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+144, 6, t_11+0+144, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+142, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+142, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+141, 6, t_11+0+141, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+139, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+139, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+138, 6, t_11+0+138, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+136, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+136, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+135, 6, t_11+0+135, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+133, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+133, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+132, 6, t_11+0+132, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+130, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+130, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+129, 6, t_11+0+129, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+127, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+127, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+126, 6, t_11+0+126, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+124, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+124, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+123, 6, t_11+0+123, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+121, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+121, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+120, 6, t_11+0+120, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+118, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+118, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+117, 6, t_11+0+117, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+115, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+115, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+114, 6, t_11+0+114, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+112, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+112, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+111, 6, t_11+0+111, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+109, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+109, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+108, 6, t_11+0+108, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+106, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+106, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+105, 6, t_11+0+105, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+103, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+103, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+102, 6, t_11+0+102, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+100, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+100, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+99, 6, t_11+0+99, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+97, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+97, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+96, 6, t_11+0+96, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+94, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+94, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+93, 6, t_11+0+93, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+91, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+91, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+90, 6, t_11+0+90, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+88, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+88, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+87, 6, t_11+0+87, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+85, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+85, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+84, 6, t_11+0+84, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+82, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+82, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+81, 6, t_11+0+81, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+79, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+79, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+78, 6, t_11+0+78, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+76, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+76, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+75, 6, t_11+0+75, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+73, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+73, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+72, 6, t_11+0+72, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+70, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+70, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+69, 6, t_11+0+69, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+67, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+67, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+66, 6, t_11+0+66, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+64, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+64, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+63, 6, t_11+0+63, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+61, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+61, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+60, 6, t_11+0+60, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+58, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+58, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+57, 6, t_11+0+57, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+55, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+55, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+54, 6, t_11+0+54, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+52, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+52, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+51, 6, t_11+0+51, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+49, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+49, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+48, 6, t_11+0+48, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+46, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+46, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+45, 6, t_11+0+45, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+43, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+43, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+42, 6, t_11+0+42, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+40, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+40, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+39, 6, t_11+0+39, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+37, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+37, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+36, 6, t_11+0+36, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+34, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+34, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+33, 6, t_11+0+33, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+31, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+31, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+30, 6, t_11+0+30, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+28, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+28, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+27, 6, t_11+0+27, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+25, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+25, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+24, 6, t_11+0+24, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+22, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+22, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+21, 6, t_11+0+21, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+19, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+19, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+18, 6, t_11+0+18, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+16, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+16, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+15, 6, t_11+0+15, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+13, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+13, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+12, 6, t_11+0+12, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+10, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+10, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+9, 6, t_11+0+9, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+7, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+7, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+6, 6, t_11+0+6, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+4, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+4, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+3, 6, t_11+0+3, 6, temp);
	GF2X_MUL(6, temp, 3, q_10+0+1, 3, p_01+0);
	GF2X_MUL(6, temp2, 3, q_11+0+1, 3, p_11+0);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(6, t_11+0+0, 6, t_11+0+0, 6, temp);
	GF2X_MUL(2, temp, 1, p_01+0+2, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+2, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+1, 2, t_11+0+1, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+1, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+1, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+0, 2, t_11+0+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+0+0, 1, p_01+0);
	GF2X_MUL(2, temp2, 1, q_11+0+0, 1, p_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, t_11+0, 1, t_11+0, 1, temp+1);
	

	return delta;
}