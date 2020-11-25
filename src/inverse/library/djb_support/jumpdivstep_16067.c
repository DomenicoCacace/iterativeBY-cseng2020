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
	
	DIGIT f_sum[1523];
	DIGIT g_sum[1523];
	
	DIGIT temp[1014];
	DIGIT temp2[1014];
	

	delta = divstepsx_256(255, delta, f+499, g+499, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+495+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+495+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+495+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g+495+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f+495+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+495+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+495+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g+495+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+487+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+487+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+487+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g+487+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f+487+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+487+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f+487+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g+487+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f+471+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+471+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+471+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f+471+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+471+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+471+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f+439+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+439+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+439+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f+439+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+439+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+439+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f+375+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+375+64, 64, p_01+384);
	gf2x_add(128, f_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+375+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f+375+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+375+64, 64, p_11+384);
	gf2x_add(128, g_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+375+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 127
	// Displacement: 128
	GF2X_MUL(256, temp, 128, f+247+128, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+247+128, 128, p_01+256);
	gf2x_add(256, f_sum+760+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247+0, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+247+0, 128, p_01+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, f_sum+760, 128, f_sum+760, 128, temp+128);
	right_bit_shift_n(256, f_sum+760, 32);
	GF2X_MUL(256, temp, 128, f+247+128, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+247+128, 128, p_11+256);
	gf2x_add(256, g_sum+760+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247+0, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+247+0, 128, p_11+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, g_sum+760, 128, g_sum+760, 128, temp+128);
	right_bit_shift_n(256, g_sum+760, 32);
	

	delta = divstepsx_256(255, delta, f_sum+885, g_sum+885, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+881+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+881+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+881+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+881+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+881+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+881+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+881+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+881+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+873+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+873+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+873+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+873+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+873+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+873+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+873+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+873+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+857+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+857+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+857+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+857+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+857+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+857+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+857+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+857+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+825+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+825+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+825+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+825+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+825+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+825+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+825+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+825+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+761+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+64, 64, p_01+384);
	gf2x_add(128, f_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+761+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+761+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+64, 64, p_11+384);
	gf2x_add(128, g_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+761+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 255
	// Displacement: 255
	GF2X_MUL(512, temp, 256, f+0+247, 256, p_00+0);
	GF2X_MUL(512, temp2, 256, g+0+247, 256, p_01+0);
	gf2x_add(504, f_sum+0, 504, temp+8, 504, temp2+8);
	GF2X_MUL(494, temp, 247, p_00+0+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_01+0+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(248, f_sum+0, 248, f_sum+0, 248, temp+246);
	GF2X_MUL(18, temp, 9, f+0+238, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+0+238, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+17);
	right_bit_shift_n(503, f_sum+0, 0);
	GF2X_MUL(512, temp, 256, f+0+247, 256, p_10+0);
	GF2X_MUL(512, temp2, 256, g+0+247, 256, p_11+0);
	gf2x_add(504, g_sum+0, 504, temp+8, 504, temp2+8);
	GF2X_MUL(494, temp, 247, p_10+0+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_11+0+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(248, g_sum+0, 248, g_sum+0, 248, temp+246);
	GF2X_MUL(18, temp, 9, f+0+238, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+0+238, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+17);
	right_bit_shift_n(503, g_sum+0, 0);
	

	delta = divstepsx_256(255, delta, f_sum+245, g_sum+245, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+241+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+241+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+241+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+241+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+241+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+241+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+241+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+241+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+233+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+233+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+233+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+233+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+233+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+233+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+233+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+233+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+217+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+217+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+217+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+217+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+217+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+217+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+217+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+217+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+185+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+185+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+185+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+185+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+185+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+185+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+185+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+185+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+121+64, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+121+64, 64, p_01+384);
	gf2x_add(128, f_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+121+0, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+121+0, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+121+64, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+121+64, 64, p_11+384);
	gf2x_add(128, g_sum+1145+0, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+121+0, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+121+0, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1202+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1202+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1202+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1194+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1194+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1194+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1178+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1146+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 127
	// Displacement: 128
	GF2X_MUL(256, temp, 128, f_sum+1+120, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g_sum+1+120, 128, p_01+256);
	gf2x_add(248, f_sum+760, 248, temp+8, 248, temp2+8);
	GF2X_MUL(240, temp, 120, p_00+256+8, 120, f_sum+1);
	GF2X_MUL(240, temp2, 120, p_01+256+8, 120, g_sum+1);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+760, 120, f_sum+760, 120, temp+120);
	right_bit_shift_n(248, f_sum+760, 32);
	GF2X_MUL(256, temp, 128, f_sum+1+120, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g_sum+1+120, 128, p_11+256);
	gf2x_add(248, g_sum+760, 248, temp+8, 248, temp2+8);
	GF2X_MUL(240, temp, 120, p_10+256+8, 120, f_sum+1);
	GF2X_MUL(240, temp2, 120, p_11+256+8, 120, g_sum+1);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+760, 120, g_sum+760, 120, temp+120);
	right_bit_shift_n(248, g_sum+760, 32);
	

	delta = divstepsx_256(255, delta, f_sum+877, g_sum+877, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+873+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+873+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+873+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+873+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+873+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+873+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+873+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+873+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+865+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+865+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+865+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+865+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+865+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+865+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+865+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+865+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+849+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+849+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+849+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+849+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+849+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+849+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+849+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+849+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+817+32, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+817+32, 32, p_01+448);
	gf2x_add(64, f_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+817+0, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+817+0, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+817+32, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+817+32, 32, p_11+448);
	gf2x_add(64, g_sum+1338+0, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+817+0, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+817+0, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1363+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1363+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1363+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1355+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1355+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1355+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 63
	// Displacement: 64
	GF2X_MUL(128, temp, 64, f_sum+761+56, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+56, 64, p_01+384);
	gf2x_add(120, f_sum+1145, 120, temp+8, 120, temp2+8);
	GF2X_MUL(112, temp, 56, p_00+384+8, 56, f_sum+761);
	GF2X_MUL(112, temp2, 56, p_01+384+8, 56, g_sum+761);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+1145, 56, f_sum+1145, 56, temp+56);
	right_bit_shift_n(120, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+761+56, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+761+56, 64, p_11+384);
	gf2x_add(120, g_sum+1145, 120, temp+8, 120, temp2+8);
	GF2X_MUL(112, temp, 56, p_10+384+8, 56, f_sum+761);
	GF2X_MUL(112, temp2, 56, p_11+384+8, 56, g_sum+761);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+1145, 56, g_sum+1145, 56, temp+56);
	right_bit_shift_n(120, g_sum+1145, 48);
	

	delta = divstepsx_256(255, delta, f_sum+1198, g_sum+1198, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1194+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1194+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1194+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1194+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1194+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1194+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1194+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1194+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1186+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1186+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1186+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1186+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1186+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1186+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1186+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1186+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 16
	GF2X_MUL(32, temp, 16, f_sum+1170+16, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170+16, 16, p_01+480);
	gf2x_add(32, f_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1170+0, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170+0, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1170+16, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170+16, 16, p_11+480);
	gf2x_add(32, g_sum+1435+0, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1170+0, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170+0, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1444+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1444+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1444+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1436+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 31
	// Displacement: 32
	GF2X_MUL(64, temp, 32, f_sum+1146+24, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+24, 32, p_01+448);
	gf2x_add(56, f_sum+1338, 56, temp+8, 56, temp2+8);
	GF2X_MUL(48, temp, 24, p_00+448+8, 24, f_sum+1146);
	GF2X_MUL(48, temp2, 24, p_01+448+8, 24, g_sum+1146);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1338, 24, f_sum+1338, 24, temp+24);
	right_bit_shift_n(56, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1146+24, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146+24, 32, p_11+448);
	gf2x_add(56, g_sum+1338, 56, temp+8, 56, temp2+8);
	GF2X_MUL(48, temp, 24, p_10+448+8, 24, f_sum+1146);
	GF2X_MUL(48, temp2, 24, p_11+448+8, 24, g_sum+1146);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1338, 24, g_sum+1338, 24, temp+24);
	right_bit_shift_n(56, g_sum+1338, 56);
	

	delta = divstepsx_256(255, delta, f_sum+1359, g_sum+1359, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1355+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1355+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1355+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1355+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1355+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1355+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1355+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1355+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1347+8, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1347+8, 8, p_01+496);
	gf2x_add(16, f_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1347+0, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1347+0, 8, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1347+8, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1347+8, 8, p_11+496);
	gf2x_add(16, g_sum+1484+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1347+0, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1347+0, 8, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1485+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1485+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1485+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 15
	// Displacement: 15
	GF2X_MUL(32, temp, 16, f_sum+1339+8, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+8, 16, p_01+480);
	gf2x_add(25, f_sum+1435, 25, temp+7, 25, temp2+7);
	GF2X_MUL(16, temp, 8, p_00+480+8, 8, f_sum+1339);
	GF2X_MUL(16, temp2, 8, p_01+480+8, 8, g_sum+1339);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(9, f_sum+1435, 9, f_sum+1435, 9, temp+7);
	GF2X_MUL(16, temp, 8, f_sum+1339+0, 8, p_00+480);
	GF2X_MUL(16, temp2, 8, g_sum+1339+0, 8, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, f_sum+1435, 1, f_sum+1435, 1, temp+15);
	right_bit_shift_n(24, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1339+8, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339+8, 16, p_11+480);
	gf2x_add(25, g_sum+1435, 25, temp+7, 25, temp2+7);
	GF2X_MUL(16, temp, 8, p_10+480+8, 8, f_sum+1339);
	GF2X_MUL(16, temp2, 8, p_11+480+8, 8, g_sum+1339);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(9, g_sum+1435, 9, g_sum+1435, 9, temp+7);
	GF2X_MUL(16, temp, 8, f_sum+1339+0, 8, p_10+480);
	GF2X_MUL(16, temp2, 8, g_sum+1339+0, 8, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, g_sum+1435, 1, g_sum+1435, 1, temp+15);
	right_bit_shift_n(24, g_sum+1435, 60);
	

	delta = divstepsx_256(255, delta, f_sum+1441, g_sum+1441, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1437+4, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1437+4, 4, p_01+504);
	gf2x_add(8, f_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1437+0, 4, p_00+504);
	GF2X_MUL(8, temp2, 4, g_sum+1437+0, 4, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	GF2X_MUL(8, temp, 4, f_sum+1437+4, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1437+4, 4, p_11+504);
	gf2x_add(8, g_sum+1509+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1437+0, 4, p_10+504);
	GF2X_MUL(8, temp2, 4, g_sum+1437+0, 4, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

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
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1436+1, 8, p_00+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+1, 8, p_01+496);
	gf2x_add(9, f_sum+1484, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_00+496+7, 1, f_sum+1436);
	GF2X_MUL(2, temp2, 1, p_01+496+7, 1, g_sum+1436);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1484, 1, f_sum+1484, 1, temp+1);
	right_bit_shift_n(9, f_sum+1484, 62);
	GF2X_MUL(16, temp, 8, f_sum+1436+1, 8, p_10+496);
	GF2X_MUL(16, temp2, 8, g_sum+1436+1, 8, p_11+496);
	gf2x_add(9, g_sum+1484, 9, temp+7, 9, temp2+7);
	GF2X_MUL(2, temp, 1, p_10+496+7, 1, f_sum+1436);
	GF2X_MUL(2, temp2, 1, p_11+496+7, 1, g_sum+1436);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1484, 1, g_sum+1484, 1, temp+1);
	right_bit_shift_n(9, g_sum+1484, 62);
	

	delta = divstepsx(3, delta, *(f_sum+1485), *(g_sum+1485), q_00+488, q_01+488, q_10+488, q_11+488);

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
	memset(q_00+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+480+7, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_10+480+7, 9, q_01+472);
	gf2x_add(18, q_00+440+6, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+472+2, 7, p_00+480);
	GF2X_MUL(14, temp2, 7, q_01+472+2, 7, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+440+1, 14, q_00+440+1, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+480+5, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+5, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+440+4, 4, q_00+440+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+3, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+3, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+440+2, 4, q_00+440+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+1, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_10+480+1, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+440+0, 4, q_00+440+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+472+1, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_01+472+1, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+440+0, 2, q_00+440+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+472+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_01+472+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+440, 1, q_00+440, 1, temp+1);
	memset(q_01+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+480+7, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_11+480+7, 9, q_01+472);
	gf2x_add(18, q_01+440+6, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_00+472+2, 7, p_01+480);
	GF2X_MUL(14, temp2, 7, q_01+472+2, 7, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+440+1, 14, q_01+440+1, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+480+5, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+5, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+440+4, 4, q_01+440+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+3, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+3, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+440+2, 4, q_01+440+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+1, 2, q_00+472);
	GF2X_MUL(4, temp2, 2, p_11+480+1, 2, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+440+0, 4, q_01+440+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_00+472+1, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_01+472+1, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+440+0, 2, q_01+440+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+472+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_01+472+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+440, 1, q_01+440, 1, temp+1);
	memset(q_10+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+480+7, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_10+480+7, 9, q_11+472);
	gf2x_add(18, q_10+440+6, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+472+2, 7, p_00+480);
	GF2X_MUL(14, temp2, 7, q_11+472+2, 7, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+440+1, 14, q_10+440+1, 14, temp);
	GF2X_MUL(4, temp, 2, p_00+480+5, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+5, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+440+4, 4, q_10+440+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+3, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+3, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+440+2, 4, q_10+440+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_00+480+1, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_10+480+1, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+440+0, 4, q_10+440+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+472+1, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_11+472+1, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+440+0, 2, q_10+440+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+472+0, 1, p_00+480);
	GF2X_MUL(2, temp2, 1, q_11+472+0, 1, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+440, 1, q_10+440, 1, temp+1);
	memset(q_11+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+480+7, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_11+480+7, 9, q_11+472);
	gf2x_add(18, q_11+440+6, 18, temp, 18, temp2);
	GF2X_MUL(14, temp, 7, q_10+472+2, 7, p_01+480);
	GF2X_MUL(14, temp2, 7, q_11+472+2, 7, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+440+1, 14, q_11+440+1, 14, temp);
	GF2X_MUL(4, temp, 2, p_01+480+5, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+5, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+440+4, 4, q_11+440+4, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+3, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+3, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+440+2, 4, q_11+440+2, 4, temp);
	GF2X_MUL(4, temp, 2, p_01+480+1, 2, q_10+472);
	GF2X_MUL(4, temp2, 2, p_11+480+1, 2, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+440+0, 4, q_11+440+0, 4, temp);
	GF2X_MUL(2, temp, 1, q_10+472+1, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_11+472+1, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+440+0, 2, q_11+440+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+472+0, 1, p_01+480);
	GF2X_MUL(2, temp2, 1, q_11+472+0, 1, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+440, 1, q_11+440, 1, temp+1);
	

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
	memset(t_00+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+0+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_10+0+8, 248, q_01+0);
	gf2x_add(496, t_00+0+7, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_00+0+240, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+240, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+239, 16, t_00+0+239, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+232, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+232, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+231, 16, t_00+0+231, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+224, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+224, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+223, 16, t_00+0+223, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+216, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+216, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+215, 16, t_00+0+215, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+208, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+208, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+207, 16, t_00+0+207, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+200, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+200, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+199, 16, t_00+0+199, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+192, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+192, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+191, 16, t_00+0+191, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+184, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+184, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+183, 16, t_00+0+183, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+176, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+176, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+175, 16, t_00+0+175, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+168, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+168, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+167, 16, t_00+0+167, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+160, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+160, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+159, 16, t_00+0+159, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+152, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+152, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+151, 16, t_00+0+151, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+144, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+144, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+143, 16, t_00+0+143, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+136, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+136, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+135, 16, t_00+0+135, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+128, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+128, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+127, 16, t_00+0+127, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+120, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+120, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+119, 16, t_00+0+119, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+112, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+112, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+111, 16, t_00+0+111, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+104, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+104, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+103, 16, t_00+0+103, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+96, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+96, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+95, 16, t_00+0+95, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+88, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+88, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+87, 16, t_00+0+87, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+80, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+80, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+79, 16, t_00+0+79, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+72, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+72, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+71, 16, t_00+0+71, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+64, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+64, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+63, 16, t_00+0+63, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+56, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+56, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+55, 16, t_00+0+55, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+48, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+48, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+47, 16, t_00+0+47, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+40, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+40, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+39, 16, t_00+0+39, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+32, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+32, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+31, 16, t_00+0+31, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+24, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+24, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+23, 16, t_00+0+23, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+16, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+16, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+15, 16, t_00+0+15, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+8, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+8, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+0+7, 16, t_00+0+7, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+0, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_01+0+0, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_00+0, 15, t_00+0, 15, temp+1);
	memset(t_01+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+0+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_11+0+8, 248, q_01+0);
	gf2x_add(496, t_01+0+7, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_00+0+240, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+240, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+239, 16, t_01+0+239, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+232, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+232, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+231, 16, t_01+0+231, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+224, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+224, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+223, 16, t_01+0+223, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+216, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+216, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+215, 16, t_01+0+215, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+208, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+208, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+207, 16, t_01+0+207, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+200, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+200, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+199, 16, t_01+0+199, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+192, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+192, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+191, 16, t_01+0+191, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+184, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+184, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+183, 16, t_01+0+183, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+176, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+176, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+175, 16, t_01+0+175, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+168, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+168, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+167, 16, t_01+0+167, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+160, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+160, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+159, 16, t_01+0+159, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+152, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+152, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+151, 16, t_01+0+151, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+144, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+144, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+143, 16, t_01+0+143, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+136, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+136, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+135, 16, t_01+0+135, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+128, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+128, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+127, 16, t_01+0+127, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+120, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+120, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+119, 16, t_01+0+119, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+112, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+112, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+111, 16, t_01+0+111, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+104, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+104, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+103, 16, t_01+0+103, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+96, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+96, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+95, 16, t_01+0+95, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+88, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+88, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+87, 16, t_01+0+87, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+80, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+80, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+79, 16, t_01+0+79, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+72, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+72, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+71, 16, t_01+0+71, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+64, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+64, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+63, 16, t_01+0+63, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+56, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+56, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+55, 16, t_01+0+55, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+48, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+48, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+47, 16, t_01+0+47, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+40, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+40, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+39, 16, t_01+0+39, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+32, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+32, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+31, 16, t_01+0+31, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+24, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+24, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+23, 16, t_01+0+23, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+16, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+16, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+15, 16, t_01+0+15, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+8, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+8, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+0+7, 16, t_01+0+7, 16, temp);
	GF2X_MUL(16, temp, 8, q_00+0+0, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_01+0+0, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_01+0, 15, t_01+0, 15, temp+1);
	memset(t_10+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+0+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_10+0+8, 248, q_11+0);
	gf2x_add(496, t_10+0+7, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_10+0+240, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+240, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+239, 16, t_10+0+239, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+232, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+232, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+231, 16, t_10+0+231, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+224, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+224, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+223, 16, t_10+0+223, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+216, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+216, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+215, 16, t_10+0+215, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+208, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+208, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+207, 16, t_10+0+207, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+200, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+200, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+199, 16, t_10+0+199, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+192, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+192, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+191, 16, t_10+0+191, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+184, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+184, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+183, 16, t_10+0+183, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+176, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+176, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+175, 16, t_10+0+175, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+168, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+168, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+167, 16, t_10+0+167, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+160, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+160, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+159, 16, t_10+0+159, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+152, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+152, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+151, 16, t_10+0+151, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+144, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+144, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+143, 16, t_10+0+143, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+136, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+136, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+135, 16, t_10+0+135, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+128, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+128, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+127, 16, t_10+0+127, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+120, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+120, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+119, 16, t_10+0+119, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+112, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+112, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+111, 16, t_10+0+111, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+104, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+104, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+103, 16, t_10+0+103, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+96, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+96, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+95, 16, t_10+0+95, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+88, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+88, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+87, 16, t_10+0+87, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+80, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+80, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+79, 16, t_10+0+79, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+72, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+72, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+71, 16, t_10+0+71, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+64, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+64, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+63, 16, t_10+0+63, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+56, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+56, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+55, 16, t_10+0+55, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+48, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+48, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+47, 16, t_10+0+47, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+40, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+40, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+39, 16, t_10+0+39, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+32, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+32, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+31, 16, t_10+0+31, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+24, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+24, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+23, 16, t_10+0+23, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+16, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+16, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+15, 16, t_10+0+15, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+8, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+8, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+0+7, 16, t_10+0+7, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+0, 8, p_00+0);
	GF2X_MUL(16, temp2, 8, q_11+0+0, 8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_10+0, 15, t_10+0, 15, temp+1);
	memset(t_11+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+0+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_11+0+8, 248, q_11+0);
	gf2x_add(496, t_11+0+7, 496, temp, 496, temp2);
	GF2X_MUL(16, temp, 8, q_10+0+240, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+240, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+239, 16, t_11+0+239, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+232, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+232, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+231, 16, t_11+0+231, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+224, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+224, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+223, 16, t_11+0+223, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+216, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+216, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+215, 16, t_11+0+215, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+208, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+208, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+207, 16, t_11+0+207, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+200, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+200, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+199, 16, t_11+0+199, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+192, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+192, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+191, 16, t_11+0+191, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+184, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+184, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+183, 16, t_11+0+183, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+176, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+176, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+175, 16, t_11+0+175, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+168, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+168, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+167, 16, t_11+0+167, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+160, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+160, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+159, 16, t_11+0+159, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+152, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+152, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+151, 16, t_11+0+151, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+144, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+144, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+143, 16, t_11+0+143, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+136, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+136, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+135, 16, t_11+0+135, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+128, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+128, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+127, 16, t_11+0+127, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+120, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+120, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+119, 16, t_11+0+119, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+112, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+112, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+111, 16, t_11+0+111, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+104, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+104, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+103, 16, t_11+0+103, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+96, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+96, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+95, 16, t_11+0+95, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+88, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+88, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+87, 16, t_11+0+87, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+80, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+80, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+79, 16, t_11+0+79, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+72, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+72, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+71, 16, t_11+0+71, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+64, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+64, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+63, 16, t_11+0+63, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+56, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+56, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+55, 16, t_11+0+55, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+48, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+48, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+47, 16, t_11+0+47, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+40, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+40, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+39, 16, t_11+0+39, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+32, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+32, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+31, 16, t_11+0+31, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+24, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+24, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+23, 16, t_11+0+23, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+16, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+16, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+15, 16, t_11+0+15, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+8, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+8, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+0+7, 16, t_11+0+7, 16, temp);
	GF2X_MUL(16, temp, 8, q_10+0+0, 8, p_01+0);
	GF2X_MUL(16, temp2, 8, q_11+0+0, 8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_11+0, 15, t_11+0, 15, temp+1);
	

	return delta;
}