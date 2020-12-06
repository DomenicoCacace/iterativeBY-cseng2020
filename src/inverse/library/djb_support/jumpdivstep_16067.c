/**
  * @author Domenico Cacace <domenico.cacace@mail.polimi.it>
  * 
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

int jumpdivstep_16067(int delta, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11) {
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
	
	DIGIT temp[512];
	DIGIT temp2[512];
	

	delta = divstepsx_256(255, delta, f+499, g+499, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f+499, p_00+504);
	gf2x_mul_4_avx(temp2, g+499, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f+495, p_00+504);
	gf2x_mul_4_avx(temp2, g+495, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f+499, p_10+504);
	gf2x_mul_4_avx(temp2, g+499, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f+495, p_10+504);
	gf2x_mul_4_avx(temp2, g+495, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f+495, p_00+496);
	gf2x_mul_8_avx(temp2, g+495, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f+487, p_00+496);
	gf2x_mul_8_avx(temp2, g+487, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f+495, p_10+496);
	gf2x_mul_8_avx(temp2, g+495, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f+487, p_10+496);
	gf2x_mul_8_avx(temp2, g+487, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f+487, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+487, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g+471, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f+487, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+487, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f+471, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g+471, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f+471, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+471, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g+439, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f+471, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+471, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f+439, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g+439, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, p_00+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, p_01+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, p_10+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, p_11+384, 64, temp, 64, temp2);
	
	// Calculating left operands: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, f+439, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+439, 64, p_01+384);
	gf2x_add(128, f_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g+375, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f+439, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+439, 64, p_11+384);
	gf2x_add(128, g_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f+375, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g+375, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	
	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1206, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1206, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1202, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1202, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, q_00+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, q_01+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, q_10+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, q_11+376, 64, temp, 64, temp2);
	
	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_10+384);
	gf2x_add(128, p_00+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_11+384);
	gf2x_add(128, p_01+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_10+384);
	gf2x_add(128, p_10+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_11+384);
	gf2x_add(128, p_11+256, 128, temp, 128, temp2);
	
	// Calculating left operands: n: 16320, depth: 1
	GF2X_MUL(256, temp, 128, f+375, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+375, 128, p_01+256);
	gf2x_add(256, f_sum+760, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g+247, 128, p_01+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, f_sum+760, 128, f_sum+760, 128, temp+128);
	right_bit_shift_n(256, f_sum+760, 32);
	GF2X_MUL(256, temp, 128, f+375, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+375, 128, p_11+256);
	gf2x_add(256, g_sum+760, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, f+247, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g+247, 128, p_11+256);
	gf2x_add(256, temp, 256, temp, 256, temp2);
	gf2x_add(128, g_sum+760, 128, g_sum+760, 128, temp+128);
	right_bit_shift_n(256, g_sum+760, 32);
	
	delta = divstepsx_256(255, delta, f_sum+885, g_sum+885, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+885, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+885, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+881, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+881, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+885, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+885, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+881, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+881, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+881, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+881, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+873, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+873, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+881, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+881, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+873, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+873, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+873, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+873, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+857, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+857, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+873, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+873, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+857, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+857, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+857, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+857, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+825, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+825, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+857, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+857, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+825, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+825, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, p_00+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, p_01+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, p_10+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, p_11+384, 64, temp, 64, temp2);
	
	// Calculating left operands: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, f_sum+825, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+825, 64, p_01+384);
	gf2x_add(128, f_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+761, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+761, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+825, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+825, 64, p_11+384);
	gf2x_add(128, g_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+761, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+761, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	
	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1206, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1206, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1202, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1202, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, q_00+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, q_01+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, q_10+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, q_11+376, 64, temp, 64, temp2);
	
	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_10+384);
	gf2x_add(128, q_00+248, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_11+384);
	gf2x_add(128, q_01+248, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_10+384);
	gf2x_add(128, q_10+248, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_11+384);
	gf2x_add(128, q_11+248, 128, temp, 128, temp2);
	
	// Recombining results: n: 16320, depth: 1
	GF2X_MUL(256, temp, 128, q_00+248, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_01+248, 128, p_10+256);
	gf2x_add(256, p_00+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_00+248, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_01+248, 128, p_11+256);
	gf2x_add(256, p_01+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+248, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, q_11+248, 128, p_10+256);
	gf2x_add(256, p_10+0, 256, temp, 256, temp2);
	GF2X_MUL(256, temp, 128, q_10+248, 128, p_01+256);
	GF2X_MUL(256, temp2, 128, q_11+248, 128, p_11+256);
	gf2x_add(256, p_11+0, 256, temp, 256, temp2);
	
	// Calculating left operands: n: 32133, depth: 0
	GF2X_MUL(512, temp, 256, f+247, 256, p_00+0);
	GF2X_MUL(512, temp2, 256, g+247, 256, p_01+0);
	gf2x_add(504, f_sum+0, 504, temp+8, 504, temp2+8);
	GF2X_MUL(494, temp, 247, p_00+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_01+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(248, f_sum+0, 248, f_sum+0, 248, temp+246);
	GF2X_MUL(18, temp, 9, f+238, 9, p_00+0);
	GF2X_MUL(18, temp2, 9, g+238, 9, p_01+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+17);
	right_bit_shift_n(503, f_sum+0, 0);
	GF2X_MUL(512, temp, 256, f+247, 256, p_10+0);
	GF2X_MUL(512, temp2, 256, g+247, 256, p_11+0);
	gf2x_add(504, g_sum+0, 504, temp+8, 504, temp2+8);
	GF2X_MUL(494, temp, 247, p_10+9, 247, f+0);
	GF2X_MUL(494, temp2, 247, p_11+9, 247, g+0);
	gf2x_add(494, temp, 494, temp, 494, temp2);
	gf2x_add(248, g_sum+0, 248, g_sum+0, 248, temp+246);
	GF2X_MUL(18, temp, 9, f+238, 9, p_10+0);
	GF2X_MUL(18, temp2, 9, g+238, 9, p_11+0);
	gf2x_add(18, temp, 18, temp, 18, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+17);
	right_bit_shift_n(503, g_sum+0, 0);
	
	delta = divstepsx_256(255, delta, f_sum+245, g_sum+245, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+245, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+245, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+241, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+241, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+245, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+245, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+241, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+241, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+241, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+241, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+233, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+233, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+241, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+241, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+233, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+233, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+233, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+233, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+217, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+217, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+233, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+233, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+217, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+217, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+217, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+217, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+185, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+185, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+217, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+217, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+185, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+185, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, p_00+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, p_01+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, p_10+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, p_11+384, 64, temp, 64, temp2);
	
	// Calculating left operands: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, f_sum+185, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+185, 64, p_01+384);
	gf2x_add(128, f_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+121, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+121, 64, p_01+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, f_sum+1145, 64, f_sum+1145, 64, temp+64);
	right_bit_shift_n(128, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+185, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+185, 64, p_11+384);
	gf2x_add(128, g_sum+1145, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, f_sum+121, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+121, 64, p_11+384);
	gf2x_add(128, temp, 128, temp, 128, temp2);
	gf2x_add(64, g_sum+1145, 64, g_sum+1145, 64, temp+64);
	right_bit_shift_n(128, g_sum+1145, 48);
	
	delta = divstepsx_256(255, delta, f_sum+1206, g_sum+1206, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1206, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1206, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1206, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1202, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1202, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1202, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1202, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1202, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1194, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1194, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1194, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1178, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1178, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1178, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1178, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+1146, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1146, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, q_00+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, q_01+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, q_10+376, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, q_11+376, 64, temp, 64, temp2);
	
	// Recombining results: n: 8160, depth: 2
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_10+384);
	gf2x_add(128, p_00+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_00+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_01+376, 64, p_11+384);
	gf2x_add(128, p_01+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_10+384);
	gf2x_add(128, p_10+256, 128, temp, 128, temp2);
	GF2X_MUL(128, temp, 64, q_10+376, 64, p_01+384);
	GF2X_MUL(128, temp2, 64, q_11+376, 64, p_11+384);
	gf2x_add(128, p_11+256, 128, temp, 128, temp2);
	
	// Calculating left operands: n: 15813, depth: 1
	GF2X_MUL(256, temp, 128, f_sum+121, 128, p_00+256);
	GF2X_MUL(256, temp2, 128, g_sum+121, 128, p_01+256);
	gf2x_add(248, f_sum+760, 248, temp+8, 248, temp2+8);
	GF2X_MUL(240, temp, 120, p_00+264, 120, f_sum+1);
	GF2X_MUL(240, temp2, 120, p_01+264, 120, g_sum+1);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, f_sum+760, 120, f_sum+760, 120, temp+120);
	right_bit_shift_n(248, f_sum+760, 32);
	GF2X_MUL(256, temp, 128, f_sum+121, 128, p_10+256);
	GF2X_MUL(256, temp2, 128, g_sum+121, 128, p_11+256);
	gf2x_add(248, g_sum+760, 248, temp+8, 248, temp2+8);
	GF2X_MUL(240, temp, 120, p_10+264, 120, f_sum+1);
	GF2X_MUL(240, temp2, 120, p_11+264, 120, g_sum+1);
	gf2x_add(240, temp, 240, temp, 240, temp2);
	gf2x_add(120, g_sum+760, 120, g_sum+760, 120, temp+120);
	right_bit_shift_n(248, g_sum+760, 32);
	
	delta = divstepsx_256(255, delta, f_sum+877, g_sum+877, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+877, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+877, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+873, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+873, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+877, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+877, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+873, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+873, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+873, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+873, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+865, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+865, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+873, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+873, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+865, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+865, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+865, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+865, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+849, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+849, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+865, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+865, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+849, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+849, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+849, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+849, 32, p_01+448);
	gf2x_add(64, f_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+817, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+817, 32, p_01+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, f_sum+1338, 32, f_sum+1338, 32, temp+32);
	right_bit_shift_n(64, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+849, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+849, 32, p_11+448);
	gf2x_add(64, g_sum+1338, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, f_sum+817, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+817, 32, p_11+448);
	gf2x_add(64, temp, 64, temp, 64, temp2);
	gf2x_add(32, g_sum+1338, 32, g_sum+1338, 32, temp+32);
	right_bit_shift_n(64, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1367, g_sum+1367, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1367, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1367, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1367, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1363, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1363, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1363, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1363, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1363, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1355, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1355, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1339, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1339, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, q_00+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, q_01+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, q_10+440, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, q_11+440, 32, temp, 32, temp2);
	
	// Recombining results: n: 4080, depth: 3
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_10+448);
	gf2x_add(64, p_00+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_00+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_01+440, 32, p_11+448);
	gf2x_add(64, p_01+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_10+448);
	gf2x_add(64, p_10+384, 64, temp, 64, temp2);
	GF2X_MUL(64, temp, 32, q_10+440, 32, p_01+448);
	GF2X_MUL(64, temp2, 32, q_11+440, 32, p_11+448);
	gf2x_add(64, p_11+384, 64, temp, 64, temp2);
	
	// Calculating left operands: n: 7653, depth: 2
	GF2X_MUL(128, temp, 64, f_sum+817, 64, p_00+384);
	GF2X_MUL(128, temp2, 64, g_sum+817, 64, p_01+384);
	gf2x_add(120, f_sum+1145, 120, temp+8, 120, temp2+8);
	GF2X_MUL(112, temp, 56, p_00+392, 56, f_sum+761);
	GF2X_MUL(112, temp2, 56, p_01+392, 56, g_sum+761);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, f_sum+1145, 56, f_sum+1145, 56, temp+56);
	right_bit_shift_n(120, f_sum+1145, 48);
	GF2X_MUL(128, temp, 64, f_sum+817, 64, p_10+384);
	GF2X_MUL(128, temp2, 64, g_sum+817, 64, p_11+384);
	gf2x_add(120, g_sum+1145, 120, temp+8, 120, temp2+8);
	GF2X_MUL(112, temp, 56, p_10+392, 56, f_sum+761);
	GF2X_MUL(112, temp2, 56, p_11+392, 56, g_sum+761);
	gf2x_add(112, temp, 112, temp, 112, temp2);
	gf2x_add(56, g_sum+1145, 56, g_sum+1145, 56, temp+56);
	right_bit_shift_n(120, g_sum+1145, 48);
	
	delta = divstepsx_256(255, delta, f_sum+1198, g_sum+1198, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1198, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1198, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1194, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1194, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1198, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1198, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1194, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1194, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1194, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1186, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1186, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1194, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1194, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1186, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1186, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1186, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1186, 16, p_01+480);
	gf2x_add(32, f_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1170, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170, 16, p_01+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1435, 16, f_sum+1435, 16, temp+16);
	right_bit_shift_n(32, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1186, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1186, 16, p_11+480);
	gf2x_add(32, g_sum+1435, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, f_sum+1170, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1170, 16, p_11+480);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1435, 16, g_sum+1435, 16, temp+16);
	right_bit_shift_n(32, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1448, g_sum+1448, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1448, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1448, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1448, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1444, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1444, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1444, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1444, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1444, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1436, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1436, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, q_00+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, q_01+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, q_10+472, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, q_11+472, 16, temp, 16, temp2);
	
	// Recombining results: n: 2040, depth: 4
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_10+480);
	gf2x_add(32, p_00+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_00+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_01+472, 16, p_11+480);
	gf2x_add(32, p_01+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_10+480);
	gf2x_add(32, p_10+448, 32, temp, 32, temp2);
	GF2X_MUL(32, temp, 16, q_10+472, 16, p_01+480);
	GF2X_MUL(32, temp2, 16, q_11+472, 16, p_11+480);
	gf2x_add(32, p_11+448, 32, temp, 32, temp2);
	
	// Calculating left operands: n: 3573, depth: 3
	GF2X_MUL(64, temp, 32, f_sum+1170, 32, p_00+448);
	GF2X_MUL(64, temp2, 32, g_sum+1170, 32, p_01+448);
	gf2x_add(56, f_sum+1338, 56, temp+8, 56, temp2+8);
	GF2X_MUL(48, temp, 24, p_00+456, 24, f_sum+1146);
	GF2X_MUL(48, temp2, 24, p_01+456, 24, g_sum+1146);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, f_sum+1338, 24, f_sum+1338, 24, temp+24);
	right_bit_shift_n(56, f_sum+1338, 56);
	GF2X_MUL(64, temp, 32, f_sum+1170, 32, p_10+448);
	GF2X_MUL(64, temp2, 32, g_sum+1170, 32, p_11+448);
	gf2x_add(56, g_sum+1338, 56, temp+8, 56, temp2+8);
	GF2X_MUL(48, temp, 24, p_10+456, 24, f_sum+1146);
	GF2X_MUL(48, temp2, 24, p_11+456, 24, g_sum+1146);
	gf2x_add(48, temp, 48, temp, 48, temp2);
	gf2x_add(24, g_sum+1338, 24, g_sum+1338, 24, temp+24);
	right_bit_shift_n(56, g_sum+1338, 56);
	
	delta = divstepsx_256(255, delta, f_sum+1359, g_sum+1359, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1359, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1359, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1355, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1355, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1359, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1359, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1355, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1355, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1355, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_01+496);
	gf2x_add(16, f_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1347, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1347, p_01+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1484, 8, f_sum+1484, 8, temp+8);
	right_bit_shift_n(16, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1355, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1355, p_11+496);
	gf2x_add(16, g_sum+1484, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, f_sum+1347, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1347, p_11+496);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1484, 8, g_sum+1484, 8, temp+8);
	right_bit_shift_n(16, g_sum+1484, 62);
	
	delta = divstepsx_256(255, delta, f_sum+1489, g_sum+1489, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1489, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1489, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1489, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1485, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1485, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, q_00+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, q_01+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, q_10+488, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, q_11+488, 8, temp, 8, temp2);
	
	// Recombining results: n: 1020, depth: 5
	gf2x_mul_8_avx(temp, q_00+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_10+496);
	gf2x_add(16, p_00+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_00+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_01+488, p_11+496);
	gf2x_add(16, p_01+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_00+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_10+496);
	gf2x_add(16, p_10+480, 16, temp, 16, temp2);
	gf2x_mul_8_avx(temp, q_10+488, p_01+496);
	gf2x_mul_8_avx(temp2, q_11+488, p_11+496);
	gf2x_add(16, p_11+480, 16, temp, 16, temp2);
	
	// Calculating left operands: n: 1533, depth: 4
	GF2X_MUL(32, temp, 16, f_sum+1347, 16, p_00+480);
	GF2X_MUL(32, temp2, 16, g_sum+1347, 16, p_01+480);
	gf2x_add(25, f_sum+1435, 25, temp+7, 25, temp2+7);
	gf2x_mul_8_avx(temp, p_00+488, f_sum+1339);
	gf2x_mul_8_avx(temp2, p_01+488, g_sum+1339);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(9, f_sum+1435, 9, f_sum+1435, 9, temp+7);
	gf2x_mul_8_avx(temp, f_sum+1339, p_00+480);
	gf2x_mul_8_avx(temp2, g_sum+1339, p_01+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, f_sum+1435, 1, f_sum+1435, 1, temp+15);
	right_bit_shift_n(24, f_sum+1435, 60);
	GF2X_MUL(32, temp, 16, f_sum+1347, 16, p_10+480);
	GF2X_MUL(32, temp2, 16, g_sum+1347, 16, p_11+480);
	gf2x_add(25, g_sum+1435, 25, temp+7, 25, temp2+7);
	gf2x_mul_8_avx(temp, p_10+488, f_sum+1339);
	gf2x_mul_8_avx(temp2, p_11+488, g_sum+1339);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(9, g_sum+1435, 9, g_sum+1435, 9, temp+7);
	gf2x_mul_8_avx(temp, f_sum+1339, p_10+480);
	gf2x_mul_8_avx(temp2, g_sum+1339, p_11+480);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(1, g_sum+1435, 1, g_sum+1435, 1, temp+15);
	right_bit_shift_n(24, g_sum+1435, 60);
	
	delta = divstepsx_256(255, delta, f_sum+1441, g_sum+1441, p_00+504, p_01+504, p_10+504, p_11+504);

	// Calculating left operands: n: 510, depth: 6
	gf2x_mul_4_avx(temp, f_sum+1441, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1441, p_01+504);
	gf2x_add(8, f_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1437, p_00+504);
	gf2x_mul_4_avx(temp2, g_sum+1437, p_01+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1509, 4, f_sum+1509, 4, temp+4);
	right_bit_shift_n(8, f_sum+1509, 63);
	gf2x_mul_4_avx(temp, f_sum+1441, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1441, p_11+504);
	gf2x_add(8, g_sum+1509, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, f_sum+1437, p_10+504);
	gf2x_mul_4_avx(temp2, g_sum+1437, p_11+504);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1509, 4, g_sum+1509, 4, temp+4);
	right_bit_shift_n(8, g_sum+1509, 63);
	
	delta = divstepsx_256(255, delta, f_sum+1510, g_sum+1510, q_00+496, q_01+496, q_10+496, q_11+496);

	// Recombining results: n: 510, depth: 6
	gf2x_mul_4_avx(temp, q_00+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_10+504);
	gf2x_add(8, p_00+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_00+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_01+496, p_11+504);
	gf2x_add(8, p_01+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_00+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_10+504);
	gf2x_add(8, p_10+496, 8, temp, 8, temp2);
	gf2x_mul_4_avx(temp, q_10+496, p_01+504);
	gf2x_mul_4_avx(temp2, q_11+496, p_11+504);
	gf2x_add(8, p_11+496, 8, temp, 8, temp2);
	
	// Calculating left operands: n: 513, depth: 5
	gf2x_mul_8_avx(temp, f_sum+1437, p_00+496);
	gf2x_mul_8_avx(temp2, g_sum+1437, p_01+496);
	gf2x_add(9, f_sum+1484, 9, temp+7, 9, temp2+7);
	gf2x_mul_1_avx(temp, p_00+503, f_sum+1436);
	gf2x_mul_1_avx(temp2, p_01+503, g_sum+1436);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+1484, 1, f_sum+1484, 1, temp+1);
	right_bit_shift_n(9, f_sum+1484, 62);
	gf2x_mul_8_avx(temp, f_sum+1437, p_10+496);
	gf2x_mul_8_avx(temp2, g_sum+1437, p_11+496);
	gf2x_add(9, g_sum+1484, 9, temp+7, 9, temp2+7);
	gf2x_mul_1_avx(temp, p_10+503, f_sum+1436);
	gf2x_mul_1_avx(temp2, p_11+503, g_sum+1436);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+1484, 1, g_sum+1484, 1, temp+1);
	right_bit_shift_n(9, g_sum+1484, 62);
	
	delta = divstepsx(3, delta, *(f_sum+1485), *(g_sum+1485), q_00+488, q_01+488, q_10+488, q_11+488);

	// Recombining results: n: 513, depth: 5
	memset(q_00+472, 0x00, 7*DIGIT_SIZE_B);
	gf2x_mul_1_avx(temp, p_00+503, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+503, q_01+488);
	gf2x_add(2, q_00+479, 2, temp, 2, temp2);
	gf2x_mul_1_avx(temp, p_00+502, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+502, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+478, 2, q_00+478, 2, temp);
	gf2x_mul_1_avx(temp, p_00+501, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+501, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+477, 2, q_00+477, 2, temp);
	gf2x_mul_1_avx(temp, p_00+500, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+500, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+476, 2, q_00+476, 2, temp);
	gf2x_mul_1_avx(temp, p_00+499, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+499, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+475, 2, q_00+475, 2, temp);
	gf2x_mul_1_avx(temp, p_00+498, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+498, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+474, 2, q_00+474, 2, temp);
	gf2x_mul_1_avx(temp, p_00+497, q_00+488);
	gf2x_mul_1_avx(temp2, p_10+497, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+473, 2, q_00+473, 2, temp);
	gf2x_mul_1_avx(temp, q_00+488, p_00+496);
	gf2x_mul_1_avx(temp2, q_01+488, p_10+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+472, 2, q_00+472, 2, temp);
	memset(q_01+472, 0x00, 7*DIGIT_SIZE_B);
	gf2x_mul_1_avx(temp, p_01+503, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+503, q_01+488);
	gf2x_add(2, q_01+479, 2, temp, 2, temp2);
	gf2x_mul_1_avx(temp, p_01+502, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+502, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+478, 2, q_01+478, 2, temp);
	gf2x_mul_1_avx(temp, p_01+501, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+501, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+477, 2, q_01+477, 2, temp);
	gf2x_mul_1_avx(temp, p_01+500, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+500, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+476, 2, q_01+476, 2, temp);
	gf2x_mul_1_avx(temp, p_01+499, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+499, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+475, 2, q_01+475, 2, temp);
	gf2x_mul_1_avx(temp, p_01+498, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+498, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+474, 2, q_01+474, 2, temp);
	gf2x_mul_1_avx(temp, p_01+497, q_00+488);
	gf2x_mul_1_avx(temp2, p_11+497, q_01+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+473, 2, q_01+473, 2, temp);
	gf2x_mul_1_avx(temp, q_00+488, p_01+496);
	gf2x_mul_1_avx(temp2, q_01+488, p_11+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+472, 2, q_01+472, 2, temp);
	memset(q_10+472, 0x00, 7*DIGIT_SIZE_B);
	gf2x_mul_1_avx(temp, p_00+503, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+503, q_11+488);
	gf2x_add(2, q_10+479, 2, temp, 2, temp2);
	gf2x_mul_1_avx(temp, p_00+502, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+502, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+478, 2, q_10+478, 2, temp);
	gf2x_mul_1_avx(temp, p_00+501, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+501, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+477, 2, q_10+477, 2, temp);
	gf2x_mul_1_avx(temp, p_00+500, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+500, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+476, 2, q_10+476, 2, temp);
	gf2x_mul_1_avx(temp, p_00+499, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+499, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+475, 2, q_10+475, 2, temp);
	gf2x_mul_1_avx(temp, p_00+498, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+498, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+474, 2, q_10+474, 2, temp);
	gf2x_mul_1_avx(temp, p_00+497, q_10+488);
	gf2x_mul_1_avx(temp2, p_10+497, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+473, 2, q_10+473, 2, temp);
	gf2x_mul_1_avx(temp, q_10+488, p_00+496);
	gf2x_mul_1_avx(temp2, q_11+488, p_10+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+472, 2, q_10+472, 2, temp);
	memset(q_11+472, 0x00, 7*DIGIT_SIZE_B);
	gf2x_mul_1_avx(temp, p_01+503, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+503, q_11+488);
	gf2x_add(2, q_11+479, 2, temp, 2, temp2);
	gf2x_mul_1_avx(temp, p_01+502, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+502, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+478, 2, q_11+478, 2, temp);
	gf2x_mul_1_avx(temp, p_01+501, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+501, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+477, 2, q_11+477, 2, temp);
	gf2x_mul_1_avx(temp, p_01+500, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+500, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+476, 2, q_11+476, 2, temp);
	gf2x_mul_1_avx(temp, p_01+499, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+499, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+475, 2, q_11+475, 2, temp);
	gf2x_mul_1_avx(temp, p_01+498, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+498, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+474, 2, q_11+474, 2, temp);
	gf2x_mul_1_avx(temp, p_01+497, q_10+488);
	gf2x_mul_1_avx(temp2, p_11+497, q_11+488);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+473, 2, q_11+473, 2, temp);
	gf2x_mul_1_avx(temp, q_10+488, p_01+496);
	gf2x_mul_1_avx(temp2, q_11+488, p_11+496);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+472, 2, q_11+472, 2, temp);
	
	// Recombining results: n: 1533, depth: 4
	memset(q_00+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+487, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_10+487, 9, q_01+472);
	gf2x_add(18, q_00+446, 18, temp, 18, temp2);
	gf2x_mul_7_avx(temp, q_00+474, p_00+480);
	gf2x_mul_7_avx(temp2, q_01+474, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_00+441, 14, q_00+441, 14, temp);
	gf2x_mul_2_avx(temp, p_00+485, q_00+472);
	gf2x_mul_2_avx(temp2, p_10+485, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+444, 4, q_00+444, 4, temp);
	gf2x_mul_2_avx(temp, p_00+483, q_00+472);
	gf2x_mul_2_avx(temp2, p_10+483, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+442, 4, q_00+442, 4, temp);
	gf2x_mul_2_avx(temp, p_00+481, q_00+472);
	gf2x_mul_2_avx(temp2, p_10+481, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_00+440, 4, q_00+440, 4, temp);
	gf2x_mul_1_avx(temp, q_00+473, p_00+480);
	gf2x_mul_1_avx(temp2, q_01+473, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+440, 2, q_00+440, 2, temp);
	gf2x_mul_1_avx(temp, q_00+472, p_00+480);
	gf2x_mul_1_avx(temp2, q_01+472, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+440, 1, q_00+440, 1, temp+1);
	memset(q_01+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+487, 9, q_00+472);
	GF2X_MUL(18, temp2, 9, p_11+487, 9, q_01+472);
	gf2x_add(18, q_01+446, 18, temp, 18, temp2);
	gf2x_mul_7_avx(temp, q_00+474, p_01+480);
	gf2x_mul_7_avx(temp2, q_01+474, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_01+441, 14, q_01+441, 14, temp);
	gf2x_mul_2_avx(temp, p_01+485, q_00+472);
	gf2x_mul_2_avx(temp2, p_11+485, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+444, 4, q_01+444, 4, temp);
	gf2x_mul_2_avx(temp, p_01+483, q_00+472);
	gf2x_mul_2_avx(temp2, p_11+483, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+442, 4, q_01+442, 4, temp);
	gf2x_mul_2_avx(temp, p_01+481, q_00+472);
	gf2x_mul_2_avx(temp2, p_11+481, q_01+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_01+440, 4, q_01+440, 4, temp);
	gf2x_mul_1_avx(temp, q_00+473, p_01+480);
	gf2x_mul_1_avx(temp2, q_01+473, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+440, 2, q_01+440, 2, temp);
	gf2x_mul_1_avx(temp, q_00+472, p_01+480);
	gf2x_mul_1_avx(temp2, q_01+472, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+440, 1, q_01+440, 1, temp+1);
	memset(q_10+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_00+487, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_10+487, 9, q_11+472);
	gf2x_add(18, q_10+446, 18, temp, 18, temp2);
	gf2x_mul_7_avx(temp, q_10+474, p_00+480);
	gf2x_mul_7_avx(temp2, q_11+474, p_10+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_10+441, 14, q_10+441, 14, temp);
	gf2x_mul_2_avx(temp, p_00+485, q_10+472);
	gf2x_mul_2_avx(temp2, p_10+485, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+444, 4, q_10+444, 4, temp);
	gf2x_mul_2_avx(temp, p_00+483, q_10+472);
	gf2x_mul_2_avx(temp2, p_10+483, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+442, 4, q_10+442, 4, temp);
	gf2x_mul_2_avx(temp, p_00+481, q_10+472);
	gf2x_mul_2_avx(temp2, p_10+481, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_10+440, 4, q_10+440, 4, temp);
	gf2x_mul_1_avx(temp, q_10+473, p_00+480);
	gf2x_mul_1_avx(temp2, q_11+473, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+440, 2, q_10+440, 2, temp);
	gf2x_mul_1_avx(temp, q_10+472, p_00+480);
	gf2x_mul_1_avx(temp2, q_11+472, p_10+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+440, 1, q_10+440, 1, temp+1);
	memset(q_11+440, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(18, temp, 9, p_01+487, 9, q_10+472);
	GF2X_MUL(18, temp2, 9, p_11+487, 9, q_11+472);
	gf2x_add(18, q_11+446, 18, temp, 18, temp2);
	gf2x_mul_7_avx(temp, q_10+474, p_01+480);
	gf2x_mul_7_avx(temp2, q_11+474, p_11+480);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(14, q_11+441, 14, q_11+441, 14, temp);
	gf2x_mul_2_avx(temp, p_01+485, q_10+472);
	gf2x_mul_2_avx(temp2, p_11+485, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+444, 4, q_11+444, 4, temp);
	gf2x_mul_2_avx(temp, p_01+483, q_10+472);
	gf2x_mul_2_avx(temp2, p_11+483, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+442, 4, q_11+442, 4, temp);
	gf2x_mul_2_avx(temp, p_01+481, q_10+472);
	gf2x_mul_2_avx(temp2, p_11+481, q_11+472);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(4, q_11+440, 4, q_11+440, 4, temp);
	gf2x_mul_1_avx(temp, q_10+473, p_01+480);
	gf2x_mul_1_avx(temp2, q_11+473, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+440, 2, q_11+440, 2, temp);
	gf2x_mul_1_avx(temp, q_10+472, p_01+480);
	gf2x_mul_1_avx(temp2, q_11+472, p_11+480);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+440, 1, q_11+440, 1, temp+1);
	
	// Recombining results: n: 3573, depth: 3
	memset(q_00+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+456, 24, q_00+440);
	GF2X_MUL(48, temp2, 24, p_10+456, 24, q_01+440);
	gf2x_add(48, q_00+384, 48, temp, 48, temp2);
	gf2x_mul_8_avx(temp, q_00+456, p_00+448);
	gf2x_mul_8_avx(temp2, q_01+456, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+392, 16, q_00+392, 16, temp);
	gf2x_mul_8_avx(temp, q_00+448, p_00+448);
	gf2x_mul_8_avx(temp2, q_01+448, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+384, 16, q_00+384, 16, temp);
	gf2x_mul_8_avx(temp, q_00+440, p_00+448);
	gf2x_mul_8_avx(temp2, q_01+440, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+376, 16, q_00+376, 16, temp);
	memset(q_01+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+456, 24, q_00+440);
	GF2X_MUL(48, temp2, 24, p_11+456, 24, q_01+440);
	gf2x_add(48, q_01+384, 48, temp, 48, temp2);
	gf2x_mul_8_avx(temp, q_00+456, p_01+448);
	gf2x_mul_8_avx(temp2, q_01+456, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+392, 16, q_01+392, 16, temp);
	gf2x_mul_8_avx(temp, q_00+448, p_01+448);
	gf2x_mul_8_avx(temp2, q_01+448, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+384, 16, q_01+384, 16, temp);
	gf2x_mul_8_avx(temp, q_00+440, p_01+448);
	gf2x_mul_8_avx(temp2, q_01+440, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+376, 16, q_01+376, 16, temp);
	memset(q_10+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_00+456, 24, q_10+440);
	GF2X_MUL(48, temp2, 24, p_10+456, 24, q_11+440);
	gf2x_add(48, q_10+384, 48, temp, 48, temp2);
	gf2x_mul_8_avx(temp, q_10+456, p_00+448);
	gf2x_mul_8_avx(temp2, q_11+456, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+392, 16, q_10+392, 16, temp);
	gf2x_mul_8_avx(temp, q_10+448, p_00+448);
	gf2x_mul_8_avx(temp2, q_11+448, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+384, 16, q_10+384, 16, temp);
	gf2x_mul_8_avx(temp, q_10+440, p_00+448);
	gf2x_mul_8_avx(temp2, q_11+440, p_10+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+376, 16, q_10+376, 16, temp);
	memset(q_11+376, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(48, temp, 24, p_01+456, 24, q_10+440);
	GF2X_MUL(48, temp2, 24, p_11+456, 24, q_11+440);
	gf2x_add(48, q_11+384, 48, temp, 48, temp2);
	gf2x_mul_8_avx(temp, q_10+456, p_01+448);
	gf2x_mul_8_avx(temp2, q_11+456, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+392, 16, q_11+392, 16, temp);
	gf2x_mul_8_avx(temp, q_10+448, p_01+448);
	gf2x_mul_8_avx(temp2, q_11+448, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+384, 16, q_11+384, 16, temp);
	gf2x_mul_8_avx(temp, q_10+440, p_01+448);
	gf2x_mul_8_avx(temp2, q_11+440, p_11+448);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+376, 16, q_11+376, 16, temp);
	
	// Recombining results: n: 7653, depth: 2
	memset(q_00+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+392, 56, q_00+376);
	GF2X_MUL(112, temp2, 56, p_10+392, 56, q_01+376);
	gf2x_add(112, q_00+256, 112, temp, 112, temp2);
	gf2x_mul_8_avx(temp, q_00+424, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+424, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+296, 16, q_00+296, 16, temp);
	gf2x_mul_8_avx(temp, q_00+416, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+416, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+288, 16, q_00+288, 16, temp);
	gf2x_mul_8_avx(temp, q_00+408, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+408, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+280, 16, q_00+280, 16, temp);
	gf2x_mul_8_avx(temp, q_00+400, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+400, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+272, 16, q_00+272, 16, temp);
	gf2x_mul_8_avx(temp, q_00+392, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+392, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+264, 16, q_00+264, 16, temp);
	gf2x_mul_8_avx(temp, q_00+384, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+384, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+256, 16, q_00+256, 16, temp);
	gf2x_mul_8_avx(temp, q_00+376, p_00+384);
	gf2x_mul_8_avx(temp2, q_01+376, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+248, 16, q_00+248, 16, temp);
	memset(q_01+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+392, 56, q_00+376);
	GF2X_MUL(112, temp2, 56, p_11+392, 56, q_01+376);
	gf2x_add(112, q_01+256, 112, temp, 112, temp2);
	gf2x_mul_8_avx(temp, q_00+424, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+424, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+296, 16, q_01+296, 16, temp);
	gf2x_mul_8_avx(temp, q_00+416, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+416, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+288, 16, q_01+288, 16, temp);
	gf2x_mul_8_avx(temp, q_00+408, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+408, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+280, 16, q_01+280, 16, temp);
	gf2x_mul_8_avx(temp, q_00+400, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+400, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+272, 16, q_01+272, 16, temp);
	gf2x_mul_8_avx(temp, q_00+392, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+392, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+264, 16, q_01+264, 16, temp);
	gf2x_mul_8_avx(temp, q_00+384, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+384, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+256, 16, q_01+256, 16, temp);
	gf2x_mul_8_avx(temp, q_00+376, p_01+384);
	gf2x_mul_8_avx(temp2, q_01+376, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+248, 16, q_01+248, 16, temp);
	memset(q_10+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_00+392, 56, q_10+376);
	GF2X_MUL(112, temp2, 56, p_10+392, 56, q_11+376);
	gf2x_add(112, q_10+256, 112, temp, 112, temp2);
	gf2x_mul_8_avx(temp, q_10+424, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+424, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+296, 16, q_10+296, 16, temp);
	gf2x_mul_8_avx(temp, q_10+416, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+416, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+288, 16, q_10+288, 16, temp);
	gf2x_mul_8_avx(temp, q_10+408, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+408, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+280, 16, q_10+280, 16, temp);
	gf2x_mul_8_avx(temp, q_10+400, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+400, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+272, 16, q_10+272, 16, temp);
	gf2x_mul_8_avx(temp, q_10+392, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+392, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+264, 16, q_10+264, 16, temp);
	gf2x_mul_8_avx(temp, q_10+384, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+384, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+256, 16, q_10+256, 16, temp);
	gf2x_mul_8_avx(temp, q_10+376, p_00+384);
	gf2x_mul_8_avx(temp2, q_11+376, p_10+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+248, 16, q_10+248, 16, temp);
	memset(q_11+248, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(112, temp, 56, p_01+392, 56, q_10+376);
	GF2X_MUL(112, temp2, 56, p_11+392, 56, q_11+376);
	gf2x_add(112, q_11+256, 112, temp, 112, temp2);
	gf2x_mul_8_avx(temp, q_10+424, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+424, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+296, 16, q_11+296, 16, temp);
	gf2x_mul_8_avx(temp, q_10+416, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+416, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+288, 16, q_11+288, 16, temp);
	gf2x_mul_8_avx(temp, q_10+408, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+408, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+280, 16, q_11+280, 16, temp);
	gf2x_mul_8_avx(temp, q_10+400, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+400, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+272, 16, q_11+272, 16, temp);
	gf2x_mul_8_avx(temp, q_10+392, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+392, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+264, 16, q_11+264, 16, temp);
	gf2x_mul_8_avx(temp, q_10+384, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+384, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+256, 16, q_11+256, 16, temp);
	gf2x_mul_8_avx(temp, q_10+376, p_01+384);
	gf2x_mul_8_avx(temp2, q_11+376, p_11+384);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+248, 16, q_11+248, 16, temp);
	
	// Recombining results: n: 15813, depth: 1
	memset(q_00+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+264, 120, q_00+248);
	GF2X_MUL(240, temp2, 120, p_10+264, 120, q_01+248);
	gf2x_add(240, q_00+8, 240, temp, 240, temp2);
	gf2x_mul_8_avx(temp, q_00+360, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+360, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+112, 16, q_00+112, 16, temp);
	gf2x_mul_8_avx(temp, q_00+352, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+352, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+104, 16, q_00+104, 16, temp);
	gf2x_mul_8_avx(temp, q_00+344, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+344, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+96, 16, q_00+96, 16, temp);
	gf2x_mul_8_avx(temp, q_00+336, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+336, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+88, 16, q_00+88, 16, temp);
	gf2x_mul_8_avx(temp, q_00+328, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+328, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+80, 16, q_00+80, 16, temp);
	gf2x_mul_8_avx(temp, q_00+320, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+320, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+72, 16, q_00+72, 16, temp);
	gf2x_mul_8_avx(temp, q_00+312, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+312, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+64, 16, q_00+64, 16, temp);
	gf2x_mul_8_avx(temp, q_00+304, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+304, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+56, 16, q_00+56, 16, temp);
	gf2x_mul_8_avx(temp, q_00+296, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+296, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+48, 16, q_00+48, 16, temp);
	gf2x_mul_8_avx(temp, q_00+288, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+288, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+40, 16, q_00+40, 16, temp);
	gf2x_mul_8_avx(temp, q_00+280, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+280, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+32, 16, q_00+32, 16, temp);
	gf2x_mul_8_avx(temp, q_00+272, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+272, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+24, 16, q_00+24, 16, temp);
	gf2x_mul_8_avx(temp, q_00+264, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+264, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+16, 16, q_00+16, 16, temp);
	gf2x_mul_8_avx(temp, q_00+256, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+256, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+8, 16, q_00+8, 16, temp);
	gf2x_mul_8_avx(temp, q_00+248, p_00+256);
	gf2x_mul_8_avx(temp2, q_01+248, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_00+0, 16, q_00+0, 16, temp);
	memset(q_01+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+264, 120, q_00+248);
	GF2X_MUL(240, temp2, 120, p_11+264, 120, q_01+248);
	gf2x_add(240, q_01+8, 240, temp, 240, temp2);
	gf2x_mul_8_avx(temp, q_00+360, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+360, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+112, 16, q_01+112, 16, temp);
	gf2x_mul_8_avx(temp, q_00+352, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+352, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+104, 16, q_01+104, 16, temp);
	gf2x_mul_8_avx(temp, q_00+344, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+344, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+96, 16, q_01+96, 16, temp);
	gf2x_mul_8_avx(temp, q_00+336, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+336, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+88, 16, q_01+88, 16, temp);
	gf2x_mul_8_avx(temp, q_00+328, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+328, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+80, 16, q_01+80, 16, temp);
	gf2x_mul_8_avx(temp, q_00+320, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+320, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+72, 16, q_01+72, 16, temp);
	gf2x_mul_8_avx(temp, q_00+312, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+312, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+64, 16, q_01+64, 16, temp);
	gf2x_mul_8_avx(temp, q_00+304, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+304, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+56, 16, q_01+56, 16, temp);
	gf2x_mul_8_avx(temp, q_00+296, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+296, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+48, 16, q_01+48, 16, temp);
	gf2x_mul_8_avx(temp, q_00+288, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+288, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+40, 16, q_01+40, 16, temp);
	gf2x_mul_8_avx(temp, q_00+280, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+280, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+32, 16, q_01+32, 16, temp);
	gf2x_mul_8_avx(temp, q_00+272, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+272, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+24, 16, q_01+24, 16, temp);
	gf2x_mul_8_avx(temp, q_00+264, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+264, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+16, 16, q_01+16, 16, temp);
	gf2x_mul_8_avx(temp, q_00+256, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+256, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+8, 16, q_01+8, 16, temp);
	gf2x_mul_8_avx(temp, q_00+248, p_01+256);
	gf2x_mul_8_avx(temp2, q_01+248, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_01+0, 16, q_01+0, 16, temp);
	memset(q_10+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_00+264, 120, q_10+248);
	GF2X_MUL(240, temp2, 120, p_10+264, 120, q_11+248);
	gf2x_add(240, q_10+8, 240, temp, 240, temp2);
	gf2x_mul_8_avx(temp, q_10+360, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+360, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+112, 16, q_10+112, 16, temp);
	gf2x_mul_8_avx(temp, q_10+352, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+352, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+104, 16, q_10+104, 16, temp);
	gf2x_mul_8_avx(temp, q_10+344, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+344, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+96, 16, q_10+96, 16, temp);
	gf2x_mul_8_avx(temp, q_10+336, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+336, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+88, 16, q_10+88, 16, temp);
	gf2x_mul_8_avx(temp, q_10+328, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+328, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+80, 16, q_10+80, 16, temp);
	gf2x_mul_8_avx(temp, q_10+320, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+320, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+72, 16, q_10+72, 16, temp);
	gf2x_mul_8_avx(temp, q_10+312, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+312, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+64, 16, q_10+64, 16, temp);
	gf2x_mul_8_avx(temp, q_10+304, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+304, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+56, 16, q_10+56, 16, temp);
	gf2x_mul_8_avx(temp, q_10+296, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+296, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+48, 16, q_10+48, 16, temp);
	gf2x_mul_8_avx(temp, q_10+288, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+288, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+40, 16, q_10+40, 16, temp);
	gf2x_mul_8_avx(temp, q_10+280, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+280, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+32, 16, q_10+32, 16, temp);
	gf2x_mul_8_avx(temp, q_10+272, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+272, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+24, 16, q_10+24, 16, temp);
	gf2x_mul_8_avx(temp, q_10+264, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+264, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+16, 16, q_10+16, 16, temp);
	gf2x_mul_8_avx(temp, q_10+256, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+256, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+8, 16, q_10+8, 16, temp);
	gf2x_mul_8_avx(temp, q_10+248, p_00+256);
	gf2x_mul_8_avx(temp2, q_11+248, p_10+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_10+0, 16, q_10+0, 16, temp);
	memset(q_11+0, 0x00, 8*DIGIT_SIZE_B);
	GF2X_MUL(240, temp, 120, p_01+264, 120, q_10+248);
	GF2X_MUL(240, temp2, 120, p_11+264, 120, q_11+248);
	gf2x_add(240, q_11+8, 240, temp, 240, temp2);
	gf2x_mul_8_avx(temp, q_10+360, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+360, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+112, 16, q_11+112, 16, temp);
	gf2x_mul_8_avx(temp, q_10+352, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+352, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+104, 16, q_11+104, 16, temp);
	gf2x_mul_8_avx(temp, q_10+344, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+344, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+96, 16, q_11+96, 16, temp);
	gf2x_mul_8_avx(temp, q_10+336, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+336, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+88, 16, q_11+88, 16, temp);
	gf2x_mul_8_avx(temp, q_10+328, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+328, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+80, 16, q_11+80, 16, temp);
	gf2x_mul_8_avx(temp, q_10+320, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+320, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+72, 16, q_11+72, 16, temp);
	gf2x_mul_8_avx(temp, q_10+312, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+312, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+64, 16, q_11+64, 16, temp);
	gf2x_mul_8_avx(temp, q_10+304, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+304, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+56, 16, q_11+56, 16, temp);
	gf2x_mul_8_avx(temp, q_10+296, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+296, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+48, 16, q_11+48, 16, temp);
	gf2x_mul_8_avx(temp, q_10+288, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+288, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+40, 16, q_11+40, 16, temp);
	gf2x_mul_8_avx(temp, q_10+280, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+280, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+32, 16, q_11+32, 16, temp);
	gf2x_mul_8_avx(temp, q_10+272, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+272, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+24, 16, q_11+24, 16, temp);
	gf2x_mul_8_avx(temp, q_10+264, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+264, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+16, 16, q_11+16, 16, temp);
	gf2x_mul_8_avx(temp, q_10+256, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+256, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+8, 16, q_11+8, 16, temp);
	gf2x_mul_8_avx(temp, q_10+248, p_01+256);
	gf2x_mul_8_avx(temp2, q_11+248, p_11+256);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, q_11+0, 16, q_11+0, 16, temp);
	
	// Recombining results: n: 32133, depth: 0
	memset(t_00+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_10+8, 248, q_01+0);
	gf2x_add(496, t_00+7, 496, temp, 496, temp2);
	gf2x_mul_8_avx(temp, q_00+240, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+240, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+239, 16, t_00+239, 16, temp);
	gf2x_mul_8_avx(temp, q_00+232, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+232, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+231, 16, t_00+231, 16, temp);
	gf2x_mul_8_avx(temp, q_00+224, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+224, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+223, 16, t_00+223, 16, temp);
	gf2x_mul_8_avx(temp, q_00+216, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+216, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+215, 16, t_00+215, 16, temp);
	gf2x_mul_8_avx(temp, q_00+208, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+208, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+207, 16, t_00+207, 16, temp);
	gf2x_mul_8_avx(temp, q_00+200, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+200, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+199, 16, t_00+199, 16, temp);
	gf2x_mul_8_avx(temp, q_00+192, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+192, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+191, 16, t_00+191, 16, temp);
	gf2x_mul_8_avx(temp, q_00+184, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+184, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+183, 16, t_00+183, 16, temp);
	gf2x_mul_8_avx(temp, q_00+176, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+176, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+175, 16, t_00+175, 16, temp);
	gf2x_mul_8_avx(temp, q_00+168, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+168, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+167, 16, t_00+167, 16, temp);
	gf2x_mul_8_avx(temp, q_00+160, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+160, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+159, 16, t_00+159, 16, temp);
	gf2x_mul_8_avx(temp, q_00+152, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+152, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+151, 16, t_00+151, 16, temp);
	gf2x_mul_8_avx(temp, q_00+144, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+144, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+143, 16, t_00+143, 16, temp);
	gf2x_mul_8_avx(temp, q_00+136, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+136, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+135, 16, t_00+135, 16, temp);
	gf2x_mul_8_avx(temp, q_00+128, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+128, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+127, 16, t_00+127, 16, temp);
	gf2x_mul_8_avx(temp, q_00+120, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+120, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+119, 16, t_00+119, 16, temp);
	gf2x_mul_8_avx(temp, q_00+112, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+112, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+111, 16, t_00+111, 16, temp);
	gf2x_mul_8_avx(temp, q_00+104, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+104, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+103, 16, t_00+103, 16, temp);
	gf2x_mul_8_avx(temp, q_00+96, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+96, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+95, 16, t_00+95, 16, temp);
	gf2x_mul_8_avx(temp, q_00+88, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+88, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+87, 16, t_00+87, 16, temp);
	gf2x_mul_8_avx(temp, q_00+80, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+80, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+79, 16, t_00+79, 16, temp);
	gf2x_mul_8_avx(temp, q_00+72, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+72, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+71, 16, t_00+71, 16, temp);
	gf2x_mul_8_avx(temp, q_00+64, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+64, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+63, 16, t_00+63, 16, temp);
	gf2x_mul_8_avx(temp, q_00+56, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+56, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+55, 16, t_00+55, 16, temp);
	gf2x_mul_8_avx(temp, q_00+48, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+48, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+47, 16, t_00+47, 16, temp);
	gf2x_mul_8_avx(temp, q_00+40, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+40, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+39, 16, t_00+39, 16, temp);
	gf2x_mul_8_avx(temp, q_00+32, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+32, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+31, 16, t_00+31, 16, temp);
	gf2x_mul_8_avx(temp, q_00+24, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+24, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+23, 16, t_00+23, 16, temp);
	gf2x_mul_8_avx(temp, q_00+16, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+16, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+15, 16, t_00+15, 16, temp);
	gf2x_mul_8_avx(temp, q_00+8, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_00+7, 16, t_00+7, 16, temp);
	gf2x_mul_8_avx(temp, q_00+0, p_00+0);
	gf2x_mul_8_avx(temp2, q_01+0, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_00+0, 15, t_00+0, 15, temp+1);
	memset(t_01+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+8, 248, q_00+0);
	GF2X_MUL(496, temp2, 248, p_11+8, 248, q_01+0);
	gf2x_add(496, t_01+7, 496, temp, 496, temp2);
	gf2x_mul_8_avx(temp, q_00+240, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+240, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+239, 16, t_01+239, 16, temp);
	gf2x_mul_8_avx(temp, q_00+232, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+232, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+231, 16, t_01+231, 16, temp);
	gf2x_mul_8_avx(temp, q_00+224, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+224, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+223, 16, t_01+223, 16, temp);
	gf2x_mul_8_avx(temp, q_00+216, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+216, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+215, 16, t_01+215, 16, temp);
	gf2x_mul_8_avx(temp, q_00+208, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+208, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+207, 16, t_01+207, 16, temp);
	gf2x_mul_8_avx(temp, q_00+200, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+200, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+199, 16, t_01+199, 16, temp);
	gf2x_mul_8_avx(temp, q_00+192, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+192, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+191, 16, t_01+191, 16, temp);
	gf2x_mul_8_avx(temp, q_00+184, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+184, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+183, 16, t_01+183, 16, temp);
	gf2x_mul_8_avx(temp, q_00+176, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+176, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+175, 16, t_01+175, 16, temp);
	gf2x_mul_8_avx(temp, q_00+168, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+168, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+167, 16, t_01+167, 16, temp);
	gf2x_mul_8_avx(temp, q_00+160, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+160, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+159, 16, t_01+159, 16, temp);
	gf2x_mul_8_avx(temp, q_00+152, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+152, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+151, 16, t_01+151, 16, temp);
	gf2x_mul_8_avx(temp, q_00+144, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+144, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+143, 16, t_01+143, 16, temp);
	gf2x_mul_8_avx(temp, q_00+136, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+136, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+135, 16, t_01+135, 16, temp);
	gf2x_mul_8_avx(temp, q_00+128, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+128, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+127, 16, t_01+127, 16, temp);
	gf2x_mul_8_avx(temp, q_00+120, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+120, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+119, 16, t_01+119, 16, temp);
	gf2x_mul_8_avx(temp, q_00+112, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+112, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+111, 16, t_01+111, 16, temp);
	gf2x_mul_8_avx(temp, q_00+104, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+104, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+103, 16, t_01+103, 16, temp);
	gf2x_mul_8_avx(temp, q_00+96, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+96, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+95, 16, t_01+95, 16, temp);
	gf2x_mul_8_avx(temp, q_00+88, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+88, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+87, 16, t_01+87, 16, temp);
	gf2x_mul_8_avx(temp, q_00+80, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+80, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+79, 16, t_01+79, 16, temp);
	gf2x_mul_8_avx(temp, q_00+72, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+72, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+71, 16, t_01+71, 16, temp);
	gf2x_mul_8_avx(temp, q_00+64, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+64, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+63, 16, t_01+63, 16, temp);
	gf2x_mul_8_avx(temp, q_00+56, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+56, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+55, 16, t_01+55, 16, temp);
	gf2x_mul_8_avx(temp, q_00+48, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+48, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+47, 16, t_01+47, 16, temp);
	gf2x_mul_8_avx(temp, q_00+40, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+40, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+39, 16, t_01+39, 16, temp);
	gf2x_mul_8_avx(temp, q_00+32, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+32, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+31, 16, t_01+31, 16, temp);
	gf2x_mul_8_avx(temp, q_00+24, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+24, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+23, 16, t_01+23, 16, temp);
	gf2x_mul_8_avx(temp, q_00+16, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+16, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+15, 16, t_01+15, 16, temp);
	gf2x_mul_8_avx(temp, q_00+8, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_01+7, 16, t_01+7, 16, temp);
	gf2x_mul_8_avx(temp, q_00+0, p_01+0);
	gf2x_mul_8_avx(temp2, q_01+0, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_01+0, 15, t_01+0, 15, temp+1);
	memset(t_10+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_00+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_10+8, 248, q_11+0);
	gf2x_add(496, t_10+7, 496, temp, 496, temp2);
	gf2x_mul_8_avx(temp, q_10+240, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+240, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+239, 16, t_10+239, 16, temp);
	gf2x_mul_8_avx(temp, q_10+232, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+232, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+231, 16, t_10+231, 16, temp);
	gf2x_mul_8_avx(temp, q_10+224, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+224, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+223, 16, t_10+223, 16, temp);
	gf2x_mul_8_avx(temp, q_10+216, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+216, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+215, 16, t_10+215, 16, temp);
	gf2x_mul_8_avx(temp, q_10+208, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+208, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+207, 16, t_10+207, 16, temp);
	gf2x_mul_8_avx(temp, q_10+200, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+200, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+199, 16, t_10+199, 16, temp);
	gf2x_mul_8_avx(temp, q_10+192, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+192, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+191, 16, t_10+191, 16, temp);
	gf2x_mul_8_avx(temp, q_10+184, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+184, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+183, 16, t_10+183, 16, temp);
	gf2x_mul_8_avx(temp, q_10+176, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+176, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+175, 16, t_10+175, 16, temp);
	gf2x_mul_8_avx(temp, q_10+168, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+168, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+167, 16, t_10+167, 16, temp);
	gf2x_mul_8_avx(temp, q_10+160, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+160, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+159, 16, t_10+159, 16, temp);
	gf2x_mul_8_avx(temp, q_10+152, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+152, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+151, 16, t_10+151, 16, temp);
	gf2x_mul_8_avx(temp, q_10+144, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+144, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+143, 16, t_10+143, 16, temp);
	gf2x_mul_8_avx(temp, q_10+136, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+136, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+135, 16, t_10+135, 16, temp);
	gf2x_mul_8_avx(temp, q_10+128, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+128, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+127, 16, t_10+127, 16, temp);
	gf2x_mul_8_avx(temp, q_10+120, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+120, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+119, 16, t_10+119, 16, temp);
	gf2x_mul_8_avx(temp, q_10+112, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+112, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+111, 16, t_10+111, 16, temp);
	gf2x_mul_8_avx(temp, q_10+104, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+104, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+103, 16, t_10+103, 16, temp);
	gf2x_mul_8_avx(temp, q_10+96, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+96, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+95, 16, t_10+95, 16, temp);
	gf2x_mul_8_avx(temp, q_10+88, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+88, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+87, 16, t_10+87, 16, temp);
	gf2x_mul_8_avx(temp, q_10+80, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+80, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+79, 16, t_10+79, 16, temp);
	gf2x_mul_8_avx(temp, q_10+72, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+72, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+71, 16, t_10+71, 16, temp);
	gf2x_mul_8_avx(temp, q_10+64, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+64, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+63, 16, t_10+63, 16, temp);
	gf2x_mul_8_avx(temp, q_10+56, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+56, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+55, 16, t_10+55, 16, temp);
	gf2x_mul_8_avx(temp, q_10+48, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+48, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+47, 16, t_10+47, 16, temp);
	gf2x_mul_8_avx(temp, q_10+40, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+40, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+39, 16, t_10+39, 16, temp);
	gf2x_mul_8_avx(temp, q_10+32, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+32, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+31, 16, t_10+31, 16, temp);
	gf2x_mul_8_avx(temp, q_10+24, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+24, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+23, 16, t_10+23, 16, temp);
	gf2x_mul_8_avx(temp, q_10+16, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+16, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+15, 16, t_10+15, 16, temp);
	gf2x_mul_8_avx(temp, q_10+8, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+8, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_10+7, 16, t_10+7, 16, temp);
	gf2x_mul_8_avx(temp, q_10+0, p_00+0);
	gf2x_mul_8_avx(temp2, q_11+0, p_10+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_10+0, 15, t_10+0, 15, temp+1);
	memset(t_11+0, 0x00, 7*DIGIT_SIZE_B);
	GF2X_MUL(496, temp, 248, p_01+8, 248, q_10+0);
	GF2X_MUL(496, temp2, 248, p_11+8, 248, q_11+0);
	gf2x_add(496, t_11+7, 496, temp, 496, temp2);
	gf2x_mul_8_avx(temp, q_10+240, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+240, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+239, 16, t_11+239, 16, temp);
	gf2x_mul_8_avx(temp, q_10+232, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+232, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+231, 16, t_11+231, 16, temp);
	gf2x_mul_8_avx(temp, q_10+224, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+224, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+223, 16, t_11+223, 16, temp);
	gf2x_mul_8_avx(temp, q_10+216, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+216, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+215, 16, t_11+215, 16, temp);
	gf2x_mul_8_avx(temp, q_10+208, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+208, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+207, 16, t_11+207, 16, temp);
	gf2x_mul_8_avx(temp, q_10+200, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+200, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+199, 16, t_11+199, 16, temp);
	gf2x_mul_8_avx(temp, q_10+192, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+192, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+191, 16, t_11+191, 16, temp);
	gf2x_mul_8_avx(temp, q_10+184, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+184, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+183, 16, t_11+183, 16, temp);
	gf2x_mul_8_avx(temp, q_10+176, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+176, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+175, 16, t_11+175, 16, temp);
	gf2x_mul_8_avx(temp, q_10+168, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+168, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+167, 16, t_11+167, 16, temp);
	gf2x_mul_8_avx(temp, q_10+160, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+160, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+159, 16, t_11+159, 16, temp);
	gf2x_mul_8_avx(temp, q_10+152, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+152, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+151, 16, t_11+151, 16, temp);
	gf2x_mul_8_avx(temp, q_10+144, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+144, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+143, 16, t_11+143, 16, temp);
	gf2x_mul_8_avx(temp, q_10+136, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+136, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+135, 16, t_11+135, 16, temp);
	gf2x_mul_8_avx(temp, q_10+128, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+128, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+127, 16, t_11+127, 16, temp);
	gf2x_mul_8_avx(temp, q_10+120, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+120, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+119, 16, t_11+119, 16, temp);
	gf2x_mul_8_avx(temp, q_10+112, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+112, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+111, 16, t_11+111, 16, temp);
	gf2x_mul_8_avx(temp, q_10+104, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+104, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+103, 16, t_11+103, 16, temp);
	gf2x_mul_8_avx(temp, q_10+96, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+96, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+95, 16, t_11+95, 16, temp);
	gf2x_mul_8_avx(temp, q_10+88, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+88, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+87, 16, t_11+87, 16, temp);
	gf2x_mul_8_avx(temp, q_10+80, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+80, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+79, 16, t_11+79, 16, temp);
	gf2x_mul_8_avx(temp, q_10+72, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+72, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+71, 16, t_11+71, 16, temp);
	gf2x_mul_8_avx(temp, q_10+64, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+64, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+63, 16, t_11+63, 16, temp);
	gf2x_mul_8_avx(temp, q_10+56, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+56, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+55, 16, t_11+55, 16, temp);
	gf2x_mul_8_avx(temp, q_10+48, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+48, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+47, 16, t_11+47, 16, temp);
	gf2x_mul_8_avx(temp, q_10+40, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+40, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+39, 16, t_11+39, 16, temp);
	gf2x_mul_8_avx(temp, q_10+32, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+32, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+31, 16, t_11+31, 16, temp);
	gf2x_mul_8_avx(temp, q_10+24, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+24, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+23, 16, t_11+23, 16, temp);
	gf2x_mul_8_avx(temp, q_10+16, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+16, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+15, 16, t_11+15, 16, temp);
	gf2x_mul_8_avx(temp, q_10+8, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+8, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(16, t_11+7, 16, t_11+7, 16, temp);
	gf2x_mul_8_avx(temp, q_10+0, p_01+0);
	gf2x_mul_8_avx(temp2, q_11+0, p_11+0);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(15, t_11+0, 15, t_11+0, 15, temp+1);
	
	return delta;
}