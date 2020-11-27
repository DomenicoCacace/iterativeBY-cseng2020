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

int jumpdivstep_19709(int n, int delta, int nf, DIGIT *f, DIGIT *g, DIGIT *t_00, DIGIT *t_01, DIGIT *t_10, DIGIT *t_11, float x) {
	DIGIT p_00[631];
	DIGIT p_01[631];
	DIGIT p_10[631];
	DIGIT p_11[631];
	
	DIGIT q_00[614];
	DIGIT q_01[614];
	DIGIT q_10[614];
	DIGIT q_11[614];
	
	DIGIT f_sum[1883];
	DIGIT g_sum[1883];
	
	DIGIT temp[1237];
	DIGIT temp2[1237];
	

	delta = divstepsx_256(255, delta, f+612, g+612, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f+608+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g+608+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+608+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g+608+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f+608+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g+608+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f+608+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g+608+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f+604+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g+604+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f+604);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g+604);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f+604+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g+604+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f+604);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g+604);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f+596+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g+596+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f+596);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g+596);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f+596+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g+596+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f+596);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g+596);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f+576+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g+576+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f+576+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g+576+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f+576+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g+576+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f+576+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g+576+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f+536+40, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g+536+40, 40, p_01+547);
	gf2x_add(80, f_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f+536+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g+536+0, 40, p_01+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1633, 40, f_sum+1633, 40, temp+40);
	right_bit_shift_n(80, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f+536+40, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g+536+40, 40, p_11+547);
	gf2x_add(80, g_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f+536+0, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g+536+0, 40, p_11+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1633, 40, g_sum+1633, 40, temp+40);
	right_bit_shift_n(80, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1670, g_sum+1670, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, q_00+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, q_01+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, q_10+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, q_11+538+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 3
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_10+547);
	gf2x_add(80, p_00+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_11+547);
	gf2x_add(80, p_01+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_10+547);
	gf2x_add(80, p_10+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_11+547);
	gf2x_add(80, p_11+467+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 9945, depth: 2
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f+460+76, 80, p_00+467);
	GF2X_MUL(160, temp2, 80, g+460+76, 80, p_01+467);
	gf2x_add(156, f_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, f+460);
	GF2X_MUL(152, temp2, 76, p_01+467+4, 76, g+460);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, f_sum+1396, 76, f_sum+1396, 76, temp+76);
	right_bit_shift_n(156, f_sum+1396, 44);
	GF2X_MUL(160, temp, 80, f+460+76, 80, p_10+467);
	GF2X_MUL(160, temp2, 80, g+460+76, 80, p_11+467);
	gf2x_add(156, g_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_10+467+4, 76, f+460);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, g+460);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, g_sum+1396, 76, g_sum+1396, 76, temp+76);
	right_bit_shift_n(156, g_sum+1396, 44);
	

	delta = divstepsx_256(255, delta, f_sum+1469, g_sum+1469, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4845, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_01+547);
	gf2x_add(76, f_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_01+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+1633, 36, f_sum+1633, 36, temp+36);
	right_bit_shift_n(76, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_11+547);
	gf2x_add(76, g_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_10+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+1633, 36, g_sum+1633, 36, temp+36);
	right_bit_shift_n(76, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1666, g_sum+1666, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_01+587);
	gf2x_add(36, f_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_01+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1754, 16, f_sum+1754, 16, temp+16);
	right_bit_shift_n(36, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_11+587);
	gf2x_add(36, g_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1754, 16, g_sum+1754, 16, temp+16);
	right_bit_shift_n(36, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1767, g_sum+1767, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, p_00+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, p_01+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, p_10+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, p_11+607+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_01+607);
	gf2x_add(16, f_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_01+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(16, f_sum+1815, 62);
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_11+607);
	gf2x_add(16, g_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_11+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(16, g_sum+1815, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_10+607);
	gf2x_add(16, q_00+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_11+607);
	gf2x_add(16, q_01+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_10+607);
	gf2x_add(16, q_10+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_11+607);
	gf2x_add(16, q_11+578+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 4
	memset(q_00+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_01+578);
	gf2x_add(32, q_00+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+12, 8, q_00+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+8, 8, q_00+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+4, 8, q_00+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+0, 8, q_00+538+0, 8, temp);
	memset(q_01+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_01+578);
	gf2x_add(32, q_01+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+12, 8, q_01+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+8, 8, q_01+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+4, 8, q_01+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+0, 8, q_01+538+0, 8, temp);
	memset(q_10+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_11+578);
	gf2x_add(32, q_10+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+12, 8, q_10+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+8, 8, q_10+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+4, 8, q_10+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+0, 8, q_10+538+0, 8, temp);
	memset(q_11+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_11+578);
	gf2x_add(32, q_11+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+12, 8, q_11+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+8, 8, q_11+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+4, 8, q_11+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+0, 8, q_11+538+0, 8, temp);
	

	// Recombining results: n: 4845, depth: 3
	memset(q_00+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_01+538);
	gf2x_add(72, q_00+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+32, 8, q_00+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+28, 8, q_00+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+24, 8, q_00+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+20, 8, q_00+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+16, 8, q_00+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+12, 8, q_00+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+8, 8, q_00+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+4, 8, q_00+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+0, 8, q_00+462+0, 8, temp);
	memset(q_01+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_01+538);
	gf2x_add(72, q_01+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+32, 8, q_01+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+28, 8, q_01+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+24, 8, q_01+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+20, 8, q_01+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+16, 8, q_01+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+12, 8, q_01+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+8, 8, q_01+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+4, 8, q_01+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+0, 8, q_01+462+0, 8, temp);
	memset(q_10+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_11+538);
	gf2x_add(72, q_10+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+32, 8, q_10+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+28, 8, q_10+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+24, 8, q_10+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+20, 8, q_10+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+16, 8, q_10+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+12, 8, q_10+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+8, 8, q_10+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+4, 8, q_10+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+0, 8, q_10+462+0, 8, temp);
	memset(q_11+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_11+538);
	gf2x_add(72, q_11+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+32, 8, q_11+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+28, 8, q_11+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+24, 8, q_11+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+20, 8, q_11+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+16, 8, q_11+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+12, 8, q_11+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+8, 8, q_11+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+4, 8, q_11+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+0, 8, q_11+462+0, 8, temp);
	

	// Recombining results: n: 9945, depth: 2
	memset(p_00+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_01+462);
	gf2x_add(152, p_00+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+72, 8, p_00+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+68, 8, p_00+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+64, 8, p_00+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+60, 8, p_00+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+56, 8, p_00+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+52, 8, p_00+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+48, 8, p_00+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+44, 8, p_00+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+40, 8, p_00+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+36, 8, p_00+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+32, 8, p_00+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+28, 8, p_00+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+24, 8, p_00+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+20, 8, p_00+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+16, 8, p_00+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+12, 8, p_00+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+8, 8, p_00+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+4, 8, p_00+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+0, 8, p_00+311+0, 8, temp);
	memset(p_01+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_01+462);
	gf2x_add(152, p_01+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+72, 8, p_01+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+68, 8, p_01+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+64, 8, p_01+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+60, 8, p_01+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+56, 8, p_01+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+52, 8, p_01+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+48, 8, p_01+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+44, 8, p_01+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+40, 8, p_01+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+36, 8, p_01+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+32, 8, p_01+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+28, 8, p_01+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+24, 8, p_01+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+20, 8, p_01+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+16, 8, p_01+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+12, 8, p_01+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+8, 8, p_01+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+4, 8, p_01+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+0, 8, p_01+311+0, 8, temp);
	memset(p_10+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_11+462);
	gf2x_add(152, p_10+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+72, 8, p_10+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+68, 8, p_10+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+64, 8, p_10+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+60, 8, p_10+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+56, 8, p_10+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+52, 8, p_10+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+48, 8, p_10+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+44, 8, p_10+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+40, 8, p_10+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+36, 8, p_10+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+32, 8, p_10+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+28, 8, p_10+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+24, 8, p_10+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+20, 8, p_10+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+16, 8, p_10+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+12, 8, p_10+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+8, 8, p_10+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+4, 8, p_10+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+0, 8, p_10+311+0, 8, temp);
	memset(p_11+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_11+462);
	gf2x_add(152, p_11+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+72, 8, p_11+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+68, 8, p_11+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+64, 8, p_11+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+60, 8, p_11+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+56, 8, p_11+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+52, 8, p_11+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+48, 8, p_11+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+44, 8, p_11+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+40, 8, p_11+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+36, 8, p_11+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+32, 8, p_11+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+28, 8, p_11+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+24, 8, p_11+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+20, 8, p_11+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+16, 8, p_11+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+12, 8, p_11+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+8, 8, p_11+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+4, 8, p_11+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+0, 8, p_11+311+0, 8, temp);
	

	// Calculating left operands: n: 19890, depth: 1
	// Digits to shift: 155
	// Displacement: 155
	GF2X_MUL(312, temp, 156, f+305+155, 156, p_00+311);
	GF2X_MUL(312, temp2, 156, g+305+155, 156, p_01+311);
	gf2x_add(312, f_sum+928+0, 312, temp, 312, temp2);
	GF2X_MUL(310, temp, 155, p_00+311+1, 155, f+305);
	GF2X_MUL(310, temp2, 155, p_01+311+1, 155, g+305);
	gf2x_add(310, temp, 310, temp, 310, temp2);
	gf2x_add(156, f_sum+928, 156, f_sum+928, 156, temp+154);
	GF2X_MUL(2, temp, 1, f+305+154, 1, p_00+311);
	GF2X_MUL(2, temp2, 1, g+305+154, 1, p_01+311);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, f_sum+928, 1, f_sum+928, 1, temp+1);
	right_bit_shift_n(311, f_sum+928, 25);
	GF2X_MUL(312, temp, 156, f+305+155, 156, p_10+311);
	GF2X_MUL(312, temp2, 156, g+305+155, 156, p_11+311);
	gf2x_add(312, g_sum+928+0, 312, temp, 312, temp2);
	GF2X_MUL(310, temp, 155, p_10+311+1, 155, f+305);
	GF2X_MUL(310, temp2, 155, p_11+311+1, 155, g+305);
	gf2x_add(310, temp, 310, temp, 310, temp2);
	gf2x_add(156, g_sum+928, 156, g_sum+928, 156, temp+154);
	GF2X_MUL(2, temp, 1, f+305+154, 1, p_10+311);
	GF2X_MUL(2, temp2, 1, g+305+154, 1, p_11+311);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, g_sum+928, 1, g_sum+928, 1, temp+1);
	right_bit_shift_n(311, g_sum+928, 25);
	

	delta = divstepsx_256(255, delta, f_sum+1081, g_sum+1081, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1077+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1077+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1077+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1077+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1077+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1077+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1077+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1077+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1073+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1073+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1073);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1073);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1073+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1073+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1073);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1073);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1065+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1065+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1065);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1065);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1065+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1065+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1065);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1065);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1045+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1045+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1045+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1045+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1045+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1045+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1045+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1045+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1005+40, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1005+40, 40, p_01+547);
	gf2x_add(80, f_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1005+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1005+0, 40, p_01+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1633, 40, f_sum+1633, 40, temp+40);
	right_bit_shift_n(80, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1005+40, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1005+40, 40, p_11+547);
	gf2x_add(80, g_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+1005+0, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1005+0, 40, p_11+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1633, 40, g_sum+1633, 40, temp+40);
	right_bit_shift_n(80, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1670, g_sum+1670, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, q_00+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, q_01+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, q_10+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, q_11+538+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 3
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_10+547);
	gf2x_add(80, p_00+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_11+547);
	gf2x_add(80, p_01+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_10+547);
	gf2x_add(80, p_10+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_11+547);
	gf2x_add(80, p_11+467+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 9945, depth: 2
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+929+76, 80, p_00+467);
	GF2X_MUL(160, temp2, 80, g_sum+929+76, 80, p_01+467);
	gf2x_add(156, f_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, f_sum+929);
	GF2X_MUL(152, temp2, 76, p_01+467+4, 76, g_sum+929);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, f_sum+1396, 76, f_sum+1396, 76, temp+76);
	right_bit_shift_n(156, f_sum+1396, 44);
	GF2X_MUL(160, temp, 80, f_sum+929+76, 80, p_10+467);
	GF2X_MUL(160, temp2, 80, g_sum+929+76, 80, p_11+467);
	gf2x_add(156, g_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_10+467+4, 76, f_sum+929);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, g_sum+929);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, g_sum+1396, 76, g_sum+1396, 76, temp+76);
	right_bit_shift_n(156, g_sum+1396, 44);
	

	delta = divstepsx_256(255, delta, f_sum+1469, g_sum+1469, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4845, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_01+547);
	gf2x_add(76, f_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_01+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+1633, 36, f_sum+1633, 36, temp+36);
	right_bit_shift_n(76, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_11+547);
	gf2x_add(76, g_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_10+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+1633, 36, g_sum+1633, 36, temp+36);
	right_bit_shift_n(76, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1666, g_sum+1666, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_01+587);
	gf2x_add(36, f_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_01+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1754, 16, f_sum+1754, 16, temp+16);
	right_bit_shift_n(36, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_11+587);
	gf2x_add(36, g_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1754, 16, g_sum+1754, 16, temp+16);
	right_bit_shift_n(36, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1767, g_sum+1767, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, p_00+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, p_01+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, p_10+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, p_11+607+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_01+607);
	gf2x_add(16, f_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_01+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(16, f_sum+1815, 62);
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_11+607);
	gf2x_add(16, g_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_11+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(16, g_sum+1815, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_10+607);
	gf2x_add(16, q_00+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_11+607);
	gf2x_add(16, q_01+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_10+607);
	gf2x_add(16, q_10+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_11+607);
	gf2x_add(16, q_11+578+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 4
	memset(q_00+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_01+578);
	gf2x_add(32, q_00+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+12, 8, q_00+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+8, 8, q_00+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+4, 8, q_00+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+0, 8, q_00+538+0, 8, temp);
	memset(q_01+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_01+578);
	gf2x_add(32, q_01+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+12, 8, q_01+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+8, 8, q_01+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+4, 8, q_01+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+0, 8, q_01+538+0, 8, temp);
	memset(q_10+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_11+578);
	gf2x_add(32, q_10+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+12, 8, q_10+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+8, 8, q_10+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+4, 8, q_10+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+0, 8, q_10+538+0, 8, temp);
	memset(q_11+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_11+578);
	gf2x_add(32, q_11+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+12, 8, q_11+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+8, 8, q_11+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+4, 8, q_11+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+0, 8, q_11+538+0, 8, temp);
	

	// Recombining results: n: 4845, depth: 3
	memset(q_00+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_01+538);
	gf2x_add(72, q_00+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+32, 8, q_00+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+28, 8, q_00+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+24, 8, q_00+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+20, 8, q_00+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+16, 8, q_00+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+12, 8, q_00+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+8, 8, q_00+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+4, 8, q_00+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+0, 8, q_00+462+0, 8, temp);
	memset(q_01+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_01+538);
	gf2x_add(72, q_01+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+32, 8, q_01+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+28, 8, q_01+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+24, 8, q_01+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+20, 8, q_01+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+16, 8, q_01+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+12, 8, q_01+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+8, 8, q_01+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+4, 8, q_01+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+0, 8, q_01+462+0, 8, temp);
	memset(q_10+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_11+538);
	gf2x_add(72, q_10+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+32, 8, q_10+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+28, 8, q_10+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+24, 8, q_10+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+20, 8, q_10+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+16, 8, q_10+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+12, 8, q_10+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+8, 8, q_10+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+4, 8, q_10+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+0, 8, q_10+462+0, 8, temp);
	memset(q_11+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_11+538);
	gf2x_add(72, q_11+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+32, 8, q_11+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+28, 8, q_11+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+24, 8, q_11+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+20, 8, q_11+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+16, 8, q_11+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+12, 8, q_11+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+8, 8, q_11+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+4, 8, q_11+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+0, 8, q_11+462+0, 8, temp);
	

	// Recombining results: n: 9945, depth: 2
	memset(q_00+306, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_01+462);
	gf2x_add(152, q_00+306+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+72, 8, q_00+306+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+68, 8, q_00+306+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+64, 8, q_00+306+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+60, 8, q_00+306+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+56, 8, q_00+306+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+52, 8, q_00+306+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+48, 8, q_00+306+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+44, 8, q_00+306+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+40, 8, q_00+306+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+36, 8, q_00+306+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+32, 8, q_00+306+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+28, 8, q_00+306+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+24, 8, q_00+306+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+20, 8, q_00+306+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+16, 8, q_00+306+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+12, 8, q_00+306+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+8, 8, q_00+306+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+4, 8, q_00+306+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+306+0, 8, q_00+306+0, 8, temp);
	memset(q_01+306, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_01+462);
	gf2x_add(152, q_01+306+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+72, 8, q_01+306+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+68, 8, q_01+306+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+64, 8, q_01+306+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+60, 8, q_01+306+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+56, 8, q_01+306+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+52, 8, q_01+306+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+48, 8, q_01+306+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+44, 8, q_01+306+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+40, 8, q_01+306+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+36, 8, q_01+306+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+32, 8, q_01+306+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+28, 8, q_01+306+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+24, 8, q_01+306+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+20, 8, q_01+306+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+16, 8, q_01+306+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+12, 8, q_01+306+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+8, 8, q_01+306+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+4, 8, q_01+306+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+306+0, 8, q_01+306+0, 8, temp);
	memset(q_10+306, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_11+462);
	gf2x_add(152, q_10+306+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+72, 8, q_10+306+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+68, 8, q_10+306+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+64, 8, q_10+306+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+60, 8, q_10+306+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+56, 8, q_10+306+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+52, 8, q_10+306+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+48, 8, q_10+306+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+44, 8, q_10+306+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+40, 8, q_10+306+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+36, 8, q_10+306+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+32, 8, q_10+306+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+28, 8, q_10+306+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+24, 8, q_10+306+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+20, 8, q_10+306+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+16, 8, q_10+306+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+12, 8, q_10+306+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+8, 8, q_10+306+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+4, 8, q_10+306+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+306+0, 8, q_10+306+0, 8, temp);
	memset(q_11+306, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_11+462);
	gf2x_add(152, q_11+306+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+72, 8, q_11+306+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+68, 8, q_11+306+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+64, 8, q_11+306+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+60, 8, q_11+306+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+56, 8, q_11+306+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+52, 8, q_11+306+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+48, 8, q_11+306+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+44, 8, q_11+306+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+40, 8, q_11+306+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+36, 8, q_11+306+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+32, 8, q_11+306+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+28, 8, q_11+306+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+24, 8, q_11+306+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+20, 8, q_11+306+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+16, 8, q_11+306+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+12, 8, q_11+306+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+8, 8, q_11+306+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+4, 8, q_11+306+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+306+0, 8, q_11+306+0, 8, temp);
	

	// Recombining results: n: 19890, depth: 1
	GF2X_MUL(312, temp, 156, q_00+306+0, 156, p_00+311);
	GF2X_MUL(312, temp2, 156, q_01+306+0, 156, p_10+311);
	gf2x_add(311, p_00+0, 311, temp+1, 311, temp2+1);
	GF2X_MUL(312, temp, 156, q_00+306+0, 156, p_01+311);
	GF2X_MUL(312, temp2, 156, q_01+306+0, 156, p_11+311);
	gf2x_add(311, p_01+0, 311, temp+1, 311, temp2+1);
	GF2X_MUL(312, temp, 156, q_10+306+0, 156, p_00+311);
	GF2X_MUL(312, temp2, 156, q_11+306+0, 156, p_10+311);
	gf2x_add(311, p_10+0, 311, temp+1, 311, temp2+1);
	GF2X_MUL(312, temp, 156, q_10+306+0, 156, p_01+311);
	GF2X_MUL(312, temp2, 156, q_11+306+0, 156, p_11+311);
	gf2x_add(311, p_11+0, 311, temp+1, 311, temp2+1);
	

	// Calculating left operands: n: 39417, depth: 0
	// Digits to shift: 310
	// Displacement: 310
	GF2X_MUL(622, temp, 311, f+0+305, 311, p_00+0);
	GF2X_MUL(622, temp2, 311, g+0+305, 311, p_01+0);
	gf2x_add(617, f_sum+0, 617, temp+5, 617, temp2+5);
	GF2X_MUL(610, temp, 305, p_00+0+6, 305, f+0);
	GF2X_MUL(610, temp2, 305, p_01+0+6, 305, g+0);
	gf2x_add(610, temp, 610, temp, 610, temp2);
	gf2x_add(306, f_sum+0, 306, f_sum+0, 306, temp+304);
	GF2X_MUL(12, temp, 6, f+0+299, 6, p_00+0);
	GF2X_MUL(12, temp2, 6, g+0+299, 6, p_01+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, f_sum+0, 1, f_sum+0, 1, temp+11);
	right_bit_shift_n(616, f_sum+0, 50);
	GF2X_MUL(622, temp, 311, f+0+305, 311, p_10+0);
	GF2X_MUL(622, temp2, 311, g+0+305, 311, p_11+0);
	gf2x_add(617, g_sum+0, 617, temp+5, 617, temp2+5);
	GF2X_MUL(610, temp, 305, p_10+0+6, 305, f+0);
	GF2X_MUL(610, temp2, 305, p_11+0+6, 305, g+0);
	gf2x_add(610, temp, 610, temp, 610, temp2);
	gf2x_add(306, g_sum+0, 306, g_sum+0, 306, temp+304);
	GF2X_MUL(12, temp, 6, f+0+299, 6, p_10+0);
	GF2X_MUL(12, temp2, 6, g+0+299, 6, p_11+0);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(1, g_sum+0, 1, g_sum+0, 1, temp+11);
	right_bit_shift_n(616, g_sum+0, 50);
	

	delta = divstepsx_256(255, delta, f_sum+303, g_sum+303, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+299+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+299+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+299+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+299+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+299+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+299+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+299+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+299+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+295+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+295+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+295);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+295);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+295+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+295+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+295);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+295);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+287+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+287+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+287);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+287);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+287+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+287+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+287);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+287);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+267+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+267+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+267+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+267+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+267+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+267+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+267+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+267+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 5100, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+227+40, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+227+40, 40, p_01+547);
	gf2x_add(80, f_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+227+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+227+0, 40, p_01+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, f_sum+1633, 40, f_sum+1633, 40, temp+40);
	right_bit_shift_n(80, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+227+40, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+227+40, 40, p_11+547);
	gf2x_add(80, g_sum+1633+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, f_sum+227+0, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+227+0, 40, p_11+547);
	gf2x_add(80, temp, 80, temp, 80, temp2);
	gf2x_add(40, g_sum+1633, 40, g_sum+1633, 40, temp+40);
	right_bit_shift_n(80, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1670, g_sum+1670, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1666+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1666+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1666+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1662+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1662+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1662);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1662);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1654+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1654+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1654);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1654);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1634+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, q_00+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, q_01+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, q_10+538+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, q_11+538+0, 40, temp, 40, temp2);
	

	// Recombining results: n: 5100, depth: 3
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_10+547);
	gf2x_add(80, p_00+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_00+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_01+538+0, 40, p_11+547);
	gf2x_add(80, p_01+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_10+547);
	gf2x_add(80, p_10+467+0, 80, temp, 80, temp2);
	GF2X_MUL(80, temp, 40, q_10+538+0, 40, p_01+547);
	GF2X_MUL(80, temp2, 40, q_11+538+0, 40, p_11+547);
	gf2x_add(80, p_11+467+0, 80, temp, 80, temp2);
	

	// Calculating left operands: n: 9945, depth: 2
	// Digits to shift: 79
	// Displacement: 80
	GF2X_MUL(160, temp, 80, f_sum+151+76, 80, p_00+467);
	GF2X_MUL(160, temp2, 80, g_sum+151+76, 80, p_01+467);
	gf2x_add(156, f_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, f_sum+151);
	GF2X_MUL(152, temp2, 76, p_01+467+4, 76, g_sum+151);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, f_sum+1396, 76, f_sum+1396, 76, temp+76);
	right_bit_shift_n(156, f_sum+1396, 44);
	GF2X_MUL(160, temp, 80, f_sum+151+76, 80, p_10+467);
	GF2X_MUL(160, temp2, 80, g_sum+151+76, 80, p_11+467);
	gf2x_add(156, g_sum+1396, 156, temp+4, 156, temp2+4);
	GF2X_MUL(152, temp, 76, p_10+467+4, 76, f_sum+151);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, g_sum+151);
	gf2x_add(152, temp, 152, temp, 152, temp2);
	gf2x_add(76, g_sum+1396, 76, g_sum+1396, 76, temp+76);
	right_bit_shift_n(156, g_sum+1396, 44);
	

	delta = divstepsx_256(255, delta, f_sum+1469, g_sum+1469, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1465+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1465+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1465+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1461+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1461+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1461);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1461);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1453+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1453+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1453);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1453);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1433+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1433+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1433+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4845, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_01+547);
	gf2x_add(76, f_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_01+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+1633, 36, f_sum+1633, 36, temp+36);
	right_bit_shift_n(76, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1397+36, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+36, 40, p_11+547);
	gf2x_add(76, g_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_10+547+4, 36, f_sum+1397);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, g_sum+1397);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+1633, 36, g_sum+1633, 36, temp+36);
	right_bit_shift_n(76, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1666, g_sum+1666, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_01+587);
	gf2x_add(36, f_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_01+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1754, 16, f_sum+1754, 16, temp+16);
	right_bit_shift_n(36, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_11+587);
	gf2x_add(36, g_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1754, 16, g_sum+1754, 16, temp+16);
	right_bit_shift_n(36, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1767, g_sum+1767, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, p_00+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, p_01+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, p_10+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, p_11+607+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_01+607);
	gf2x_add(16, f_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_01+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(16, f_sum+1815, 62);
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_11+607);
	gf2x_add(16, g_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_11+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(16, g_sum+1815, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_10+607);
	gf2x_add(16, q_00+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_11+607);
	gf2x_add(16, q_01+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_10+607);
	gf2x_add(16, q_10+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_11+607);
	gf2x_add(16, q_11+578+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 4
	memset(q_00+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_01+578);
	gf2x_add(32, q_00+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+12, 8, q_00+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+8, 8, q_00+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+4, 8, q_00+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+0, 8, q_00+538+0, 8, temp);
	memset(q_01+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_01+578);
	gf2x_add(32, q_01+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+12, 8, q_01+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+8, 8, q_01+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+4, 8, q_01+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+0, 8, q_01+538+0, 8, temp);
	memset(q_10+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_11+578);
	gf2x_add(32, q_10+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+12, 8, q_10+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+8, 8, q_10+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+4, 8, q_10+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+0, 8, q_10+538+0, 8, temp);
	memset(q_11+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_11+578);
	gf2x_add(32, q_11+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+12, 8, q_11+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+8, 8, q_11+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+4, 8, q_11+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+0, 8, q_11+538+0, 8, temp);
	

	// Recombining results: n: 4845, depth: 3
	memset(q_00+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_01+538);
	gf2x_add(72, q_00+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+32, 8, q_00+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+28, 8, q_00+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+24, 8, q_00+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+20, 8, q_00+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+16, 8, q_00+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+12, 8, q_00+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+8, 8, q_00+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+4, 8, q_00+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+462+0, 8, q_00+462+0, 8, temp);
	memset(q_01+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_01+538);
	gf2x_add(72, q_01+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+32, 8, q_01+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+28, 8, q_01+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+24, 8, q_01+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+20, 8, q_01+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+16, 8, q_01+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+12, 8, q_01+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+8, 8, q_01+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+4, 8, q_01+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+462+0, 8, q_01+462+0, 8, temp);
	memset(q_10+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_11+538);
	gf2x_add(72, q_10+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+32, 8, q_10+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+28, 8, q_10+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+24, 8, q_10+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+20, 8, q_10+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+16, 8, q_10+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+12, 8, q_10+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+8, 8, q_10+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+4, 8, q_10+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+462+0, 8, q_10+462+0, 8, temp);
	memset(q_11+462, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_11+538);
	gf2x_add(72, q_11+462+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+32, 8, q_11+462+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+28, 8, q_11+462+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+24, 8, q_11+462+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+20, 8, q_11+462+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+16, 8, q_11+462+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+12, 8, q_11+462+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+8, 8, q_11+462+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+4, 8, q_11+462+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+462+0, 8, q_11+462+0, 8, temp);
	

	// Recombining results: n: 9945, depth: 2
	memset(p_00+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_01+462);
	gf2x_add(152, p_00+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+72, 8, p_00+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+68, 8, p_00+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+64, 8, p_00+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+60, 8, p_00+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+56, 8, p_00+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+52, 8, p_00+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+48, 8, p_00+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+44, 8, p_00+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+40, 8, p_00+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+36, 8, p_00+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+32, 8, p_00+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+28, 8, p_00+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+24, 8, p_00+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+20, 8, p_00+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+16, 8, p_00+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+12, 8, p_00+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+8, 8, p_00+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+4, 8, p_00+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+311+0, 8, p_00+311+0, 8, temp);
	memset(p_01+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_00+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_01+462);
	gf2x_add(152, p_01+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_00+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+72, 8, p_01+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+68, 8, p_01+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+64, 8, p_01+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+60, 8, p_01+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+56, 8, p_01+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+52, 8, p_01+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+48, 8, p_01+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+44, 8, p_01+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+40, 8, p_01+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+36, 8, p_01+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+32, 8, p_01+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+28, 8, p_01+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+24, 8, p_01+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+20, 8, p_01+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+16, 8, p_01+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+12, 8, p_01+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+8, 8, p_01+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+4, 8, p_01+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_01+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+311+0, 8, p_01+311+0, 8, temp);
	memset(p_10+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_00+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_10+467+4, 76, q_11+462);
	gf2x_add(152, p_10+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+72, 8, p_10+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+68, 8, p_10+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+64, 8, p_10+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+60, 8, p_10+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+56, 8, p_10+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+52, 8, p_10+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+48, 8, p_10+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+44, 8, p_10+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+40, 8, p_10+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+36, 8, p_10+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+32, 8, p_10+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+28, 8, p_10+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+24, 8, p_10+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+20, 8, p_10+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+16, 8, p_10+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+12, 8, p_10+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+8, 8, p_10+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+4, 8, p_10+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_00+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_10+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+311+0, 8, p_10+311+0, 8, temp);
	memset(p_11+311, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(152, temp, 76, p_01+467+4, 76, q_10+462);
	GF2X_MUL(152, temp2, 76, p_11+467+4, 76, q_11+462);
	gf2x_add(152, p_11+311+4, 152, temp, 152, temp2);
	GF2X_MUL(8, temp, 4, q_10+462+72, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+72, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+72, 8, p_11+311+72, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+68, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+68, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+68, 8, p_11+311+68, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+64, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+64, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+64, 8, p_11+311+64, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+60, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+60, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+60, 8, p_11+311+60, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+56, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+56, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+56, 8, p_11+311+56, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+52, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+52, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+52, 8, p_11+311+52, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+48, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+48, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+48, 8, p_11+311+48, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+44, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+44, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+44, 8, p_11+311+44, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+40, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+40, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+40, 8, p_11+311+40, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+36, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+36, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+36, 8, p_11+311+36, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+32, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+32, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+32, 8, p_11+311+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+28, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+28, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+28, 8, p_11+311+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+24, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+24, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+24, 8, p_11+311+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+20, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+20, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+20, 8, p_11+311+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+16, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+16, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+16, 8, p_11+311+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+12, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+12, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+12, 8, p_11+311+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+8, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+8, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+8, 8, p_11+311+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+4, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+4, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+4, 8, p_11+311+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+462+0, 4, p_01+467);
	GF2X_MUL(8, temp2, 4, q_11+462+0, 4, p_11+467);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+311+0, 8, p_11+311+0, 8, temp);
	

	// Calculating left operands: n: 19527, depth: 1
	// Digits to shift: 155
	// Displacement: 156
	GF2X_MUL(312, temp, 156, f_sum+1+150, 156, p_00+311);
	GF2X_MUL(312, temp2, 156, g_sum+1+150, 156, p_01+311);
	gf2x_add(306, f_sum+928, 306, temp+6, 306, temp2+6);
	GF2X_MUL(300, temp, 150, p_00+311+6, 150, f_sum+1);
	GF2X_MUL(300, temp2, 150, p_01+311+6, 150, g_sum+1);
	gf2x_add(300, temp, 300, temp, 300, temp2);
	gf2x_add(150, f_sum+928, 150, f_sum+928, 150, temp+150);
	right_bit_shift_n(306, f_sum+928, 25);
	GF2X_MUL(312, temp, 156, f_sum+1+150, 156, p_10+311);
	GF2X_MUL(312, temp2, 156, g_sum+1+150, 156, p_11+311);
	gf2x_add(306, g_sum+928, 306, temp+6, 306, temp2+6);
	GF2X_MUL(300, temp, 150, p_10+311+6, 150, f_sum+1);
	GF2X_MUL(300, temp2, 150, p_11+311+6, 150, g_sum+1);
	gf2x_add(300, temp, 300, temp, 300, temp2);
	gf2x_add(150, g_sum+928, 150, g_sum+928, 150, temp+150);
	right_bit_shift_n(306, g_sum+928, 25);
	

	delta = divstepsx_256(255, delta, f_sum+1075, g_sum+1075, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1071+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1071+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1071+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1071+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1071+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1071+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1071+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1071+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1067+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1067+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1067);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1067);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1067+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1067+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1067);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1067);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1059+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1059+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1059);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1059);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1059+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1059+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1059);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1059);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1039+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1039+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1039+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1039+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1039+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1039+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1039+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1039+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4845, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1003+36, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1003+36, 40, p_01+547);
	gf2x_add(76, f_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, f_sum+1003);
	GF2X_MUL(72, temp2, 36, p_01+547+4, 36, g_sum+1003);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, f_sum+1633, 36, f_sum+1633, 36, temp+36);
	right_bit_shift_n(76, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1003+36, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1003+36, 40, p_11+547);
	gf2x_add(76, g_sum+1633, 76, temp+4, 76, temp2+4);
	GF2X_MUL(72, temp, 36, p_10+547+4, 36, f_sum+1003);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, g_sum+1003);
	gf2x_add(72, temp, 72, temp, 72, temp2);
	gf2x_add(36, g_sum+1633, 36, g_sum+1633, 36, temp+36);
	right_bit_shift_n(76, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1666, g_sum+1666, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1662+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1662+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1662+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1658+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1658+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1658);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1658);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1650+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1650+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1650);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1650);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2295, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_01+587);
	gf2x_add(36, f_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_01+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, f_sum+1754, 16, f_sum+1754, 16, temp+16);
	right_bit_shift_n(36, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+16, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+16, 20, p_11+587);
	gf2x_add(36, g_sum+1754, 36, temp+4, 36, temp2+4);
	GF2X_MUL(32, temp, 16, p_10+587+4, 16, f_sum+1634);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, g_sum+1634);
	gf2x_add(32, temp, 32, temp, 32, temp2);
	gf2x_add(16, g_sum+1754, 16, g_sum+1754, 16, temp+16);
	right_bit_shift_n(36, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1767, g_sum+1767, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1763+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1763+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1763+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, p_00+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, p_01+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, p_10+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, p_11+607+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 1020, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_01+607);
	gf2x_add(16, f_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_01+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(16, f_sum+1815, 62);
	GF2X_MUL(16, temp, 8, f_sum+1755+8, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+8, 8, p_11+607);
	gf2x_add(16, g_sum+1815+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, f_sum+1755+0, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+0, 8, p_11+607);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(16, g_sum+1815, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1020, depth: 5
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_10+607);
	gf2x_add(16, q_00+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_00+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_01+598+0, 8, p_11+607);
	gf2x_add(16, q_01+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_10+607);
	gf2x_add(16, q_10+578+0, 16, temp, 16, temp2);
	GF2X_MUL(16, temp, 8, q_10+598+0, 8, p_01+607);
	GF2X_MUL(16, temp2, 8, q_11+598+0, 8, p_11+607);
	gf2x_add(16, q_11+578+0, 16, temp, 16, temp2);
	

	// Recombining results: n: 2295, depth: 4
	memset(q_00+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_01+578);
	gf2x_add(32, q_00+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+12, 8, q_00+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+8, 8, q_00+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+4, 8, q_00+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+538+0, 8, q_00+538+0, 8, temp);
	memset(q_01+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_00+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_01+578);
	gf2x_add(32, q_01+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_00+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+12, 8, q_01+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+8, 8, q_01+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+4, 8, q_01+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_01+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+538+0, 8, q_01+538+0, 8, temp);
	memset(q_10+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_00+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_10+587+4, 16, q_11+578);
	gf2x_add(32, q_10+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+12, 8, q_10+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+8, 8, q_10+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+4, 8, q_10+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_00+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_10+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+538+0, 8, q_10+538+0, 8, temp);
	memset(q_11+538, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(32, temp, 16, p_01+587+4, 16, q_10+578);
	GF2X_MUL(32, temp2, 16, p_11+587+4, 16, q_11+578);
	gf2x_add(32, q_11+538+4, 32, temp, 32, temp2);
	GF2X_MUL(8, temp, 4, q_10+578+12, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+12, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+12, 8, q_11+538+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+8, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+8, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+8, 8, q_11+538+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+4, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+4, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+4, 8, q_11+538+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+578+0, 4, p_01+587);
	GF2X_MUL(8, temp2, 4, q_11+578+0, 4, p_11+587);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+538+0, 8, q_11+538+0, 8, temp);
	

	// Recombining results: n: 4845, depth: 3
	memset(p_00+467, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_01+538);
	gf2x_add(72, p_00+467+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+32, 8, p_00+467+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+28, 8, p_00+467+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+24, 8, p_00+467+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+20, 8, p_00+467+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+16, 8, p_00+467+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+12, 8, p_00+467+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+8, 8, p_00+467+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+4, 8, p_00+467+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+467+0, 8, p_00+467+0, 8, temp);
	memset(p_01+467, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_00+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_01+538);
	gf2x_add(72, p_01+467+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_00+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+32, 8, p_01+467+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+28, 8, p_01+467+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+24, 8, p_01+467+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+20, 8, p_01+467+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+16, 8, p_01+467+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+12, 8, p_01+467+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+8, 8, p_01+467+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+4, 8, p_01+467+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_01+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+467+0, 8, p_01+467+0, 8, temp);
	memset(p_10+467, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_00+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_10+547+4, 36, q_11+538);
	gf2x_add(72, p_10+467+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+32, 8, p_10+467+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+28, 8, p_10+467+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+24, 8, p_10+467+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+20, 8, p_10+467+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+16, 8, p_10+467+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+12, 8, p_10+467+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+8, 8, p_10+467+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+4, 8, p_10+467+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_00+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_10+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+467+0, 8, p_10+467+0, 8, temp);
	memset(p_11+467, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(72, temp, 36, p_01+547+4, 36, q_10+538);
	GF2X_MUL(72, temp2, 36, p_11+547+4, 36, q_11+538);
	gf2x_add(72, p_11+467+4, 72, temp, 72, temp2);
	GF2X_MUL(8, temp, 4, q_10+538+32, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+32, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+32, 8, p_11+467+32, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+28, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+28, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+28, 8, p_11+467+28, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+24, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+24, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+24, 8, p_11+467+24, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+20, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+20, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+20, 8, p_11+467+20, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+16, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+16, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+16, 8, p_11+467+16, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+12, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+12, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+12, 8, p_11+467+12, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+8, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+8, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+8, 8, p_11+467+8, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+4, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+4, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+4, 8, p_11+467+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+538+0, 4, p_01+547);
	GF2X_MUL(8, temp2, 4, q_11+538+0, 4, p_11+547);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+467+0, 8, p_11+467+0, 8, temp);
	

	// Calculating left operands: n: 9582, depth: 2
	// Digits to shift: 75
	// Displacement: 75
	GF2X_MUL(152, temp, 76, f_sum+929+74, 76, p_00+467);
	GF2X_MUL(152, temp2, 76, g_sum+929+74, 76, p_01+467);
	gf2x_add(151, f_sum+1396, 151, temp+1, 151, temp2+1);
	GF2X_MUL(148, temp, 74, p_00+467+2, 74, f_sum+929);
	GF2X_MUL(148, temp2, 74, p_01+467+2, 74, g_sum+929);
	gf2x_add(148, temp, 148, temp, 148, temp2);
	gf2x_add(75, f_sum+1396, 75, f_sum+1396, 75, temp+73);
	GF2X_MUL(4, temp, 2, f_sum+929+72, 2, p_00+467);
	GF2X_MUL(4, temp2, 2, g_sum+929+72, 2, p_01+467);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, f_sum+1396, 1, f_sum+1396, 1, temp+3);
	right_bit_shift_n(150, f_sum+1396, 45);
	GF2X_MUL(152, temp, 76, f_sum+929+74, 76, p_10+467);
	GF2X_MUL(152, temp2, 76, g_sum+929+74, 76, p_11+467);
	gf2x_add(151, g_sum+1396, 151, temp+1, 151, temp2+1);
	GF2X_MUL(148, temp, 74, p_10+467+2, 74, f_sum+929);
	GF2X_MUL(148, temp2, 74, p_11+467+2, 74, g_sum+929);
	gf2x_add(148, temp, 148, temp, 148, temp2);
	gf2x_add(75, g_sum+1396, 75, g_sum+1396, 75, temp+73);
	GF2X_MUL(4, temp, 2, f_sum+929+72, 2, p_10+467);
	GF2X_MUL(4, temp2, 2, g_sum+929+72, 2, p_11+467);
	gf2x_add(4, temp, 4, temp, 4, temp2);
	gf2x_add(1, g_sum+1396, 1, g_sum+1396, 1, temp+3);
	right_bit_shift_n(150, g_sum+1396, 45);
	

	delta = divstepsx_256(255, delta, f_sum+1468, g_sum+1468, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1464+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1464+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1464+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1464+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1464+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1464+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1464+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1464+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1460+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1460+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1460);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1460);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1460+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1460+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1460);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1460);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1452+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1452+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1452);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1452);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1452+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1452+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1452);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1452);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2550, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1432+20, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1432+20, 20, p_01+587);
	gf2x_add(40, f_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1432+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1432+0, 20, p_01+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, f_sum+1754, 20, f_sum+1754, 20, temp+20);
	right_bit_shift_n(40, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1432+20, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1432+20, 20, p_11+587);
	gf2x_add(40, g_sum+1754+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, f_sum+1432+0, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1432+0, 20, p_11+587);
	gf2x_add(40, temp, 40, temp, 40, temp2);
	gf2x_add(20, g_sum+1754, 20, g_sum+1754, 20, temp+20);
	right_bit_shift_n(40, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1771, g_sum+1771, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1767+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1767+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1767+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1763+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1763+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1763);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1763);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1755+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1755+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1755);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1755);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(q_00+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, q_00+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+4, 8, q_00+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_00+578+0, 8, q_00+578+0, 8, temp);
	memset(q_01+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, q_01+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+4, 8, q_01+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_01+578+0, 8, q_01+578+0, 8, temp);
	memset(q_10+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, q_10+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+4, 8, q_10+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_10+578+0, 8, q_10+578+0, 8, temp);
	memset(q_11+578, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, q_11+578+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+4, 8, q_11+578+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, q_11+578+0, 8, q_11+578+0, 8, temp);
	

	// Recombining results: n: 2550, depth: 4
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_10+587);
	gf2x_add(40, p_00+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_00+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_01+578+0, 20, p_11+587);
	gf2x_add(40, p_01+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_10+587);
	gf2x_add(40, p_10+547+0, 40, temp, 40, temp2);
	GF2X_MUL(40, temp, 20, q_10+578+0, 20, p_01+587);
	GF2X_MUL(40, temp2, 20, q_11+578+0, 20, p_11+587);
	gf2x_add(40, p_11+547+0, 40, temp, 40, temp2);
	

	// Calculating left operands: n: 4737, depth: 3
	// Digits to shift: 39
	// Displacement: 40
	GF2X_MUL(80, temp, 40, f_sum+1397+35, 40, p_00+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+35, 40, p_01+547);
	gf2x_add(75, f_sum+1633, 75, temp+5, 75, temp2+5);
	GF2X_MUL(70, temp, 35, p_00+547+5, 35, f_sum+1397);
	GF2X_MUL(70, temp2, 35, p_01+547+5, 35, g_sum+1397);
	gf2x_add(70, temp, 70, temp, 70, temp2);
	gf2x_add(35, f_sum+1633, 35, f_sum+1633, 35, temp+35);
	right_bit_shift_n(75, f_sum+1633, 54);
	GF2X_MUL(80, temp, 40, f_sum+1397+35, 40, p_10+547);
	GF2X_MUL(80, temp2, 40, g_sum+1397+35, 40, p_11+547);
	gf2x_add(75, g_sum+1633, 75, temp+5, 75, temp2+5);
	GF2X_MUL(70, temp, 35, p_10+547+5, 35, f_sum+1397);
	GF2X_MUL(70, temp2, 35, p_11+547+5, 35, g_sum+1397);
	gf2x_add(70, temp, 70, temp, 70, temp2);
	gf2x_add(35, g_sum+1633, 35, g_sum+1633, 35, temp+35);
	right_bit_shift_n(75, g_sum+1633, 54);
	

	delta = divstepsx_256(255, delta, f_sum+1665, g_sum+1665, p_00+627, p_01+627, p_10+627, p_11+627);

	// Calculating left operands: n: 510, depth: 7
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1661+4, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1661+4, 4, p_01+627);
	gf2x_add(8, f_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1661+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, g_sum+1661+0, 4, p_01+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1869, 4, f_sum+1869, 4, temp+4);
	right_bit_shift_n(8, f_sum+1869, 63);
	GF2X_MUL(8, temp, 4, f_sum+1661+4, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1661+4, 4, p_11+627);
	gf2x_add(8, g_sum+1869+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1661+0, 4, p_10+627);
	GF2X_MUL(8, temp2, 4, g_sum+1661+0, 4, p_11+627);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1869, 4, g_sum+1869, 4, temp+4);
	right_bit_shift_n(8, g_sum+1869, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1870, g_sum+1870, q_00+610, q_01+610, q_10+610, q_11+610);

	// Recombining results: n: 510, depth: 7
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_10+627);
	gf2x_add(8, p_00+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_01+610+0, 4, p_11+627);
	gf2x_add(8, p_01+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_00+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_10+627);
	gf2x_add(8, p_10+619+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+610+0, 4, p_01+627);
	GF2X_MUL(8, temp2, 4, q_11+610+0, 4, p_11+627);
	gf2x_add(8, p_11+619+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 765, depth: 6
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1657+4, 8, p_00+619);
	GF2X_MUL(16, temp2, 8, g_sum+1657+4, 8, p_01+619);
	gf2x_add(12, f_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, f_sum+1657);
	GF2X_MUL(8, temp2, 4, p_01+619+4, 4, g_sum+1657);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(12, f_sum+1848, 62);
	GF2X_MUL(16, temp, 8, f_sum+1657+4, 8, p_10+619);
	GF2X_MUL(16, temp2, 8, g_sum+1657+4, 8, p_11+619);
	gf2x_add(12, g_sum+1848, 12, temp+4, 12, temp2+4);
	GF2X_MUL(8, temp, 4, p_10+619+4, 4, f_sum+1657);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, g_sum+1657);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(12, g_sum+1848, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 765, depth: 6
	memset(p_00+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_01+606);
	gf2x_add(8, p_00+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+607+0, 8, p_00+607+0, 8, temp);
	memset(p_01+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_00+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_01+606);
	gf2x_add(8, p_01+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+607+0, 8, p_01+607+0, 8, temp);
	memset(p_10+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_00+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_10+619+4, 4, q_11+606);
	gf2x_add(8, p_10+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+607+0, 8, p_10+607+0, 8, temp);
	memset(p_11+607, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(8, temp, 4, p_01+619+4, 4, q_10+606);
	GF2X_MUL(8, temp2, 4, p_11+619+4, 4, q_11+606);
	gf2x_add(8, p_11+607+4, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+607+0, 8, p_11+607+0, 8, temp);
	

	// Calculating left operands: n: 1275, depth: 5
	// Digits to shift: 11
	// Displacement: 12
	GF2X_MUL(24, temp, 12, f_sum+1649+8, 12, p_00+607);
	GF2X_MUL(24, temp2, 12, g_sum+1649+8, 12, p_01+607);
	gf2x_add(20, f_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, f_sum+1649);
	GF2X_MUL(16, temp2, 8, p_01+607+4, 8, g_sum+1649);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, f_sum+1815, 8, f_sum+1815, 8, temp+8);
	right_bit_shift_n(20, f_sum+1815, 61);
	GF2X_MUL(24, temp, 12, f_sum+1649+8, 12, p_10+607);
	GF2X_MUL(24, temp2, 12, g_sum+1649+8, 12, p_11+607);
	gf2x_add(20, g_sum+1815, 20, temp+4, 20, temp2+4);
	GF2X_MUL(16, temp, 8, p_10+607+4, 8, f_sum+1649);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, g_sum+1649);
	gf2x_add(16, temp, 16, temp, 16, temp2);
	gf2x_add(8, g_sum+1815, 8, g_sum+1815, 8, temp+8);
	right_bit_shift_n(20, g_sum+1815, 61);
	

	delta = divstepsx_256(255, delta, f_sum+1820, g_sum+1820, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1816+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, q_00+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, q_01+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, q_10+598+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, q_11+598+0, 8, temp, 8, temp2);
	

	// Recombining results: n: 1275, depth: 5
	memset(p_00+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_01+598);
	gf2x_add(16, p_00+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+4, 8, p_00+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_00+587+0, 8, p_00+587+0, 8, temp);
	memset(p_01+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_00+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_01+598);
	gf2x_add(16, p_01+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_00+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+4, 8, p_01+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_00+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_01+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_01+587+0, 8, p_01+587+0, 8, temp);
	memset(p_10+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_00+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_10+607+4, 8, q_11+598);
	gf2x_add(16, p_10+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+4, 8, p_10+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_00+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_10+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_10+587+0, 8, p_10+587+0, 8, temp);
	memset(p_11+587, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(16, temp, 8, p_01+607+4, 8, q_10+598);
	GF2X_MUL(16, temp2, 8, p_11+607+4, 8, q_11+598);
	gf2x_add(16, p_11+587+4, 16, temp, 16, temp2);
	GF2X_MUL(8, temp, 4, q_10+598+4, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+4, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+4, 8, p_11+587+4, 8, temp);
	GF2X_MUL(8, temp, 4, q_10+598+0, 4, p_01+607);
	GF2X_MUL(8, temp2, 4, q_11+598+0, 4, p_11+607);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(8, p_11+587+0, 8, p_11+587+0, 8, temp);
	

	// Calculating left operands: n: 2187, depth: 4
	// Digits to shift: 19
	// Displacement: 20
	GF2X_MUL(40, temp, 20, f_sum+1634+15, 20, p_00+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+15, 20, p_01+587);
	gf2x_add(35, f_sum+1754, 35, temp+5, 35, temp2+5);
	GF2X_MUL(30, temp, 15, p_00+587+5, 15, f_sum+1634);
	GF2X_MUL(30, temp2, 15, p_01+587+5, 15, g_sum+1634);
	gf2x_add(30, temp, 30, temp, 30, temp2);
	gf2x_add(15, f_sum+1754, 15, f_sum+1754, 15, temp+15);
	right_bit_shift_n(35, f_sum+1754, 59);
	GF2X_MUL(40, temp, 20, f_sum+1634+15, 20, p_10+587);
	GF2X_MUL(40, temp2, 20, g_sum+1634+15, 20, p_11+587);
	gf2x_add(35, g_sum+1754, 35, temp+5, 35, temp2+5);
	GF2X_MUL(30, temp, 15, p_10+587+5, 15, f_sum+1634);
	GF2X_MUL(30, temp2, 15, p_11+587+5, 15, g_sum+1634);
	gf2x_add(30, temp, 30, temp, 30, temp2);
	gf2x_add(15, g_sum+1754, 15, g_sum+1754, 15, temp+15);
	right_bit_shift_n(35, g_sum+1754, 59);
	

	delta = divstepsx_256(255, delta, f_sum+1766, g_sum+1766, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 510, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1762+4, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1762+4, 4, p_01+619);
	gf2x_add(8, f_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1762+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1762+0, 4, p_01+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, f_sum+1848, 4, f_sum+1848, 4, temp+4);
	right_bit_shift_n(8, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1762+4, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1762+4, 4, p_11+619);
	gf2x_add(8, g_sum+1848+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, f_sum+1762+0, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1762+0, 4, p_11+619);
	gf2x_add(8, temp, 8, temp, 8, temp2);
	gf2x_add(4, g_sum+1848, 4, g_sum+1848, 4, temp+4);
	right_bit_shift_n(8, g_sum+1848, 63);
	

	delta = divstepsx_256(255, delta, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606);

	// Recombining results: n: 510, depth: 6
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_10+619);
	gf2x_add(8, p_00+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_00+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_01+606+0, 4, p_11+619);
	gf2x_add(8, p_01+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_10+619);
	gf2x_add(8, p_10+607+0, 8, temp, 8, temp2);
	GF2X_MUL(8, temp, 4, q_10+606+0, 4, p_01+619);
	GF2X_MUL(8, temp2, 4, q_11+606+0, 4, p_11+619);
	gf2x_add(8, p_11+607+0, 8, temp, 8, temp2);
	

	// Calculating left operands: n: 912, depth: 5
	// Digits to shift: 7
	// Displacement: 8
	GF2X_MUL(16, temp, 8, f_sum+1755+7, 8, p_00+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+7, 8, p_01+607);
	gf2x_add(15, f_sum+1815, 15, temp+1, 15, temp2+1);
	GF2X_MUL(14, temp, 7, p_00+607+1, 7, f_sum+1755);
	GF2X_MUL(14, temp2, 7, p_01+607+1, 7, g_sum+1755);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, f_sum+1815, 7, f_sum+1815, 7, temp+7);
	right_bit_shift_n(15, f_sum+1815, 62);
	GF2X_MUL(16, temp, 8, f_sum+1755+7, 8, p_10+607);
	GF2X_MUL(16, temp2, 8, g_sum+1755+7, 8, p_11+607);
	gf2x_add(15, g_sum+1815, 15, temp+1, 15, temp2+1);
	GF2X_MUL(14, temp, 7, p_10+607+1, 7, f_sum+1755);
	GF2X_MUL(14, temp2, 7, p_11+607+1, 7, g_sum+1755);
	gf2x_add(14, temp, 14, temp, 14, temp2);
	gf2x_add(7, g_sum+1815, 7, g_sum+1815, 7, temp+7);
	right_bit_shift_n(15, g_sum+1815, 62);
	

	delta = divstepsx_256(255, delta, f_sum+1819, g_sum+1819, p_00+619, p_01+619, p_10+619, p_11+619);

	// Calculating left operands: n: 402, depth: 6
	// Digits to shift: 3
	// Displacement: 4
	GF2X_MUL(8, temp, 4, f_sum+1816+3, 4, p_00+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+3, 4, p_01+619);
	gf2x_add(7, f_sum+1848, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_00+619+1, 3, f_sum+1816);
	GF2X_MUL(6, temp2, 3, p_01+619+1, 3, g_sum+1816);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, f_sum+1848, 3, f_sum+1848, 3, temp+3);
	right_bit_shift_n(7, f_sum+1848, 63);
	GF2X_MUL(8, temp, 4, f_sum+1816+3, 4, p_10+619);
	GF2X_MUL(8, temp2, 4, g_sum+1816+3, 4, p_11+619);
	gf2x_add(7, g_sum+1848, 7, temp+1, 7, temp2+1);
	GF2X_MUL(6, temp, 3, p_10+619+1, 3, f_sum+1816);
	GF2X_MUL(6, temp2, 3, p_11+619+1, 3, g_sum+1816);
	gf2x_add(6, temp, 6, temp, 6, temp2);
	gf2x_add(3, g_sum+1848, 3, g_sum+1848, 3, temp+3);
	right_bit_shift_n(7, g_sum+1848, 63);
	

	delta = support_jumpdivstep(147, delta, 3, f_sum+1849, g_sum+1849, q_00+606, q_01+606, q_10+606, q_11+606, x);

	// Recombining results: n: 402, depth: 6
	memset(q_00+598, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+619+1, 3, q_00+606);
	GF2X_MUL(6, temp2, 3, p_10+619+1, 3, q_01+606);
	gf2x_add(6, q_00+598+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+606+2, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_01+606+2, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+598+2, 2, q_00+598+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+606+1, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_01+606+1, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+598+1, 2, q_00+598+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+606+0, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_01+606+0, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+598+0, 2, q_00+598+0, 2, temp);
	memset(q_01+598, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+619+1, 3, q_00+606);
	GF2X_MUL(6, temp2, 3, p_11+619+1, 3, q_01+606);
	gf2x_add(6, q_01+598+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_00+606+2, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_01+606+2, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+598+2, 2, q_01+598+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+606+1, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_01+606+1, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+598+1, 2, q_01+598+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+606+0, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_01+606+0, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+598+0, 2, q_01+598+0, 2, temp);
	memset(q_10+598, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_00+619+1, 3, q_10+606);
	GF2X_MUL(6, temp2, 3, p_10+619+1, 3, q_11+606);
	gf2x_add(6, q_10+598+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+606+2, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_11+606+2, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+598+2, 2, q_10+598+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+606+1, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_11+606+1, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+598+1, 2, q_10+598+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+606+0, 1, p_00+619);
	GF2X_MUL(2, temp2, 1, q_11+606+0, 1, p_10+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+598+0, 2, q_10+598+0, 2, temp);
	memset(q_11+598, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(6, temp, 3, p_01+619+1, 3, q_10+606);
	GF2X_MUL(6, temp2, 3, p_11+619+1, 3, q_11+606);
	gf2x_add(6, q_11+598+1, 6, temp, 6, temp2);
	GF2X_MUL(2, temp, 1, q_10+606+2, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_11+606+2, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+598+2, 2, q_11+598+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+606+1, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_11+606+1, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+598+1, 2, q_11+598+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+606+0, 1, p_01+619);
	GF2X_MUL(2, temp2, 1, q_11+606+0, 1, p_11+619);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+598+0, 2, q_11+598+0, 2, temp);
	

	// Recombining results: n: 912, depth: 5
	memset(q_00+578, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+607+1, 7, q_00+598);
	GF2X_MUL(14, temp2, 7, p_10+607+1, 7, q_01+598);
	gf2x_add(14, q_00+578+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_00+598+6, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+6, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+6, 2, q_00+578+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+5, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+5, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+5, 2, q_00+578+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+4, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+4, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+4, 2, q_00+578+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+3, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+3, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+3, 2, q_00+578+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+2, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+2, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+2, 2, q_00+578+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+1, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+1, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+1, 2, q_00+578+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+0, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_01+598+0, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+578+0, 2, q_00+578+0, 2, temp);
	memset(q_01+578, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+607+1, 7, q_00+598);
	GF2X_MUL(14, temp2, 7, p_11+607+1, 7, q_01+598);
	gf2x_add(14, q_01+578+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_00+598+6, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+6, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+6, 2, q_01+578+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+5, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+5, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+5, 2, q_01+578+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+4, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+4, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+4, 2, q_01+578+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+3, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+3, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+3, 2, q_01+578+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+2, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+2, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+2, 2, q_01+578+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+1, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+1, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+1, 2, q_01+578+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+598+0, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_01+598+0, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+578+0, 2, q_01+578+0, 2, temp);
	memset(q_10+578, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_00+607+1, 7, q_10+598);
	GF2X_MUL(14, temp2, 7, p_10+607+1, 7, q_11+598);
	gf2x_add(14, q_10+578+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_10+598+6, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+6, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+6, 2, q_10+578+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+5, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+5, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+5, 2, q_10+578+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+4, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+4, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+4, 2, q_10+578+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+3, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+3, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+3, 2, q_10+578+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+2, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+2, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+2, 2, q_10+578+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+1, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+1, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+1, 2, q_10+578+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+0, 1, p_00+607);
	GF2X_MUL(2, temp2, 1, q_11+598+0, 1, p_10+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+578+0, 2, q_10+578+0, 2, temp);
	memset(q_11+578, 0x00, 1*DIGIT_SIZE_B);
	GF2X_MUL(14, temp, 7, p_01+607+1, 7, q_10+598);
	GF2X_MUL(14, temp2, 7, p_11+607+1, 7, q_11+598);
	gf2x_add(14, q_11+578+1, 14, temp, 14, temp2);
	GF2X_MUL(2, temp, 1, q_10+598+6, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+6, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+6, 2, q_11+578+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+5, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+5, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+5, 2, q_11+578+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+4, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+4, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+4, 2, q_11+578+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+3, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+3, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+3, 2, q_11+578+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+2, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+2, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+2, 2, q_11+578+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+1, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+1, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+1, 2, q_11+578+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+598+0, 1, p_01+607);
	GF2X_MUL(2, temp2, 1, q_11+598+0, 1, p_11+607);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+578+0, 2, q_11+578+0, 2, temp);
	

	// Recombining results: n: 2187, depth: 4
	memset(q_00+538, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_00+587+5, 15, q_00+578);
	GF2X_MUL(30, temp2, 15, p_10+587+5, 15, q_01+578);
	gf2x_add(30, q_00+538+5, 30, temp, 30, temp2);
	GF2X_MUL(10, temp, 5, q_00+578+10, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_01+578+10, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+538+10, 10, q_00+538+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+578+5, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_01+578+5, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+538+5, 10, q_00+538+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+578+0, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_01+578+0, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+538+0, 10, q_00+538+0, 10, temp);
	memset(q_01+538, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_01+587+5, 15, q_00+578);
	GF2X_MUL(30, temp2, 15, p_11+587+5, 15, q_01+578);
	gf2x_add(30, q_01+538+5, 30, temp, 30, temp2);
	GF2X_MUL(10, temp, 5, q_00+578+10, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_01+578+10, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+538+10, 10, q_01+538+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+578+5, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_01+578+5, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+538+5, 10, q_01+538+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+578+0, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_01+578+0, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+538+0, 10, q_01+538+0, 10, temp);
	memset(q_10+538, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_00+587+5, 15, q_10+578);
	GF2X_MUL(30, temp2, 15, p_10+587+5, 15, q_11+578);
	gf2x_add(30, q_10+538+5, 30, temp, 30, temp2);
	GF2X_MUL(10, temp, 5, q_10+578+10, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_11+578+10, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+538+10, 10, q_10+538+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+578+5, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_11+578+5, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+538+5, 10, q_10+538+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+578+0, 5, p_00+587);
	GF2X_MUL(10, temp2, 5, q_11+578+0, 5, p_10+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+538+0, 10, q_10+538+0, 10, temp);
	memset(q_11+538, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(30, temp, 15, p_01+587+5, 15, q_10+578);
	GF2X_MUL(30, temp2, 15, p_11+587+5, 15, q_11+578);
	gf2x_add(30, q_11+538+5, 30, temp, 30, temp2);
	GF2X_MUL(10, temp, 5, q_10+578+10, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_11+578+10, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+538+10, 10, q_11+538+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+578+5, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_11+578+5, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+538+5, 10, q_11+538+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+578+0, 5, p_01+587);
	GF2X_MUL(10, temp2, 5, q_11+578+0, 5, p_11+587);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+538+0, 10, q_11+538+0, 10, temp);
	

	// Recombining results: n: 4737, depth: 3
	memset(q_00+462, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(70, temp, 35, p_00+547+5, 35, q_00+538);
	GF2X_MUL(70, temp2, 35, p_10+547+5, 35, q_01+538);
	gf2x_add(70, q_00+462+5, 70, temp, 70, temp2);
	GF2X_MUL(10, temp, 5, q_00+538+30, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+30, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+30, 10, q_00+462+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+25, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+25, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+25, 10, q_00+462+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+20, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+20, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+20, 10, q_00+462+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+15, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+15, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+15, 10, q_00+462+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+10, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+10, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+10, 10, q_00+462+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+5, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+5, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+5, 10, q_00+462+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+0, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_01+538+0, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_00+462+0, 10, q_00+462+0, 10, temp);
	memset(q_01+462, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(70, temp, 35, p_01+547+5, 35, q_00+538);
	GF2X_MUL(70, temp2, 35, p_11+547+5, 35, q_01+538);
	gf2x_add(70, q_01+462+5, 70, temp, 70, temp2);
	GF2X_MUL(10, temp, 5, q_00+538+30, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+30, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+30, 10, q_01+462+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+25, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+25, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+25, 10, q_01+462+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+20, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+20, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+20, 10, q_01+462+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+15, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+15, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+15, 10, q_01+462+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+10, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+10, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+10, 10, q_01+462+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+5, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+5, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+5, 10, q_01+462+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+538+0, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_01+538+0, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_01+462+0, 10, q_01+462+0, 10, temp);
	memset(q_10+462, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(70, temp, 35, p_00+547+5, 35, q_10+538);
	GF2X_MUL(70, temp2, 35, p_10+547+5, 35, q_11+538);
	gf2x_add(70, q_10+462+5, 70, temp, 70, temp2);
	GF2X_MUL(10, temp, 5, q_10+538+30, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+30, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+30, 10, q_10+462+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+25, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+25, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+25, 10, q_10+462+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+20, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+20, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+20, 10, q_10+462+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+15, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+15, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+15, 10, q_10+462+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+10, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+10, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+10, 10, q_10+462+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+5, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+5, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+5, 10, q_10+462+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+0, 5, p_00+547);
	GF2X_MUL(10, temp2, 5, q_11+538+0, 5, p_10+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_10+462+0, 10, q_10+462+0, 10, temp);
	memset(q_11+462, 0x00, 5*DIGIT_SIZE_B);
	GF2X_MUL(70, temp, 35, p_01+547+5, 35, q_10+538);
	GF2X_MUL(70, temp2, 35, p_11+547+5, 35, q_11+538);
	gf2x_add(70, q_11+462+5, 70, temp, 70, temp2);
	GF2X_MUL(10, temp, 5, q_10+538+30, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+30, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+30, 10, q_11+462+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+25, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+25, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+25, 10, q_11+462+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+20, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+20, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+20, 10, q_11+462+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+15, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+15, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+15, 10, q_11+462+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+10, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+10, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+10, 10, q_11+462+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+5, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+5, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+5, 10, q_11+462+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+538+0, 5, p_01+547);
	GF2X_MUL(10, temp2, 5, q_11+538+0, 5, p_11+547);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, q_11+462+0, 10, q_11+462+0, 10, temp);
	

	// Recombining results: n: 9582, depth: 2
	GF2X_MUL(150, temp, 75, p_00+467+1, 75, q_00+462);
	GF2X_MUL(150, temp2, 75, p_10+467+1, 75, q_01+462);
	gf2x_add(150, q_00+306+0, 150, temp, 150, temp2);
	GF2X_MUL(2, temp, 1, q_00+462+74, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+74, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+73, 2, q_00+306+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+73, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+73, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+72, 2, q_00+306+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+72, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+72, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+71, 2, q_00+306+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+71, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+71, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+70, 2, q_00+306+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+70, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+70, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+69, 2, q_00+306+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+69, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+69, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+68, 2, q_00+306+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+68, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+68, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+67, 2, q_00+306+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+67, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+67, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+66, 2, q_00+306+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+66, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+66, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+65, 2, q_00+306+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+65, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+65, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+64, 2, q_00+306+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+64, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+64, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+63, 2, q_00+306+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+63, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+63, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+62, 2, q_00+306+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+62, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+62, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+61, 2, q_00+306+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+61, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+61, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+60, 2, q_00+306+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+60, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+60, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+59, 2, q_00+306+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+59, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+59, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+58, 2, q_00+306+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+58, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+58, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+57, 2, q_00+306+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+57, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+57, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+56, 2, q_00+306+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+56, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+56, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+55, 2, q_00+306+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+55, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+55, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+54, 2, q_00+306+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+54, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+54, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+53, 2, q_00+306+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+53, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+53, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+52, 2, q_00+306+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+52, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+52, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+51, 2, q_00+306+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+51, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+51, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+50, 2, q_00+306+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+50, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+50, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+49, 2, q_00+306+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+49, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+49, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+48, 2, q_00+306+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+48, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+48, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+47, 2, q_00+306+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+47, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+47, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+46, 2, q_00+306+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+46, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+46, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+45, 2, q_00+306+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+45, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+45, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+44, 2, q_00+306+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+44, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+44, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+43, 2, q_00+306+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+43, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+43, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+42, 2, q_00+306+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+42, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+42, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+41, 2, q_00+306+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+41, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+41, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+40, 2, q_00+306+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+40, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+40, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+39, 2, q_00+306+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+39, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+39, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+38, 2, q_00+306+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+38, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+38, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+37, 2, q_00+306+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+37, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+37, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+36, 2, q_00+306+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+36, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+36, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+35, 2, q_00+306+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+35, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+35, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+34, 2, q_00+306+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+34, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+34, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+33, 2, q_00+306+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+33, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+33, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+32, 2, q_00+306+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+32, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+32, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+31, 2, q_00+306+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+31, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+31, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+30, 2, q_00+306+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+30, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+30, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+29, 2, q_00+306+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+29, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+29, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+28, 2, q_00+306+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+28, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+28, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+27, 2, q_00+306+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+27, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+27, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+26, 2, q_00+306+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+26, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+26, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+25, 2, q_00+306+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+25, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+25, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+24, 2, q_00+306+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+24, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+24, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+23, 2, q_00+306+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+23, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+23, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+22, 2, q_00+306+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+22, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+22, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+21, 2, q_00+306+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+21, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+21, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+20, 2, q_00+306+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+20, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+20, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+19, 2, q_00+306+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+19, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+19, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+18, 2, q_00+306+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+18, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+18, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+17, 2, q_00+306+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+17, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+17, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+16, 2, q_00+306+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+16, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+16, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+15, 2, q_00+306+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+15, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+15, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+14, 2, q_00+306+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+14, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+14, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+13, 2, q_00+306+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+13, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+13, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+12, 2, q_00+306+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+12, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+12, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+11, 2, q_00+306+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+11, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+11, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+10, 2, q_00+306+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+10, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+10, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+9, 2, q_00+306+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+9, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+9, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+8, 2, q_00+306+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+8, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+8, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+7, 2, q_00+306+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+7, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+7, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+6, 2, q_00+306+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+6, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+6, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+5, 2, q_00+306+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+5, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+5, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+4, 2, q_00+306+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+4, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+4, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+3, 2, q_00+306+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+3, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+3, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+2, 2, q_00+306+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+2, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+2, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+1, 2, q_00+306+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+1, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+1, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_00+306+0, 2, q_00+306+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+0, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_01+462+0, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_00+306, 1, q_00+306, 1, temp+1);
	GF2X_MUL(150, temp, 75, p_01+467+1, 75, q_00+462);
	GF2X_MUL(150, temp2, 75, p_11+467+1, 75, q_01+462);
	gf2x_add(150, q_01+306+0, 150, temp, 150, temp2);
	GF2X_MUL(2, temp, 1, q_00+462+74, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+74, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+73, 2, q_01+306+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+73, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+73, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+72, 2, q_01+306+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+72, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+72, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+71, 2, q_01+306+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+71, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+71, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+70, 2, q_01+306+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+70, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+70, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+69, 2, q_01+306+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+69, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+69, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+68, 2, q_01+306+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+68, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+68, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+67, 2, q_01+306+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+67, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+67, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+66, 2, q_01+306+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+66, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+66, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+65, 2, q_01+306+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+65, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+65, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+64, 2, q_01+306+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+64, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+64, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+63, 2, q_01+306+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+63, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+63, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+62, 2, q_01+306+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+62, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+62, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+61, 2, q_01+306+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+61, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+61, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+60, 2, q_01+306+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+60, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+60, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+59, 2, q_01+306+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+59, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+59, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+58, 2, q_01+306+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+58, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+58, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+57, 2, q_01+306+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+57, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+57, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+56, 2, q_01+306+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+56, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+56, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+55, 2, q_01+306+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+55, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+55, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+54, 2, q_01+306+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+54, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+54, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+53, 2, q_01+306+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+53, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+53, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+52, 2, q_01+306+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+52, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+52, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+51, 2, q_01+306+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+51, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+51, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+50, 2, q_01+306+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+50, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+50, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+49, 2, q_01+306+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+49, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+49, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+48, 2, q_01+306+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+48, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+48, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+47, 2, q_01+306+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+47, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+47, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+46, 2, q_01+306+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+46, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+46, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+45, 2, q_01+306+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+45, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+45, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+44, 2, q_01+306+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+44, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+44, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+43, 2, q_01+306+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+43, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+43, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+42, 2, q_01+306+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+42, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+42, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+41, 2, q_01+306+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+41, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+41, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+40, 2, q_01+306+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+40, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+40, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+39, 2, q_01+306+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+39, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+39, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+38, 2, q_01+306+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+38, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+38, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+37, 2, q_01+306+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+37, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+37, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+36, 2, q_01+306+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+36, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+36, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+35, 2, q_01+306+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+35, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+35, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+34, 2, q_01+306+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+34, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+34, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+33, 2, q_01+306+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+33, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+33, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+32, 2, q_01+306+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+32, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+32, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+31, 2, q_01+306+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+31, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+31, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+30, 2, q_01+306+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+30, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+30, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+29, 2, q_01+306+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+29, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+29, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+28, 2, q_01+306+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+28, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+28, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+27, 2, q_01+306+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+27, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+27, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+26, 2, q_01+306+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+26, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+26, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+25, 2, q_01+306+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+25, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+25, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+24, 2, q_01+306+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+24, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+24, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+23, 2, q_01+306+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+23, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+23, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+22, 2, q_01+306+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+22, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+22, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+21, 2, q_01+306+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+21, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+21, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+20, 2, q_01+306+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+20, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+20, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+19, 2, q_01+306+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+19, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+19, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+18, 2, q_01+306+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+18, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+18, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+17, 2, q_01+306+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+17, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+17, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+16, 2, q_01+306+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+16, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+16, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+15, 2, q_01+306+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+15, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+15, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+14, 2, q_01+306+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+14, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+14, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+13, 2, q_01+306+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+13, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+13, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+12, 2, q_01+306+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+12, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+12, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+11, 2, q_01+306+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+11, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+11, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+10, 2, q_01+306+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+10, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+10, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+9, 2, q_01+306+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+9, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+9, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+8, 2, q_01+306+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+8, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+8, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+7, 2, q_01+306+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+7, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+7, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+6, 2, q_01+306+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+6, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+6, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+5, 2, q_01+306+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+5, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+5, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+4, 2, q_01+306+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+4, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+4, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+3, 2, q_01+306+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+3, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+3, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+2, 2, q_01+306+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+2, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+2, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+1, 2, q_01+306+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+1, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+1, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_01+306+0, 2, q_01+306+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_00+462+0, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_01+462+0, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_01+306, 1, q_01+306, 1, temp+1);
	GF2X_MUL(150, temp, 75, p_00+467+1, 75, q_10+462);
	GF2X_MUL(150, temp2, 75, p_10+467+1, 75, q_11+462);
	gf2x_add(150, q_10+306+0, 150, temp, 150, temp2);
	GF2X_MUL(2, temp, 1, q_10+462+74, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+74, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+73, 2, q_10+306+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+73, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+73, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+72, 2, q_10+306+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+72, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+72, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+71, 2, q_10+306+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+71, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+71, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+70, 2, q_10+306+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+70, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+70, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+69, 2, q_10+306+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+69, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+69, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+68, 2, q_10+306+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+68, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+68, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+67, 2, q_10+306+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+67, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+67, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+66, 2, q_10+306+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+66, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+66, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+65, 2, q_10+306+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+65, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+65, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+64, 2, q_10+306+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+64, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+64, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+63, 2, q_10+306+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+63, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+63, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+62, 2, q_10+306+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+62, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+62, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+61, 2, q_10+306+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+61, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+61, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+60, 2, q_10+306+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+60, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+60, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+59, 2, q_10+306+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+59, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+59, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+58, 2, q_10+306+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+58, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+58, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+57, 2, q_10+306+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+57, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+57, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+56, 2, q_10+306+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+56, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+56, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+55, 2, q_10+306+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+55, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+55, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+54, 2, q_10+306+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+54, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+54, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+53, 2, q_10+306+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+53, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+53, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+52, 2, q_10+306+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+52, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+52, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+51, 2, q_10+306+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+51, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+51, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+50, 2, q_10+306+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+50, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+50, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+49, 2, q_10+306+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+49, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+49, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+48, 2, q_10+306+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+48, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+48, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+47, 2, q_10+306+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+47, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+47, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+46, 2, q_10+306+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+46, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+46, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+45, 2, q_10+306+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+45, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+45, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+44, 2, q_10+306+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+44, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+44, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+43, 2, q_10+306+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+43, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+43, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+42, 2, q_10+306+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+42, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+42, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+41, 2, q_10+306+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+41, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+41, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+40, 2, q_10+306+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+40, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+40, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+39, 2, q_10+306+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+39, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+39, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+38, 2, q_10+306+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+38, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+38, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+37, 2, q_10+306+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+37, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+37, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+36, 2, q_10+306+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+36, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+36, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+35, 2, q_10+306+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+35, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+35, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+34, 2, q_10+306+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+34, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+34, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+33, 2, q_10+306+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+33, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+33, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+32, 2, q_10+306+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+32, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+32, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+31, 2, q_10+306+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+31, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+31, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+30, 2, q_10+306+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+30, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+30, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+29, 2, q_10+306+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+29, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+29, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+28, 2, q_10+306+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+28, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+28, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+27, 2, q_10+306+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+27, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+27, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+26, 2, q_10+306+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+26, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+26, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+25, 2, q_10+306+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+25, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+25, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+24, 2, q_10+306+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+24, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+24, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+23, 2, q_10+306+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+23, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+23, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+22, 2, q_10+306+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+22, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+22, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+21, 2, q_10+306+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+21, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+21, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+20, 2, q_10+306+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+20, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+20, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+19, 2, q_10+306+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+19, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+19, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+18, 2, q_10+306+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+18, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+18, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+17, 2, q_10+306+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+17, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+17, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+16, 2, q_10+306+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+16, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+16, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+15, 2, q_10+306+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+15, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+15, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+14, 2, q_10+306+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+14, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+14, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+13, 2, q_10+306+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+13, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+13, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+12, 2, q_10+306+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+12, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+12, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+11, 2, q_10+306+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+11, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+11, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+10, 2, q_10+306+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+10, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+10, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+9, 2, q_10+306+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+9, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+9, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+8, 2, q_10+306+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+8, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+8, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+7, 2, q_10+306+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+7, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+7, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+6, 2, q_10+306+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+6, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+6, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+5, 2, q_10+306+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+5, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+5, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+4, 2, q_10+306+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+4, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+4, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+3, 2, q_10+306+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+3, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+3, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+2, 2, q_10+306+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+2, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+2, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+1, 2, q_10+306+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+1, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+1, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_10+306+0, 2, q_10+306+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+0, 1, p_00+467);
	GF2X_MUL(2, temp2, 1, q_11+462+0, 1, p_10+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_10+306, 1, q_10+306, 1, temp+1);
	GF2X_MUL(150, temp, 75, p_01+467+1, 75, q_10+462);
	GF2X_MUL(150, temp2, 75, p_11+467+1, 75, q_11+462);
	gf2x_add(150, q_11+306+0, 150, temp, 150, temp2);
	GF2X_MUL(2, temp, 1, q_10+462+74, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+74, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+73, 2, q_11+306+73, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+73, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+73, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+72, 2, q_11+306+72, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+72, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+72, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+71, 2, q_11+306+71, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+71, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+71, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+70, 2, q_11+306+70, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+70, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+70, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+69, 2, q_11+306+69, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+69, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+69, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+68, 2, q_11+306+68, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+68, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+68, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+67, 2, q_11+306+67, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+67, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+67, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+66, 2, q_11+306+66, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+66, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+66, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+65, 2, q_11+306+65, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+65, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+65, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+64, 2, q_11+306+64, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+64, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+64, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+63, 2, q_11+306+63, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+63, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+63, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+62, 2, q_11+306+62, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+62, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+62, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+61, 2, q_11+306+61, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+61, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+61, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+60, 2, q_11+306+60, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+60, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+60, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+59, 2, q_11+306+59, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+59, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+59, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+58, 2, q_11+306+58, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+58, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+58, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+57, 2, q_11+306+57, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+57, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+57, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+56, 2, q_11+306+56, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+56, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+56, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+55, 2, q_11+306+55, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+55, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+55, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+54, 2, q_11+306+54, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+54, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+54, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+53, 2, q_11+306+53, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+53, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+53, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+52, 2, q_11+306+52, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+52, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+52, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+51, 2, q_11+306+51, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+51, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+51, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+50, 2, q_11+306+50, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+50, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+50, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+49, 2, q_11+306+49, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+49, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+49, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+48, 2, q_11+306+48, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+48, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+48, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+47, 2, q_11+306+47, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+47, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+47, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+46, 2, q_11+306+46, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+46, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+46, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+45, 2, q_11+306+45, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+45, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+45, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+44, 2, q_11+306+44, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+44, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+44, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+43, 2, q_11+306+43, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+43, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+43, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+42, 2, q_11+306+42, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+42, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+42, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+41, 2, q_11+306+41, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+41, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+41, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+40, 2, q_11+306+40, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+40, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+40, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+39, 2, q_11+306+39, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+39, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+39, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+38, 2, q_11+306+38, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+38, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+38, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+37, 2, q_11+306+37, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+37, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+37, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+36, 2, q_11+306+36, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+36, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+36, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+35, 2, q_11+306+35, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+35, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+35, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+34, 2, q_11+306+34, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+34, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+34, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+33, 2, q_11+306+33, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+33, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+33, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+32, 2, q_11+306+32, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+32, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+32, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+31, 2, q_11+306+31, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+31, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+31, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+30, 2, q_11+306+30, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+30, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+30, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+29, 2, q_11+306+29, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+29, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+29, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+28, 2, q_11+306+28, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+28, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+28, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+27, 2, q_11+306+27, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+27, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+27, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+26, 2, q_11+306+26, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+26, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+26, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+25, 2, q_11+306+25, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+25, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+25, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+24, 2, q_11+306+24, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+24, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+24, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+23, 2, q_11+306+23, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+23, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+23, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+22, 2, q_11+306+22, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+22, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+22, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+21, 2, q_11+306+21, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+21, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+21, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+20, 2, q_11+306+20, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+20, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+20, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+19, 2, q_11+306+19, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+19, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+19, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+18, 2, q_11+306+18, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+18, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+18, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+17, 2, q_11+306+17, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+17, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+17, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+16, 2, q_11+306+16, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+16, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+16, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+15, 2, q_11+306+15, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+15, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+15, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+14, 2, q_11+306+14, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+14, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+14, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+13, 2, q_11+306+13, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+13, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+13, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+12, 2, q_11+306+12, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+12, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+12, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+11, 2, q_11+306+11, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+11, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+11, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+10, 2, q_11+306+10, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+10, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+10, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+9, 2, q_11+306+9, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+9, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+9, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+8, 2, q_11+306+8, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+8, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+8, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+7, 2, q_11+306+7, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+7, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+7, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+6, 2, q_11+306+6, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+6, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+6, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+5, 2, q_11+306+5, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+5, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+5, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+4, 2, q_11+306+4, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+4, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+4, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+3, 2, q_11+306+3, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+3, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+3, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+2, 2, q_11+306+2, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+2, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+2, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+1, 2, q_11+306+1, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+1, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+1, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, q_11+306+0, 2, q_11+306+0, 2, temp);
	GF2X_MUL(2, temp, 1, q_10+462+0, 1, p_01+467);
	GF2X_MUL(2, temp2, 1, q_11+462+0, 1, p_11+467);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(1, q_11+306, 1, q_11+306, 1, temp+1);
	

	// Recombining results: n: 19527, depth: 1
	memset(q_00+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(300, temp, 150, p_00+311+6, 150, q_00+306);
	GF2X_MUL(300, temp2, 150, p_10+311+6, 150, q_01+306);
	gf2x_add(300, q_00+0+6, 300, temp, 300, temp2);
	GF2X_MUL(12, temp, 6, q_00+306+144, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+144, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+144, 12, q_00+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+138, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+138, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+138, 12, q_00+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+132, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+132, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+132, 12, q_00+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+126, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+126, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+126, 12, q_00+0+126, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+120, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+120, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+120, 12, q_00+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+114, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+114, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+114, 12, q_00+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+108, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+108, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+108, 12, q_00+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+102, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+102, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+102, 12, q_00+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+96, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+96, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+96, 12, q_00+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+90, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+90, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+90, 12, q_00+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+84, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+84, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+84, 12, q_00+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+78, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+78, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+78, 12, q_00+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+72, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+72, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+72, 12, q_00+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+66, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+66, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+66, 12, q_00+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+60, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+60, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+60, 12, q_00+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+54, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+54, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+54, 12, q_00+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+48, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+48, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+48, 12, q_00+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+42, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+42, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+42, 12, q_00+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+36, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+36, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+36, 12, q_00+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+30, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+30, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+30, 12, q_00+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+24, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+24, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+24, 12, q_00+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+18, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+18, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+18, 12, q_00+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+12, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+12, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+12, 12, q_00+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+6, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+6, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+6, 12, q_00+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+0, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_01+306+0, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_00+0+0, 12, q_00+0+0, 12, temp);
	memset(q_01+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(300, temp, 150, p_01+311+6, 150, q_00+306);
	GF2X_MUL(300, temp2, 150, p_11+311+6, 150, q_01+306);
	gf2x_add(300, q_01+0+6, 300, temp, 300, temp2);
	GF2X_MUL(12, temp, 6, q_00+306+144, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+144, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+144, 12, q_01+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+138, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+138, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+138, 12, q_01+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+132, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+132, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+132, 12, q_01+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+126, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+126, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+126, 12, q_01+0+126, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+120, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+120, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+120, 12, q_01+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+114, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+114, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+114, 12, q_01+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+108, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+108, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+108, 12, q_01+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+102, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+102, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+102, 12, q_01+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+96, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+96, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+96, 12, q_01+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+90, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+90, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+90, 12, q_01+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+84, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+84, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+84, 12, q_01+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+78, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+78, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+78, 12, q_01+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+72, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+72, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+72, 12, q_01+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+66, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+66, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+66, 12, q_01+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+60, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+60, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+60, 12, q_01+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+54, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+54, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+54, 12, q_01+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+48, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+48, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+48, 12, q_01+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+42, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+42, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+42, 12, q_01+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+36, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+36, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+36, 12, q_01+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+30, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+30, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+30, 12, q_01+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+24, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+24, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+24, 12, q_01+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+18, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+18, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+18, 12, q_01+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+12, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+12, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+12, 12, q_01+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+6, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+6, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+6, 12, q_01+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_00+306+0, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_01+306+0, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_01+0+0, 12, q_01+0+0, 12, temp);
	memset(q_10+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(300, temp, 150, p_00+311+6, 150, q_10+306);
	GF2X_MUL(300, temp2, 150, p_10+311+6, 150, q_11+306);
	gf2x_add(300, q_10+0+6, 300, temp, 300, temp2);
	GF2X_MUL(12, temp, 6, q_10+306+144, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+144, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+144, 12, q_10+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+138, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+138, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+138, 12, q_10+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+132, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+132, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+132, 12, q_10+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+126, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+126, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+126, 12, q_10+0+126, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+120, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+120, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+120, 12, q_10+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+114, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+114, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+114, 12, q_10+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+108, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+108, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+108, 12, q_10+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+102, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+102, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+102, 12, q_10+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+96, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+96, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+96, 12, q_10+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+90, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+90, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+90, 12, q_10+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+84, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+84, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+84, 12, q_10+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+78, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+78, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+78, 12, q_10+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+72, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+72, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+72, 12, q_10+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+66, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+66, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+66, 12, q_10+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+60, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+60, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+60, 12, q_10+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+54, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+54, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+54, 12, q_10+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+48, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+48, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+48, 12, q_10+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+42, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+42, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+42, 12, q_10+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+36, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+36, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+36, 12, q_10+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+30, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+30, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+30, 12, q_10+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+24, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+24, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+24, 12, q_10+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+18, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+18, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+18, 12, q_10+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+12, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+12, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+12, 12, q_10+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+6, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+6, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+6, 12, q_10+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+0, 6, p_00+311);
	GF2X_MUL(12, temp2, 6, q_11+306+0, 6, p_10+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_10+0+0, 12, q_10+0+0, 12, temp);
	memset(q_11+0, 0x00, 6*DIGIT_SIZE_B);
	GF2X_MUL(300, temp, 150, p_01+311+6, 150, q_10+306);
	GF2X_MUL(300, temp2, 150, p_11+311+6, 150, q_11+306);
	gf2x_add(300, q_11+0+6, 300, temp, 300, temp2);
	GF2X_MUL(12, temp, 6, q_10+306+144, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+144, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+144, 12, q_11+0+144, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+138, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+138, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+138, 12, q_11+0+138, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+132, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+132, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+132, 12, q_11+0+132, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+126, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+126, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+126, 12, q_11+0+126, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+120, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+120, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+120, 12, q_11+0+120, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+114, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+114, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+114, 12, q_11+0+114, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+108, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+108, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+108, 12, q_11+0+108, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+102, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+102, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+102, 12, q_11+0+102, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+96, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+96, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+96, 12, q_11+0+96, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+90, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+90, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+90, 12, q_11+0+90, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+84, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+84, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+84, 12, q_11+0+84, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+78, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+78, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+78, 12, q_11+0+78, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+72, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+72, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+72, 12, q_11+0+72, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+66, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+66, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+66, 12, q_11+0+66, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+60, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+60, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+60, 12, q_11+0+60, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+54, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+54, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+54, 12, q_11+0+54, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+48, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+48, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+48, 12, q_11+0+48, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+42, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+42, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+42, 12, q_11+0+42, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+36, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+36, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+36, 12, q_11+0+36, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+30, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+30, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+30, 12, q_11+0+30, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+24, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+24, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+24, 12, q_11+0+24, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+18, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+18, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+18, 12, q_11+0+18, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+12, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+12, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+12, 12, q_11+0+12, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+6, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+6, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+6, 12, q_11+0+6, 12, temp);
	GF2X_MUL(12, temp, 6, q_10+306+0, 6, p_01+311);
	GF2X_MUL(12, temp2, 6, q_11+306+0, 6, p_11+311);
	gf2x_add(12, temp, 12, temp, 12, temp2);
	gf2x_add(12, q_11+0+0, 12, q_11+0+0, 12, temp);
	

	// Recombining results: n: 39417, depth: 0
	memset(t_00+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(612, temp, 306, p_00+0+5, 306, q_00+0);
	GF2X_MUL(612, temp2, 306, p_10+0+5, 306, q_01+0);
	gf2x_add(612, t_00+0+4, 612, temp, 612, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+301, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+301, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+300, 10, t_00+0+300, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+296, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+296, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+295, 10, t_00+0+295, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+291, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+291, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+290, 10, t_00+0+290, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+286, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+286, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+285, 10, t_00+0+285, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+281, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+281, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+280, 10, t_00+0+280, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+276, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+276, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+275, 10, t_00+0+275, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+271, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+271, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+270, 10, t_00+0+270, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+266, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+266, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+265, 10, t_00+0+265, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+261, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+261, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+260, 10, t_00+0+260, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+256, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+256, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+255, 10, t_00+0+255, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+251, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+251, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+250, 10, t_00+0+250, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+246, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+246, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+245, 10, t_00+0+245, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+241, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+241, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+240, 10, t_00+0+240, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+236, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+236, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+235, 10, t_00+0+235, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+231, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+231, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+230, 10, t_00+0+230, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+226, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+226, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+225, 10, t_00+0+225, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+221, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+221, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+220, 10, t_00+0+220, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+216, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+216, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+215, 10, t_00+0+215, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+211, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+211, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+210, 10, t_00+0+210, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+206, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+206, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+205, 10, t_00+0+205, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+201, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+201, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+200, 10, t_00+0+200, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+196, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+196, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+195, 10, t_00+0+195, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+191, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+191, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+190, 10, t_00+0+190, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+186, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+186, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+185, 10, t_00+0+185, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+181, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+181, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+180, 10, t_00+0+180, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+176, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+176, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+175, 10, t_00+0+175, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+171, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+171, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+170, 10, t_00+0+170, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+166, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+166, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+165, 10, t_00+0+165, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+161, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+161, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+160, 10, t_00+0+160, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+156, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+156, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+155, 10, t_00+0+155, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+151, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+151, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+150, 10, t_00+0+150, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+146, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+146, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+145, 10, t_00+0+145, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+141, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+141, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+140, 10, t_00+0+140, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+136, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+136, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+135, 10, t_00+0+135, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+131, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+131, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+130, 10, t_00+0+130, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+126, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+126, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+125, 10, t_00+0+125, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+121, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+121, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+120, 10, t_00+0+120, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+116, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+116, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+115, 10, t_00+0+115, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+111, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+111, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+110, 10, t_00+0+110, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+106, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+106, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+105, 10, t_00+0+105, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+101, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+101, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+100, 10, t_00+0+100, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+96, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+96, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+95, 10, t_00+0+95, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+91, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+91, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+90, 10, t_00+0+90, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+86, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+86, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+85, 10, t_00+0+85, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+81, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+81, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+80, 10, t_00+0+80, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+76, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+76, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+75, 10, t_00+0+75, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+71, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+71, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+70, 10, t_00+0+70, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+66, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+66, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+65, 10, t_00+0+65, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+61, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+61, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+60, 10, t_00+0+60, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+56, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+56, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+55, 10, t_00+0+55, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+51, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+51, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+50, 10, t_00+0+50, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+46, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+46, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+45, 10, t_00+0+45, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+41, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+41, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+40, 10, t_00+0+40, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+36, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+36, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+35, 10, t_00+0+35, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+31, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+31, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+30, 10, t_00+0+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+26, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+26, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+25, 10, t_00+0+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+21, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+21, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+20, 10, t_00+0+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+16, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+16, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+15, 10, t_00+0+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+11, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+11, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+10, 10, t_00+0+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+6, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+6, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+5, 10, t_00+0+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+1, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_01+0+1, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_00+0+0, 10, t_00+0+0, 10, temp);
	GF2X_MUL(2, temp, 1, p_00+0+4, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+4, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+3, 2, t_00+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+3, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_10+0+3, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_00+0+2, 2, t_00+0+2, 2, temp);
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
	memset(t_01+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(612, temp, 306, p_01+0+5, 306, q_00+0);
	GF2X_MUL(612, temp2, 306, p_11+0+5, 306, q_01+0);
	gf2x_add(612, t_01+0+4, 612, temp, 612, temp2);
	GF2X_MUL(10, temp, 5, q_00+0+301, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+301, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+300, 10, t_01+0+300, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+296, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+296, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+295, 10, t_01+0+295, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+291, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+291, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+290, 10, t_01+0+290, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+286, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+286, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+285, 10, t_01+0+285, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+281, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+281, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+280, 10, t_01+0+280, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+276, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+276, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+275, 10, t_01+0+275, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+271, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+271, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+270, 10, t_01+0+270, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+266, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+266, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+265, 10, t_01+0+265, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+261, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+261, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+260, 10, t_01+0+260, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+256, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+256, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+255, 10, t_01+0+255, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+251, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+251, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+250, 10, t_01+0+250, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+246, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+246, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+245, 10, t_01+0+245, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+241, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+241, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+240, 10, t_01+0+240, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+236, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+236, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+235, 10, t_01+0+235, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+231, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+231, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+230, 10, t_01+0+230, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+226, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+226, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+225, 10, t_01+0+225, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+221, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+221, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+220, 10, t_01+0+220, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+216, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+216, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+215, 10, t_01+0+215, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+211, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+211, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+210, 10, t_01+0+210, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+206, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+206, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+205, 10, t_01+0+205, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+201, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+201, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+200, 10, t_01+0+200, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+196, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+196, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+195, 10, t_01+0+195, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+191, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+191, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+190, 10, t_01+0+190, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+186, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+186, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+185, 10, t_01+0+185, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+181, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+181, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+180, 10, t_01+0+180, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+176, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+176, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+175, 10, t_01+0+175, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+171, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+171, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+170, 10, t_01+0+170, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+166, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+166, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+165, 10, t_01+0+165, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+161, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+161, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+160, 10, t_01+0+160, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+156, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+156, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+155, 10, t_01+0+155, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+151, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+151, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+150, 10, t_01+0+150, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+146, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+146, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+145, 10, t_01+0+145, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+141, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+141, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+140, 10, t_01+0+140, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+136, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+136, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+135, 10, t_01+0+135, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+131, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+131, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+130, 10, t_01+0+130, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+126, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+126, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+125, 10, t_01+0+125, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+121, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+121, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+120, 10, t_01+0+120, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+116, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+116, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+115, 10, t_01+0+115, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+111, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+111, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+110, 10, t_01+0+110, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+106, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+106, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+105, 10, t_01+0+105, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+101, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+101, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+100, 10, t_01+0+100, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+96, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+96, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+95, 10, t_01+0+95, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+91, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+91, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+90, 10, t_01+0+90, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+86, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+86, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+85, 10, t_01+0+85, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+81, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+81, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+80, 10, t_01+0+80, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+76, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+76, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+75, 10, t_01+0+75, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+71, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+71, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+70, 10, t_01+0+70, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+66, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+66, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+65, 10, t_01+0+65, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+61, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+61, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+60, 10, t_01+0+60, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+56, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+56, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+55, 10, t_01+0+55, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+51, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+51, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+50, 10, t_01+0+50, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+46, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+46, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+45, 10, t_01+0+45, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+41, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+41, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+40, 10, t_01+0+40, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+36, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+36, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+35, 10, t_01+0+35, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+31, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+31, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+30, 10, t_01+0+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+26, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+26, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+25, 10, t_01+0+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+21, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+21, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+20, 10, t_01+0+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+16, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+16, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+15, 10, t_01+0+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+11, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+11, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+10, 10, t_01+0+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+6, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+6, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+5, 10, t_01+0+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_00+0+1, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_01+0+1, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_01+0+0, 10, t_01+0+0, 10, temp);
	GF2X_MUL(2, temp, 1, p_01+0+4, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+4, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+3, 2, t_01+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+3, 1, q_00+0);
	GF2X_MUL(2, temp2, 1, p_11+0+3, 1, q_01+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_01+0+2, 2, t_01+0+2, 2, temp);
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
	memset(t_10+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(612, temp, 306, p_00+0+5, 306, q_10+0);
	GF2X_MUL(612, temp2, 306, p_10+0+5, 306, q_11+0);
	gf2x_add(612, t_10+0+4, 612, temp, 612, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+301, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+301, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+300, 10, t_10+0+300, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+296, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+296, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+295, 10, t_10+0+295, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+291, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+291, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+290, 10, t_10+0+290, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+286, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+286, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+285, 10, t_10+0+285, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+281, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+281, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+280, 10, t_10+0+280, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+276, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+276, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+275, 10, t_10+0+275, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+271, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+271, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+270, 10, t_10+0+270, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+266, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+266, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+265, 10, t_10+0+265, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+261, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+261, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+260, 10, t_10+0+260, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+256, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+256, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+255, 10, t_10+0+255, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+251, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+251, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+250, 10, t_10+0+250, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+246, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+246, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+245, 10, t_10+0+245, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+241, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+241, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+240, 10, t_10+0+240, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+236, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+236, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+235, 10, t_10+0+235, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+231, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+231, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+230, 10, t_10+0+230, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+226, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+226, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+225, 10, t_10+0+225, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+221, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+221, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+220, 10, t_10+0+220, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+216, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+216, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+215, 10, t_10+0+215, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+211, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+211, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+210, 10, t_10+0+210, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+206, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+206, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+205, 10, t_10+0+205, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+201, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+201, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+200, 10, t_10+0+200, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+196, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+196, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+195, 10, t_10+0+195, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+191, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+191, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+190, 10, t_10+0+190, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+186, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+186, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+185, 10, t_10+0+185, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+181, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+181, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+180, 10, t_10+0+180, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+176, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+176, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+175, 10, t_10+0+175, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+171, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+171, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+170, 10, t_10+0+170, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+166, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+166, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+165, 10, t_10+0+165, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+161, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+161, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+160, 10, t_10+0+160, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+156, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+156, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+155, 10, t_10+0+155, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+151, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+151, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+150, 10, t_10+0+150, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+146, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+146, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+145, 10, t_10+0+145, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+141, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+141, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+140, 10, t_10+0+140, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+136, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+136, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+135, 10, t_10+0+135, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+131, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+131, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+130, 10, t_10+0+130, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+126, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+126, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+125, 10, t_10+0+125, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+121, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+121, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+120, 10, t_10+0+120, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+116, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+116, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+115, 10, t_10+0+115, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+111, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+111, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+110, 10, t_10+0+110, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+106, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+106, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+105, 10, t_10+0+105, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+101, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+101, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+100, 10, t_10+0+100, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+96, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+96, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+95, 10, t_10+0+95, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+91, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+91, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+90, 10, t_10+0+90, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+86, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+86, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+85, 10, t_10+0+85, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+81, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+81, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+80, 10, t_10+0+80, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+76, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+76, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+75, 10, t_10+0+75, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+71, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+71, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+70, 10, t_10+0+70, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+66, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+66, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+65, 10, t_10+0+65, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+61, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+61, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+60, 10, t_10+0+60, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+56, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+56, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+55, 10, t_10+0+55, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+51, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+51, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+50, 10, t_10+0+50, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+46, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+46, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+45, 10, t_10+0+45, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+41, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+41, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+40, 10, t_10+0+40, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+36, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+36, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+35, 10, t_10+0+35, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+31, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+31, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+30, 10, t_10+0+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+26, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+26, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+25, 10, t_10+0+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+21, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+21, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+20, 10, t_10+0+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+16, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+16, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+15, 10, t_10+0+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+11, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+11, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+10, 10, t_10+0+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+6, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+6, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+5, 10, t_10+0+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+1, 5, p_00+0);
	GF2X_MUL(10, temp2, 5, q_11+0+1, 5, p_10+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_10+0+0, 10, t_10+0+0, 10, temp);
	GF2X_MUL(2, temp, 1, p_00+0+4, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+4, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+3, 2, t_10+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_00+0+3, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_10+0+3, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_10+0+2, 2, t_10+0+2, 2, temp);
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
	memset(t_11+0, 0x00, 4*DIGIT_SIZE_B);
	GF2X_MUL(612, temp, 306, p_01+0+5, 306, q_10+0);
	GF2X_MUL(612, temp2, 306, p_11+0+5, 306, q_11+0);
	gf2x_add(612, t_11+0+4, 612, temp, 612, temp2);
	GF2X_MUL(10, temp, 5, q_10+0+301, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+301, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+300, 10, t_11+0+300, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+296, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+296, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+295, 10, t_11+0+295, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+291, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+291, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+290, 10, t_11+0+290, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+286, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+286, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+285, 10, t_11+0+285, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+281, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+281, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+280, 10, t_11+0+280, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+276, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+276, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+275, 10, t_11+0+275, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+271, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+271, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+270, 10, t_11+0+270, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+266, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+266, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+265, 10, t_11+0+265, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+261, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+261, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+260, 10, t_11+0+260, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+256, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+256, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+255, 10, t_11+0+255, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+251, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+251, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+250, 10, t_11+0+250, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+246, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+246, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+245, 10, t_11+0+245, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+241, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+241, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+240, 10, t_11+0+240, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+236, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+236, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+235, 10, t_11+0+235, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+231, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+231, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+230, 10, t_11+0+230, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+226, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+226, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+225, 10, t_11+0+225, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+221, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+221, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+220, 10, t_11+0+220, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+216, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+216, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+215, 10, t_11+0+215, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+211, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+211, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+210, 10, t_11+0+210, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+206, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+206, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+205, 10, t_11+0+205, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+201, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+201, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+200, 10, t_11+0+200, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+196, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+196, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+195, 10, t_11+0+195, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+191, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+191, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+190, 10, t_11+0+190, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+186, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+186, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+185, 10, t_11+0+185, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+181, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+181, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+180, 10, t_11+0+180, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+176, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+176, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+175, 10, t_11+0+175, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+171, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+171, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+170, 10, t_11+0+170, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+166, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+166, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+165, 10, t_11+0+165, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+161, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+161, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+160, 10, t_11+0+160, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+156, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+156, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+155, 10, t_11+0+155, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+151, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+151, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+150, 10, t_11+0+150, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+146, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+146, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+145, 10, t_11+0+145, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+141, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+141, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+140, 10, t_11+0+140, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+136, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+136, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+135, 10, t_11+0+135, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+131, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+131, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+130, 10, t_11+0+130, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+126, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+126, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+125, 10, t_11+0+125, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+121, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+121, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+120, 10, t_11+0+120, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+116, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+116, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+115, 10, t_11+0+115, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+111, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+111, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+110, 10, t_11+0+110, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+106, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+106, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+105, 10, t_11+0+105, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+101, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+101, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+100, 10, t_11+0+100, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+96, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+96, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+95, 10, t_11+0+95, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+91, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+91, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+90, 10, t_11+0+90, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+86, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+86, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+85, 10, t_11+0+85, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+81, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+81, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+80, 10, t_11+0+80, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+76, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+76, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+75, 10, t_11+0+75, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+71, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+71, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+70, 10, t_11+0+70, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+66, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+66, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+65, 10, t_11+0+65, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+61, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+61, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+60, 10, t_11+0+60, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+56, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+56, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+55, 10, t_11+0+55, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+51, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+51, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+50, 10, t_11+0+50, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+46, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+46, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+45, 10, t_11+0+45, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+41, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+41, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+40, 10, t_11+0+40, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+36, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+36, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+35, 10, t_11+0+35, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+31, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+31, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+30, 10, t_11+0+30, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+26, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+26, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+25, 10, t_11+0+25, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+21, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+21, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+20, 10, t_11+0+20, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+16, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+16, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+15, 10, t_11+0+15, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+11, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+11, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+10, 10, t_11+0+10, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+6, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+6, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+5, 10, t_11+0+5, 10, temp);
	GF2X_MUL(10, temp, 5, q_10+0+1, 5, p_01+0);
	GF2X_MUL(10, temp2, 5, q_11+0+1, 5, p_11+0);
	gf2x_add(10, temp, 10, temp, 10, temp2);
	gf2x_add(10, t_11+0+0, 10, t_11+0+0, 10, temp);
	GF2X_MUL(2, temp, 1, p_01+0+4, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+4, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+3, 2, t_11+0+3, 2, temp);
	GF2X_MUL(2, temp, 1, p_01+0+3, 1, q_10+0);
	GF2X_MUL(2, temp2, 1, p_11+0+3, 1, q_11+0);
	gf2x_add(2, temp, 2, temp, 2, temp2);
	gf2x_add(2, t_11+0+2, 2, t_11+0+2, 2, temp);
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